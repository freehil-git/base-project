/**
  * @file
  * @brief
  *       <b>File Map:</b>\n
  *       <b>FH_Root</b>, Section <b>FH_Perif</b>, <b>FH_DO</b> (Digital Output)\n
  *       Functions in this file, handle RFCommunication (<b>RobotFramework</b> <b>C</b>ommunication) for all commands related to <b>DO</b> (Digital Output)
  *
  * @attention <b>FH</b> user could left this file intact
  *
  *******************************************************************************
  * SPDX-License-Identifier: Apache-2.0
 *
 * Copyright 2026 Vahid Hasirchi
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
  ********************************************************************************

  *
  * <b>For more information refer to FreeHIL.com</b>
  *
*/
/* Primary Includes ------------------------------------------------------------------*/
#include "../../../../FH_Embedded/FH_Root/FH_Perif/FH_DO/FH_DO.h"

#include "stdio.h"

#if FH_DO_MaxPeripheralNumber > 0    // It is configurable in FH_DevicePeripherals.h

/* Secondary Includes ------------------------------------------------------------------*/
#include "../../../../FH_Embedded/FH_Root/FH_General/FH_GeneralFunctions/FH_GeneralFunctions.h"
#include "../../../../FH_Embedded/FH_Setup/FH_DeviceAddress/FH_DeviceAddress.h"
#include "../../../../FH_Embedded/FH_Setup/FH_RFCommunication/FH_RFCommunication.h"
#include "../../../../FH_Embedded/FH_Root/FH_Perif/FH_DO/Cmd/Init/Init_H/FH_DO_Init_H.h"
#include "../../../../FH_Embedded/FH_Root/FH_Perif/FH_DO/Cmd/Init/Init_C/FH_DO_Init_C.h"
#include "../../../../FH_Embedded/FH_Root/FH_Perif/FH_DO/Cmd/Init/Init_S/FH_DO_Init_S.h"
#include "../../../../FH_Embedded/FH_Root/FH_Perif/FH_DO/Cmd/SetStatus/SetStatus_H/FH_DO_SetStatus_H.h"
#include "../../../../FH_Embedded/FH_Root/FH_Perif/FH_DO/Cmd/SetStatus/SetStatus_C/FH_DO_SetStatus_C.h"
#include "../../../../FH_Embedded/FH_Root/FH_Perif/FH_DO/Cmd/SetStatus/SetStatus_S/FH_DO_SetStatus_S.h"

