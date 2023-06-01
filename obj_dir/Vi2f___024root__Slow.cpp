// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vi2f.h for the primary calling header

#include "verilated.h"

#include "Vi2f__Syms.h"
#include "Vi2f___024root.h"

void Vi2f___024root___ctor_var_reset(Vi2f___024root* vlSelf);

Vi2f___024root::Vi2f___024root(Vi2f__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vi2f___024root___ctor_var_reset(this);
}

void Vi2f___024root::__Vconfigure(bool first) {
    if (false && first) {}  // Prevent unused
}

Vi2f___024root::~Vi2f___024root() {
}
