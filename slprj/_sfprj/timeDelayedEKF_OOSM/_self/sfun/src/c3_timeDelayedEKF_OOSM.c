/* Include files */

#include <stddef.h>
#include "blas.h"
#include "timeDelayedEKF_OOSM_sfun.h"
#include "c3_timeDelayedEKF_OOSM.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "timeDelayedEKF_OOSM_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c_with_debugger(S, sfGlobalDebugInstanceStruct);

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization);
static void chart_debug_initialize_data_addresses(SimStruct *S);

/* Type Definitions */

/* Named Constants */
#define c3_event_meas_trigger          (0)
#define c3_event_record_state          (1)
#define c3_event_update                (2)
#define CALL_EVENT                     (-1)
#define c3_IN_NO_ACTIVE_CHILD          ((uint8_T)0U)
#define c3_IN_state_foo                ((uint8_T)1U)
#define c3_IN_state_init               ((uint8_T)1U)
#define c3_IN_state_update             ((uint8_T)2U)
#define c3_IN_state_wait               ((uint8_T)3U)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;

/* Function Declarations */
static void initialize_c3_timeDelayedEKF_OOSM
  (SFc3_timeDelayedEKF_OOSMInstanceStruct *chartInstance);
static void initialize_params_c3_timeDelayedEKF_OOSM
  (SFc3_timeDelayedEKF_OOSMInstanceStruct *chartInstance);
static void enable_c3_timeDelayedEKF_OOSM(SFc3_timeDelayedEKF_OOSMInstanceStruct
  *chartInstance);
static void disable_c3_timeDelayedEKF_OOSM
  (SFc3_timeDelayedEKF_OOSMInstanceStruct *chartInstance);
