package mine;
	class Packet;
	rand integer req_time_t,wait_time_t;
	constraint c {wait_time_t>100; wait_time_t<300;
			req_time_t>0;req_time_t<101;}
	endclass : Packet

	class Reset;
	rand integer reset_wait_t,reset_hold_t;
	constraint c {reset_wait_t>300;reset_wait_t<500;
			reset_hold_t>3;reset_hold_t<10;}
	endclass : Reset	
endpackage : mine;