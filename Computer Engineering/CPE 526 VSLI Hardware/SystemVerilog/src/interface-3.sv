interface arb_if(input bit clk);
	logic RESET;
	integer REQ_TIME0,REQ_TIME1,REQ_TIME2,REQ_TIME3,REQ_TIME4,REQ_TIME5,REQ_TIME6,REQ_TIME7;
	logic [0:7] REQ,GRANT,GEN_REQ;
	property a;
		@(clk)
		$onehot(GRANT) == 1 | GRANT == 8'b0;
	endproperty;
	one_hot_assert: assert property(a);
	clocking cb  @(posedge clk);
	endclocking
endinterface