module prob5_moore(input clk, rst, X1, X2, X3, X4, output Z1, Z2);
    reg [3:0] State;

    always @(posedge clk) begin
        if(rst)
            state <= 4'b0001;
        else begin
            State[0] <= (State[0] & ~X1) | (State[1] & X2) | (State[3] + ~X4);
            State[1] <= (State[0] & X1) | (State[3] & X4);
            State[2] <= (State[1] & ~X1) | (State[2] & ~X3);
            State[3] <= (State[2] & X3);
        end
    end

    assign Z1 <= Q0 + Q2 + Q3;
    assign Z2 <= Q1 + Q3;
endmodule