`include "./vsrc/fmul/wallace_24x24.v"

module wallace_24x24_product (a,b,z);	// 8*8 wallacetree product
	input [23:0] a;
	input [23:0] b;
	output [47:0] z;
	wire [47:8] x;
	wire [47:8] y;
	wire [47:8] z_high;
	wire [7:0] z_low;
	wallace_24x24 wt_partial (a,b,x,y,z_low);
	assign z_high = x+y;
	assign z = {z_high, z_low};	// product
endmodule
