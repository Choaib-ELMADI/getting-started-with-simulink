# Copyright 1994-2017 The MathWorks, Inc.
#
# File    : rsim_lcc64.tmf   
#
# Abstract:
#       Template makefile for building a PC-based "rapid simulation" executable 
#       from the generated C code for a Simulink model using generated C code 
#       and the
#			LCC compiler Version 2.4
#
# 	This makefile attempts to conform to the guidelines specified in the
# 	IEEE Std 1003.2-1992 (POSIX) standard. It is designed to be used
#       with GNU Make (gmake) which is located in matlabroot/bin/win32.
#
# 	Note that this template is automatically customized by the build 
#       procedure to create "<model>.mk"
#
#       The following defines can be used to modify the behavior of the
#	build:
#	  OPT_OPTS       - Optimization options. Default is none. To enable
#                          debugging specify as OPT_OPTS=-g4.
#	  OPTS           - User specific compile options.
#	  USER_SRCS      - Additional user sources, such as files needed by
#			   S-functions.
#	  USER_INCLUDES  - Additional include paths
#			   (i.e. USER_INCLUDES="-Iwhere-ever -Iwhere-ever2")
#			   (For Lcc, have a '/'as file seperator before the
#			   file name instead of a '\' .
#			   i.e.,  d:\work\proj1/myfile.c - reqd for 'gmake')
#
#       This template makefile is designed to be used with a system target
#       file that contains 'rtwgensettings.BuildDirSuffix' see rsim.tlc

#------------------------ Macros read by make_rtw ------------------------------
#
# The following macros are read by the build procedure:
#
#  MAKECMD         - This is the command used to invoke the make utility
#  HOST            - What platform this template makefile is targeted for
#                    (i.e. PC or UNIX)
#  BUILD           - Invoke make from the build procedure (yes/no)?
#  SYS_TARGET_FILE - Name of system target file.

MAKECMD         = "%MATLAB%\bin\win64\gmake"
SHELL           = cmd
HOST            = PC
BUILD           = yes
SYS_TARGET_FILE = rsim.tlc
BUILD_SUCCESS	= *** Created
COMPILER_TOOL_CHAIN = lcc

# Opt in to simplified format by specifying compatible Toolchain
TOOLCHAIN_NAME = "LCC-win64 v2.4.1 | gmake (64-bit Windows)"

MAKEFILE_FILESEP = /

#---------------------- Tokens expanded by make_rtw ----------------------------
#
# The following tokens, when wrapped with "|>" and "<|" are expanded by the
# build procedure.
#
#  MODEL_NAME          - Name of the Simulink block diagram
#  MODEL_MODULES       - Any additional generated source modules
#  MAKEFILE_NAME       - Name of makefile created from template makefile <model>.mk
#  MATLAB_ROOT         - Path to where MATLAB is installed.
#  MATLAB_BIN          - Path to MATLAB executable.
#  S_FUNCTIONS         - List of S-functions.
#  S_FUNCTIONS_LIB     - List of S-functions libraries to link.
#  BUILDARGS           - Options passed in at the command line.

MODEL               = StateFlow_1
MODULES             = rt_logging.c StateFlow_1.c StateFlow_1_data.c rtGetInf.c rtGetNaN.c rt_nonfinite.c rsim_main.c rsim_sup.c rsim_mat.c simulink_solver_api.c rsim_utils.c common_utils.c
MAKEFILE            = StateFlow_1.mk
MATLAB_ROOT         = C:/Program Files/MATLAB/R2018a
ALT_MATLAB_ROOT     = C:/PROGRA~1/MATLAB/R2018a
MATLAB_BIN          = C:/Program Files/MATLAB/R2018a/bin
ALT_MATLAB_BIN      = C:/PROGRA~1/MATLAB/R2018a/bin
MASTER_ANCHOR_DIR   = 
START_DIR           = C:/Users/CHOAIB~1/DOCUME~1/DIF~1.Y/21E71~1.ELE/989DD~1.GET/MODELB~1
S_FUNCTIONS         = 
S_FUNCTIONS_LIB     = 
BUILDARGS           =  EXTMODE_STATIC_ALLOC=0 EXTMODE_STATIC_ALLOC_SIZE=1000000 EXTMODE_TRANSPORT=0 TMW_EXTMODE_TESTING=0 COMBINE_OUTPUT_UPDATE_FCNS=0 INCLUDE_MDL_TERMINATE_FCN=1 MULTI_INSTANCE_CODE=0 ISPROTECTINGMODEL=NOTPROTECTING

SOLVER              = 
SOLVER_TYPE         = VariableStep
NUMST               = 2
TID01EQ             = 0
NCSTATES            = 0
MULTITASKING        = 0

PCMATLABROOT        = C:\\Program Files\\MATLAB\\R2018a

