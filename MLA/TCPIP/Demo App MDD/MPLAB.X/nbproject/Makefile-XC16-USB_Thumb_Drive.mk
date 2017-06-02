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
ifeq "$(wildcard nbproject/Makefile-local-XC16-USB_Thumb_Drive.mk)" "nbproject/Makefile-local-XC16-USB_Thumb_Drive.mk"
include nbproject/Makefile-local-XC16-USB_Thumb_Drive.mk
endif
endif

# Environment
MKDIR=mkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=XC16-USB_Thumb_Drive
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/MPLAB.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/MPLAB.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=-mafrlcsj
else
COMPARISON_BUILD=
endif

ifdef SUB_IMAGE_ADDRESS
SUB_IMAGE_ADDRESS_COMMAND=--image-address $(SUB_IMAGE_ADDRESS)
else
SUB_IMAGE_ADDRESS_COMMAND=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=../BerkeleyTCPClientDemo.c ../BerkeleyTCPServerDemo.c ../BerkeleyUDPClientDemo.c ../GenericTCPClient.c ../GenericTCPServer.c ../PingDemo.c ../SMTPDemo.c ../UARTConfig.c "../../../Microchip/TCPIP Stack/ARCFOUR.c" "../../../Microchip/TCPIP Stack/ARP.c" "../../../Microchip/TCPIP Stack/Announce.c" "../../../Microchip/TCPIP Stack/AutoIP.c" "../../../Microchip/TCPIP Stack/BerkeleyAPI.c" "../../../Microchip/TCPIP Stack/BigInt.c" "../../../Microchip/TCPIP Stack/DHCP.c" "../../../Microchip/TCPIP Stack/DHCPs.c" "../../../Microchip/TCPIP Stack/DNS.c" "../../../Microchip/TCPIP Stack/DNSs.c" "../../../Microchip/TCPIP Stack/Delay.c" "../../../Microchip/TCPIP Stack/DynDNS.c" "../../../Microchip/TCPIP Stack/ENC28J60.c" "../../../Microchip/TCPIP Stack/ENCX24J600.c" "../../../Microchip/TCPIP Stack/FTP.c" "../../../Microchip/TCPIP Stack/FileSystem.c" ../HTTP2_MDD.c "../../../Microchip/TCPIP Stack/Hashes.c" "../../../Microchip/TCPIP Stack/Helpers.c" "../../../Microchip/TCPIP Stack/ICMP.c" "../../../Microchip/TCPIP Stack/IP.c" "../../../Microchip/TCPIP Stack/LCDBlocking.c" "../../../Microchip/TCPIP Stack/MPFS2.c" "../../../Microchip/TCPIP Stack/NBNS.c" "../../../Microchip/TCPIP Stack/RSA.c" "../../../Microchip/TCPIP Stack/Random.c" "../../../Microchip/TCPIP Stack/Reboot.c" "../../../Microchip/TCPIP Stack/SMTP.c" "../../../Microchip/TCPIP Stack/SNMP.c" "../../../Microchip/TCPIP Stack/SNTP.c" "../../../Microchip/TCPIP Stack/SPIEEPROM.c" "../../../Microchip/TCPIP Stack/SPIFlash.c" "../../../Microchip/TCPIP Stack/SPIRAM.c" "../../../Microchip/TCPIP Stack/SSL.c" "../../../Microchip/TCPIP Stack/StackTsk.c" "../../../Microchip/TCPIP Stack/TCP.c" "../../../Microchip/TCPIP Stack/TCPPerformanceTest.c" "../../../Microchip/TCPIP Stack/TFTPc.c" "../../../Microchip/TCPIP Stack/Telnet.c" "../../../Microchip/TCPIP Stack/Tick.c" "../../../Microchip/TCPIP Stack/UART.c" "../../../Microchip/TCPIP Stack/UART2TCPBridge.c" "../../../Microchip/TCPIP Stack/UDP.c" "../../../Microchip/TCPIP Stack/UDPPerformanceTest.c" ../../../Microchip/USB/usb_host.c "../../../Microchip/USB/MSD Host Driver/usb_host_msd.c" "../../../Microchip/USB/MSD Host Driver/usb_host_msd_scsi.c" ../CustomHTTPApp.c ../CustomSSLCert.c "../../../Microchip/MDD File System/FSIO.c" ../MainDemo.c ../usb_config.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/_ext/1472/BerkeleyTCPClientDemo.o ${OBJECTDIR}/_ext/1472/BerkeleyTCPServerDemo.o ${OBJECTDIR}/_ext/1472/BerkeleyUDPClientDemo.o ${OBJECTDIR}/_ext/1472/GenericTCPClient.o ${OBJECTDIR}/_ext/1472/GenericTCPServer.o ${OBJECTDIR}/_ext/1472/PingDemo.o ${OBJECTDIR}/_ext/1472/SMTPDemo.o ${OBJECTDIR}/_ext/1472/UARTConfig.o ${OBJECTDIR}/_ext/1954962658/ARCFOUR.o ${OBJECTDIR}/_ext/1954962658/ARP.o ${OBJECTDIR}/_ext/1954962658/Announce.o ${OBJECTDIR}/_ext/1954962658/AutoIP.o ${OBJECTDIR}/_ext/1954962658/BerkeleyAPI.o ${OBJECTDIR}/_ext/1954962658/BigInt.o ${OBJECTDIR}/_ext/1954962658/DHCP.o ${OBJECTDIR}/_ext/1954962658/DHCPs.o ${OBJECTDIR}/_ext/1954962658/DNS.o ${OBJECTDIR}/_ext/1954962658/DNSs.o ${OBJECTDIR}/_ext/1954962658/Delay.o ${OBJECTDIR}/_ext/1954962658/DynDNS.o ${OBJECTDIR}/_ext/1954962658/ENC28J60.o ${OBJECTDIR}/_ext/1954962658/ENCX24J600.o ${OBJECTDIR}/_ext/1954962658/FTP.o ${OBJECTDIR}/_ext/1954962658/FileSystem.o ${OBJECTDIR}/_ext/1472/HTTP2_MDD.o ${OBJECTDIR}/_ext/1954962658/Hashes.o ${OBJECTDIR}/_ext/1954962658/Helpers.o ${OBJECTDIR}/_ext/1954962658/ICMP.o ${OBJECTDIR}/_ext/1954962658/IP.o ${OBJECTDIR}/_ext/1954962658/LCDBlocking.o ${OBJECTDIR}/_ext/1954962658/MPFS2.o ${OBJECTDIR}/_ext/1954962658/NBNS.o ${OBJECTDIR}/_ext/1954962658/RSA.o ${OBJECTDIR}/_ext/1954962658/Random.o ${OBJECTDIR}/_ext/1954962658/Reboot.o ${OBJECTDIR}/_ext/1954962658/SMTP.o ${OBJECTDIR}/_ext/1954962658/SNMP.o ${OBJECTDIR}/_ext/1954962658/SNTP.o ${OBJECTDIR}/_ext/1954962658/SPIEEPROM.o ${OBJECTDIR}/_ext/1954962658/SPIFlash.o ${OBJECTDIR}/_ext/1954962658/SPIRAM.o ${OBJECTDIR}/_ext/1954962658/SSL.o ${OBJECTDIR}/_ext/1954962658/StackTsk.o ${OBJECTDIR}/_ext/1954962658/TCP.o ${OBJECTDIR}/_ext/1954962658/TCPPerformanceTest.o ${OBJECTDIR}/_ext/1954962658/TFTPc.o ${OBJECTDIR}/_ext/1954962658/Telnet.o ${OBJECTDIR}/_ext/1954962658/Tick.o ${OBJECTDIR}/_ext/1954962658/UART.o ${OBJECTDIR}/_ext/1954962658/UART2TCPBridge.o ${OBJECTDIR}/_ext/1954962658/UDP.o ${OBJECTDIR}/_ext/1954962658/UDPPerformanceTest.o ${OBJECTDIR}/_ext/549097302/usb_host.o ${OBJECTDIR}/_ext/172487899/usb_host_msd.o ${OBJECTDIR}/_ext/172487899/usb_host_msd_scsi.o ${OBJECTDIR}/_ext/1472/CustomHTTPApp.o ${OBJECTDIR}/_ext/1472/CustomSSLCert.o ${OBJECTDIR}/_ext/1788384718/FSIO.o ${OBJECTDIR}/_ext/1472/MainDemo.o ${OBJECTDIR}/_ext/1472/usb_config.o
POSSIBLE_DEPFILES=${OBJECTDIR}/_ext/1472/BerkeleyTCPClientDemo.o.d ${OBJECTDIR}/_ext/1472/BerkeleyTCPServerDemo.o.d ${OBJECTDIR}/_ext/1472/BerkeleyUDPClientDemo.o.d ${OBJECTDIR}/_ext/1472/GenericTCPClient.o.d ${OBJECTDIR}/_ext/1472/GenericTCPServer.o.d ${OBJECTDIR}/_ext/1472/PingDemo.o.d ${OBJECTDIR}/_ext/1472/SMTPDemo.o.d ${OBJECTDIR}/_ext/1472/UARTConfig.o.d ${OBJECTDIR}/_ext/1954962658/ARCFOUR.o.d ${OBJECTDIR}/_ext/1954962658/ARP.o.d ${OBJECTDIR}/_ext/1954962658/Announce.o.d ${OBJECTDIR}/_ext/1954962658/AutoIP.o.d ${OBJECTDIR}/_ext/1954962658/BerkeleyAPI.o.d ${OBJECTDIR}/_ext/1954962658/BigInt.o.d ${OBJECTDIR}/_ext/1954962658/DHCP.o.d ${OBJECTDIR}/_ext/1954962658/DHCPs.o.d ${OBJECTDIR}/_ext/1954962658/DNS.o.d ${OBJECTDIR}/_ext/1954962658/DNSs.o.d ${OBJECTDIR}/_ext/1954962658/Delay.o.d ${OBJECTDIR}/_ext/1954962658/DynDNS.o.d ${OBJECTDIR}/_ext/1954962658/ENC28J60.o.d ${OBJECTDIR}/_ext/1954962658/ENCX24J600.o.d ${OBJECTDIR}/_ext/1954962658/FTP.o.d ${OBJECTDIR}/_ext/1954962658/FileSystem.o.d ${OBJECTDIR}/_ext/1472/HTTP2_MDD.o.d ${OBJECTDIR}/_ext/1954962658/Hashes.o.d ${OBJECTDIR}/_ext/1954962658/Helpers.o.d ${OBJECTDIR}/_ext/1954962658/ICMP.o.d ${OBJECTDIR}/_ext/1954962658/IP.o.d ${OBJECTDIR}/_ext/1954962658/LCDBlocking.o.d ${OBJECTDIR}/_ext/1954962658/MPFS2.o.d ${OBJECTDIR}/_ext/1954962658/NBNS.o.d ${OBJECTDIR}/_ext/1954962658/RSA.o.d ${OBJECTDIR}/_ext/1954962658/Random.o.d ${OBJECTDIR}/_ext/1954962658/Reboot.o.d ${OBJECTDIR}/_ext/1954962658/SMTP.o.d ${OBJECTDIR}/_ext/1954962658/SNMP.o.d ${OBJECTDIR}/_ext/1954962658/SNTP.o.d ${OBJECTDIR}/_ext/1954962658/SPIEEPROM.o.d ${OBJECTDIR}/_ext/1954962658/SPIFlash.o.d ${OBJECTDIR}/_ext/1954962658/SPIRAM.o.d ${OBJECTDIR}/_ext/1954962658/SSL.o.d ${OBJECTDIR}/_ext/1954962658/StackTsk.o.d ${OBJECTDIR}/_ext/1954962658/TCP.o.d ${OBJECTDIR}/_ext/1954962658/TCPPerformanceTest.o.d ${OBJECTDIR}/_ext/1954962658/TFTPc.o.d ${OBJECTDIR}/_ext/1954962658/Telnet.o.d ${OBJECTDIR}/_ext/1954962658/Tick.o.d ${OBJECTDIR}/_ext/1954962658/UART.o.d ${OBJECTDIR}/_ext/1954962658/UART2TCPBridge.o.d ${OBJECTDIR}/_ext/1954962658/UDP.o.d ${OBJECTDIR}/_ext/1954962658/UDPPerformanceTest.o.d ${OBJECTDIR}/_ext/549097302/usb_host.o.d ${OBJECTDIR}/_ext/172487899/usb_host_msd.o.d ${OBJECTDIR}/_ext/172487899/usb_host_msd_scsi.o.d ${OBJECTDIR}/_ext/1472/CustomHTTPApp.o.d ${OBJECTDIR}/_ext/1472/CustomSSLCert.o.d ${OBJECTDIR}/_ext/1788384718/FSIO.o.d ${OBJECTDIR}/_ext/1472/MainDemo.o.d ${OBJECTDIR}/_ext/1472/usb_config.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/_ext/1472/BerkeleyTCPClientDemo.o ${OBJECTDIR}/_ext/1472/BerkeleyTCPServerDemo.o ${OBJECTDIR}/_ext/1472/BerkeleyUDPClientDemo.o ${OBJECTDIR}/_ext/1472/GenericTCPClient.o ${OBJECTDIR}/_ext/1472/GenericTCPServer.o ${OBJECTDIR}/_ext/1472/PingDemo.o ${OBJECTDIR}/_ext/1472/SMTPDemo.o ${OBJECTDIR}/_ext/1472/UARTConfig.o ${OBJECTDIR}/_ext/1954962658/ARCFOUR.o ${OBJECTDIR}/_ext/1954962658/ARP.o ${OBJECTDIR}/_ext/1954962658/Announce.o ${OBJECTDIR}/_ext/1954962658/AutoIP.o ${OBJECTDIR}/_ext/1954962658/BerkeleyAPI.o ${OBJECTDIR}/_ext/1954962658/BigInt.o ${OBJECTDIR}/_ext/1954962658/DHCP.o ${OBJECTDIR}/_ext/1954962658/DHCPs.o ${OBJECTDIR}/_ext/1954962658/DNS.o ${OBJECTDIR}/_ext/1954962658/DNSs.o ${OBJECTDIR}/_ext/1954962658/Delay.o ${OBJECTDIR}/_ext/1954962658/DynDNS.o ${OBJECTDIR}/_ext/1954962658/ENC28J60.o ${OBJECTDIR}/_ext/1954962658/ENCX24J600.o ${OBJECTDIR}/_ext/1954962658/FTP.o ${OBJECTDIR}/_ext/1954962658/FileSystem.o ${OBJECTDIR}/_ext/1472/HTTP2_MDD.o ${OBJECTDIR}/_ext/1954962658/Hashes.o ${OBJECTDIR}/_ext/1954962658/Helpers.o ${OBJECTDIR}/_ext/1954962658/ICMP.o ${OBJECTDIR}/_ext/1954962658/IP.o ${OBJECTDIR}/_ext/1954962658/LCDBlocking.o ${OBJECTDIR}/_ext/1954962658/MPFS2.o ${OBJECTDIR}/_ext/1954962658/NBNS.o ${OBJECTDIR}/_ext/1954962658/RSA.o ${OBJECTDIR}/_ext/1954962658/Random.o ${OBJECTDIR}/_ext/1954962658/Reboot.o ${OBJECTDIR}/_ext/1954962658/SMTP.o ${OBJECTDIR}/_ext/1954962658/SNMP.o ${OBJECTDIR}/_ext/1954962658/SNTP.o ${OBJECTDIR}/_ext/1954962658/SPIEEPROM.o ${OBJECTDIR}/_ext/1954962658/SPIFlash.o ${OBJECTDIR}/_ext/1954962658/SPIRAM.o ${OBJECTDIR}/_ext/1954962658/SSL.o ${OBJECTDIR}/_ext/1954962658/StackTsk.o ${OBJECTDIR}/_ext/1954962658/TCP.o ${OBJECTDIR}/_ext/1954962658/TCPPerformanceTest.o ${OBJECTDIR}/_ext/1954962658/TFTPc.o ${OBJECTDIR}/_ext/1954962658/Telnet.o ${OBJECTDIR}/_ext/1954962658/Tick.o ${OBJECTDIR}/_ext/1954962658/UART.o ${OBJECTDIR}/_ext/1954962658/UART2TCPBridge.o ${OBJECTDIR}/_ext/1954962658/UDP.o ${OBJECTDIR}/_ext/1954962658/UDPPerformanceTest.o ${OBJECTDIR}/_ext/549097302/usb_host.o ${OBJECTDIR}/_ext/172487899/usb_host_msd.o ${OBJECTDIR}/_ext/172487899/usb_host_msd_scsi.o ${OBJECTDIR}/_ext/1472/CustomHTTPApp.o ${OBJECTDIR}/_ext/1472/CustomSSLCert.o ${OBJECTDIR}/_ext/1788384718/FSIO.o ${OBJECTDIR}/_ext/1472/MainDemo.o ${OBJECTDIR}/_ext/1472/usb_config.o

