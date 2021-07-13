`timescale 1ns/100 ps

module PartOneTD;
	reg A = 0, B = 0, clk = 0, rst = 0, en = 0;
	wire S;

	initial
	  begin

	#10	// 0ns
	rst = 1; A = 1;	B = 1;	en = 1;

	#10	// 10ns
	rst = 0; A = 0;	B = 1;	en = 1;
	
	#10 // 20ns
	rst = 0; A = 1;	B = 0;	en = 1;

	#10 // 30ns
	rst = 0; A = 0;	B = 0;	en = 1;

	#10 // 40ns 
	rst = 0; A = 1;	B = 1;	en = 1;

	#10 // 50ns
	rst = 0; A = 1;	B = 1;	en = 1;
	
	#10 // 60ns
	rst = 1; A = 0;	B = 0;	en = 1;

	#10 // 70 ns
	rst = 0; A = 0;	B = 1;	en = 1;
	
	#10 // 80 ns
	rst = 0; A = 1;	B = 0;	en = 1;
	end

  always
      begin
      clk = #5 ~clk;
      end

   PartOne uut (.A(A),.B(B),.clk(clk),.en(en),.rst(rst),.S(S)); 

endmodule


