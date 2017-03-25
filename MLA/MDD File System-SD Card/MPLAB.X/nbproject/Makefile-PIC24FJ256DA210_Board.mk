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
ifeq "$(wildcard nbproject/Makefile-local-PIC24FJ256DA210_Board.mk)" "nbproject/Makefile-local-PIC24FJ256DA210_Board.mk"
include nbproject/Makefile-local-PIC24FJ256DA210_Board.mk
endif
endif

# Environment
MKDIR=mkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=PIC24FJ256DA210_Board
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
COMPARISON_BUILD=-mafrlcsj
else
COMPARISON_BUILD=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=../PIC24F/Demonstration2.c "../../Microchip/MDD File System/FSIO.c" "../../Microchip/MDD File System/SD-SPI.c"

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/_ext/1850834999/Demonstration2.o ${OBJECTDIR}/_ext/65885567/FSIO.o ${OBJECTDIR}/_ext/65885567/SD-SPI.o
POSSIBLE_DEPFILES=${OBJECTDIR}/_ext/1850834999/Demonstration2.o.d ${OBJECTDIR}/_ext/65885567/FSIO.o.d ${OBJECTDIR}/_ext/65885567/SD-SPI.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/_ext/1850834999/Demonstration2.o ${OBJECTDIR}/_ext/65885567/FSIO.o ${OBJECTDIR}/_ext/65885567/SD-SPI.o

# Source Files
SOURCEFILES=../PIC24F/Demonstration2.c ../../Microchip/MDD File System/FSIO.c ../../Microchip/MDD File System/SD-SPI.c


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
	${MAKE}  -f nbproject/Makefile-PIC24FJ256DA210_Board.mk dist/${CND_CONF}/${IMAGE_TYPE}/MPLAB.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=24FJ256DA210
MP_LINKER_FILE_OPTION=,--script="../PIC18F/18f46k20_g.lkr"
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/_ext/1850834999/Demonstration2.o: ../PIC24F/Demonstration2.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1850834999" 
	@${RM} ${OBJECTDIR}/_ext/1850834999/Demonstration2.o.d 
	@${RM} ${OBJECTDIR}/_ext/1850834999/Demonstration2.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../PIC24F/Demonstration2.c  -o ${OBJECTDIR}/_ext/1850834999/Demonstration2.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1850834999/Demonstration2.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_REAL_ICE=1  -mno-eds-warn  -omf=coff -DXPRJ_PIC24FJ256DA210_Board=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I".." -I"../PIC24F" -I"../../Include" -I"../../Include/MDD File System" -I"../../Microchip/Include" -I"../../Microchip/Include/MDD File System" -I"../../../Microchip/Include/MDD File System" -I"../../../MDD File System-SD Card" -I"../../../MDD File System-SD Card/PIC24F" -msmart-io=1 -Wall -msfr-warn=off   -fno-ivopts
	@${FIXDEPS} "${OBJECTDIR}/_ext/1850834999/Demonstration2.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/65885567/FSIO.o: ../../Microchip/MDD\ File\ System/FSIO.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/65885567" 
	@${RM} ${OBJECTDIR}/_ext/65885567/FSIO.o.d 
	@${RM} ${OBJECTDIR}/_ext/65885567/FSIO.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  "../../Microchip/MDD File System/FSIO.c"  -o ${OBJECTDIR}/_ext/65885567/FSIO.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/65885567/FSIO.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_REAL_ICE=1  -mno-eds-warn  -omf=coff -DXPRJ_PIC24FJ256DA210_Board=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I".." -I"../PIC24F" -I"../../Include" -I"../../Include/MDD File System" -I"../../Microchip/Include" -I"../../Microchip/Include/MDD File System" -I"../../../Microchip/Include/MDD File System" -I"../../../MDD File System-SD Card" -I"../../../MDD File System-SD Card/PIC24F" -msmart-io=1 -Wall -msfr-warn=off   -fno-ivopts
	@${FIXDEPS} "${OBJECTDIR}/_ext/65885567/FSIO.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/65885567/SD-SPI.o: ../../Microchip/MDD\ File\ System/SD-SPI.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/65885567" 
	@${RM} ${OBJECTDIR}/_ext/65885567/SD-SPI.o.d 
	@${RM} ${OBJECTDIR}/_ext/65885567/SD-SPI.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  "../../Microchip/MDD File System/SD-SPI.c"  -o ${OBJECTDIR}/_ext/65885567/SD-SPI.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/65885567/SD-SPI.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_REAL_ICE=1  -mno-eds-warn  -omf=coff -DXPRJ_PIC24FJ256DA210_Board=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I".." -I"../PIC24F" -I"../../Include" -I"../../Include/MDD File System" -I"../../Microchip/Include" -I"../../Microchip/Include/MDD File System" -I"../../../Microchip/Include/MDD File System" -I"../../../MDD File System-SD Card" -I"../../../MDD File System-SD Card/PIC24F" -msmart-io=1 -Wall -msfr-warn=off   -fno-ivopts
	@${FIXDEPS} "${OBJECTDIR}/_ext/65885567/SD-SPI.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
