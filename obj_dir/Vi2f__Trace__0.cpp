// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vi2f__Syms.h"


void Vi2f___024root__trace_chg_sub_0(Vi2f___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vi2f___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vi2f___024root__trace_chg_top_0\n"); );
    // Init
    Vi2f___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vi2f___024root*>(voidSelf);
    Vi2f__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vi2f___024root__trace_chg_sub_0((&vlSymsp->TOP), bufp);
}

void Vi2f___024root__trace_chg_sub_0(Vi2f___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vi2f__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vi2f___024root__trace_chg_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[1U])) {
        bufp->chgIData(oldp+0,(vlSelf->i2f__DOT__f5),32);
        bufp->chgIData(oldp+1,(vlSelf->i2f__DOT__f4),32);
        bufp->chgIData(oldp+2,(vlSelf->i2f__DOT__f3),32);
        bufp->chgIData(oldp+3,(vlSelf->i2f__DOT__f2),32);
        bufp->chgIData(oldp+4,(vlSelf->i2f__DOT__f1),32);
        bufp->chgIData(oldp+5,(vlSelf->i2f__DOT__f0),32);
        bufp->chgBit(oldp+6,((1U & (~ (IData)((0U != 
                                               (vlSelf->i2f__DOT__f5 
                                                >> 0x10U)))))));
        bufp->chgBit(oldp+7,((1U & (~ (IData)((0U != 
                                               (vlSelf->i2f__DOT__f4 
                                                >> 0x18U)))))));
        bufp->chgBit(oldp+8,((1U & (~ (IData)((0U != 
                                               (vlSelf->i2f__DOT__f3 
                                                >> 0x1cU)))))));
        bufp->chgBit(oldp+9,((1U & (~ (IData)((0U != 
                                               (vlSelf->i2f__DOT__f2 
                                                >> 0x1eU)))))));
        bufp->chgBit(oldp+10,((1U & (~ (vlSelf->i2f__DOT__f1 
                                        >> 0x1fU)))));
        bufp->chgIData(oldp+11,((0x7fffffU & (vlSelf->i2f__DOT__f0 
                                              >> 8U))),23);
        bufp->chgCData(oldp+12,((0xffU & ((IData)(0x9eU) 
                                          - ((0x10U 
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
                                                             >> 0x1fU)))))))))),8);
    }
    bufp->chgIData(oldp+13,(vlSelf->d),32);
    bufp->chgIData(oldp+14,(vlSelf->a),32);
    bufp->chgBit(oldp+15,(vlSelf->p_lost));
    bufp->chgBit(oldp+16,((vlSelf->d >> 0x1fU)));
}

void Vi2f___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vi2f___024root__trace_cleanup\n"); );
    // Init
    Vi2f___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vi2f___024root*>(voidSelf);
    Vi2f__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
}
