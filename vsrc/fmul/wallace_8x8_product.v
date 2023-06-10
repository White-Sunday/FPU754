`include "./vsrc/fmul/wallace_8x8.v"

module wallace_8x8_product (a,b,z);	// 8*8 wallacetree product
	input [7:0] a;
	input [7:0] b;
	output [15:0] z;
	wire [15:5] x;
	wire [15:5] y;
	wire [15:5] z_high;
	wire [4:0] z_low;
	wallace_8x8 wt_partial (a,b,x,y,z_low);
	assign z_high = x+y;
	assign z = {z_high, z_low};	// product
endmodule
