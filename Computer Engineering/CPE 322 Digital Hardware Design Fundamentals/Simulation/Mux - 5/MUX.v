`timescale 1ns/1ps
module MUX(input [5:0] I, [2:0] S, output reg O);
    always @ (I or S) begin
        case(S)
        3'b000 : O = I[0]; 
        3'b001 : O = I[1]; 
        3'b010 : O = I[2]; 
        3'b011 : O = I[3]; 
        3'b100 : O = I[4]; 
        3'b101 : O = I[5]; 
        3'b110 : O = I[2]; 
        3'b111 : O = I[3]; 
        default : O = I[0]; 
        endcase
    end
endmodule

`timescale 1ns/1ps
module tb_MUX();
    reg clk2, clk3, clk4, clk5;
    reg [2:0] sel;
    wire out;

    initial begin
        clk2 = 0;
        clk3 = 0;
        clk4 = 0;
        clk5 = 0;
        sel = 0;
    end

    always #5 clk2 = ~clk2;
    always #10 clk3 = ~clk3;
    always #15 clk4 = ~clk4;
    always #20 clk5 = ~clk5;
    always #100 sel = sel + 3'b001;

    MUX uut ({clk5, clk4, clk3, clk2, 1'b1, 1'b0}, sel, out);

endmodule