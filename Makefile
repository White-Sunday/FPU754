sim:
	verilator --cc --exe --build --trace ./csrc/f2i.cpp ./vsrc/f2i.v
test:
	verilator --cc --exe --build --trace ./csrc/test.cpp ./vsrc/test.v
