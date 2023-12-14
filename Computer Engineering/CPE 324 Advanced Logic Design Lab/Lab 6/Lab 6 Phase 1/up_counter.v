module up_counter #(parameter WIDTH, parameter TERM_CNT)
(input clk, reset, en, output reg [WIDTH - 1: 0] count);

    always @ (posedge clk) begin
        if(reset) begin count = 0; end
        else if(en) begin count = count + 1; end
        if(count == (2**(WIDTH)-1)) begin count = 0; end
    end
endmodule

