/**
  * @file
  * @brief
  *       <b>File Map:</b>\n
  *       <b>FH_Root</b>, Section <b>FH_Perif</b>, <b>FH_PWMI</b> (PWM Input)\n
  *       Functions in this file, handle RFCommunication (<b>RobotFramework</b> <b>C</b>ommunication) for all commands related to <b>PWMI</b> (PWM Input)
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
#include "../../../../FH_Embedded/FH_Root/FH_Perif/FH_PWMI/FH_PWMI.h"

#include "stdio.h"

#if FH_PWMI_MaxPeripheralNumber > 0    // It is configurable in FH_DevicePeripherals.h

/* Secondary Includes ------------------------------------------------------------------*/
#include "../../../../FH_Embedded/FH_Root/FH_General/FH_GeneralFunctions/FH_GeneralFunctions.h"
#include "../../../../FH_Embedded/FH_Setup/FH_DeviceAddress/FH_DeviceAddress.h"
#include "../../../../FH_Embedded/FH_Setup/FH_RFCommunication/FH_RFCommunication.h"
#include "../../../../FH_Embedded/FH_Root/FH_Perif/FH_PWMI/Cmd/Init/Init_H/FH_PWMI_Init_H.h"
#include "../../../../FH_Embedded/FH_Root/FH_Perif/FH_PWMI/Cmd/Init/Init_C/FH_PWMI_Init_C.h"
#include "../../../../FH_Embedded/FH_Root/FH_Perif/FH_PWMI/Cmd/Init/Init_S/FH_PWMI_Init_S.h"
#include "../../../../FH_Embedded/FH_Root/FH_Perif/FH_PWMI/Cmd/GetStatus/GetStatus_H/FH_PWMI_GetStatus_H.h"
#include "../../../../FH_Embedded/FH_Root/FH_Perif/FH_PWMI/Cmd/GetStatus/GetStatus_C/FH_PWMI_GetStatus_C.h"
#include "../../../../FH_Embedded/FH_Root/FH_Perif/FH_PWMI/Cmd/GetStatus/GetStatus_S/FH_PWMI_GetStatus_S.h"

/**
 * @brief This function is the basic function of handling RFCommunication (<b>RobotFramework</b> <b>C</b>ommunication) for all the <b>Commands</b> related to the <b>Function</b> <b>PWMI</b> (PWM Input)\n
 *        This function is called from <b>FH_RFCommunication()</b>
 *
 * @param  fh_RFCommunication_Message
 *         The message frame set by <b>RobotFramework</b>
 *
 * @return FH_ErrorInfo is returned
 *

*/
FH_ErrorInfo FH_PWMI_RFCommunication(FH_RFCommunication_Message* fh_RFCommunication_Message)
{
	FH_ErrorInfo fh_ErrorInfo;    // Error Information
	FH_ResetErrorInfo(&fh_ErrorInfo);    // Reset Error Information to default

	uint32_t FH_PWMI_Frequency;    // It temporarily stores the frequency of a PWM input
	uint32_t* FH_PWMI_Frequency_Ptr = &FH_PWMI_Frequency;    // Pointer with &FH_PWMI_Frequency address

	uint8_t FH_PWMI_DutyCycle;    // It temporarily stores the duty cycle of a PWM input
	uint8_t* FH_PWMI_DutyCycle_Ptr = &FH_PWMI_DutyCycle;    // Pointer with &FH_PWMI_DutyCycle address

	FH_Uint8Uint32 fh_Uint8Uint32;    // To convert 32 bits data (uint32_t) to four 8 bits data (uint8_t) in FH_PWMI_Frequency

	switch (fh_RFCommunication_Message -> Command)
	{
		case FH_PWMI_Commands_Init:    // If the command is FH_PWMI_Commands_Init
			fh_ErrorInfo = FH_PWMI_ProcessCommand_Init(fh_RFCommunication_Message);    // Handle FH_PWMI_Commands_Init command
			sprintf(FH_RFCommunication_SendBuf,"%02x|PWMI|Init|%02x|\n",FH_RFCommunication_DeviceAddress,fh_ErrorInfo.error_code);    // set FH_RFCommunication_SendBuf buffer
			FH_RFCommunication_Send(FH_RFCommunication_SendBuf);  // Send the result back to the Robot Framework
			break;
		case FH_PWMI_Commands_GetStatus:    // If the command is FH_PWMI_Commands_GetStatus
			fh_ErrorInfo = FH_PWMI_ProcessCommand_GetStatus(fh_RFCommunication_Message, FH_PWMI_Frequency_Ptr, FH_PWMI_DutyCycle_Ptr);    // Handle FH_PWMI_Commands_GetStatus command

			sprintf(FH_RFCommunication_SendBuf,"%02x|PWMI|GetStatus|%02x|",FH_RFCommunication_DeviceAddress,fh_ErrorInfo.error_code);    // set FH_RFCommunication_SendBuf buffer
			FH_RFCommunication_Send(FH_RFCommunication_SendBuf);    // Send the result back to the Robot Framework

			fh_Uint8Uint32.value = FH_PWMI_Frequency;    // set the 32 bit value
			for (int i = 3 ; i >= 0; i--)
			{
				sprintf(FH_RFCommunication_SendBuf,"%02x",fh_Uint8Uint32.bytes[i]);    // Format the data and set FH_RFCommunication_SendBuf buffer
				FH_RFCommunication_Send(FH_RFCommunication_SendBuf);    // Send the result back to the Robot Framework
			}

			sprintf(FH_RFCommunication_SendBuf,"|%02x|\n",FH_PWMI_DutyCycle);    // set FH_RFCommunication_SendBuf buffer
			FH_RFCommunication_Send(FH_RFCommunication_SendBuf);    // Send the result back to the Robot Framework
			break;
		default:
			break;
	}
	return fh_ErrorInfo;
}