static void c3_update_debugger_state_c3_timeDelayedEKF_OOSM
  (SFc3_timeDelayedEKF_OOSMInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c3_timeDelayedEKF_OOSM
  (SFc3_timeDelayedEKF_OOSMInstanceStruct *chartInstance);
static void set_sim_state_c3_timeDelayedEKF_OOSM
  (SFc3_timeDelayedEKF_OOSMInstanceStruct *chartInstance, const mxArray *c3_st);
static void c3_set_sim_state_side_effects_c3_timeDelayedEKF_OOSM
  (SFc3_timeDelayedEKF_OOSMInstanceStruct *chartInstance);
static void finalize_c3_timeDelayedEKF_OOSM
  (SFc3_timeDelayedEKF_OOSMInstanceStruct *chartInstance);
static void sf_gateway_c3_timeDelayedEKF_OOSM
  (SFc3_timeDelayedEKF_OOSMInstanceStruct *chartInstance);
static void mdl_start_c3_timeDelayedEKF_OOSM
  (SFc3_timeDelayedEKF_OOSMInstanceStruct *chartInstance);
static void c3_chartstep_c3_timeDelayedEKF_OOSM
  (SFc3_timeDelayedEKF_OOSMInstanceStruct *chartInstance);
static void initSimStructsc3_timeDelayedEKF_OOSM
  (SFc3_timeDelayedEKF_OOSMInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c3_machineNumber, uint32_T
  c3_chartNumber, uint32_T c3_instanceNumber);
static const mxArray *c3_sf_marshallOut(void *chartInstanceVoid, void *c3_inData);
static int8_T c3_emlrt_marshallIn(SFc3_timeDelayedEKF_OOSMInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_b_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static uint32_T c3_b_emlrt_marshallIn(SFc3_timeDelayedEKF_OOSMInstanceStruct
  *chartInstance, const mxArray *c3_b_ev_initEventCounter, const char_T
  *c3_identifier);
static uint32_T c3_c_emlrt_marshallIn(SFc3_timeDelayedEKF_OOSMInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_c_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static int32_T c3_d_emlrt_marshallIn(SFc3_timeDelayedEKF_OOSMInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_d_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static uint8_T c3_e_emlrt_marshallIn(SFc3_timeDelayedEKF_OOSMInstanceStruct
  *chartInstance, const mxArray *c3_b_tp_state_foo, const char_T *c3_identifier);
static uint8_T c3_f_emlrt_marshallIn(SFc3_timeDelayedEKF_OOSMInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static boolean_T c3_g_emlrt_marshallIn(SFc3_timeDelayedEKF_OOSMInstanceStruct
  *chartInstance, const mxArray *c3_b_ev_init, const char_T *c3_identifier);
static boolean_T c3_h_emlrt_marshallIn(SFc3_timeDelayedEKF_OOSMInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static const mxArray *c3_i_emlrt_marshallIn
  (SFc3_timeDelayedEKF_OOSMInstanceStruct *chartInstance, const mxArray
   *c3_b_setSimStateSideEffectsInfo, const char_T *c3_identifier);
static const mxArray *c3_j_emlrt_marshallIn
  (SFc3_timeDelayedEKF_OOSMInstanceStruct *chartInstance, const mxArray *c3_u,
   const emlrtMsgIdentifier *c3_parentId);
static void init_dsm_address_info(SFc3_timeDelayedEKF_OOSMInstanceStruct
  *chartInstance);
static void init_simulink_io_address(SFc3_timeDelayedEKF_OOSMInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c3_timeDelayedEKF_OOSM
  (SFc3_timeDelayedEKF_OOSMInstanceStruct *chartInstance)
{
  if (sf_is_first_init_cond(chartInstance->S)) {
    initSimStructsc3_timeDelayedEKF_OOSM(chartInstance);
    chart_debug_initialize_data_addresses(chartInstance->S);
  }

  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c3_doSetSimStateSideEffects = 0U;
  chartInstance->c3_setSimStateSideEffectsInfo = NULL;
  chartInstance->c3_is_state_foo = c3_IN_NO_ACTIVE_CHILD;
  chartInstance->c3_tp_state_foo = 0U;
  chartInstance->c3_tp_state_init = 0U;
  chartInstance->c3_tp_state_update = 0U;
  chartInstance->c3_tp_state_wait = 0U;
  chartInstance->c3_is_active_c3_timeDelayedEKF_OOSM = 0U;
  chartInstance->c3_is_c3_timeDelayedEKF_OOSM = c3_IN_NO_ACTIVE_CHILD;
  chartInstance->c3_ev_initEventCounter = 0U;
  *chartInstance->c3_ev_init = false;
  chartInstance->c3_ev_updateEventCounter = 0U;
  *chartInstance->c3_ev_update = false;
}

static void initialize_params_c3_timeDelayedEKF_OOSM
  (SFc3_timeDelayedEKF_OOSMInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c3_timeDelayedEKF_OOSM(SFc3_timeDelayedEKF_OOSMInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c3_timeDelayedEKF_OOSM
  (SFc3_timeDelayedEKF_OOSMInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c3_update_debugger_state_c3_timeDelayedEKF_OOSM
  (SFc3_timeDelayedEKF_OOSMInstanceStruct *chartInstance)
{
  uint32_T c3_prevAniVal;
  c3_prevAniVal = _SFD_GET_ANIMATION();
  _SFD_SET_ANIMATION(0U);
  _SFD_SET_HONOR_BREAKPOINTS(0U);
  if (chartInstance->c3_is_active_c3_timeDelayedEKF_OOSM == 1U) {
    _SFD_CC_CALL(CHART_ACTIVE_TAG, 0U, chartInstance->c3_sfEvent);
  }

  if (chartInstance->c3_is_c3_timeDelayedEKF_OOSM == c3_IN_state_foo) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c3_sfEvent);
  }

  if (chartInstance->c3_is_state_foo == c3_IN_state_init) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c3_sfEvent);
  }

  if (chartInstance->c3_is_state_foo == c3_IN_state_wait) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, chartInstance->c3_sfEvent);
  }

  if (chartInstance->c3_is_state_foo == c3_IN_state_update) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c3_sfEvent);
  }

  _SFD_SET_ANIMATION(c3_prevAniVal);
  _SFD_SET_HONOR_BREAKPOINTS(1U);
  _SFD_ANIMATE();
}

static const mxArray *get_sim_state_c3_timeDelayedEKF_OOSM
  (SFc3_timeDelayedEKF_OOSMInstanceStruct *chartInstance)
{
  const mxArray *c3_st;
  const mxArray *c3_y = NULL;
  boolean_T c3_hoistedGlobal;
  boolean_T c3_u;
  const mxArray *c3_b_y = NULL;
  boolean_T c3_b_hoistedGlobal;
  boolean_T c3_b_u;
  const mxArray *c3_c_y = NULL;
  uint32_T c3_c_hoistedGlobal;
  uint32_T c3_c_u;
  const mxArray *c3_d_y = NULL;
  uint32_T c3_d_hoistedGlobal;
  uint32_T c3_d_u;
  const mxArray *c3_e_y = NULL;
  uint8_T c3_e_hoistedGlobal;
  uint8_T c3_e_u;
  const mxArray *c3_f_y = NULL;
  uint8_T c3_f_hoistedGlobal;
  uint8_T c3_f_u;
  const mxArray *c3_g_y = NULL;
  uint8_T c3_g_hoistedGlobal;
  uint8_T c3_g_u;
  const mxArray *c3_h_y = NULL;
  c3_st = NULL;
  c3_st = NULL;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_createcellmatrix(7, 1), false);
  c3_hoistedGlobal = *chartInstance->c3_ev_init;
  c3_u = c3_hoistedGlobal;
  c3_b_y = NULL;
  sf_mex_assign(&c3_b_y, sf_mex_create("y", &c3_u, 11, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c3_y, 0, c3_b_y);
  c3_b_hoistedGlobal = *chartInstance->c3_ev_update;
  c3_b_u = c3_b_hoistedGlobal;
  c3_c_y = NULL;
  sf_mex_assign(&c3_c_y, sf_mex_create("y", &c3_b_u, 11, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c3_y, 1, c3_c_y);
  c3_c_hoistedGlobal = chartInstance->c3_ev_initEventCounter;
  c3_c_u = c3_c_hoistedGlobal;
  c3_d_y = NULL;
  sf_mex_assign(&c3_d_y, sf_mex_create("y", &c3_c_u, 7, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c3_y, 2, c3_d_y);
  c3_d_hoistedGlobal = chartInstance->c3_ev_updateEventCounter;
  c3_d_u = c3_d_hoistedGlobal;
  c3_e_y = NULL;
  sf_mex_assign(&c3_e_y, sf_mex_create("y", &c3_d_u, 7, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c3_y, 3, c3_e_y);
  c3_e_hoistedGlobal = chartInstance->c3_is_active_c3_timeDelayedEKF_OOSM;
  c3_e_u = c3_e_hoistedGlobal;
  c3_f_y = NULL;
  sf_mex_assign(&c3_f_y, sf_mex_create("y", &c3_e_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c3_y, 4, c3_f_y);
  c3_f_hoistedGlobal = chartInstance->c3_is_c3_timeDelayedEKF_OOSM;
  c3_f_u = c3_f_hoistedGlobal;
  c3_g_y = NULL;
  sf_mex_assign(&c3_g_y, sf_mex_create("y", &c3_f_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c3_y, 5, c3_g_y);
  c3_g_hoistedGlobal = chartInstance->c3_is_state_foo;
  c3_g_u = c3_g_hoistedGlobal;
  c3_h_y = NULL;
  sf_mex_assign(&c3_h_y, sf_mex_create("y", &c3_g_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c3_y, 6, c3_h_y);
  sf_mex_assign(&c3_st, c3_y, false);
  return c3_st;
}

static void set_sim_state_c3_timeDelayedEKF_OOSM
  (SFc3_timeDelayedEKF_OOSMInstanceStruct *chartInstance, const mxArray *c3_st)
{
  const mxArray *c3_u;
  c3_u = sf_mex_dup(c3_st);
  *chartInstance->c3_ev_init = c3_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("ev_init", c3_u, 0)), "ev_init");
  *chartInstance->c3_ev_update = c3_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("ev_update", c3_u, 1)), "ev_update");
  chartInstance->c3_ev_initEventCounter = c3_b_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell("ev_initEventCounter", c3_u, 2)),
    "ev_initEventCounter");
  chartInstance->c3_ev_updateEventCounter = c3_b_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell("ev_updateEventCounter", c3_u, 3)),
    "ev_updateEventCounter");
  chartInstance->c3_is_active_c3_timeDelayedEKF_OOSM = c3_e_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell("is_active_c3_timeDelayedEKF_OOSM",
       c3_u, 4)), "is_active_c3_timeDelayedEKF_OOSM");
  chartInstance->c3_is_c3_timeDelayedEKF_OOSM = c3_e_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell("is_c3_timeDelayedEKF_OOSM", c3_u,
       5)), "is_c3_timeDelayedEKF_OOSM");
  chartInstance->c3_is_state_foo = c3_e_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell("is_state_foo", c3_u, 6)), "is_state_foo");
  sf_mex_assign(&chartInstance->c3_setSimStateSideEffectsInfo,
                c3_i_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(
    "setSimStateSideEffectsInfo", c3_u, 7)), "setSimStateSideEffectsInfo"), true);
  sf_mex_destroy(&c3_u);
  chartInstance->c3_doSetSimStateSideEffects = 1U;
  c3_update_debugger_state_c3_timeDelayedEKF_OOSM(chartInstance);
  sf_mex_destroy(&c3_st);
}

