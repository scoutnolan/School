// Textbook problem 8.24 
module Comparator(A, B, EQ, GT);    
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