// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VI2F__SYMS_H_
#define VERILATED_VI2F__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "Vi2f.h"

// INCLUDE MODULE CLASSES
#include "Vi2f___024root.h"

// SYMS CLASS (contains all model state)
class Vi2f__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    Vi2f* const __Vm_modelp;
    bool __Vm_activity = false;  ///< Used by trace routines to determine change occurred
    uint32_t __Vm_baseCode = 0;  ///< Used by trace routines when tracing multiple models
    VlDeleter __Vm_deleter;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    Vi2f___024root                 TOP;

    // CONSTRUCTORS
    Vi2f__Syms(VerilatedContext* contextp, const char* namep, Vi2f* modelp);
    ~Vi2f__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

#endif  // guard