static void c3_set_sim_state_side_effects_c3_timeDelayedEKF_OOSM
  (SFc3_timeDelayedEKF_OOSMInstanceStruct *chartInstance)
{
  if (chartInstance->c3_doSetSimStateSideEffects != 0) {
    chartInstance->c3_tp_state_foo = (uint8_T)
      (chartInstance->c3_is_c3_timeDelayedEKF_OOSM == c3_IN_state_foo);
    chartInstance->c3_tp_state_init = (uint8_T)(chartInstance->c3_is_state_foo ==
      c3_IN_state_init);
    chartInstance->c3_tp_state_update = (uint8_T)(chartInstance->c3_is_state_foo
      == c3_IN_state_update);
    chartInstance->c3_tp_state_wait = (uint8_T)(chartInstance->c3_is_state_foo ==
      c3_IN_state_wait);
    chartInstance->c3_doSetSimStateSideEffects = 0U;
  }
}

static void finalize_c3_timeDelayedEKF_OOSM
  (SFc3_timeDelayedEKF_OOSMInstanceStruct *chartInstance)
{
  sf_mex_destroy(&chartInstance->c3_setSimStateSideEffectsInfo);
}

static void sf_gateway_c3_timeDelayedEKF_OOSM
  (SFc3_timeDelayedEKF_OOSMInstanceStruct *chartInstance)
{
  int32_T c3_inputEventFiredFlag;
  c3_set_sim_state_side_effects_c3_timeDelayedEKF_OOSM(chartInstance);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 0U, chartInstance->c3_sfEvent);
  c3_inputEventFiredFlag = 0;
  if (*chartInstance->c3_meas_trigger == 1) {
    c3_inputEventFiredFlag = 1;
    chartInstance->c3_sfEvent = c3_event_meas_trigger;
    _SFD_CE_CALL(EVENT_BEFORE_BROADCAST_TAG, c3_event_meas_trigger,
                 chartInstance->c3_sfEvent);
    c3_chartstep_c3_timeDelayedEKF_OOSM(chartInstance);
    _SFD_CE_CALL(EVENT_AFTER_BROADCAST_TAG, c3_event_meas_trigger,
                 chartInstance->c3_sfEvent);
  }

  if (*chartInstance->c3_record_state == 1) {
    c3_inputEventFiredFlag = 1;
    chartInstance->c3_sfEvent = c3_event_record_state;
    _SFD_CE_CALL(EVENT_BEFORE_BROADCAST_TAG, c3_event_record_state,
                 chartInstance->c3_sfEvent);
    c3_chartstep_c3_timeDelayedEKF_OOSM(chartInstance);
    _SFD_CE_CALL(EVENT_AFTER_BROADCAST_TAG, c3_event_record_state,
                 chartInstance->c3_sfEvent);
  }

  if (*chartInstance->c3_update == 1) {
    c3_inputEventFiredFlag = 1;
    chartInstance->c3_sfEvent = c3_event_update;
    _SFD_CE_CALL(EVENT_BEFORE_BROADCAST_TAG, c3_event_update,
                 chartInstance->c3_sfEvent);
    c3_chartstep_c3_timeDelayedEKF_OOSM(chartInstance);
    _SFD_CE_CALL(EVENT_AFTER_BROADCAST_TAG, c3_event_update,
                 chartInstance->c3_sfEvent);
  }

  if (c3_inputEventFiredFlag != 0) {
    if (chartInstance->c3_ev_initEventCounter > 0U) {
      *chartInstance->c3_ev_init = !*chartInstance->c3_ev_init;
      chartInstance->c3_ev_initEventCounter--;
    }
  }

  if (c3_inputEventFiredFlag != 0) {
    if (chartInstance->c3_ev_updateEventCounter > 0U) {
      *chartInstance->c3_ev_update = !*chartInstance->c3_ev_update;
      chartInstance->c3_ev_updateEventCounter--;
    }
  }

  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_timeDelayedEKF_OOSMMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void mdl_start_c3_timeDelayedEKF_OOSM
  (SFc3_timeDelayedEKF_OOSMInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c3_chartstep_c3_timeDelayedEKF_OOSM
  (SFc3_timeDelayedEKF_OOSMInstanceStruct *chartInstance)
{
  boolean_T c3_out;
  boolean_T c3_b_out;
  boolean_T c3_c_out;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c3_sfEvent);
  if (chartInstance->c3_is_active_c3_timeDelayedEKF_OOSM == 0U) {
    _SFD_CC_CALL(CHART_ENTER_ENTRY_FUNCTION_TAG, 0U, chartInstance->c3_sfEvent);
    chartInstance->c3_is_active_c3_timeDelayedEKF_OOSM = 1U;
    _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c3_sfEvent);
    chartInstance->c3_is_c3_timeDelayedEKF_OOSM = c3_IN_state_foo;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c3_sfEvent);
    chartInstance->c3_tp_state_foo = 1U;
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 0U, chartInstance->c3_sfEvent);
    chartInstance->c3_is_state_foo = c3_IN_state_init;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c3_sfEvent);
    chartInstance->c3_tp_state_init = 1U;
    chartInstance->c3_ev_initEventCounter++;
  } else {
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c3_sfEvent);
    switch (chartInstance->c3_is_state_foo) {
     case c3_IN_state_init:
      CV_STATE_EVAL(0, 0, 1);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 3U,
                   chartInstance->c3_sfEvent);
      c3_out = (CV_TRANSITION_EVAL(3U, (int32_T)_SFD_CCP_CALL(3U, 0,
                  chartInstance->c3_sfEvent == c3_event_update != 0U,
                  chartInstance->c3_sfEvent)) != 0);
      if (c3_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 3U, chartInstance->c3_sfEvent);
        chartInstance->c3_tp_state_init = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c3_sfEvent);
        chartInstance->c3_is_state_foo = c3_IN_state_update;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c3_sfEvent);
        chartInstance->c3_tp_state_update = 1U;
        chartInstance->c3_ev_updateEventCounter++;
      } else {
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 1U,
                     chartInstance->c3_sfEvent);
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c3_sfEvent);
      break;

     case c3_IN_state_update:
      CV_STATE_EVAL(0, 0, 2);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 1U,
                   chartInstance->c3_sfEvent);
      c3_b_out = (CV_TRANSITION_EVAL(1U, (int32_T)_SFD_CCP_CALL(1U, 0,
        chartInstance->c3_sfEvent == c3_event_meas_trigger != 0U,
        chartInstance->c3_sfEvent)) != 0);
      if (c3_b_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 1U, chartInstance->c3_sfEvent);
        chartInstance->c3_tp_state_update = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c3_sfEvent);
        chartInstance->c3_is_state_foo = c3_IN_state_wait;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, chartInstance->c3_sfEvent);
        chartInstance->c3_tp_state_wait = 1U;
      } else {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 4U, chartInstance->c3_sfEvent);
        chartInstance->c3_tp_state_update = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c3_sfEvent);
        chartInstance->c3_is_state_foo = c3_IN_state_update;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c3_sfEvent);
        chartInstance->c3_tp_state_update = 1U;
        chartInstance->c3_ev_updateEventCounter++;
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 2U, chartInstance->c3_sfEvent);
      break;

     case c3_IN_state_wait:
      CV_STATE_EVAL(0, 0, 3);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 2U,
                   chartInstance->c3_sfEvent);
      c3_c_out = (CV_TRANSITION_EVAL(2U, (int32_T)_SFD_CCP_CALL(2U, 0,
        chartInstance->c3_sfEvent == c3_event_record_state != 0U,
        chartInstance->c3_sfEvent)) != 0);
      if (c3_c_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 2U, chartInstance->c3_sfEvent);
        chartInstance->c3_tp_state_wait = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, chartInstance->c3_sfEvent);
        chartInstance->c3_is_state_foo = c3_IN_state_init;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c3_sfEvent);
        chartInstance->c3_tp_state_init = 1U;
        chartInstance->c3_ev_initEventCounter++;
      } else {
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 3U,
                     chartInstance->c3_sfEvent);
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 3U, chartInstance->c3_sfEvent);
      break;

     default:
      CV_STATE_EVAL(0, 0, 0);

      /* Unreachable state, for coverage only */
      chartInstance->c3_is_state_foo = c3_IN_NO_ACTIVE_CHILD;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c3_sfEvent);
      break;
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c3_sfEvent);
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c3_sfEvent);
}

