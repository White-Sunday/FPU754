#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <verilated.h>
#include <verilated_vcd_c.h>
#include "../obj_dir/Vtest.h"

int main(int argc, char **argv)
{
	VerilatedContext *contextp = new VerilatedContext;
	contextp->commandArgs(argc, argv);
	Vtest *top = new Vtest{contextp};

	VerilatedVcdC *tfp = new VerilatedVcdC;
	contextp->traceEverOn(true);
	top->trace(tfp,0);
	tfp->open("test_wave.vcd");

	top->a = 0x00000001;
	top->eval();
	tfp->dump(contextp->time());
	
	contextp->timeInc(1);
	top->a = 0xffffffff;
	top->eval();
	tfp->dump(contextp->time());

	contextp->timeInc(1);
	top->a = 0x80000000;
	top->eval();
	tfp->dump(contextp->time());

	contextp->timeInc(1);
	top->eval();
	tfp->dump(contextp->time());
	
	delete top;
	tfp->close();
	delete contextp;
	return 0;
}
