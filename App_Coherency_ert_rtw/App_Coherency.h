/*
 * File: App_Coherency.h
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

#ifndef RTW_HEADER_App_Coherency_h_
#define RTW_HEADER_App_Coherency_h_
#ifndef App_Coherency_COMMON_INCLUDES_
# define App_Coherency_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* App_Coherency_COMMON_INCLUDES_ */

/* Macros for accessing real-time model data structure */

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T App_vSensor1;                 /* '<Root>/App_vSensor1' */
  real_T App_vSensor1_a;               /* '<Root>/App_vSensor2' */
} ExtU;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  boolean_T App_bSensor1Failure;       /* '<Root>/App_bSensor1Failure' */
  boolean_T App_bSensor2Failure;       /* '<Root>/App_bSensor2Failure' */
  boolean_T App_bCoherencyFailure;     /* '<Root>/App_bCoherencyFailure' */
} ExtY;

/* External inputs (root inport signals with default storage) */
extern ExtU rtU;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY rtY;

/* Model entry point functions */
extern void App_Coherency_initialize(void);
extern void App_Coherency_step(void);

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Note that this particular code originates from a subsystem build,
 * and has its own system numbers different from the parent model.
 * Refer to the system hierarchy for this subsystem below, and use the
 * MATLAB hilite_system command to trace the generated code back
 * to the parent model.  For example,
 *
 * hilite_system('Position_Sensor_Characteristics/App_Coherency')    - opens subsystem Position_Sensor_Characteristics/App_Coherency
 * hilite_system('Position_Sensor_Characteristics/App_Coherency/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'Position_Sensor_Characteristics'
 * '<S1>'   : 'Position_Sensor_Characteristics/App_Coherency'
 */
#endif                                 /* RTW_HEADER_App_Coherency_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
