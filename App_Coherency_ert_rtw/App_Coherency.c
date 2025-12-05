/*
 * File: App_Coherency.c
 *
 * Code generated for Simulink model 'App_Coherency'.
 *
 * Model version                  : 1.15
 * Simulink Coder version         : 8.14 (R2018a) 06-Feb-2018
 * C/C++ source code generated on : Fri Dec  5 11:03:48 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#include "App_Coherency.h"

/* External inputs (root inport signals with default storage) */
ExtU rtU;

/* External outputs (root outports fed by signals with default storage) */
ExtY rtY;

/* Model step function */
void App_Coherency_step(void)
{
  /* Outputs for Atomic SubSystem: '<Root>/App_Coherency' */
  /* Outport: '<Root>/App_bSensor1Failure' incorporates:
   *  Constant: '<S1>/Constant'
   *  Constant: '<S1>/Constant1'
   *  Inport: '<Root>/App_vSensor1'
   *  Logic: '<S1>/OR'
   *  RelationalOperator: '<S1>/GreaterThan'
   *  RelationalOperator: '<S1>/Less Than'
   */
  rtY.App_bSensor1Failure = ((rtU.App_vSensor1 > 4.5) || (rtU.App_vSensor1 < 0.5));

  /* Outport: '<Root>/App_bSensor2Failure' incorporates:
   *  Constant: '<S1>/Constant2'
   *  Constant: '<S1>/Constant3'
   *  Inport: '<Root>/App_vSensor2'
   *  Logic: '<S1>/OR1'
   *  RelationalOperator: '<S1>/GreaterThan1'
   *  RelationalOperator: '<S1>/Less Than1'
   */
  rtY.App_bSensor2Failure = ((rtU.App_vSensor1_a > 4.5) || (rtU.App_vSensor1_a <
    0.5));

  /* Outport: '<Root>/App_bCoherencyFailure' incorporates:
   *  Constant: '<S1>/Constant4'
   *  Inport: '<Root>/App_vSensor1'
   *  Inport: '<Root>/App_vSensor2'
   *  RelationalOperator: '<S1>/NotEqual'
   *  Sum: '<S1>/Add'
   */
  rtY.App_bCoherencyFailure = (rtU.App_vSensor1 + rtU.App_vSensor1_a != 5.0);

  /* End of Outputs for SubSystem: '<Root>/App_Coherency' */
}

/* Model initialize function */
void App_Coherency_initialize(void)
{
  /* (no initialization code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
