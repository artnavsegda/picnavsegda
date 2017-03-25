#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-PIC18F46K20.mk)" "nbproject/Makefile-local-PIC18F46K20.mk"
include nbproject/Makefile-local-PIC18F46K20.mk
endif
endif

# Environment
MKDIR=mkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=PIC18F46K20
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=cof
DEBUGGABLE_SUFFIX=cof
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/MPLAB.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=cof
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/MPLAB.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=
else
COMPARISON_BUILD=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=../PIC18F/Demonstration.c "../../Microchip/PIC18 salloc/salloc.c" "../../Microchip/MDD File System/FSIO.c" "../../Microchip/MDD File System/SD-SPI.c"

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/_ext/1850835836/Demonstration.o ${OBJECTDIR}/_ext/782774512/salloc.o ${OBJECTDIR}/_ext/65885567/FSIO.o ${OBJECTDIR}/_ext/65885567/SD-SPI.o
POSSIBLE_DEPFILES=${OBJECTDIR}/_ext/1850835836/Demonstration.o.d ${OBJECTDIR}/_ext/782774512/salloc.o.d ${OBJECTDIR}/_ext/65885567/FSIO.o.d ${OBJECTDIR}/_ext/65885567/SD-SPI.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/_ext/1850835836/Demonstration.o ${OBJECTDIR}/_ext/782774512/salloc.o ${OBJECTDIR}/_ext/65885567/FSIO.o ${OBJECTDIR}/_ext/65885567/SD-SPI.o

# Source Files
SOURCEFILES=../PIC18F/Demonstration.c ../../Microchip/PIC18 salloc/salloc.c ../../Microchip/MDD File System/FSIO.c ../../Microchip/MDD File System/SD-SPI.c


CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-PIC18F46K20.mk dist/${CND_CONF}/${IMAGE_TYPE}/MPLAB.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=18F46K20
MP_PROCESSOR_OPTION_LD=18f46k20
MP_LINKER_DEBUG_OPTION=-r=ROM@0xFD30:0xFFFF -r=RAM@GPR:0xEF4:0xEFF -u_DEBUGSTACK
# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/_ext/1850835836/Demonstration.o: ../PIC18F/Demonstration.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1850835836" 
	@${RM} ${OBJECTDIR}/_ext/1850835836/Demonstration.o.d 
	@${RM} ${OBJECTDIR}/_ext/1850835836/Demonstration.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -p$(MP_PROCESSOR_OPTION) -I"." -I"./PIC18F" -I"../../MDD File System-SD Card/PIC18F" -I"../../MDD File System-SD Card" -I"../../Microchip/Include/MDD File System" -I"../../Microchip/Include" -I"../../Microchip/Include/PIC18 salloc" -ml -oa- -Ls -o-  -I ${MP_CC_DIR}/../h  -fo ${OBJECTDIR}/_ext/1850835836/Demonstration.o   ../PIC18F/Demonstration.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1850835836/Demonstration.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1850835836/Demonstration.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/782774512/salloc.o: ../../Microchip/PIC18\ salloc/salloc.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/782774512" 
	@${RM} ${OBJECTDIR}/_ext/782774512/salloc.o.d 
	@${RM} ${OBJECTDIR}/_ext/782774512/salloc.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -p$(MP_PROCESSOR_OPTION) -I"." -I"./PIC18F" -I"../../MDD File System-SD Card/PIC18F" -I"../../MDD File System-SD Card" -I"../../Microchip/Include/MDD File System" -I"../../Microchip/Include" -I"../../Microchip/Include/PIC18 salloc" -ml -oa- -Ls -o-  -I ${MP_CC_DIR}/../h  -fo ${OBJECTDIR}/_ext/782774512/salloc.o   "../../Microchip/PIC18 salloc/salloc.c" 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/782774512/salloc.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/782774512/salloc.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/65885567/FSIO.o: ../../Microchip/MDD\ File\ System/FSIO.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/65885567" 
	@${RM} ${OBJECTDIR}/_ext/65885567/FSIO.o.d 
	@${RM} ${OBJECTDIR}/_ext/65885567/FSIO.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -p$(MP_PROCESSOR_OPTION) -I"." -I"./PIC18F" -I"../../MDD File System-SD Card/PIC18F" -I"../../MDD File System-SD Card" -I"../../Microchip/Include/MDD File System" -I"../../Microchip/Include" -I"../../Microchip/Include/PIC18 salloc" -ml -oa- -Ls -o-  -I ${MP_CC_DIR}/../h  -fo ${OBJECTDIR}/_ext/65885567/FSIO.o   "../../Microchip/MDD File System/FSIO.c" 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/65885567/FSIO.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/65885567/FSIO.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/65885567/SD-SPI.o: ../../Microchip/MDD\ File\ System/SD-SPI.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/65885567" 
	@${RM} ${OBJECTDIR}/_ext/65885567/SD-SPI.o.d 
	@${RM} ${OBJECTDIR}/_ext/65885567/SD-SPI.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -p$(MP_PROCESSOR_OPTION) -I"." -I"./PIC18F" -I"../../MDD File System-SD Card/PIC18F" -I"../../MDD File System-SD Card" -I"../../Microchip/Include/MDD File System" -I"../../Microchip/Include" -I"../../Microchip/Include/PIC18 salloc" -ml -oa- -Ls -o-  -I ${MP_CC_DIR}/../h  -fo ${OBJECTDIR}/_ext/65885567/SD-SPI.o   "../../Microchip/MDD File System/SD-SPI.c" 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/65885567/SD-SPI.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/65885567/SD-SPI.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
