#ifndef __c3_timeDelayedEKF_OOSM_h__
#define __c3_timeDelayedEKF_OOSM_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc3_timeDelayedEKF_OOSMInstanceStruct
#define typedef_SFc3_timeDelayedEKF_OOSMInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  uint32_T c3_ev_initEventCounter;
  uint32_T c3_ev_updateEventCounter;
  int32_T c3_sfEvent;
  uint8_T c3_tp_state_foo;
  uint8_T c3_tp_state_init;
  uint8_T c3_tp_state_wait;
  uint8_T c3_tp_state_update;
  boolean_T c3_isStable;
  uint8_T c3_is_active_c3_timeDelayedEKF_OOSM;
  uint8_T c3_is_c3_timeDelayedEKF_OOSM;
  uint8_T c3_is_state_foo;
  uint8_T c3_doSetSimStateSideEffects;
  const mxArray *c3_setSimStateSideEffectsInfo;
  int8_T *c3_meas_trigger;
  int8_T *c3_record_state;
  boolean_T *c3_ev_init;
  boolean_T *c3_ev_update;
  int8_T *c3_update;
} SFc3_timeDelayedEKF_OOSMInstanceStruct;

#endif                                 /*typedef_SFc3_timeDelayedEKF_OOSMInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c3_timeDelayedEKF_OOSM_get_eml_resolved_functions_info
  (void);

/* Function Definitions */
extern void sf_c3_timeDelayedEKF_OOSM_get_check_sum(mxArray *plhs[]);
extern void c3_timeDelayedEKF_OOSM_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif
