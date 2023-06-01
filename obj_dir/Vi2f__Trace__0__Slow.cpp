// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vi2f__Syms.h"


VL_ATTR_COLD void Vi2f___024root__trace_init_sub__TOP__0(Vi2f___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vi2f__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vi2f___024root__trace_init_sub__TOP__0\n"); );
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBus(c+14,"d", false,-1, 31,0);
    tracep->declBus(c+15,"a", false,-1, 31,0);
    tracep->declBit(c+16,"p_lost", false,-1);
    tracep->pushNamePrefix("i2f ");
    tracep->declBus(c+14,"d", false,-1, 31,0);
    tracep->declBus(c+15,"a", false,-1, 31,0);
    tracep->declBit(c+16,"p_lost", false,-1);
    tracep->declBit(c+17,"sign", false,-1);
    tracep->declBus(c+1,"f5", false,-1, 31,0);
    tracep->declBus(c+2,"f4", false,-1, 31,0);
    tracep->declBus(c+3,"f3", false,-1, 31,0);
    tracep->declBus(c+4,"f2", false,-1, 31,0);
    tracep->declBus(c+5,"f1", false,-1, 31,0);
    tracep->declBus(c+6,"f0", false,-1, 31,0);
    tracep->declBit(c+7,"sa4", false,-1);
    tracep->declBit(c+8,"sa3", false,-1);
    tracep->declBit(c+9,"sa2", false,-1);
    tracep->declBit(c+10,"sa1", false,-1);
    tracep->declBit(c+11,"sa0", false,-1);
    tracep->declBus(c+12,"fraction", false,-1, 22,0);
    tracep->declBus(c+13,"exponent", false,-1, 7,0);
    tracep->popNamePrefix(1);
}

VL_ATTR_COLD void Vi2f___024root__trace_init_top(Vi2f___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vi2f__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vi2f___024root__trace_init_top\n"); );
    // Body
    Vi2f___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void Vi2f___024root__trace_full_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vi2f___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vi2f___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void Vi2f___024root__trace_register(Vi2f___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vi2f__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vi2f___024root__trace_register\n"); );
    // Body
    tracep->addFullCb(&Vi2f___024root__trace_full_top_0, vlSelf);
    tracep->addChgCb(&Vi2f___024root__trace_chg_top_0, vlSelf);
    tracep->addCleanupCb(&Vi2f___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vi2f___024root__trace_full_sub_0(Vi2f___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vi2f___024root__trace_full_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vi2f___024root__trace_full_top_0\n"); );
    // Init
    Vi2f___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vi2f___024root*>(voidSelf);
    Vi2f__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vi2f___024root__trace_full_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vi2f___024root__trace_full_sub_0(Vi2f___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vi2f__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vi2f___024root__trace_full_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullIData(oldp+1,(vlSelf->i2f__DOT__f5),32);
    bufp->fullIData(oldp+2,(vlSelf->i2f__DOT__f4),32);
    bufp->fullIData(oldp+3,(vlSelf->i2f__DOT__f3),32);
    bufp->fullIData(oldp+4,(vlSelf->i2f__DOT__f2),32);
    bufp->fullIData(oldp+5,(vlSelf->i2f__DOT__f1),32);
    bufp->fullIData(oldp+6,(vlSelf->i2f__DOT__f0),32);
    bufp->fullBit(oldp+7,((1U & (~ (IData)((0U != (vlSelf->i2f__DOT__f5 
                                                   >> 0x10U)))))));
    bufp->fullBit(oldp+8,((1U & (~ (IData)((0U != (vlSelf->i2f__DOT__f4 
                                                   >> 0x18U)))))));
    bufp->fullBit(oldp+9,((1U & (~ (IData)((0U != (vlSelf->i2f__DOT__f3 
                                                   >> 0x1cU)))))));
    bufp->fullBit(oldp+10,((1U & (~ (IData)((0U != 
                                             (vlSelf->i2f__DOT__f2 
                                              >> 0x1eU)))))));
    bufp->fullBit(oldp+11,((1U & (~ (vlSelf->i2f__DOT__f1 
                                     >> 0x1fU)))));
    bufp->fullIData(oldp+12,((0x7fffffU & (vlSelf->i2f__DOT__f0 
                                           >> 8U))),23);
    bufp->fullCData(oldp+13,((0xffU & ((IData)(0x9eU) 
                                       - ((0x10U & 
                                           ((~ (IData)(
                                                       (0U 
                                                        != 
                                                        (vlSelf->i2f__DOT__f5 
                                                         >> 0x10U)))) 
                                            << 4U)) 
                                          | ((8U & 
                                              ((~ (IData)(
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
    bufp->fullIData(oldp+14,(vlSelf->d),32);
    bufp->fullIData(oldp+15,(vlSelf->a),32);
    bufp->fullBit(oldp+16,(vlSelf->p_lost));
    bufp->fullBit(oldp+17,((vlSelf->d >> 0x1fU)));
}