else
${OBJECTDIR}/_ext/1850834999/Demonstration2.o: ../PIC24F/Demonstration2.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1850834999" 
	@${RM} ${OBJECTDIR}/_ext/1850834999/Demonstration2.o.d 
	@${RM} ${OBJECTDIR}/_ext/1850834999/Demonstration2.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../PIC24F/Demonstration2.c  -o ${OBJECTDIR}/_ext/1850834999/Demonstration2.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1850834999/Demonstration2.o.d"      -mno-eds-warn  -g -omf=coff -DXPRJ_PIC24FJ256DA210_Board=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I".." -I"../PIC24F" -I"../../Include" -I"../../Include/MDD File System" -I"../../Microchip/Include" -I"../../Microchip/Include/MDD File System" -I"../../../Microchip/Include/MDD File System" -I"../../../MDD File System-SD Card" -I"../../../MDD File System-SD Card/PIC24F" -msmart-io=1 -Wall -msfr-warn=off   -fno-ivopts
	@${FIXDEPS} "${OBJECTDIR}/_ext/1850834999/Demonstration2.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/65885567/FSIO.o: ../../Microchip/MDD\ File\ System/FSIO.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/65885567" 
	@${RM} ${OBJECTDIR}/_ext/65885567/FSIO.o.d 
	@${RM} ${OBJECTDIR}/_ext/65885567/FSIO.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  "../../Microchip/MDD File System/FSIO.c"  -o ${OBJECTDIR}/_ext/65885567/FSIO.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/65885567/FSIO.o.d"      -mno-eds-warn  -g -omf=coff -DXPRJ_PIC24FJ256DA210_Board=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I".." -I"../PIC24F" -I"../../Include" -I"../../Include/MDD File System" -I"../../Microchip/Include" -I"../../Microchip/Include/MDD File System" -I"../../../Microchip/Include/MDD File System" -I"../../../MDD File System-SD Card" -I"../../../MDD File System-SD Card/PIC24F" -msmart-io=1 -Wall -msfr-warn=off   -fno-ivopts
	@${FIXDEPS} "${OBJECTDIR}/_ext/65885567/FSIO.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/65885567/SD-SPI.o: ../../Microchip/MDD\ File\ System/SD-SPI.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/65885567" 
	@${RM} ${OBJECTDIR}/_ext/65885567/SD-SPI.o.d 
	@${RM} ${OBJECTDIR}/_ext/65885567/SD-SPI.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  "../../Microchip/MDD File System/SD-SPI.c"  -o ${OBJECTDIR}/_ext/65885567/SD-SPI.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/65885567/SD-SPI.o.d"      -mno-eds-warn  -g -omf=coff -DXPRJ_PIC24FJ256DA210_Board=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I".." -I"../PIC24F" -I"../../Include" -I"../../Include/MDD File System" -I"../../Microchip/Include" -I"../../Microchip/Include/MDD File System" -I"../../../Microchip/Include/MDD File System" -I"../../../MDD File System-SD Card" -I"../../../MDD File System-SD Card/PIC24F" -msmart-io=1 -Wall -msfr-warn=off   -fno-ivopts
	@${FIXDEPS} "${OBJECTDIR}/_ext/65885567/SD-SPI.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemblePreproc
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/MPLAB.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    ../PIC18F/18f46k20_g.lkr
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o dist/${CND_CONF}/${IMAGE_TYPE}/MPLAB.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -D__DEBUG -D__MPLAB_DEBUGGER_REAL_ICE=1  -omf=coff -DXPRJ_PIC24FJ256DA210_Board=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)   -mreserve=data@0x800:0x81B -mreserve=data@0x81C:0x81D -mreserve=data@0x81E:0x81F -mreserve=data@0x820:0x821 -mreserve=data@0x822:0x823 -mreserve=data@0x824:0x827 -mreserve=data@0x82A:0x84F   -Wl,--local-stack,,--defsym=__MPLAB_BUILD=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,--defsym=__MPLAB_DEBUGGER_REAL_ICE=1,$(MP_LINKER_FILE_OPTION),--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--library-path="..",--no-force-link,--smart-io,-Map="$(BINDIR_)$(TARGETBASE).map",--report-mem,--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml$(MP_EXTRA_LD_POST) 
	
else
dist/${CND_CONF}/${IMAGE_TYPE}/MPLAB.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   ../PIC18F/18f46k20_g.lkr
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o dist/${CND_CONF}/${IMAGE_TYPE}/MPLAB.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -omf=coff -DXPRJ_PIC24FJ256DA210_Board=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wl,--local-stack,,--defsym=__MPLAB_BUILD=1,$(MP_LINKER_FILE_OPTION),--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--library-path="..",--no-force-link,--smart-io,-Map="$(BINDIR_)$(TARGETBASE).map",--report-mem,--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml$(MP_EXTRA_LD_POST) 
	${MP_CC_DIR}/xc16-bin2hex dist/${CND_CONF}/${IMAGE_TYPE}/MPLAB.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} -a  -omf=coff  
	
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/PIC24FJ256DA210_Board
	${RM} -r dist/PIC24FJ256DA210_Board

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell "${PATH_TO_IDE_BIN}"mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
