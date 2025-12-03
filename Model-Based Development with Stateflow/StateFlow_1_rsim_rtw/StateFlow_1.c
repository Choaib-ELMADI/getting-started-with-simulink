/*
 * StateFlow_1.c
 *
 * Code generation for model "StateFlow_1".
 *
 * Model version              : 1.14
 * Simulink Coder version : 8.14 (R2018a) 06-Feb-2018
 * C source code generated on : Fri Feb 14 17:38:09 2025
 *
 * Target selection: rsim.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include <math.h>
#include "StateFlow_1.h"
#include "StateFlow_1_private.h"
#include "StateFlow_1_dt.h"

/* user code (top of parameter file) */
const int_T gblNumToFiles = 0;
const int_T gblNumFrFiles = 0;
const int_T gblNumFrWksBlocks = 0;
const char *gblSlvrJacPatternFileName =
  "StateFlow_1_rsim_rtw\\StateFlow_1_Jpattern.mat";

/* Root inports information  */
const int_T gblNumRootInportBlks = 0;
const int_T gblNumModelInputs = 0;
extern rtInportTUtable *gblInportTUtables;
extern const char *gblInportFileName;
const int_T gblInportDataTypeIdx[] = { -1 };

const int_T gblInportDims[] = { -1 } ;

const int_T gblInportComplex[] = { -1 };

const int_T gblInportInterpoFlag[] = { -1 };

const int_T gblInportContinuous[] = { -1 };

#include "simstruc.h"
#include "fixedpoint.h"

/* Named constants for Chart: '<Root>/Chart' */
#define StateFlow_1_IN_NO_ACTIVE_CHILD ((uint8_T)0U)
#define StateFlow_1_IN_OFF_STATE       ((uint8_T)1U)
#define StateFlow_1_IN_ON_STATE        ((uint8_T)2U)

/* Block signals (default storage) */
B rtB;

/* Block states (default storage) */
DW rtDW;

/* Parent Simstruct */
static SimStruct model_S;
SimStruct *const rtS = &model_S;

/* System initialize for root system: '<Root>' */
void MdlInitialize(void)
{
  /* SystemInitialize for Chart: '<Root>/Chart' */
  rtDW.is_active_c3_StateFlow_1 = 0U;
  rtDW.is_c3_StateFlow_1 = StateFlow_1_IN_NO_ACTIVE_CHILD;
}

/* Enable for root system: '<Root>' */
void MdlEnable(void)
{
  /* Enable for DiscretePulseGenerator: '<Root>/Pulse Generator' */
  rtDW.justEnabled = 1;

  /* Force a sample hit at this major time step */
  _ssSetSampleHit(rtS, 1, 1);
  _ssSetTaskTime(rtS, 1, ssGetT(rtS));
  _ssSetVarNextHitTime(rtS, 0, ssGetT(rtS));
  ;
}

/* Start for root system: '<Root>' */
void MdlStart(void)
{
  MdlInitialize();
  MdlEnable();
}

