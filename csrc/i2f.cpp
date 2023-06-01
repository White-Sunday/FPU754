#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <verilated.h>
#include <verilated_vcd_c.h>
#include <../obj_dir/Vi2f.h>

#define step(statements) do{ \
	contextp->timeInc(1); \
	{statements} \
	top->eval(); \
	tfp->dump(contextp->time()); \
} while(0)

int main(int argc, char **argv)
{
	VerilatedContext *contextp = new VerilatedContext;
	contextp->commandArgs(argc, argv);
	Vi2f *top = new Vi2f{contextp};

	VerilatedVcdC *tfp = new VerilatedVcdC;
	contextp->traceEverOn(true);
	top->trace(tfp, 0);
	tfp->open("wave.vcd");

	// init signal
	top->d = 0x1fffffff;
	top->eval();
	tfp->dump(contextp->time());

	step();

	delete top;
	tfp->close();
	delete contextp;
	return 0;
}