/**
 * @brief This function is the basic function of handling RFCommunication (<b>RobotFramework</b> <b>C</b>ommunication) for all the <b>Commands</b> related to the <b>Function</b> <b>DO</b> (Digital Output)\n
 *        This function is called from <b>FH_RFCommunication()</b>
 *
 * @param  fh_RFCommunication_Message
 *         The message frame set by <b>RobotFramework</b>
 *
 * @return FH_ErrorInfo is returned
 *

*/
FH_ErrorInfo FH_DO_RFCommunication (FH_RFCommunication_Message* fh_RFCommunication_Message)
{
	FH_ErrorInfo fh_ErrorInfo;    // Error Information
	FH_ResetErrorInfo(&fh_ErrorInfo);    // Reset Error Information to default

	switch (fh_RFCommunication_Message -> Command)    // Check different commands
	{
		case FH_DO_Commands_Init:    // If the command is FH_DO_Commands_Init
			fh_ErrorInfo = FH_DO_ProcessCommand_Init(fh_RFCommunication_Message);    // Handle FH_DO_Commands_Init command
			sprintf(FH_RFCommunication_SendBuf,"%02x|DO|Init|%02x|\n",FH_RFCommunication_DeviceAddress,fh_ErrorInfo.error_code);    // set FH_RFCommunication_SendBuf buffer
			FH_RFCommunication_Send(FH_RFCommunication_SendBuf);    // Send the result back to the Robot Framework
			break;
		case FH_DO_Commands_SetStatus:    // If the command is FH_DO_Commands_SetStatus
			fh_ErrorInfo = FH_DO_ProcessCommand_SetStatus(fh_RFCommunication_Message);    // Handle FH_DO_Commands_SetStatus command
			sprintf(FH_RFCommunication_SendBuf,"%02x|DO|SetStatus|%02x|\n",FH_RFCommunication_DeviceAddress,fh_ErrorInfo.error_code);    // set FH_RFCommunication_SendBuf buffer
			FH_RFCommunication_Send(FH_RFCommunication_SendBuf);    // Send the result back to the Robot Framework
			break;
		case FH_DO_Commands_InitMULTI:    // If the command is FH_DO_Commands_InitMULTI
			fh_ErrorInfo = FH_DO_ProcessCommand_InitMULTI(fh_RFCommunication_Message);    // Handle FH_DO_Commands_InitMULTI command
			sprintf(FH_RFCommunication_SendBuf,"%02x|DO|InitMULTI|%02x|\n",FH_RFCommunication_DeviceAddress,fh_ErrorInfo.error_code);    // set FH_RFCommunication_SendBuf buffer
			FH_RFCommunication_Send(FH_RFCommunication_SendBuf);    // Send the result back to the Robot Framework
			break;
		case FH_DO_Commands_SetStatusMULTI:    // If the command is FH_DO_Commands_SetStatusMULTI
			fh_ErrorInfo = FH_DO_ProcessCommand_SetStatusMULTI(fh_RFCommunication_Message);    // Handle FH_DO_Commands_SetStatusMULTI command
			sprintf(FH_RFCommunication_SendBuf,"%02x|DO|SetStatusMULTI|%02x|\n",FH_RFCommunication_DeviceAddress,fh_ErrorInfo.error_code);    // set FH_RFCommunication_SendBuf buffer
			FH_RFCommunication_Send(FH_RFCommunication_SendBuf);    // Send the result back to the Robot Framework
			break;
		default:
			break;
	}
	return fh_ErrorInfo;
}

/**
 * @brief This function handles <b>FH_DO_Commands_Init</b> command\n
 *        There are 3 main items handled in this function as following:\n
 *        1 - Verifying the health of the received message\n
 *        2 - Setting the addresses of the functions in <b>FH_Functions</b>, Section <b>FH_DO</b> (Digital Output) to an array of function pointer\n
 *        3 - Calling the related function in <b>FH_Functions</b>, Section <b>FH_DO</b> (Digital Output) according to the first parameter of the Data in the message frame
 *
 * @param  fh_RFCommunication_Message
 *         The message frame set by <b>RobotFramework</b>
 *
 * @verbatim
    ==============================================================================
                          ##### RobotFramework Example #####
    ==============================================================================
    @{MessageData} =    Create List    ${DO01}
    &{Message}     =    Create Dictionary    DeviceAddress=${DeviceAddress_01}    Function=${Function_DO}    Command=${DO_Commands_Init}    Data=@{MessageData}
    ${Result}    SendMessage    &{Message}

    Comments:

    DO01 => It indicates the Digital Output 01
    DeviceAddress_01 => It shall be equal to the address of the device: FH_RFCommunication_DeviceAddress
    Function_DO => It is the function in the message frame
    DO_Commands_Init => It is the command of the function in the message frame
  @endverbatim
 *
 *
 * @return FH_ErrorInfo is returned
 *

*/
FH_ErrorInfo FH_DO_ProcessCommand_Init(FH_RFCommunication_Message* fh_RFCommunication_Message)
{
	FH_ErrorInfo fh_ErrorInfo;    // Error Information
	FH_ResetErrorInfo(&fh_ErrorInfo);    // Reset Error Information to default

    // Item 1 - Verifying the health of the received message
	fh_ErrorInfo = FH_DO_Init_H(fh_RFCommunication_Message);    // Calling the related health function
	if (fh_ErrorInfo.error_code != FH_ERROR_OK)    // Check if the message is healthy or not
	{
		return fh_ErrorInfo;    // Return the error
	}

	// Item 2 - Setting the addresses of the functions in <b>FH_Functions</b>, Section <b>FH_DO</b> (Digital Output) to an array of function pointer
	FH_DO_Init_FuncPtrModel FH_DO_Init_FuncPtr[FH_DO_MaxPeripheralNumber];    // An array of function pointer FH_DO_Init_FuncPtrModel
	FH_DO_Init_S (FH_DO_Init_FuncPtr);    // Setting the address of the functions

	// Item 3 - Calling the related function in <b>FH_Functions</b>, Section <b>FH_DO</b> (Digital Output) according to the first parameter of the Data in the message frame
	FH_ResetErrorInfo(&fh_ErrorInfo);    // Reset Error Information to default
	fh_ErrorInfo = FH_DO_Init_C (fh_RFCommunication_Message, FH_DO_Init_FuncPtr);    // Calling the related function according to the first parameter of the Data in the message frame
	return fh_ErrorInfo;
}

