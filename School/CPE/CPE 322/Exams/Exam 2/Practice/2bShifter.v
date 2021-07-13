module Shifter(in, s, out);

    input [1:0]in
    input s;
    output [1:0] out;

    assign out[1] = (~s && in[1]) || (s && in[0]);
    assign out[0] = (~s && in[0]);

endmodule

module Decoder(addr, nen, row_sel)  // 3 to 8 decoder
    input [2:0] addr;
    input nen = 0;
    output [7:0] row_sel;
    
    always @(addr, nen)begin
        if(nen)
            row_sel = 0;
        else                // when nen is low
            case(addr)
                0: row_sel = 8'b00000001;
                1: row_sel = 8'b00000010;
                2: row_sel = 8'b00000100;
                3: row_sel = 8'b00001000;
                4: row_sel = 8'b00010000;
                5: row_sel = 8'b00100000;
                6: row_sel = 8'b01000000;
                7: row_sel = 8'b10000000;
            endcase
        end

endmodule


// 8b register with load and synchronous reset
module Register(din, ld, rst, clk, q);
    output [7:0] q;
    input [7:0] din;
    input ld, rst, clk;
    wire q_nxt, temp;
    reg tempreg[7:0];

    assign q_nxt = ld ? din : q;        // qnext will be din if 1, q if 0.

    always@ (posedge clk)
        q <= rst ? 8'h0 : q_nxt;        // q will get 0 if reset is 1, q_nxt if 0.
        tempreg <= rst ? 8'h0 : q_nxt;
endmodule