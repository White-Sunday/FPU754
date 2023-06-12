`include "./vsrc/fdiv/wallace_26x26.v"

module wallace_26x26_product (a,b,z);	// 26*26 wallacetree product
	input [25:0] a;
	input [25:0] b;
	output [51:0] z;
	wire [51:8] x;
	wire [51:8] y;
	wire [51:8] z_high;
	wire [7:0] z_low;
	wallace_26x26 wt_partial (a,b,x,y,z_low);
	assign z_high = x+y;
	assign z = {z_high, z_low};	// product
endmodule
