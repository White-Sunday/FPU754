`include "./vsrc/fsqrt/wallace_24x28.v"

module wallace_24x28_product (a,b,z);	// 24*28 wallacetree product
	input [23:0] a;
	input [27:0] b;
	output [51:0] z;
	wire [51:8] x;
	wire [51:8] y;
	wire [51:8] z_high;
	wire [7:0] z_low;
	wallace_24x28 wt_partial (a,b,x,y,z_low);
	assign z_high = x+y;
	assign z = {z_high, z_low};	// product
endmodule
