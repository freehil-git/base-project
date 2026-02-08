/**
  * @file
  * @brief
  *       <b>File Map:</b>\n
  *       <b>FH_Root</b>, Section <b>FH_Perif</b>, <b>FH_DI</b> (Digital Input)\n
  *       Functions in this file, handle RFCommunication (<b>RobotFramework</b> <b>C</b>ommunication) for all commands related to <b>DI</b> (Digital Input)
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
#include "../../../../FH_Embedded/FH_Root/FH_Perif/FH_DI/FH_DI.h"

#include "stdio.h"

#if FH_DI_MaxPeripheralNumber > 0    // It is configurable in FH_DevicePeripherals.h

/* Secondary Includes ------------------------------------------------------------------*/
#include "../../../../FH_Embedded/FH_Root/FH_General/FH_GeneralFunctions/FH_GeneralFunctions.h"
#include "../../../../FH_Embedded/FH_Setup/FH_DeviceAddress/FH_DeviceAddress.h"
#include "../../../../FH_Embedded/FH_Setup/FH_RFCommunication/FH_RFCommunication.h"
#include "../../../../FH_Embedded/FH_Root/FH_Perif/FH_DI/Cmd/Init/Init_H/FH_DI_Init_H.h"
#include "../../../../FH_Embedded/FH_Root/FH_Perif/FH_DI/Cmd/Init/Init_C/FH_DI_Init_C.h"
#include "../../../../FH_Embedded/FH_Root/FH_Perif/FH_DI/Cmd/Init/Init_S/FH_DI_Init_S.h"
#include "../../../../FH_Embedded/FH_Root/FH_Perif/FH_DI/Cmd/GetStatus/GetStatus_H/FH_DI_GetStatus_H.h"
#include "../../../../FH_Embedded/FH_Root/FH_Perif/FH_DI/Cmd/GetStatus/GetStatus_C/FH_DI_GetStatus_C.h"
#include "../../../../FH_Embedded/FH_Root/FH_Perif/FH_DI/Cmd/GetStatus/GetStatus_S/FH_DI_GetStatus_S.h"

