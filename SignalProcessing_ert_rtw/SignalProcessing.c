/*
 * File: SignalProcessing.c
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

#include "SignalProcessing.h"
#include "SignalProcessing_private.h"

/* Block signals (default storage) */
B_SignalProcessing_T SignalProcessing_B;

/* Block states (default storage) */
DW_SignalProcessing_T SignalProcessing_DW;

/* External inputs (root inport signals with default storage) */
ExtU_SignalProcessing_T SignalProcessing_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_SignalProcessing_T SignalProcessing_Y;

/* Real-time model */
RT_MODEL_SignalProcessing_T SignalProcessing_M_;
RT_MODEL_SignalProcessing_T *const SignalProcessing_M = &SignalProcessing_M_;
static void rate_monotonic_scheduler(void);

/*
 * Set which subrates need to run this base step (base rate always runs).
 * This function must be called prior to calling the model step function
 * in order to "remember" which rates need to run this base step.  The
 * buffering of events allows for overlapping preemption.
 */
void SignalProcessing_SetEventsForThisBaseStep(boolean_T *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[1] = ((boolean_T)rtmStepTask(SignalProcessing_M, 1));
}

/*
 *   This function updates active task flag for each subrate
 * and rate transition flags for tasks that exchange data.
 * The function assumes rate-monotonic multitasking scheduler.
 * The function must be called at model base rate so that
 * the generated code self-manages all its subrates and rate
 * transition flags.
 */
static void rate_monotonic_scheduler(void)
{
  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (SignalProcessing_M->Timing.TaskCounters.TID[1])++;
  if ((SignalProcessing_M->Timing.TaskCounters.TID[1]) > 11) {/* Sample time: [0.125s, 0.0s] */
    SignalProcessing_M->Timing.TaskCounters.TID[1] = 0;
  }
}

