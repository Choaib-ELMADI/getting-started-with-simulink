/*
 * File: SignalProcessing.h
 *
 * Code generated for Simulink model 'SignalProcessing'.
 *
 * Model version                  : 1.6
 * Simulink Coder version         : 8.14 (R2018a) 06-Feb-2018
 * C/C++ source code generated on : Tue Apr 30 01:39:11 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_SignalProcessing_h_
#define RTW_HEADER_SignalProcessing_h_
#include <math.h>
#include <string.h>
#include <stddef.h>
#ifndef SignalProcessing_COMMON_INCLUDES_
# define SignalProcessing_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#endif                                 /* SignalProcessing_COMMON_INCLUDES_ */

#include "SignalProcessing_types.h"
#include "MW_target_hardware_resources.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmStepTask
# define rtmStepTask(rtm, idx)         ((rtm)->Timing.TaskCounters.TID[(idx)] == 0)
#endif

#ifndef rtmTaskCounter
# define rtmTaskCounter(rtm, idx)      ((rtm)->Timing.TaskCounters.TID[(idx)])
#endif

/* Block signals (default storage) */
typedef struct {
  real_T Abs[12];                      /* '<Root>/Abs' */
  real_T Abs1[12];                     /* '<Root>/Abs1' */
} B_SignalProcessing_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T Delay1_DSTATE[2];             /* '<Root>/Delay1' */
  real_T Buffer_CircBuf[24];           /* '<Root>/Buffer' */
  real_T Delay22_DSTATE;               /* '<S4>/Delay22' */
  real_T Delay21_DSTATE;               /* '<S4>/Delay21' */
  real_T Delay11_DSTATE;               /* '<S4>/Delay11' */
  real_T Delay12_DSTATE;               /* '<S4>/Delay12' */
  real_T Buffer1_CircBuf[24];          /* '<Root>/Buffer1' */
  real_T Delay11_DSTATE_f;             /* '<S3>/Delay11' */
  real_T Delay21_DSTATE_c;             /* '<S3>/Delay21' */
  real_T Delay12_DSTATE_c;             /* '<S3>/Delay12' */
  real_T Delay22_DSTATE_o;             /* '<S3>/Delay22' */
  int32_T Buffer_inBufPtrIdx;          /* '<Root>/Buffer' */
  int32_T Buffer_outBufPtrIdx;         /* '<Root>/Buffer' */
  int32_T Buffer1_inBufPtrIdx;         /* '<Root>/Buffer1' */
  int32_T Buffer1_outBufPtrIdx;        /* '<Root>/Buffer1' */
} DW_SignalProcessing_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T Power;                        /* '<Root>/Power' */
} ExtU_SignalProcessing_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  uint8_T Outport;                     /* '<Root>/Outport' */
} ExtY_SignalProcessing_T;

