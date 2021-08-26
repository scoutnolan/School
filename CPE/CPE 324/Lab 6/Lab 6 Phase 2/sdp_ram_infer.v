module sdp_ram_infer #(
  parameter WIDTH,
  parameter DEPTH,
  parameter DEPTH_LOG
) (
  input                  wrClk,
  input                  rdClk,
  input                  rdRst,
  input                  wrEn,
  input  [WIDTH-1:0]     wrDat,
  input  [DEPTH_LOG-1:0] wrAdr,
  input                  rdEn,
  input  [DEPTH_LOG-1:0] rdAdr,
  output [WIDTH-1:0]     rdDat    
);

  reg  [WIDTH-1:0] rdDat_i;
  reg  [WIDTH-1:0] ram [0:DEPTH-1];

  always @(posedge wrClk) begin
    if (wrEn) ram[wrAdr] <= wrDat;
  end

  always @(posedge rdClk) begin
    if (rdRst) rdDat_i <= 'h0;
    else if (rdEn) rdDat_i <= ram[rdAdr];
  end
  assign rdDat = rdDat_i;

endmodule