/**
 * @brief This function handles <b>FH_DO_Commands_SetStatus</b> command\n
 *        There are 3 main items handled in this function as following:\n
 *        1 - Verifying the health of the received message\n
 *        2 - Setting the addresses of the functions in <b>FH_Functions</b>, Section <b>FH_DO</b> (Digital Output) to an array of function pointer\n
 *        3 - Calling the related function in <b>FH_Functions</b>, Section <b>FH_DO</b> (Digital Output) according to the first parameter of the Data in the message frame
 *            (The second parameter resemble the digital data to be set as 1 or 0)
 *
 * @param  fh_RFCommunication_Message
 *         The message frame set by <b>RobotFramework</b>
 *
 * @verbatim
    ==============================================================================
                          ##### RobotFramework Example #####
    ==============================================================================
    @{MessageData} =    Create List    ${DO01}    ${DO_Set}
    &{Message}     =    Create Dictionary    DeviceAddress=${DeviceAddress_01}    Function=${Function_DO}    Command=${DO_Commands_SetStatus}    Data=@{MessageData}
    ${Result}    SendMessage    &{Message}

    Comments:

    DO01 => It indicates the Digital Output 01
    DO_Set => It indicates the Digital Output 01 shall be Set (DO_Reset indicates the Digital Output 01 shall be Reset)
    DeviceAddress_01 => It shall be equal to the address of the device: FH_RFCommunication_DeviceAddress
    Function_DO => It is the function in the message frame
    DO_Commands_SetStatus => It is the command of the function in the message frame
  @endverbatim
 *
 *
 * @return FH_ErrorInfo is returned
 *

*/
FH_ErrorInfo FH_DO_ProcessCommand_SetStatus(FH_RFCommunication_Message* fh_RFCommunication_Message)
{
	FH_ErrorInfo fh_ErrorInfo;    // Error Information
	FH_ResetErrorInfo(&fh_ErrorInfo);    // Reset Error Information to default

    // Item 1 - Verifying the health of the received message
	fh_ErrorInfo = FH_DO_SetStatus_H(fh_RFCommunication_Message);    // Calling the related health function
	if (fh_ErrorInfo.error_code != FH_ERROR_OK)    // Check if the message is healthy or not
	{
		return fh_ErrorInfo;    // Return the error
	}
	
	// Item 2 - Setting the addresses of the functions in <b>FH_Functions</b>, Section <b>FH_DO</b> (Digital Output) to an array of function pointer
	FH_DO_SetStatus_FuncPtrModel FH_DO_SetStatus_FuncPtr[FH_DO_MaxPeripheralNumber];    // An array of function pointer FH_DO_Init_FuncPtrModel
	FH_DO_SetStatus_S (FH_DO_SetStatus_FuncPtr);    // Setting the address of the functions

	// Item 3 - Calling the related function in <b>FH_Functions</b>, Section <b>FH_DO</b> (Digital Output) according to the first parameter of the Data in the message frame
	FH_ResetErrorInfo(&fh_ErrorInfo);    // Reset Error Information to default
	fh_ErrorInfo = FH_DO_SetStatus_C (fh_RFCommunication_Message, FH_DO_SetStatus_FuncPtr);    // Calling the related function according to the first parameter of the Data in the message frame
	return fh_ErrorInfo;
}

