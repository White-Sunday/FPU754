// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vi2f.h"
#include "Vi2f__Syms.h"
#include "verilated_vcd_c.h"

//============================================================
// Constructors

Vi2f::Vi2f(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vi2f__Syms(contextp(), _vcname__, this)}
    , p_lost{vlSymsp->TOP.p_lost}
    , d{vlSymsp->TOP.d}
    , a{vlSymsp->TOP.a}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vi2f::Vi2f(const char* _vcname__)
    : Vi2f(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vi2f::~Vi2f() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vi2f___024root___eval_debug_assertions(Vi2f___024root* vlSelf);
#endif  // VL_DEBUG
void Vi2f___024root___eval_static(Vi2f___024root* vlSelf);
void Vi2f___024root___eval_initial(Vi2f___024root* vlSelf);
void Vi2f___024root___eval_settle(Vi2f___024root* vlSelf);
void Vi2f___024root___eval(Vi2f___024root* vlSelf);

void Vi2f::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vi2f::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vi2f___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_activity = true;
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vi2f___024root___eval_static(&(vlSymsp->TOP));
        Vi2f___024root___eval_initial(&(vlSymsp->TOP));
        Vi2f___024root___eval_settle(&(vlSymsp->TOP));
    }
    // MTask 0 start
    VL_DEBUG_IF(VL_DBG_MSGF("MTask0 starting\n"););
    Verilated::mtaskId(0);
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vi2f___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vi2f::eventsPending() { return false; }

uint64_t Vi2f::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "%Error: No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* Vi2f::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vi2f___024root___eval_final(Vi2f___024root* vlSelf);

VL_ATTR_COLD void Vi2f::final() {
    Vi2f___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vi2f::hierName() const { return vlSymsp->name(); }
const char* Vi2f::modelName() const { return "Vi2f"; }
unsigned Vi2f::threads() const { return 1; }
std::unique_ptr<VerilatedTraceConfig> Vi2f::traceConfig() const {
    return std::unique_ptr<VerilatedTraceConfig>{new VerilatedTraceConfig{false, false, false}};
};

//============================================================
// Trace configuration

void Vi2f___024root__trace_init_top(Vi2f___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vi2f___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vi2f___024root*>(voidSelf);
    Vi2f__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->scopeEscape(' ');
    tracep->pushNamePrefix(std::string{vlSymsp->name()} + ' ');
    Vi2f___024root__trace_init_top(vlSelf, tracep);
    tracep->popNamePrefix();
    tracep->scopeEscape('.');
}

VL_ATTR_COLD void Vi2f___024root__trace_register(Vi2f___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void Vi2f::trace(VerilatedVcdC* tfp, int levels, int options) {
    if (tfp->isOpen()) {
        vl_fatal(__FILE__, __LINE__, __FILE__,"'Vi2f::trace()' shall not be called after 'VerilatedVcdC::open()'.");
    }
    if (false && levels && options) {}  // Prevent unused
    tfp->spTrace()->addModel(this);
    tfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->TOP));
    Vi2f___024root__trace_register(&(vlSymsp->TOP), tfp->spTrace());
}
