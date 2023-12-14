`timescale 1ps/1ps

module ring_osc (output z);
    reg[8:0] inv;
    integer i;
    initial begin inv = 0; end
    assign z = inv[0];
    always @(*) begin
        #200 inv[0] <= ~inv[8];
        for(i=1 ; i < 9; i = i+1) begin
        #200 inv[i] <= ~inv[i-1];
        end
    end
endmodule 