/**
 * @brief This function handles <b>FH_DO_ProcessCommand_InitMULTI</b> command\n
 *        With this function, mass initialization of up to 64 <b>DO</b> (Digital Output) is possible instead of just 1 <b>DO</b> (Digital Output)\n
 *        There are 3 main items handled in this function as following:\n
 *        1 - Verifying the health of the received message\n
 *        2 - Setting the addresses of the functions in <b>FH_Functions</b>, Section <b>FH_DO</b> (Digital Output) to an array of function pointer\n
 *        3 - Calling the related function(s) in <b>FH_Functions</b>, Section <b>FH_DO</b> (Digital Output) according to the 8 first parameters of the Data in the message frame
 *            (The first 8 bytes resemble 64 bits and each bit resembles 1 <b>DO</b> (Digital Output) and if the bit is 1, the related <b>DO</b> (Digital Output) function will be called)
 *
 * @param  fh_RFCommunication_Message
 *         The message frame set by <b>RobotFramework</b>
 *
 * @verbatim
    ==============================================================================
                          ##### RobotFramework Example #####
    ==============================================================================
    @{MessageData} =    Create List    FF    FF    FF    FF    FF    FF    FF    FF
    &{Message}     =    Create Dictionary    DeviceAddress=${DeviceAddress_01}    Function=${Function_DO}    Command=${DO_Commands_InitMULTI}    Data=@{MessageData}
    ${Result}    SendMessage    &{Message}

    Comments:

	FF    FF    FF    FF    FF    FF    FF    FF => Example data as the first 8 parameters of the Data in the message frame utilized as mask (In this example it means all 64 digital outputs shall be initialized)
    DeviceAddress_01 => It shall be equal to the address of the device: FH_RFCommunication_DeviceAddress
    Function_DO => It is the function in the message frame
    DO_Commands_InitMULTI => It is the command of the function in the message frame
  @endverbatim
 *
 * @return FH_ErrorInfo is returned
 *

*/
FH_ErrorInfo FH_DO_ProcessCommand_InitMULTI(FH_RFCommunication_Message* fh_RFCommunication_Message)
{
	FH_ErrorInfo fh_ErrorInfo;    // Error Information
	FH_ResetErrorInfo(&fh_ErrorInfo);    // Reset Error Information to default

    // Item 1 - Verifying the health of the received message
	fh_ErrorInfo = FH_DO_InitMULTI_H(fh_RFCommunication_Message);    // Calling the related health function
	if (fh_ErrorInfo.error_code != FH_ERROR_OK)    // Check if the message is healthy or not
	{
		return fh_ErrorInfo;    // Return the error
	}

	// Item 2 - Setting the addresses of the functions in <b>FH_Functions</b>, Section <b>FH_DO</b> (Digital Output) to an array of function pointer
	FH_DO_Init_FuncPtrModel FH_DO_Init_FuncPtr[FH_DO_MaxPeripheralNumber];    // An array of function pointer FH_DO_Init_FuncPtrModel
	FH_DO_Init_S (FH_DO_Init_FuncPtr);    // Setting the address of the functions

	// Item 3 - Calling the related function(s) in <b>FH_Functions</b>, Section <b>FH_DO</b> (Digital Output) according to the 8 first parameters of the Data in the message frame
	//          (8 bytes resemble 64 bits and each bit resembles 1 <b>DO</b> (Digital Output) and if the bit is 1, the related <b>DO</b> (Digital Output) function will be called)
	FH_ResetErrorInfo(&fh_ErrorInfo);    // Reset Error Information to default
	fh_ErrorInfo = FH_DO_InitMULTI_C (fh_RFCommunication_Message, FH_DO_Init_FuncPtr);    // Calling the related function according to the first 8 parameters of Data in the message frame
	return fh_ErrorInfo;
}

