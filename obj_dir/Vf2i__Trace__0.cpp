// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vf2i__Syms.h"


void Vf2i___024root__trace_chg_sub_0(Vf2i___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vf2i___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vf2i___024root__trace_chg_top_0\n"); );
    // Init
    Vf2i___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vf2i___024root*>(voidSelf);
    Vf2i__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vf2i___024root__trace_chg_sub_0((&vlSymsp->TOP), bufp);
}

void Vf2i___024root__trace_chg_sub_0(Vf2i___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vf2i__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vf2i___024root__trace_chg_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[1U])) {
        bufp->chgQData(oldp+0,(vlSelf->f2i__DOT__frac0),56);
        bufp->chgQData(oldp+2,(vlSelf->f2i__DOT__f_abs),56);
        bufp->chgBit(oldp+4,((0U != (0xffffffU & (IData)(vlSelf->f2i__DOT__f_abs)))));
        bufp->chgIData(oldp+5,(vlSelf->f2i__DOT__int32),32);
    }
    bufp->chgIData(oldp+6,(vlSelf->a),32);
    bufp->chgIData(oldp+7,(vlSelf->d),32);
    bufp->chgBit(oldp+8,(vlSelf->p_lost));
    bufp->chgBit(oldp+9,(vlSelf->denorm));
    bufp->chgBit(oldp+10,(vlSelf->invalid));
    bufp->chgBit(oldp+11,((0U != (0xffU & (vlSelf->a 
                                           >> 0x17U)))));
    bufp->chgBit(oldp+12,((0U != (0x7fffffU & vlSelf->a))));
    bufp->chgBit(oldp+13,((1U & ((~ (IData)((0U != 
                                             (0xffU 
                                              & (vlSelf->a 
                                                 >> 0x17U))))) 
                                 & (~ (IData)((0U != 
                                               (0x7fffffU 
                                                & vlSelf->a))))))));
    bufp->chgBit(oldp+14,((vlSelf->a >> 0x1fU)));
    bufp->chgSData(oldp+15,((0x1ffU & ((IData)(0x9eU) 
                                       - (0xffU & (vlSelf->a 
                                                   >> 0x17U))))),9);
}

void Vf2i___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vf2i___024root__trace_cleanup\n"); );
    // Init
    Vf2i___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vf2i___024root*>(voidSelf);
    Vf2i__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
}
