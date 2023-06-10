#include <stdio.h>
#include <stdlib.h>
#include <verilated.h>
#include <verilated_vcd_c.h>
#include "../obj_dir/Vwallace_24x24_product.h"

#define step(statements) do { \
	contextp->timeInc(1); \
	{statements} \
	top->eval(); \
	tfp->dump(contextp->time()); \
} while(0)

int main(int argc, char **argv)
{
	VerilatedContext *contextp = new VerilatedContext;
	contextp->commandArgs(argc, argv);
	Vwallace_24x24_product *top = new Vwallace_24x24_product{contextp};
	
	VerilatedVcdC *tfp = new VerilatedVcdC;
	contextp->traceEverOn(true);
	top->trace(tfp, 0);
	tfp->open("wave.vcd");

	// init signal
	top->a = 0x000000;
	top->b = 0x000001;
	top->eval();
	tfp->dump(contextp->time());

	step({top->a=0xffffff;top->b=0x000002;});
	step({top->a=0xffffff;top->b=0x000004;});
	step({top->a=0xffffff;top->b=0x000008;});
	step({top->a=0xffffff;top->b=0x100000;});
	step({top->a=0xffffff;top->b=0x200000;});
	step({top->a=0xffffff;top->b=0x400000;});
	step({top->a=0xffffff;top->b=0xffffff;});
	step();

	delete top;
	tfp->close();
	delete tfp;
	delete contextp;
	return 0;
}