static void initSimStructsc3_timeDelayedEKF_OOSM
  (SFc3_timeDelayedEKF_OOSMInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c3_machineNumber, uint32_T
  c3_chartNumber, uint32_T c3_instanceNumber)
{
  (void)c3_machineNumber;
  (void)c3_chartNumber;
  (void)c3_instanceNumber;
}

const mxArray *sf_c3_timeDelayedEKF_OOSM_get_eml_resolved_functions_info(void)
{
  const mxArray *c3_nameCaptureInfo = NULL;
  c3_nameCaptureInfo = NULL;
  sf_mex_assign(&c3_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c3_nameCaptureInfo;
}

static const mxArray *c3_sf_marshallOut(void *chartInstanceVoid, void *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int8_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_timeDelayedEKF_OOSMInstanceStruct *chartInstance;
  chartInstance = (SFc3_timeDelayedEKF_OOSMInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_u = *(int8_T *)c3_inData;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 2, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static int8_T c3_emlrt_marshallIn(SFc3_timeDelayedEKF_OOSMInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  int8_T c3_y;
  int8_T c3_i0;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_i0, 1, 2, 0U, 0, 0U, 0);
  c3_y = c3_i0;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_b_meas_trigger;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  int8_T c3_y;
  SFc3_timeDelayedEKF_OOSMInstanceStruct *chartInstance;
  chartInstance = (SFc3_timeDelayedEKF_OOSMInstanceStruct *)chartInstanceVoid;
  c3_b_meas_trigger = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_meas_trigger),
    &c3_thisId);
  sf_mex_destroy(&c3_b_meas_trigger);
  *(int8_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_b_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  uint32_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_timeDelayedEKF_OOSMInstanceStruct *chartInstance;
  chartInstance = (SFc3_timeDelayedEKF_OOSMInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_u = *(uint32_T *)c3_inData;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 7, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static uint32_T c3_b_emlrt_marshallIn(SFc3_timeDelayedEKF_OOSMInstanceStruct
  *chartInstance, const mxArray *c3_b_ev_initEventCounter, const char_T
  *c3_identifier)
{
  uint32_T c3_y;
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c3_b_ev_initEventCounter), &c3_thisId);
  sf_mex_destroy(&c3_b_ev_initEventCounter);
  return c3_y;
}

static uint32_T c3_c_emlrt_marshallIn(SFc3_timeDelayedEKF_OOSMInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  uint32_T c3_y;
  uint32_T c3_u0;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_u0, 1, 7, 0U, 0, 0U, 0);
  c3_y = c3_u0;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_b_ev_initEventCounter;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  uint32_T c3_y;
  SFc3_timeDelayedEKF_OOSMInstanceStruct *chartInstance;
  chartInstance = (SFc3_timeDelayedEKF_OOSMInstanceStruct *)chartInstanceVoid;
  c3_b_ev_initEventCounter = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c3_b_ev_initEventCounter), &c3_thisId);
  sf_mex_destroy(&c3_b_ev_initEventCounter);
  *(uint32_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_c_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_timeDelayedEKF_OOSMInstanceStruct *chartInstance;
  chartInstance = (SFc3_timeDelayedEKF_OOSMInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_u = *(int32_T *)c3_inData;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static int32_T c3_d_emlrt_marshallIn(SFc3_timeDelayedEKF_OOSMInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  int32_T c3_y;
  int32_T c3_i1;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_i1, 1, 6, 0U, 0, 0U, 0);
  c3_y = c3_i1;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_b_sfEvent;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  int32_T c3_y;
  SFc3_timeDelayedEKF_OOSMInstanceStruct *chartInstance;
  chartInstance = (SFc3_timeDelayedEKF_OOSMInstanceStruct *)chartInstanceVoid;
  c3_b_sfEvent = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_sfEvent),
    &c3_thisId);
  sf_mex_destroy(&c3_b_sfEvent);
  *(int32_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_d_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  uint8_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_timeDelayedEKF_OOSMInstanceStruct *chartInstance;
  chartInstance = (SFc3_timeDelayedEKF_OOSMInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_u = *(uint8_T *)c3_inData;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static uint8_T c3_e_emlrt_marshallIn(SFc3_timeDelayedEKF_OOSMInstanceStruct
  *chartInstance, const mxArray *c3_b_tp_state_foo, const char_T *c3_identifier)
{
  uint8_T c3_y;
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_tp_state_foo),
    &c3_thisId);
  sf_mex_destroy(&c3_b_tp_state_foo);
  return c3_y;
}

