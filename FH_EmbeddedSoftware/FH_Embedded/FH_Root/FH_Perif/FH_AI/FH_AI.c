/**
  * @file
  * @brief
  *       <b>File Map:</b>\n
  *       <b>FH_Root</b>, Section <b>FH_Perif</b>, <b>FH_AI</b> (Analog Input)\n
  *       Functions in this file, handle RFCommunication (<b>RobotFramework</b> <b>C</b>ommunication) for all commands related to <b>AI</b> (Analog Input)
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
#include "../../../../FH_Embedded/FH_Root/FH_Perif/FH_AI/FH_AI.h"

#include "stdio.h"

#if FH_AI_MaxPeripheralNumber > 0    // It is configurable in FH_DevicePeripherals.h

/* Secondary Includes ------------------------------------------------------------------*/
#include "../../../../FH_Embedded/FH_Root/FH_General/FH_GeneralFunctions/FH_GeneralFunctions.h"
#include "../../../../FH_Embedded/FH_Setup/FH_DeviceAddress/FH_DeviceAddress.h"
#include "../../../../FH_Embedded/FH_Setup/FH_RFCommunication/FH_RFCommunication.h"
#include "../../../../FH_Embedded/FH_Root/FH_Perif/FH_AI/Cmd/Init/Init_H/FH_AI_Init_H.h"
#include "../../../../FH_Embedded/FH_Root/FH_Perif/FH_AI/Cmd/Init/Init_C/FH_AI_Init_C.h"
#include "../../../../FH_Embedded/FH_Root/FH_Perif/FH_AI/Cmd/Init/Init_S/FH_AI_Init_S.h"
#include "../../../../FH_Embedded/FH_Root/FH_Perif/FH_AI/Cmd/GetStatus/GetStatus_H/FH_AI_GetStatus_H.h"
#include "../../../../FH_Embedded/FH_Root/FH_Perif/FH_AI/Cmd/GetStatus/GetStatus_C/FH_AI_GetStatus_C.h"
#include "../../../../FH_Embedded/FH_Root/FH_Perif/FH_AI/Cmd/GetStatus/GetStatus_S/FH_AI_GetStatus_S.h"

/**
 * @brief This function is the basic function of handling RFCommunication (<b>RobotFramework</b> <b>C</b>ommunication) for all the <b>Commands</b> related to the <b>Function</b> <b>AI</b> (Analog Input)\n
 *        This function is called from <b>FH_RFCommunication()</b>
 *
 * @param  fh_RFCommunication_Message
 *         The message frame set by <b>RobotFramework</b>
 *
 * @return FH_ErrorInfo is returned
 *

*/
FH_ErrorInfo FH_AI_RFCommunication(FH_RFCommunication_Message* fh_RFCommunication_Message)
{
	FH_ErrorInfo fh_ErrorInfo;    // Error Information
	FH_ResetErrorInfo(&fh_ErrorInfo);    // Reset Error Information to default

	uint32_t FH_AI_Data;    // It temporarily stores the status of a analog input
	uint32_t* FH_AI_Data_Ptr = &FH_AI_Data;    // Pointer with &FH_AI_Data address

	FH_Uint8Uint32 fh_Uint8Uint32;    // To convert 32 bits data (uint32_t) to four 8 bits data (uint8_t) in FH_PWMI_Frequency

	switch (fh_RFCommunication_Message -> Command)
	{
		case FH_AI_Commands_Init:    // If the command is FH_AI_Commands_Init
			fh_ErrorInfo = FH_AI_ProcessCommand_Init(fh_RFCommunication_Message);    // Handle FH_AI_Commands_Init command
			sprintf(FH_RFCommunication_SendBuf,"%02x|AI|Init|%02x|\n",FH_RFCommunication_DeviceAddress,fh_ErrorInfo.error_code);    // set FH_RFCommunication_SendBuf buffer
			FH_RFCommunication_Send(FH_RFCommunication_SendBuf);  // Send the result back to the Robot Framework
			break;
		case FH_AI_Commands_GetStatus:    // If the command is FH_AI_Commands_GetStatus
			fh_ErrorInfo = FH_AI_ProcessCommand_GetStatus(fh_RFCommunication_Message, FH_AI_Data_Ptr);    // Handle FH_AI_Commands_GetStatus command

			sprintf(FH_RFCommunication_SendBuf,"%02x|AI|GetStatus|%02x|",FH_RFCommunication_DeviceAddress,fh_ErrorInfo.error_code);    // set FH_RFCommunication_SendBuf buffer
			FH_RFCommunication_Send(FH_RFCommunication_SendBuf);  // Send the result back to the Robot Framework

			fh_Uint8Uint32.value = FH_AI_Data;    // set the 32 bit value
			for (int i = 3 ; i >= 0; i--)
			{
				sprintf(FH_RFCommunication_SendBuf,"%02x",fh_Uint8Uint32.bytes[i]);    // Format the data and set FH_RFCommunication_SendBuf buffer
				FH_RFCommunication_Send(FH_RFCommunication_SendBuf);    // Send the result back to the Robot Framework
			}

			sprintf(FH_RFCommunication_SendBuf,"|\n");    // set FH_RFCommunication_SendBuf buffer
			FH_RFCommunication_Send(FH_RFCommunication_SendBuf);    // Send the result back to the Robot Framework
			break;
		default:
			break;
	}
	return fh_ErrorInfo;
}

