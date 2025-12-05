/*
 * File: coder_assumptions.h
 *
 * Abstract: Coder assumptions header file
 */

#ifndef CODER_ASSUMPTIONS_H
#define CODER_ASSUMPTIONS_H

/* include model specific checks */
#include "App_Coherency_ca.h"

/* global results variable mapping for static code */
#define CA_Expected_HWImpl             CA_App_Coherency_ExpHW
#define CA_Actual_HWImpl               CA_App_Coherency_ActHW
#define CA_HWImpl_Results              CA_App_Coherency_HWRes
#define CA_PortableWordSizes_Results   CA_App_Coherency_PWSRes

/* entry point function mapping for static code */
#define CA_Run_Tests                   App_Coherency_caRunTests
#endif                                 /* CODER_ASSUMPTIONS_H */
