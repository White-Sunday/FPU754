#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <verilated.h>
#include <verilated_vcd_c.h>
#include "../obj_dir/Vfsqrt_newton.h"

#define step(statements) do { \
	        contextp->timeInc(1); \
	        {statements} \
	        top->eval(); \
	        tfp->dump(contextp->time()); \
} while(0)

int main(int argc, char **argv)
{
	VerilatedContext *contextp = new VerilatedContext;
	contextp->commandArgs(argc,argv);
	Vfsqrt_newton *top = new Vfsqrt_newton{contextp};

	VerilatedVcdC *tfp = new VerilatedVcdC;
	contextp->traceEverOn(true);
	top->trace(tfp,0);
	tfp->open("wave.vcd");

	// init signal
	// top->d = 0x41100000;
	top->d = 0x41100000;
	top->fsqrt = 0;
	top->rm = 0;
	top->clk = 1;
	top->clrn = 0;
	top->ena = 0;
	top->eval();
	tfp->dump(contextp->time());
	step({top->clk=0;top->clrn=1;top->ena = 1;});
	// ID
	step({top->clk=1;top->clrn=1;});
	step({top->clk=0;top->clrn=1;top->fsqrt=1;});
	// ID stall
	int i = 0;
	for (i=0;i<21;++i)
	{
		step({top->clk=1;top->clrn=1;});
		step({top->clk=0;top->clrn=1;});
	}
	step({top->clk=1;top->clrn=1;top->fsqrt=0;});
	step({top->clk=0;top->clrn=1;});
	// e1 e2 e3
	step({top->clk=1;top->clrn=1;});
	step({top->clk=0;top->clrn=1;});
	step({top->clk=1;top->clrn=1;});
	step({top->clk=0;top->clrn=1;});
	step({top->clk=1;top->clrn=1;});
	step({top->clk=0;top->clrn=1;});
	step();

	delete top;
	tfp->close();
	delete contextp;
	return 0;
}
