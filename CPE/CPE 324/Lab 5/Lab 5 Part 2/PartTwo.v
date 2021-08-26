module Mealy(input A, B, carry, en, rst, clk, output S, cout);
    wire cin, x1, x2, x3;
    wire w0, w1, w2, w3, w4, w5, w6;

	//  Cin value
    DFF A0(carry, clk, rst, en, cin);

	// XOR A and B
    and(w0, A, B);
    or (w1, A, B);
    not(w2, w0);
    and(w3, w2, w1);
	// XOR A, B, and CIN
    and(w4, w3, cin);
    or (w5, w3, cin);
    not(w6, w4);
    and(S, w6, w5);
	// Perform operation on inputs
    and A2(x1, A, B);
    and A3(x2, A, cin);
    and A4(x3, B, cin);
    or A5(cout, x1, x2, x3);
endmodule 


module DFF(input D, clk, rst, en, output reg Q);
    initial
    begin
    Q <= 0;
    end
    always @(posedge clk) begin
    if(rst) Q <= 0;
    else if(en) Q <= D;
    end
endmodule 