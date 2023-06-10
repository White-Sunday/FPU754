sim:
	verilator --cc --exe --build --trace ./csrc/wallace_24x24_product.cpp ./vsrc/fmul/wallace_24x24_product.v
pipelined:
	verilator --cc --exe --build --trace ./csrc/pipelined_fadder.cpp ./vsrc/pipelined_fadder.v
test:
	verilator --cc --exe --build --trace ./csrc/test.cpp ./vsrc/test.v
clean:
	rm -r ./obj_dir