/* Outputs for root system: '<Root>' */
void MdlOutputs(int_T tid)
{
  real_T taskTimeV;
  real_T ratio;
  uint32_T numCycles;
  if (ssIsSampleHit(rtS, 1, 0)) {
    /* DiscretePulseGenerator: '<Root>/Pulse Generator' */
    taskTimeV = ssGetTaskTime(rtS,1);
    if (ssGetTNextWasAdjusted(rtS, 1)) {
      rtDW.nextTime = _ssGetVarNextHitTime(rtS, 0);
    }

    if (rtDW.justEnabled != 0) {
      rtDW.justEnabled = 0;
      if (taskTimeV >= rtP.PulseGenerator_PhaseDelay) {
        ratio = (taskTimeV - rtP.PulseGenerator_PhaseDelay) /
          rtP.PulseGenerator_Period;
        numCycles = (uint32_T)floor(ratio);
        if (fabs((real_T)(numCycles + 1U) - ratio) < DBL_EPSILON * ratio) {
          numCycles++;
        }

        rtDW.numCompleteCycles = numCycles;
        ratio = ((real_T)numCycles * rtP.PulseGenerator_Period +
                 rtP.PulseGenerator_PhaseDelay) + rtP.PulseGenerator_Duty *
          rtP.PulseGenerator_Period / 100.0;
        if (taskTimeV < ratio) {
          rtDW.currentValue = 1;
          rtDW.nextTime = ratio;
        } else {
          rtDW.currentValue = 0;
          rtDW.nextTime = (real_T)(numCycles + 1U) * rtP.PulseGenerator_Period +
            rtP.PulseGenerator_PhaseDelay;
        }
      } else {
        rtDW.numCompleteCycles = rtP.PulseGenerator_PhaseDelay != 0.0 ? -1 : 0;
        rtDW.currentValue = 0;
        rtDW.nextTime = rtP.PulseGenerator_PhaseDelay;
      }
    } else {
      if (rtDW.nextTime <= taskTimeV) {
        if (rtDW.currentValue == 1) {
          rtDW.currentValue = 0;
          rtDW.nextTime = (real_T)(rtDW.numCompleteCycles + 1LL) *
            rtP.PulseGenerator_Period + rtP.PulseGenerator_PhaseDelay;
        } else {
          rtDW.numCompleteCycles++;
          rtDW.currentValue = 1;
          rtDW.nextTime = (rtP.PulseGenerator_Duty * rtP.PulseGenerator_Period *
                           0.01 + (real_T)rtDW.numCompleteCycles *
                           rtP.PulseGenerator_Period) +
            rtP.PulseGenerator_PhaseDelay;
        }
      }
    }

    _ssSetVarNextHitTime(rtS, 0, rtDW.nextTime);
    if (rtDW.currentValue == 1) {
      rtB.PulseGenerator = rtP.PulseGenerator_Amp;
    } else {
      rtB.PulseGenerator = 0.0;
    }

    /* End of DiscretePulseGenerator: '<Root>/Pulse Generator' */
  }

  if (ssIsSampleHit(rtS, 0, 0)) {
    /* Chart: '<Root>/Chart' incorporates:
     *  DataTypeConversion: '<Root>/Data Type Conversion'
     */
    if (rtDW.is_active_c3_StateFlow_1 == 0U) {
      rtDW.is_active_c3_StateFlow_1 = 1U;
      rtDW.is_c3_StateFlow_1 = StateFlow_1_IN_ON_STATE;
    } else if (rtDW.is_c3_StateFlow_1 == StateFlow_1_IN_OFF_STATE) {
      /* DataTypeConversion: '<Root>/Data Type Conversion' */
      taskTimeV = floor(rtB.PulseGenerator);
      if (rtIsNaN(taskTimeV) || rtIsInf(taskTimeV)) {
        taskTimeV = 0.0;
      } else {
        taskTimeV = fmod(taskTimeV, 256.0);
      }

      if ((taskTimeV < 0.0 ? (int32_T)(int8_T)-(int8_T)(uint8_T)-taskTimeV :
           (int32_T)(int8_T)(uint8_T)taskTimeV) == 1) {
        rtDW.is_c3_StateFlow_1 = StateFlow_1_IN_ON_STATE;
      }
    } else {
      /* DataTypeConversion: '<Root>/Data Type Conversion' */
      taskTimeV = floor(rtB.PulseGenerator);
      if (rtIsNaN(taskTimeV) || rtIsInf(taskTimeV)) {
        taskTimeV = 0.0;
      } else {
        taskTimeV = fmod(taskTimeV, 256.0);
      }

      if ((taskTimeV < 0.0 ? (int32_T)(int8_T)-(int8_T)(uint8_T)-taskTimeV :
           (int32_T)(int8_T)(uint8_T)taskTimeV) == 0) {
        rtDW.is_c3_StateFlow_1 = StateFlow_1_IN_OFF_STATE;
      }
    }

    /* End of Chart: '<Root>/Chart' */
  }

  UNUSED_PARAMETER(tid);
}

/* Update for root system: '<Root>' */
void MdlUpdate(int_T tid)
{
  UNUSED_PARAMETER(tid);
}

/* Termination for root system: '<Root>' */
void MdlTerminate(void)
{
}

