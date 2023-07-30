sim:
	verilator --cc --exe --build --trace ./csrc/fsqrt_newton.cpp ./vsrc/fsqrt_newton.v
pipelined:
	verilator --cc --exe --build --trace ./csrc/pipelined_fadder.cpp ./vsrc/pipelined_fadder.v
test:
	verilator --cc --exe --build --trace ./csrc/test.cpp ./vsrc/test.v
clean:
	rm -r ./obj_dir
