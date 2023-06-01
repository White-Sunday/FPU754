// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "Vi2f__Syms.h"
#include "Vi2f.h"
#include "Vi2f___024root.h"

// FUNCTIONS
Vi2f__Syms::~Vi2f__Syms()
{
}

Vi2f__Syms::Vi2f__Syms(VerilatedContext* contextp, const char* namep, Vi2f* modelp)
    : VerilatedSyms{contextp}
    // Setup internal state of the Syms class
    , __Vm_modelp{modelp}
    // Setup module instances
    , TOP{this, namep}
{
    // Configure time unit / time precision
    _vm_contextp__->timeunit(-12);
    _vm_contextp__->timeprecision(-12);
    // Setup each module's pointers to their submodules
    // Setup each module's pointer back to symbol table (for public functions)
    TOP.__Vconfigure(true);
}