RSIM_SOLVER_SELECTION  = 1
RSIM_PARAMETER_LOADING = 1

MODELREFS               = 
SHARED_SRC              = 
SHARED_SRC_DIR          = 
SHARED_BIN_DIR          = 
SHARED_LIB              = 
SHARED_LIB_LINK      = $(subst /,\,$(SHARED_LIB)) 

OPTIMIZATION_FLAGS      = 
ADDITIONAL_LDFLAGS      = 
DEFINES_CUSTOM          = 

#--------------------------- Model and reference models -----------------------
MODELLIB                  = StateFlow_1lib.lib
MODELREF_LINK_LIBS        = 
MODELREF_LINK_RSPFILE     = StateFlow_1_ref.rsp
MODELREF_INC_PATH         = 
RELATIVE_PATH_TO_ANCHOR   = ..
# NONE: standalone, SIM: modelref sim, RTW: modelref coder target
MODELREF_TARGET_TYPE       = NONE

GLOBAL_TIMING_ENGINE       = 0

#-- In the case when directory name contains space ---
ifneq ($(MATLAB_ROOT),$(ALT_MATLAB_ROOT))
MATLAB_ROOT := $(ALT_MATLAB_ROOT)
endif
ifneq ($(MATLAB_BIN),$(ALT_MATLAB_BIN))
MATLAB_BIN := $(ALT_MATLAB_BIN)
endif
MATLAB_ARCH_BIN = $(MATLAB_BIN)\win64

#---------------------------- Solver ------------------------------------------
RSIM_WITH_SL_SOLVER = 0

ifeq ($(RSIM_SOLVER_SELECTION),1)
  ifeq ($(SOLVER_TYPE),VariableStep)
    RSIM_WITH_SL_SOLVER = 1
  endif
  ifeq ($(GLOBAL_TIMING_ENGINE),1)
    RSIM_WITH_SL_SOLVER = 1
  endif
endif

ifeq ($(RSIM_SOLVER_SELECTION),2)
  RSIM_WITH_SL_SOLVER = 1
endif

#--------------------------- Tool Specifications -------------------------------

LCC = $(MATLAB_ROOT)\sys\lcc64\lcc64
include $(MATLAB_ROOT)\rtw\c\tools\lcc64tools.mak

CMD_FILE             = $(MODEL).rsp

#------------------------------Parameter Tuning---------------------------------
ifeq ($(RSIM_PARAMETER_LOADING),1)
  PARAM_CC_OPTS = -DRSIM_PARAMETER_LOADING
endif

#------------------------------ Include Path -----------------------------------

ADD_INCLUDES = \
	-I$(START_DIR) \
	-I$(START_DIR)/StateFlow_1_rsim_rtw \


# see MATLAB_INCLUDES and COMPILER_INCLUDES from lcctools.mak
SHARED_INCLUDES =
ifneq ($(SHARED_SRC_DIR),)
SHARED_INCLUDES = -I$(SHARED_SRC_DIR) 
endif

INCLUDES = -I. -I$(RELATIVE_PATH_TO_ANCHOR) $(MATLAB_INCLUDES) $(ADD_INCLUDES) \
           $(COMPILER_INCLUDES) $(USER_INCLUDES) $(MODELREF_INC_PATH) $(SHARED_INCLUDES)

INCLUDES += -I$(MATLAB_ROOT)\rtw\c\rsim -I$(MATLAB_ROOT)\rtw\c\src\rapid

#-------------------------------- C Flags --------------------------------------

# Optimization Options
ifndef OPT_OPTS
OPT_OPTS = $(DEFAULT_OPT_OPTS)
endif

# General User Options
OPTS =

# Compiler options, etc:
ifneq ($(OPTIMIZATION_FLAGS),)
CC_OPTS = $(OPTS) $(ANSI_OPTS)  $(PARAM_CC_OPTS) $(OPTIMIZATION_FLAGS)
else
CC_OPTS = $(OPT_OPTS) $(OPTS) $(ANSI_OPTS)  $(PARAM_CC_OPTS)
endif

CPP_REQ_DEFINES = -DMODEL=$(MODEL) -DHAVESTDIO

ifeq ($(RSIM_WITH_SL_SOLVER),1)
    CPP_REQ_DEFINES += -DNRT -DRSIM_WITH_SL_SOLVER

ifeq ($(MULTITASKING),1)		
    CPP_REQ_DEFINES += -DRSIM_WITH_SOLVER_MULTITASKING \
                       -DTID01EQ=$(TID01EQ) \
                       -DNUMST=$(NUMST) 
endif
else
  CPP_REQ_DEFINES += -DRT -DNUMST=$(NUMST) -DTID01EQ=$(TID01EQ) \
                     -DNCSTATES=$(NCSTATES) -DMT=$(MULTITASKING)
