`timescale 1ns/1ps
module v_module(input I, output reg X, output Y, Z);
    always @ (I) X <= #5 ~I;
    not #(5) G1 (Y, X);
    assign #5 Z = ~Y;
endmodule


`timescale 1ns/1ps
module tb_v_module();
    reg I;
    wire X, Y, Z;
    initial begin
        I = 0;
    end

    always begin
        I = 0;
        #5;     I = 1;
        #2.5;   I = 0;
        #7.5;   I = 1;
        #50;    I = 0;
        #25;    I = 1;
        #5;     I = 0;
        #5;     I = 1;
    end

    v_module uut(I, X, Y, Z);

endmodule
