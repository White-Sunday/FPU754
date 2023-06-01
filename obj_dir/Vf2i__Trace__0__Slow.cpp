// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vf2i__Syms.h"


VL_ATTR_COLD void Vf2i___024root__trace_init_sub__TOP__0(Vf2i___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vf2i__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vf2i___024root__trace_init_sub__TOP__0\n"); );
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBus(c+7,"a", false,-1, 31,0);
    tracep->declBus(c+8,"d", false,-1, 31,0);
    tracep->declBit(c+9,"p_lost", false,-1);
    tracep->declBit(c+10,"denorm", false,-1);
    tracep->declBit(c+11,"invalid", false,-1);
    tracep->pushNamePrefix("f2i ");
    tracep->declBus(c+7,"a", false,-1, 31,0);
    tracep->declBus(c+8,"d", false,-1, 31,0);
    tracep->declBit(c+9,"p_lost", false,-1);
    tracep->declBit(c+10,"denorm", false,-1);
    tracep->declBit(c+11,"invalid", false,-1);
    tracep->declBit(c+12,"hidden_bit", false,-1);
    tracep->declBit(c+13,"frac_is_not_0", false,-1);
    tracep->declBit(c+14,"is_zero", false,-1);
    tracep->declBit(c+15,"sign", false,-1);
    tracep->declBus(c+16,"shift_right_bits", false,-1, 8,0);
    tracep->declQuad(c+1,"frac0", false,-1, 55,0);
    tracep->declQuad(c+3,"f_abs", false,-1, 55,0);
    tracep->declBit(c+5,"lost_bits", false,-1);
    tracep->declBus(c+6,"int32", false,-1, 31,0);
    tracep->popNamePrefix(1);
}

VL_ATTR_COLD void Vf2i___024root__trace_init_top(Vf2i___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vf2i__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vf2i___024root__trace_init_top\n"); );
    // Body
    Vf2i___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void Vf2i___024root__trace_full_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vf2i___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vf2i___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void Vf2i___024root__trace_register(Vf2i___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vf2i__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vf2i___024root__trace_register\n"); );
    // Body
    tracep->addFullCb(&Vf2i___024root__trace_full_top_0, vlSelf);
    tracep->addChgCb(&Vf2i___024root__trace_chg_top_0, vlSelf);
    tracep->addCleanupCb(&Vf2i___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vf2i___024root__trace_full_sub_0(Vf2i___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vf2i___024root__trace_full_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vf2i___024root__trace_full_top_0\n"); );
    // Init
    Vf2i___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vf2i___024root*>(voidSelf);
    Vf2i__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vf2i___024root__trace_full_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vf2i___024root__trace_full_sub_0(Vf2i___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vf2i__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vf2i___024root__trace_full_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullQData(oldp+1,(vlSelf->f2i__DOT__frac0),56);
    bufp->fullQData(oldp+3,(vlSelf->f2i__DOT__f_abs),56);
    bufp->fullBit(oldp+5,((0U != (0xffffffU & (IData)(vlSelf->f2i__DOT__f_abs)))));
    bufp->fullIData(oldp+6,(vlSelf->f2i__DOT__int32),32);
    bufp->fullIData(oldp+7,(vlSelf->a),32);
    bufp->fullIData(oldp+8,(vlSelf->d),32);
    bufp->fullBit(oldp+9,(vlSelf->p_lost));
    bufp->fullBit(oldp+10,(vlSelf->denorm));
    bufp->fullBit(oldp+11,(vlSelf->invalid));
    bufp->fullBit(oldp+12,((0U != (0xffU & (vlSelf->a 
                                            >> 0x17U)))));
    bufp->fullBit(oldp+13,((0U != (0x7fffffU & vlSelf->a))));
    bufp->fullBit(oldp+14,((1U & ((~ (IData)((0U != 
                                              (0xffU 
                                               & (vlSelf->a 
                                                  >> 0x17U))))) 
                                  & (~ (IData)((0U 
                                                != 
                                                (0x7fffffU 
                                                 & vlSelf->a))))))));
    bufp->fullBit(oldp+15,((vlSelf->a >> 0x1fU)));
    bufp->fullSData(oldp+16,((0x1ffU & ((IData)(0x9eU) 
                                        - (0xffU & 
                                           (vlSelf->a 
                                            >> 0x17U))))),9);
}
