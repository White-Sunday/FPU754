#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <verilated.h>
#include <verilated_vcd_c.h>
#include "../obj_dir/Vf2i.h"

#define step(statements) do { \
	contextp->timeInc(1); \
	{statements} \
	top->eval(); \
	tfp->dump(contextp->time()); \
}while(0)

int main(int argc, char **argv)
{
	VerilatedContext *contextp = new VerilatedContext;
	contextp->commandArgs(argc, argv);
	Vf2i *top = new Vf2i{contextp};

	VerilatedVcdC *tfp = new VerilatedVcdC;
	contextp->traceEverOn(true);
	top->trace(tfp, 0);
	tfp->open("wave.vcd");
	
	// init signal
	top->a = 0x4effffff;
	top->eval();
        tfp->dump(contextp->time());

	step({top->a = 0x4f000000;});
	step({top->a = 0x3f800000;});
	step({top->a = 0x3f000000;});
	step({top->a = 0x00000001;});
	step({top->a = 0x7f800000;});
	step({top->a = 0x3fc00000;});
	step({top->a = 0xcf000000;});
	step({top->a = 0xcf000001;});
	step({top->a = 0xbf800000;});
	step({top->a = 0xbf7fffff;});
	step({top->a = 0x80000001;});
	step({top->a = 0xff800000;});
	step({top->a = 0x00000000;});
	step();

	delete top;
	tfp->close();
	delete contextp;
	return 0;
}