static uint8_T c3_f_emlrt_marshallIn(SFc3_timeDelayedEKF_OOSMInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  uint8_T c3_y;
  uint8_T c3_u1;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_u1, 1, 3, 0U, 0, 0U, 0);
  c3_y = c3_u1;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_b_tp_state_foo;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  uint8_T c3_y;
  SFc3_timeDelayedEKF_OOSMInstanceStruct *chartInstance;
  chartInstance = (SFc3_timeDelayedEKF_OOSMInstanceStruct *)chartInstanceVoid;
  c3_b_tp_state_foo = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_tp_state_foo),
    &c3_thisId);
  sf_mex_destroy(&c3_b_tp_state_foo);
  *(uint8_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

static boolean_T c3_g_emlrt_marshallIn(SFc3_timeDelayedEKF_OOSMInstanceStruct
  *chartInstance, const mxArray *c3_b_ev_init, const char_T *c3_identifier)
{
  boolean_T c3_y;
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_ev_init),
    &c3_thisId);
  sf_mex_destroy(&c3_b_ev_init);
  return c3_y;
}

static boolean_T c3_h_emlrt_marshallIn(SFc3_timeDelayedEKF_OOSMInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  boolean_T c3_y;
  boolean_T c3_b0;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_b0, 1, 11, 0U, 0, 0U, 0);
  c3_y = c3_b0;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static const mxArray *c3_i_emlrt_marshallIn
  (SFc3_timeDelayedEKF_OOSMInstanceStruct *chartInstance, const mxArray
   *c3_b_setSimStateSideEffectsInfo, const char_T *c3_identifier)
{
  const mxArray *c3_y = NULL;
  emlrtMsgIdentifier c3_thisId;
  c3_y = NULL;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  sf_mex_assign(&c3_y, c3_j_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c3_b_setSimStateSideEffectsInfo), &c3_thisId), false);
  sf_mex_destroy(&c3_b_setSimStateSideEffectsInfo);
  return c3_y;
}

