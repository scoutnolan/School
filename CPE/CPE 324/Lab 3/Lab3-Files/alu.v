module alu (
  input    clk,
  input  [7:0]  operandA,
  input  [7:0]  operandB,
  input  [2:0]  opCode,
  output reg [15:0] opResult
);

  always @(posedge clk)
  begin
  case (opCode[2:0])
	3'd0	: opResult = operandA + operandB;		// OPCODE 0, ADD.
	3'd1	: opResult = operandA - operandB;		// OPCODE 1, SUB.
	3'd2	: opResult = operandA ^ operandB;		// OPCODE 2, XOR.
	3'd3	: opResult = operandA & operandB;		// OPCODE 3, AND.
	3'd4	: opResult = operandA | operandB;		// OPCODE 4, OR.
	3'd5	: opResult = operandA * operandB;		// OPCODE 5, MUL.
	3'd6	: opResult = operandA << operandB;		// OPCODE 6, SL.
	3'd7	: opResult = operandA >> operandB;		// OPCODE 7, SR.
	default : opResult = operandA + operandB;		// Defualt case.
  endcase
  end
endmodule