/**
 * @brief This function handles <b>FH_DO_ProcessCommand_SetStatusMULTI</b> command\n
 *        With this function, mass status set of up to 64 <b>DO</b> (Digital Output) is possible instead of just 1 <b>DO</b> (Digital Output)\n
 *        There are 3 main items handled in this function as following:\n
 *        1 - Verifying the health of the received message\n
 *        2 - Setting the addresses of the functions in <b>FH_Functions</b>, Section <b>FH_DO</b> (Digital Output) to an array of function pointer\n
 *        3 - Calling the related function in <b>FH_Functions</b>, Section <b>FH_DO</b> (Digital Output) according to the 16 first parameters of the Data in the message frame\n
 *            (The first  8 bytes as mask resemble 64 bits and each bit resembles 1 <b>DO</b> (Digital Output) and if the bit is 1, the related <b>DO</b> (Digital Output) function will be called)\n
 *            (The second 8 bytes as data resemble 64 bits and each bit resembles status of 1 <b>DO</b> (Digital Output) as 1 or 0 of the corresponding bit in the first 8 bytes)
 *
 * @param  fh_RFCommunication_Message
 *         The message frame set by <b>RobotFramework</b>
 *
 * @verbatim
    ==============================================================================
                          ##### RobotFramework Example #####
    ==============================================================================
    @{MessageData} =    Create List    FF    FF    FF    FF    FF    FF    FF    FF    01    02    03    04    05    06    07    08
    &{Message}     =    Create Dictionary    DeviceAddress=${DeviceAddress_01}    Function=${Function_DO}    Command=${DO_Commands_SetStatusMULTI}    Data=@{MessageData}
    ${Result}    SendMessage    &{Message}

    Comments:

	FF    FF    FF    FF    FF    FF    FF    FF => Example data as the first 8 parameters of the Data in the message frame utilized as mask (In this example it means all 64 digital outputs shall set status)
	01    02    03    04    05    06    07    08 => Example data as the second 8 parameters of the Data in the message frame as data value of 1 or 0, corresponding to the first 8 bytes)
    DeviceAddress_01 => It shall be equal to the address of the device: FH_RFCommunication_DeviceAddress
    Function_DO => It is the function in the message frame
    DO_Commands_SetStatusMULTI => It is the command of the function in the message frame
  @endverbatim
 *
 * @return FH_ErrorInfo is returned
 *

*/
FH_ErrorInfo FH_DO_ProcessCommand_SetStatusMULTI(FH_RFCommunication_Message* fh_RFCommunication_Message)
{
	FH_ErrorInfo fh_ErrorInfo;    // Error Information
	FH_ResetErrorInfo(&fh_ErrorInfo);    // Reset Error Information to default

    // Item 1 - Verifying the health of the received message
	fh_ErrorInfo = FH_DO_SetStatusMULTI_H(fh_RFCommunication_Message);    // Calling the related health function
	if (fh_ErrorInfo.error_code != FH_ERROR_OK)
	{
		return fh_ErrorInfo;    // Return the error
	}
	
	// Item 2 - Setting the addresses of the functions in <b>FH_Functions</b>, Section <b>FH_DO</b> (Digital Output) to an array of function pointer
	FH_DO_SetStatus_FuncPtrModel FH_DO_SetStatus_FuncPtr[FH_DO_MaxPeripheralNumber];    // An array of function pointer FH_DO_Init_FuncPtrModel
	FH_DO_SetStatus_S (FH_DO_SetStatus_FuncPtr);    // Setting the address of the functions

	// 3 - Calling the related function in <b>FH_Functions</b>, Section <b>FH_DO</b> (Digital Output) according to the 16 first parameters of the Data in the message frame
	//     (First  8 bytes as mask resemble 64 bits and each bit resembles 1 <b>DO</b> (Digital Output) and if the bit is 1, the related <b>DO</b> (Digital Output) function will be called)
	//     (Second 8 bytes as data resemble 64 bits and each bit resembles status of 1 <b>DO</b> (Digital Output) as 1 or 0 of the corresponding bit in the first 8 bytes)
	FH_ResetErrorInfo(&fh_ErrorInfo);    // Reset Error Information to default
	fh_ErrorInfo = FH_DO_SetStatusMULTI_C (fh_RFCommunication_Message, FH_DO_SetStatus_FuncPtr);    // Calling the related function according to the first 8 parameters of the Data in the message frame
	return fh_ErrorInfo;
}
	
#endif
