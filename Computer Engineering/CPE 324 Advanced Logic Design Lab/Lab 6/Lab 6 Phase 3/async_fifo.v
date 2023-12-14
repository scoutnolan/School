module async_fifo #(
  parameter WIDTH,
  parameter DEPTH
) (
  input              wrClk,
  input              wrRst,
  input              wrEn,
  input  [WIDTH-1:0] wrData,
  input              rdClk,
  input              rdRst,
  input              rdEn,
  output             full,
  output             empty,
  output [WIDTH-1:0] rdData
);

  // use the Verilog function $clog2 to easily find the ceiling(log2(N)) of N
  localparam DEPTH_LOG = $clog2(DEPTH);
  // for FULL detection, make sure to store an extra bit
  localparam PTR_WIDTH = (DEPTH == 2**DEPTH_LOG) ? DEPTH_LOG+1 : DEPTH_LOG;

  // TODO: everything else-
  // remember that the pointers need to use PTR_WIDTH, but the
  // FIFO RAM needs to use DEPTH_LOG, which may be 1 bit narrower than
  // PTR_WIDTH

//wire declarations
wire a2;
wire a3;
wire [PTR_WIDTH-1:0] w0;
wire [PTR_WIDTH-1:0] w1;
wire [PTR_WIDTH-1:0] w2;
wire [PTR_WIDTH-1:0] w3;
wire [PTR_WIDTH-1:0] w4;
wire [PTR_WIDTH-1:0] w5;
wire [PTR_WIDTH-1:0] w6;
wire [PTR_WIDTH-1:0] w7;
wire [PTR_WIDTH-1:0] w8;
wire [PTR_WIDTH-1:0] w9;

and a0(a2,wrEn,~full);
and a1(a3,rdEn,~empty);


//Write Pointer module
up_counter #(
	.WIDTH(PTR_WIDTH),
	.TERM_CNT(DEPTH))
Write_Ptr(
	.clk(wrClk),
	.reset(wrRst),
	.en(a2),
	.count(w0)
);


//Read Pointer Module
up_counter #(
	.WIDTH(PTR_WIDTH),
	.TERM_CNT(DEPTH))
Read_Ptr(
	.clk(rdClk),
	.reset(rdRst),
	.en(a3),
	.count(w1)
);


//FIFO RAM Module
sdp_ram_infer #(
	.WIDTH(WIDTH),
	.DEPTH(DEPTH),
	.DEPTH_LOG(PTR_WIDTH)
)
FIFO_RAM(
	.wrClk(wrClk),
	.rdClk(rdClk),
	.rdRst(rdRst),
	.wrEn(a2),
	.wrDat(wrData),
	.wrAdr(w0),
	.rdEn(a3),
	.rdAdr(w1),
	.rdDat(rdData)
);


//gray_coder_write module
gray_coder #(
	.WIDTH(PTR_WIDTH)
)
gray_coder_write(
	.binIn(w0),
	.gcOut(w2)
);

// D flip flop write module
D_Flip_Flop #(
	.WIDTH(PTR_WIDTH)
) WptrGC (
	.clk(wrClk),
	.D(w2),
	.Q(w3)
);

//meta write module
meta #(
	.DATA_WIDTH(PTR_WIDTH),
	.DEPTH(2)
)
WptrGCX(
	.clk(rdClk),
	.in_sig(w3),
	.out_sig(w4)
);

//gray_decoder_write module
gray_decoder #(
	.WIDTH(PTR_WIDTH)
)
gray_decoder_write(
	.gcIn(w4),
	.binOut(w5)
);



//gray_coder_read module
gray_coder #(
	.WIDTH(PTR_WIDTH)
)
gray_coder_read(
	.binIn(w1),
	.gcOut(w6)
);

// D flip flop read module
D_Flip_Flop #(
	.WIDTH(PTR_WIDTH)
) RptrGC (
	.clk(rdClk),
	.D(w6),
	.Q(w7)
);

//meta read module
meta #(
	.DATA_WIDTH(PTR_WIDTH),
	.DEPTH(2)
)
RptrGCX(
	.clk(wrClk),
	.in_sig(w7),
	.out_sig(w8)
);

//gray_decoder_read module
gray_decoder #(
	.WIDTH(PTR_WIDTH)
)
gray_decoder_read(
	.gcIn(w8),
	.binOut(w9)
);


assign full = (DEPTH == (w0-w9)) ? 1 : 0;
assign empty = (w5 == w1) ? 1 : 0;


endmodule