/* Function to initialize sizes */
void MdlInitializeSizes(void)
{
  ssSetNumContStates(rtS, 0);          /* Number of continuous states */
  ssSetNumY(rtS, 0);                   /* Number of model outputs */
  ssSetNumU(rtS, 0);                   /* Number of model inputs */
  ssSetDirectFeedThrough(rtS, 0);      /* The model is not direct feedthrough */
  ssSetNumSampleTimes(rtS, 2);         /* Number of sample times */
  ssSetNumBlocks(rtS, 4);              /* Number of blocks */
  ssSetNumBlockIO(rtS, 1);             /* Number of block outputs */
  ssSetNumBlockParams(rtS, 4);         /* Sum of parameter "widths" */
}

/* Function to initialize sample times. */
void MdlInitializeSampleTimes(void)
{
  /* task periods */
  ssSetSampleTime(rtS, 0, 0.0);
  ssSetSampleTime(rtS, 1, -2.0);

  /* task offsets */
  ssSetOffsetTime(rtS, 0, 1.0);
  ssSetOffsetTime(rtS, 1, 0.0);
}

/* Function to register the model */
/* Turns off all optimizations on Windows because of issues with VC 2015 compiler.
   This function is not performance-critical, hence this is not a problem.
 */
#if defined(_MSC_VER)

#pragma optimize( "", off )

#endif

