// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VF2I__SYMS_H_
#define VERILATED_VF2I__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "Vf2i.h"

// INCLUDE MODULE CLASSES
#include "Vf2i___024root.h"

// SYMS CLASS (contains all model state)
class Vf2i__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    Vf2i* const __Vm_modelp;
    bool __Vm_activity = false;  ///< Used by trace routines to determine change occurred
    uint32_t __Vm_baseCode = 0;  ///< Used by trace routines when tracing multiple models
    VlDeleter __Vm_deleter;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    Vf2i___024root                 TOP;

    // CONSTRUCTORS
    Vf2i__Syms(VerilatedContext* contextp, const char* namep, Vf2i* modelp);
    ~Vf2i__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

#endif  // guard
