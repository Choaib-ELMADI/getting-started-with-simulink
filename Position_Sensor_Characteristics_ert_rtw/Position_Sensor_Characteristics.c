/*
 * File: Position_Sensor_Characteristics.c
 *
 * Code generated for Simulink model 'Position_Sensor_Characteristics'.
 *
 * Model version                  : 1.7
 * Simulink Coder version         : 8.14 (R2018a) 06-Feb-2018
 * C/C++ source code generated on : Fri Dec  5 09:45:06 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#include "Position_Sensor_Characteristics.h"

/* External inputs (root inport signals with default storage) */
ExtU rtU;

/* External outputs (root outports fed by signals with default storage) */
ExtY rtY;

/* Real-time model */
RT_MODEL rtM_;
RT_MODEL *const rtM = &rtM_;
static void App_Coherency(void);

/* Output and update for atomic system: '<Root>/App_Coherency' */
static void App_Coherency(void)
{
  /* Outport: '<Root>/App_bCoherencyFailure' incorporates:
   *  Constant: '<S1>/Constant4'
   *  Inport: '<Root>/App_vSensor1'
   *  RelationalOperator: '<S1>/NotEqual'
   *  Sum: '<S1>/Add'
   */
  rtY.App_bCoherencyFailure = (rtU.App_vSensor1 + rtU.App_vSensor1 != 5.0);

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
   *  Inport: '<Root>/App_vSensor1'
   *  Logic: '<S1>/OR1'
   *  RelationalOperator: '<S1>/GreaterThan1'
   *  RelationalOperator: '<S1>/Less Than1'
   */
  rtY.App_bSensor2Failure = ((rtU.App_vSensor1 > 4.5) || (rtU.App_vSensor1 < 0.5));
}

/* Model step function */
void Position_Sensor_Characteristics_step(void)
{
  /* Outputs for Atomic SubSystem: '<Root>/App_Coherency' */
  App_Coherency();

  /* End of Outputs for SubSystem: '<Root>/App_Coherency' */
}

/* Model initialize function */
void Position_Sensor_Characteristics_initialize(void)
{
  /* (no initialization code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