/**
 * @brief This function handles <b>FH_PWMI_Commands_Init</b> command\n
 *        There are 3 main items handled in this function as following:\n
 *        1 - Verifying the health of the received message\n
 *        2 - Setting the addresses of the functions in <b>FH_Functions</b>, Section <b>FH_PWMI</b> (PWM Input) to an array of function pointer\n
 *        3 - Calling the related function in <b>FH_Functions</b>, Section <b>FH_PWMI</b> (PWM Input) according to the first parameter of the Data in the message frame
 *
 * @param  fh_RFCommunication_Message
 *         The message frame set by <b>RobotFramework</b>
 *
 * @verbatim
    ==============================================================================
                          ##### RobotFramework Example #####
    ==============================================================================
    @{MessageData} =    Create List    ${PWMI01}
    &{Message}     =    Create Dictionary    DeviceAddress=${DeviceAddress_01}    Function=${Function_PWMI}    Command=${PWMI_Commands_Init}    Data=@{MessageData}
    ${Result}    SendMessage    &{Message}

    Comments:

    PWMI01 => It indicates the PWM Input 01
    DeviceAddress_01 => It shall be equal to the address of the device: FH_RFCommunication_DeviceAddress
    Function_PWMI => It is the function in the message frame
    PWMI_Commands_Init => It is the command of the function in the message frame
  @endverbatim
 *
 * @return FH_ErrorInfo is returned
 *

*/
FH_ErrorInfo FH_PWMI_ProcessCommand_Init(FH_RFCommunication_Message* fh_RFCommunication_Message)
{
	FH_ErrorInfo fh_ErrorInfo;    // Error Information
	FH_ResetErrorInfo(&fh_ErrorInfo);    // Reset Error Information to default

	// Item 1 - Verifying the health of the received message
	fh_ErrorInfo = FH_PWMI_Init_H(fh_RFCommunication_Message);
	if (fh_ErrorInfo.error_code != FH_ERROR_OK)    // Check if the message is healthy or not
	{
		return fh_ErrorInfo;    // Return the error
	}

	// 2 - Setting the addresses of the functions in <b>FH_Functions</b>, Section <b>FH_PWMI</b> (PWM Input) to an array of function pointer
	FH_PWMI_Init_FuncPtrModel FH_PWMI_Init_FuncPtr[FH_PWMI_MaxPeripheralNumber];    // An array of function pointer FH_PWMI_Init_FuncPtrModel
	FH_PWMI_Init_S (FH_PWMI_Init_FuncPtr);   // Setting the address of the functions

	// 3 - Calling the related function in <b>FH_Functions</b>, Section <b>FH_PWMI</b> (PWM Input) according to the first parameter of the Data in the message frame
	FH_ResetErrorInfo(&fh_ErrorInfo);    // Reset Error Information to default
	fh_ErrorInfo = FH_PWMI_Init_C (fh_RFCommunication_Message, FH_PWMI_Init_FuncPtr);    // Calling the related function according to the first parameter of the Data in the message frame
	return fh_ErrorInfo;
}

