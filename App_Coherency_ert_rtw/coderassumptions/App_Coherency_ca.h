/*
 * File: App_Coherency_ca.h
 *
 * Abstract: Tests assumptions in the generated code.
 */

#ifndef APP_COHERENCY_CA_H
#define APP_COHERENCY_CA_H

/* preprocessor validation checks */
#include "App_Coherency_ca_preproc.h"
#include "coder_assumptions_hwimpl.h"

/* variables holding test results */
extern CA_HWImpl_TestResults CA_App_Coherency_HWRes;
extern CA_PWS_TestResults CA_App_Coherency_PWSRes;

/* variables holding "expected" and "actual" hardware implementation */
extern const CA_HWImpl CA_App_Coherency_ExpHW;
extern CA_HWImpl CA_App_Coherency_ActHW;

/* entry point function to run tests */
void App_Coherency_caRunTests(void);

#endif                                 /* APP_COHERENCY_CA_H */
