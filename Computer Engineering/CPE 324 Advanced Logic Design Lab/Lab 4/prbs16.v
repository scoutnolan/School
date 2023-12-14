module prbs16 #(
  parameter NUM_CYC = 1
) (
  input         clk,
  input         rst,
  input         shiftEn,
  output [15:0] outSeq
);

  reg [15:0] lfsrReg;
  
  always @(posedge clk)
  begin
        if (rst | lfsrReg == 16'h0000) begin // check if reset or failsafe
            lfsrReg[15:0] = 16'hFFFF; 			// reset everything to 1
        end
        else if (shiftEn) begin
            lfsrReg[0] <= lfsrReg[15] ^ lfsrReg[12] ^ lfsrReg[11] ^ lfsrReg[10];
            lfsrReg[15:1] <= lfsrReg[14:0];
        end
  end

  assign outSeq = lfsrReg;
endmodule