/**
 * @brief This function handles <b>FH_PWMI_Commands_GetStatus</b> command\n
 *        There are 3 main items handled in this function as following:\n
 *        1 - Verifying the health of the received message\n
 *        2 - Setting the addresses of the functions in <b>FH_Functions</b>, Section <b>FH_PWMI</b> (PWM Input) to an array of function pointer\n
 *        3 - Calling the related function in <b>FH_Functions</b>, Section <b>FH_PWMI</b> (PWM Input) according to the first parameter of the Data in the message frame
 *
 * @param  fh_RFCommunication_Message
 *         The message frame set by <b>RobotFramework</b>
 *
 * @verbatim
    ==============================================================================
                          ##### RobotFramework Example #####
    ==============================================================================
    @{MessageData} =    Create List    ${PWMI01}
    &{Message}     =    Create Dictionary    DeviceAddress=${DeviceAddress_01}    Function=${Function_PWMI}    Command=${PWMI_Commands_GetStatus}    Data=@{MessageData}
    ${Result}    SendMessage    &{Message}

    Comments:

    PWMI01 => It indicates the PWM Input 01
    DeviceAddress_01 => It shall be equal to the address of the device: FH_RFCommunication_DeviceAddress
    Function_PWMI => It is the function in the message frame
    PWMI_Commands_GetStatus => It is the command of the function in the message frame
  @endverbatim
 *
 *
 * @return FH_ErrorInfo is returned
 *

*/
FH_ErrorInfo FH_PWMI_ProcessCommand_GetStatus(FH_RFCommunication_Message* fh_RFCommunication_Message, uint32_t* FH_PWMI_Frequency, uint8_t* FH_PWMI_DutyCycle)
{
	FH_ErrorInfo fh_ErrorInfo;    // Error Information
	FH_ResetErrorInfo(&fh_ErrorInfo);    // Reset Error Information to default

	// Item 1 - Verifying the health of the received message
	fh_ErrorInfo = FH_PWMI_GetStatus_H(fh_RFCommunication_Message);
	if (fh_ErrorInfo.error_code != FH_ERROR_OK)    // Check if the message is healthy or not
	{
		return fh_ErrorInfo;    // Return the error
	}

	// 2 - Setting the addresses of the functions in <b>FH_Functions</b>, Section <b>FH_PWMI</b> (PWM Input) to an array of function pointer
	FH_PWMI_GetStatus_FuncPtrModel FH_PWMI_GetStatus_FuncPtr[FH_PWMI_MaxPeripheralNumber];    // An array of function pointer FH_PWMI_GetStatus_FuncPtrModel
	FH_PWMI_GetStatus_S (FH_PWMI_GetStatus_FuncPtr);   // Setting the address of the functions

	// 3 - Calling the related function in <b>FH_Functions</b>, Section <b>FH_PWMI</b> (PWM Input) according to the first parameter of the Data in the message frame
	FH_ResetErrorInfo(&fh_ErrorInfo);    // Reset Error Information to default
	fh_ErrorInfo = FH_PWMI_GetStatus_C (fh_RFCommunication_Message, FH_PWMI_Frequency, FH_PWMI_DutyCycle , FH_PWMI_GetStatus_FuncPtr);    // Calling the related function according to the first parameter of the Data in the message frame
	return fh_ErrorInfo;
}
	
#endif
