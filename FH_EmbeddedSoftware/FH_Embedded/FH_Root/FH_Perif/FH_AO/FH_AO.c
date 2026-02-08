/**
  * @file
  * @brief
  *       <b>File Map:</b>\n
  *       <b>FH_Root</b>, Section <b>FH_Perif</b>, <b>FH_AO</b> (Analog Output)\n
  *       Functions in this file, handle RFCommunication (<b>RobotFramework</b> <b>C</b>ommunication) for all commands related to <b>AO</b> (Analog Output)
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
#include "../../../../FH_Embedded/FH_Root/FH_Perif/FH_AO/FH_AO.h"

#include "stdio.h"

#if FH_AO_MaxPeripheralNumber > 0    // It is configurable in FH_DevicePeripherals.h

/* Secondary Includes ------------------------------------------------------------------*/
#include "../../../../FH_Embedded/FH_Root/FH_General/FH_GeneralFunctions/FH_GeneralFunctions.h"
#include "../../../../FH_Embedded/FH_Setup/FH_DeviceAddress/FH_DeviceAddress.h"
#include "../../../../FH_Embedded/FH_Setup/FH_RFCommunication/FH_RFCommunication.h"
#include "../../../../FH_Embedded/FH_Root/FH_Perif/FH_AO/Cmd/Init/Init_H/FH_AO_Init_H.h"
#include "../../../../FH_Embedded/FH_Root/FH_Perif/FH_AO/Cmd/Init/Init_C/FH_AO_Init_C.h"
#include "../../../../FH_Embedded/FH_Root/FH_Perif/FH_AO/Cmd/Init/Init_S/FH_AO_Init_S.h"
#include "../../../../FH_Embedded/FH_Root/FH_Perif/FH_AO/Cmd/SetStatus/SetStatus_H/FH_AO_SetStatus_H.h"
#include "../../../../FH_Embedded/FH_Root/FH_Perif/FH_AO/Cmd/SetStatus/SetStatus_C/FH_AO_SetStatus_C.h"
#include "../../../../FH_Embedded/FH_Root/FH_Perif/FH_AO/Cmd/SetStatus/SetStatus_S/FH_AO_SetStatus_S.h"

/**
 * @brief This function is the basic function of handling RFCommunication (<b>RobotFramework</b> <b>C</b>ommunication) for all the <b>Commands</b> related to the <b>Function</b> <b>AO</b> (Analog Output)\n
 *        This function is called from <b>FH_RFCommunication()</b>
 *
 * @param  fh_RFCommunication_Message
 *         The message frame set by <b>RobotFramework</b>
 *
 * @return FH_ErrorInfo is returned
 *

*/
FH_ErrorInfo FH_AO_RFCommunication(FH_RFCommunication_Message* fh_RFCommunication_Message)
{
	FH_ErrorInfo fh_ErrorInfo;    // Error Information
	FH_ResetErrorInfo(&fh_ErrorInfo);    // Reset Error Information to default

	switch (fh_RFCommunication_Message -> Command)    // Check different commands
	{
		case FH_AO_Commands_Init:    // If the command is FH_AO_Commands_Init
			fh_ErrorInfo = FH_AO_ProcessCommand_Init(fh_RFCommunication_Message);    // Handle FH_AO_Commands_Init command
			sprintf(FH_RFCommunication_SendBuf,"%02x|AO|Init|%02x|\n",FH_RFCommunication_DeviceAddress,fh_ErrorInfo.error_code);    // set FH_RFCommunication_SendBuf buffer
			FH_RFCommunication_Send(FH_RFCommunication_SendBuf);    // Send the result back to the Robot Framework
			break;
		case FH_AO_Commands_SetStatus:    // If the command is FH_AO_Commands_SetStatus
			fh_ErrorInfo = FH_AO_ProcessCommand_SetStatus(fh_RFCommunication_Message);    // Handle FH_AO_Commands_SetStatus command
			sprintf(FH_RFCommunication_SendBuf,"%02x|AO|SetStatus|%02x|\n",FH_RFCommunication_DeviceAddress,fh_ErrorInfo.error_code);    // set FH_RFCommunication_SendBuf buffer
			FH_RFCommunication_Send(FH_RFCommunication_SendBuf);    // Send the result back to the Robot Framework
			break;
		default:
			break;
	}
	return fh_ErrorInfo;
}

