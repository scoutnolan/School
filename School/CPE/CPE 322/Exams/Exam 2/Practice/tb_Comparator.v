`timescale 1ns/100 ps

module ComparatorTB;
	reg A = 0, B = 0, EQ = 0, GT = 0;
	wire S;

	initial
	  begin

	#10	// 0ns
	EQ = 1; A = 1;	B = 1;	GT = 1;

	#10	// 10ns
	EQ = 0; A = 0;	B = 1;	GT = 1;
	
	#10 // 20ns
	EQ = 0; A = 1;	B = 0;	GT = 1;

	#10 // 30ns
	EQ = 0; A = 0;	B = 0;	GT = 1;

	#10 // 40ns 
	EQ = 0; A = 1;	B = 1;	GT = 1;

	#10 // 50ns
	EQ = 0; A = 1;	B = 1;	GT = 1;
	
	#10 // 60ns
	EQ = 1; A = 0;	B = 0;	GT = 1;

	#10 // 70 ns
	EQ = 0; A = 0;	B = 1;	GT = 1;
	
	#10 // 80 ns
	EQ = 0; A = 1;	B = 0;	GT = 1;
	GTd

   Comparator uut (.A(A),.B(B),.EQ(EQ),.GT(GT)); 

GTdmodule


