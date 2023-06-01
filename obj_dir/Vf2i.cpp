// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vf2i.h"
#include "Vf2i__Syms.h"
#include "verilated_vcd_c.h"

//============================================================
// Constructors

Vf2i::Vf2i(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vf2i__Syms(contextp(), _vcname__, this)}
    , p_lost{vlSymsp->TOP.p_lost}
    , denorm{vlSymsp->TOP.denorm}
    , invalid{vlSymsp->TOP.invalid}
    , a{vlSymsp->TOP.a}
    , d{vlSymsp->TOP.d}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vf2i::Vf2i(const char* _vcname__)
    : Vf2i(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vf2i::~Vf2i() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vf2i___024root___eval_debug_assertions(Vf2i___024root* vlSelf);
#endif  // VL_DEBUG
void Vf2i___024root___eval_static(Vf2i___024root* vlSelf);
void Vf2i___024root___eval_initial(Vf2i___024root* vlSelf);
void Vf2i___024root___eval_settle(Vf2i___024root* vlSelf);
void Vf2i___024root___eval(Vf2i___024root* vlSelf);

void Vf2i::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vf2i::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vf2i___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_activity = true;
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vf2i___024root___eval_static(&(vlSymsp->TOP));
        Vf2i___024root___eval_initial(&(vlSymsp->TOP));
        Vf2i___024root___eval_settle(&(vlSymsp->TOP));
    }
    // MTask 0 start
    VL_DEBUG_IF(VL_DBG_MSGF("MTask0 starting\n"););
    Verilated::mtaskId(0);
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vf2i___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vf2i::eventsPending() { return false; }

uint64_t Vf2i::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "%Error: No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* Vf2i::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vf2i___024root___eval_final(Vf2i___024root* vlSelf);

VL_ATTR_COLD void Vf2i::final() {
    Vf2i___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vf2i::hierName() const { return vlSymsp->name(); }
const char* Vf2i::modelName() const { return "Vf2i"; }
unsigned Vf2i::threads() const { return 1; }
std::unique_ptr<VerilatedTraceConfig> Vf2i::traceConfig() const {
    return std::unique_ptr<VerilatedTraceConfig>{new VerilatedTraceConfig{false, false, false}};
};

//============================================================
// Trace configuration

void Vf2i___024root__trace_init_top(Vf2i___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vf2i___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vf2i___024root*>(voidSelf);
    Vf2i__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->scopeEscape(' ');
    tracep->pushNamePrefix(std::string{vlSymsp->name()} + ' ');
    Vf2i___024root__trace_init_top(vlSelf, tracep);
    tracep->popNamePrefix();
    tracep->scopeEscape('.');
}

VL_ATTR_COLD void Vf2i___024root__trace_register(Vf2i___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void Vf2i::trace(VerilatedVcdC* tfp, int levels, int options) {
    if (tfp->isOpen()) {
        vl_fatal(__FILE__, __LINE__, __FILE__,"'Vf2i::trace()' shall not be called after 'VerilatedVcdC::open()'.");
    }
    if (false && levels && options) {}  // Prevent unused
    tfp->spTrace()->addModel(this);
    tfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->TOP));
    Vf2i___024root__trace_register(&(vlSymsp->TOP), tfp->spTrace());
}
