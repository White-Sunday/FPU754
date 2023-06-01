module test (a, b);
	input [31:0] a;
	output b;
	assign b = ~|a;
endmodule
