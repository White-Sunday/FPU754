module shift_even_bits (a,b,sa);	// shift even bits until MSB if 1x or 01
	input [23:0] a;			// input data to be shifted
	output [23:0] b;		// output data(1xxx...x or 01xx...x)
	output [4:0] sa;		// shift amount, even number
	
	wire sa4,sa3,sa2,sa1,sa0;
	assign sa = {sa4,sa3,sa2,sa1,sa0};
	wire [23:0] a5,a4,a3,a2,a1;
	assign a5 = a;
	assign sa4 = ~|a5[23:8];		// 16-bit 0
	assign a4 = sa4? {a5[7:0],16'b0} : a5;
	assign sa3 = ~|a4[23:16];		// 8-bit 0
	assign a3 = sa3? {a4[15:0],8'b0} : a4;
	assign sa2 = ~|a3[23:20];		// 4-bit 0
	assign a2 = sa2? {a3[19:0],8'b0} : a3;
	assign sa1 = ~|a2[23:22];		// 2-bit 0
	assign a1 = sa1? {a2[21:0],8'b0} : a2;
	assign sa0 = 0;
	assign b = a1;
endmodule
