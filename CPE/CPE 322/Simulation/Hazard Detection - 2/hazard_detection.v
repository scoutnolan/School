`timescale 1ns/1ps
module hazard (input a, b, c, d, output z);
    wire w1;
    wire w2;
    wire w3;
    wire w4;

    nor #(1) a1 (w1, d, ~a);
    nor #(1) a2 (w2, a, c);
    nand #(1) a3 (w4, a, b);
    or #(1) a4 (w3, w1, w2);
    nand #(1) a5 (z, w3, w4);
endmodule

`timescale 1ns/1ps
module tb_hazard ();
    reg a, b, c, d;
    wire z;

    initial begin
        a = 0;
		b = 0;
		c = 0;
		d = 0;
    end

    always begin
        a = 0; b = 0; c = 0; d = 0;
        #10;   
        a = 1; b = 0; c = 0; d = 0;  
        #10;  
        a = 0; b = 0; c = 0; d = 1;  
        #10;  
        a = 1; b = 0; c = 0; d = 1;  
        #10;  

        a = 0; b = 0; c = 1; d = 1;  
        #10;  
        a = 1; b = 0; c = 1; d = 1; 
        #10;  

        a = 0; b = 0; c = 1; d = 0;  
        #10;  
        a = 1; b = 0; c = 1; d = 0; 
        #10;  

        a = 0; b = 1; c = 0; d = 0;  
        #10;  
        a = 1; b = 1; c = 0; d = 0; 
        
        a = 0; b = 1; c = 0; d = 1;  
        #10;  
        a = 1; b = 1; c = 0; d = 1;
        #10;  
        
        a = 0; b = 1; c = 1; d = 1;  
        #10;  
        a = 1; b = 1; c = 1; d = 1;
        #10;  
        
        a = 0; b = 1; c = 1; d = 0;  
        #10;  
        a = 1; b = 1; c = 1; d = 0; // HAZARD HERE
        #10;  
        
        a = 0; b = 1; c = 1; d = 0;  // HAZARD HERE
        #10;  
        a = 1; b = 1; c = 1; d = 0; 
        #10;  

        // B transitions
        
        a = 0; b = 0; c = 0; d = 0;  
        #10;  
        a = 0; b = 1; c = 0; d = 0;   
        #10;  
        
        a = 0; b = 0; c = 0; d = 1;  
        #10;  
        a = 0; b = 1; c = 0; d = 1;   
        #10;  
        
        a = 0; b = 0; c = 1; d = 1;  
        #10;  
        a = 0; b = 1; c = 1; d = 1;   
        #10;  
        
        a = 0; b = 0; c = 1; d = 0;  
        #10;  
        a = 0; b = 1; c = 1; d = 0;   
        #10;  
        
        a = 1; b = 0; c = 0; d = 0;  
        #10;  
        a = 1; b = 1; c = 0; d = 0;   
        #10;  
        
        a = 1; b = 0; c = 0; d = 1;  
        #10;  
        a = 1; b = 1; c = 0; d = 1;  
        #10;  
        
        a = 1; b = 0; c = 1; d = 1;  
        #10; 
        a = 1; b = 1; c = 1; d = 1;   
        #10;  
        
        a = 1; b = 0; c = 1; d = 0;  
        #10;  
        a = 1; b = 1; c = 1; d = 0;   
        #10;  

        // C transitions
        
        a = 0; b = 0; c = 0; d = 0;  
        #10;  
        a = 0; b = 0; c = 1; d = 0;  
        #10;  
        
        a = 0; b = 1; c = 0; d = 0;  
        #10;  
        a = 0; b = 1; c = 1; d = 0;  
        #10;  
        
        a = 1; b = 1; c = 0; d = 0;  
        #10;  
        a = 1; b = 1; c = 1; d = 0; 
        #10;  
        
        a = 1; b = 0; c = 0; d = 0;  
        #10;  
        a = 1; b = 0; c = 1; d = 0;  
        #10;  
        
        a = 0; b = 0; c = 0; d = 1;  
        #10;  
        a = 0; b = 0; c = 1; d = 1;  
        #10;  
        
        a = 0; b = 1; c = 0; d = 1;  
        #10;  
        a = 0; b = 1; c = 1; d = 1;  
        #10;  
        
        a = 1; b = 1; c = 0; d = 1;  
        #10;  
        a = 1; b = 1; c = 1; d = 1;  
        #10;  
        
        a = 1; b = 0; c = 0; d = 1;  
        #10;  
        a = 1; b = 0; c = 1; d = 1;  
        #10;  

        // D transitions
        
        a = 0; b = 0; c = 0; d = 0;  
        #10;  
        a = 0; b = 0; c = 0; d = 1;   
        #10;  
        
        a = 0; b = 1; c = 0; d = 0;  
        #10;  
        a = 0; b = 1; c = 0; d = 1;   
        #10;  
        
        a = 1; b = 1; c = 0; d = 0;  
        #10;  
        a = 1; b = 1; c = 0; d = 1;   
        #10;  
        
        a = 1; b = 0; c = 0; d = 0;  
        #10;  
        a = 1; b = 0; c = 0; d = 1;   
        #10;  
        
        a = 0; b = 0; c = 1; d = 0;  
        #10;  
        a = 0; b = 0; c = 1; d = 1;   
        #10;  
        
        a = 0; b = 1; c = 1; d = 0;  
        #10;  
        a = 0; b = 1; c = 1; d = 1;   
        #10;  
        
        a = 1; b = 1; c = 1; d = 0;  
        #10;  
        a = 1; b = 1; c = 1; d = 1;   
        #10;  
        
        a = 1; b = 0; c = 1; d = 0;  
        #10;  
        a = 1; b = 0; c = 1; d = 1;   
        #10;  
        end
    
    hazard uut (.a (a), .b (b), .c (c), .d (d), .z (z));
endmodule
