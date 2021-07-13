module prob5_moore(input clk, rst, X1, X2, X3, X4, output Z1, Z2);
    reg[3:0] State;
    parameter S0 = 4'b1000, S1 = 4'b0100, S2 = 4'b0010, S3 = 4'b0001;
    
    always@(State) begin
        case(State)
            S0: Z1 <= 1; Z2 <= 0;
            S1: Z1 <= 0; Z2 <= 1;
            S2: Z1 <= 1; Z2 <= 0;
            S3: Z1 <= 1; Z2 <= 1;
            default Z1 <= 0; Z2 <= 0;
        endcase
    end
    
    always @(posedge clk or rst)begin
        if(rst)
            State <= S0;
        case(State) 
            S0: if(X1 == 1) begin State <= S1; end else State <= S0; 
            S1: if(X2 == 1) begin State <= S0; end else State <= S2; 
            S2: if(X3 == 1) begin State <= S3; end else State <= S2; 
            S3: if(X4 == 1) begin State <= S1; end else State <= S0; 
            default State <= S0;
        endcase
    end
endmodule 