/* Model step function for TID0 */
void SignalProcessing_step0(void)      /* Sample time: [0.010416666666666666s, 0.0s] */
{
  int32_T i;
  int32_T offsetFromMemBase;
  int32_T nSamps;
  real_T rtb_Delay21;
  real_T HPFPower;

  {                                    /* Sample time: [0.010416666666666666s, 0.0s] */
    rate_monotonic_scheduler();
  }

  /* Delay: '<Root>/Delay1' */
  HPFPower = SignalProcessing_DW.Delay1_DSTATE[0];

  /* Buffer: '<Root>/Buffer' */
  nSamps = 24L;
  offsetFromMemBase = SignalProcessing_DW.Buffer_inBufPtrIdx;
  if (24L - SignalProcessing_DW.Buffer_inBufPtrIdx <= 1L) {
    for (i = 0L; i < 24L - SignalProcessing_DW.Buffer_inBufPtrIdx; i++) {
      SignalProcessing_DW.Buffer_CircBuf[SignalProcessing_DW.Buffer_inBufPtrIdx
        + i] = HPFPower;
    }

    offsetFromMemBase = 0L;
    nSamps = SignalProcessing_DW.Buffer_inBufPtrIdx;
  }

  for (i = 0L; i < nSamps - 23L; i++) {
    SignalProcessing_DW.Buffer_CircBuf[offsetFromMemBase + i] = HPFPower;
  }

  SignalProcessing_DW.Buffer_inBufPtrIdx++;
  if (SignalProcessing_DW.Buffer_inBufPtrIdx >= 24L) {
    SignalProcessing_DW.Buffer_inBufPtrIdx -= 24L;
  }

  /* End of Buffer: '<Root>/Buffer' */

  /* Delay: '<S4>/Delay22' */
  HPFPower = SignalProcessing_DW.Delay22_DSTATE;

  /* Delay: '<S4>/Delay21' */
  rtb_Delay21 = SignalProcessing_DW.Delay21_DSTATE;

  /* Delay: '<S4>/Delay11' incorporates:
   *  Delay: '<S4>/Delay21'
   */
  SignalProcessing_DW.Delay21_DSTATE = SignalProcessing_DW.Delay11_DSTATE;

  /* Sum: '<S4>/SumA31' incorporates:
   *  Delay: '<S4>/Delay11'
   *  Delay: '<S4>/Delay21'
   *  Gain: '<S4>/a(2)(1)'
   *  Gain: '<S4>/a(3)(1)'
   *  Gain: '<S4>/s(1)'
   *  Inport: '<Root>/Power'
   *  Sum: '<S4>/SumA21'
   */
  SignalProcessing_DW.Delay11_DSTATE = (SignalProcessing_P.s1_Gain *
    SignalProcessing_U.Power - SignalProcessing_P.a21_Gain *
    SignalProcessing_DW.Delay21_DSTATE) - SignalProcessing_P.a31_Gain *
    rtb_Delay21;

  /* Delay: '<S4>/Delay12' incorporates:
   *  Delay: '<S4>/Delay22'
   */
  SignalProcessing_DW.Delay22_DSTATE = SignalProcessing_DW.Delay12_DSTATE;

  /* Sum: '<S4>/SumA32' incorporates:
   *  Delay: '<S4>/Delay11'
   *  Delay: '<S4>/Delay12'
   *  Delay: '<S4>/Delay21'
   *  Delay: '<S4>/Delay22'
   *  Gain: '<S4>/a(2)(2)'
   *  Gain: '<S4>/a(3)(2)'
   *  Gain: '<S4>/b(2)(1)'
   *  Gain: '<S4>/s(2)'
   *  Sum: '<S4>/SumA22'
   *  Sum: '<S4>/SumB21'
   *  Sum: '<S4>/SumB31'
   */
  SignalProcessing_DW.Delay12_DSTATE = (((SignalProcessing_P.b21_Gain *
    SignalProcessing_DW.Delay21_DSTATE + SignalProcessing_DW.Delay11_DSTATE) +
    rtb_Delay21) * SignalProcessing_P.s2_Gain - SignalProcessing_P.a22_Gain *
    SignalProcessing_DW.Delay22_DSTATE) - SignalProcessing_P.a32_Gain * HPFPower;

  /* Gain: '<S4>/s(3)' incorporates:
   *  Delay: '<S4>/Delay12'
   *  Delay: '<S4>/Delay22'
   *  Gain: '<S4>/b(2)(2)'
   *  Sum: '<S4>/SumB22'
   *  Sum: '<S4>/SumB32'
   */
  HPFPower = ((SignalProcessing_P.b22_Gain * SignalProcessing_DW.Delay22_DSTATE
               + SignalProcessing_DW.Delay12_DSTATE) + HPFPower) *
    SignalProcessing_P.s3_Gain;

  /* Buffer: '<Root>/Buffer1' */
  nSamps = 24L;
  offsetFromMemBase = SignalProcessing_DW.Buffer1_inBufPtrIdx;
  if (24L - SignalProcessing_DW.Buffer1_inBufPtrIdx <= 1L) {
    for (i = 0L; i < 24L - SignalProcessing_DW.Buffer1_inBufPtrIdx; i++) {
      SignalProcessing_DW.Buffer1_CircBuf[SignalProcessing_DW.Buffer1_inBufPtrIdx
        + i] = HPFPower;
    }

    offsetFromMemBase = 0L;
    nSamps = SignalProcessing_DW.Buffer1_inBufPtrIdx;
  }

  for (i = 0L; i < nSamps - 23L; i++) {
    SignalProcessing_DW.Buffer1_CircBuf[offsetFromMemBase + i] = HPFPower;
  }

  SignalProcessing_DW.Buffer1_inBufPtrIdx++;
  if (SignalProcessing_DW.Buffer1_inBufPtrIdx >= 24L) {
    SignalProcessing_DW.Buffer1_inBufPtrIdx -= 24L;
  }

  /* End of Buffer: '<Root>/Buffer1' */

  /* Delay: '<S3>/Delay11' */
  HPFPower = SignalProcessing_DW.Delay11_DSTATE_f;

  /* Sum: '<S3>/SumA31' incorporates:
   *  Delay: '<S3>/Delay11'
   *  Delay: '<S3>/Delay21'
   *  Gain: '<S3>/a(2)(1)'
   *  Gain: '<S3>/a(3)(1)'
   *  Gain: '<S3>/s(1)'
   *  Inport: '<Root>/Power'
   *  Sum: '<S3>/SumA21'
   */
  SignalProcessing_DW.Delay11_DSTATE_f = (SignalProcessing_P.s1_Gain_o *
    SignalProcessing_U.Power - SignalProcessing_P.a21_Gain_h *
    SignalProcessing_DW.Delay11_DSTATE_f) - SignalProcessing_P.a31_Gain_j *
    SignalProcessing_DW.Delay21_DSTATE_c;

  /* Delay: '<S3>/Delay12' */
  rtb_Delay21 = SignalProcessing_DW.Delay12_DSTATE_c;

  /* Sum: '<S3>/SumA32' incorporates:
   *  Delay: '<S3>/Delay11'
   *  Delay: '<S3>/Delay12'
   *  Delay: '<S3>/Delay21'
   *  Delay: '<S3>/Delay22'
   *  Gain: '<S3>/a(2)(2)'
   *  Gain: '<S3>/a(3)(2)'
   *  Gain: '<S3>/b(2)(1)'
   *  Gain: '<S3>/s(2)'
   *  Sum: '<S3>/SumA22'
   *  Sum: '<S3>/SumB21'
   *  Sum: '<S3>/SumB31'
   */
  SignalProcessing_DW.Delay12_DSTATE_c = (((SignalProcessing_P.b21_Gain_i *
    HPFPower + SignalProcessing_DW.Delay11_DSTATE_f) +
    SignalProcessing_DW.Delay21_DSTATE_c) * SignalProcessing_P.s2_Gain_e -
    SignalProcessing_P.a22_Gain_k * SignalProcessing_DW.Delay12_DSTATE_c) -
    SignalProcessing_P.a32_Gain_b * SignalProcessing_DW.Delay22_DSTATE_o;

  /* Update for Delay: '<Root>/Delay1' incorporates:
   *  Delay: '<S3>/Delay12'
   *  Delay: '<S3>/Delay22'
   *  Gain: '<S3>/b(2)(2)'
   *  Gain: '<S3>/s(3)'
   *  Sum: '<S3>/SumB22'
   *  Sum: '<S3>/SumB32'
   */
  SignalProcessing_DW.Delay1_DSTATE[0] = SignalProcessing_DW.Delay1_DSTATE[1];
  SignalProcessing_DW.Delay1_DSTATE[1] = ((SignalProcessing_P.b22_Gain_a *
    rtb_Delay21 + SignalProcessing_DW.Delay12_DSTATE_c) +
    SignalProcessing_DW.Delay22_DSTATE_o) * SignalProcessing_P.s3_Gain_j;

  /* Update for Delay: '<S3>/Delay21' */
  SignalProcessing_DW.Delay21_DSTATE_c = HPFPower;

  /* Update for Delay: '<S3>/Delay22' */
  SignalProcessing_DW.Delay22_DSTATE_o = rtb_Delay21;
}

