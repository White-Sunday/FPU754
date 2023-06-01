// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vf2i.h for the primary calling header

#include "verilated.h"

#include "Vf2i___024root.h"

VL_INLINE_OPT void Vf2i___024root___ico_sequent__TOP__0(Vf2i___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vf2i__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vf2i___024root___ico_sequent__TOP__0\n"); );
    // Init
    CData/*0:0*/ f2i__DOT____VdfgExtracted_h602d5dd9__0;
    f2i__DOT____VdfgExtracted_h602d5dd9__0 = 0;
    // Body
    vlSelf->denorm = ((~ (IData)((0U != (0xffU & (vlSelf->a 
                                                  >> 0x17U))))) 
                      & (0U != (0x7fffffU & vlSelf->a)));
    vlSelf->f2i__DOT__frac0 = (((QData)((IData)((0U 
                                                 != 
                                                 (0xffU 
                                                  & (vlSelf->a 
                                                     >> 0x17U))))) 
                                << 0x37U) | ((QData)((IData)(
                                                             (0x7fffffU 
                                                              & vlSelf->a))) 
                                             << 0x20U));
    vlSelf->f2i__DOT__f_abs = (0xffffffffffffffULL 
                               & ((0x20U < (0x1ffU 
                                            & ((IData)(0x9eU) 
                                               - (0xffU 
                                                  & (vlSelf->a 
                                                     >> 0x17U)))))
                                   ? (vlSelf->f2i__DOT__frac0 
                                      >> 0x20U) : (
                                                   (0x37U 
                                                    >= 
                                                    (0x1ffU 
                                                     & ((IData)(0x9eU) 
                                                        - 
                                                        (0xffU 
                                                         & (vlSelf->a 
                                                            >> 0x17U)))))
                                                    ? 
                                                   (vlSelf->f2i__DOT__frac0 
                                                    >> 
                                                    (0x1ffU 
                                                     & ((IData)(0x9eU) 
                                                        - 
                                                        (0xffU 
                                                         & (vlSelf->a 
                                                            >> 0x17U)))))
                                                    : 0ULL)));
    vlSelf->f2i__DOT__int32 = ((vlSelf->a >> 0x1fU)
                                ? ((IData)(1U) + (~ (IData)(
                                                            (vlSelf->f2i__DOT__f_abs 
                                                             >> 0x18U))))
                                : (IData)((vlSelf->f2i__DOT__f_abs 
                                           >> 0x18U)));
    f2i__DOT____VdfgExtracted_h602d5dd9__0 = ((vlSelf->a 
                                               >> 0x1fU) 
                                              != (vlSelf->f2i__DOT__int32 
                                                  >> 0x1fU));
    vlSelf->invalid = (1U & ((~ (IData)(vlSelf->denorm)) 
                             & ((1U & (((IData)(0x9eU) 
                                        - (0xffU & 
                                           (vlSelf->a 
                                            >> 0x17U))) 
                                       >> 8U)) | ((0x1fU 
                                                   >= 
                                                   (0xffU 
                                                    & ((IData)(0x9eU) 
                                                       - 
                                                       (vlSelf->a 
                                                        >> 0x17U)))) 
                                                  & (IData)(f2i__DOT____VdfgExtracted_h602d5dd9__0)))));
    vlSelf->p_lost = (1U & ((IData)(vlSelf->denorm) 
                            | ((~ (1U & (((IData)(0x9eU) 
                                          - (0xffU 
                                             & (vlSelf->a 
                                                >> 0x17U))) 
                                         >> 8U))) & 
                               ((0x1fU < (0xffU & ((IData)(0x9eU) 
                                                   - 
                                                   (vlSelf->a 
                                                    >> 0x17U))))
                                 ? (~ ((~ (IData)((0U 
                                                   != 
                                                   (0xffU 
                                                    & (vlSelf->a 
                                                       >> 0x17U))))) 
                                       & (~ (IData)(
                                                    (0U 
                                                     != 
                                                     (0x7fffffU 
                                                      & vlSelf->a))))))
                                 : ((~ (IData)(f2i__DOT____VdfgExtracted_h602d5dd9__0)) 
                                    & (0U != (0xffffffU 
                                              & (IData)(vlSelf->f2i__DOT__f_abs))))))));
    vlSelf->d = ((IData)(vlSelf->denorm) ? 0U : ((0x100U 
                                                  & ((IData)(0x9eU) 
                                                     - 
                                                     (0xffU 
                                                      & (vlSelf->a 
                                                         >> 0x17U))))
                                                  ? 0x80000000U
                                                  : 
                                                 ((0x1fU 
                                                   < 
                                                   (0xffU 
                                                    & ((IData)(0x9eU) 
                                                       - 
                                                       (vlSelf->a 
                                                        >> 0x17U))))
                                                   ? 0U
                                                   : 
                                                  ((IData)(f2i__DOT____VdfgExtracted_h602d5dd9__0)
                                                    ? 0x80000000U
                                                    : vlSelf->f2i__DOT__int32))));
}

