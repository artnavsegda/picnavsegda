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
ifeq "$(wildcard nbproject/Makefile-local-PICDEM.net2_ENC28J60.mk)" "nbproject/Makefile-local-PICDEM.net2_ENC28J60.mk"
include nbproject/Makefile-local-PICDEM.net2_ENC28J60.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=PICDEM.net2_ENC28J60
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/udpDEMO.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/udpDEMO.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=../board_support_package/picdem2_net/adc.c ../board_support_package/picdem2_net/configuration.c ../board_support_package/picdem2_net/eeprom.c ../board_support_package/picdem2_net/hardware.c ../board_support_package/picdem2_net/lcd.c ../board_support_package/picdem2_net/lcd_hw.c ../board_support_package/picdem2_net/led_driver.c ../board_support_package/picdem2_net/mssp_spi_master.c ../board_support_package/picdem2_net/rtcc.c ../board_support_package/picdem2_net/uart.c "../../TCPIP Library/ethernet_drivers/enc28J60.c" "../../TCPIP Library/source/arpv4.c" "../../TCPIP Library/source/dhcp_client.c" "../../TCPIP Library/source/icmp.c" "../../TCPIP Library/source/ipv4.c" "../../TCPIP Library/source/mac_address.c" "../../TCPIP Library/source/network.c" "../../TCPIP Library/source/syslog.c" "../../TCPIP Library/source/tcpv4.c" "../../TCPIP Library/source/udpv4.c" main.c udp_demo.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/_ext/822349805/adc.p1 ${OBJECTDIR}/_ext/822349805/configuration.p1 ${OBJECTDIR}/_ext/822349805/eeprom.p1 ${OBJECTDIR}/_ext/822349805/hardware.p1 ${OBJECTDIR}/_ext/822349805/lcd.p1 ${OBJECTDIR}/_ext/822349805/lcd_hw.p1 ${OBJECTDIR}/_ext/822349805/led_driver.p1 ${OBJECTDIR}/_ext/822349805/mssp_spi_master.p1 ${OBJECTDIR}/_ext/822349805/rtcc.p1 ${OBJECTDIR}/_ext/822349805/uart.p1 ${OBJECTDIR}/_ext/870151663/enc28J60.p1 ${OBJECTDIR}/_ext/2026168359/arpv4.p1 ${OBJECTDIR}/_ext/2026168359/dhcp_client.p1 ${OBJECTDIR}/_ext/2026168359/icmp.p1 ${OBJECTDIR}/_ext/2026168359/ipv4.p1 ${OBJECTDIR}/_ext/2026168359/mac_address.p1 ${OBJECTDIR}/_ext/2026168359/network.p1 ${OBJECTDIR}/_ext/2026168359/syslog.p1 ${OBJECTDIR}/_ext/2026168359/tcpv4.p1 ${OBJECTDIR}/_ext/2026168359/udpv4.p1 ${OBJECTDIR}/main.p1 ${OBJECTDIR}/udp_demo.p1
POSSIBLE_DEPFILES=${OBJECTDIR}/_ext/822349805/adc.p1.d ${OBJECTDIR}/_ext/822349805/configuration.p1.d ${OBJECTDIR}/_ext/822349805/eeprom.p1.d ${OBJECTDIR}/_ext/822349805/hardware.p1.d ${OBJECTDIR}/_ext/822349805/lcd.p1.d ${OBJECTDIR}/_ext/822349805/lcd_hw.p1.d ${OBJECTDIR}/_ext/822349805/led_driver.p1.d ${OBJECTDIR}/_ext/822349805/mssp_spi_master.p1.d ${OBJECTDIR}/_ext/822349805/rtcc.p1.d ${OBJECTDIR}/_ext/822349805/uart.p1.d ${OBJECTDIR}/_ext/870151663/enc28J60.p1.d ${OBJECTDIR}/_ext/2026168359/arpv4.p1.d ${OBJECTDIR}/_ext/2026168359/dhcp_client.p1.d ${OBJECTDIR}/_ext/2026168359/icmp.p1.d ${OBJECTDIR}/_ext/2026168359/ipv4.p1.d ${OBJECTDIR}/_ext/2026168359/mac_address.p1.d ${OBJECTDIR}/_ext/2026168359/network.p1.d ${OBJECTDIR}/_ext/2026168359/syslog.p1.d ${OBJECTDIR}/_ext/2026168359/tcpv4.p1.d ${OBJECTDIR}/_ext/2026168359/udpv4.p1.d ${OBJECTDIR}/main.p1.d ${OBJECTDIR}/udp_demo.p1.d

# Object Files
OBJECTFILES=${OBJECTDIR}/_ext/822349805/adc.p1 ${OBJECTDIR}/_ext/822349805/configuration.p1 ${OBJECTDIR}/_ext/822349805/eeprom.p1 ${OBJECTDIR}/_ext/822349805/hardware.p1 ${OBJECTDIR}/_ext/822349805/lcd.p1 ${OBJECTDIR}/_ext/822349805/lcd_hw.p1 ${OBJECTDIR}/_ext/822349805/led_driver.p1 ${OBJECTDIR}/_ext/822349805/mssp_spi_master.p1 ${OBJECTDIR}/_ext/822349805/rtcc.p1 ${OBJECTDIR}/_ext/822349805/uart.p1 ${OBJECTDIR}/_ext/870151663/enc28J60.p1 ${OBJECTDIR}/_ext/2026168359/arpv4.p1 ${OBJECTDIR}/_ext/2026168359/dhcp_client.p1 ${OBJECTDIR}/_ext/2026168359/icmp.p1 ${OBJECTDIR}/_ext/2026168359/ipv4.p1 ${OBJECTDIR}/_ext/2026168359/mac_address.p1 ${OBJECTDIR}/_ext/2026168359/network.p1 ${OBJECTDIR}/_ext/2026168359/syslog.p1 ${OBJECTDIR}/_ext/2026168359/tcpv4.p1 ${OBJECTDIR}/_ext/2026168359/udpv4.p1 ${OBJECTDIR}/main.p1 ${OBJECTDIR}/udp_demo.p1