/* Parameters (default storage) */
struct P_SignalProcessing_T_ {
  real_T CompareToConstant1_const;     /* Mask Parameter: CompareToConstant1_const
                                        * Referenced by: '<S2>/Constant'
                                        */
  real_T CompareToConstant_const;      /* Mask Parameter: CompareToConstant_const
                                        * Referenced by: '<S1>/Constant'
                                        */
  real_T Delay1_InitialCondition;      /* Expression: 0.0
                                        * Referenced by: '<Root>/Delay1'
                                        */
  real_T Buffer_ic;                    /* Expression: 0
                                        * Referenced by: '<Root>/Buffer'
                                        */
  real_T Delay22_InitialCondition;     /* Expression: 0
                                        * Referenced by: '<S4>/Delay22'
                                        */
  real_T Delay21_InitialCondition;     /* Expression: 0
                                        * Referenced by: '<S4>/Delay21'
                                        */
  real_T s1_Gain;                      /* Expression: 0.169519875796438041
                                        * Referenced by: '<S4>/s(1)'
                                        */
  real_T Delay11_InitialCondition;     /* Expression: 0
                                        * Referenced by: '<S4>/Delay11'
                                        */
  real_T a21_Gain;                     /* Expression: -0.986468505507065885
                                        * Referenced by: '<S4>/a(2)(1)'
                                        */
  real_T a31_Gain;                     /* Expression: 0.664548008692817938
                                        * Referenced by: '<S4>/a(3)(1)'
                                        */
  real_T b21_Gain;                     /* Expression: 2
                                        * Referenced by: '<S4>/b(2)(1)'
                                        */
  real_T s2_Gain;                      /* Expression: 0.0770355431600029394
                                        * Referenced by: '<S4>/s(2)'
                                        */
  real_T Delay12_InitialCondition;     /* Expression: 0
                                        * Referenced by: '<S4>/Delay12'
                                        */
  real_T a22_Gain;                     /* Expression: -0.991774516589532085
                                        * Referenced by: '<S4>/a(2)(2)'
                                        */
  real_T a32_Gain;                     /* Expression: 0.299916689229544009
                                        * Referenced by: '<S4>/a(3)(2)'
                                        */
  real_T b22_Gain;                     /* Expression: 2
                                        * Referenced by: '<S4>/b(2)(2)'
                                        */
  real_T s3_Gain;                      /* Expression: 0.99426007395295668
                                        * Referenced by: '<S4>/s(3)'
                                        */
  real_T Buffer1_ic;                   /* Expression: 0
                                        * Referenced by: '<Root>/Buffer1'
                                        */
  real_T Delay11_InitialCondition_g;   /* Expression: 0
                                        * Referenced by: '<S3>/Delay11'
                                        */
  real_T a21_Gain_h;                   /* Expression: -1.37746147936585883
                                        * Referenced by: '<S3>/a(2)(1)'
                                        */
  real_T s1_Gain_o;                    /* Expression: 0.778303989583340239
                                        * Referenced by: '<S3>/s(1)'
                                        */
  real_T Delay21_InitialCondition_c;   /* Expression: 0
                                        * Referenced by: '<S3>/Delay21'
                                        */
  real_T a31_Gain_j;                   /* Expression: 0.735754478967502124
                                        * Referenced by: '<S3>/a(3)(1)'
                                        */
  real_T b21_Gain_i;                   /* Expression: -2
                                        * Referenced by: '<S3>/b(2)(1)'
                                        */
  real_T s2_Gain_e;                    /* Expression: 0.500365739143975308
                                        * Referenced by: '<S3>/s(2)'
                                        */
  real_T Delay12_InitialCondition_m;   /* Expression: 0
                                        * Referenced by: '<S3>/Delay12'
                                        */
  real_T a22_Gain_k;                   /* Expression: -0.781642879726572759
                                        * Referenced by: '<S3>/a(2)(2)'
                                        */
  real_T Delay22_InitialCondition_g;   /* Expression: 0
                                        * Referenced by: '<S3>/Delay22'
                                        */
  real_T a32_Gain_b;                   /* Expression: 0.219820076849328444
                                        * Referenced by: '<S3>/a(3)(2)'
                                        */
  real_T b22_Gain_a;                   /* Expression: -2
                                        * Referenced by: '<S3>/b(2)(2)'
                                        */
  real_T s3_Gain_j;                    /* Expression: 0.99426007395295668
                                        * Referenced by: '<S3>/s(3)'
                                        */
  uint16_T Delay1_DelayLength;         /* Computed Parameter: Delay1_DelayLength
                                        * Referenced by: '<Root>/Delay1'
                                        */
  uint16_T Delay22_DelayLength;        /* Computed Parameter: Delay22_DelayLength
                                        * Referenced by: '<S4>/Delay22'
                                        */
  uint16_T Delay21_DelayLength;        /* Computed Parameter: Delay21_DelayLength
                                        * Referenced by: '<S4>/Delay21'
                                        */
  uint16_T Delay11_DelayLength;        /* Computed Parameter: Delay11_DelayLength
                                        * Referenced by: '<S4>/Delay11'
                                        */
  uint16_T Delay12_DelayLength;        /* Computed Parameter: Delay12_DelayLength
                                        * Referenced by: '<S4>/Delay12'
                                        */
  uint16_T Delay11_DelayLength_b;      /* Computed Parameter: Delay11_DelayLength_b
                                        * Referenced by: '<S3>/Delay11'
                                        */
  uint16_T Delay21_DelayLength_i;      /* Computed Parameter: Delay21_DelayLength_i
                                        * Referenced by: '<S3>/Delay21'
                                        */
  uint16_T Delay12_DelayLength_o;      /* Computed Parameter: Delay12_DelayLength_o
                                        * Referenced by: '<S3>/Delay12'
                                        */
  uint16_T Delay22_DelayLength_l;      /* Computed Parameter: Delay22_DelayLength_l
                                        * Referenced by: '<S3>/Delay22'
                                        */
  uint8_T Gain_Gain;                   /* Computed Parameter: Gain_Gain
                                        * Referenced by: '<Root>/Gain'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_SignalProcessing_T {
  const char_T *errorStatus;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    struct {
      uint8_T TID[2];
    } TaskCounters;
  } Timing;
};

/* Block parameters (default storage) */
extern P_SignalProcessing_T SignalProcessing_P;

/* Block signals (default storage) */
extern B_SignalProcessing_T SignalProcessing_B;

/* Block states (default storage) */
extern DW_SignalProcessing_T SignalProcessing_DW;

/* External inputs (root inport signals with default storage) */
extern ExtU_SignalProcessing_T SignalProcessing_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_SignalProcessing_T SignalProcessing_Y;

/* External function called from main */
extern void SignalProcessing_SetEventsForThisBaseStep(boolean_T *eventFlags);

/* Model entry point functions */
extern void SignalProcessing_SetEventsForThisBaseStep(boolean_T *eventFlags);
extern void SignalProcessing_initialize(void);
extern void SignalProcessing_step0(void);
extern void SignalProcessing_step1(void);
extern void SignalProcessing_terminate(void);

/* Real-time Model object */
extern RT_MODEL_SignalProcessing_T *const SignalProcessing_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'SignalProcessing'
 * '<S1>'   : 'SignalProcessing/Compare To Constant'
 * '<S2>'   : 'SignalProcessing/Compare To Constant1'
 * '<S3>'   : 'SignalProcessing/Highpass Filter'
 * '<S4>'   : 'SignalProcessing/Lowpass Filter'
 */
#endif                                 /* RTW_HEADER_SignalProcessing_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
