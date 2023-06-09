module fadder (a, b, sub, rm, s);	// fadder for addition and subtraction
	input [31:0] a;		// fp a
	input [31:0] b;		// fp b
	input sub;		// sub flag: 0-add; 1-sub
	input [1:0] rm;		// round mode
	output [31:0] s;	// fp output
	wire exchange = ({1'b0, b[30:0]} > {1'b0, a[30:0]});	// exchange to get the large fp and small fp
	wire [31:0] fp_large = exchange? b : a;
	wire [31:0] fp_small = exchange? a : b;

	wire fp_large_hidden_bit = |fp_large[30:23];
	wire fp_small_hidden_bit = |fp_small[30:23];

	wire [23:0] large_frac24 = {fp_large_hidden_bit, fp_large[22:0]};	// expansion bit, 24=23+1
	wire [23:0] small_frac24 = {fp_small_hidden_bit, fp_small[22:0]};

	wire [7:0] temp_exp = fp_large[30:23];

	wire sign = exchange? sub ^ b[31] : a[31];	// the sign of s
	wire op_sub = sub ^ fp_large[31] ^ fp_small[31];
	
	// special cases: inf and nan
	wire fp_large_expo_is_ff = &fp_large[30:23];	// exp == 0xff
	wire fp_small_expo_is_ff = &fp_small[30:23];

	wire fp_large_frac_is_00 = ~|fp_large[22:0];	// frac == 0x0
	wire fp_small_frac_is_00 = ~|fp_small[22:0];

	wire fp_large_is_inf = fp_large_expo_is_ff & fp_large_frac_is_00;
	wire fp_small_is_inf = fp_small_expo_is_ff & fp_small_frac_is_00;
	wire fp_large_is_nan = fp_large_expo_is_ff & ~fp_large_frac_is_00;
	wire fp_small_is_nan = fp_small_expo_is_ff & ~fp_small_frac_is_00;
	wire s_is_inf = fp_large_is_inf | fp_small_is_inf;
	wire s_is_nan = fp_large_is_nan | fp_small_is_nan | ((sub ^ fp_small[31] ^ fp_large[31]) & fp_large_is_inf & fp_small_is_inf);
	wire [22:0] nan_frac = ({1'b0,a[22:0]}>{1'b0,b[22:0]})? {1'b1,a[21:0]} : {1'b1,b[21:0]};	// this nan_frac is strange...IEEE754 standard?
	wire [22:0] inf_nan_frac = s_is_nan? nan_frac : 23'h0;

	// alignment
	wire [7:0] exp_diff = fp_large[30:23] - fp_small[30:23];		// exponent different
	wire small_den_only = (fp_large[30:23] != 0) & (fp_small[30:23] == 0);	// only fp_small is denormalized number or 0
	wire [7:0] shift_amount = small_den_only? exp_diff - 8'h1 : exp_diff;	// shift_amount for alignment
	wire [49:0] small_frac50 = (shift_amount >= 26)? {26'h0,small_frac24} : {small_frac24,26'h0}>>shift_amount;
	wire [26:0] small_frac27 = {small_frac50[49:24], |small_frac50[23:0]};
	wire [27:0] aligned_large_frac = {1'b0,large_frac24, 3'b000};
	wire [27:0] aligned_small_frac = {1'b0,small_frac27};

	// calculation
	wire [27:0] cal_frac = op_sub? aligned_large_frac - aligned_small_frac : aligned_large_frac + aligned_small_frac;
	
	// normalization
	wire [26:0] f4,f3,f2,f1,f0;
	wire zeros4,zeros3,zeros2,zeros1,zeros0;		// shift amount for normalization
	assign zeros4 = ~|cal_frac[26:11];		// 16-bit 0
	assign f4 = zeros4? {cal_frac[10:0],16'b0} : cal_frac[26:0];
	assign zeros3 = ~|f4[26:19];			// 8-bit 0
	assign f3 = zeros3? {f4[18:0],8'b0} : f4;
	assign zeros2 = ~|f3[26:23];			// 4-bit 0
	assign f2 = zeros2? {f3[22:0],4'b0} : f3;
	assign zeros1 = ~|f2[26:25];			// 2-bit 0
	assign f1 = zeros1? {f2[24:0],2'b0} : f2;
	assign zeros0 = ~f1[26];			// 1-bit 0
	assign f0 = zeros0? {f1[25:0],1'b0} : f1;
	wire [4:0] zeros = {zeros4,zeros3,zeros2,zeros1,zeros0};
	reg [7:0] exp0;
	reg [26:0] frac0;
	always @ * begin
		if(cal_frac[27]) begin		// 1x.xxxxxxxxxxxxxxxxxxxxxxx xxx  
			frac0 = cal_frac[27:1];	//  1.xxxxxxxxxxxxxxxxxxxxxxx xxx
			exp0 = temp_exp + 8'h1;
		end 
		else begin
			if((temp_exp > {3'b0,zeros}) && (f0[26])) begin	// s is a normalized number
				exp0 = temp_exp - {3'b0,zeros};
				frac0 = f0;				// 1.xxxxxxxxxxxxxxxxxxxxxxx xxx
			end
			else begin					// s is a denormalized number or 0
				exp0 = 0;
				if(temp_exp != 0)			// fp_large is a normalized number
					frac0 = cal_frac[26:0] << (temp_exp-8'h1);	// (e-127) = ((e-1)-126)
				else 					// fp_large is a denormalized number or 0
					frac0 = cal_frac[26:0];
			end
		end
	end

	// rounding 00-nearest(toward even);01-minus infinite;10-plus infinite;11-zero(frac_plus_1 always equal 0)
	wire frac_plus_1 =
		~rm[1] & ~rm[0] & frac0[2] & (frac0[1] | frac0[0])|
		~rm[1] & ~rm[0] & frac0[2] & ~frac0[1] & ~frac0[0] & frac0[3]|
		~rm[1] & rm[0] & (frac0[2] | frac0[1] | frac0[0]) & sign|
		rm[1] & ~rm[0] & (frac0[2] | frac0[1] | frac0[0]) & ~sign;
	wire [24:0] frac_round = {1'b0,frac0[26:3]} + {24'b0,frac_plus_1};
	wire [7:0] exponent = frac_round[24]? exp0 + 8'h1 : exp0;
	wire overflow = &exp0 | &exponent;
	assign s = final_result(overflow,rm,sign,s_is_nan,s_is_inf,exponent,frac_round[22:0],inf_nan_frac);
	function [31:0] final_result;
		input overflow;
		input [1:0] rm;
		input sign;
		input is_nan;
		input is_inf;
		input [7:0] exponent;
		input [22:0] fraction, inf_nan_frac;
		/* verilator lint_off CASEX */
		/* verilator lint_off CASEOVERLAP */
		casex ({overflow,rm,sign,s_is_nan,s_is_inf})
			6'b1_00_x_0_x : final_result = {sign,8'hff,23'h000000};		// nearest round: inf
			6'b1_01_0_0_x : final_result = {sign,8'hfe,23'h7fffff};		// minus inf round: positive max
			6'b1_01_1_0_x : final_result = {sign,8'hff,23'h000000};		// minus inf round: negative inf
			6'b1_10_0_0_x : final_result = {sign,8'hff,23'h000000}; 	// plus inf round: positive inf
			6'b1_10_1_0_x : final_result = {sign,8'hfe,23'h7fffff};		// plus inf round: negative max
			6'b1_11_x_0_x : final_result = {sign,8'hfe,23'h7fffff}; 	// zero inf round: max
			6'b0_xx_x_0_0 : final_result = {sign,exponent,fraction};	// normalized number
			6'bx_xx_x_1_x : final_result = {1'b1,8'hff,inf_nan_frac};	// nan(emmmmm...there always set sign 1)
			6'bx_xx_x_0_1 : final_result = {sign,8'hff,inf_nan_frac};	// inf
			default       : final_result = {sign,8'h00,23'h000000};		// 0
		endcase
	endfunction
endmodule
