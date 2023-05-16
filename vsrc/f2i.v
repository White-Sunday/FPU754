module f2i (a,d,p_post,denorm,invalid);	// convert float to integer
	input [31:0] a;			// float
	output [31:0] d;		// integer
	output p_lost;			// precision lost
	output denorm;			// if a is a denormalized number, the denorm signal outputs a 1
	output invalid;			// inf,nan,out_of_range
	
	reg [31:0] d;			// will be combinational
	reg p_lost;			// will be combinational
	reg invalid;			// will be combinational
	wire hidden_bit = |a[30:23];	// hidden bit: the result of operation "|" for each bit of the bus "a" 
	wire frac_is_not_0 = |a[22:0];
	



