#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <verilated.h>
#include <verilated_vcd_c.h>
#include "../obj_dir/Vpipelined_fmul.h"

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
	Vpipelined_fmul *top = new Vpipelined_fmul{contextp};

	VerilatedVcdC *tfp = new VerilatedVcdC;
	contextp->traceEverOn(true);
	top->trace(tfp,0);
	tfp->open("wave.vcd");

	// init signal
	top->a = 0;
	top->b = 0;
	top->rm = 0;
	top->clk = 0;
	top->clrn = 0;
	top->e = 0;
	top->eval();
	tfp->dump(contextp->time());
	
	step({top->a=0x3fc00000;top->b=0x3fc00000;top->rm=0;top->clk=0;top->clrn=1;top->e=1;});
	step({top->a=0x3fc00000;top->b=0x3fc00000;top->rm=0;top->clk=1;top->clrn=1;top->e=1;});
	step({top->a=0x00800000;top->b=0x00800000;top->rm=0;top->clk=0;top->clrn=1;top->e=1;});
	step({top->a=0x00800000;top->b=0x00800000;top->rm=0;top->clk=1;top->clrn=1;top->e=1;});
	step({top->a=0x7f7fffff;top->b=0x7f7fffff;top->rm=0;top->clk=0;top->clrn=1;top->e=1;});
	step({top->a=0x7f7fffff;top->b=0x7f7fffff;top->rm=0;top->clk=1;top->clrn=1;top->e=1;});
	step({top->a=0x00800000;top->b=0x3f000000;top->rm=0;top->clk=0;top->clrn=1;top->e=1;});
	step({top->a=0x00800000;top->b=0x3f000000;top->rm=0;top->clk=1;top->clrn=1;top->e=1;});
	step({top->a=0x003fffff;top->b=0x40000000;top->rm=0;top->clk=0;top->clrn=1;top->e=1;});
	step({top->a=0x003fffff;top->b=0x40000000;top->rm=0;top->clk=1;top->clrn=1;top->e=1;});
	step({top->a=0x7f800000;top->b=0x00ffffff;top->rm=0;top->clk=0;top->clrn=1;top->e=1;});
	step({top->a=0x7f800000;top->b=0x00ffffff;top->rm=0;top->clk=1;top->clrn=1;top->e=1;});
	step({top->a=0x7f800000;top->b=0x00000000;top->rm=0;top->clk=0;top->clrn=1;top->e=1;});
	step({top->a=0x7f800000;top->b=0x00000000;top->rm=0;top->clk=1;top->clrn=1;top->e=1;});
	step({top->a=0x7ff000ff;top->b=0x3f80ff00;top->rm=0;top->clk=0;top->clrn=1;top->e=1;});
	step({top->a=0x7ff000ff;top->b=0x3f80ff00;top->rm=0;top->clk=1;top->clrn=1;top->e=1;});

	step({top->a=0x7ff000ff;top->b=0x3f80ff00;top->rm=0;top->clk=0;top->clrn=1;top->e=1;});
	step({top->a=0x7ff000ff;top->b=0x3f80ff00;top->rm=0;top->clk=1;top->clrn=1;top->e=1;});
	step({top->a=0x7ff000ff;top->b=0x3f80ff00;top->rm=0;top->clk=0;top->clrn=1;top->e=1;});
	step({top->a=0x7ff000ff;top->b=0x3f80ff00;top->rm=0;top->clk=1;top->clrn=1;top->e=1;});
	step();

	delete top;
	tfp->close();
	delete contextp;
	return 0;
}
