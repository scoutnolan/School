// Nolan Anderson CPE 324 
// Lab 5 Part 1

module PartOne(input A, B,  clk, rst, en, output reg S);

	reg state = 0;
	reg next = 0;

	always @( A,B,state)begin
		case(state)
			0 : if (A == 0 && B == 0) begin next = 0; S= 0; end
				else if (A ==1 && B == 1) begin next = 1; S = 0; end
				else begin next = 0; S = 1; end
			1 : if (A == 0 && B == 0) begin next = 0; S= 1; end
				else if (A ==1 && B == 1) begin next = 1; S = 1; end
				else begin next = 1; S = 0; end
			endcase
	end

	always @(posedge  clk)begin
	  
		if (rst)begin
			state = 0;
		end
		else begin
			if (en) begin state = next; end
		end
	 end
endmodule