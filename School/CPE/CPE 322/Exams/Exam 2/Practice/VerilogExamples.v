// Exam 2 Problem 8.10
// Hammings code
// Hammings code is used for error detection and correction in communication and memory systems. 
// Part C

module error_detection(data, PARITY, Syndrome)

input [6:0] data;           // 7 bit input
input PARITY;
output [2:0] Syndrome;      // 3 output options

// Even parity (1) = use XOR
// Odd parity  (0) = use XNOR

assign Syndrome[2] = (PARITY) ? (data[3] ^ data[4] ^ data[5] ^ data[6]) : 
                                (data[3] ~^ data[4] ~^ data[5] ~^ data[6]);
                        
assign Syndrome[1] = (PARITY) ? (data[1] ^ data[2] ^ data[5] ^ data[6]) : 
                                (data[1] ~^ data[2] ~^ data[5] ~^ data[6]);

assign Syndrome[0] = (PARITY) ? (data[0] ^ data[1] ^ data[4] ^ data[6]) : 
                                (data[0] ~^ data[1] ~^ data[4] ~^ data[6]);
endmodule 


// How many LUT 4's for this module? 
// 7 or 8


// 6.18 example
// Went from a function to the actual verilog code. 

module example_6_18(a, b, c, d, e, f, Z);

    wire t1, t2, t3, t4, Z;
    wire a, b, c, d, e, f;
    output Z;

    and c0(t1, a, ~b, c, d, e, f);      // t1 = ab'cdef
    and c1(t2, ~a, b, ~c, ~d, e);       // t2 = a'bc'de
    and c2(t3, ~b, ~c, e, ~f);          // t3 = b'c'ef'
    and c3(t4, a, b, c, d, ~e, f);      // t4 = abcde'f
    or c4(Z, t1, t2, t3, t4);           // z = t1 + t2 + t3 + t4

    // Z(a,b,c,d,e,f) - implement using LUT 4's, you could do shannons
    // or you can just write it straight out.

endmodule


// Textbook problem 8.24 
module Comparator(A, B, EQ, GT)    
    parameter N;            // define the length of the input vectors.
    input [N - 1:0] A;      // Input defined as length of N-1 -> 0.
    input [N - 1:0] B;
    output reg EQ, GT;      // Single bit, 0 or 1.
    integer i;
    reg LT = 0;
    always@(A,B) begin
        EQ = 1;  GT = 0; LT = 0;
        for(i = N-1; i >= 0; i--) begin             // start with the high values first
            if(A[i] > B[i] && LT == 0 && GT == 0) begin
                GT = 1'b1;
                LT = 1'b0;
            end
            else if(A[i] < B[i] && LT == 1'b0 && GT == 1'b0) begin
                LT = 1'b1;
                GT = 1'b0;
            end
        end
    end

endmodule
