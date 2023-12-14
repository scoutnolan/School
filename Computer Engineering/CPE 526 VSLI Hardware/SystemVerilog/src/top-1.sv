module top;
	bit clk;
	always #5 clk=~clk;

	arb_if arbif(clk);

	prio_enc_arb A1 (.REQ (arbif.REQ),
		    .GRANT (arbif.GRANT),
		    .RESET (arbif.RESET),
		    .CLK (clk));
	req_dev r0 (.GEN_REQ (arbif.GEN_REQ[0]),
		    .REQ_TIME (arbif.REQ_TIME0),
		    .REQUEST (arbif.REQ[0]),
		    .GRANT (arbif.GRANT[0]),
		    .RESET (arbif.RESET),
		    .CLK(clk));
	req_dev r1 (.GEN_REQ (arbif.GEN_REQ[1]),
		    .REQ_TIME (arbif.REQ_TIME1),
		    .REQUEST (arbif.REQ[1]),
		    .GRANT (arbif.GRANT[1]),
		    .RESET (arbif.RESET),
		    .CLK(clk));
	req_dev r2 (.GEN_REQ (arbif.GEN_REQ[2]),
		    .REQ_TIME (arbif.REQ_TIME2),
		    .REQUEST (arbif.REQ[2]),
		    .GRANT (arbif.GRANT[2]),
		    .RESET (arbif.RESET),
		    .CLK(clk));
	req_dev r3 (.GEN_REQ (arbif.GEN_REQ[3]),
		    .REQ_TIME (arbif.REQ_TIME3),
		    .REQUEST (arbif.REQ[3]),
		    .GRANT (arbif.GRANT[3]),
		    .RESET (arbif.RESET),
		    .CLK(clk));
	req_dev r4 (.GEN_REQ (arbif.GEN_REQ[4]),
		    .REQ_TIME (arbif.REQ_TIME4),
		    .REQUEST (arbif.REQ[4]),
		    .GRANT (arbif.GRANT[4]),
		    .RESET (arbif.RESET), 
		    .CLK(clk));
	req_dev r5 (.GEN_REQ (arbif.GEN_REQ[5]),
		    .REQ_TIME (arbif.REQ_TIME5),
		    .REQUEST (arbif.REQ[5]),
		    .GRANT (arbif.GRANT[5]),
		    .RESET (arbif.RESET),
		    .CLK(clk));
	req_dev r6 (.GEN_REQ (arbif.GEN_REQ[6]),
		    .REQ_TIME (arbif.REQ_TIME6),
		    .REQUEST (arbif.REQ[6]),
		    .GRANT (arbif.GRANT[6]),
		    .RESET (arbif.RESET),
		    .CLK(clk));
	req_dev r7 (.GEN_REQ (arbif.GEN_REQ[7]),
		    .REQ_TIME (arbif.REQ_TIME7),
		    .REQUEST (arbif.REQ[7]),
		    .GRANT (arbif.GRANT[7]),
		    .RESET (arbif.RESET),
		    .CLK(clk));

	test0 t0 (arbif);
	test1 t1 (arbif);	
	test2 t2 (arbif);
	test3 t3 (arbif);
	test4 t4 (arbif);
	test5 t5 (arbif);
	test6 t6 (arbif);
	test7 t7 (arbif);
	reset_test t8 (arbif);
endmodule : top