SimStruct * StateFlow_1(void)
{
  static struct _ssMdlInfo mdlInfo;
  (void) memset((char *)rtS, 0,
                sizeof(SimStruct));
  (void) memset((char *)&mdlInfo, 0,
                sizeof(struct _ssMdlInfo));
  ssSetMdlInfoPtr(rtS, &mdlInfo);

  /* timing info */
  {
    static time_T mdlPeriod[NSAMPLE_TIMES];
    static time_T mdlOffset[NSAMPLE_TIMES];
    static time_T mdlTaskTimes[NSAMPLE_TIMES];
    static int_T mdlTsMap[NSAMPLE_TIMES];
    static int_T mdlSampleHits[NSAMPLE_TIMES];
    static boolean_T mdlTNextWasAdjustedPtr[NSAMPLE_TIMES];
    static int_T mdlPerTaskSampleHits[NSAMPLE_TIMES * NSAMPLE_TIMES];
    static time_T mdlTimeOfNextSampleHit[NSAMPLE_TIMES];

    {
      int_T i;
      for (i = 0; i < NSAMPLE_TIMES; i++) {
        mdlPeriod[i] = 0.0;
        mdlOffset[i] = 0.0;
        mdlTaskTimes[i] = 0.0;
        mdlTsMap[i] = i;
        mdlSampleHits[i] = 1;
      }
    }

    ssSetSampleTimePtr(rtS, &mdlPeriod[0]);
    ssSetOffsetTimePtr(rtS, &mdlOffset[0]);
    ssSetSampleTimeTaskIDPtr(rtS, &mdlTsMap[0]);
    ssSetTPtr(rtS, &mdlTaskTimes[0]);
    ssSetSampleHitPtr(rtS, &mdlSampleHits[0]);
    ssSetTNextWasAdjustedPtr(rtS, &mdlTNextWasAdjustedPtr[0]);
    ssSetPerTaskSampleHitsPtr(rtS, &mdlPerTaskSampleHits[0]);
    ssSetTimeOfNextSampleHitPtr(rtS, &mdlTimeOfNextSampleHit[0]);
  }

  ssSetSolverMode(rtS, SOLVER_MODE_SINGLETASKING);

  /*
   * initialize model vectors and cache them in SimStruct
   */

  /* block I/O */
  {
    ssSetBlockIO(rtS, ((void *) &rtB));
    (void) memset(((void *) &rtB), 0,
                  sizeof(B));
  }

  /* parameters */
  ssSetDefaultParam(rtS, (real_T *) &rtP);

  /* states (dwork) */
  {
    void *dwork = (void *) &rtDW;
    ssSetRootDWork(rtS, dwork);
    (void) memset(dwork, 0,
                  sizeof(DW));
  }

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    ssSetModelMappingInfo(rtS, &dtInfo);
    dtInfo.numDataTypes = 17;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Model specific registration */
  ssSetRootSS(rtS, rtS);
  ssSetVersion(rtS, SIMSTRUCT_VERSION_LEVEL2);
  ssSetModelName(rtS, "StateFlow_1");
  ssSetPath(rtS, "StateFlow_1");
  ssSetTStart(rtS, 0.0);
  ssSetTFinal(rtS, 10.0);

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = NULL;
    ssSetRTWLogInfo(rtS, &rt_DataLoggingInfo);
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(ssGetRTWLogInfo(rtS), (NULL));
    rtliSetLogXSignalPtrs(ssGetRTWLogInfo(rtS), (NULL));
    rtliSetLogT(ssGetRTWLogInfo(rtS), "tout");
    rtliSetLogX(ssGetRTWLogInfo(rtS), "");
    rtliSetLogXFinal(ssGetRTWLogInfo(rtS), "");
    rtliSetLogVarNameModifier(ssGetRTWLogInfo(rtS), "rt_");
    rtliSetLogFormat(ssGetRTWLogInfo(rtS), 4);
    rtliSetLogMaxRows(ssGetRTWLogInfo(rtS), 0);
    rtliSetLogDecimation(ssGetRTWLogInfo(rtS), 1);
    rtliSetLogY(ssGetRTWLogInfo(rtS), "");
    rtliSetLogYSignalInfo(ssGetRTWLogInfo(rtS), (NULL));
    rtliSetLogYSignalPtrs(ssGetRTWLogInfo(rtS), (NULL));
  }

  {
    static ssSolverInfo slvrInfo;
    ssSetStepSize(rtS, 0.01);
    ssSetMinStepSize(rtS, 0.0);
    ssSetMaxNumMinSteps(rtS, -1);
    ssSetMinStepViolatedError(rtS, 0);
    ssSetMaxStepSize(rtS, 0.01);
    ssSetSolverMaxOrder(rtS, -1);
    ssSetSolverRefineFactor(rtS, 1);
    ssSetOutputTimes(rtS, (NULL));
    ssSetNumOutputTimes(rtS, 0);
    ssSetOutputTimesOnly(rtS, 0);
    ssSetOutputTimesIndex(rtS, 0);
    ssSetZCCacheNeedsReset(rtS, 0);
    ssSetDerivCacheNeedsReset(rtS, 0);
    ssSetNumNonContDerivSigInfos(rtS, 0);
    ssSetNonContDerivSigInfos(rtS, (NULL));
    ssSetSolverInfo(rtS, &slvrInfo);
    ssSetSolverName(rtS, "VariableStepDiscrete");
    ssSetVariableStepSolver(rtS, 1);
    ssSetSolverConsistencyChecking(rtS, 0);
    ssSetSolverAdaptiveZcDetection(rtS, 0);
    ssSetSolverRobustResetMethod(rtS, 0);
    ssSetSolverStateProjection(rtS, 0);
    ssSetSolverMassMatrixType(rtS, (ssMatrixType)0);
    ssSetSolverMassMatrixNzMax(rtS, 0);
    ssSetModelOutputs(rtS, MdlOutputs);
    ssSetModelLogData(rtS, rt_UpdateTXYLogVars);
    ssSetModelLogDataIfInInterval(rtS, rt_UpdateTXXFYLogVars);
    ssSetModelUpdate(rtS, MdlUpdate);
    ssSetTNextTid(rtS, INT_MIN);
    ssSetTNext(rtS, rtMinusInf);
    ssSetSolverNeedsReset(rtS);
    ssSetNumNonsampledZCs(rtS, 0);
  }

  ssSetChecksumVal(rtS, 0, 1611812398U);
  ssSetChecksumVal(rtS, 1, 2509785642U);
  ssSetChecksumVal(rtS, 2, 332548632U);
  ssSetChecksumVal(rtS, 3, 260144195U);
  return rtS;
}

/* When you use the on parameter, it resets the optimizations to those that you
   specified with the /O compiler option. */
#if defined(_MSC_VER)

#pragma optimize( "", on )

#endif