# Source Files
SOURCEFILES=../board_support_package/picdem2_net/adc.c ../board_support_package/picdem2_net/configuration.c ../board_support_package/picdem2_net/eeprom.c ../board_support_package/picdem2_net/hardware.c ../board_support_package/picdem2_net/lcd.c ../board_support_package/picdem2_net/lcd_hw.c ../board_support_package/picdem2_net/led_driver.c ../board_support_package/picdem2_net/mssp_spi_master.c ../board_support_package/picdem2_net/rtcc.c ../board_support_package/picdem2_net/uart.c ../../TCPIP Library/ethernet_drivers/enc28J60.c ../../TCPIP Library/source/arpv4.c ../../TCPIP Library/source/dhcp_client.c ../../TCPIP Library/source/icmp.c ../../TCPIP Library/source/ipv4.c ../../TCPIP Library/source/mac_address.c ../../TCPIP Library/source/network.c ../../TCPIP Library/source/syslog.c ../../TCPIP Library/source/tcpv4.c ../../TCPIP Library/source/udpv4.c main.c udp_demo.c


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
	${MAKE}  -f nbproject/Makefile-PICDEM.net2_ENC28J60.mk dist/${CND_CONF}/${IMAGE_TYPE}/udpDEMO.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=18F97J60
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/_ext/822349805/adc.p1: ../board_support_package/picdem2_net/adc.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/822349805" 
	@${RM} ${OBJECTDIR}/_ext/822349805/adc.p1.d 
	@${RM} ${OBJECTDIR}/_ext/822349805/adc.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=realice  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -DUSE_ENC28J60_SPI -DUDP_DEMO -P -N255 -I"../../" -I"../" -I"../board_support_package" -I"../board_support_package/picdem2_net" -I"../../TCPIP Library" -I"../../TCPIP Library/ethernet_drivers" -I"../../TCPIP Library/include" -I"../../TCPIP Library/source" -I"../udpDEMO.X" --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/822349805/adc.p1  ../board_support_package/picdem2_net/adc.c 
	@-${MV} ${OBJECTDIR}/_ext/822349805/adc.d ${OBJECTDIR}/_ext/822349805/adc.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/822349805/adc.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/822349805/configuration.p1: ../board_support_package/picdem2_net/configuration.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/822349805" 
	@${RM} ${OBJECTDIR}/_ext/822349805/configuration.p1.d 
	@${RM} ${OBJECTDIR}/_ext/822349805/configuration.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=realice  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -DUSE_ENC28J60_SPI -DUDP_DEMO -P -N255 -I"../../" -I"../" -I"../board_support_package" -I"../board_support_package/picdem2_net" -I"../../TCPIP Library" -I"../../TCPIP Library/ethernet_drivers" -I"../../TCPIP Library/include" -I"../../TCPIP Library/source" -I"../udpDEMO.X" --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/822349805/configuration.p1  ../board_support_package/picdem2_net/configuration.c 
	@-${MV} ${OBJECTDIR}/_ext/822349805/configuration.d ${OBJECTDIR}/_ext/822349805/configuration.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/822349805/configuration.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/822349805/eeprom.p1: ../board_support_package/picdem2_net/eeprom.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/822349805" 
	@${RM} ${OBJECTDIR}/_ext/822349805/eeprom.p1.d 
	@${RM} ${OBJECTDIR}/_ext/822349805/eeprom.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=realice  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -DUSE_ENC28J60_SPI -DUDP_DEMO -P -N255 -I"../../" -I"../" -I"../board_support_package" -I"../board_support_package/picdem2_net" -I"../../TCPIP Library" -I"../../TCPIP Library/ethernet_drivers" -I"../../TCPIP Library/include" -I"../../TCPIP Library/source" -I"../udpDEMO.X" --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/822349805/eeprom.p1  ../board_support_package/picdem2_net/eeprom.c 
	@-${MV} ${OBJECTDIR}/_ext/822349805/eeprom.d ${OBJECTDIR}/_ext/822349805/eeprom.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/822349805/eeprom.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/822349805/hardware.p1: ../board_support_package/picdem2_net/hardware.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/822349805" 
	@${RM} ${OBJECTDIR}/_ext/822349805/hardware.p1.d 
	@${RM} ${OBJECTDIR}/_ext/822349805/hardware.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=realice  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -DUSE_ENC28J60_SPI -DUDP_DEMO -P -N255 -I"../../" -I"../" -I"../board_support_package" -I"../board_support_package/picdem2_net" -I"../../TCPIP Library" -I"../../TCPIP Library/ethernet_drivers" -I"../../TCPIP Library/include" -I"../../TCPIP Library/source" -I"../udpDEMO.X" --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/822349805/hardware.p1  ../board_support_package/picdem2_net/hardware.c 
	@-${MV} ${OBJECTDIR}/_ext/822349805/hardware.d ${OBJECTDIR}/_ext/822349805/hardware.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/822349805/hardware.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/822349805/lcd.p1: ../board_support_package/picdem2_net/lcd.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/822349805" 
	@${RM} ${OBJECTDIR}/_ext/822349805/lcd.p1.d 
	@${RM} ${OBJECTDIR}/_ext/822349805/lcd.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=realice  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -DUSE_ENC28J60_SPI -DUDP_DEMO -P -N255 -I"../../" -I"../" -I"../board_support_package" -I"../board_support_package/picdem2_net" -I"../../TCPIP Library" -I"../../TCPIP Library/ethernet_drivers" -I"../../TCPIP Library/include" -I"../../TCPIP Library/source" -I"../udpDEMO.X" --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/822349805/lcd.p1  ../board_support_package/picdem2_net/lcd.c 
	@-${MV} ${OBJECTDIR}/_ext/822349805/lcd.d ${OBJECTDIR}/_ext/822349805/lcd.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/822349805/lcd.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/822349805/lcd_hw.p1: ../board_support_package/picdem2_net/lcd_hw.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/822349805" 
	@${RM} ${OBJECTDIR}/_ext/822349805/lcd_hw.p1.d 
	@${RM} ${OBJECTDIR}/_ext/822349805/lcd_hw.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=realice  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -DUSE_ENC28J60_SPI -DUDP_DEMO -P -N255 -I"../../" -I"../" -I"../board_support_package" -I"../board_support_package/picdem2_net" -I"../../TCPIP Library" -I"../../TCPIP Library/ethernet_drivers" -I"../../TCPIP Library/include" -I"../../TCPIP Library/source" -I"../udpDEMO.X" --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/822349805/lcd_hw.p1  ../board_support_package/picdem2_net/lcd_hw.c 
	@-${MV} ${OBJECTDIR}/_ext/822349805/lcd_hw.d ${OBJECTDIR}/_ext/822349805/lcd_hw.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/822349805/lcd_hw.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/822349805/led_driver.p1: ../board_support_package/picdem2_net/led_driver.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/822349805" 
	@${RM} ${OBJECTDIR}/_ext/822349805/led_driver.p1.d 
	@${RM} ${OBJECTDIR}/_ext/822349805/led_driver.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=realice  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -DUSE_ENC28J60_SPI -DUDP_DEMO -P -N255 -I"../../" -I"../" -I"../board_support_package" -I"../board_support_package/picdem2_net" -I"../../TCPIP Library" -I"../../TCPIP Library/ethernet_drivers" -I"../../TCPIP Library/include" -I"../../TCPIP Library/source" -I"../udpDEMO.X" --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/822349805/led_driver.p1  ../board_support_package/picdem2_net/led_driver.c 
	@-${MV} ${OBJECTDIR}/_ext/822349805/led_driver.d ${OBJECTDIR}/_ext/822349805/led_driver.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/822349805/led_driver.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/822349805/mssp_spi_master.p1: ../board_support_package/picdem2_net/mssp_spi_master.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/822349805" 
	@${RM} ${OBJECTDIR}/_ext/822349805/mssp_spi_master.p1.d 
	@${RM} ${OBJECTDIR}/_ext/822349805/mssp_spi_master.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=realice  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -DUSE_ENC28J60_SPI -DUDP_DEMO -P -N255 -I"../../" -I"../" -I"../board_support_package" -I"../board_support_package/picdem2_net" -I"../../TCPIP Library" -I"../../TCPIP Library/ethernet_drivers" -I"../../TCPIP Library/include" -I"../../TCPIP Library/source" -I"../udpDEMO.X" --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/822349805/mssp_spi_master.p1  ../board_support_package/picdem2_net/mssp_spi_master.c 
	@-${MV} ${OBJECTDIR}/_ext/822349805/mssp_spi_master.d ${OBJECTDIR}/_ext/822349805/mssp_spi_master.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/822349805/mssp_spi_master.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/822349805/rtcc.p1: ../board_support_package/picdem2_net/rtcc.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/822349805" 
	@${RM} ${OBJECTDIR}/_ext/822349805/rtcc.p1.d 
	@${RM} ${OBJECTDIR}/_ext/822349805/rtcc.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=realice  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -DUSE_ENC28J60_SPI -DUDP_DEMO -P -N255 -I"../../" -I"../" -I"../board_support_package" -I"../board_support_package/picdem2_net" -I"../../TCPIP Library" -I"../../TCPIP Library/ethernet_drivers" -I"../../TCPIP Library/include" -I"../../TCPIP Library/source" -I"../udpDEMO.X" --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/822349805/rtcc.p1  ../board_support_package/picdem2_net/rtcc.c 
	@-${MV} ${OBJECTDIR}/_ext/822349805/rtcc.d ${OBJECTDIR}/_ext/822349805/rtcc.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/822349805/rtcc.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/822349805/uart.p1: ../board_support_package/picdem2_net/uart.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/822349805" 
	@${RM} ${OBJECTDIR}/_ext/822349805/uart.p1.d 
	@${RM} ${OBJECTDIR}/_ext/822349805/uart.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=realice  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -DUSE_ENC28J60_SPI -DUDP_DEMO -P -N255 -I"../../" -I"../" -I"../board_support_package" -I"../board_support_package/picdem2_net" -I"../../TCPIP Library" -I"../../TCPIP Library/ethernet_drivers" -I"../../TCPIP Library/include" -I"../../TCPIP Library/source" -I"../udpDEMO.X" --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/822349805/uart.p1  ../board_support_package/picdem2_net/uart.c 
	@-${MV} ${OBJECTDIR}/_ext/822349805/uart.d ${OBJECTDIR}/_ext/822349805/uart.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/822349805/uart.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/870151663/enc28J60.p1: ../../TCPIP\ Library/ethernet_drivers/enc28J60.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/870151663" 
	@${RM} ${OBJECTDIR}/_ext/870151663/enc28J60.p1.d 
	@${RM} ${OBJECTDIR}/_ext/870151663/enc28J60.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=realice  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -DUSE_ENC28J60_SPI -DUDP_DEMO -P -N255 -I"../../" -I"../" -I"../board_support_package" -I"../board_support_package/picdem2_net" -I"../../TCPIP Library" -I"../../TCPIP Library/ethernet_drivers" -I"../../TCPIP Library/include" -I"../../TCPIP Library/source" -I"../udpDEMO.X" --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/870151663/enc28J60.p1  "../../TCPIP Library/ethernet_drivers/enc28J60.c" 
	@-${MV} ${OBJECTDIR}/_ext/870151663/enc28J60.d ${OBJECTDIR}/_ext/870151663/enc28J60.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/870151663/enc28J60.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/2026168359/arpv4.p1: ../../TCPIP\ Library/source/arpv4.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/2026168359" 
	@${RM} ${OBJECTDIR}/_ext/2026168359/arpv4.p1.d 
	@${RM} ${OBJECTDIR}/_ext/2026168359/arpv4.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=realice  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -DUSE_ENC28J60_SPI -DUDP_DEMO -P -N255 -I"../../" -I"../" -I"../board_support_package" -I"../board_support_package/picdem2_net" -I"../../TCPIP Library" -I"../../TCPIP Library/ethernet_drivers" -I"../../TCPIP Library/include" -I"../../TCPIP Library/source" -I"../udpDEMO.X" --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/2026168359/arpv4.p1  "../../TCPIP Library/source/arpv4.c" 
	@-${MV} ${OBJECTDIR}/_ext/2026168359/arpv4.d ${OBJECTDIR}/_ext/2026168359/arpv4.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/2026168359/arpv4.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/2026168359/dhcp_client.p1: ../../TCPIP\ Library/source/dhcp_client.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/2026168359" 
	@${RM} ${OBJECTDIR}/_ext/2026168359/dhcp_client.p1.d 
	@${RM} ${OBJECTDIR}/_ext/2026168359/dhcp_client.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=realice  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -DUSE_ENC28J60_SPI -DUDP_DEMO -P -N255 -I"../../" -I"../" -I"../board_support_package" -I"../board_support_package/picdem2_net" -I"../../TCPIP Library" -I"../../TCPIP Library/ethernet_drivers" -I"../../TCPIP Library/include" -I"../../TCPIP Library/source" -I"../udpDEMO.X" --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/2026168359/dhcp_client.p1  "../../TCPIP Library/source/dhcp_client.c" 
	@-${MV} ${OBJECTDIR}/_ext/2026168359/dhcp_client.d ${OBJECTDIR}/_ext/2026168359/dhcp_client.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/2026168359/dhcp_client.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/2026168359/icmp.p1: ../../TCPIP\ Library/source/icmp.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/2026168359" 
	@${RM} ${OBJECTDIR}/_ext/2026168359/icmp.p1.d 
	@${RM} ${OBJECTDIR}/_ext/2026168359/icmp.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=realice  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -DUSE_ENC28J60_SPI -DUDP_DEMO -P -N255 -I"../../" -I"../" -I"../board_support_package" -I"../board_support_package/picdem2_net" -I"../../TCPIP Library" -I"../../TCPIP Library/ethernet_drivers" -I"../../TCPIP Library/include" -I"../../TCPIP Library/source" -I"../udpDEMO.X" --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/2026168359/icmp.p1  "../../TCPIP Library/source/icmp.c" 
	@-${MV} ${OBJECTDIR}/_ext/2026168359/icmp.d ${OBJECTDIR}/_ext/2026168359/icmp.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/2026168359/icmp.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/2026168359/ipv4.p1: ../../TCPIP\ Library/source/ipv4.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/2026168359" 
	@${RM} ${OBJECTDIR}/_ext/2026168359/ipv4.p1.d 
	@${RM} ${OBJECTDIR}/_ext/2026168359/ipv4.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=realice  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -DUSE_ENC28J60_SPI -DUDP_DEMO -P -N255 -I"../../" -I"../" -I"../board_support_package" -I"../board_support_package/picdem2_net" -I"../../TCPIP Library" -I"../../TCPIP Library/ethernet_drivers" -I"../../TCPIP Library/include" -I"../../TCPIP Library/source" -I"../udpDEMO.X" --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/2026168359/ipv4.p1  "../../TCPIP Library/source/ipv4.c" 
	@-${MV} ${OBJECTDIR}/_ext/2026168359/ipv4.d ${OBJECTDIR}/_ext/2026168359/ipv4.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/2026168359/ipv4.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/2026168359/mac_address.p1: ../../TCPIP\ Library/source/mac_address.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/2026168359" 
	@${RM} ${OBJECTDIR}/_ext/2026168359/mac_address.p1.d 
	@${RM} ${OBJECTDIR}/_ext/2026168359/mac_address.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=realice  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -DUSE_ENC28J60_SPI -DUDP_DEMO -P -N255 -I"../../" -I"../" -I"../board_support_package" -I"../board_support_package/picdem2_net" -I"../../TCPIP Library" -I"../../TCPIP Library/ethernet_drivers" -I"../../TCPIP Library/include" -I"../../TCPIP Library/source" -I"../udpDEMO.X" --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/2026168359/mac_address.p1  "../../TCPIP Library/source/mac_address.c" 
	@-${MV} ${OBJECTDIR}/_ext/2026168359/mac_address.d ${OBJECTDIR}/_ext/2026168359/mac_address.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/2026168359/mac_address.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/2026168359/network.p1: ../../TCPIP\ Library/source/network.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/2026168359" 
	@${RM} ${OBJECTDIR}/_ext/2026168359/network.p1.d 
	@${RM} ${OBJECTDIR}/_ext/2026168359/network.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=realice  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -DUSE_ENC28J60_SPI -DUDP_DEMO -P -N255 -I"../../" -I"../" -I"../board_support_package" -I"../board_support_package/picdem2_net" -I"../../TCPIP Library" -I"../../TCPIP Library/ethernet_drivers" -I"../../TCPIP Library/include" -I"../../TCPIP Library/source" -I"../udpDEMO.X" --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/2026168359/network.p1  "../../TCPIP Library/source/network.c" 
	@-${MV} ${OBJECTDIR}/_ext/2026168359/network.d ${OBJECTDIR}/_ext/2026168359/network.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/2026168359/network.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/2026168359/syslog.p1: ../../TCPIP\ Library/source/syslog.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/2026168359" 
	@${RM} ${OBJECTDIR}/_ext/2026168359/syslog.p1.d 
	@${RM} ${OBJECTDIR}/_ext/2026168359/syslog.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=realice  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -DUSE_ENC28J60_SPI -DUDP_DEMO -P -N255 -I"../../" -I"../" -I"../board_support_package" -I"../board_support_package/picdem2_net" -I"../../TCPIP Library" -I"../../TCPIP Library/ethernet_drivers" -I"../../TCPIP Library/include" -I"../../TCPIP Library/source" -I"../udpDEMO.X" --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/2026168359/syslog.p1  "../../TCPIP Library/source/syslog.c" 
	@-${MV} ${OBJECTDIR}/_ext/2026168359/syslog.d ${OBJECTDIR}/_ext/2026168359/syslog.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/2026168359/syslog.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/2026168359/tcpv4.p1: ../../TCPIP\ Library/source/tcpv4.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/2026168359" 
	@${RM} ${OBJECTDIR}/_ext/2026168359/tcpv4.p1.d 
	@${RM} ${OBJECTDIR}/_ext/2026168359/tcpv4.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=realice  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -DUSE_ENC28J60_SPI -DUDP_DEMO -P -N255 -I"../../" -I"../" -I"../board_support_package" -I"../board_support_package/picdem2_net" -I"../../TCPIP Library" -I"../../TCPIP Library/ethernet_drivers" -I"../../TCPIP Library/include" -I"../../TCPIP Library/source" -I"../udpDEMO.X" --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/2026168359/tcpv4.p1  "../../TCPIP Library/source/tcpv4.c" 
	@-${MV} ${OBJECTDIR}/_ext/2026168359/tcpv4.d ${OBJECTDIR}/_ext/2026168359/tcpv4.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/2026168359/tcpv4.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/2026168359/udpv4.p1: ../../TCPIP\ Library/source/udpv4.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/2026168359" 
	@${RM} ${OBJECTDIR}/_ext/2026168359/udpv4.p1.d 
	@${RM} ${OBJECTDIR}/_ext/2026168359/udpv4.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=realice  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -DUSE_ENC28J60_SPI -DUDP_DEMO -P -N255 -I"../../" -I"../" -I"../board_support_package" -I"../board_support_package/picdem2_net" -I"../../TCPIP Library" -I"../../TCPIP Library/ethernet_drivers" -I"../../TCPIP Library/include" -I"../../TCPIP Library/source" -I"../udpDEMO.X" --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/2026168359/udpv4.p1  "../../TCPIP Library/source/udpv4.c" 
	@-${MV} ${OBJECTDIR}/_ext/2026168359/udpv4.d ${OBJECTDIR}/_ext/2026168359/udpv4.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/2026168359/udpv4.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/main.p1: main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.p1.d 
	@${RM} ${OBJECTDIR}/main.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=realice  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -DUSE_ENC28J60_SPI -DUDP_DEMO -P -N255 -I"../../" -I"../" -I"../board_support_package" -I"../board_support_package/picdem2_net" -I"../../TCPIP Library" -I"../../TCPIP Library/ethernet_drivers" -I"../../TCPIP Library/include" -I"../../TCPIP Library/source" -I"../udpDEMO.X" --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/main.p1  main.c 
	@-${MV} ${OBJECTDIR}/main.d ${OBJECTDIR}/main.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/main.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/udp_demo.p1: udp_demo.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/udp_demo.p1.d 
	@${RM} ${OBJECTDIR}/udp_demo.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=realice  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -DUSE_ENC28J60_SPI -DUDP_DEMO -P -N255 -I"../../" -I"../" -I"../board_support_package" -I"../board_support_package/picdem2_net" -I"../../TCPIP Library" -I"../../TCPIP Library/ethernet_drivers" -I"../../TCPIP Library/include" -I"../../TCPIP Library/source" -I"../udpDEMO.X" --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/udp_demo.p1  udp_demo.c 
	@-${MV} ${OBJECTDIR}/udp_demo.d ${OBJECTDIR}/udp_demo.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/udp_demo.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
