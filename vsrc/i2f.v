module i2f (d, a, p_lost);	// convert integer to float
	input [31:0] d;		// integer
	output [31:0] a;	// float
	output p_lost;		// precision lost
	wire sign = d[31];	// sign bit
	wire [31:0] f5 = sign? -d : d;	// absolute
	wire [31:0] f4, f3, f2, f1, f0;
	wire sa4, sa3, sa2, sa2, sa1, sa0;		// shift amount 记录左移多少位
	// 按照16、8、4、2、1字节把左边的0全部移完
	assign sa4 = ~|f5[31:16];	// ~| 按位|后~
	assign f4 = sa4? {f5[15:0], 16'b0} : f5;
	assign sa3 = ~|f4[31:24];
	assign f3 = sa3? {f4[23:0], 8'b0} : f4;
	assign sa2 = ~|f3[31:28];
	assign f2 = sa2? {f3[27:0], 4'b0} : f3;
	assign sa1 = ~|f2[31:30];
	assign f1 = sa1? {f2[29:0], 2'b0} : f2;
	assign sa0 = ~f1[31];
	assign f0 = sa0? {f1[30:0], 1'b0} : f1;
	assign p_lost = |f0[7:0];	// 最后8位不全为0说明有精度损失
	wire [22:0] fraction = f0[30:8];
	wire [7:0] exponent = 8'h9e - {3'h0, sa4, sa3, sa2, sa1, sa0};	// 0x9e = 158 = 127 + 31
	assign a = (d == 0)? 0 : {sign, exponent, fraction};	// 上述过程判断不出0，所以这里要加一道判断
endmodule
