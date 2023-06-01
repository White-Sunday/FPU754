// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vf2i.h for the primary calling header

#ifndef VERILATED_VF2I___024ROOT_H_
#define VERILATED_VF2I___024ROOT_H_  // guard

#include "verilated.h"

class Vf2i__Syms;

class Vf2i___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_OUT8(p_lost,0,0);
    VL_OUT8(denorm,0,0);
    VL_OUT8(invalid,0,0);
    CData/*0:0*/ __VactContinue;
    VL_IN(a,31,0);
    VL_OUT(d,31,0);
    IData/*31:0*/ f2i__DOT__int32;
    IData/*31:0*/ __VstlIterCount;
    IData/*31:0*/ __VicoIterCount;
    IData/*31:0*/ __VactIterCount;
    QData/*55:0*/ f2i__DOT__frac0;
    QData/*55:0*/ f2i__DOT__f_abs;
    VlUnpacked<CData/*0:0*/, 2> __Vm_traceActivity;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VicoTriggered;
    VlTriggerVec<0> __VactTriggered;
    VlTriggerVec<0> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vf2i__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vf2i___024root(Vf2i__Syms* symsp, const char* v__name);
    ~Vf2i___024root();
    VL_UNCOPYABLE(Vf2i___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);


#endif  // guard