else
${OBJECTDIR}/_ext/822349805/adc.p1: ../board_support_package/picdem2_net/adc.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/822349805" 
	@${RM} ${OBJECTDIR}/_ext/822349805/adc.p1.d 
	@${RM} ${OBJECTDIR}/_ext/822349805/adc.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -DUSE_ENC28J60_SPI -DUDP_DEMO -P -N255 -I"../../" -I"../" -I"../board_support_package" -I"../board_support_package/picdem2_net" -I"../../TCPIP Library" -I"../../TCPIP Library/ethernet_drivers" -I"../../TCPIP Library/include" -I"../../TCPIP Library/source" -I"../udpDEMO.X" --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/822349805/adc.p1  ../board_support_package/picdem2_net/adc.c 
	@-${MV} ${OBJECTDIR}/_ext/822349805/adc.d ${OBJECTDIR}/_ext/822349805/adc.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/822349805/adc.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/822349805/configuration.p1: ../board_support_package/picdem2_net/configuration.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/822349805" 
	@${RM} ${OBJECTDIR}/_ext/822349805/configuration.p1.d 
	@${RM} ${OBJECTDIR}/_ext/822349805/configuration.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -DUSE_ENC28J60_SPI -DUDP_DEMO -P -N255 -I"../../" -I"../" -I"../board_support_package" -I"../board_support_package/picdem2_net" -I"../../TCPIP Library" -I"../../TCPIP Library/ethernet_drivers" -I"../../TCPIP Library/include" -I"../../TCPIP Library/source" -I"../udpDEMO.X" --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/822349805/configuration.p1  ../board_support_package/picdem2_net/configuration.c 
	@-${MV} ${OBJECTDIR}/_ext/822349805/configuration.d ${OBJECTDIR}/_ext/822349805/configuration.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/822349805/configuration.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/822349805/eeprom.p1: ../board_support_package/picdem2_net/eeprom.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/822349805" 
	@${RM} ${OBJECTDIR}/_ext/822349805/eeprom.p1.d 
	@${RM} ${OBJECTDIR}/_ext/822349805/eeprom.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -DUSE_ENC28J60_SPI -DUDP_DEMO -P -N255 -I"../../" -I"../" -I"../board_support_package" -I"../board_support_package/picdem2_net" -I"../../TCPIP Library" -I"../../TCPIP Library/ethernet_drivers" -I"../../TCPIP Library/include" -I"../../TCPIP Library/source" -I"../udpDEMO.X" --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/822349805/eeprom.p1  ../board_support_package/picdem2_net/eeprom.c 
	@-${MV} ${OBJECTDIR}/_ext/822349805/eeprom.d ${OBJECTDIR}/_ext/822349805/eeprom.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/822349805/eeprom.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/822349805/hardware.p1: ../board_support_package/picdem2_net/hardware.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/822349805" 
	@${RM} ${OBJECTDIR}/_ext/822349805/hardware.p1.d 
	@${RM} ${OBJECTDIR}/_ext/822349805/hardware.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -DUSE_ENC28J60_SPI -DUDP_DEMO -P -N255 -I"../../" -I"../" -I"../board_support_package" -I"../board_support_package/picdem2_net" -I"../../TCPIP Library" -I"../../TCPIP Library/ethernet_drivers" -I"../../TCPIP Library/include" -I"../../TCPIP Library/source" -I"../udpDEMO.X" --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/822349805/hardware.p1  ../board_support_package/picdem2_net/hardware.c 
	@-${MV} ${OBJECTDIR}/_ext/822349805/hardware.d ${OBJECTDIR}/_ext/822349805/hardware.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/822349805/hardware.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/822349805/lcd.p1: ../board_support_package/picdem2_net/lcd.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/822349805" 
	@${RM} ${OBJECTDIR}/_ext/822349805/lcd.p1.d 
	@${RM} ${OBJECTDIR}/_ext/822349805/lcd.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -DUSE_ENC28J60_SPI -DUDP_DEMO -P -N255 -I"../../" -I"../" -I"../board_support_package" -I"../board_support_package/picdem2_net" -I"../../TCPIP Library" -I"../../TCPIP Library/ethernet_drivers" -I"../../TCPIP Library/include" -I"../../TCPIP Library/source" -I"../udpDEMO.X" --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/822349805/lcd.p1  ../board_support_package/picdem2_net/lcd.c 
	@-${MV} ${OBJECTDIR}/_ext/822349805/lcd.d ${OBJECTDIR}/_ext/822349805/lcd.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/822349805/lcd.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/822349805/lcd_hw.p1: ../board_support_package/picdem2_net/lcd_hw.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/822349805" 
	@${RM} ${OBJECTDIR}/_ext/822349805/lcd_hw.p1.d 
	@${RM} ${OBJECTDIR}/_ext/822349805/lcd_hw.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -DUSE_ENC28J60_SPI -DUDP_DEMO -P -N255 -I"../../" -I"../" -I"../board_support_package" -I"../board_support_package/picdem2_net" -I"../../TCPIP Library" -I"../../TCPIP Library/ethernet_drivers" -I"../../TCPIP Library/include" -I"../../TCPIP Library/source" -I"../udpDEMO.X" --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/822349805/lcd_hw.p1  ../board_support_package/picdem2_net/lcd_hw.c 
	@-${MV} ${OBJECTDIR}/_ext/822349805/lcd_hw.d ${OBJECTDIR}/_ext/822349805/lcd_hw.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/822349805/lcd_hw.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/822349805/led_driver.p1: ../board_support_package/picdem2_net/led_driver.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/822349805" 
	@${RM} ${OBJECTDIR}/_ext/822349805/led_driver.p1.d 
	@${RM} ${OBJECTDIR}/_ext/822349805/led_driver.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -DUSE_ENC28J60_SPI -DUDP_DEMO -P -N255 -I"../../" -I"../" -I"../board_support_package" -I"../board_support_package/picdem2_net" -I"../../TCPIP Library" -I"../../TCPIP Library/ethernet_drivers" -I"../../TCPIP Library/include" -I"../../TCPIP Library/source" -I"../udpDEMO.X" --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/822349805/led_driver.p1  ../board_support_package/picdem2_net/led_driver.c 
	@-${MV} ${OBJECTDIR}/_ext/822349805/led_driver.d ${OBJECTDIR}/_ext/822349805/led_driver.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/822349805/led_driver.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/822349805/mssp_spi_master.p1: ../board_support_package/picdem2_net/mssp_spi_master.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/822349805" 
	@${RM} ${OBJECTDIR}/_ext/822349805/mssp_spi_master.p1.d 
	@${RM} ${OBJECTDIR}/_ext/822349805/mssp_spi_master.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -DUSE_ENC28J60_SPI -DUDP_DEMO -P -N255 -I"../../" -I"../" -I"../board_support_package" -I"../board_support_package/picdem2_net" -I"../../TCPIP Library" -I"../../TCPIP Library/ethernet_drivers" -I"../../TCPIP Library/include" -I"../../TCPIP Library/source" -I"../udpDEMO.X" --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/822349805/mssp_spi_master.p1  ../board_support_package/picdem2_net/mssp_spi_master.c 
	@-${MV} ${OBJECTDIR}/_ext/822349805/mssp_spi_master.d ${OBJECTDIR}/_ext/822349805/mssp_spi_master.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/822349805/mssp_spi_master.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/822349805/rtcc.p1: ../board_support_package/picdem2_net/rtcc.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/822349805" 
	@${RM} ${OBJECTDIR}/_ext/822349805/rtcc.p1.d 
	@${RM} ${OBJECTDIR}/_ext/822349805/rtcc.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -DUSE_ENC28J60_SPI -DUDP_DEMO -P -N255 -I"../../" -I"../" -I"../board_support_package" -I"../board_support_package/picdem2_net" -I"../../TCPIP Library" -I"../../TCPIP Library/ethernet_drivers" -I"../../TCPIP Library/include" -I"../../TCPIP Library/source" -I"../udpDEMO.X" --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/822349805/rtcc.p1  ../board_support_package/picdem2_net/rtcc.c 
	@-${MV} ${OBJECTDIR}/_ext/822349805/rtcc.d ${OBJECTDIR}/_ext/822349805/rtcc.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/822349805/rtcc.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/822349805/uart.p1: ../board_support_package/picdem2_net/uart.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/822349805" 
	@${RM} ${OBJECTDIR}/_ext/822349805/uart.p1.d 
	@${RM} ${OBJECTDIR}/_ext/822349805/uart.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -DUSE_ENC28J60_SPI -DUDP_DEMO -P -N255 -I"../../" -I"../" -I"../board_support_package" -I"../board_support_package/picdem2_net" -I"../../TCPIP Library" -I"../../TCPIP Library/ethernet_drivers" -I"../../TCPIP Library/include" -I"../../TCPIP Library/source" -I"../udpDEMO.X" --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/822349805/uart.p1  ../board_support_package/picdem2_net/uart.c 
	@-${MV} ${OBJECTDIR}/_ext/822349805/uart.d ${OBJECTDIR}/_ext/822349805/uart.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/822349805/uart.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/870151663/enc28J60.p1: ../../TCPIP\ Library/ethernet_drivers/enc28J60.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/870151663" 
	@${RM} ${OBJECTDIR}/_ext/870151663/enc28J60.p1.d 
	@${RM} ${OBJECTDIR}/_ext/870151663/enc28J60.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -DUSE_ENC28J60_SPI -DUDP_DEMO -P -N255 -I"../../" -I"../" -I"../board_support_package" -I"../board_support_package/picdem2_net" -I"../../TCPIP Library" -I"../../TCPIP Library/ethernet_drivers" -I"../../TCPIP Library/include" -I"../../TCPIP Library/source" -I"../udpDEMO.X" --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/870151663/enc28J60.p1  "../../TCPIP Library/ethernet_drivers/enc28J60.c" 
	@-${MV} ${OBJECTDIR}/_ext/870151663/enc28J60.d ${OBJECTDIR}/_ext/870151663/enc28J60.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/870151663/enc28J60.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/2026168359/arpv4.p1: ../../TCPIP\ Library/source/arpv4.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/2026168359" 
	@${RM} ${OBJECTDIR}/_ext/2026168359/arpv4.p1.d 
	@${RM} ${OBJECTDIR}/_ext/2026168359/arpv4.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -DUSE_ENC28J60_SPI -DUDP_DEMO -P -N255 -I"../../" -I"../" -I"../board_support_package" -I"../board_support_package/picdem2_net" -I"../../TCPIP Library" -I"../../TCPIP Library/ethernet_drivers" -I"../../TCPIP Library/include" -I"../../TCPIP Library/source" -I"../udpDEMO.X" --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/2026168359/arpv4.p1  "../../TCPIP Library/source/arpv4.c" 
	@-${MV} ${OBJECTDIR}/_ext/2026168359/arpv4.d ${OBJECTDIR}/_ext/2026168359/arpv4.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/2026168359/arpv4.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/2026168359/dhcp_client.p1: ../../TCPIP\ Library/source/dhcp_client.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/2026168359" 
	@${RM} ${OBJECTDIR}/_ext/2026168359/dhcp_client.p1.d 
	@${RM} ${OBJECTDIR}/_ext/2026168359/dhcp_client.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -DUSE_ENC28J60_SPI -DUDP_DEMO -P -N255 -I"../../" -I"../" -I"../board_support_package" -I"../board_support_package/picdem2_net" -I"../../TCPIP Library" -I"../../TCPIP Library/ethernet_drivers" -I"../../TCPIP Library/include" -I"../../TCPIP Library/source" -I"../udpDEMO.X" --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/2026168359/dhcp_client.p1  "../../TCPIP Library/source/dhcp_client.c" 
	@-${MV} ${OBJECTDIR}/_ext/2026168359/dhcp_client.d ${OBJECTDIR}/_ext/2026168359/dhcp_client.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/2026168359/dhcp_client.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/2026168359/icmp.p1: ../../TCPIP\ Library/source/icmp.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/2026168359" 
	@${RM} ${OBJECTDIR}/_ext/2026168359/icmp.p1.d 
	@${RM} ${OBJECTDIR}/_ext/2026168359/icmp.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -DUSE_ENC28J60_SPI -DUDP_DEMO -P -N255 -I"../../" -I"../" -I"../board_support_package" -I"../board_support_package/picdem2_net" -I"../../TCPIP Library" -I"../../TCPIP Library/ethernet_drivers" -I"../../TCPIP Library/include" -I"../../TCPIP Library/source" -I"../udpDEMO.X" --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/2026168359/icmp.p1  "../../TCPIP Library/source/icmp.c" 
	@-${MV} ${OBJECTDIR}/_ext/2026168359/icmp.d ${OBJECTDIR}/_ext/2026168359/icmp.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/2026168359/icmp.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/2026168359/ipv4.p1: ../../TCPIP\ Library/source/ipv4.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/2026168359" 
	@${RM} ${OBJECTDIR}/_ext/2026168359/ipv4.p1.d 
	@${RM} ${OBJECTDIR}/_ext/2026168359/ipv4.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -DUSE_ENC28J60_SPI -DUDP_DEMO -P -N255 -I"../../" -I"../" -I"../board_support_package" -I"../board_support_package/picdem2_net" -I"../../TCPIP Library" -I"../../TCPIP Library/ethernet_drivers" -I"../../TCPIP Library/include" -I"../../TCPIP Library/source" -I"../udpDEMO.X" --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/2026168359/ipv4.p1  "../../TCPIP Library/source/ipv4.c" 
	@-${MV} ${OBJECTDIR}/_ext/2026168359/ipv4.d ${OBJECTDIR}/_ext/2026168359/ipv4.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/2026168359/ipv4.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/2026168359/mac_address.p1: ../../TCPIP\ Library/source/mac_address.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/2026168359" 
	@${RM} ${OBJECTDIR}/_ext/2026168359/mac_address.p1.d 
	@${RM} ${OBJECTDIR}/_ext/2026168359/mac_address.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -DUSE_ENC28J60_SPI -DUDP_DEMO -P -N255 -I"../../" -I"../" -I"../board_support_package" -I"../board_support_package/picdem2_net" -I"../../TCPIP Library" -I"../../TCPIP Library/ethernet_drivers" -I"../../TCPIP Library/include" -I"../../TCPIP Library/source" -I"../udpDEMO.X" --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/2026168359/mac_address.p1  "../../TCPIP Library/source/mac_address.c" 
	@-${MV} ${OBJECTDIR}/_ext/2026168359/mac_address.d ${OBJECTDIR}/_ext/2026168359/mac_address.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/2026168359/mac_address.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/2026168359/network.p1: ../../TCPIP\ Library/source/network.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/2026168359" 
	@${RM} ${OBJECTDIR}/_ext/2026168359/network.p1.d 
	@${RM} ${OBJECTDIR}/_ext/2026168359/network.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -DUSE_ENC28J60_SPI -DUDP_DEMO -P -N255 -I"../../" -I"../" -I"../board_support_package" -I"../board_support_package/picdem2_net" -I"../../TCPIP Library" -I"../../TCPIP Library/ethernet_drivers" -I"../../TCPIP Library/include" -I"../../TCPIP Library/source" -I"../udpDEMO.X" --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/2026168359/network.p1  "../../TCPIP Library/source/network.c" 
	@-${MV} ${OBJECTDIR}/_ext/2026168359/network.d ${OBJECTDIR}/_ext/2026168359/network.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/2026168359/network.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/2026168359/syslog.p1: ../../TCPIP\ Library/source/syslog.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/2026168359" 
	@${RM} ${OBJECTDIR}/_ext/2026168359/syslog.p1.d 
	@${RM} ${OBJECTDIR}/_ext/2026168359/syslog.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -DUSE_ENC28J60_SPI -DUDP_DEMO -P -N255 -I"../../" -I"../" -I"../board_support_package" -I"../board_support_package/picdem2_net" -I"../../TCPIP Library" -I"../../TCPIP Library/ethernet_drivers" -I"../../TCPIP Library/include" -I"../../TCPIP Library/source" -I"../udpDEMO.X" --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/2026168359/syslog.p1  "../../TCPIP Library/source/syslog.c" 
	@-${MV} ${OBJECTDIR}/_ext/2026168359/syslog.d ${OBJECTDIR}/_ext/2026168359/syslog.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/2026168359/syslog.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/2026168359/tcpv4.p1: ../../TCPIP\ Library/source/tcpv4.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/2026168359" 
	@${RM} ${OBJECTDIR}/_ext/2026168359/tcpv4.p1.d 
	@${RM} ${OBJECTDIR}/_ext/2026168359/tcpv4.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -DUSE_ENC28J60_SPI -DUDP_DEMO -P -N255 -I"../../" -I"../" -I"../board_support_package" -I"../board_support_package/picdem2_net" -I"../../TCPIP Library" -I"../../TCPIP Library/ethernet_drivers" -I"../../TCPIP Library/include" -I"../../TCPIP Library/source" -I"../udpDEMO.X" --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/2026168359/tcpv4.p1  "../../TCPIP Library/source/tcpv4.c" 
	@-${MV} ${OBJECTDIR}/_ext/2026168359/tcpv4.d ${OBJECTDIR}/_ext/2026168359/tcpv4.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/2026168359/tcpv4.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/2026168359/udpv4.p1: ../../TCPIP\ Library/source/udpv4.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/2026168359" 
	@${RM} ${OBJECTDIR}/_ext/2026168359/udpv4.p1.d 
	@${RM} ${OBJECTDIR}/_ext/2026168359/udpv4.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -DUSE_ENC28J60_SPI -DUDP_DEMO -P -N255 -I"../../" -I"../" -I"../board_support_package" -I"../board_support_package/picdem2_net" -I"../../TCPIP Library" -I"../../TCPIP Library/ethernet_drivers" -I"../../TCPIP Library/include" -I"../../TCPIP Library/source" -I"../udpDEMO.X" --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/2026168359/udpv4.p1  "../../TCPIP Library/source/udpv4.c" 
	@-${MV} ${OBJECTDIR}/_ext/2026168359/udpv4.d ${OBJECTDIR}/_ext/2026168359/udpv4.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/2026168359/udpv4.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/main.p1: main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.p1.d 
	@${RM} ${OBJECTDIR}/main.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -DUSE_ENC28J60_SPI -DUDP_DEMO -P -N255 -I"../../" -I"../" -I"../board_support_package" -I"../board_support_package/picdem2_net" -I"../../TCPIP Library" -I"../../TCPIP Library/ethernet_drivers" -I"../../TCPIP Library/include" -I"../../TCPIP Library/source" -I"../udpDEMO.X" --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/main.p1  main.c 
	@-${MV} ${OBJECTDIR}/main.d ${OBJECTDIR}/main.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/main.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/udp_demo.p1: udp_demo.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/udp_demo.p1.d 
	@${RM} ${OBJECTDIR}/udp_demo.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -DUSE_ENC28J60_SPI -DUDP_DEMO -P -N255 -I"../../" -I"../" -I"../board_support_package" -I"../board_support_package/picdem2_net" -I"../../TCPIP Library" -I"../../TCPIP Library/ethernet_drivers" -I"../../TCPIP Library/include" -I"../../TCPIP Library/source" -I"../udpDEMO.X" --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/udp_demo.p1  udp_demo.c 
	@-${MV} ${OBJECTDIR}/udp_demo.d ${OBJECTDIR}/udp_demo.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/udp_demo.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/udpDEMO.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE) --chip=$(MP_PROCESSOR_OPTION) -G -mdist/${CND_CONF}/${IMAGE_TYPE}/udpDEMO.X.${IMAGE_TYPE}.map  -D__DEBUG=1 --debugger=realice  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -DUSE_ENC28J60_SPI -DUDP_DEMO -P -N255 -I"../../" -I"../" -I"../board_support_package" -I"../board_support_package/picdem2_net" -I"../../TCPIP Library" -I"../../TCPIP Library/ethernet_drivers" -I"../../TCPIP Library/include" -I"../../TCPIP Library/source" -I"../udpDEMO.X" --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s" --MSGDISABLE=1467:Off;       --memorysummary dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml -odist/${CND_CONF}/${IMAGE_TYPE}/udpDEMO.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}     
	@${RM} dist/${CND_CONF}/${IMAGE_TYPE}/udpDEMO.X.${IMAGE_TYPE}.hex 
	
else
dist/${CND_CONF}/${IMAGE_TYPE}/udpDEMO.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE) --chip=$(MP_PROCESSOR_OPTION) -G -mdist/${CND_CONF}/${IMAGE_TYPE}/udpDEMO.X.${IMAGE_TYPE}.map  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -DUSE_ENC28J60_SPI -DUDP_DEMO -P -N255 -I"../../" -I"../" -I"../board_support_package" -I"../board_support_package/picdem2_net" -I"../../TCPIP Library" -I"../../TCPIP Library/ethernet_drivers" -I"../../TCPIP Library/include" -I"../../TCPIP Library/source" -I"../udpDEMO.X" --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s" --MSGDISABLE=1467:Off;    --memorysummary dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml -odist/${CND_CONF}/${IMAGE_TYPE}/udpDEMO.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}     
	
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/PICDEM.net2_ENC28J60
	${RM} -r dist/PICDEM.net2_ENC28J60

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