endif

CFLAGS = $(DEFAULT_CFLAGS) $(CC_OPTS) $(DEFINES_CUSTOM) $(CPP_REQ_DEFINES) $(INCLUDES) -noregistrylookup -w
#----------------------------- Source Files ------------------------------------

ifeq ($(MODELREF_TARGET_TYPE), NONE)
    PRODUCT            = $(RELATIVE_PATH_TO_ANCHOR)/$(MODEL).exe
    BIN_SETTING        = $(LD) $(LDFLAGS) $(ADDITIONAL_LDFLAGS) -o $(PRODUCT) $(SYSLIBS)
    BUILD_PRODUCT_TYPE = executable
    REQ_SRCS           = $(MODULES)
ifeq ($(RSIM_WITH_SL_SOLVER),0)
REQ_SRCS += $(SOLVER)
endif
else
    # Model reference coder target
    PRODUCT            = $(MODELLIB)
    REQ_SRCS           = $(MODULES)
endif

USER_SRCS =

USER_OBJS      = $(addsuffix .obj, $(basename $(USER_SRCS)))
LOCAL_USER_OBJS = $(notdir $(USER_OBJS))

SRCS = $(REQ_SRCS) $(S_FUNCTIONS)

OBJS      = $(addsuffix .obj, $(basename $(SRCS))) $(USER_OBJS)
LINK_OBJS = $(addsuffix .obj, $(basename $(SRCS))) $(LOCAL_USER_OBJS)

SHARED_OBJS := $(addsuffix .obj, $(basename $(wildcard $(SHARED_SRC))))
FMT_SHARED_OBJS = $(subst /,\,$(SHARED_OBJS))
#--------------------------- Link flags & libraries ----------------------------

ifeq ($(OPT_OPTS),$(DEFAULT_OPT_OPTS))
LDFLAGS = -s -L$(LIB)
else
LDFLAGS = -L$(LIB)
endif

LIBUT  = $(MATLAB_ROOT)\extern\lib\win64\microsoft\libut.lib
LIBMX  = $(MATLAB_ROOT)\extern\lib\win64\microsoft\libmx.lib
LIBMAT = $(MATLAB_ROOT)\extern\lib\win64\microsoft\libmat.lib
LIBMWMATHUTIL = $(MATLAB_ROOT)\extern\lib\win64\microsoft\libmwmathutil.lib
LIBSL_SOLVER_RTW = $(MATLAB_ROOT)\extern\lib\win64\microsoft\libmwsl_solver_rtw.lib
LIBSL_FILEIO     = $(MATLAB_ROOT)\extern\lib\win64\microsoft\libmwsl_fileio.lib
LIBSIGSTREAM     = $(MATLAB_ROOT)\extern\lib\win64\microsoft\libmwsigstream.lib
LIBSL_SIMTARGET_INSTRUMENTATION     = $(MATLAB_ROOT)\extern\lib\win64\microsoft\libmwsl_simtarget_instrumentation.lib


MAT_LIBS = $(LIBUT) $(LIBMX) $(LIBMAT) $(LIBMWMATHUTIL) $(LIBSL_FILEIO) $(LIBSIGSTREAM) $(LIBSL_SIMTARGET_INSTRUMENTATION)
ifeq ($(RSIM_WITH_SL_SOLVER),1)
MAT_LIBS += $(LIBSL_SOLVER_RTW)
endif

#------------------------- Additional Libraries -------------------------------

LIBS =


LIBMWIPP = $(MATLAB_ROOT)\lib\win64\libmwipp.lib
LIBS +=  $(S_FUNCTIONS_LIB) $(LIBMWIPP)
LIBS += $(MATLAB_ROOT)\sys\lcc64\lcc64\lib64\ws2_32.lib
LIBS += $(MATLAB_ROOT)\sys\lcc64\lcc64\lib64\mswsock.lib 

#--------------------------------- Rules ---------------------------------------

ifeq ($(MODELREF_TARGET_TYPE),NONE)
$(PRODUCT) : $(OBJS) $(SHARED_LIB) $(LIBS) $(MODELREF_LINK_LIBS)
	$(BIN_SETTING) @$(CMD_FILE) @$(MODELREF_LINK_RSPFILE) $(SHARED_LIB_LINK) \
		$(MAT_LIBS) $(LIBS) 
	@cmd /C "echo $(BUILD_SUCCESS) executable: $(MODEL).exe"
else
$(PRODUCT) : $(OBJS) $(SHARED_LIB)
	$(LIBCMD) /out:$@ $(LINK_OBJS)
	@cmd /C "echo $(BUILD_SUCCESS) $(MODELLIB)"
endif

%.obj : %.c
	$(CC) -c -Fo$(@F) $(CFLAGS) $<

