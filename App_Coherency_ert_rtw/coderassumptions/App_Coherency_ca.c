/*
 * File: App_Coherency_ca.c
 *
 * Abstract: Tests assumptions in the generated code.
 */

#include "App_Coherency_ca.h"

CA_HWImpl_TestResults CA_App_Coherency_HWRes;
CA_PWS_TestResults CA_App_Coherency_PWSRes;
const CA_HWImpl CA_App_Coherency_ExpHW = {
  8,                                   /* BitPerChar */
  16,                                  /* BitPerShort */
  32,                                  /* BitPerInt */
  32,                                  /* BitPerLong */
  64,                                  /* BitPerLongLong */
  32,                                  /* BitPerFloat */
  64,                                  /* BitPerDouble */
  32,                                  /* BitPerPointer */
  32,                                  /* BitPerSizeT */
  32,                                  /* BitPerPtrDiffT */
  CA_LITTLE_ENDIAN,                    /* Endianess */
  CA_ZERO,                             /* IntDivRoundTo */
  1,                                   /* ShiftRightIntArith */
  1,                                   /* LongLongMode */
  0,                                   /* PortableWordSizes */
  "ARM Compatible->ARM Cortex",        /* HWDeviceType */
  0                                    /* MemoryAtStartup */
};

CA_HWImpl CA_App_Coherency_ActHW;
void App_Coherency_caRunTests(void)
{
  /* verify hardware implementation */
  caVerifyPortableWordSizes(&CA_App_Coherency_ActHW, &CA_App_Coherency_ExpHW,
    &CA_App_Coherency_PWSRes);
  caVerifyHWImpl(&CA_App_Coherency_ActHW, &CA_App_Coherency_ExpHW,
                 &CA_App_Coherency_HWRes);
}
