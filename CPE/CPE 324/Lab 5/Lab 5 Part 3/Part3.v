// Nolan Anderson CPE 324 
// Lab 5 Part 3

module Part3(input A,B,clk,rst,en, output reg S);

	reg [1:0] state = 0;
	reg [1:0] next = 0;

	always @(A, B, state)begin
		case(state)
			0 : begin    S = 0;
				if (A == 0 && B == 0) begin next = 0; end
				else if (A ==1 && B == 1) begin next = 2; end
				else begin next = 1; end
			    end
			1 : begin S = 1;
				if (A == 0 && B == 0) begin next = 0; end
				else if (A ==1 && B == 1) begin next = 2; end
				else begin next = 1; end
			    end
			2 : begin S = 0;
				if (A == 0 && B == 0) begin next = 1; end
				else if (A ==1 && B == 1) begin next = 3; end
				else begin next = 2; end
			    end
			3 : begin S = 1;
				if (A == 0 && B == 0) begin next = 1; end
				else if (A ==1 && B == 1) begin next = 3; end
				else begin next = 2; end
			    end
			endcase
	end

	always @(posedge clk)begin
	  
		if (rst)begin
			state = 0;
		end
		else begin
			if (en) begin state = next; end
		end
	 end

endmodule