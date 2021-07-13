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

endmodule
