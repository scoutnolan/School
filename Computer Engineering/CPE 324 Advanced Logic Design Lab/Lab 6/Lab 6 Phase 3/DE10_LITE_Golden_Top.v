// Nolan Anderson
// CPE324 
// Lab 6 Phase 3 Top Level File
`define ENABLE_CLOCK1
`define ENABLE_HEX0
`define ENABLE_HEX1
`define ENABLE_HEX2
`define ENABLE_HEX3
`define ENABLE_HEX4
`define ENABLE_HEX5
`define ENABLE_KEY
`define ENABLE_LED
`define ENABLE_SW
`define ENABLE_GPIO

module DE10_LITE_Golden_Top(

	//////////// ADC CLOCK: 3.3-V LVTTL //////////
`ifdef ENABLE_ADC_CLOCK
	input 		          		ADC_CLK_10,
`endif
	//////////// CLOCK 1: 3.3-V LVTTL //////////
`ifdef ENABLE_CLOCK1
	input 		          		MAX10_CLK1_50,
`endif
	//////////// CLOCK 2: 3.3-V LVTTL //////////
`ifdef ENABLE_CLOCK2
	input 		          		MAX10_CLK2_50,
`endif

	//////////// SDRAM: 3.3-V LVTTL //////////
`ifdef ENABLE_SDRAM
	output		    [12:0]		DRAM_ADDR,
	output		     [1:0]		DRAM_BA,
	output		          		DRAM_CAS_N,
	output		          		DRAM_CKE,
	output		          		DRAM_CLK,
	output		          		DRAM_CS_N,
	inout 		    [15:0]		DRAM_DQ,
	output		          		DRAM_LDQM,
	output		          		DRAM_RAS_N,
	output		          		DRAM_UDQM,
	output		          		DRAM_WE_N,
`endif

	//////////// SEG7: 3.3-V LVTTL //////////
`ifdef ENABLE_HEX0
	output		     [7:0]		HEX0,
`endif
`ifdef ENABLE_HEX1
	output		     [7:0]		HEX1,
`endif
`ifdef ENABLE_HEX2
	output		     [7:0]		HEX2,
`endif
`ifdef ENABLE_HEX3
	output		     [7:0]		HEX3,
`endif
`ifdef ENABLE_HEX4
	output		     [7:0]		HEX4,
`endif
`ifdef ENABLE_HEX5
	output		     [7:0]		HEX5,
`endif

	//////////// KEY: 3.3 V SCHMITT TRIGGER //////////
`ifdef ENABLE_KEY
	input 		     [1:0]		KEY,
`endif

	//////////// LED: 3.3-V LVTTL //////////
`ifdef ENABLE_LED
	output		     [9:0]		LEDR,
`endif

	//////////// SW: 3.3-V LVTTL //////////
`ifdef ENABLE_SW
	input 		     [9:0]		SW,
`endif

	//////////// VGA: 3.3-V LVTTL //////////
`ifdef ENABLE_VGA
	output		     [3:0]		VGA_B,
	output		     [3:0]		VGA_G,
	output		          		VGA_HS,
	output		     [3:0]		VGA_R,
	output		          		VGA_VS,
`endif

	//////////// Accelerometer: 3.3-V LVTTL //////////
`ifdef ENABLE_ACCELEROMETER
	output		          		GSENSOR_CS_N,
	input 		     [2:1]		GSENSOR_INT,
	output		          		GSENSOR_SCLK,
	inout 		          		GSENSOR_SDI,
	inout 		          		GSENSOR_SDO,
`endif

	//////////// Arduino: 3.3-V LVTTL //////////
`ifdef ENABLE_ARDUINO
	inout 		    [15:0]		ARDUINO_IO,
	inout 		          		ARDUINO_RESET_N,
`endif

	//////////// GPIO, GPIO connect to GPIO Default: 3.3-V LVTTL //////////
`ifdef ENABLE_GPIO
	inout 		    [35:0]		GPIO
`endif
);

//=======================================================
//  REG/WIRE declarations
//=======================================================
wire notButton0, clk67, a1, w0, w1, w2, w3, w6, w8, lock, buttonPress;
assign notButton0 = ~KEY[0];
localparam WIDTH = 24;
localparam DEPTH = 36;
wire [WIDTH-1:0] w4;
wire [WIDTH-1:0] w5;
wire [WIDTH-1:0] w7;
assign LEDR[0] = lock;

//=======================================================
//  Structural coding
//=======================================================

meta #(.DATA_WIDTH (1), .DEPTH (2)) 
meta_1(
  .clk (clk67),
  .in_sig (KEY[1]),
  .out_sig (w0)
);

D_Flip_Flop #(	.WIDTH(WIDTH)) 
RptrGC(
	.clk(clk67),
	.D(w0),
	.Q(w1)
);

and a0(a1,~w0,w1);

syspll pll66 (
   .areset(notButton0),
	.inclk0 (MAX10_CLK1_50),
	.c0     (clk67),
	.locked (lock)
 );
 
meta #(.DATA_WIDTH (1),.DEPTH (2))
meta_sys1(
  .clk (clk67),
  .in_sig (~lock),
  .out_sig (w2)
);

meta #(.DATA_WIDTH (1), .DEPTH (2)) 
meta_sys2(
  .clk (clk67),
  .in_sig (~lock),
  .out_sig (w3)
);
	
up_counter #(.WIDTH(WIDTH), .TERM_CNT(DEPTH))
Write_Ptr(
	.clk(MAX10_CLK1_50),
	.reset(w2),
	.en(~w6),
	.count(w4)
);

fibonacci_rom fib_rom(
	.rdadr(w4),
	.rddat(w5)
);

async_fifo #(.WIDTH(WIDTH),.DEPTH(DEPTH)) 
a_fifo(
  .wrClk(MAX10_CLK1_50),
  .wrRst(w2),
  .wrEn(~w6),
  .wrData(w5),
  .rdClk(clk67),
  .rdRst(w3),
  .rdEn(a1),
  .full(w6),
  .empty(LEDR[1]),
  .rdData(w7)
);

display_driver hex_leds (
  .clk        (clk67),
  .dispMode   (1'b1),       
  .oneMsPulse (1'b1),
  .OpReg      (1'b0),         
  .ShowOpReg  (1'b0),       
  .OpCode     (1'b0),
  .ShowOpCode (1'b0), 
  .OpResult   (w7), 
  .HEX0       (HEX0),
  .HEX1       (HEX1),
  .HEX2       (HEX2),
  .HEX3       (HEX3),
  .HEX4       (HEX4),
  .HEX5       (HEX5)
);

endmodule