else
${OBJECTDIR}/_ext/1850835836/Demonstration.o: ../PIC18F/Demonstration.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1850835836" 
	@${RM} ${OBJECTDIR}/_ext/1850835836/Demonstration.o.d 
	@${RM} ${OBJECTDIR}/_ext/1850835836/Demonstration.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -I"." -I"./PIC18F" -I"../../MDD File System-SD Card/PIC18F" -I"../../MDD File System-SD Card" -I"../../Microchip/Include/MDD File System" -I"../../Microchip/Include" -I"../../Microchip/Include/PIC18 salloc" -ml -oa- -Ls -o-  -I ${MP_CC_DIR}/../h  -fo ${OBJECTDIR}/_ext/1850835836/Demonstration.o   ../PIC18F/Demonstration.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1850835836/Demonstration.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1850835836/Demonstration.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/782774512/salloc.o: ../../Microchip/PIC18\ salloc/salloc.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/782774512" 
	@${RM} ${OBJECTDIR}/_ext/782774512/salloc.o.d 
	@${RM} ${OBJECTDIR}/_ext/782774512/salloc.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -I"." -I"./PIC18F" -I"../../MDD File System-SD Card/PIC18F" -I"../../MDD File System-SD Card" -I"../../Microchip/Include/MDD File System" -I"../../Microchip/Include" -I"../../Microchip/Include/PIC18 salloc" -ml -oa- -Ls -o-  -I ${MP_CC_DIR}/../h  -fo ${OBJECTDIR}/_ext/782774512/salloc.o   "../../Microchip/PIC18 salloc/salloc.c" 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/782774512/salloc.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/782774512/salloc.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/65885567/FSIO.o: ../../Microchip/MDD\ File\ System/FSIO.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/65885567" 
	@${RM} ${OBJECTDIR}/_ext/65885567/FSIO.o.d 
	@${RM} ${OBJECTDIR}/_ext/65885567/FSIO.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -I"." -I"./PIC18F" -I"../../MDD File System-SD Card/PIC18F" -I"../../MDD File System-SD Card" -I"../../Microchip/Include/MDD File System" -I"../../Microchip/Include" -I"../../Microchip/Include/PIC18 salloc" -ml -oa- -Ls -o-  -I ${MP_CC_DIR}/../h  -fo ${OBJECTDIR}/_ext/65885567/FSIO.o   "../../Microchip/MDD File System/FSIO.c" 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/65885567/FSIO.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/65885567/FSIO.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/65885567/SD-SPI.o: ../../Microchip/MDD\ File\ System/SD-SPI.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/65885567" 
	@${RM} ${OBJECTDIR}/_ext/65885567/SD-SPI.o.d 
	@${RM} ${OBJECTDIR}/_ext/65885567/SD-SPI.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -I"." -I"./PIC18F" -I"../../MDD File System-SD Card/PIC18F" -I"../../MDD File System-SD Card" -I"../../Microchip/Include/MDD File System" -I"../../Microchip/Include" -I"../../Microchip/Include/PIC18 salloc" -ml -oa- -Ls -o-  -I ${MP_CC_DIR}/../h  -fo ${OBJECTDIR}/_ext/65885567/SD-SPI.o   "../../Microchip/MDD File System/SD-SPI.c" 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/65885567/SD-SPI.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/65885567/SD-SPI.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/MPLAB.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    ../PIC18F/18f46k20_g.lkr
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_LD} $(MP_EXTRA_LD_PRE) "../PIC18F/18f46k20_g.lkr"  -p$(MP_PROCESSOR_OPTION_LD)  -w -x -u_DEBUG   -z__MPLAB_BUILD=1  -u_CRUNTIME -z__MPLAB_DEBUG=1 -z__MPLAB_DEBUGGER_PK3=1 $(MP_LINKER_DEBUG_OPTION) -l ${MP_CC_DIR}/../lib  -o dist/${CND_CONF}/${IMAGE_TYPE}/MPLAB.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}   
else
dist/${CND_CONF}/${IMAGE_TYPE}/MPLAB.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   ../PIC18F/18f46k20_g.lkr
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_LD} $(MP_EXTRA_LD_PRE) "../PIC18F/18f46k20_g.lkr"  -p$(MP_PROCESSOR_OPTION_LD)  -w    -z__MPLAB_BUILD=1  -u_CRUNTIME -l ${MP_CC_DIR}/../lib  -o dist/${CND_CONF}/${IMAGE_TYPE}/MPLAB.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}   
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/PIC18F46K20
	${RM} -r dist/PIC18F46K20

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell "${PATH_TO_IDE_BIN}"mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