# Source Files
SOURCEFILES=../BerkeleyTCPClientDemo.c ../BerkeleyTCPServerDemo.c ../BerkeleyUDPClientDemo.c ../GenericTCPClient.c ../GenericTCPServer.c ../PingDemo.c ../SMTPDemo.c ../UARTConfig.c ../../../Microchip/TCPIP Stack/ARCFOUR.c ../../../Microchip/TCPIP Stack/ARP.c ../../../Microchip/TCPIP Stack/Announce.c ../../../Microchip/TCPIP Stack/AutoIP.c ../../../Microchip/TCPIP Stack/BerkeleyAPI.c ../../../Microchip/TCPIP Stack/BigInt.c ../../../Microchip/TCPIP Stack/DHCP.c ../../../Microchip/TCPIP Stack/DHCPs.c ../../../Microchip/TCPIP Stack/DNS.c ../../../Microchip/TCPIP Stack/DNSs.c ../../../Microchip/TCPIP Stack/Delay.c ../../../Microchip/TCPIP Stack/DynDNS.c ../../../Microchip/TCPIP Stack/ENC28J60.c ../../../Microchip/TCPIP Stack/ENCX24J600.c ../../../Microchip/TCPIP Stack/FTP.c ../../../Microchip/TCPIP Stack/FileSystem.c ../HTTP2_MDD.c ../../../Microchip/TCPIP Stack/Hashes.c ../../../Microchip/TCPIP Stack/Helpers.c ../../../Microchip/TCPIP Stack/ICMP.c ../../../Microchip/TCPIP Stack/IP.c ../../../Microchip/TCPIP Stack/LCDBlocking.c ../../../Microchip/TCPIP Stack/MPFS2.c ../../../Microchip/TCPIP Stack/NBNS.c ../../../Microchip/TCPIP Stack/RSA.c ../../../Microchip/TCPIP Stack/Random.c ../../../Microchip/TCPIP Stack/Reboot.c ../../../Microchip/TCPIP Stack/SMTP.c ../../../Microchip/TCPIP Stack/SNMP.c ../../../Microchip/TCPIP Stack/SNTP.c ../../../Microchip/TCPIP Stack/SPIEEPROM.c ../../../Microchip/TCPIP Stack/SPIFlash.c ../../../Microchip/TCPIP Stack/SPIRAM.c ../../../Microchip/TCPIP Stack/SSL.c ../../../Microchip/TCPIP Stack/StackTsk.c ../../../Microchip/TCPIP Stack/TCP.c ../../../Microchip/TCPIP Stack/TCPPerformanceTest.c ../../../Microchip/TCPIP Stack/TFTPc.c ../../../Microchip/TCPIP Stack/Telnet.c ../../../Microchip/TCPIP Stack/Tick.c ../../../Microchip/TCPIP Stack/UART.c ../../../Microchip/TCPIP Stack/UART2TCPBridge.c ../../../Microchip/TCPIP Stack/UDP.c ../../../Microchip/TCPIP Stack/UDPPerformanceTest.c ../../../Microchip/USB/usb_host.c ../../../Microchip/USB/MSD Host Driver/usb_host_msd.c ../../../Microchip/USB/MSD Host Driver/usb_host_msd_scsi.c ../CustomHTTPApp.c ../CustomSSLCert.c ../../../Microchip/MDD File System/FSIO.c ../MainDemo.c ../usb_config.c


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
	${MAKE}  -f nbproject/Makefile-XC16-USB_Thumb_Drive.mk dist/${CND_CONF}/${IMAGE_TYPE}/MPLAB.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=24FJ256GB410
