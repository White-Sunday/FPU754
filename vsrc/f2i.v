module f2i (a,d,p_lost,denorm,invalid);	// convert float to integer
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
	assign denorm = ~hidden_bit & frac_is_not_0;	// denorm:biased exponent=all 0 bits;fraction=anything except all 0 bits
	wire is_zero = ~hidden_bit & ~frac_is_not_0;	// zero:biased exponene and fraction=all 0 bits
	wire sign = a[31];
	wire [8:0] shift_right_bits = 9'd158 - {1'b0, a[30:23]};	// shift to right by 158(127+31)-e_a bits
	wire [55:0] frac0 = {hidden_bit, a[22:0], 32'h0};	// 32+24 = 56bits
	wire [55:0] f_abs = ($signed(shift_right_bits)>9'd32)?frac0 >> 6'd32 : frac0 >> shift_right_bits; // shift; $signed(c) can change c to signed
	wire lost_bits = |f_abs[23:0];	// if != 0, p_lost = 1
	wire [31:0] int32 = sign?~f_abs[55:24] + 32'd1 : f_abs[55:24];

	always @ * begin
		if (denorm) begin
			p_lost = 1;
			invalid = 0;
			d = 32'h00000000;
		end 
		else begin
			if (shift_right_bits[8]) begin
				p_lost = 0;
				invalid = 1;
				d = 32'h80000000;
			end
		       	else begin
				if (shift_right_bits[7:0]>8'h1f) begin
					if (is_zero) p_lost = 0;
					else p_lost = 1;
					invalid = 0;
					d = 32'h00000000;
				end 
				else begin
					if (sign != int32[31]) begin
						p_lost = 0;
						invalid = 1;
						d = 32'h80000000;
					end 
					else begin
						if (lost_bits) p_lost = 1;
						else p_lost = 0;
						invalid = 0;
						d = int32;
					end
				end
			end
		end
	end
endmodule
	