/**
 * @brief This function handles <b>FH_AI_Commands_Init</b> command\n
 *        There are 3 main items handled in this function as following:\n
 *        1 - Verifying the health of the received message\n
 *        2 - Setting the addresses of the functions in <b>FH_Functions</b>, Section <b>FH_AI</b> (Analog Input) to an array of function pointer\n
 *        3 - Calling the related function in <b>FH_Functions</b>, Section <b>FH_AI</b> (Analog Input) according to the first parameter of the Data in the message frame
 *
 * @param  fh_RFCommunication_Message
 *         The message frame set by <b>RobotFramework</b>
 *
 * @verbatim
    ==============================================================================
                          ##### RobotFramework Example #####
    ==============================================================================
    @{MessageData} =    Create List    ${AI01}
    &{Message}     =    Create Dictionary    DeviceAddress=${DeviceAddress_01}    Function=${Function_AI}    Command=${AI_Commands_Init}    Data=@{MessageData}
    ${Result}    SendMessage    &{Message}

    Comments:

    AI01 => It indicates the Analog Input 01
    DeviceAddress_01 => It shall be equal to the address of the device: FH_RFCommunication_DeviceAddress
    Function_AI => It is the function in the message frame
    AI_Commands_Init => It is the command of the function in the message frame
  @endverbatim
 *
 * @return FH_ErrorInfo is returned
 *

*/
FH_ErrorInfo FH_AI_ProcessCommand_Init(FH_RFCommunication_Message* fh_RFCommunication_Message)
{
	FH_ErrorInfo fh_ErrorInfo;    // Error Information
	FH_ResetErrorInfo(&fh_ErrorInfo);    // Reset Error Information to default

	// Item 1 - Verifying the health of the received message
	fh_ErrorInfo = FH_AI_Init_H(fh_RFCommunication_Message);
	if (fh_ErrorInfo.error_code != FH_ERROR_OK)    // Check if the message is healthy or not
	{
		return fh_ErrorInfo;    // Return the error
	}

	// 2 - Setting the addresses of the functions in <b>FH_Functions</b>, Section <b>FH_AI</b> (Analog Input) to an array of function pointer
	FH_AI_Init_FuncPtrModel FH_AI_Init_FuncPtr[FH_AI_MaxPeripheralNumber];    // An array of function pointer FH_AI_Init_FuncPtrModel
	FH_AI_Init_S (FH_AI_Init_FuncPtr);   // Setting the address of the functions

	// 3 - Calling the related function in <b>FH_Functions</b>, Section <b>FH_AI</b> (Analog Input) according to the first parameter of the Data in the message frame
	FH_ResetErrorInfo(&fh_ErrorInfo);    // Reset Error Information to default
	fh_ErrorInfo = FH_AI_Init_C (fh_RFCommunication_Message, FH_AI_Init_FuncPtr);    // Calling the related function according to the first parameter of the Data in the message frame
	return fh_ErrorInfo;
}

/**
 * @brief This function handles <b>FH_AI_Commands_GetStatus</b> command\n
 *        There are 3 main items handled in this function as following:\n
 *        1 - Verifying the health of the received message\n
 *        2 - Setting the addresses of the functions in <b>FH_Functions</b>, Section <b>FH_AI</b> (Analog Input) to an array of function pointer\n
 *        3 - Calling the related function in <b>FH_Functions</b>, Section <b>FH_AI</b> (Analog Input) according to the first parameter of the Data in the message frame
 *
 * @param  fh_RFCommunication_Message
 *         The message frame set by <b>RobotFramework</b>
 *
 * @verbatim
    ==============================================================================
                          ##### RobotFramework Example #####
    ==============================================================================
    @{MessageData} =    Create List    ${AI01}
    &{Message}     =    Create Dictionary    DeviceAddress=${DeviceAddress_01}    Function=${Function_AI}    Command=${AI_Commands_GetStatus}    Data=@{MessageData}
    ${Result}    SendMessage    &{Message}

    Comments:

    AI01 => It indicates the Analog Input 01
    DeviceAddress_01 => It shall be equal to the address of the device: FH_RFCommunication_DeviceAddress
    Function_AI => It is the function in the message frame
    AI_Commands_GetStatus => It is the command of the function in the message frame
  @endverbatim
 *
 *
 * @return FH_ErrorInfo is returned
 *

*/
FH_ErrorInfo FH_AI_ProcessCommand_GetStatus(FH_RFCommunication_Message* fh_RFCommunication_Message, uint32_t* FH_AI_Data)
{
	FH_ErrorInfo fh_ErrorInfo;    // Error Information
	FH_ResetErrorInfo(&fh_ErrorInfo);    // Reset Error Information to default

	// Item 1 - Verifying the health of the received message
	fh_ErrorInfo = FH_AI_GetStatus_H(fh_RFCommunication_Message);
	if (fh_ErrorInfo.error_code != FH_ERROR_OK)    // Check if the message is healthy or not
	{
		return fh_ErrorInfo;    // Return the error
	}

	// 2 - Setting the addresses of the functions in <b>FH_Functions</b>, Section <b>FH_AI</b> (Analog Input) to an array of function pointer
	FH_AI_GetStatus_FuncPtrModel FH_AI_GetStatus_FuncPtr[FH_AI_MaxPeripheralNumber];    // An array of function pointer FH_AI_GetStatus_FuncPtrModel
	FH_AI_GetStatus_S (FH_AI_GetStatus_FuncPtr);   // Setting the address of the functions

	// 3 - Calling the related function in <b>FH_Functions</b>, Section <b>FH_AI</b> (Analog Input) according to the first parameter of the Data in the message frame
	FH_ResetErrorInfo(&fh_ErrorInfo);    // Reset Error Information to default
	fh_ErrorInfo = FH_AI_GetStatus_C (fh_RFCommunication_Message, FH_AI_Data, FH_AI_GetStatus_FuncPtr);    // Calling the related function according to the first parameter of the Data in the message frame
	return fh_ErrorInfo;
}
	
#endif
