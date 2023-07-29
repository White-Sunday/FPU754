`include "./vsrc/fdiv/wallace_26x24.v"

module wallace_24x26 (a,b,x,y,z_low);	// 24*26 wallacetree
	input [23:0] a;
	input [25:0] b;
	output [49:8] x;
	output [49:8] y;
	output [7:0] z_low;
	wallace_26x24 wt_partial (b,a,x,y,z_low);
endmodule
