// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vi2f.h for the primary calling header

#ifndef VERILATED_VI2F___024ROOT_H_
#define VERILATED_VI2F___024ROOT_H_  // guard

#include "verilated.h"

class Vi2f__Syms;

class Vi2f___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_OUT8(p_lost,0,0);
    CData/*0:0*/ __VactContinue;
    VL_IN(d,31,0);
    VL_OUT(a,31,0);
    IData/*31:0*/ i2f__DOT__f5;
    IData/*31:0*/ i2f__DOT__f4;
    IData/*31:0*/ i2f__DOT__f3;
    IData/*31:0*/ i2f__DOT__f2;
    IData/*31:0*/ i2f__DOT__f1;
    IData/*31:0*/ i2f__DOT__f0;
    IData/*31:0*/ __VstlIterCount;
    IData/*31:0*/ __VicoIterCount;
    IData/*31:0*/ __VactIterCount;
    VlUnpacked<CData/*0:0*/, 2> __Vm_traceActivity;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VicoTriggered;
    VlTriggerVec<0> __VactTriggered;
    VlTriggerVec<0> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vi2f__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vi2f___024root(Vi2f__Syms* symsp, const char* v__name);
    ~Vi2f___024root();
    VL_UNCOPYABLE(Vi2f___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);


#endif  // guard
