import mine::*;

module test0(arb_if arbif);
	int seed = 1;
	Packet p;
	initial begin
		p = new();
		p.srandom(seed);
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
	int seed = 2;
	Packet p;
	initial begin
		p = new();
		p.srandom(seed);
		repeat(200)
		begin
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
	int seed = 3;
	Packet p;
	initial begin
		p = new();
		p.srandom(seed);
		repeat(200)
		begin
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
	int seed = 4;
	Packet p;
	initial begin
		p = new();
		p.srandom(seed);
		repeat(200)
		begin
			p.randomize();
			arbif.REQ_TIME3 <= p.req_time_t;
			repeat (p.wait_time_t) @(arbif.cb);
			arbif.GEN_REQ[3] <= 1'b1;
			@(posedge arbif.REQ[3]);
			arbif.GEN_REQ[3] <= 1'b0;
		end
	end
endmodule :test3	

module test4(arb_if arbif);
	int seed = 5;
	Packet p;
	initial begin
		p = new();
		p.srandom(seed);
		repeat(200)
		begin
			p.randomize();
			arbif.REQ_TIME4 <= p.req_time_t;
			repeat (p.wait_time_t) @(arbif.cb);
			arbif.GEN_REQ[4] <= 1'b1;
			@(posedge arbif.REQ[4]);
			arbif.GEN_REQ[4] <= 1'b0;
		end
	end
endmodule :test4	

module test5(arb_if arbif);
	int seed = 6;
	Packet p;
	initial begin
		p = new();
		p.srandom(seed);
		repeat(200)
		begin
			p.randomize();
			arbif.REQ_TIME5 <= p.req_time_t;
			repeat (p.wait_time_t) @(arbif.cb);
			arbif.GEN_REQ[5] <= 1'b1;
			@(posedge arbif.REQ[5]);
			arbif.GEN_REQ[5] <= 1'b0;
		end
	end
endmodule :test5	

module test6(arb_if arbif);
	int seed = 7;
	Packet p;
	initial begin	
		p = new();
		p.srandom(seed);
		repeat(200)
		begin
			p.randomize();
			arbif.REQ_TIME6 <= p.req_time_t;
			repeat (p.wait_time_t) @(arbif.cb);
			arbif.GEN_REQ[6] <= 1'b1;
			@(posedge arbif.REQ[6]);
			arbif.GEN_REQ[6] <= 1'b0;
		end
	end
endmodule :test6	

module test7(arb_if arbif);
	int seed = 8;
	Packet p;	
	initial begin
		p = new();
		p.srandom(seed);
		repeat(200)
		begin
			p.randomize();
			arbif.REQ_TIME7 <= p.req_time_t;
			repeat (p.wait_time_t) @(arbif.cb);
			arbif.GEN_REQ[7] <= 1'b1;
			@(posedge arbif.REQ[7]);
			arbif.GEN_REQ[7] <= 1'b0;
		end
	end
endmodule :test7

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