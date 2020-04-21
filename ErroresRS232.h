//==============================================================================
//
// Title:       RS232Errors.h
// Purpose:     A short description of the interface.
//
// Created on:  02/10/2016 at 16:56:18 by SEGAINVEX.
// Copyright:   UNIVERSIDAD AUTONOMA DE MADRID. All Rights Reserved.
//
//==============================================================================

#ifndef __RS232Errors_H__
#define __RS232Errors_H__

//#ifdef __cplusplus
//    extern "C" {
//#endif

//==============================================================================
// Include files

#include "cvidef.h"

//==============================================================================
// Types
struct RS232Error{
	int CodigoError;
	char *ClaveError;
	char *DescripcionError;
	};
//==============================================================================
// Constants
struct RS232Error RS232DescripcionDeError[]={
	
/*01*/ -1, "kRS_UnknownSysError", "Unknown system error. ",
/*02*/ -2, "kRS_InvalidPortNum", " Invalid port number. ",
/*03*/ -3, "kRS_PortNotOpen Port", " is not open. ",
/*04*/ -4, "kRS_UnknownIOError", " Unknown I/O error. ",
/*05*/ -5, "kRS_InternalError", " Unexpected internal error. ",
/*06*/ -6, "kRS_NoPortFound", " No serial port found. ",
/*07*/ -7, "kRS_CanNotOpenPort", " Cannot open port. ",
/*08*/ -8, "kRS_NullPointerPassed", " A NULL pointer was passed when a non-NULL pointer was expected. ",
/*09*/ -11, "kRS_OutOfMemory"," Out of memory. ",
/*10*/ -12, "kRS_OutOfSystemResources", " Unable to allocate system resources. ",
/*11*/ -13, "kRS_InvalidParameter", " Invalid parameter. ",
/*12*/ -14, "kRS_InvalidBaudRate", " Invalid baud rate. ",
/*13*/ -24, "kRS_InvalidParity", " Invalid parity. ",
/*14*/ -34, "kRS_InvalidDataBits", " Invalid number of data bits. ",
/*15*/ -44, "kRS_InvalidStopBits", " Invalid number of stop bits. ",
/*16*/ -90, "kRS_BadFileHandle", " Bad file handle. ",
/*17*/ -91, "kRS_FileIOError", " File I/O error. ",
/*18*/ -94, "kRS_InvalidCount", " Invalid count; must be greater than or equal to 0. ",
/*19*/ -97, "kRS_InvalidIntLevel", " Invalid interrupt level. ",
/*20*/ -99, "kRS_IOTimeOut", " I/O operation timed out. ",
/*21*/ -104, "kRS_InvalidBreakTime", " Break time must be a positive value. ",
/*22*/ -114, "kRS_InvalidInQSize", " Requested input queue size must be 0 or greater. ",
/*23*/ -124, "kRS_InvalidOutQSize", " Requested output queue size must be 0 or greater. ",
/*24*/ -151, "kRS_GeneralIOFailure", " General I/O error. ",
/*25*/ -152, "kRS_InvalidBufferPointer", " Buffer parameter is NULL. ",
/*26*/ -180, "kRS_VISALibrariesMissing", " A necessary run-time library could not be found or loaded. ",
/*27*/ -257, "kRS_NoAckReceived Packet", " was sent, but no acknowledgment was received. ",
/*28*/ -258, "kRS_MaxRetriesBeforeSend", " Packet was not sent within retry limit. ",
/*29*/ -259, "kRS_MaxRetriesBeforeReceived", " Packet was not received within retry limit.", 							
/*30*/ -260, "kRS_UnexpectedEOT", " End of transmission character encountered when start of data character expected. ",
/*31*/ -261, "kRS_CanNotReadPackNum", " Unable to read packet number. ",
/*32*/ -262, "kRS_InconsistentPackNum", " Inconsistent packet number. ",
/*33*/ -263, "kRS_CanNotReadPackData", " Unable to read packet data. ",
/*34*/ -264, "kRS_CanNotReadCheckSum", " Unable to read checksum. ",
/*35*/ -265, "kRS_CheckSumError", " Checksum received did not match computed checksum. ",
/*36*/ -269, "kRS_PackSizeGTInQ", " Packet size exceeds input queue size. ",
/*37*/ -300, "kRS_OpenFileError", " Error opening file.   ",
/*38*/ -301, "kRS_ReadFileError", " Error reading file. ",
/*39*/ -302, "kRS_NoInitNegAck", " Did not receive initial negative acknowledgment character. ",
/*40*/ -303, "kRS_NoAckAfterEOT", " Did not receive acknowledgment after end of transmission character was sent. ",
/*41*/ -304, "kRS_WriteFileError", " Error writing to file. ",
/*42*/ -305, "kRS_NoSOHorEOT", " Did not receive either a start of data or end of transmission character when expected. ",
/*43*/ -402, "kRS_TransferCancelled", " Transfer was canceled because CAN ASCII character was received. ",
/*44*/ -503, "kRS_InvalidStartDelay", " Invalid start delay. ",
/*45*/ -504, "kRS_InvalidMaxTries", " Invalid maximum number of retries. ",
/*46*/ -505, "kRS_InvalidWaitPeriod", " Invalid wait period.", 
/*47*/ -506, "kRS_InvalidPacketSize", " Invalid packet size. ",
/*48*/ -507, "kRS_CanNotReadCRC", " Unable to read Cyclical Redundancy Check.", 
/*49*/ -508, "kRS_CRCError", " Cyclical Redundancy Check error.", 
};



//==============================================================================
// External variables

//==============================================================================
// Global functions


#endif  /* ndef __RS232Errors_H__ */