/* Model step function for TID1 */
void SignalProcessing_step1(void)      /* Sample time: [0.125s, 0.0s] */
{
  int32_T i;
  int32_T uyIdx;
  int32_T nSampsAtBot;
  int32_T nSamps;
  real_T tmp;
  real_T tmp_0;
  int16_T i_0;

  /* Buffer: '<Root>/Buffer' */
  uyIdx = 0L;
  if (SignalProcessing_DW.Buffer_outBufPtrIdx < 0L) {
    SignalProcessing_DW.Buffer_outBufPtrIdx += 24L;
  }

  nSampsAtBot = 24L - SignalProcessing_DW.Buffer_outBufPtrIdx;
  nSamps = 12L;
  if (24L - SignalProcessing_DW.Buffer_outBufPtrIdx <= 12L) {
    for (i = 0L; i < 24L - SignalProcessing_DW.Buffer_outBufPtrIdx; i++) {
      SignalProcessing_B.Abs[i] =
        SignalProcessing_DW.Buffer_CircBuf[SignalProcessing_DW.Buffer_outBufPtrIdx
        + i];
    }

    uyIdx = 24L - SignalProcessing_DW.Buffer_outBufPtrIdx;
    SignalProcessing_DW.Buffer_outBufPtrIdx = 0L;
    nSamps = 12L - nSampsAtBot;
  }

  for (i = 0L; i < nSamps; i++) {
    SignalProcessing_B.Abs[uyIdx + i] =
      SignalProcessing_DW.Buffer_CircBuf[SignalProcessing_DW.Buffer_outBufPtrIdx
      + i];
  }

  SignalProcessing_DW.Buffer_outBufPtrIdx += nSamps;

  /* End of Buffer: '<Root>/Buffer' */

  /* Abs: '<Root>/Abs' */
  for (i_0 = 0; i_0 < 12; i_0++) {
    SignalProcessing_B.Abs[i_0] = fabs(SignalProcessing_B.Abs[i_0]);
  }

  /* End of Abs: '<Root>/Abs' */

  /* Buffer: '<Root>/Buffer1' */
  uyIdx = 0L;
  if (SignalProcessing_DW.Buffer1_outBufPtrIdx < 0L) {
    SignalProcessing_DW.Buffer1_outBufPtrIdx += 24L;
  }

  nSampsAtBot = 24L - SignalProcessing_DW.Buffer1_outBufPtrIdx;
  nSamps = 12L;
  if (24L - SignalProcessing_DW.Buffer1_outBufPtrIdx <= 12L) {
    for (i = 0L; i < 24L - SignalProcessing_DW.Buffer1_outBufPtrIdx; i++) {
      SignalProcessing_B.Abs1[i] =
        SignalProcessing_DW.Buffer1_CircBuf[SignalProcessing_DW.Buffer1_outBufPtrIdx
        + i];
    }

    uyIdx = 24L - SignalProcessing_DW.Buffer1_outBufPtrIdx;
    SignalProcessing_DW.Buffer1_outBufPtrIdx = 0L;
    nSamps = 12L - nSampsAtBot;
  }

  for (i = 0L; i < nSamps; i++) {
    SignalProcessing_B.Abs1[uyIdx + i] =
      SignalProcessing_DW.Buffer1_CircBuf[SignalProcessing_DW.Buffer1_outBufPtrIdx
      + i];
  }

  SignalProcessing_DW.Buffer1_outBufPtrIdx += nSamps;

  /* End of Buffer: '<Root>/Buffer1' */

  /* Sum: '<Root>/Sum of Elements1' */
  tmp = -0.0;

  /* Sum: '<Root>/Sum of Elements' */
  tmp_0 = -0.0;
  for (i_0 = 0; i_0 < 12; i_0++) {
    /* Sum: '<Root>/Sum of Elements1' incorporates:
     *  Abs: '<Root>/Abs1'
     */
    tmp += fabs(SignalProcessing_B.Abs1[i_0]);

    /* Sum: '<Root>/Sum of Elements' */
    tmp_0 += SignalProcessing_B.Abs[i_0];
  }

  /* Outport: '<Root>/Outport' incorporates:
   *  Constant: '<S1>/Constant'
   *  Constant: '<S2>/Constant'
   *  Gain: '<Root>/Gain'
   *  Logic: '<Root>/AND'
   *  Product: '<Root>/Divide'
   *  RelationalOperator: '<S1>/Compare'
   *  RelationalOperator: '<S2>/Compare'
   *  Sum: '<Root>/Sum of Elements'
   *  Sum: '<Root>/Sum of Elements1'
   */
  SignalProcessing_Y.Outport = (uint8_T)((tmp >=
    SignalProcessing_P.CompareToConstant1_const) && (tmp / tmp_0 >=
    SignalProcessing_P.CompareToConstant_const) ? (int16_T)
    SignalProcessing_P.Gain_Gain : 0);
}