/**
 * @brief This function is the basic function of handling RFCommunication (<b>RobotFramework</b> <b>C</b>ommunication) for all the <b>Commands</b> related to the <b>Function</b> <b>DI</b> (Digital Input)\n
 *        This function is called from <b>FH_RFCommunication()</b>
 *
 * @param  fh_RFCommunication_Message
 *         The message frame set by <b>RobotFramework</b>
 *
 * @return FH_ErrorInfo is returned
 *

*/
FH_ErrorInfo FH_DI_RFCommunication(FH_RFCommunication_Message* fh_RFCommunication_Message)
{
	FH_ErrorInfo fh_ErrorInfo;    // Error Information
	FH_ResetErrorInfo(&fh_ErrorInfo);    // Reset Error Information to default

	uint8_t FH_DI_Data;    // It temporarily stores the status of a digital input
	uint8_t* FH_DI_Data_Ptr;    // Pointer with &FH_DI_Data address
	uint8_t FH_DI_MULTIData [8];    // It temporarily stores the status of a 64 digital inputs

	switch (fh_RFCommunication_Message -> Command)    // Check different commands
	{
		case FH_DI_Commands_Init:    // If the command is FH_DI_Commands_Init
			fh_ErrorInfo = FH_DI_ProcessCommand_Init(fh_RFCommunication_Message);    // Handle FH_DI_Commands_Init command
			sprintf(FH_RFCommunication_SendBuf,"%02x|DI|Init|%02x|\n",FH_RFCommunication_DeviceAddress,fh_ErrorInfo.error_code);    // set FH_RFCommunication_SendBuf buffer
			FH_RFCommunication_Send(FH_RFCommunication_SendBuf);  // Send the result back to the Robot Framework
			break;
		case FH_DI_Commands_GetStatus:    // If the command is FH_DI_Commands_SetStatus
			FH_DI_Data_Ptr = &FH_DI_Data;   // Pointer with &FH_DI_Data address
			fh_ErrorInfo = FH_DI_ProcessCommand_GetStatus(fh_RFCommunication_Message, FH_DI_Data_Ptr);    // Handle FH_DI_Commands_GetStatus command
			sprintf(FH_RFCommunication_SendBuf,"%02x|DI|GetStatus|%02x|%d|\n",FH_RFCommunication_DeviceAddress,fh_ErrorInfo.error_code,FH_DI_Data);    // set FH_RFCommunication_SendBuf buffer
			FH_RFCommunication_Send(FH_RFCommunication_SendBuf);  // Send the result back to the Robot Framework
			break;
		case FH_DI_Commands_InitMULTI:    // If the command is FH_DI_Commands_InitMULTI
			fh_ErrorInfo = FH_DI_ProcessCommand_InitMULTI(fh_RFCommunication_Message);    // Handle FH_DI_Commands_InitMULTI command
			sprintf(FH_RFCommunication_SendBuf,"%02x|DI|InitMULTI|%02x|\n",FH_RFCommunication_DeviceAddress,fh_ErrorInfo.error_code);    // set FH_RFCommunication_SendBuf buffer
			FH_RFCommunication_Send(FH_RFCommunication_SendBuf);    // Send the result back to the Robot Framework
			break;
		case FH_DI_Commands_GetStatusMULTI:    // If the command is FH_DI_Commands_GetStatusMULTI
			FH_DI_Data_Ptr = &FH_DI_MULTIData[0];
			fh_ErrorInfo = FH_DI_ProcessCommand_GetStatusMULTI(fh_RFCommunication_Message, FH_DI_Data_Ptr);    // Handle FH_DI_Commands_GetStatusMULTI command

			sprintf(FH_RFCommunication_SendBuf,"%02x|DI|GetStatusMULTI|%02x|",FH_RFCommunication_DeviceAddress,fh_ErrorInfo.error_code);    // set FH_RFCommunication_SendBuf buffer
			FH_RFCommunication_Send(FH_RFCommunication_SendBuf);  // Send the result back to the Robot Framework

			for (int i = 0 ; i < 8; i++)
			{
				sprintf(FH_RFCommunication_SendBuf,"%02x",FH_DI_MULTIData[i]);    // Format the data and set FH_RFCommunication_SendBuf buffer
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
 * @brief This function handles <b>FH_DI_Commands_Init</b> command\n
 *        There are 3 main items handled in this function as following:\n
 *        1 - Verifying the health of the received message\n
 *        2 - Setting the addresses of the functions in <b>FH_Functions</b>, Section <b>FH_DI</b> (Digital Input) to an array of function pointer\n
 *        3 - Calling the related function in <b>FH_Functions</b>, Section <b>FH_DI</b> (Digital Input) according to the first parameter of the Data in the message frame
 *
 * @param  fh_RFCommunication_Message
 *         The message frame set by <b>RobotFramework</b>
 *
 * @verbatim
    ==============================================================================
                          ##### RobotFramework Example #####
    ==============================================================================
    @{MessageData} =    Create List    ${DI01}
    &{Message}     =    Create Dictionary    DeviceAddress=${DeviceAddress_01}    Function=${Function_DI}    Command=${DI_Commands_Init}    Data=@{MessageData}
    ${Result}    SendMessage    &{Message}

    Comments:

    DI01 => It indicates the Digital Input 01
    DeviceAddress_01 => It shall be equal to the address of the device: FH_RFCommunication_DeviceAddress
    Function_DI => It is the function in the message frame
    DI_Commands_Init => It is the command of the function in the message frame
  @endverbatim
 *
 * @return FH_ErrorInfo is returned
 *

*/
FH_ErrorInfo FH_DI_ProcessCommand_Init(FH_RFCommunication_Message* fh_RFCommunication_Message)
{
	FH_ErrorInfo fh_ErrorInfo;    // Error Information
	FH_ResetErrorInfo(&fh_ErrorInfo);    // Reset Error Information to default

	// Item 1 - Verifying the health of the received message
	fh_ErrorInfo = FH_DI_Init_H(fh_RFCommunication_Message);
	if (fh_ErrorInfo.error_code != FH_ERROR_OK)    // Check if the message is healthy or not
	{
		return fh_ErrorInfo;    // Return the error
	}

	// 2 - Setting the addresses of the functions in <b>FH_Functions</b>, Section <b>FH_DI</b> (Digital Input) to an array of function pointer\n
	FH_DI_Init_FuncPtrModel FH_DI_Init_FuncPtr[FH_DI_MaxPeripheralNumber];    // An array of function pointer FH_DI_Init_FuncPtrModel
	FH_DI_Init_S (FH_DI_Init_FuncPtr);    // Setting the address of the functions

	// 3 - Calling the related function in <b>FH_Functions</b>, Section <b>FH_DI</b> (Digital Input) according to the first parameter of the Data in the message frame
	FH_ResetErrorInfo(&fh_ErrorInfo);    // Reset Error Information to default
	fh_ErrorInfo = FH_DI_Init_C (fh_RFCommunication_Message, FH_DI_Init_FuncPtr);    // Calling the related function according to the first parameter of the Data in the message frame
	return fh_ErrorInfo;
}

/**
 * @brief This function handles <b>FH_DI_Commands_GetStatus</b> command\n
 *        There are 3 main items handled in this function as following:\n
 *        1 - Verifying the health of the received message\n
 *        2 - Setting the addresses of the functions in <b>FH_Functions</b>, Section <b>FH_DI</b> (Digital Input) to an array of function pointer\n
 *        3 - Calling the related function in <b>FH_Functions</b>, Section <b>FH_DI</b> (Digital Input) according to the first parameter of the Data in the message frame
 *
 * @param  fh_RFCommunication_Message
 *         The message frame set by <b>RobotFramework</b>
 *
 * @verbatim
    ==============================================================================
                          ##### RobotFramework Example #####
    ==============================================================================
    @{MessageData} =    Create List    ${DI01}
    &{Message}     =    Create Dictionary    DeviceAddress=${DeviceAddress_01}    Function=${Function_DI}    Command=${DI_Commands_GetStatus}    Data=@{MessageData}
    ${Result}    SendMessage    &{Message}

    Comments:

    DI01 => It indicates the Digital Input 01
    DeviceAddress_01 => It shall be equal to the address of the device: FH_RFCommunication_DeviceAddress
    Function_DI => It is the function in the message frame
    DI_Commands_GetStatus => It is the command of the function in the message frame
  @endverbatim
 *
 *
 * @return FH_ErrorInfo is returned
 *

*/
FH_ErrorInfo FH_DI_ProcessCommand_GetStatus(FH_RFCommunication_Message* fh_RFCommunication_Message, uint8_t* FH_DI_Data)
{
	FH_ErrorInfo fh_ErrorInfo;    // Error Information
	FH_ResetErrorInfo(&fh_ErrorInfo);    // Reset Error Information to default

	// 1 - Verifying the health of the received message
	fh_ErrorInfo = FH_DI_GetStatus_H(fh_RFCommunication_Message);
	if (fh_ErrorInfo.error_code != FH_ERROR_OK)    // Check if the message is healthy or not
	{
		return fh_ErrorInfo;    // Return the error
	}
	
	// 2 - Setting the addresses of the functions in <b>FH_Functions</b>, Section <b>FH_DI</b> (Digital Input) to an array of function pointer
	FH_DI_GetStatus_FuncPtrModel FH_DI_GetStatus_FuncPtr[FH_DI_MaxPeripheralNumber];    // An array of function pointer FH_DI_GetStatus_FuncPtrModel
	FH_DI_GetStatus_S (FH_DI_GetStatus_FuncPtr);    // Setting the address of the functions

	// 3 - Calling the related function in <b>FH_Functions</b>, Section <b>FH_DI</b> (Digital Input) according to the first parameter of the Data in the message frame
	FH_ResetErrorInfo(&fh_ErrorInfo);    // Reset Error Information to default
	fh_ErrorInfo = FH_DI_GetStatus_C (fh_RFCommunication_Message, FH_DI_Data, FH_DI_GetStatus_FuncPtr);    // Calling the related function according to the first parameter of the Data in the message frame
	return fh_ErrorInfo;
}

/**
 * @brief This function handles <b>FH_DI_ProcessCommand_InitMULTI</b> command\n
 *        With this function, mass initialization of up to 64 <b>DI</b> (Digital Input) is possible instead of just 1 <b>DI</b> (Digital Input)\n
 *        There are 3 main items handled in this function as following:\n
 *        1 - Verifying the health of the received message\n
 *        2 - Setting the addresses of the functions in <b>FH_Functions</b>, Section <b>FH_DI</b> (Digital Input) to an array of function pointer\n
 *        3 - Calling the related function(s) in <b>FH_Functions</b>, Section <b>FH_DI</b> (Digital Input) according to the 8 first parameters of the Data in the message frame\n
 *            (The first 8 parameters resemble 64 bits and each bit resembles 1 <b>DI</b> (Digital Input) and if the bit is 1, the related <b>DI</b> (Digital Input) function will be called)
 *
 * @param  fh_RFCommunication_Message
 *         The message frame set by <b>RobotFramework</b>
 *
 * @verbatim
    ==============================================================================
                          ##### RobotFramework Example #####
    ==============================================================================
    @{MessageData} =    Create List    FF    FF    FF    FF    FF    FF    FF    FF
    &{Message}     =    Create Dictionary    DeviceAddress=${DeviceAddress_01}    Function=${Function_DI}    Command=${DI_Commands_InitMULTI}    Data=@{MessageData}
    ${Result}    SendMessage    &{Message}

    Comments:

    FF    FF    FF    FF    FF    FF    FF    FF => Example data as the first 8 parameters
    DeviceAddress_01 => It shall be equal to the address of the device: FH_RFCommunication_DeviceAddress
    Function_DI => It is the function in the message frame
    DI_Commands_InitMULTI => It is the command of the function in the message frame
  @endverbatim
 *
 * @return FH_ErrorInfo is returned
 *

*/
FH_ErrorInfo FH_DI_ProcessCommand_InitMULTI(FH_RFCommunication_Message* fh_RFCommunication_Message)
{
	FH_ErrorInfo fh_ErrorInfo;    // Error Information
	FH_ResetErrorInfo(&fh_ErrorInfo);    // Reset Error Information to default

	// 1 - Verifying the health of the received message
	fh_ErrorInfo = FH_DI_InitMULTI_H(fh_RFCommunication_Message);
	if (fh_ErrorInfo.error_code != FH_ERROR_OK)    // Check if the message is healthy or not
	{
		return fh_ErrorInfo;    // Return the error
	}

	// 2 - Setting the addresses of the functions in <b>FH_Functions</b>, Section <b>FH_DI</b> (Digital Input) to an array of function pointer
	FH_DI_Init_FuncPtrModel FH_DI_Init_FuncPtr[FH_DI_MaxPeripheralNumber];    // An array of function pointer FH_DI_Init_FuncPtrModel
	FH_DI_Init_S (FH_DI_Init_FuncPtr);    // Setting the address of the functions

	// 3 - Calling the related function(s) in <b>FH_Functions</b>, Section <b>FH_DI</b> (Digital Input) according to the 8 first parameters of the Data in the message frame
	// (The first 8 parameters resemble 64 bits and each bit resembles 1 <b>DI</b> (Digital Input) and if the bit is 1, the related <b>DI</b> (Digital Input) function will be called)
	FH_ResetErrorInfo(&fh_ErrorInfo);    // Reset Error Information to default
	fh_ErrorInfo = FH_DI_InitMULTI_C (fh_RFCommunication_Message, FH_DI_Init_FuncPtr);    // Calling the related function according to the first 8 parameters of the Data in the message frame
	return fh_ErrorInfo;
}

/**
 * @brief This function handles <b>FH_DI_ProcessCommand_GetStatusMULTI</b> command\n
 *        With this function, mass status get of up to 64 <b>DI</b> (Digital Input) is possible instead of just 1 <b>DI</b> (Digital Input)\n
 *        There are 3 main items handled in this function as following:\n
 *        1 - Verifying the health of the received message\n
 *        2 - Setting the addresses of the functions in <b>FH_Functions</b>, Section <b>FH_DI</b> (Digital Input) to an array of function pointer\n
 *        3 - Calling the related function in <b>FH_Functions</b>, Section <b>FH_DI</b> (Digital Input) according to the 8 first parameters of the Data in the message frame\n
 *            (The first 8 parameters as mask resemble 64 bits and each bit resembles 1 <b>DI</b> (Digital Input) and if the bit is 1, the related <b>DI</b> (Digital Input) function will be called)
 *
 * @param  fh_RFCommunication_Message
 *         The message frame set by <b>RobotFramework</b>
 * @param  FH_DI_MULTIData
 *         64 bits (8 bytes) resemble 64 bits result and each bit resembles the status of 1 <b>DI</b> (Digital Input) as 1 or 0 of the corresponding bit in the first 8 bytes of the Data
 *
 * @verbatim
    ==============================================================================
                          ##### RobotFramework Example #####
    ==============================================================================
    @{MessageData} =    Create List    FF    FF    FF    FF    FF    FF    FF    FF
    &{Message}     =    Create Dictionary    DeviceAddress=${DeviceAddress_01}    Function=${Function_DI}    Command=${DI_Commands_GetStatusMULTI}    Data=@{MessageData}
    ${Result}    SendMessage    &{Message}

    Comments:

    FF    FF    FF    FF    FF    FF    FF    FF => Example data as the first 8 parameters
    DeviceAddress_01 => It shall be equal to the address of the device: FH_RFCommunication_DeviceAddress
    Function_DI => It is the function in the message frame
    DI_Commands_GetStatusMULTI => It is the command of the function in the message frame
  @endverbatim
 *
 * @return FH_ErrorInfo is returned
 *

*/
FH_ErrorInfo FH_DI_ProcessCommand_GetStatusMULTI(FH_RFCommunication_Message* fh_RFCommunication_Message, uint8_t* FH_DI_MULTIData)
{
	FH_ErrorInfo fh_ErrorInfo;    // Error Information
	FH_ResetErrorInfo(&fh_ErrorInfo);    // Reset Error Information to default

	// 1 - Verifying the health of the received message
	fh_ErrorInfo = FH_DI_GetStatusMULTI_H(fh_RFCommunication_Message);
	if (fh_ErrorInfo.error_code != FH_ERROR_OK)    // Check if the message is healthy or not
	{
		return fh_ErrorInfo;    // Return the error
	}
	
	// 2 - Setting the addresses of the functions in <b>FH_Functions</b>, Section <b>FH_DI</b> (Digital Input) to an array of function pointer
	FH_DI_GetStatus_FuncPtrModel FH_DI_GetStatus_FuncPtr[FH_DI_MaxPeripheralNumber];    // An array of function pointer FH_DI_GetStatus_FuncPtrModel
	FH_DI_GetStatus_S (FH_DI_GetStatus_FuncPtr);    // Setting the address of the functions

	// 3 - Calling the related function in <b>FH_Functions</b>, Section <b>FH_DI</b> (Digital Input) according to the 8 first parameters of the Data in the message frame
	// (The first 8 parameters as mask resemble 64 bits and each bit resembles 1 <b>DI</b> (Digital Input) and if the bit is 1, the related <b>DI</b> (Digital Input) function will be called)
	FH_ResetErrorInfo(&fh_ErrorInfo);    // Reset Error Information to default
	fh_ErrorInfo = FH_DI_GetStatusMULTI_C (fh_RFCommunication_Message, FH_DI_MULTIData, FH_DI_GetStatus_FuncPtr);    // Calling the related function according to the first 8 parameters of the Data in the message frame
	return fh_ErrorInfo;
}
	
#endif
