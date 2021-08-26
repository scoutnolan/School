module  D_Flip_Flop # (
  parameter WIDTH
  )
  (
  input clk,
  input [WIDTH-1:0] D,
  output reg [WIDTH-1:0] Q
);

always@(posedge clk) begin
  Q = D;
end

endmodule