static const mxArray *c3_j_emlrt_marshallIn
  (SFc3_timeDelayedEKF_OOSMInstanceStruct *chartInstance, const mxArray *c3_u,
   const emlrtMsgIdentifier *c3_parentId)
{
  const mxArray *c3_y = NULL;
  (void)chartInstance;
  (void)c3_parentId;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_duplicatearraysafe(&c3_u), false);
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void init_dsm_address_info(SFc3_timeDelayedEKF_OOSMInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc3_timeDelayedEKF_OOSMInstanceStruct
  *chartInstance)
{
  chartInstance->c3_meas_trigger = (int8_T *)(ssGetInputPortSignalPtrs_wrapper
    (chartInstance->S, 0))[0U];
  chartInstance->c3_record_state = (int8_T *)(ssGetInputPortSignalPtrs_wrapper
    (chartInstance->S, 0))[1U];
  chartInstance->c3_ev_init = (boolean_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c3_ev_update = (boolean_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c3_update = (int8_T *)(ssGetInputPortSignalPtrs_wrapper
    (chartInstance->S, 0))[2U];
}

/* SFunction Glue Code */
#ifdef utFree
#undef utFree
#endif

#ifdef utMalloc
#undef utMalloc
#endif

#ifdef __cplusplus

extern "C" void *utMalloc(size_t size);
extern "C" void utFree(void*);

#else

extern void *utMalloc(size_t size);
extern void utFree(void*);

#endif

void sf_c3_timeDelayedEKF_OOSM_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(4202247395U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(381469371U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1668624304U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(851446421U);
}

mxArray* sf_c3_timeDelayedEKF_OOSM_get_post_codegen_info(void);
mxArray *sf_c3_timeDelayedEKF_OOSM_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("BgccIToW5srDzB527FO3TC");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  {
    mxArray* mxPostCodegenInfo = sf_c3_timeDelayedEKF_OOSM_get_post_codegen_info
      ();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c3_timeDelayedEKF_OOSM_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c3_timeDelayedEKF_OOSM_jit_fallback_info(void)
{
  const char *infoFields[] = { "fallbackType", "fallbackReason",
    "hiddenFallbackType", "hiddenFallbackReason", "incompatibleSymbol" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 5, infoFields);
  mxArray *fallbackType = mxCreateString("pre");
  mxArray *fallbackReason = mxCreateString("hasBreakpoints");
  mxArray *hiddenFallbackType = mxCreateString("none");
  mxArray *hiddenFallbackReason = mxCreateString("");
  mxArray *incompatibleSymbol = mxCreateString("");
  mxSetField(mxInfo, 0, infoFields[0], fallbackType);
  mxSetField(mxInfo, 0, infoFields[1], fallbackReason);
  mxSetField(mxInfo, 0, infoFields[2], hiddenFallbackType);
  mxSetField(mxInfo, 0, infoFields[3], hiddenFallbackReason);
  mxSetField(mxInfo, 0, infoFields[4], incompatibleSymbol);
  return mxInfo;
}

mxArray *sf_c3_timeDelayedEKF_OOSM_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c3_timeDelayedEKF_OOSM_get_post_codegen_info(void)
{
  const char* fieldNames[] = { "exportedFunctionsUsedByThisChart",
    "exportedFunctionsChecksum" };

  mwSize dims[2] = { 1, 1 };

  mxArray* mxPostCodegenInfo = mxCreateStructArray(2, dims, sizeof(fieldNames)/
    sizeof(fieldNames[0]), fieldNames);

  {
    mxArray* mxExportedFunctionsChecksum = mxCreateString("");
    mwSize exp_dims[2] = { 0, 1 };

    mxArray* mxExportedFunctionsUsedByThisChart = mxCreateCellArray(2, exp_dims);
    mxSetField(mxPostCodegenInfo, 0, "exportedFunctionsUsedByThisChart",
               mxExportedFunctionsUsedByThisChart);
    mxSetField(mxPostCodegenInfo, 0, "exportedFunctionsChecksum",
               mxExportedFunctionsChecksum);
  }

  return mxPostCodegenInfo;
}

static const mxArray *sf_get_sim_state_info_c3_timeDelayedEKF_OOSM(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x7'type','srcId','name','auxInfo'{{M[6],M[30],T\"ev_init\",},{M[6],M[31],T\"ev_update\",},{M[7],M[30],T\"ev_initEventCounter\",},{M[7],M[31],T\"ev_updateEventCounter\",},{M[8],M[0],T\"is_active_c3_timeDelayedEKF_OOSM\",},{M[9],M[0],T\"is_c3_timeDelayedEKF_OOSM\",},{M[9],M[1],T\"is_state_foo\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 7, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c3_timeDelayedEKF_OOSM_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc3_timeDelayedEKF_OOSMInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc3_timeDelayedEKF_OOSMInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _timeDelayedEKF_OOSMMachineNumber_,
           3,
           4,
           5,
           0,
           0,
           5,
           0,
           0,
           0,
           0,
           &(chartInstance->chartNumber),
           &(chartInstance->instanceNumber),
           (void *)S);

        /* Each instance must initialize its own list of scripts */
        init_script_number_translation(_timeDelayedEKF_OOSMMachineNumber_,
          chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_timeDelayedEKF_OOSMMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _timeDelayedEKF_OOSMMachineNumber_,
            chartInstance->chartNumber,
            5,
            5,
            5);
          _SFD_EVENT_SCOPE(0,1);
          _SFD_EVENT_SCOPE(1,1);
          _SFD_EVENT_SCOPE(2,1);
          _SFD_EVENT_SCOPE(3,2);
          _SFD_EVENT_SCOPE(4,2);
          _SFD_STATE_INFO(0,0,0);
          _SFD_STATE_INFO(1,0,0);
          _SFD_STATE_INFO(2,0,0);
          _SFD_STATE_INFO(3,0,0);
          _SFD_CH_SUBSTATE_COUNT(1);
          _SFD_CH_SUBSTATE_DECOMP(0);
          _SFD_CH_SUBSTATE_INDEX(0,0);
          _SFD_ST_SUBSTATE_COUNT(0,3);
          _SFD_ST_SUBSTATE_INDEX(0,0,1);
          _SFD_ST_SUBSTATE_INDEX(0,1,2);
          _SFD_ST_SUBSTATE_INDEX(0,2,3);
          _SFD_ST_SUBSTATE_COUNT(1,0);
          _SFD_ST_SUBSTATE_COUNT(2,0);
          _SFD_ST_SUBSTATE_COUNT(3,0);
        }

        _SFD_CV_INIT_CHART(1,0,0,0);

        {
          _SFD_CV_INIT_STATE(0,3,1,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(1,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(2,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(3,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(4,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = { 0 };

          static unsigned int sEndGuardMap[] = { 12 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(1,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 0 };

          static unsigned int sEndGuardMap[] = { 6 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(3,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 0 };

          static unsigned int sEndGuardMap[] = { 12 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(2,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _timeDelayedEKF_OOSMMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static void chart_debug_initialize_data_addresses(SimStruct *S)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc3_timeDelayedEKF_OOSMInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc3_timeDelayedEKF_OOSMInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S)) {
      /* do this only if simulation is starting and after we know the addresses of all data */
      {
        (void)chartInstance;
      }
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "s0B3nRQvHzzyhUJyYa6S5VC";
}

static void sf_opaque_initialize_c3_timeDelayedEKF_OOSM(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc3_timeDelayedEKF_OOSMInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c3_timeDelayedEKF_OOSM
    ((SFc3_timeDelayedEKF_OOSMInstanceStruct*) chartInstanceVar);
  initialize_c3_timeDelayedEKF_OOSM((SFc3_timeDelayedEKF_OOSMInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c3_timeDelayedEKF_OOSM(void *chartInstanceVar)
{
  enable_c3_timeDelayedEKF_OOSM((SFc3_timeDelayedEKF_OOSMInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c3_timeDelayedEKF_OOSM(void *chartInstanceVar)
{
  disable_c3_timeDelayedEKF_OOSM((SFc3_timeDelayedEKF_OOSMInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c3_timeDelayedEKF_OOSM(void *chartInstanceVar)
{
  sf_gateway_c3_timeDelayedEKF_OOSM((SFc3_timeDelayedEKF_OOSMInstanceStruct*)
    chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c3_timeDelayedEKF_OOSM(SimStruct*
  S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  return get_sim_state_c3_timeDelayedEKF_OOSM
    ((SFc3_timeDelayedEKF_OOSMInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
}

static void sf_opaque_set_sim_state_c3_timeDelayedEKF_OOSM(SimStruct* S, const
  mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  set_sim_state_c3_timeDelayedEKF_OOSM((SFc3_timeDelayedEKF_OOSMInstanceStruct*)
    chartInfo->chartInstance, st);
}

static void sf_opaque_terminate_c3_timeDelayedEKF_OOSM(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc3_timeDelayedEKF_OOSMInstanceStruct*) chartInstanceVar
      )->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_timeDelayedEKF_OOSM_optimization_info();
    }

    finalize_c3_timeDelayedEKF_OOSM((SFc3_timeDelayedEKF_OOSMInstanceStruct*)
      chartInstanceVar);
    utFree(chartInstanceVar);
    if (crtInfo != NULL) {
      utFree(crtInfo);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc3_timeDelayedEKF_OOSM((SFc3_timeDelayedEKF_OOSMInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c3_timeDelayedEKF_OOSM(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    initialize_params_c3_timeDelayedEKF_OOSM
      ((SFc3_timeDelayedEKF_OOSMInstanceStruct*)(chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c3_timeDelayedEKF_OOSM(SimStruct *S)
{
  ssMdlUpdateIsEmpty(S, 1);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_timeDelayedEKF_OOSM_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,3);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,1);
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,3,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,3);
    if (chartIsInlinable) {
    }

    ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=2; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,3);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(3898185972U));
  ssSetChecksum1(S,(1714184306U));
  ssSetChecksum2(S,(2483936048U));
  ssSetChecksum3(S,(1660012195U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c3_timeDelayedEKF_OOSM(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Stateflow");
  }
}

static void mdlStart_c3_timeDelayedEKF_OOSM(SimStruct *S)
{
  SFc3_timeDelayedEKF_OOSMInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc3_timeDelayedEKF_OOSMInstanceStruct *)utMalloc(sizeof
    (SFc3_timeDelayedEKF_OOSMInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc3_timeDelayedEKF_OOSMInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 0;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c3_timeDelayedEKF_OOSM;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c3_timeDelayedEKF_OOSM;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c3_timeDelayedEKF_OOSM;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c3_timeDelayedEKF_OOSM;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c3_timeDelayedEKF_OOSM;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c3_timeDelayedEKF_OOSM;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c3_timeDelayedEKF_OOSM;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c3_timeDelayedEKF_OOSM;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c3_timeDelayedEKF_OOSM;
  chartInstance->chartInfo.mdlStart = mdlStart_c3_timeDelayedEKF_OOSM;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c3_timeDelayedEKF_OOSM;
  chartInstance->chartInfo.extModeExec = NULL;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->chartInfo.callAtomicSubchartUserFcn = NULL;
  chartInstance->chartInfo.callAtomicSubchartAutoFcn = NULL;
  chartInstance->chartInfo.debugInstance = sfGlobalDebugInstanceStruct;
  chartInstance->S = S;
  crtInfo->isEnhancedMooreMachine = 0;
  crtInfo->checksum = SF_RUNTIME_INFO_CHECKSUM;
  crtInfo->fCheckOverflow = sf_runtime_overflow_check_is_on(S);
  crtInfo->instanceInfo = (&(chartInstance->chartInfo));
  crtInfo->isJITEnabled = false;
  crtInfo->compiledInfo = NULL;
  ssSetUserData(S,(void *)(crtInfo));  /* register the chart instance with simstruct */
  init_dsm_address_info(chartInstance);
  init_simulink_io_address(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  chart_debug_initialization(S,1);
}

void c3_timeDelayedEKF_OOSM_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c3_timeDelayedEKF_OOSM(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c3_timeDelayedEKF_OOSM(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c3_timeDelayedEKF_OOSM(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c3_timeDelayedEKF_OOSM_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
