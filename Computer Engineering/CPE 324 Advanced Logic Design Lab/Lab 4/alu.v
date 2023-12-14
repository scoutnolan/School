module alu #(
  parameter DATA_WIDTH
) (
  input    clk,
  input  [15:0]  operandA,
  input  [15:0]  operandB,
  input  [2:0]  opCode,
  output [31:0] opResult
);

  reg  signed [31:0] result;
  reg  signed [31:0] array[7:0];
  reg  [2:0] regopCode;
  
  always @(posedge clk)
  begin
    array[0] <= operandA + operandB;
	 array[1] <= operandA - operandB;
	 array[2] <= operandA ^ operandB;
	 array[3] <= operandA & operandB;
	 array[4] <= operandA | operandB;
	 array[5] <= operandA[15:0] *  operandB[15:0];
	 array[6] <= operandA[15:0] << operandB[3:0];
	 array[7] <= operandA[15:0] >> operandB[3:0];
	 regopCode <= opCode;

  end
  assign opResult = array[regopCode];
  
endmodule
