module sum_log(input [3:0] a, b, c, d, e, f, g, h, output [6:0] sum)

    wire[4:0] w1, w2, w4, w5;       // increasing by one bit
    wire[5:0] w3, w6;

    w1 = a + b;         // add them all together
    w2 = c + d;
    w3 = w1 + w2;
    w4 = e + f;
    w5 = g + f;h
    w6 = w4 + w5;
    sum = w3 + w6;      // assign the sum output.
endmodule
