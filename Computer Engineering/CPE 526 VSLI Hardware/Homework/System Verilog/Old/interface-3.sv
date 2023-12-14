interface arb_if(input bit clk);
	logic RESET;
	integer REQ_TIME0,REQ_TIME1,REQ_TIME2,REQ_TIME3;
	logic [0:3] REQ,GRANT,GEN_REQ;
	clocking cb  @(posedge clk);
	endclocking
endinterface