%.obj : %.cpp
	$(CC) -c -Fo$(@F) $(CFLAGS) $<

%.obj : %.C
	$(CC) -c -Fo$(@F) $(CFLAGS) $<

%.obj : %.CPP
	$(CC) -c -Fo$(@F) $(CFLAGS) $<

%.obj : $(RELATIVE_PATH_TO_ANCHOR)/%.c
	$(CC) -c -Fo$(@F) -I$(RELATIVE_PATH_TO_ANCHOR)/$(<F:.c=cn_rtw) $(CFLAGS)  $<

%.obj : $(RELATIVE_PATH_TO_ANCHOR)/%.cpp
	$(CC) -c -Fo$(@F) -I$(RELATIVE_PATH_TO_ANCHOR)/$(<F:.c=cn_rtw) $(CFLAGS)  $<

%.obj : $(RELATIVE_PATH_TO_ANCHOR)/%.C
	$(CC) -c -Fo$(@F) -I$(RELATIVE_PATH_TO_ANCHOR)/$(<F:.c=cn_rtw) $(CFLAGS)  $<

%.obj : $(RELATIVE_PATH_TO_ANCHOR)/%.CPP
	$(CC) -c -Fo$(@F) -I$(RELATIVE_PATH_TO_ANCHOR)/$(<F:.c=cn_rtw) $(CFLAGS)  $<

%.obj : $(MATLAB_ROOT)/rtw/c/rsim/%.c
	$(CC) -c -Fo$(@F) $(CFLAGS) $<

%.obj : $(MATLAB_ROOT)/rtw/c/rsim/%.C
	$(CC) -c -Fo$(@F) $(CFLAGS) $<

%.obj : $(MATLAB_ROOT)/rtw/c/src/%.c
	$(CC) -c -Fo$(@F) $(CFLAGS) $<

%.obj : $(MATLAB_ROOT)/rtw/c/src/%.C
	$(CC) -c -Fo$(@F) $(CFLAGS) $<

%.obj : $(MATLAB_ROOT)/rtw/c/src/rapid/%.c
	$(CC) -c -Fo$(@F) $(CFLAGS) $<

%.obj : $(MATLAB_ROOT)/rtw/c/src/rapid/%.C
	$(CC) -c -Fo$(@F) $(CFLAGS) $<

simulink_solver_api.obj : $(MATLAB_ROOT)/simulink/include/simulink_solver_api.c
	$(CC) -c -Fo$(@F) $(CFLAGS) $<

# Additional sources

%.obj : $(MATLAB_ROOT)/rtw/c/src/%.c
	$(CC) -c -Fo$(@F) $(CFLAGS) $<

%.obj : $(MATLAB_ROOT)/simulink/src/%.c
	$(CC) -c -Fo$(@F) $(CFLAGS) $<



%.obj : $(MATLAB_ROOT)/rtw/c/src/%.C
	$(CC) -c -Fo$(@F) $(CFLAGS) $<

%.obj : $(MATLAB_ROOT)/simulink/src/%.C
	$(CC) -c -Fo$(@F) $(CFLAGS) $<



%.obj : $(MATLAB_ROOT)/rtw/c/src/%.cpp
	$(CC) -c -Fo$(@F) $(CFLAGS) $<

%.obj : $(MATLAB_ROOT)/simulink/src/%.cpp
	$(CC) -c -Fo$(@F) $(CFLAGS) $<



%.obj : $(MATLAB_ROOT)/rtw/c/src/%.CPP
	$(CC) -c -Fo$(@F) $(CFLAGS) $<

%.obj : $(MATLAB_ROOT)/simulink/src/%.CPP
	$(CC) -c -Fo$(@F) $(CFLAGS) $<



lccstub.obj : $(LCC)/mex/lccstub.c
	$(CC) $(CFLAGS) $(INCLUDES) $(LCC)/mex/lccstub.c -o ./lccstub.obj

%.obj : $(MATLAB_ROOT)/simulink/src/%.c
	$(CC) -c -Fo$(@F) $(CFLAGS) $<

%.obj : $(MATLAB_ROOT)/simulink/src/%.C
	$(CC) -c -Fo$(@F) $(CFLAGS) $<

# Libraries:





#----------------------------- Dependencies ------------------------------------

$(OBJS) : $(MAKEFILE) rtw_proj.tmw

$(SHARED_OBJS) : $(SHARED_BIN_DIR)/%.obj : $(SHARED_SRC_DIR)/%.c 
	$(CC) -c -Fo$@ $(CFLAGS) $<

$(SHARED_LIB) : $(SHARED_OBJS)
	@cmd /C "echo ### Creating $@" 
	$(LIBCMD) /out:$@ $(FMT_SHARED_OBJS)
	@cmd /C "echo ### $@ Created"
