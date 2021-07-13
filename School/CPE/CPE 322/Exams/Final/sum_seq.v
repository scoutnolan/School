module sum_seq(input [3:0] a, b, c, d, e, f, g, h, output [6:0] sum)

    wire w1, w2, w3, w4, w5, w6;

    wire[4:0] w1;       // increasing by one bit
    wire[5:0] w2;
    wire[6:0] w3;
    wire[7:0] w4;
    wire[8:0] w5;
    wire[9:0] w6;

    w1 = a + b;         // add them all together
    w2 = w1 + c;
    w3 = w2 + d;
    w4 = w3 + e;
    w5 = w4 + f;
    w6 = w5 + g;
    sum = w5 + h;       // sum output

endmodule