MP_LINKER_FILE_OPTION=,--script=p24FJ256GB410.gld
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/_ext/1472/BerkeleyTCPClientDemo.o: ../BerkeleyTCPClientDemo.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/BerkeleyTCPClientDemo.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/BerkeleyTCPClientDemo.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../BerkeleyTCPClientDemo.c  -o ${OBJECTDIR}/_ext/1472/BerkeleyTCPClientDemo.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/BerkeleyTCPClientDemo.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -DXPRJ_XC16-USB_Thumb_Drive=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -Os -I".." -I"../../Microchip/Include" -I"../../../Microchip/Include" -I"../../../Microchip/Include/TCPIP Stack" -I"../../../Microchip/Include/USB" -I"../../../Microchip/Include/MDD File System" -msmart-io=1 -Wall -msfr-warn=off   -fno-ivopts
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/BerkeleyTCPClientDemo.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1472/BerkeleyTCPServerDemo.o: ../BerkeleyTCPServerDemo.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/BerkeleyTCPServerDemo.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/BerkeleyTCPServerDemo.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../BerkeleyTCPServerDemo.c  -o ${OBJECTDIR}/_ext/1472/BerkeleyTCPServerDemo.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/BerkeleyTCPServerDemo.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -DXPRJ_XC16-USB_Thumb_Drive=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -Os -I".." -I"../../Microchip/Include" -I"../../../Microchip/Include" -I"../../../Microchip/Include/TCPIP Stack" -I"../../../Microchip/Include/USB" -I"../../../Microchip/Include/MDD File System" -msmart-io=1 -Wall -msfr-warn=off   -fno-ivopts
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/BerkeleyTCPServerDemo.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1472/BerkeleyUDPClientDemo.o: ../BerkeleyUDPClientDemo.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/BerkeleyUDPClientDemo.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/BerkeleyUDPClientDemo.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../BerkeleyUDPClientDemo.c  -o ${OBJECTDIR}/_ext/1472/BerkeleyUDPClientDemo.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/BerkeleyUDPClientDemo.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -DXPRJ_XC16-USB_Thumb_Drive=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -Os -I".." -I"../../Microchip/Include" -I"../../../Microchip/Include" -I"../../../Microchip/Include/TCPIP Stack" -I"../../../Microchip/Include/USB" -I"../../../Microchip/Include/MDD File System" -msmart-io=1 -Wall -msfr-warn=off   -fno-ivopts
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/BerkeleyUDPClientDemo.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1472/GenericTCPClient.o: ../GenericTCPClient.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/GenericTCPClient.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/GenericTCPClient.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../GenericTCPClient.c  -o ${OBJECTDIR}/_ext/1472/GenericTCPClient.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/GenericTCPClient.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -DXPRJ_XC16-USB_Thumb_Drive=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -Os -I".." -I"../../Microchip/Include" -I"../../../Microchip/Include" -I"../../../Microchip/Include/TCPIP Stack" -I"../../../Microchip/Include/USB" -I"../../../Microchip/Include/MDD File System" -msmart-io=1 -Wall -msfr-warn=off   -fno-ivopts
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/GenericTCPClient.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1472/GenericTCPServer.o: ../GenericTCPServer.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/GenericTCPServer.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/GenericTCPServer.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../GenericTCPServer.c  -o ${OBJECTDIR}/_ext/1472/GenericTCPServer.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/GenericTCPServer.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -DXPRJ_XC16-USB_Thumb_Drive=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -Os -I".." -I"../../Microchip/Include" -I"../../../Microchip/Include" -I"../../../Microchip/Include/TCPIP Stack" -I"../../../Microchip/Include/USB" -I"../../../Microchip/Include/MDD File System" -msmart-io=1 -Wall -msfr-warn=off   -fno-ivopts
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/GenericTCPServer.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1472/PingDemo.o: ../PingDemo.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/PingDemo.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/PingDemo.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../PingDemo.c  -o ${OBJECTDIR}/_ext/1472/PingDemo.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/PingDemo.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -DXPRJ_XC16-USB_Thumb_Drive=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -Os -I".." -I"../../Microchip/Include" -I"../../../Microchip/Include" -I"../../../Microchip/Include/TCPIP Stack" -I"../../../Microchip/Include/USB" -I"../../../Microchip/Include/MDD File System" -msmart-io=1 -Wall -msfr-warn=off   -fno-ivopts
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/PingDemo.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1472/SMTPDemo.o: ../SMTPDemo.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/SMTPDemo.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/SMTPDemo.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../SMTPDemo.c  -o ${OBJECTDIR}/_ext/1472/SMTPDemo.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/SMTPDemo.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -DXPRJ_XC16-USB_Thumb_Drive=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -Os -I".." -I"../../Microchip/Include" -I"../../../Microchip/Include" -I"../../../Microchip/Include/TCPIP Stack" -I"../../../Microchip/Include/USB" -I"../../../Microchip/Include/MDD File System" -msmart-io=1 -Wall -msfr-warn=off   -fno-ivopts
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/SMTPDemo.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1472/UARTConfig.o: ../UARTConfig.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/UARTConfig.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/UARTConfig.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../UARTConfig.c  -o ${OBJECTDIR}/_ext/1472/UARTConfig.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/UARTConfig.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -DXPRJ_XC16-USB_Thumb_Drive=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -Os -I".." -I"../../Microchip/Include" -I"../../../Microchip/Include" -I"../../../Microchip/Include/TCPIP Stack" -I"../../../Microchip/Include/USB" -I"../../../Microchip/Include/MDD File System" -msmart-io=1 -Wall -msfr-warn=off   -fno-ivopts
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/UARTConfig.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1954962658/ARCFOUR.o: ../../../Microchip/TCPIP\ Stack/ARCFOUR.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1954962658" 
	@${RM} ${OBJECTDIR}/_ext/1954962658/ARCFOUR.o.d 
	@${RM} ${OBJECTDIR}/_ext/1954962658/ARCFOUR.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  "../../../Microchip/TCPIP Stack/ARCFOUR.c"  -o ${OBJECTDIR}/_ext/1954962658/ARCFOUR.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1954962658/ARCFOUR.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -DXPRJ_XC16-USB_Thumb_Drive=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -Os -I".." -I"../../Microchip/Include" -I"../../../Microchip/Include" -I"../../../Microchip/Include/TCPIP Stack" -I"../../../Microchip/Include/USB" -I"../../../Microchip/Include/MDD File System" -msmart-io=1 -Wall -msfr-warn=off   -fno-ivopts
	@${FIXDEPS} "${OBJECTDIR}/_ext/1954962658/ARCFOUR.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1954962658/ARP.o: ../../../Microchip/TCPIP\ Stack/ARP.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1954962658" 
	@${RM} ${OBJECTDIR}/_ext/1954962658/ARP.o.d 
	@${RM} ${OBJECTDIR}/_ext/1954962658/ARP.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  "../../../Microchip/TCPIP Stack/ARP.c"  -o ${OBJECTDIR}/_ext/1954962658/ARP.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1954962658/ARP.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -DXPRJ_XC16-USB_Thumb_Drive=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -Os -I".." -I"../../Microchip/Include" -I"../../../Microchip/Include" -I"../../../Microchip/Include/TCPIP Stack" -I"../../../Microchip/Include/USB" -I"../../../Microchip/Include/MDD File System" -msmart-io=1 -Wall -msfr-warn=off   -fno-ivopts
	@${FIXDEPS} "${OBJECTDIR}/_ext/1954962658/ARP.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1954962658/Announce.o: ../../../Microchip/TCPIP\ Stack/Announce.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1954962658" 
	@${RM} ${OBJECTDIR}/_ext/1954962658/Announce.o.d 
	@${RM} ${OBJECTDIR}/_ext/1954962658/Announce.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  "../../../Microchip/TCPIP Stack/Announce.c"  -o ${OBJECTDIR}/_ext/1954962658/Announce.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1954962658/Announce.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -DXPRJ_XC16-USB_Thumb_Drive=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -Os -I".." -I"../../Microchip/Include" -I"../../../Microchip/Include" -I"../../../Microchip/Include/TCPIP Stack" -I"../../../Microchip/Include/USB" -I"../../../Microchip/Include/MDD File System" -msmart-io=1 -Wall -msfr-warn=off   -fno-ivopts
	@${FIXDEPS} "${OBJECTDIR}/_ext/1954962658/Announce.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1954962658/AutoIP.o: ../../../Microchip/TCPIP\ Stack/AutoIP.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1954962658" 
	@${RM} ${OBJECTDIR}/_ext/1954962658/AutoIP.o.d 
	@${RM} ${OBJECTDIR}/_ext/1954962658/AutoIP.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  "../../../Microchip/TCPIP Stack/AutoIP.c"  -o ${OBJECTDIR}/_ext/1954962658/AutoIP.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1954962658/AutoIP.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -DXPRJ_XC16-USB_Thumb_Drive=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -Os -I".." -I"../../Microchip/Include" -I"../../../Microchip/Include" -I"../../../Microchip/Include/TCPIP Stack" -I"../../../Microchip/Include/USB" -I"../../../Microchip/Include/MDD File System" -msmart-io=1 -Wall -msfr-warn=off   -fno-ivopts
	@${FIXDEPS} "${OBJECTDIR}/_ext/1954962658/AutoIP.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1954962658/BerkeleyAPI.o: ../../../Microchip/TCPIP\ Stack/BerkeleyAPI.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1954962658" 
	@${RM} ${OBJECTDIR}/_ext/1954962658/BerkeleyAPI.o.d 
	@${RM} ${OBJECTDIR}/_ext/1954962658/BerkeleyAPI.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  "../../../Microchip/TCPIP Stack/BerkeleyAPI.c"  -o ${OBJECTDIR}/_ext/1954962658/BerkeleyAPI.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1954962658/BerkeleyAPI.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -DXPRJ_XC16-USB_Thumb_Drive=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -Os -I".." -I"../../Microchip/Include" -I"../../../Microchip/Include" -I"../../../Microchip/Include/TCPIP Stack" -I"../../../Microchip/Include/USB" -I"../../../Microchip/Include/MDD File System" -msmart-io=1 -Wall -msfr-warn=off   -fno-ivopts
	@${FIXDEPS} "${OBJECTDIR}/_ext/1954962658/BerkeleyAPI.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1954962658/BigInt.o: ../../../Microchip/TCPIP\ Stack/BigInt.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1954962658" 
	@${RM} ${OBJECTDIR}/_ext/1954962658/BigInt.o.d 
	@${RM} ${OBJECTDIR}/_ext/1954962658/BigInt.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  "../../../Microchip/TCPIP Stack/BigInt.c"  -o ${OBJECTDIR}/_ext/1954962658/BigInt.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1954962658/BigInt.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -DXPRJ_XC16-USB_Thumb_Drive=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -Os -I".." -I"../../Microchip/Include" -I"../../../Microchip/Include" -I"../../../Microchip/Include/TCPIP Stack" -I"../../../Microchip/Include/USB" -I"../../../Microchip/Include/MDD File System" -msmart-io=1 -Wall -msfr-warn=off   -fno-ivopts
	@${FIXDEPS} "${OBJECTDIR}/_ext/1954962658/BigInt.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1954962658/DHCP.o: ../../../Microchip/TCPIP\ Stack/DHCP.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1954962658" 
	@${RM} ${OBJECTDIR}/_ext/1954962658/DHCP.o.d 
	@${RM} ${OBJECTDIR}/_ext/1954962658/DHCP.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  "../../../Microchip/TCPIP Stack/DHCP.c"  -o ${OBJECTDIR}/_ext/1954962658/DHCP.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1954962658/DHCP.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -DXPRJ_XC16-USB_Thumb_Drive=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -Os -I".." -I"../../Microchip/Include" -I"../../../Microchip/Include" -I"../../../Microchip/Include/TCPIP Stack" -I"../../../Microchip/Include/USB" -I"../../../Microchip/Include/MDD File System" -msmart-io=1 -Wall -msfr-warn=off   -fno-ivopts
	@${FIXDEPS} "${OBJECTDIR}/_ext/1954962658/DHCP.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1954962658/DHCPs.o: ../../../Microchip/TCPIP\ Stack/DHCPs.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1954962658" 
	@${RM} ${OBJECTDIR}/_ext/1954962658/DHCPs.o.d 
	@${RM} ${OBJECTDIR}/_ext/1954962658/DHCPs.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  "../../../Microchip/TCPIP Stack/DHCPs.c"  -o ${OBJECTDIR}/_ext/1954962658/DHCPs.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1954962658/DHCPs.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -DXPRJ_XC16-USB_Thumb_Drive=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -Os -I".." -I"../../Microchip/Include" -I"../../../Microchip/Include" -I"../../../Microchip/Include/TCPIP Stack" -I"../../../Microchip/Include/USB" -I"../../../Microchip/Include/MDD File System" -msmart-io=1 -Wall -msfr-warn=off   -fno-ivopts
	@${FIXDEPS} "${OBJECTDIR}/_ext/1954962658/DHCPs.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1954962658/DNS.o: ../../../Microchip/TCPIP\ Stack/DNS.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1954962658" 
	@${RM} ${OBJECTDIR}/_ext/1954962658/DNS.o.d 
	@${RM} ${OBJECTDIR}/_ext/1954962658/DNS.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  "../../../Microchip/TCPIP Stack/DNS.c"  -o ${OBJECTDIR}/_ext/1954962658/DNS.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1954962658/DNS.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -DXPRJ_XC16-USB_Thumb_Drive=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -Os -I".." -I"../../Microchip/Include" -I"../../../Microchip/Include" -I"../../../Microchip/Include/TCPIP Stack" -I"../../../Microchip/Include/USB" -I"../../../Microchip/Include/MDD File System" -msmart-io=1 -Wall -msfr-warn=off   -fno-ivopts
	@${FIXDEPS} "${OBJECTDIR}/_ext/1954962658/DNS.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1954962658/DNSs.o: ../../../Microchip/TCPIP\ Stack/DNSs.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1954962658" 
	@${RM} ${OBJECTDIR}/_ext/1954962658/DNSs.o.d 
	@${RM} ${OBJECTDIR}/_ext/1954962658/DNSs.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  "../../../Microchip/TCPIP Stack/DNSs.c"  -o ${OBJECTDIR}/_ext/1954962658/DNSs.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1954962658/DNSs.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -DXPRJ_XC16-USB_Thumb_Drive=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -Os -I".." -I"../../Microchip/Include" -I"../../../Microchip/Include" -I"../../../Microchip/Include/TCPIP Stack" -I"../../../Microchip/Include/USB" -I"../../../Microchip/Include/MDD File System" -msmart-io=1 -Wall -msfr-warn=off   -fno-ivopts
	@${FIXDEPS} "${OBJECTDIR}/_ext/1954962658/DNSs.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1954962658/Delay.o: ../../../Microchip/TCPIP\ Stack/Delay.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1954962658" 
	@${RM} ${OBJECTDIR}/_ext/1954962658/Delay.o.d 
	@${RM} ${OBJECTDIR}/_ext/1954962658/Delay.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  "../../../Microchip/TCPIP Stack/Delay.c"  -o ${OBJECTDIR}/_ext/1954962658/Delay.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1954962658/Delay.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -DXPRJ_XC16-USB_Thumb_Drive=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -Os -I".." -I"../../Microchip/Include" -I"../../../Microchip/Include" -I"../../../Microchip/Include/TCPIP Stack" -I"../../../Microchip/Include/USB" -I"../../../Microchip/Include/MDD File System" -msmart-io=1 -Wall -msfr-warn=off   -fno-ivopts
	@${FIXDEPS} "${OBJECTDIR}/_ext/1954962658/Delay.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1954962658/DynDNS.o: ../../../Microchip/TCPIP\ Stack/DynDNS.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1954962658" 
	@${RM} ${OBJECTDIR}/_ext/1954962658/DynDNS.o.d 
	@${RM} ${OBJECTDIR}/_ext/1954962658/DynDNS.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  "../../../Microchip/TCPIP Stack/DynDNS.c"  -o ${OBJECTDIR}/_ext/1954962658/DynDNS.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1954962658/DynDNS.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -DXPRJ_XC16-USB_Thumb_Drive=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -Os -I".." -I"../../Microchip/Include" -I"../../../Microchip/Include" -I"../../../Microchip/Include/TCPIP Stack" -I"../../../Microchip/Include/USB" -I"../../../Microchip/Include/MDD File System" -msmart-io=1 -Wall -msfr-warn=off   -fno-ivopts
	@${FIXDEPS} "${OBJECTDIR}/_ext/1954962658/DynDNS.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1954962658/ENC28J60.o: ../../../Microchip/TCPIP\ Stack/ENC28J60.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1954962658" 
	@${RM} ${OBJECTDIR}/_ext/1954962658/ENC28J60.o.d 
	@${RM} ${OBJECTDIR}/_ext/1954962658/ENC28J60.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  "../../../Microchip/TCPIP Stack/ENC28J60.c"  -o ${OBJECTDIR}/_ext/1954962658/ENC28J60.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1954962658/ENC28J60.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -DXPRJ_XC16-USB_Thumb_Drive=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -Os -I".." -I"../../Microchip/Include" -I"../../../Microchip/Include" -I"../../../Microchip/Include/TCPIP Stack" -I"../../../Microchip/Include/USB" -I"../../../Microchip/Include/MDD File System" -msmart-io=1 -Wall -msfr-warn=off   -fno-ivopts
	@${FIXDEPS} "${OBJECTDIR}/_ext/1954962658/ENC28J60.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1954962658/ENCX24J600.o: ../../../Microchip/TCPIP\ Stack/ENCX24J600.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1954962658" 
	@${RM} ${OBJECTDIR}/_ext/1954962658/ENCX24J600.o.d 
	@${RM} ${OBJECTDIR}/_ext/1954962658/ENCX24J600.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  "../../../Microchip/TCPIP Stack/ENCX24J600.c"  -o ${OBJECTDIR}/_ext/1954962658/ENCX24J600.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1954962658/ENCX24J600.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -DXPRJ_XC16-USB_Thumb_Drive=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -Os -I".." -I"../../Microchip/Include" -I"../../../Microchip/Include" -I"../../../Microchip/Include/TCPIP Stack" -I"../../../Microchip/Include/USB" -I"../../../Microchip/Include/MDD File System" -msmart-io=1 -Wall -msfr-warn=off   -fno-ivopts
	@${FIXDEPS} "${OBJECTDIR}/_ext/1954962658/ENCX24J600.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1954962658/FTP.o: ../../../Microchip/TCPIP\ Stack/FTP.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1954962658" 
	@${RM} ${OBJECTDIR}/_ext/1954962658/FTP.o.d 
	@${RM} ${OBJECTDIR}/_ext/1954962658/FTP.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  "../../../Microchip/TCPIP Stack/FTP.c"  -o ${OBJECTDIR}/_ext/1954962658/FTP.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1954962658/FTP.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -DXPRJ_XC16-USB_Thumb_Drive=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -Os -I".." -I"../../Microchip/Include" -I"../../../Microchip/Include" -I"../../../Microchip/Include/TCPIP Stack" -I"../../../Microchip/Include/USB" -I"../../../Microchip/Include/MDD File System" -msmart-io=1 -Wall -msfr-warn=off   -fno-ivopts
	@${FIXDEPS} "${OBJECTDIR}/_ext/1954962658/FTP.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1954962658/FileSystem.o: ../../../Microchip/TCPIP\ Stack/FileSystem.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1954962658" 
	@${RM} ${OBJECTDIR}/_ext/1954962658/FileSystem.o.d 
	@${RM} ${OBJECTDIR}/_ext/1954962658/FileSystem.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  "../../../Microchip/TCPIP Stack/FileSystem.c"  -o ${OBJECTDIR}/_ext/1954962658/FileSystem.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1954962658/FileSystem.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -DXPRJ_XC16-USB_Thumb_Drive=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -Os -I".." -I"../../Microchip/Include" -I"../../../Microchip/Include" -I"../../../Microchip/Include/TCPIP Stack" -I"../../../Microchip/Include/USB" -I"../../../Microchip/Include/MDD File System" -msmart-io=1 -Wall -msfr-warn=off   -fno-ivopts
	@${FIXDEPS} "${OBJECTDIR}/_ext/1954962658/FileSystem.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1472/HTTP2_MDD.o: ../HTTP2_MDD.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/HTTP2_MDD.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/HTTP2_MDD.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../HTTP2_MDD.c  -o ${OBJECTDIR}/_ext/1472/HTTP2_MDD.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/HTTP2_MDD.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -DXPRJ_XC16-USB_Thumb_Drive=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -Os -I".." -I"../../Microchip/Include" -I"../../../Microchip/Include" -I"../../../Microchip/Include/TCPIP Stack" -I"../../../Microchip/Include/USB" -I"../../../Microchip/Include/MDD File System" -msmart-io=1 -Wall -msfr-warn=off   -fno-ivopts
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/HTTP2_MDD.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1954962658/Hashes.o: ../../../Microchip/TCPIP\ Stack/Hashes.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1954962658" 
	@${RM} ${OBJECTDIR}/_ext/1954962658/Hashes.o.d 
	@${RM} ${OBJECTDIR}/_ext/1954962658/Hashes.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  "../../../Microchip/TCPIP Stack/Hashes.c"  -o ${OBJECTDIR}/_ext/1954962658/Hashes.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1954962658/Hashes.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -DXPRJ_XC16-USB_Thumb_Drive=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -Os -I".." -I"../../Microchip/Include" -I"../../../Microchip/Include" -I"../../../Microchip/Include/TCPIP Stack" -I"../../../Microchip/Include/USB" -I"../../../Microchip/Include/MDD File System" -msmart-io=1 -Wall -msfr-warn=off   -fno-ivopts
	@${FIXDEPS} "${OBJECTDIR}/_ext/1954962658/Hashes.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1954962658/Helpers.o: ../../../Microchip/TCPIP\ Stack/Helpers.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1954962658" 
	@${RM} ${OBJECTDIR}/_ext/1954962658/Helpers.o.d 
	@${RM} ${OBJECTDIR}/_ext/1954962658/Helpers.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  "../../../Microchip/TCPIP Stack/Helpers.c"  -o ${OBJECTDIR}/_ext/1954962658/Helpers.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1954962658/Helpers.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -DXPRJ_XC16-USB_Thumb_Drive=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -Os -I".." -I"../../Microchip/Include" -I"../../../Microchip/Include" -I"../../../Microchip/Include/TCPIP Stack" -I"../../../Microchip/Include/USB" -I"../../../Microchip/Include/MDD File System" -msmart-io=1 -Wall -msfr-warn=off   -fno-ivopts
	@${FIXDEPS} "${OBJECTDIR}/_ext/1954962658/Helpers.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1954962658/ICMP.o: ../../../Microchip/TCPIP\ Stack/ICMP.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1954962658" 
	@${RM} ${OBJECTDIR}/_ext/1954962658/ICMP.o.d 
	@${RM} ${OBJECTDIR}/_ext/1954962658/ICMP.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  "../../../Microchip/TCPIP Stack/ICMP.c"  -o ${OBJECTDIR}/_ext/1954962658/ICMP.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1954962658/ICMP.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -DXPRJ_XC16-USB_Thumb_Drive=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -Os -I".." -I"../../Microchip/Include" -I"../../../Microchip/Include" -I"../../../Microchip/Include/TCPIP Stack" -I"../../../Microchip/Include/USB" -I"../../../Microchip/Include/MDD File System" -msmart-io=1 -Wall -msfr-warn=off   -fno-ivopts
	@${FIXDEPS} "${OBJECTDIR}/_ext/1954962658/ICMP.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1954962658/IP.o: ../../../Microchip/TCPIP\ Stack/IP.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1954962658" 
	@${RM} ${OBJECTDIR}/_ext/1954962658/IP.o.d 
	@${RM} ${OBJECTDIR}/_ext/1954962658/IP.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  "../../../Microchip/TCPIP Stack/IP.c"  -o ${OBJECTDIR}/_ext/1954962658/IP.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1954962658/IP.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -DXPRJ_XC16-USB_Thumb_Drive=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -Os -I".." -I"../../Microchip/Include" -I"../../../Microchip/Include" -I"../../../Microchip/Include/TCPIP Stack" -I"../../../Microchip/Include/USB" -I"../../../Microchip/Include/MDD File System" -msmart-io=1 -Wall -msfr-warn=off   -fno-ivopts
	@${FIXDEPS} "${OBJECTDIR}/_ext/1954962658/IP.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1954962658/LCDBlocking.o: ../../../Microchip/TCPIP\ Stack/LCDBlocking.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1954962658" 
	@${RM} ${OBJECTDIR}/_ext/1954962658/LCDBlocking.o.d 
	@${RM} ${OBJECTDIR}/_ext/1954962658/LCDBlocking.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  "../../../Microchip/TCPIP Stack/LCDBlocking.c"  -o ${OBJECTDIR}/_ext/1954962658/LCDBlocking.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1954962658/LCDBlocking.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -DXPRJ_XC16-USB_Thumb_Drive=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -Os -I".." -I"../../Microchip/Include" -I"../../../Microchip/Include" -I"../../../Microchip/Include/TCPIP Stack" -I"../../../Microchip/Include/USB" -I"../../../Microchip/Include/MDD File System" -msmart-io=1 -Wall -msfr-warn=off   -fno-ivopts
	@${FIXDEPS} "${OBJECTDIR}/_ext/1954962658/LCDBlocking.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1954962658/MPFS2.o: ../../../Microchip/TCPIP\ Stack/MPFS2.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1954962658" 
	@${RM} ${OBJECTDIR}/_ext/1954962658/MPFS2.o.d 
	@${RM} ${OBJECTDIR}/_ext/1954962658/MPFS2.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  "../../../Microchip/TCPIP Stack/MPFS2.c"  -o ${OBJECTDIR}/_ext/1954962658/MPFS2.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1954962658/MPFS2.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -DXPRJ_XC16-USB_Thumb_Drive=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -Os -I".." -I"../../Microchip/Include" -I"../../../Microchip/Include" -I"../../../Microchip/Include/TCPIP Stack" -I"../../../Microchip/Include/USB" -I"../../../Microchip/Include/MDD File System" -msmart-io=1 -Wall -msfr-warn=off   -fno-ivopts
	@${FIXDEPS} "${OBJECTDIR}/_ext/1954962658/MPFS2.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1954962658/NBNS.o: ../../../Microchip/TCPIP\ Stack/NBNS.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1954962658" 
	@${RM} ${OBJECTDIR}/_ext/1954962658/NBNS.o.d 
	@${RM} ${OBJECTDIR}/_ext/1954962658/NBNS.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  "../../../Microchip/TCPIP Stack/NBNS.c"  -o ${OBJECTDIR}/_ext/1954962658/NBNS.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1954962658/NBNS.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -DXPRJ_XC16-USB_Thumb_Drive=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -Os -I".." -I"../../Microchip/Include" -I"../../../Microchip/Include" -I"../../../Microchip/Include/TCPIP Stack" -I"../../../Microchip/Include/USB" -I"../../../Microchip/Include/MDD File System" -msmart-io=1 -Wall -msfr-warn=off   -fno-ivopts
	@${FIXDEPS} "${OBJECTDIR}/_ext/1954962658/NBNS.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1954962658/RSA.o: ../../../Microchip/TCPIP\ Stack/RSA.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1954962658" 
	@${RM} ${OBJECTDIR}/_ext/1954962658/RSA.o.d 
	@${RM} ${OBJECTDIR}/_ext/1954962658/RSA.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  "../../../Microchip/TCPIP Stack/RSA.c"  -o ${OBJECTDIR}/_ext/1954962658/RSA.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1954962658/RSA.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -DXPRJ_XC16-USB_Thumb_Drive=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -Os -I".." -I"../../Microchip/Include" -I"../../../Microchip/Include" -I"../../../Microchip/Include/TCPIP Stack" -I"../../../Microchip/Include/USB" -I"../../../Microchip/Include/MDD File System" -msmart-io=1 -Wall -msfr-warn=off   -fno-ivopts
	@${FIXDEPS} "${OBJECTDIR}/_ext/1954962658/RSA.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1954962658/Random.o: ../../../Microchip/TCPIP\ Stack/Random.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1954962658" 
	@${RM} ${OBJECTDIR}/_ext/1954962658/Random.o.d 
	@${RM} ${OBJECTDIR}/_ext/1954962658/Random.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  "../../../Microchip/TCPIP Stack/Random.c"  -o ${OBJECTDIR}/_ext/1954962658/Random.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1954962658/Random.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -DXPRJ_XC16-USB_Thumb_Drive=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -Os -I".." -I"../../Microchip/Include" -I"../../../Microchip/Include" -I"../../../Microchip/Include/TCPIP Stack" -I"../../../Microchip/Include/USB" -I"../../../Microchip/Include/MDD File System" -msmart-io=1 -Wall -msfr-warn=off   -fno-ivopts
	@${FIXDEPS} "${OBJECTDIR}/_ext/1954962658/Random.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1954962658/Reboot.o: ../../../Microchip/TCPIP\ Stack/Reboot.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1954962658" 
	@${RM} ${OBJECTDIR}/_ext/1954962658/Reboot.o.d 
	@${RM} ${OBJECTDIR}/_ext/1954962658/Reboot.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  "../../../Microchip/TCPIP Stack/Reboot.c"  -o ${OBJECTDIR}/_ext/1954962658/Reboot.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1954962658/Reboot.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -DXPRJ_XC16-USB_Thumb_Drive=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -Os -I".." -I"../../Microchip/Include" -I"../../../Microchip/Include" -I"../../../Microchip/Include/TCPIP Stack" -I"../../../Microchip/Include/USB" -I"../../../Microchip/Include/MDD File System" -msmart-io=1 -Wall -msfr-warn=off   -fno-ivopts
	@${FIXDEPS} "${OBJECTDIR}/_ext/1954962658/Reboot.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1954962658/SMTP.o: ../../../Microchip/TCPIP\ Stack/SMTP.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1954962658" 
	@${RM} ${OBJECTDIR}/_ext/1954962658/SMTP.o.d 
	@${RM} ${OBJECTDIR}/_ext/1954962658/SMTP.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  "../../../Microchip/TCPIP Stack/SMTP.c"  -o ${OBJECTDIR}/_ext/1954962658/SMTP.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1954962658/SMTP.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -DXPRJ_XC16-USB_Thumb_Drive=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -Os -I".." -I"../../Microchip/Include" -I"../../../Microchip/Include" -I"../../../Microchip/Include/TCPIP Stack" -I"../../../Microchip/Include/USB" -I"../../../Microchip/Include/MDD File System" -msmart-io=1 -Wall -msfr-warn=off   -fno-ivopts
	@${FIXDEPS} "${OBJECTDIR}/_ext/1954962658/SMTP.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1954962658/SNMP.o: ../../../Microchip/TCPIP\ Stack/SNMP.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1954962658" 
	@${RM} ${OBJECTDIR}/_ext/1954962658/SNMP.o.d 
	@${RM} ${OBJECTDIR}/_ext/1954962658/SNMP.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  "../../../Microchip/TCPIP Stack/SNMP.c"  -o ${OBJECTDIR}/_ext/1954962658/SNMP.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1954962658/SNMP.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -DXPRJ_XC16-USB_Thumb_Drive=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -Os -I".." -I"../../Microchip/Include" -I"../../../Microchip/Include" -I"../../../Microchip/Include/TCPIP Stack" -I"../../../Microchip/Include/USB" -I"../../../Microchip/Include/MDD File System" -msmart-io=1 -Wall -msfr-warn=off   -fno-ivopts
	@${FIXDEPS} "${OBJECTDIR}/_ext/1954962658/SNMP.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1954962658/SNTP.o: ../../../Microchip/TCPIP\ Stack/SNTP.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1954962658" 
	@${RM} ${OBJECTDIR}/_ext/1954962658/SNTP.o.d 
	@${RM} ${OBJECTDIR}/_ext/1954962658/SNTP.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  "../../../Microchip/TCPIP Stack/SNTP.c"  -o ${OBJECTDIR}/_ext/1954962658/SNTP.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1954962658/SNTP.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -DXPRJ_XC16-USB_Thumb_Drive=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -Os -I".." -I"../../Microchip/Include" -I"../../../Microchip/Include" -I"../../../Microchip/Include/TCPIP Stack" -I"../../../Microchip/Include/USB" -I"../../../Microchip/Include/MDD File System" -msmart-io=1 -Wall -msfr-warn=off   -fno-ivopts
	@${FIXDEPS} "${OBJECTDIR}/_ext/1954962658/SNTP.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1954962658/SPIEEPROM.o: ../../../Microchip/TCPIP\ Stack/SPIEEPROM.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1954962658" 
	@${RM} ${OBJECTDIR}/_ext/1954962658/SPIEEPROM.o.d 
	@${RM} ${OBJECTDIR}/_ext/1954962658/SPIEEPROM.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  "../../../Microchip/TCPIP Stack/SPIEEPROM.c"  -o ${OBJECTDIR}/_ext/1954962658/SPIEEPROM.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1954962658/SPIEEPROM.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -DXPRJ_XC16-USB_Thumb_Drive=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -Os -I".." -I"../../Microchip/Include" -I"../../../Microchip/Include" -I"../../../Microchip/Include/TCPIP Stack" -I"../../../Microchip/Include/USB" -I"../../../Microchip/Include/MDD File System" -msmart-io=1 -Wall -msfr-warn=off   -fno-ivopts
	@${FIXDEPS} "${OBJECTDIR}/_ext/1954962658/SPIEEPROM.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1954962658/SPIFlash.o: ../../../Microchip/TCPIP\ Stack/SPIFlash.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1954962658" 
	@${RM} ${OBJECTDIR}/_ext/1954962658/SPIFlash.o.d 
	@${RM} ${OBJECTDIR}/_ext/1954962658/SPIFlash.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  "../../../Microchip/TCPIP Stack/SPIFlash.c"  -o ${OBJECTDIR}/_ext/1954962658/SPIFlash.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1954962658/SPIFlash.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -DXPRJ_XC16-USB_Thumb_Drive=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -Os -I".." -I"../../Microchip/Include" -I"../../../Microchip/Include" -I"../../../Microchip/Include/TCPIP Stack" -I"../../../Microchip/Include/USB" -I"../../../Microchip/Include/MDD File System" -msmart-io=1 -Wall -msfr-warn=off   -fno-ivopts
	@${FIXDEPS} "${OBJECTDIR}/_ext/1954962658/SPIFlash.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1954962658/SPIRAM.o: ../../../Microchip/TCPIP\ Stack/SPIRAM.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1954962658" 
	@${RM} ${OBJECTDIR}/_ext/1954962658/SPIRAM.o.d 
	@${RM} ${OBJECTDIR}/_ext/1954962658/SPIRAM.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  "../../../Microchip/TCPIP Stack/SPIRAM.c"  -o ${OBJECTDIR}/_ext/1954962658/SPIRAM.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1954962658/SPIRAM.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -DXPRJ_XC16-USB_Thumb_Drive=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -Os -I".." -I"../../Microchip/Include" -I"../../../Microchip/Include" -I"../../../Microchip/Include/TCPIP Stack" -I"../../../Microchip/Include/USB" -I"../../../Microchip/Include/MDD File System" -msmart-io=1 -Wall -msfr-warn=off   -fno-ivopts
	@${FIXDEPS} "${OBJECTDIR}/_ext/1954962658/SPIRAM.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1954962658/SSL.o: ../../../Microchip/TCPIP\ Stack/SSL.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1954962658" 
	@${RM} ${OBJECTDIR}/_ext/1954962658/SSL.o.d 
	@${RM} ${OBJECTDIR}/_ext/1954962658/SSL.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  "../../../Microchip/TCPIP Stack/SSL.c"  -o ${OBJECTDIR}/_ext/1954962658/SSL.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1954962658/SSL.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -DXPRJ_XC16-USB_Thumb_Drive=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -Os -I".." -I"../../Microchip/Include" -I"../../../Microchip/Include" -I"../../../Microchip/Include/TCPIP Stack" -I"../../../Microchip/Include/USB" -I"../../../Microchip/Include/MDD File System" -msmart-io=1 -Wall -msfr-warn=off   -fno-ivopts
	@${FIXDEPS} "${OBJECTDIR}/_ext/1954962658/SSL.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1954962658/StackTsk.o: ../../../Microchip/TCPIP\ Stack/StackTsk.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1954962658" 
	@${RM} ${OBJECTDIR}/_ext/1954962658/StackTsk.o.d 
	@${RM} ${OBJECTDIR}/_ext/1954962658/StackTsk.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  "../../../Microchip/TCPIP Stack/StackTsk.c"  -o ${OBJECTDIR}/_ext/1954962658/StackTsk.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1954962658/StackTsk.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -DXPRJ_XC16-USB_Thumb_Drive=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -Os -I".." -I"../../Microchip/Include" -I"../../../Microchip/Include" -I"../../../Microchip/Include/TCPIP Stack" -I"../../../Microchip/Include/USB" -I"../../../Microchip/Include/MDD File System" -msmart-io=1 -Wall -msfr-warn=off   -fno-ivopts
	@${FIXDEPS} "${OBJECTDIR}/_ext/1954962658/StackTsk.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1954962658/TCP.o: ../../../Microchip/TCPIP\ Stack/TCP.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1954962658" 
	@${RM} ${OBJECTDIR}/_ext/1954962658/TCP.o.d 
	@${RM} ${OBJECTDIR}/_ext/1954962658/TCP.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  "../../../Microchip/TCPIP Stack/TCP.c"  -o ${OBJECTDIR}/_ext/1954962658/TCP.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1954962658/TCP.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -DXPRJ_XC16-USB_Thumb_Drive=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -Os -I".." -I"../../Microchip/Include" -I"../../../Microchip/Include" -I"../../../Microchip/Include/TCPIP Stack" -I"../../../Microchip/Include/USB" -I"../../../Microchip/Include/MDD File System" -msmart-io=1 -Wall -msfr-warn=off   -fno-ivopts
	@${FIXDEPS} "${OBJECTDIR}/_ext/1954962658/TCP.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1954962658/TCPPerformanceTest.o: ../../../Microchip/TCPIP\ Stack/TCPPerformanceTest.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1954962658" 
	@${RM} ${OBJECTDIR}/_ext/1954962658/TCPPerformanceTest.o.d 
	@${RM} ${OBJECTDIR}/_ext/1954962658/TCPPerformanceTest.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  "../../../Microchip/TCPIP Stack/TCPPerformanceTest.c"  -o ${OBJECTDIR}/_ext/1954962658/TCPPerformanceTest.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1954962658/TCPPerformanceTest.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -DXPRJ_XC16-USB_Thumb_Drive=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -Os -I".." -I"../../Microchip/Include" -I"../../../Microchip/Include" -I"../../../Microchip/Include/TCPIP Stack" -I"../../../Microchip/Include/USB" -I"../../../Microchip/Include/MDD File System" -msmart-io=1 -Wall -msfr-warn=off   -fno-ivopts
	@${FIXDEPS} "${OBJECTDIR}/_ext/1954962658/TCPPerformanceTest.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1954962658/TFTPc.o: ../../../Microchip/TCPIP\ Stack/TFTPc.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1954962658" 
	@${RM} ${OBJECTDIR}/_ext/1954962658/TFTPc.o.d 
	@${RM} ${OBJECTDIR}/_ext/1954962658/TFTPc.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  "../../../Microchip/TCPIP Stack/TFTPc.c"  -o ${OBJECTDIR}/_ext/1954962658/TFTPc.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1954962658/TFTPc.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -DXPRJ_XC16-USB_Thumb_Drive=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -Os -I".." -I"../../Microchip/Include" -I"../../../Microchip/Include" -I"../../../Microchip/Include/TCPIP Stack" -I"../../../Microchip/Include/USB" -I"../../../Microchip/Include/MDD File System" -msmart-io=1 -Wall -msfr-warn=off   -fno-ivopts
	@${FIXDEPS} "${OBJECTDIR}/_ext/1954962658/TFTPc.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1954962658/Telnet.o: ../../../Microchip/TCPIP\ Stack/Telnet.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1954962658" 
	@${RM} ${OBJECTDIR}/_ext/1954962658/Telnet.o.d 
	@${RM} ${OBJECTDIR}/_ext/1954962658/Telnet.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  "../../../Microchip/TCPIP Stack/Telnet.c"  -o ${OBJECTDIR}/_ext/1954962658/Telnet.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1954962658/Telnet.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -DXPRJ_XC16-USB_Thumb_Drive=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -Os -I".." -I"../../Microchip/Include" -I"../../../Microchip/Include" -I"../../../Microchip/Include/TCPIP Stack" -I"../../../Microchip/Include/USB" -I"../../../Microchip/Include/MDD File System" -msmart-io=1 -Wall -msfr-warn=off   -fno-ivopts
	@${FIXDEPS} "${OBJECTDIR}/_ext/1954962658/Telnet.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1954962658/Tick.o: ../../../Microchip/TCPIP\ Stack/Tick.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1954962658" 
	@${RM} ${OBJECTDIR}/_ext/1954962658/Tick.o.d 
	@${RM} ${OBJECTDIR}/_ext/1954962658/Tick.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  "../../../Microchip/TCPIP Stack/Tick.c"  -o ${OBJECTDIR}/_ext/1954962658/Tick.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1954962658/Tick.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -DXPRJ_XC16-USB_Thumb_Drive=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -Os -I".." -I"../../Microchip/Include" -I"../../../Microchip/Include" -I"../../../Microchip/Include/TCPIP Stack" -I"../../../Microchip/Include/USB" -I"../../../Microchip/Include/MDD File System" -msmart-io=1 -Wall -msfr-warn=off   -fno-ivopts
	@${FIXDEPS} "${OBJECTDIR}/_ext/1954962658/Tick.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1954962658/UART.o: ../../../Microchip/TCPIP\ Stack/UART.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1954962658" 
	@${RM} ${OBJECTDIR}/_ext/1954962658/UART.o.d 
	@${RM} ${OBJECTDIR}/_ext/1954962658/UART.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  "../../../Microchip/TCPIP Stack/UART.c"  -o ${OBJECTDIR}/_ext/1954962658/UART.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1954962658/UART.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -DXPRJ_XC16-USB_Thumb_Drive=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -Os -I".." -I"../../Microchip/Include" -I"../../../Microchip/Include" -I"../../../Microchip/Include/TCPIP Stack" -I"../../../Microchip/Include/USB" -I"../../../Microchip/Include/MDD File System" -msmart-io=1 -Wall -msfr-warn=off   -fno-ivopts
	@${FIXDEPS} "${OBJECTDIR}/_ext/1954962658/UART.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1954962658/UART2TCPBridge.o: ../../../Microchip/TCPIP\ Stack/UART2TCPBridge.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1954962658" 
	@${RM} ${OBJECTDIR}/_ext/1954962658/UART2TCPBridge.o.d 
	@${RM} ${OBJECTDIR}/_ext/1954962658/UART2TCPBridge.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  "../../../Microchip/TCPIP Stack/UART2TCPBridge.c"  -o ${OBJECTDIR}/_ext/1954962658/UART2TCPBridge.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1954962658/UART2TCPBridge.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -DXPRJ_XC16-USB_Thumb_Drive=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -Os -I".." -I"../../Microchip/Include" -I"../../../Microchip/Include" -I"../../../Microchip/Include/TCPIP Stack" -I"../../../Microchip/Include/USB" -I"../../../Microchip/Include/MDD File System" -msmart-io=1 -Wall -msfr-warn=off   -fno-ivopts
	@${FIXDEPS} "${OBJECTDIR}/_ext/1954962658/UART2TCPBridge.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1954962658/UDP.o: ../../../Microchip/TCPIP\ Stack/UDP.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1954962658" 
	@${RM} ${OBJECTDIR}/_ext/1954962658/UDP.o.d 
	@${RM} ${OBJECTDIR}/_ext/1954962658/UDP.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  "../../../Microchip/TCPIP Stack/UDP.c"  -o ${OBJECTDIR}/_ext/1954962658/UDP.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1954962658/UDP.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -DXPRJ_XC16-USB_Thumb_Drive=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -Os -I".." -I"../../Microchip/Include" -I"../../../Microchip/Include" -I"../../../Microchip/Include/TCPIP Stack" -I"../../../Microchip/Include/USB" -I"../../../Microchip/Include/MDD File System" -msmart-io=1 -Wall -msfr-warn=off   -fno-ivopts
	@${FIXDEPS} "${OBJECTDIR}/_ext/1954962658/UDP.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1954962658/UDPPerformanceTest.o: ../../../Microchip/TCPIP\ Stack/UDPPerformanceTest.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1954962658" 
	@${RM} ${OBJECTDIR}/_ext/1954962658/UDPPerformanceTest.o.d 
	@${RM} ${OBJECTDIR}/_ext/1954962658/UDPPerformanceTest.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  "../../../Microchip/TCPIP Stack/UDPPerformanceTest.c"  -o ${OBJECTDIR}/_ext/1954962658/UDPPerformanceTest.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1954962658/UDPPerformanceTest.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -DXPRJ_XC16-USB_Thumb_Drive=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -Os -I".." -I"../../Microchip/Include" -I"../../../Microchip/Include" -I"../../../Microchip/Include/TCPIP Stack" -I"../../../Microchip/Include/USB" -I"../../../Microchip/Include/MDD File System" -msmart-io=1 -Wall -msfr-warn=off   -fno-ivopts
	@${FIXDEPS} "${OBJECTDIR}/_ext/1954962658/UDPPerformanceTest.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/549097302/usb_host.o: ../../../Microchip/USB/usb_host.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/549097302" 
	@${RM} ${OBJECTDIR}/_ext/549097302/usb_host.o.d 
	@${RM} ${OBJECTDIR}/_ext/549097302/usb_host.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../../Microchip/USB/usb_host.c  -o ${OBJECTDIR}/_ext/549097302/usb_host.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/549097302/usb_host.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -DXPRJ_XC16-USB_Thumb_Drive=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -Os -I".." -I"../../Microchip/Include" -I"../../../Microchip/Include" -I"../../../Microchip/Include/TCPIP Stack" -I"../../../Microchip/Include/USB" -I"../../../Microchip/Include/MDD File System" -msmart-io=1 -Wall -msfr-warn=off   -fno-ivopts
	@${FIXDEPS} "${OBJECTDIR}/_ext/549097302/usb_host.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/172487899/usb_host_msd.o: ../../../Microchip/USB/MSD\ Host\ Driver/usb_host_msd.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/172487899" 
	@${RM} ${OBJECTDIR}/_ext/172487899/usb_host_msd.o.d 
	@${RM} ${OBJECTDIR}/_ext/172487899/usb_host_msd.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  "../../../Microchip/USB/MSD Host Driver/usb_host_msd.c"  -o ${OBJECTDIR}/_ext/172487899/usb_host_msd.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/172487899/usb_host_msd.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -DXPRJ_XC16-USB_Thumb_Drive=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -Os -I".." -I"../../Microchip/Include" -I"../../../Microchip/Include" -I"../../../Microchip/Include/TCPIP Stack" -I"../../../Microchip/Include/USB" -I"../../../Microchip/Include/MDD File System" -msmart-io=1 -Wall -msfr-warn=off   -fno-ivopts
	@${FIXDEPS} "${OBJECTDIR}/_ext/172487899/usb_host_msd.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/172487899/usb_host_msd_scsi.o: ../../../Microchip/USB/MSD\ Host\ Driver/usb_host_msd_scsi.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/172487899" 
	@${RM} ${OBJECTDIR}/_ext/172487899/usb_host_msd_scsi.o.d 
	@${RM} ${OBJECTDIR}/_ext/172487899/usb_host_msd_scsi.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  "../../../Microchip/USB/MSD Host Driver/usb_host_msd_scsi.c"  -o ${OBJECTDIR}/_ext/172487899/usb_host_msd_scsi.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/172487899/usb_host_msd_scsi.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -DXPRJ_XC16-USB_Thumb_Drive=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -Os -I".." -I"../../Microchip/Include" -I"../../../Microchip/Include" -I"../../../Microchip/Include/TCPIP Stack" -I"../../../Microchip/Include/USB" -I"../../../Microchip/Include/MDD File System" -msmart-io=1 -Wall -msfr-warn=off   -fno-ivopts
	@${FIXDEPS} "${OBJECTDIR}/_ext/172487899/usb_host_msd_scsi.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1472/CustomHTTPApp.o: ../CustomHTTPApp.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/CustomHTTPApp.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/CustomHTTPApp.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../CustomHTTPApp.c  -o ${OBJECTDIR}/_ext/1472/CustomHTTPApp.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/CustomHTTPApp.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -DXPRJ_XC16-USB_Thumb_Drive=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -Os -I".." -I"../../Microchip/Include" -I"../../../Microchip/Include" -I"../../../Microchip/Include/TCPIP Stack" -I"../../../Microchip/Include/USB" -I"../../../Microchip/Include/MDD File System" -msmart-io=1 -Wall -msfr-warn=off   -fno-ivopts
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/CustomHTTPApp.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1472/CustomSSLCert.o: ../CustomSSLCert.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/CustomSSLCert.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/CustomSSLCert.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../CustomSSLCert.c  -o ${OBJECTDIR}/_ext/1472/CustomSSLCert.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/CustomSSLCert.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -DXPRJ_XC16-USB_Thumb_Drive=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -Os -I".." -I"../../Microchip/Include" -I"../../../Microchip/Include" -I"../../../Microchip/Include/TCPIP Stack" -I"../../../Microchip/Include/USB" -I"../../../Microchip/Include/MDD File System" -msmart-io=1 -Wall -msfr-warn=off   -fno-ivopts
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/CustomSSLCert.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1788384718/FSIO.o: ../../../Microchip/MDD\ File\ System/FSIO.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1788384718" 
	@${RM} ${OBJECTDIR}/_ext/1788384718/FSIO.o.d 
	@${RM} ${OBJECTDIR}/_ext/1788384718/FSIO.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  "../../../Microchip/MDD File System/FSIO.c"  -o ${OBJECTDIR}/_ext/1788384718/FSIO.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1788384718/FSIO.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -DXPRJ_XC16-USB_Thumb_Drive=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -Os -I".." -I"../../Microchip/Include" -I"../../../Microchip/Include" -I"../../../Microchip/Include/TCPIP Stack" -I"../../../Microchip/Include/USB" -I"../../../Microchip/Include/MDD File System" -msmart-io=1 -Wall -msfr-warn=off   -fno-ivopts
	@${FIXDEPS} "${OBJECTDIR}/_ext/1788384718/FSIO.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1472/MainDemo.o: ../MainDemo.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/MainDemo.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/MainDemo.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../MainDemo.c  -o ${OBJECTDIR}/_ext/1472/MainDemo.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/MainDemo.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -DXPRJ_XC16-USB_Thumb_Drive=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -Os -I".." -I"../../Microchip/Include" -I"../../../Microchip/Include" -I"../../../Microchip/Include/TCPIP Stack" -I"../../../Microchip/Include/USB" -I"../../../Microchip/Include/MDD File System" -msmart-io=1 -Wall -msfr-warn=off   -fno-ivopts
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/MainDemo.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1472/usb_config.o: ../usb_config.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/usb_config.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/usb_config.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../usb_config.c  -o ${OBJECTDIR}/_ext/1472/usb_config.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/usb_config.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -DXPRJ_XC16-USB_Thumb_Drive=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -Os -I".." -I"../../Microchip/Include" -I"../../../Microchip/Include" -I"../../../Microchip/Include/TCPIP Stack" -I"../../../Microchip/Include/USB" -I"../../../Microchip/Include/MDD File System" -msmart-io=1 -Wall -msfr-warn=off   -fno-ivopts
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/usb_config.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
else
${OBJECTDIR}/_ext/1472/BerkeleyTCPClientDemo.o: ../BerkeleyTCPClientDemo.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/BerkeleyTCPClientDemo.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/BerkeleyTCPClientDemo.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../BerkeleyTCPClientDemo.c  -o ${OBJECTDIR}/_ext/1472/BerkeleyTCPClientDemo.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/BerkeleyTCPClientDemo.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_XC16-USB_Thumb_Drive=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -Os -I".." -I"../../Microchip/Include" -I"../../../Microchip/Include" -I"../../../Microchip/Include/TCPIP Stack" -I"../../../Microchip/Include/USB" -I"../../../Microchip/Include/MDD File System" -msmart-io=1 -Wall -msfr-warn=off   -fno-ivopts
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/BerkeleyTCPClientDemo.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1472/BerkeleyTCPServerDemo.o: ../BerkeleyTCPServerDemo.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/BerkeleyTCPServerDemo.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/BerkeleyTCPServerDemo.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../BerkeleyTCPServerDemo.c  -o ${OBJECTDIR}/_ext/1472/BerkeleyTCPServerDemo.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/BerkeleyTCPServerDemo.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_XC16-USB_Thumb_Drive=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -Os -I".." -I"../../Microchip/Include" -I"../../../Microchip/Include" -I"../../../Microchip/Include/TCPIP Stack" -I"../../../Microchip/Include/USB" -I"../../../Microchip/Include/MDD File System" -msmart-io=1 -Wall -msfr-warn=off   -fno-ivopts
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/BerkeleyTCPServerDemo.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1472/BerkeleyUDPClientDemo.o: ../BerkeleyUDPClientDemo.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/BerkeleyUDPClientDemo.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/BerkeleyUDPClientDemo.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../BerkeleyUDPClientDemo.c  -o ${OBJECTDIR}/_ext/1472/BerkeleyUDPClientDemo.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/BerkeleyUDPClientDemo.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_XC16-USB_Thumb_Drive=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -Os -I".." -I"../../Microchip/Include" -I"../../../Microchip/Include" -I"../../../Microchip/Include/TCPIP Stack" -I"../../../Microchip/Include/USB" -I"../../../Microchip/Include/MDD File System" -msmart-io=1 -Wall -msfr-warn=off   -fno-ivopts
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/BerkeleyUDPClientDemo.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1472/GenericTCPClient.o: ../GenericTCPClient.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/GenericTCPClient.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/GenericTCPClient.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../GenericTCPClient.c  -o ${OBJECTDIR}/_ext/1472/GenericTCPClient.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/GenericTCPClient.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_XC16-USB_Thumb_Drive=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -Os -I".." -I"../../Microchip/Include" -I"../../../Microchip/Include" -I"../../../Microchip/Include/TCPIP Stack" -I"../../../Microchip/Include/USB" -I"../../../Microchip/Include/MDD File System" -msmart-io=1 -Wall -msfr-warn=off   -fno-ivopts
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/GenericTCPClient.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1472/GenericTCPServer.o: ../GenericTCPServer.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/GenericTCPServer.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/GenericTCPServer.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../GenericTCPServer.c  -o ${OBJECTDIR}/_ext/1472/GenericTCPServer.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/GenericTCPServer.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_XC16-USB_Thumb_Drive=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -Os -I".." -I"../../Microchip/Include" -I"../../../Microchip/Include" -I"../../../Microchip/Include/TCPIP Stack" -I"../../../Microchip/Include/USB" -I"../../../Microchip/Include/MDD File System" -msmart-io=1 -Wall -msfr-warn=off   -fno-ivopts
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/GenericTCPServer.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1472/PingDemo.o: ../PingDemo.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/PingDemo.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/PingDemo.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../PingDemo.c  -o ${OBJECTDIR}/_ext/1472/PingDemo.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/PingDemo.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_XC16-USB_Thumb_Drive=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -Os -I".." -I"../../Microchip/Include" -I"../../../Microchip/Include" -I"../../../Microchip/Include/TCPIP Stack" -I"../../../Microchip/Include/USB" -I"../../../Microchip/Include/MDD File System" -msmart-io=1 -Wall -msfr-warn=off   -fno-ivopts
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/PingDemo.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1472/SMTPDemo.o: ../SMTPDemo.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/SMTPDemo.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/SMTPDemo.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../SMTPDemo.c  -o ${OBJECTDIR}/_ext/1472/SMTPDemo.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/SMTPDemo.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_XC16-USB_Thumb_Drive=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -Os -I".." -I"../../Microchip/Include" -I"../../../Microchip/Include" -I"../../../Microchip/Include/TCPIP Stack" -I"../../../Microchip/Include/USB" -I"../../../Microchip/Include/MDD File System" -msmart-io=1 -Wall -msfr-warn=off   -fno-ivopts
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/SMTPDemo.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1472/UARTConfig.o: ../UARTConfig.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/UARTConfig.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/UARTConfig.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../UARTConfig.c  -o ${OBJECTDIR}/_ext/1472/UARTConfig.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/UARTConfig.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_XC16-USB_Thumb_Drive=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -Os -I".." -I"../../Microchip/Include" -I"../../../Microchip/Include" -I"../../../Microchip/Include/TCPIP Stack" -I"../../../Microchip/Include/USB" -I"../../../Microchip/Include/MDD File System" -msmart-io=1 -Wall -msfr-warn=off   -fno-ivopts
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/UARTConfig.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1954962658/ARCFOUR.o: ../../../Microchip/TCPIP\ Stack/ARCFOUR.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1954962658" 
	@${RM} ${OBJECTDIR}/_ext/1954962658/ARCFOUR.o.d 
	@${RM} ${OBJECTDIR}/_ext/1954962658/ARCFOUR.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  "../../../Microchip/TCPIP Stack/ARCFOUR.c"  -o ${OBJECTDIR}/_ext/1954962658/ARCFOUR.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1954962658/ARCFOUR.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_XC16-USB_Thumb_Drive=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -Os -I".." -I"../../Microchip/Include" -I"../../../Microchip/Include" -I"../../../Microchip/Include/TCPIP Stack" -I"../../../Microchip/Include/USB" -I"../../../Microchip/Include/MDD File System" -msmart-io=1 -Wall -msfr-warn=off   -fno-ivopts
	@${FIXDEPS} "${OBJECTDIR}/_ext/1954962658/ARCFOUR.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1954962658/ARP.o: ../../../Microchip/TCPIP\ Stack/ARP.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1954962658" 
	@${RM} ${OBJECTDIR}/_ext/1954962658/ARP.o.d 
	@${RM} ${OBJECTDIR}/_ext/1954962658/ARP.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  "../../../Microchip/TCPIP Stack/ARP.c"  -o ${OBJECTDIR}/_ext/1954962658/ARP.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1954962658/ARP.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_XC16-USB_Thumb_Drive=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -Os -I".." -I"../../Microchip/Include" -I"../../../Microchip/Include" -I"../../../Microchip/Include/TCPIP Stack" -I"../../../Microchip/Include/USB" -I"../../../Microchip/Include/MDD File System" -msmart-io=1 -Wall -msfr-warn=off   -fno-ivopts
	@${FIXDEPS} "${OBJECTDIR}/_ext/1954962658/ARP.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1954962658/Announce.o: ../../../Microchip/TCPIP\ Stack/Announce.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1954962658" 
	@${RM} ${OBJECTDIR}/_ext/1954962658/Announce.o.d 
	@${RM} ${OBJECTDIR}/_ext/1954962658/Announce.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  "../../../Microchip/TCPIP Stack/Announce.c"  -o ${OBJECTDIR}/_ext/1954962658/Announce.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1954962658/Announce.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_XC16-USB_Thumb_Drive=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -Os -I".." -I"../../Microchip/Include" -I"../../../Microchip/Include" -I"../../../Microchip/Include/TCPIP Stack" -I"../../../Microchip/Include/USB" -I"../../../Microchip/Include/MDD File System" -msmart-io=1 -Wall -msfr-warn=off   -fno-ivopts
	@${FIXDEPS} "${OBJECTDIR}/_ext/1954962658/Announce.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1954962658/AutoIP.o: ../../../Microchip/TCPIP\ Stack/AutoIP.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1954962658" 
	@${RM} ${OBJECTDIR}/_ext/1954962658/AutoIP.o.d 
	@${RM} ${OBJECTDIR}/_ext/1954962658/AutoIP.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  "../../../Microchip/TCPIP Stack/AutoIP.c"  -o ${OBJECTDIR}/_ext/1954962658/AutoIP.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1954962658/AutoIP.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_XC16-USB_Thumb_Drive=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -Os -I".." -I"../../Microchip/Include" -I"../../../Microchip/Include" -I"../../../Microchip/Include/TCPIP Stack" -I"../../../Microchip/Include/USB" -I"../../../Microchip/Include/MDD File System" -msmart-io=1 -Wall -msfr-warn=off   -fno-ivopts
	@${FIXDEPS} "${OBJECTDIR}/_ext/1954962658/AutoIP.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1954962658/BerkeleyAPI.o: ../../../Microchip/TCPIP\ Stack/BerkeleyAPI.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1954962658" 
	@${RM} ${OBJECTDIR}/_ext/1954962658/BerkeleyAPI.o.d 
	@${RM} ${OBJECTDIR}/_ext/1954962658/BerkeleyAPI.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  "../../../Microchip/TCPIP Stack/BerkeleyAPI.c"  -o ${OBJECTDIR}/_ext/1954962658/BerkeleyAPI.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1954962658/BerkeleyAPI.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_XC16-USB_Thumb_Drive=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -Os -I".." -I"../../Microchip/Include" -I"../../../Microchip/Include" -I"../../../Microchip/Include/TCPIP Stack" -I"../../../Microchip/Include/USB" -I"../../../Microchip/Include/MDD File System" -msmart-io=1 -Wall -msfr-warn=off   -fno-ivopts
	@${FIXDEPS} "${OBJECTDIR}/_ext/1954962658/BerkeleyAPI.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1954962658/BigInt.o: ../../../Microchip/TCPIP\ Stack/BigInt.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1954962658" 
	@${RM} ${OBJECTDIR}/_ext/1954962658/BigInt.o.d 
	@${RM} ${OBJECTDIR}/_ext/1954962658/BigInt.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  "../../../Microchip/TCPIP Stack/BigInt.c"  -o ${OBJECTDIR}/_ext/1954962658/BigInt.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1954962658/BigInt.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_XC16-USB_Thumb_Drive=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -Os -I".." -I"../../Microchip/Include" -I"../../../Microchip/Include" -I"../../../Microchip/Include/TCPIP Stack" -I"../../../Microchip/Include/USB" -I"../../../Microchip/Include/MDD File System" -msmart-io=1 -Wall -msfr-warn=off   -fno-ivopts
	@${FIXDEPS} "${OBJECTDIR}/_ext/1954962658/BigInt.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1954962658/DHCP.o: ../../../Microchip/TCPIP\ Stack/DHCP.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1954962658" 
	@${RM} ${OBJECTDIR}/_ext/1954962658/DHCP.o.d 
	@${RM} ${OBJECTDIR}/_ext/1954962658/DHCP.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  "../../../Microchip/TCPIP Stack/DHCP.c"  -o ${OBJECTDIR}/_ext/1954962658/DHCP.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1954962658/DHCP.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_XC16-USB_Thumb_Drive=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -Os -I".." -I"../../Microchip/Include" -I"../../../Microchip/Include" -I"../../../Microchip/Include/TCPIP Stack" -I"../../../Microchip/Include/USB" -I"../../../Microchip/Include/MDD File System" -msmart-io=1 -Wall -msfr-warn=off   -fno-ivopts
	@${FIXDEPS} "${OBJECTDIR}/_ext/1954962658/DHCP.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1954962658/DHCPs.o: ../../../Microchip/TCPIP\ Stack/DHCPs.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1954962658" 
	@${RM} ${OBJECTDIR}/_ext/1954962658/DHCPs.o.d 
	@${RM} ${OBJECTDIR}/_ext/1954962658/DHCPs.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  "../../../Microchip/TCPIP Stack/DHCPs.c"  -o ${OBJECTDIR}/_ext/1954962658/DHCPs.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1954962658/DHCPs.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_XC16-USB_Thumb_Drive=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -Os -I".." -I"../../Microchip/Include" -I"../../../Microchip/Include" -I"../../../Microchip/Include/TCPIP Stack" -I"../../../Microchip/Include/USB" -I"../../../Microchip/Include/MDD File System" -msmart-io=1 -Wall -msfr-warn=off   -fno-ivopts
	@${FIXDEPS} "${OBJECTDIR}/_ext/1954962658/DHCPs.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1954962658/DNS.o: ../../../Microchip/TCPIP\ Stack/DNS.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1954962658" 
	@${RM} ${OBJECTDIR}/_ext/1954962658/DNS.o.d 
	@${RM} ${OBJECTDIR}/_ext/1954962658/DNS.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  "../../../Microchip/TCPIP Stack/DNS.c"  -o ${OBJECTDIR}/_ext/1954962658/DNS.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1954962658/DNS.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_XC16-USB_Thumb_Drive=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -Os -I".." -I"../../Microchip/Include" -I"../../../Microchip/Include" -I"../../../Microchip/Include/TCPIP Stack" -I"../../../Microchip/Include/USB" -I"../../../Microchip/Include/MDD File System" -msmart-io=1 -Wall -msfr-warn=off   -fno-ivopts
	@${FIXDEPS} "${OBJECTDIR}/_ext/1954962658/DNS.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1954962658/DNSs.o: ../../../Microchip/TCPIP\ Stack/DNSs.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1954962658" 
	@${RM} ${OBJECTDIR}/_ext/1954962658/DNSs.o.d 
	@${RM} ${OBJECTDIR}/_ext/1954962658/DNSs.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  "../../../Microchip/TCPIP Stack/DNSs.c"  -o ${OBJECTDIR}/_ext/1954962658/DNSs.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1954962658/DNSs.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_XC16-USB_Thumb_Drive=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -Os -I".." -I"../../Microchip/Include" -I"../../../Microchip/Include" -I"../../../Microchip/Include/TCPIP Stack" -I"../../../Microchip/Include/USB" -I"../../../Microchip/Include/MDD File System" -msmart-io=1 -Wall -msfr-warn=off   -fno-ivopts
	@${FIXDEPS} "${OBJECTDIR}/_ext/1954962658/DNSs.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1954962658/Delay.o: ../../../Microchip/TCPIP\ Stack/Delay.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1954962658" 
	@${RM} ${OBJECTDIR}/_ext/1954962658/Delay.o.d 
	@${RM} ${OBJECTDIR}/_ext/1954962658/Delay.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  "../../../Microchip/TCPIP Stack/Delay.c"  -o ${OBJECTDIR}/_ext/1954962658/Delay.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1954962658/Delay.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_XC16-USB_Thumb_Drive=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -Os -I".." -I"../../Microchip/Include" -I"../../../Microchip/Include" -I"../../../Microchip/Include/TCPIP Stack" -I"../../../Microchip/Include/USB" -I"../../../Microchip/Include/MDD File System" -msmart-io=1 -Wall -msfr-warn=off   -fno-ivopts
	@${FIXDEPS} "${OBJECTDIR}/_ext/1954962658/Delay.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1954962658/DynDNS.o: ../../../Microchip/TCPIP\ Stack/DynDNS.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1954962658" 
	@${RM} ${OBJECTDIR}/_ext/1954962658/DynDNS.o.d 
	@${RM} ${OBJECTDIR}/_ext/1954962658/DynDNS.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  "../../../Microchip/TCPIP Stack/DynDNS.c"  -o ${OBJECTDIR}/_ext/1954962658/DynDNS.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1954962658/DynDNS.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_XC16-USB_Thumb_Drive=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -Os -I".." -I"../../Microchip/Include" -I"../../../Microchip/Include" -I"../../../Microchip/Include/TCPIP Stack" -I"../../../Microchip/Include/USB" -I"../../../Microchip/Include/MDD File System" -msmart-io=1 -Wall -msfr-warn=off   -fno-ivopts
	@${FIXDEPS} "${OBJECTDIR}/_ext/1954962658/DynDNS.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1954962658/ENC28J60.o: ../../../Microchip/TCPIP\ Stack/ENC28J60.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1954962658" 
	@${RM} ${OBJECTDIR}/_ext/1954962658/ENC28J60.o.d 
	@${RM} ${OBJECTDIR}/_ext/1954962658/ENC28J60.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  "../../../Microchip/TCPIP Stack/ENC28J60.c"  -o ${OBJECTDIR}/_ext/1954962658/ENC28J60.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1954962658/ENC28J60.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_XC16-USB_Thumb_Drive=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -Os -I".." -I"../../Microchip/Include" -I"../../../Microchip/Include" -I"../../../Microchip/Include/TCPIP Stack" -I"../../../Microchip/Include/USB" -I"../../../Microchip/Include/MDD File System" -msmart-io=1 -Wall -msfr-warn=off   -fno-ivopts
	@${FIXDEPS} "${OBJECTDIR}/_ext/1954962658/ENC28J60.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1954962658/ENCX24J600.o: ../../../Microchip/TCPIP\ Stack/ENCX24J600.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1954962658" 
	@${RM} ${OBJECTDIR}/_ext/1954962658/ENCX24J600.o.d 
	@${RM} ${OBJECTDIR}/_ext/1954962658/ENCX24J600.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  "../../../Microchip/TCPIP Stack/ENCX24J600.c"  -o ${OBJECTDIR}/_ext/1954962658/ENCX24J600.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1954962658/ENCX24J600.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_XC16-USB_Thumb_Drive=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -Os -I".." -I"../../Microchip/Include" -I"../../../Microchip/Include" -I"../../../Microchip/Include/TCPIP Stack" -I"../../../Microchip/Include/USB" -I"../../../Microchip/Include/MDD File System" -msmart-io=1 -Wall -msfr-warn=off   -fno-ivopts
	@${FIXDEPS} "${OBJECTDIR}/_ext/1954962658/ENCX24J600.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1954962658/FTP.o: ../../../Microchip/TCPIP\ Stack/FTP.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1954962658" 
	@${RM} ${OBJECTDIR}/_ext/1954962658/FTP.o.d 
	@${RM} ${OBJECTDIR}/_ext/1954962658/FTP.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  "../../../Microchip/TCPIP Stack/FTP.c"  -o ${OBJECTDIR}/_ext/1954962658/FTP.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1954962658/FTP.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_XC16-USB_Thumb_Drive=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -Os -I".." -I"../../Microchip/Include" -I"../../../Microchip/Include" -I"../../../Microchip/Include/TCPIP Stack" -I"../../../Microchip/Include/USB" -I"../../../Microchip/Include/MDD File System" -msmart-io=1 -Wall -msfr-warn=off   -fno-ivopts
	@${FIXDEPS} "${OBJECTDIR}/_ext/1954962658/FTP.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1954962658/FileSystem.o: ../../../Microchip/TCPIP\ Stack/FileSystem.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1954962658" 
	@${RM} ${OBJECTDIR}/_ext/1954962658/FileSystem.o.d 
	@${RM} ${OBJECTDIR}/_ext/1954962658/FileSystem.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  "../../../Microchip/TCPIP Stack/FileSystem.c"  -o ${OBJECTDIR}/_ext/1954962658/FileSystem.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1954962658/FileSystem.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_XC16-USB_Thumb_Drive=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -Os -I".." -I"../../Microchip/Include" -I"../../../Microchip/Include" -I"../../../Microchip/Include/TCPIP Stack" -I"../../../Microchip/Include/USB" -I"../../../Microchip/Include/MDD File System" -msmart-io=1 -Wall -msfr-warn=off   -fno-ivopts
	@${FIXDEPS} "${OBJECTDIR}/_ext/1954962658/FileSystem.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1472/HTTP2_MDD.o: ../HTTP2_MDD.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/HTTP2_MDD.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/HTTP2_MDD.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../HTTP2_MDD.c  -o ${OBJECTDIR}/_ext/1472/HTTP2_MDD.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/HTTP2_MDD.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_XC16-USB_Thumb_Drive=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -Os -I".." -I"../../Microchip/Include" -I"../../../Microchip/Include" -I"../../../Microchip/Include/TCPIP Stack" -I"../../../Microchip/Include/USB" -I"../../../Microchip/Include/MDD File System" -msmart-io=1 -Wall -msfr-warn=off   -fno-ivopts
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/HTTP2_MDD.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1954962658/Hashes.o: ../../../Microchip/TCPIP\ Stack/Hashes.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1954962658" 
	@${RM} ${OBJECTDIR}/_ext/1954962658/Hashes.o.d 
	@${RM} ${OBJECTDIR}/_ext/1954962658/Hashes.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  "../../../Microchip/TCPIP Stack/Hashes.c"  -o ${OBJECTDIR}/_ext/1954962658/Hashes.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1954962658/Hashes.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_XC16-USB_Thumb_Drive=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -Os -I".." -I"../../Microchip/Include" -I"../../../Microchip/Include" -I"../../../Microchip/Include/TCPIP Stack" -I"../../../Microchip/Include/USB" -I"../../../Microchip/Include/MDD File System" -msmart-io=1 -Wall -msfr-warn=off   -fno-ivopts
	@${FIXDEPS} "${OBJECTDIR}/_ext/1954962658/Hashes.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1954962658/Helpers.o: ../../../Microchip/TCPIP\ Stack/Helpers.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1954962658" 
	@${RM} ${OBJECTDIR}/_ext/1954962658/Helpers.o.d 
	@${RM} ${OBJECTDIR}/_ext/1954962658/Helpers.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  "../../../Microchip/TCPIP Stack/Helpers.c"  -o ${OBJECTDIR}/_ext/1954962658/Helpers.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1954962658/Helpers.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_XC16-USB_Thumb_Drive=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -Os -I".." -I"../../Microchip/Include" -I"../../../Microchip/Include" -I"../../../Microchip/Include/TCPIP Stack" -I"../../../Microchip/Include/USB" -I"../../../Microchip/Include/MDD File System" -msmart-io=1 -Wall -msfr-warn=off   -fno-ivopts
	@${FIXDEPS} "${OBJECTDIR}/_ext/1954962658/Helpers.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1954962658/ICMP.o: ../../../Microchip/TCPIP\ Stack/ICMP.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1954962658" 
	@${RM} ${OBJECTDIR}/_ext/1954962658/ICMP.o.d 
	@${RM} ${OBJECTDIR}/_ext/1954962658/ICMP.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  "../../../Microchip/TCPIP Stack/ICMP.c"  -o ${OBJECTDIR}/_ext/1954962658/ICMP.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1954962658/ICMP.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_XC16-USB_Thumb_Drive=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -Os -I".." -I"../../Microchip/Include" -I"../../../Microchip/Include" -I"../../../Microchip/Include/TCPIP Stack" -I"../../../Microchip/Include/USB" -I"../../../Microchip/Include/MDD File System" -msmart-io=1 -Wall -msfr-warn=off   -fno-ivopts
	@${FIXDEPS} "${OBJECTDIR}/_ext/1954962658/ICMP.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1954962658/IP.o: ../../../Microchip/TCPIP\ Stack/IP.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1954962658" 
	@${RM} ${OBJECTDIR}/_ext/1954962658/IP.o.d 
	@${RM} ${OBJECTDIR}/_ext/1954962658/IP.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  "../../../Microchip/TCPIP Stack/IP.c"  -o ${OBJECTDIR}/_ext/1954962658/IP.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1954962658/IP.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_XC16-USB_Thumb_Drive=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -Os -I".." -I"../../Microchip/Include" -I"../../../Microchip/Include" -I"../../../Microchip/Include/TCPIP Stack" -I"../../../Microchip/Include/USB" -I"../../../Microchip/Include/MDD File System" -msmart-io=1 -Wall -msfr-warn=off   -fno-ivopts
	@${FIXDEPS} "${OBJECTDIR}/_ext/1954962658/IP.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1954962658/LCDBlocking.o: ../../../Microchip/TCPIP\ Stack/LCDBlocking.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1954962658" 
	@${RM} ${OBJECTDIR}/_ext/1954962658/LCDBlocking.o.d 
	@${RM} ${OBJECTDIR}/_ext/1954962658/LCDBlocking.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  "../../../Microchip/TCPIP Stack/LCDBlocking.c"  -o ${OBJECTDIR}/_ext/1954962658/LCDBlocking.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1954962658/LCDBlocking.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_XC16-USB_Thumb_Drive=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -Os -I".." -I"../../Microchip/Include" -I"../../../Microchip/Include" -I"../../../Microchip/Include/TCPIP Stack" -I"../../../Microchip/Include/USB" -I"../../../Microchip/Include/MDD File System" -msmart-io=1 -Wall -msfr-warn=off   -fno-ivopts
	@${FIXDEPS} "${OBJECTDIR}/_ext/1954962658/LCDBlocking.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1954962658/MPFS2.o: ../../../Microchip/TCPIP\ Stack/MPFS2.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1954962658" 
	@${RM} ${OBJECTDIR}/_ext/1954962658/MPFS2.o.d 
	@${RM} ${OBJECTDIR}/_ext/1954962658/MPFS2.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  "../../../Microchip/TCPIP Stack/MPFS2.c"  -o ${OBJECTDIR}/_ext/1954962658/MPFS2.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1954962658/MPFS2.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_XC16-USB_Thumb_Drive=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -Os -I".." -I"../../Microchip/Include" -I"../../../Microchip/Include" -I"../../../Microchip/Include/TCPIP Stack" -I"../../../Microchip/Include/USB" -I"../../../Microchip/Include/MDD File System" -msmart-io=1 -Wall -msfr-warn=off   -fno-ivopts
	@${FIXDEPS} "${OBJECTDIR}/_ext/1954962658/MPFS2.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1954962658/NBNS.o: ../../../Microchip/TCPIP\ Stack/NBNS.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1954962658" 
	@${RM} ${OBJECTDIR}/_ext/1954962658/NBNS.o.d 
	@${RM} ${OBJECTDIR}/_ext/1954962658/NBNS.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  "../../../Microchip/TCPIP Stack/NBNS.c"  -o ${OBJECTDIR}/_ext/1954962658/NBNS.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1954962658/NBNS.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_XC16-USB_Thumb_Drive=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -Os -I".." -I"../../Microchip/Include" -I"../../../Microchip/Include" -I"../../../Microchip/Include/TCPIP Stack" -I"../../../Microchip/Include/USB" -I"../../../Microchip/Include/MDD File System" -msmart-io=1 -Wall -msfr-warn=off   -fno-ivopts
	@${FIXDEPS} "${OBJECTDIR}/_ext/1954962658/NBNS.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1954962658/RSA.o: ../../../Microchip/TCPIP\ Stack/RSA.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1954962658" 
	@${RM} ${OBJECTDIR}/_ext/1954962658/RSA.o.d 
	@${RM} ${OBJECTDIR}/_ext/1954962658/RSA.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  "../../../Microchip/TCPIP Stack/RSA.c"  -o ${OBJECTDIR}/_ext/1954962658/RSA.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1954962658/RSA.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_XC16-USB_Thumb_Drive=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -Os -I".." -I"../../Microchip/Include" -I"../../../Microchip/Include" -I"../../../Microchip/Include/TCPIP Stack" -I"../../../Microchip/Include/USB" -I"../../../Microchip/Include/MDD File System" -msmart-io=1 -Wall -msfr-warn=off   -fno-ivopts
	@${FIXDEPS} "${OBJECTDIR}/_ext/1954962658/RSA.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1954962658/Random.o: ../../../Microchip/TCPIP\ Stack/Random.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1954962658" 
	@${RM} ${OBJECTDIR}/_ext/1954962658/Random.o.d 
	@${RM} ${OBJECTDIR}/_ext/1954962658/Random.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  "../../../Microchip/TCPIP Stack/Random.c"  -o ${OBJECTDIR}/_ext/1954962658/Random.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1954962658/Random.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_XC16-USB_Thumb_Drive=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -Os -I".." -I"../../Microchip/Include" -I"../../../Microchip/Include" -I"../../../Microchip/Include/TCPIP Stack" -I"../../../Microchip/Include/USB" -I"../../../Microchip/Include/MDD File System" -msmart-io=1 -Wall -msfr-warn=off   -fno-ivopts
	@${FIXDEPS} "${OBJECTDIR}/_ext/1954962658/Random.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1954962658/Reboot.o: ../../../Microchip/TCPIP\ Stack/Reboot.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1954962658" 
	@${RM} ${OBJECTDIR}/_ext/1954962658/Reboot.o.d 
	@${RM} ${OBJECTDIR}/_ext/1954962658/Reboot.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  "../../../Microchip/TCPIP Stack/Reboot.c"  -o ${OBJECTDIR}/_ext/1954962658/Reboot.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1954962658/Reboot.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_XC16-USB_Thumb_Drive=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -Os -I".." -I"../../Microchip/Include" -I"../../../Microchip/Include" -I"../../../Microchip/Include/TCPIP Stack" -I"../../../Microchip/Include/USB" -I"../../../Microchip/Include/MDD File System" -msmart-io=1 -Wall -msfr-warn=off   -fno-ivopts
	@${FIXDEPS} "${OBJECTDIR}/_ext/1954962658/Reboot.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1954962658/SMTP.o: ../../../Microchip/TCPIP\ Stack/SMTP.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1954962658" 
	@${RM} ${OBJECTDIR}/_ext/1954962658/SMTP.o.d 
	@${RM} ${OBJECTDIR}/_ext/1954962658/SMTP.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  "../../../Microchip/TCPIP Stack/SMTP.c"  -o ${OBJECTDIR}/_ext/1954962658/SMTP.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1954962658/SMTP.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_XC16-USB_Thumb_Drive=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -Os -I".." -I"../../Microchip/Include" -I"../../../Microchip/Include" -I"../../../Microchip/Include/TCPIP Stack" -I"../../../Microchip/Include/USB" -I"../../../Microchip/Include/MDD File System" -msmart-io=1 -Wall -msfr-warn=off   -fno-ivopts
	@${FIXDEPS} "${OBJECTDIR}/_ext/1954962658/SMTP.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1954962658/SNMP.o: ../../../Microchip/TCPIP\ Stack/SNMP.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1954962658" 
	@${RM} ${OBJECTDIR}/_ext/1954962658/SNMP.o.d 
	@${RM} ${OBJECTDIR}/_ext/1954962658/SNMP.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  "../../../Microchip/TCPIP Stack/SNMP.c"  -o ${OBJECTDIR}/_ext/1954962658/SNMP.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1954962658/SNMP.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_XC16-USB_Thumb_Drive=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -Os -I".." -I"../../Microchip/Include" -I"../../../Microchip/Include" -I"../../../Microchip/Include/TCPIP Stack" -I"../../../Microchip/Include/USB" -I"../../../Microchip/Include/MDD File System" -msmart-io=1 -Wall -msfr-warn=off   -fno-ivopts
	@${FIXDEPS} "${OBJECTDIR}/_ext/1954962658/SNMP.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1954962658/SNTP.o: ../../../Microchip/TCPIP\ Stack/SNTP.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1954962658" 
	@${RM} ${OBJECTDIR}/_ext/1954962658/SNTP.o.d 
	@${RM} ${OBJECTDIR}/_ext/1954962658/SNTP.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  "../../../Microchip/TCPIP Stack/SNTP.c"  -o ${OBJECTDIR}/_ext/1954962658/SNTP.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1954962658/SNTP.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_XC16-USB_Thumb_Drive=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -Os -I".." -I"../../Microchip/Include" -I"../../../Microchip/Include" -I"../../../Microchip/Include/TCPIP Stack" -I"../../../Microchip/Include/USB" -I"../../../Microchip/Include/MDD File System" -msmart-io=1 -Wall -msfr-warn=off   -fno-ivopts
	@${FIXDEPS} "${OBJECTDIR}/_ext/1954962658/SNTP.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1954962658/SPIEEPROM.o: ../../../Microchip/TCPIP\ Stack/SPIEEPROM.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1954962658" 
	@${RM} ${OBJECTDIR}/_ext/1954962658/SPIEEPROM.o.d 
	@${RM} ${OBJECTDIR}/_ext/1954962658/SPIEEPROM.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  "../../../Microchip/TCPIP Stack/SPIEEPROM.c"  -o ${OBJECTDIR}/_ext/1954962658/SPIEEPROM.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1954962658/SPIEEPROM.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_XC16-USB_Thumb_Drive=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -Os -I".." -I"../../Microchip/Include" -I"../../../Microchip/Include" -I"../../../Microchip/Include/TCPIP Stack" -I"../../../Microchip/Include/USB" -I"../../../Microchip/Include/MDD File System" -msmart-io=1 -Wall -msfr-warn=off   -fno-ivopts
	@${FIXDEPS} "${OBJECTDIR}/_ext/1954962658/SPIEEPROM.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1954962658/SPIFlash.o: ../../../Microchip/TCPIP\ Stack/SPIFlash.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1954962658" 
	@${RM} ${OBJECTDIR}/_ext/1954962658/SPIFlash.o.d 
	@${RM} ${OBJECTDIR}/_ext/1954962658/SPIFlash.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  "../../../Microchip/TCPIP Stack/SPIFlash.c"  -o ${OBJECTDIR}/_ext/1954962658/SPIFlash.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1954962658/SPIFlash.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_XC16-USB_Thumb_Drive=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -Os -I".." -I"../../Microchip/Include" -I"../../../Microchip/Include" -I"../../../Microchip/Include/TCPIP Stack" -I"../../../Microchip/Include/USB" -I"../../../Microchip/Include/MDD File System" -msmart-io=1 -Wall -msfr-warn=off   -fno-ivopts
	@${FIXDEPS} "${OBJECTDIR}/_ext/1954962658/SPIFlash.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1954962658/SPIRAM.o: ../../../Microchip/TCPIP\ Stack/SPIRAM.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1954962658" 
	@${RM} ${OBJECTDIR}/_ext/1954962658/SPIRAM.o.d 
	@${RM} ${OBJECTDIR}/_ext/1954962658/SPIRAM.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  "../../../Microchip/TCPIP Stack/SPIRAM.c"  -o ${OBJECTDIR}/_ext/1954962658/SPIRAM.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1954962658/SPIRAM.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_XC16-USB_Thumb_Drive=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -Os -I".." -I"../../Microchip/Include" -I"../../../Microchip/Include" -I"../../../Microchip/Include/TCPIP Stack" -I"../../../Microchip/Include/USB" -I"../../../Microchip/Include/MDD File System" -msmart-io=1 -Wall -msfr-warn=off   -fno-ivopts
	@${FIXDEPS} "${OBJECTDIR}/_ext/1954962658/SPIRAM.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1954962658/SSL.o: ../../../Microchip/TCPIP\ Stack/SSL.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1954962658" 
	@${RM} ${OBJECTDIR}/_ext/1954962658/SSL.o.d 
	@${RM} ${OBJECTDIR}/_ext/1954962658/SSL.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  "../../../Microchip/TCPIP Stack/SSL.c"  -o ${OBJECTDIR}/_ext/1954962658/SSL.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1954962658/SSL.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_XC16-USB_Thumb_Drive=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -Os -I".." -I"../../Microchip/Include" -I"../../../Microchip/Include" -I"../../../Microchip/Include/TCPIP Stack" -I"../../../Microchip/Include/USB" -I"../../../Microchip/Include/MDD File System" -msmart-io=1 -Wall -msfr-warn=off   -fno-ivopts
	@${FIXDEPS} "${OBJECTDIR}/_ext/1954962658/SSL.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1954962658/StackTsk.o: ../../../Microchip/TCPIP\ Stack/StackTsk.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1954962658" 
	@${RM} ${OBJECTDIR}/_ext/1954962658/StackTsk.o.d 
	@${RM} ${OBJECTDIR}/_ext/1954962658/StackTsk.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  "../../../Microchip/TCPIP Stack/StackTsk.c"  -o ${OBJECTDIR}/_ext/1954962658/StackTsk.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1954962658/StackTsk.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_XC16-USB_Thumb_Drive=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -Os -I".." -I"../../Microchip/Include" -I"../../../Microchip/Include" -I"../../../Microchip/Include/TCPIP Stack" -I"../../../Microchip/Include/USB" -I"../../../Microchip/Include/MDD File System" -msmart-io=1 -Wall -msfr-warn=off   -fno-ivopts
	@${FIXDEPS} "${OBJECTDIR}/_ext/1954962658/StackTsk.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1954962658/TCP.o: ../../../Microchip/TCPIP\ Stack/TCP.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1954962658" 
	@${RM} ${OBJECTDIR}/_ext/1954962658/TCP.o.d 
	@${RM} ${OBJECTDIR}/_ext/1954962658/TCP.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  "../../../Microchip/TCPIP Stack/TCP.c"  -o ${OBJECTDIR}/_ext/1954962658/TCP.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1954962658/TCP.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_XC16-USB_Thumb_Drive=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -Os -I".." -I"../../Microchip/Include" -I"../../../Microchip/Include" -I"../../../Microchip/Include/TCPIP Stack" -I"../../../Microchip/Include/USB" -I"../../../Microchip/Include/MDD File System" -msmart-io=1 -Wall -msfr-warn=off   -fno-ivopts
	@${FIXDEPS} "${OBJECTDIR}/_ext/1954962658/TCP.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1954962658/TCPPerformanceTest.o: ../../../Microchip/TCPIP\ Stack/TCPPerformanceTest.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1954962658" 
	@${RM} ${OBJECTDIR}/_ext/1954962658/TCPPerformanceTest.o.d 
	@${RM} ${OBJECTDIR}/_ext/1954962658/TCPPerformanceTest.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  "../../../Microchip/TCPIP Stack/TCPPerformanceTest.c"  -o ${OBJECTDIR}/_ext/1954962658/TCPPerformanceTest.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1954962658/TCPPerformanceTest.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_XC16-USB_Thumb_Drive=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -Os -I".." -I"../../Microchip/Include" -I"../../../Microchip/Include" -I"../../../Microchip/Include/TCPIP Stack" -I"../../../Microchip/Include/USB" -I"../../../Microchip/Include/MDD File System" -msmart-io=1 -Wall -msfr-warn=off   -fno-ivopts
	@${FIXDEPS} "${OBJECTDIR}/_ext/1954962658/TCPPerformanceTest.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1954962658/TFTPc.o: ../../../Microchip/TCPIP\ Stack/TFTPc.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1954962658" 
	@${RM} ${OBJECTDIR}/_ext/1954962658/TFTPc.o.d 
	@${RM} ${OBJECTDIR}/_ext/1954962658/TFTPc.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  "../../../Microchip/TCPIP Stack/TFTPc.c"  -o ${OBJECTDIR}/_ext/1954962658/TFTPc.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1954962658/TFTPc.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_XC16-USB_Thumb_Drive=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -Os -I".." -I"../../Microchip/Include" -I"../../../Microchip/Include" -I"../../../Microchip/Include/TCPIP Stack" -I"../../../Microchip/Include/USB" -I"../../../Microchip/Include/MDD File System" -msmart-io=1 -Wall -msfr-warn=off   -fno-ivopts
	@${FIXDEPS} "${OBJECTDIR}/_ext/1954962658/TFTPc.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1954962658/Telnet.o: ../../../Microchip/TCPIP\ Stack/Telnet.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1954962658" 
	@${RM} ${OBJECTDIR}/_ext/1954962658/Telnet.o.d 
	@${RM} ${OBJECTDIR}/_ext/1954962658/Telnet.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  "../../../Microchip/TCPIP Stack/Telnet.c"  -o ${OBJECTDIR}/_ext/1954962658/Telnet.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1954962658/Telnet.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_XC16-USB_Thumb_Drive=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -Os -I".." -I"../../Microchip/Include" -I"../../../Microchip/Include" -I"../../../Microchip/Include/TCPIP Stack" -I"../../../Microchip/Include/USB" -I"../../../Microchip/Include/MDD File System" -msmart-io=1 -Wall -msfr-warn=off   -fno-ivopts
	@${FIXDEPS} "${OBJECTDIR}/_ext/1954962658/Telnet.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1954962658/Tick.o: ../../../Microchip/TCPIP\ Stack/Tick.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1954962658" 
	@${RM} ${OBJECTDIR}/_ext/1954962658/Tick.o.d 
	@${RM} ${OBJECTDIR}/_ext/1954962658/Tick.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  "../../../Microchip/TCPIP Stack/Tick.c"  -o ${OBJECTDIR}/_ext/1954962658/Tick.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1954962658/Tick.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_XC16-USB_Thumb_Drive=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -Os -I".." -I"../../Microchip/Include" -I"../../../Microchip/Include" -I"../../../Microchip/Include/TCPIP Stack" -I"../../../Microchip/Include/USB" -I"../../../Microchip/Include/MDD File System" -msmart-io=1 -Wall -msfr-warn=off   -fno-ivopts
	@${FIXDEPS} "${OBJECTDIR}/_ext/1954962658/Tick.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1954962658/UART.o: ../../../Microchip/TCPIP\ Stack/UART.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1954962658" 
	@${RM} ${OBJECTDIR}/_ext/1954962658/UART.o.d 
	@${RM} ${OBJECTDIR}/_ext/1954962658/UART.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  "../../../Microchip/TCPIP Stack/UART.c"  -o ${OBJECTDIR}/_ext/1954962658/UART.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1954962658/UART.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_XC16-USB_Thumb_Drive=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -Os -I".." -I"../../Microchip/Include" -I"../../../Microchip/Include" -I"../../../Microchip/Include/TCPIP Stack" -I"../../../Microchip/Include/USB" -I"../../../Microchip/Include/MDD File System" -msmart-io=1 -Wall -msfr-warn=off   -fno-ivopts
	@${FIXDEPS} "${OBJECTDIR}/_ext/1954962658/UART.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1954962658/UART2TCPBridge.o: ../../../Microchip/TCPIP\ Stack/UART2TCPBridge.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1954962658" 
	@${RM} ${OBJECTDIR}/_ext/1954962658/UART2TCPBridge.o.d 
	@${RM} ${OBJECTDIR}/_ext/1954962658/UART2TCPBridge.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  "../../../Microchip/TCPIP Stack/UART2TCPBridge.c"  -o ${OBJECTDIR}/_ext/1954962658/UART2TCPBridge.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1954962658/UART2TCPBridge.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_XC16-USB_Thumb_Drive=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -Os -I".." -I"../../Microchip/Include" -I"../../../Microchip/Include" -I"../../../Microchip/Include/TCPIP Stack" -I"../../../Microchip/Include/USB" -I"../../../Microchip/Include/MDD File System" -msmart-io=1 -Wall -msfr-warn=off   -fno-ivopts
	@${FIXDEPS} "${OBJECTDIR}/_ext/1954962658/UART2TCPBridge.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1954962658/UDP.o: ../../../Microchip/TCPIP\ Stack/UDP.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1954962658" 
	@${RM} ${OBJECTDIR}/_ext/1954962658/UDP.o.d 
	@${RM} ${OBJECTDIR}/_ext/1954962658/UDP.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  "../../../Microchip/TCPIP Stack/UDP.c"  -o ${OBJECTDIR}/_ext/1954962658/UDP.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1954962658/UDP.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_XC16-USB_Thumb_Drive=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -Os -I".." -I"../../Microchip/Include" -I"../../../Microchip/Include" -I"../../../Microchip/Include/TCPIP Stack" -I"../../../Microchip/Include/USB" -I"../../../Microchip/Include/MDD File System" -msmart-io=1 -Wall -msfr-warn=off   -fno-ivopts
	@${FIXDEPS} "${OBJECTDIR}/_ext/1954962658/UDP.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1954962658/UDPPerformanceTest.o: ../../../Microchip/TCPIP\ Stack/UDPPerformanceTest.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1954962658" 
	@${RM} ${OBJECTDIR}/_ext/1954962658/UDPPerformanceTest.o.d 
	@${RM} ${OBJECTDIR}/_ext/1954962658/UDPPerformanceTest.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  "../../../Microchip/TCPIP Stack/UDPPerformanceTest.c"  -o ${OBJECTDIR}/_ext/1954962658/UDPPerformanceTest.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1954962658/UDPPerformanceTest.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_XC16-USB_Thumb_Drive=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -Os -I".." -I"../../Microchip/Include" -I"../../../Microchip/Include" -I"../../../Microchip/Include/TCPIP Stack" -I"../../../Microchip/Include/USB" -I"../../../Microchip/Include/MDD File System" -msmart-io=1 -Wall -msfr-warn=off   -fno-ivopts
	@${FIXDEPS} "${OBJECTDIR}/_ext/1954962658/UDPPerformanceTest.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/549097302/usb_host.o: ../../../Microchip/USB/usb_host.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/549097302" 
	@${RM} ${OBJECTDIR}/_ext/549097302/usb_host.o.d 
	@${RM} ${OBJECTDIR}/_ext/549097302/usb_host.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../../Microchip/USB/usb_host.c  -o ${OBJECTDIR}/_ext/549097302/usb_host.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/549097302/usb_host.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_XC16-USB_Thumb_Drive=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -Os -I".." -I"../../Microchip/Include" -I"../../../Microchip/Include" -I"../../../Microchip/Include/TCPIP Stack" -I"../../../Microchip/Include/USB" -I"../../../Microchip/Include/MDD File System" -msmart-io=1 -Wall -msfr-warn=off   -fno-ivopts
	@${FIXDEPS} "${OBJECTDIR}/_ext/549097302/usb_host.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/172487899/usb_host_msd.o: ../../../Microchip/USB/MSD\ Host\ Driver/usb_host_msd.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/172487899" 
	@${RM} ${OBJECTDIR}/_ext/172487899/usb_host_msd.o.d 
	@${RM} ${OBJECTDIR}/_ext/172487899/usb_host_msd.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  "../../../Microchip/USB/MSD Host Driver/usb_host_msd.c"  -o ${OBJECTDIR}/_ext/172487899/usb_host_msd.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/172487899/usb_host_msd.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_XC16-USB_Thumb_Drive=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -Os -I".." -I"../../Microchip/Include" -I"../../../Microchip/Include" -I"../../../Microchip/Include/TCPIP Stack" -I"../../../Microchip/Include/USB" -I"../../../Microchip/Include/MDD File System" -msmart-io=1 -Wall -msfr-warn=off   -fno-ivopts
	@${FIXDEPS} "${OBJECTDIR}/_ext/172487899/usb_host_msd.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/172487899/usb_host_msd_scsi.o: ../../../Microchip/USB/MSD\ Host\ Driver/usb_host_msd_scsi.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/172487899" 
	@${RM} ${OBJECTDIR}/_ext/172487899/usb_host_msd_scsi.o.d 
	@${RM} ${OBJECTDIR}/_ext/172487899/usb_host_msd_scsi.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  "../../../Microchip/USB/MSD Host Driver/usb_host_msd_scsi.c"  -o ${OBJECTDIR}/_ext/172487899/usb_host_msd_scsi.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/172487899/usb_host_msd_scsi.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_XC16-USB_Thumb_Drive=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -Os -I".." -I"../../Microchip/Include" -I"../../../Microchip/Include" -I"../../../Microchip/Include/TCPIP Stack" -I"../../../Microchip/Include/USB" -I"../../../Microchip/Include/MDD File System" -msmart-io=1 -Wall -msfr-warn=off   -fno-ivopts
	@${FIXDEPS} "${OBJECTDIR}/_ext/172487899/usb_host_msd_scsi.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1472/CustomHTTPApp.o: ../CustomHTTPApp.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/CustomHTTPApp.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/CustomHTTPApp.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../CustomHTTPApp.c  -o ${OBJECTDIR}/_ext/1472/CustomHTTPApp.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/CustomHTTPApp.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_XC16-USB_Thumb_Drive=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -Os -I".." -I"../../Microchip/Include" -I"../../../Microchip/Include" -I"../../../Microchip/Include/TCPIP Stack" -I"../../../Microchip/Include/USB" -I"../../../Microchip/Include/MDD File System" -msmart-io=1 -Wall -msfr-warn=off   -fno-ivopts
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/CustomHTTPApp.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1472/CustomSSLCert.o: ../CustomSSLCert.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/CustomSSLCert.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/CustomSSLCert.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../CustomSSLCert.c  -o ${OBJECTDIR}/_ext/1472/CustomSSLCert.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/CustomSSLCert.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_XC16-USB_Thumb_Drive=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -Os -I".." -I"../../Microchip/Include" -I"../../../Microchip/Include" -I"../../../Microchip/Include/TCPIP Stack" -I"../../../Microchip/Include/USB" -I"../../../Microchip/Include/MDD File System" -msmart-io=1 -Wall -msfr-warn=off   -fno-ivopts
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/CustomSSLCert.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1788384718/FSIO.o: ../../../Microchip/MDD\ File\ System/FSIO.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1788384718" 
	@${RM} ${OBJECTDIR}/_ext/1788384718/FSIO.o.d 
	@${RM} ${OBJECTDIR}/_ext/1788384718/FSIO.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  "../../../Microchip/MDD File System/FSIO.c"  -o ${OBJECTDIR}/_ext/1788384718/FSIO.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1788384718/FSIO.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_XC16-USB_Thumb_Drive=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -Os -I".." -I"../../Microchip/Include" -I"../../../Microchip/Include" -I"../../../Microchip/Include/TCPIP Stack" -I"../../../Microchip/Include/USB" -I"../../../Microchip/Include/MDD File System" -msmart-io=1 -Wall -msfr-warn=off   -fno-ivopts
	@${FIXDEPS} "${OBJECTDIR}/_ext/1788384718/FSIO.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1472/MainDemo.o: ../MainDemo.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/MainDemo.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/MainDemo.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../MainDemo.c  -o ${OBJECTDIR}/_ext/1472/MainDemo.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/MainDemo.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_XC16-USB_Thumb_Drive=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -Os -I".." -I"../../Microchip/Include" -I"../../../Microchip/Include" -I"../../../Microchip/Include/TCPIP Stack" -I"../../../Microchip/Include/USB" -I"../../../Microchip/Include/MDD File System" -msmart-io=1 -Wall -msfr-warn=off   -fno-ivopts
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/MainDemo.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1472/usb_config.o: ../usb_config.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/usb_config.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/usb_config.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../usb_config.c  -o ${OBJECTDIR}/_ext/1472/usb_config.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/usb_config.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_XC16-USB_Thumb_Drive=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -Os -I".." -I"../../Microchip/Include" -I"../../../Microchip/Include" -I"../../../Microchip/Include/TCPIP Stack" -I"../../../Microchip/Include/USB" -I"../../../Microchip/Include/MDD File System" -msmart-io=1 -Wall -msfr-warn=off   -fno-ivopts
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/usb_config.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
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
dist/${CND_CONF}/${IMAGE_TYPE}/MPLAB.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk  ../../../Microchip/TCPIP\ Stack/BigInt_helper_elf.a  
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o dist/${CND_CONF}/${IMAGE_TYPE}/MPLAB.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}    "../../../Microchip/TCPIP Stack/BigInt_helper_elf.a"  -mcpu=$(MP_PROCESSOR_OPTION)        -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -omf=elf -DXPRJ_XC16-USB_Thumb_Drive=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)   -mreserve=data@0x800:0x81B -mreserve=data@0x81C:0x81D -mreserve=data@0x81E:0x81F -mreserve=data@0x820:0x821 -mreserve=data@0x822:0x823 -mreserve=data@0x824:0x827 -mreserve=data@0x82A:0x84F   -Wl,--local-stack,,--defsym=__MPLAB_BUILD=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,--defsym=__MPLAB_DEBUGGER_PK3=1,$(MP_LINKER_FILE_OPTION),--heap=2048,--no-check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--library-path="..",--no-force-link,--smart-io,-Map="$(BINDIR_)$(TARGETBASE).map",--report-mem,--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml$(MP_EXTRA_LD_POST) 
	
else
dist/${CND_CONF}/${IMAGE_TYPE}/MPLAB.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk  ../../../Microchip/TCPIP\ Stack/BigInt_helper_elf.a 
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o dist/${CND_CONF}/${IMAGE_TYPE}/MPLAB.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}    "../../../Microchip/TCPIP Stack/BigInt_helper_elf.a"  -mcpu=$(MP_PROCESSOR_OPTION)        -omf=elf -DXPRJ_XC16-USB_Thumb_Drive=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wl,--local-stack,,--defsym=__MPLAB_BUILD=1,$(MP_LINKER_FILE_OPTION),--heap=2048,--no-check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--library-path="..",--no-force-link,--smart-io,-Map="$(BINDIR_)$(TARGETBASE).map",--report-mem,--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml$(MP_EXTRA_LD_POST) 
	${MP_CC_DIR}/xc16-bin2hex dist/${CND_CONF}/${IMAGE_TYPE}/MPLAB.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} -a  -omf=elf  
	
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/XC16-USB_Thumb_Drive
	${RM} -r dist/XC16-USB_Thumb_Drive

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell "${PATH_TO_IDE_BIN}"mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
