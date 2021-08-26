`timescale 1ns/1ps
module JKFF(input J, K, CLK, CLR, output Q);
    reg Qi;
    always @(negedge CLK) begin
        if(CLR == 1) begin Qi <= 1'b0; end
        else begin 
            if(J & ~K) Qi <= 1'b1;
            else if (K & ~J) Qi <= 1'b0;
            else if(J & K) Qi <= ~Qi;
        end
    end
    assign Q = Qi;
endmodule

`timescale 1ns/1ps
module tb_JKFF();
    reg clk, clr, j, k;
    wire q;

    initial begin
        clk = 0;
        clr = 1;
    end

    always #5 clk = ~clk;
    always #100 clr = ~clr;

    always begin
        j = 0; k = 0;
        #10; j = 1; k = 0;        
        #10; j = 0; k = 1;
        #50; j = 0; k = 1;
        #20; j = 1; k = 0;
        #400;
   end

   JKFF uut (j, k, clk, clr, q);

endmodule