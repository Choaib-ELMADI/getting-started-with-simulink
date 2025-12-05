/*
 * File: Position_Sensor_Characteristics.h
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

#ifndef RTW_HEADER_Position_Sensor_Characteristics_h_
#define RTW_HEADER_Position_Sensor_Characteristics_h_
#ifndef Position_Sensor_Characteristics_COMMON_INCLUDES_
# define Position_Sensor_Characteristics_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#endif                                 /* Position_Sensor_Characteristics_COMMON_INCLUDES_ */

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Forward declaration for rtModel */
typedef struct tag_RTM RT_MODEL;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T App_vSensor1;                 /* '<Root>/App_vSensor1' */
} ExtU;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  boolean_T App_bSensor1Failure;       /* '<Root>/App_bSensor1Failure' */
  boolean_T App_bSensor2Failure;       /* '<Root>/App_bSensor2Failure' */
  boolean_T App_bCoherencyFailure;     /* '<Root>/App_bCoherencyFailure' */
} ExtY;

/* Real-time Model Data Structure */
struct tag_RTM {
  const char_T * volatile errorStatus;
};

/* External inputs (root inport signals with default storage) */
extern ExtU rtU;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY rtY;

/* Model entry point functions */
extern void Position_Sensor_Characteristics_initialize(void);
extern void Position_Sensor_Characteristics_step(void);

/* Real-time Model object */
extern RT_MODEL *const rtM;

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
 * '<Root>' : 'Position_Sensor_Characteristics'
 * '<S1>'   : 'Position_Sensor_Characteristics/App_Coherency'
 */
#endif                                 /* RTW_HEADER_Position_Sensor_Characteristics_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
