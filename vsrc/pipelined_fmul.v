`include "vsrc/pipelined_fmul/fmul_add.v"
`include "vsrc/pipelined_fmul/fmul_mul.v"
`include "vsrc/pipelined_fmul/fmul_norm.v"
`include "vsrc/pipelined_fmul/reg_add_norm.v"
`include "vsrc/pipelined_fmul/reg_mul_add.v"

module pipelined_fmul (a, b, rm, s, clk, clrn, e);	// pipelined fp mul
	input [31:0] a;		// fp a
	input [31:0] b;		// fp b
	input [1:0] rm;		// round mode
	input clk, clrn;	// clock and reset
	input e;		// enable
	output [31:0] s;	// fp output

	wire m_sign;
	wire [9:0] m_exp10;
	wire m_is_nan;
	wire m_is_inf;
	wire [22:0] m_inf_nan_frac;
	wire [39:0] m_sum;
	wire [39:0] m_carry;
	wire [7:0] m_z8;
	// exe1: partial product stage (carry and sum generated by wallace tree)
	fmul_mul  mull1 (a,b,m_sign,m_exp10,m_is_nan,m_is_inf,m_inf_nan_frac,m_sum,m_carry,m_z8);

	wire [1:0] a_rm;
	wire a_sign;
	wire [9:0] a_exp10;
	wire a_is_nan;
	wire a_is_inf;
	wire [22:0] a_inf_nan_frac;
	wire [39:0] a_sum;
	wire [39:0] a_carry;
	wire [7:0] a_z8;
	// pipeline register
	reg_mul_add reg_ma(rm,m_sign,m_exp10,m_is_nan,m_is_inf,m_inf_nan_frac,m_sum,m_carry,m_z8,
	clk,clrn,e,a_rm,a_sign,a_exp10,a_is_nan,a_is_inf,a_inf_nan_frac,a_sum,a_carry,a_z8);
	
	wire [47:8] a_z40;
	// exe2: addition stage (product by adding carry and sum)
	fmul_add mul2 (a_sum,a_carry,a_z40);
	
	wire [47:0] a_z48 = {a_z40, a_z8};
	wire [1:0] n_rm;
	wire n_sign;
	wire [9:0] n_exp10;
	wire n_is_nan;
	wire n_is_inf;
	wire [22:0] n_inf_nan_frac;
	wire [47:0] n_z48;

	// pipeline register
	reg_add_norm reg_an (a_rm,a_sign,a_exp10,a_is_nan,a_is_inf,a_inf_nan_frac,a_z48,
	clk,clrn,e,n_rm,n_sign,n_exp10,n_is_nan,n_is_inf,n_inf_nan_frac,n_z48);

	// exe3: normalization stage
	fmul_norm mul3 (n_rm,n_sign,n_exp10,n_is_nan,n_is_inf,n_inf_nan_frac,n_z48,s);
endmodule
