import mine::*;

module test0(arb_if arbif);
	int seed = 500;
	Packet p;
	
	initial begin
		
		p=new();
		repeat(200)
		begin
			p.randomize();
			arbif.REQ_TIME0 <= p.req_time_t;
			repeat (p.wait_time_t) @(arbif.cb);
			arbif.GEN_REQ[0] <= 1'b1;
			@(posedge arbif.REQ[0]);
			arbif.GEN_REQ[0] <= 1'b0;
		end

	end
endmodule :test0		

module test1(arb_if arbif);
	int seed = 500;
	Packet p;
	
	initial begin
		
		p=new();
		repeat(200)
		begin
			p.randomize();
			p.randomize();
			arbif.REQ_TIME1 <= p.req_time_t;
			repeat (p.wait_time_t) @(arbif.cb);
			arbif.GEN_REQ[1] <= 1'b1;
			@(posedge arbif.REQ[1]);
			arbif.GEN_REQ[1] <= 1'b0;
		end

	end
endmodule :test1

module test2(arb_if arbif);
	int seed = 500;
	Packet p;
	
	initial begin
		
		p=new();
		repeat(200)
		begin
			p.randomize();
			p.randomize();
			p.randomize();
			arbif.REQ_TIME2 <= p.req_time_t;
			repeat (p.wait_time_t) @(arbif.cb);
			arbif.GEN_REQ[2] <= 1'b1;
			@(posedge arbif.REQ[2]);
			arbif.GEN_REQ[2] <= 1'b0;
		end

	end
endmodule :test2	

module test3(arb_if arbif);
	int seed = 500;
	Packet p;
	
	initial begin
		
		p=new();
		repeat(200)
		begin
			p.randomize();
			p.randomize();
			p.randomize();
			p.randomize();
			arbif.REQ_TIME3 <= p.req_time_t;
			repeat (p.wait_time_t) @(arbif.cb);
			arbif.GEN_REQ[3] <= 1'b1;
			@(posedge arbif.REQ[3]);
			arbif.GEN_REQ[3] <= 1'b0;
		end

	end
endmodule :test3		

module reset_test(arb_if arbif);
	int seed = 500;
	Reset r;
	initial begin
		r=new();
		repeat(200)
		begin
			r.randomize();
			repeat(r.reset_wait_t) @(arbif.cb);
			arbif.RESET <= 1'b1;
			repeat(r.reset_hold_t) @(arbif.cb);
			arbif.RESET <= 1'b0;
		end
	$stop;
	end
endmodule : reset_test