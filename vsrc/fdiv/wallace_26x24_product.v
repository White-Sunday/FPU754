`include "./vsrc/fdiv/wallace_26x24.v"

module wallace_26x24_product (a,b,z);	// 26*24 wallacetree product
	input [25:0] a;
	input [23:0] b;
	output [49:0] z;
	wire [49:8] x;
	wire [49:8] y;
	wire [49:8] z_high;
	wire [7:0] z_low;
	wallace_26x24 wt_partial (a,b,x,y,z_low);
	assign z_high = x+y;
	assign z = {z_high, z_low};	// product
endmodule
