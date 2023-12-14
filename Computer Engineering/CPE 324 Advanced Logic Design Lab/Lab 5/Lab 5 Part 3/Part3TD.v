`timescale 1ns/100 ps

module Part3TD;
	reg A = 0, B = 0, clk = 0, rst = 0, en = 0;
	wire S;

	initial
	  begin

	// 0ns
	rst = 1; A = 0;	B = 0;	en = 1;

	#10 // 10ns
	rst = 0; A = 1;	B = 1;	en = 1;
	
	#10 // 20ns 
	rst = 0; A = 0;	B = 1;	en = 1;

	#10 // 30ns
	rst = 0; A = 1;	B = 0;	en = 1;

	#10 // 40ns
	rst = 1; A = 0;	B = 0;	en = 0;

	#10 // 50ns
	rst = 0; A = 0;	B = 1;	en = 1;
	
	#10 // 60ns
	rst = 0; A = 0;	B = 0;	en = 1;

	#10 // 70ns
	rst = 0; A = 1;	B = 0;	en = 1;
	
	#10 // 80ns
	rst = 0; A = 1;	B = 0;	en = 1;

	#10 // 90 ns
	rst = 0; A = 1;	B = 0;	en = 1;

	#10	//100ns
	rst = 0; A = 0;	B = 1;	en = 1;

	#10 //110ns
	rst = 0; A = 1;	B = 1;	en = 1;

	#10 // 120ns
	rst = 0; A = 1;	B = 1;	en = 1;
	
	#10 // 130ns
	rst = 0; A = 1;	B = 1;	en = 1;

	#10 // 140ns
	rst = 0; A = 0;	B = 0;	en = 1;

	#10 // 150ns
	rst = 0; A = 1;	B = 1;	en = 1;
	
	#10 // 160ns
	rst = 0; A = 1;	B = 1;	en = 1;

	#10 // 170ns
	rst = 0; A = 0;	B = 1;	en = 1;

	#10 // 180ns
	rst = 0; A = 1;	B = 1;	en = 1;

	#10 // 190ns
	rst = 0; A = 1;	B = 0;	en = 1;
	
	#10 // 200ns
	rst = 0; A = 0;	B = 0;	en = 1;
	end


  always
      begin
      clk = #5 ~clk;
      end

    Part3 uut (.A(A),.B(B),.clk(clk),.rst(rst),.en(en),.S(S)); 

endmodule