void Vf2i___024root___eval_ico(Vf2i___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vf2i__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vf2i___024root___eval_ico\n"); );
    // Body
    if (vlSelf->__VicoTriggered.at(0U)) {
        Vf2i___024root___ico_sequent__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[1U] = 1U;
    }
}

void Vf2i___024root___eval_act(Vf2i___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vf2i__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vf2i___024root___eval_act\n"); );
}

void Vf2i___024root___eval_nba(Vf2i___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vf2i__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vf2i___024root___eval_nba\n"); );
}

void Vf2i___024root___eval_triggers__ico(Vf2i___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void Vf2i___024root___dump_triggers__ico(Vf2i___024root* vlSelf);
#endif  // VL_DEBUG
void Vf2i___024root___eval_triggers__act(Vf2i___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void Vf2i___024root___dump_triggers__act(Vf2i___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vf2i___024root___dump_triggers__nba(Vf2i___024root* vlSelf);
#endif  // VL_DEBUG

void Vf2i___024root___eval(Vf2i___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vf2i__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vf2i___024root___eval\n"); );
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
        Vf2i___024root___eval_triggers__ico(vlSelf);
        if (vlSelf->__VicoTriggered.any()) {
            __VicoContinue = 1U;
            if (VL_UNLIKELY((0x64U < vlSelf->__VicoIterCount))) {
#ifdef VL_DEBUG
                Vf2i___024root___dump_triggers__ico(vlSelf);
#endif
                VL_FATAL_MT("vsrc/f2i.v", 1, "", "Input combinational region did not converge.");
            }
            vlSelf->__VicoIterCount = ((IData)(1U) 
                                       + vlSelf->__VicoIterCount);
            Vf2i___024root___eval_ico(vlSelf);
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
            Vf2i___024root___eval_triggers__act(vlSelf);
            if (vlSelf->__VactTriggered.any()) {
                vlSelf->__VactContinue = 1U;
                if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                    Vf2i___024root___dump_triggers__act(vlSelf);
#endif
                    VL_FATAL_MT("vsrc/f2i.v", 1, "", "Active region did not converge.");
                }
                vlSelf->__VactIterCount = ((IData)(1U) 
                                           + vlSelf->__VactIterCount);
                __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
                vlSelf->__VnbaTriggered.set(vlSelf->__VactTriggered);
                Vf2i___024root___eval_act(vlSelf);
            }
        }
        if (vlSelf->__VnbaTriggered.any()) {
            __VnbaContinue = 1U;
            if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
                Vf2i___024root___dump_triggers__nba(vlSelf);
#endif
                VL_FATAL_MT("vsrc/f2i.v", 1, "", "NBA region did not converge.");
            }
            __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
            Vf2i___024root___eval_nba(vlSelf);
        }
    }
}

#ifdef VL_DEBUG
void Vf2i___024root___eval_debug_assertions(Vf2i___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vf2i__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vf2i___024root___eval_debug_assertions\n"); );
}
#endif  // VL_DEBUG
