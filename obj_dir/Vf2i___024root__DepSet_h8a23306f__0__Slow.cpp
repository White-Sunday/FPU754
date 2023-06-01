// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vf2i.h for the primary calling header

#include "verilated.h"

#include "Vf2i___024root.h"

VL_ATTR_COLD void Vf2i___024root___eval_static(Vf2i___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vf2i__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vf2i___024root___eval_static\n"); );
}

VL_ATTR_COLD void Vf2i___024root___eval_initial(Vf2i___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vf2i__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vf2i___024root___eval_initial\n"); );
}

VL_ATTR_COLD void Vf2i___024root___eval_final(Vf2i___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vf2i__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vf2i___024root___eval_final\n"); );
}

VL_ATTR_COLD void Vf2i___024root___eval_triggers__stl(Vf2i___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void Vf2i___024root___dump_triggers__stl(Vf2i___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD void Vf2i___024root___eval_stl(Vf2i___024root* vlSelf);

VL_ATTR_COLD void Vf2i___024root___eval_settle(Vf2i___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vf2i__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vf2i___024root___eval_settle\n"); );
    // Init
    CData/*0:0*/ __VstlContinue;
    // Body
    vlSelf->__VstlIterCount = 0U;
    __VstlContinue = 1U;
    while (__VstlContinue) {
        __VstlContinue = 0U;
        Vf2i___024root___eval_triggers__stl(vlSelf);
        if (vlSelf->__VstlTriggered.any()) {
            __VstlContinue = 1U;
            if (VL_UNLIKELY((0x64U < vlSelf->__VstlIterCount))) {
#ifdef VL_DEBUG
                Vf2i___024root___dump_triggers__stl(vlSelf);
#endif
                VL_FATAL_MT("vsrc/f2i.v", 1, "", "Settle region did not converge.");
            }
            vlSelf->__VstlIterCount = ((IData)(1U) 
                                       + vlSelf->__VstlIterCount);
            Vf2i___024root___eval_stl(vlSelf);
        }
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vf2i___024root___dump_triggers__stl(Vf2i___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vf2i__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vf2i___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VstlTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if (vlSelf->__VstlTriggered.at(0U)) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

void Vf2i___024root___ico_sequent__TOP__0(Vf2i___024root* vlSelf);

VL_ATTR_COLD void Vf2i___024root___eval_stl(Vf2i___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vf2i__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vf2i___024root___eval_stl\n"); );
    // Body
    if (vlSelf->__VstlTriggered.at(0U)) {
        Vf2i___024root___ico_sequent__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[1U] = 1U;
        vlSelf->__Vm_traceActivity[0U] = 1U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vf2i___024root___dump_triggers__ico(Vf2i___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vf2i__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vf2i___024root___dump_triggers__ico\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VicoTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if (vlSelf->__VicoTriggered.at(0U)) {
        VL_DBG_MSGF("         'ico' region trigger index 0 is active: Internal 'ico' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vf2i___024root___dump_triggers__act(Vf2i___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vf2i__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vf2i___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VactTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vf2i___024root___dump_triggers__nba(Vf2i___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vf2i__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vf2i___024root___dump_triggers__nba\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VnbaTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vf2i___024root___ctor_var_reset(Vf2i___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vf2i__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vf2i___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->a = VL_RAND_RESET_I(32);
    vlSelf->d = VL_RAND_RESET_I(32);
    vlSelf->p_lost = VL_RAND_RESET_I(1);
    vlSelf->denorm = VL_RAND_RESET_I(1);
    vlSelf->invalid = VL_RAND_RESET_I(1);
    vlSelf->f2i__DOT__frac0 = VL_RAND_RESET_Q(56);
    vlSelf->f2i__DOT__f_abs = VL_RAND_RESET_Q(56);
    vlSelf->f2i__DOT__int32 = VL_RAND_RESET_I(32);
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = 0;
    }
}