/**
 * @brief This function handles <b>FH_AO_Commands_Init</b> command\n
 *        There are 3 main items handled in this function as following:\n
 *        1 - Verifying the health of the received message\n
 *        2 - Setting the addresses of the functions in <b>FH_Functions</b>, Section <b>FH_AO</b> (Analog Output) to an array of function pointer\n
 *        3 - Calling the related function in <b>FH_Functions</b>, Section <b>FH_AO</b> (Analog Output) according to the first parameter of the Data in the message frame
 *
 * @param  fh_RFCommunication_Message
 *         The message frame set by <b>RobotFramework</b>
 *
 * @verbatim
    ==============================================================================
                          ##### RobotFramework Example #####
    ==============================================================================
    @{MessageData} =    Create List    ${AO01}
    &{Message}     =    Create Dictionary    DeviceAddress=${DeviceAddress_01}    Function=${Function_AO}    Command=${AO_Commands_Init}    Data=@{MessageData}
    ${Result}    SendMessage    &{Message}

    Comments:

    AO01 => It indicates the Analog Output 01
    DeviceAddress_01 => It shall be equal to the address of the device: FH_RFCommunication_DeviceAddress
    Function_AO => It is the function in the message frame
    AO_Commands_Init => It is the command of the function in the message frame
  @endverbatim
 *
 * @return FH_ErrorInfo is returned
 *

*/
FH_ErrorInfo FH_AO_ProcessCommand_Init(FH_RFCommunication_Message* fh_RFCommunication_Message)
{
	FH_ErrorInfo fh_ErrorInfo;    // Error Information
	FH_ResetErrorInfo(&fh_ErrorInfo);    // Reset Error Information to default

	// 1 - Verifying the health of the received message
	fh_ErrorInfo = FH_AO_Init_H(fh_RFCommunication_Message);
	if (fh_ErrorInfo.error_code != FH_ERROR_OK)    // Check if the message is healthy or not
	{
		return fh_ErrorInfo;    // Return the error
	}

	// 2 - Setting the addresses of the functions in <b>FH_Functions</b>, Section <b>FH_AO</b> (Analog Output) to an array of function pointer
	FH_AO_Init_FuncPtrModel FH_AO_Init_FuncPtr[FH_AO_MaxPeripheralNumber];    // An array of function pointer FH_AO_Init_FuncPtrModel
	FH_AO_Init_S (FH_AO_Init_FuncPtr);    // Setting the address of the functions

	// 3 - Calling the related function in <b>FH_Functions</b>, Section <b>FH_AO</b> (Analog Output) according to the first parameter of the Data in the message frame
	FH_ResetErrorInfo(&fh_ErrorInfo);    // Reset Error Information to default
	fh_ErrorInfo = FH_AO_Init_C (fh_RFCommunication_Message, FH_AO_Init_FuncPtr);    // Calling the related function according to the first parameter of the Data in the message frame
	return fh_ErrorInfo;
}

/**
 * @brief This function handles <b>FH_AO_Commands_SetStatus</b> command\n
 *        There are 3 main items handled in this function as following:\n
 *        1 - Verifying the health of the received message\n
 *        2 - Setting the addresses of the functions in <b>FH_Functions</b>, Section <b>FH_AO</b> (Analog Output) to an array of function pointer\n
 *        3 - Calling the related function in <b>FH_Functions</b>, Section <b>FH_AO</b> (Analog Output) according to the first parameter of the Data in the message frame\n
 *            (The next 4 parameters after the first one, resemble the analog data to be set as one 32 bit data)
 *
 * @param  fh_RFCommunication_Message
 *         The message frame set by <b>RobotFramework</b>
 *
 * @verbatim
    ==============================================================================
                          ##### RobotFramework Example #####
    ==============================================================================
    @{MessageData} =    Create List    ${AO01}    F1    C2    01    08
    &{Message}     =    Create Dictionary    DeviceAddress=${DeviceAddress_01}    Function=${Function_AO}    Command=${AO_Commands_SetStatus}    Data=@{MessageData}
    ${Result}    SendMessage    &{Message}

    Comments:

    AO01 => It indicates the Analog Output 01
    F1    C2    01    08 => Example data as analog value (0xF1C20108) to be set through the <b>Analog Output 01</b>\n
    DeviceAddress_01 => It shall be equal to the address of the device: FH_RFCommunication_DeviceAddress
    Function_AO => It is the function in the message frame
    AO_Commands_SetStatus => It is the command of the function in the message frame
  @endverbatim
 *
 *
 * @return FH_ErrorInfo is returned
 *

*/
FH_ErrorInfo FH_AO_ProcessCommand_SetStatus(FH_RFCommunication_Message* fh_RFCommunication_Message)
{
	FH_ErrorInfo fh_ErrorInfo;    // Error Information
	FH_ResetErrorInfo(&fh_ErrorInfo);    // Reset Error Information to default

	// 1 - Verifying the health of the received message
	fh_ErrorInfo = FH_AO_SetStatus_H(fh_RFCommunication_Message);
	if (fh_ErrorInfo.error_code != FH_ERROR_OK)    // Check if the message is healthy or not
	{
		return fh_ErrorInfo;    // Return the error
	}
	
	// 2 - Setting the addresses of the functions in <b>FH_Functions</b>, Section <b>FH_AO</b> (Analog Output) to an array of function pointer
	FH_AO_SetStatus_FuncPtrModel FH_AO_SetStatus_FuncPtr[FH_AO_MaxPeripheralNumber];    // An array of function pointer FH_AO_SetStatus_FuncPtrModel
	FH_AO_SetStatus_S (FH_AO_SetStatus_FuncPtr);    // Setting the address of the functions

	// 3 - Calling the related function in <b>FH_Functions</b>, Section <b>FH_AO</b> (Analog Output) according to the first parameter of the Data in the message frame
	FH_ResetErrorInfo(&fh_ErrorInfo);    // Reset Error Information to default
	fh_ErrorInfo = FH_AO_SetStatus_C (fh_RFCommunication_Message, FH_AO_SetStatus_FuncPtr);    // Calling the related function according to the first 1 + 4 parameters of the Data in the message frame
	return fh_ErrorInfo;
}
	
#endif
