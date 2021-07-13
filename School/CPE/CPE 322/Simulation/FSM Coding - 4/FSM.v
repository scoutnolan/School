`timescale 1ns/1ps
module tb_FSM();
    reg clk; 
    reg rst;
    reg N;
    wire Sh;

    initial begin
        clk = 0;
        rst = 1;
    end

    always #5 clk = ~clk;
    always #20 rst = 0;

    always begin
        N = 0;
        #40; N = 1;
        #20; N = 0;
        #80; N = 1;
        #20; N = 0;
    end

    FSM uut (N, rst, clk, Sh);
    
endmodule

`timescale 1ns/1ps
module FSM(input N, input rst, input clk, output reg Sh);
    reg [1:0] state;
    reg [1:0] next ;

    always @(state, N) begin
        case(state)
            0: begin
                next <= N? 1:0;
                Sh <= N? 1:0;
            end
            1: begin
                next  <= 2;
                Sh <= 1;
            end
            2: begin
                next  <= 3;
                Sh <= 1;
            end
            default: begin
                next  <= 0;
                Sh <= 1;
            end
    endcase
    end
        
    always @(posedge clk) begin
        if (rst)
            state <= 0;
        else
            state <= next;
    end
endmodule

