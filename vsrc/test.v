module test (a, b);
	// input [31:0] a;
	// output b;
	// assign b = ~|a;
	/* verilator lint_off WIDTHTRUNC */
	// input [31:0] a;
	// input [31:0] b;
	// output [31:0] z;
	// assign z = {1'b0,a}+b;
endmodule
