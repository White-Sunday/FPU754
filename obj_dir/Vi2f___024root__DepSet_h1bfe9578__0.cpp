// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vi2f.h for the primary calling header

#include "verilated.h"

#include "Vi2f___024root.h"

VL_INLINE_OPT void Vi2f___024root___ico_sequent__TOP__0(Vi2f___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vi2f__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vi2f___024root___ico_sequent__TOP__0\n"); );
    // Body
    vlSelf->i2f__DOT__f5 = ((vlSelf->d >> 0x1fU) ? 
                            (- vlSelf->d) : vlSelf->d);
    vlSelf->i2f__DOT__f4 = ((0U != (vlSelf->i2f__DOT__f5 
                                    >> 0x10U)) ? vlSelf->i2f__DOT__f5
                             : (vlSelf->i2f__DOT__f5 
                                << 0x10U));
    vlSelf->i2f__DOT__f3 = ((0U != (vlSelf->i2f__DOT__f4 
                                    >> 0x18U)) ? vlSelf->i2f__DOT__f4
                             : (vlSelf->i2f__DOT__f4 
                                << 8U));
    vlSelf->i2f__DOT__f2 = ((0U != (vlSelf->i2f__DOT__f3 
                                    >> 0x1cU)) ? vlSelf->i2f__DOT__f3
                             : (vlSelf->i2f__DOT__f3 
                                << 4U));
    vlSelf->i2f__DOT__f1 = ((0U != (vlSelf->i2f__DOT__f2 
                                    >> 0x1eU)) ? vlSelf->i2f__DOT__f2
                             : (vlSelf->i2f__DOT__f2 
                                << 2U));
    vlSelf->i2f__DOT__f0 = ((vlSelf->i2f__DOT__f1 >> 0x1fU)
                             ? vlSelf->i2f__DOT__f1
                             : (vlSelf->i2f__DOT__f1 
                                << 1U));
    vlSelf->p_lost = (0U != (0xffU & vlSelf->i2f__DOT__f0));
    vlSelf->a = ((0U == vlSelf->d) ? 0U : ((0x80000000U 
                                            & vlSelf->d) 
                                           | ((0x7f800000U 
                                               & (((IData)(0x9eU) 
                                                   - 
                                                   ((0x10U 
                                                     & ((~ (IData)(
                                                                   (0U 
                                                                    != 
                                                                    (vlSelf->i2f__DOT__f5 
                                                                     >> 0x10U)))) 
                                                        << 4U)) 
                                                    | ((8U 
                                                        & ((~ (IData)(
                                                                      (0U 
                                                                       != 
                                                                       (vlSelf->i2f__DOT__f4 
                                                                        >> 0x18U)))) 
                                                           << 3U)) 
                                                       | ((4U 
                                                           & ((~ (IData)(
                                                                         (0U 
                                                                          != 
                                                                          (vlSelf->i2f__DOT__f3 
                                                                           >> 0x1cU)))) 
                                                              << 2U)) 
                                                          | ((2U 
                                                              & ((~ (IData)(
                                                                            (0U 
                                                                             != 
                                                                             (vlSelf->i2f__DOT__f2 
                                                                              >> 0x1eU)))) 
                                                                 << 1U)) 
                                                             | (1U 
                                                                & (~ 
                                                                   (vlSelf->i2f__DOT__f1 
                                                                    >> 0x1fU)))))))) 
                                                  << 0x17U)) 
                                              | (0x7fffffU 
                                                 & (vlSelf->i2f__DOT__f0 
                                                    >> 8U)))));
}

void Vi2f___024root___eval_ico(Vi2f___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vi2f__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vi2f___024root___eval_ico\n"); );
    // Body
    if (vlSelf->__VicoTriggered.at(0U)) {
        Vi2f___024root___ico_sequent__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[1U] = 1U;
    }
}

void Vi2f___024root___eval_act(Vi2f___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vi2f__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vi2f___024root___eval_act\n"); );
}

void Vi2f___024root___eval_nba(Vi2f___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vi2f__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vi2f___024root___eval_nba\n"); );
}

void Vi2f___024root___eval_triggers__ico(Vi2f___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void Vi2f___024root___dump_triggers__ico(Vi2f___024root* vlSelf);
#endif  // VL_DEBUG
void Vi2f___024root___eval_triggers__act(Vi2f___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void Vi2f___024root___dump_triggers__act(Vi2f___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vi2f___024root___dump_triggers__nba(Vi2f___024root* vlSelf);
#endif  // VL_DEBUG

void Vi2f___024root___eval(Vi2f___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vi2f__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vi2f___024root___eval\n"); );
    // Init
    CData/*0:0*/ __VicoContinue;
    VlTriggerVec<0> __VpreTriggered;
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    vlSelf->__VicoIterCount = 0U;
    __VicoContinue = 1U;
    while (__VicoContinue) {
        __VicoContinue = 0U;
        Vi2f___024root___eval_triggers__ico(vlSelf);
        if (vlSelf->__VicoTriggered.any()) {
            __VicoContinue = 1U;
            if (VL_UNLIKELY((0x64U < vlSelf->__VicoIterCount))) {
#ifdef VL_DEBUG
                Vi2f___024root___dump_triggers__ico(vlSelf);
#endif
                VL_FATAL_MT("vsrc/i2f.v", 1, "", "Input combinational region did not converge.");
            }
            vlSelf->__VicoIterCount = ((IData)(1U) 
                                       + vlSelf->__VicoIterCount);
            Vi2f___024root___eval_ico(vlSelf);
        }
    }
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        __VnbaContinue = 0U;
        vlSelf->__VnbaTriggered.clear();
        vlSelf->__VactIterCount = 0U;
        vlSelf->__VactContinue = 1U;
        while (vlSelf->__VactContinue) {
            vlSelf->__VactContinue = 0U;
            Vi2f___024root___eval_triggers__act(vlSelf);
            if (vlSelf->__VactTriggered.any()) {
                vlSelf->__VactContinue = 1U;
                if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                    Vi2f___024root___dump_triggers__act(vlSelf);
#endif
                    VL_FATAL_MT("vsrc/i2f.v", 1, "", "Active region did not converge.");
                }
                vlSelf->__VactIterCount = ((IData)(1U) 
                                           + vlSelf->__VactIterCount);
                __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
                vlSelf->__VnbaTriggered.set(vlSelf->__VactTriggered);
                Vi2f___024root___eval_act(vlSelf);
            }
        }
        if (vlSelf->__VnbaTriggered.any()) {
            __VnbaContinue = 1U;
            if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
                Vi2f___024root___dump_triggers__nba(vlSelf);
#endif
                VL_FATAL_MT("vsrc/i2f.v", 1, "", "NBA region did not converge.");
            }
            __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
            Vi2f___024root___eval_nba(vlSelf);
        }
    }
}

#ifdef VL_DEBUG
void Vi2f___024root___eval_debug_assertions(Vi2f___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vi2f__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vi2f___024root___eval_debug_assertions\n"); );
}
#endif  // VL_DEBUG
