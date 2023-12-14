`timescale 1ns/100 ps

module lab5_part2TB;
	reg A = 0, B = 0, carry = 0, clk = 0, rst = 0, en = 0;
	wire S, cout;

	initial
	  begin

	//0ns
	rst = 1;	A = 1;	B = 1;	en = 1;

	#10	//10ns
	rst = 0;	A = 0;	B = 1;	en = 1;
	
	#10	//20ns
	rst = 0;	A = 1;	B = 0;	en = 1;

	#10	//30ns
	rst = 0;	A = 0;	B = 0;	en = 1;

	#10	//40ns
	rst = 0;	A = 1;	B = 1;	en = 1;

	#10	//50ns
	rst = 0;	A = 1;	B = 1;	en = 1;
	
	#10 //60ns
	rst = 1;	A = 0;	B = 0;	en = 1;

	#10	//70ns
	rst = 0;	A = 0;	B = 1;	en = 1;
	
	#10	//80ns
	rst = 0;	A = 1;	B = 0;	en = 1;
	end


  always
      begin
      clk = #5 ~clk;
      end

    Mealy uut (.A(A),.B(B),.carry(cout),.en(en),.rst(rst),.clk(clk),.S(S),.cout(cout)); 

endmodule