/* Model initialize function */
void SignalProcessing_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)SignalProcessing_M, 0,
                sizeof(RT_MODEL_SignalProcessing_T));

  /* states (dwork) */
  (void) memset((void *)&SignalProcessing_DW, 0,
                sizeof(DW_SignalProcessing_T));

  /* external inputs */
  SignalProcessing_U.Power = 0.0;

  /* external outputs */
  SignalProcessing_Y.Outport = 0U;

  {
    int16_T i;

    /* InitializeConditions for Delay: '<Root>/Delay1' */
    SignalProcessing_DW.Delay1_DSTATE[0] =
      SignalProcessing_P.Delay1_InitialCondition;
    SignalProcessing_DW.Delay1_DSTATE[1] =
      SignalProcessing_P.Delay1_InitialCondition;

    /* InitializeConditions for Buffer: '<Root>/Buffer' */
    SignalProcessing_DW.Buffer_inBufPtrIdx = 12L;
    SignalProcessing_DW.Buffer_outBufPtrIdx = 0L;

    /* InitializeConditions for Delay: '<S4>/Delay22' */
    SignalProcessing_DW.Delay22_DSTATE =
      SignalProcessing_P.Delay22_InitialCondition;

    /* InitializeConditions for Delay: '<S4>/Delay21' */
    SignalProcessing_DW.Delay21_DSTATE =
      SignalProcessing_P.Delay21_InitialCondition;

    /* InitializeConditions for Delay: '<S4>/Delay11' */
    SignalProcessing_DW.Delay11_DSTATE =
      SignalProcessing_P.Delay11_InitialCondition;

    /* InitializeConditions for Delay: '<S4>/Delay12' */
    SignalProcessing_DW.Delay12_DSTATE =
      SignalProcessing_P.Delay12_InitialCondition;
    for (i = 0; i < 24; i++) {
      /* InitializeConditions for Buffer: '<Root>/Buffer' */
      SignalProcessing_DW.Buffer_CircBuf[i] = SignalProcessing_P.Buffer_ic;

      /* InitializeConditions for Buffer: '<Root>/Buffer1' */
      SignalProcessing_DW.Buffer1_CircBuf[i] = SignalProcessing_P.Buffer1_ic;
    }

    /* InitializeConditions for Buffer: '<Root>/Buffer1' */
    SignalProcessing_DW.Buffer1_inBufPtrIdx = 12L;
    SignalProcessing_DW.Buffer1_outBufPtrIdx = 0L;

    /* InitializeConditions for Delay: '<S3>/Delay11' */
    SignalProcessing_DW.Delay11_DSTATE_f =
      SignalProcessing_P.Delay11_InitialCondition_g;

    /* InitializeConditions for Delay: '<S3>/Delay21' */
    SignalProcessing_DW.Delay21_DSTATE_c =
      SignalProcessing_P.Delay21_InitialCondition_c;

    /* InitializeConditions for Delay: '<S3>/Delay12' */
    SignalProcessing_DW.Delay12_DSTATE_c =
      SignalProcessing_P.Delay12_InitialCondition_m;

    /* InitializeConditions for Delay: '<S3>/Delay22' */
    SignalProcessing_DW.Delay22_DSTATE_o =
      SignalProcessing_P.Delay22_InitialCondition_g;
  }
}

/* Model terminate function */
void SignalProcessing_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
