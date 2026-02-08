/**
  * @file
  * @brief
  *       <b>File Map:</b>\n
  *       <b>FH_Root</b>, Section <b>FH_Perif</b>, <b>FH_CAN</b>\n
  *       Functions in this file, handle RFCommunication (<b>RobotFramework</b> <b>C</b>ommunication) for all commands related to <b>CAN</b>
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
#include "../../../../FH_Embedded/FH_Root/FH_Perif/FH_CAN/FH_CAN.h"

#include "stdio.h"

#if FH_CAN_MaxPeripheralNumber > 0    // It is configurable in FH_DevicePeripherals.h

/* Secondary Includes ------------------------------------------------------------------*/
#include "../../../../FH_Embedded/FH_Root/FH_General/FH_GeneralFunctions/FH_GeneralFunctions.h"
#include "../../../../FH_Embedded/FH_Setup/FH_DeviceAddress/FH_DeviceAddress.h"
#include "../../../../FH_Embedded/FH_Setup/FH_RFCommunication/FH_RFCommunication.h"
#include "../../../../FH_Embedded/FH_Root/FH_Perif/FH_CAN/Cmd/Init/Init_H/FH_CAN_Init_H.h"
#include "../../../../FH_Embedded/FH_Root/FH_Perif/FH_CAN/Cmd/Init/Init_C/FH_CAN_Init_C.h"
#include "../../../../FH_Embedded/FH_Root/FH_Perif/FH_CAN/Cmd/Init/Init_S/FH_CAN_Init_S.h"
#include "../../../../FH_Embedded/FH_Root/FH_Perif/FH_CAN/Cmd/Send/Send_H/FH_CAN_Send_H.h"
#include "../../../../FH_Embedded/FH_Root/FH_Perif/FH_CAN/Cmd/Send/Send_C/FH_CAN_Send_C.h"
#include "../../../../FH_Embedded/FH_Root/FH_Perif/FH_CAN/Cmd/Send/Send_S/FH_CAN_Send_S.h"
#include "../../../../FH_Embedded/FH_Root/FH_Perif/FH_CAN/Cmd/Receive/Receive_H/FH_CAN_Receive_H.h"
#include "../../../../FH_Embedded/FH_Root/FH_Perif/FH_CAN/Cmd/Receive/Receive_C/FH_CAN_Receive_C.h"
#include "../../../../FH_Embedded/FH_Root/FH_Perif/FH_CAN/Cmd/Receive/Receive_S/FH_CAN_Receive_S.h"
#include "../../../../FH_Embedded/FH_Root/FH_Perif/FH_CAN/Cmd/ReceiveW/ReceiveW_H/FH_CAN_ReceiveW_H.h"
#include "../../../../FH_Embedded/FH_Root/FH_Perif/FH_CAN/Cmd/ReceiveW/ReceiveW_C/FH_CAN_ReceiveW_C.h"
#include "../../../../FH_Embedded/FH_Root/FH_Perif/FH_CAN/Cmd/ReceiveW/ReceiveW_S/FH_CAN_ReceiveW_S.h"
#include "../../../../FH_Embedded/FH_Root/FH_Perif/FH_CAN/Cmd/ResetRB/ResetRB_H/FH_CAN_ResetRB_H.h"
#include "../../../../FH_Embedded/FH_Root/FH_Perif/FH_CAN/Cmd/ResetRB/ResetRB_C/FH_CAN_ResetRB_C.h"
#include "../../../../FH_Embedded/FH_Root/FH_Perif/FH_CAN/Cmd/ResetRB/ResetRB_S/FH_CAN_ResetRB_S.h"
#include "../../../../FH_Embedded/FH_Root/FH_Perif/FH_CAN/Cmd/SSD8/SSD8_H/FH_CAN_SSD8_H.h"
#include "../../../../FH_Embedded/FH_Root/FH_Perif/FH_CAN/Cmd/SSD8/SSD8_C/FH_CAN_SSD8_C.h"
#include "../../../../FH_Embedded/FH_Root/FH_Perif/FH_CAN/Cmd/SSD8/SSD8_S/FH_CAN_SSD8_S.h"
#include "../../../../FH_Embedded/FH_Root/FH_Perif/FH_CAN/Cmd/SSD16/SSD16_H/FH_CAN_SSD16_H.h"
#include "../../../../FH_Embedded/FH_Root/FH_Perif/FH_CAN/Cmd/SSD16/SSD16_C/FH_CAN_SSD16_C.h"
#include "../../../../FH_Embedded/FH_Root/FH_Perif/FH_CAN/Cmd/SSD16/SSD16_S/FH_CAN_SSD16_S.h"
#include "../../../../FH_Embedded/FH_Root/FH_Perif/FH_CAN/Cmd/SSD32/SSD32_H/FH_CAN_SSD32_H.h"
#include "../../../../FH_Embedded/FH_Root/FH_Perif/FH_CAN/Cmd/SSD32/SSD32_C/FH_CAN_SSD32_C.h"
#include "../../../../FH_Embedded/FH_Root/FH_Perif/FH_CAN/Cmd/SSD32/SSD32_S/FH_CAN_SSD32_S.h"
#include "../../../../FH_Embedded/FH_Root/FH_Perif/FH_CAN/Cmd/GSD8/GSD8_H/FH_CAN_GSD8_H.h"
#include "../../../../FH_Embedded/FH_Root/FH_Perif/FH_CAN/Cmd/GSD8/GSD8_C/FH_CAN_GSD8_C.h"
#include "../../../../FH_Embedded/FH_Root/FH_Perif/FH_CAN/Cmd/GSD8/GSD8_S/FH_CAN_GSD8_S.h"
#include "../../../../FH_Embedded/FH_Root/FH_Perif/FH_CAN/Cmd/GSD16/GSD16_H/FH_CAN_GSD16_H.h"
#include "../../../../FH_Embedded/FH_Root/FH_Perif/FH_CAN/Cmd/GSD16/GSD16_C/FH_CAN_GSD16_C.h"
#include "../../../../FH_Embedded/FH_Root/FH_Perif/FH_CAN/Cmd/GSD16/GSD16_S/FH_CAN_GSD16_S.h"
#include "../../../../FH_Embedded/FH_Root/FH_Perif/FH_CAN/Cmd/GSD32/GSD32_H/FH_CAN_GSD32_H.h"
#include "../../../../FH_Embedded/FH_Root/FH_Perif/FH_CAN/Cmd/GSD32/GSD32_C/FH_CAN_GSD32_C.h"
#include "../../../../FH_Embedded/FH_Root/FH_Perif/FH_CAN/Cmd/GSD32/GSD32_S/FH_CAN_GSD32_S.h"

/**
 * @brief This function is the basic function of handling RFCommunication (<b>RobotFramework</b> <b>C</b>ommunication) for all the <b>Commands</b> related to the <b>Function</b> <b>CAN</b>\n
 *        This function is called from <b>FH_RFCommunication()</b>
 *
 * @param  fh_RFCommunication_Message
 *         The message frame set by <b>RobotFramework</b>
 *
 * @return FH_ErrorInfo is returned
 *

*/
FH_ErrorInfo FH_CAN_RFCommunication(FH_RFCommunication_Message* fh_RFCommunication_Message)
{
	FH_ErrorInfo fh_ErrorInfo;    // Error Information
	FH_ResetErrorInfo(&fh_ErrorInfo);    // Reset Error Information to default

	uint8_t FH_DataSize;    // It temporarily stores the received data size
	uint8_t TemporaryCollectDataBuffer [FH_RFCommunication_SendBufLength];    // It temporarily stores the received data
	uint8_t* FH_DataSize_Ptr = &FH_DataSize;    // Pointer with &FH_DataSize address
	uint8_t* FH_DataBuffer_Ptr = &TemporaryCollectDataBuffer[0];    // Pointer with &TemporaryCollectDataBuffer[0] address

	switch (fh_RFCommunication_Message -> Command)    // Check different commands
	{
		case FH_CAN_Commands_Init:    // If the command is FH_CAN_Commands_Init
			fh_ErrorInfo = FH_CAN_ProcessCommand_Init (fh_RFCommunication_Message);    // Handle FH_CAN_Commands_Init command
			sprintf(FH_RFCommunication_SendBuf,"%02x|CAN|Init|%02x|\n",FH_RFCommunication_DeviceAddress,fh_ErrorInfo.error_code);    // set FH_RFCommunication_SendBuf buffer
			FH_RFCommunication_Send(FH_RFCommunication_SendBuf);    // Send the result back to the Robot Framework
			break;
		case FH_CAN_Commands_Send:    // If the command is FH_CAN_Commands_Send
			fh_ErrorInfo = FH_CAN_ProcessCommand_Send (fh_RFCommunication_Message);    // Handle FH_CAN_Commands_Send command
			sprintf(FH_RFCommunication_SendBuf,"%02x|CAN|Send|%02x|\n",FH_RFCommunication_DeviceAddress,fh_ErrorInfo.error_code);    // set FH_RFCommunication_SendBuf buffer
			FH_RFCommunication_Send(FH_RFCommunication_SendBuf);    // Send the result back to the Robot Framework
			break;
		case FH_CAN_Commands_Receive:    // If the command is FH_CAN_Commands_Receive
			fh_ErrorInfo = FH_CAN_ProcessCommand_Receive (fh_RFCommunication_Message, FH_DataBuffer_Ptr, FH_DataSize_Ptr);    // Handle FH_CAN_Commands_Receive command

			sprintf(FH_RFCommunication_SendBuf,"%02x|CAN|Receive|%02x|%02x|",FH_RFCommunication_DeviceAddress,fh_ErrorInfo.error_code,FH_DataSize);    // set FH_RFCommunication_SendBuf buffer
			FH_RFCommunication_Send(FH_RFCommunication_SendBuf);    // Send the result back to the Robot Framework

			for (uint8_t i = 0; i < FH_DataSize ; i++)    // Iteration within the length of the FH_DataSize
			{
				sprintf(FH_RFCommunication_SendBuf,"%02x",TemporaryCollectDataBuffer[i]);    // set FH_RFCommunication_SendBuf buffer
				FH_RFCommunication_Send(FH_RFCommunication_SendBuf);    // Send the result back to the Robot Framework
			}

			sprintf(FH_RFCommunication_SendBuf,"|\n");    // set FH_RFCommunication_SendBuf buffer
			FH_RFCommunication_Send(FH_RFCommunication_SendBuf);    // Send the result back to the Robot Framework
			break;
		case FH_CAN_Commands_ReceiveW:    // If the command is FH_CAN_Commands_ReceiveW
			fh_ErrorInfo = FH_CAN_ProcessCommand_ReceiveW (fh_RFCommunication_Message, FH_DataBuffer_Ptr, FH_DataSize_Ptr);    // Handle FH_CAN_Commands_ReceiveW command

			sprintf(FH_RFCommunication_SendBuf,"%02x|CAN|ReceiveW|%02x|%02x|",FH_RFCommunication_DeviceAddress,fh_ErrorInfo.error_code,FH_DataSize);    // set FH_RFCommunication_SendBuf buffer
			FH_RFCommunication_Send(FH_RFCommunication_SendBuf);    // Send the result back to the Robot Framework

			for (uint8_t i = 0; i < FH_DataSize ; i++)    // Iteration within the length of the FH_DataSize
			{
				sprintf(FH_RFCommunication_SendBuf,"%02x",TemporaryCollectDataBuffer[i]);    // set FH_RFCommunication_SendBuf buffer
				FH_RFCommunication_Send(FH_RFCommunication_SendBuf);    // Send the result back to the Robot Framework
			}

			sprintf(FH_RFCommunication_SendBuf,"|\n");    // set FH_RFCommunication_SendBuf buffer
			FH_RFCommunication_Send(FH_RFCommunication_SendBuf);    // Send the result back to the Robot Framework
			break;
		case FH_CAN_Commands_ResetRB:    // If the command is FH_CAN_Commands_ResetRB
			fh_ErrorInfo = FH_CAN_ProcessCommand_ResetRB (fh_RFCommunication_Message);    // Handle FH_CAN_Commands_ResetRB command
			sprintf(FH_RFCommunication_SendBuf,"%02x|CAN|ResetRB|%02x|\n",FH_RFCommunication_DeviceAddress,fh_ErrorInfo.error_code);    // set FH_RFCommunication_SendBuf buffer
			FH_RFCommunication_Send(FH_RFCommunication_SendBuf);    // Send the result back to the Robot Framework
			break;
		case FH_CAN_Commands_SSD8:    // If the command is FH_CAN_Commands_SSD8
			fh_ErrorInfo = FH_CAN_ProcessCommand_SSD8 (fh_RFCommunication_Message);    // Handle FH_CAN_Commands_SSD8 command
			sprintf(FH_RFCommunication_SendBuf,"%02x|CAN|SSD8|%02x|\n",FH_RFCommunication_DeviceAddress,fh_ErrorInfo.error_code);    // set FH_RFCommunication_SendBuf buffer
			FH_RFCommunication_Send(FH_RFCommunication_SendBuf);    // Send the result back to the Robot Framework
			break;
		case FH_CAN_Commands_SSD16:    // If the command is FH_CAN_Commands_SSD16
			fh_ErrorInfo = FH_CAN_ProcessCommand_SSD16  (fh_RFCommunication_Message);    // Handle FH_CAN_Commands_SSD16 command
			sprintf(FH_RFCommunication_SendBuf,"%02x|CAN|SSD16|%02x|\n",FH_RFCommunication_DeviceAddress,fh_ErrorInfo.error_code);    // set FH_RFCommunication_SendBuf buffer
			FH_RFCommunication_Send(FH_RFCommunication_SendBuf);    // Send the result back to the Robot Framework
			break;
		case FH_CAN_Commands_SSD32:    // If the command is FH_CAN_Commands_SSD32
			fh_ErrorInfo = FH_CAN_ProcessCommand_SSD32 (fh_RFCommunication_Message);    // Handle FH_CAN_Commands_SSD32 command
			sprintf(FH_RFCommunication_SendBuf,"%02x|CAN|SSD32|%02x|\n",FH_RFCommunication_DeviceAddress,fh_ErrorInfo.error_code);    // set FH_RFCommunication_SendBuf buffer
			FH_RFCommunication_Send(FH_RFCommunication_SendBuf);    // Send the result back to the Robot Framework
			break;
		case FH_CAN_Commands_GSD8:    // If the command is FH_CAN_Commands_GSD8
			fh_ErrorInfo = FH_CAN_ProcessCommand_GSD8 (fh_RFCommunication_Message, FH_DataSize_Ptr, FH_DataBuffer_Ptr);    // Handle FH_CAN_Commands_GSD8 command

			sprintf(FH_RFCommunication_SendBuf,"%02x|CAN|GSD8|%02x|%02x|",FH_RFCommunication_DeviceAddress,fh_ErrorInfo.error_code,FH_DataSize);    // set FH_RFCommunication_SendBuf buffer
			FH_RFCommunication_Send(FH_RFCommunication_SendBuf);    // Send the result back to the Robot Framework

			for (uint8_t i = 0; i < FH_DataSize ; i++)    // Iteration within the length of the FH_DataSize
			{
				sprintf(FH_RFCommunication_SendBuf,"%02x",TemporaryCollectDataBuffer[i]);    // set FH_RFCommunication_SendBuf buffer
				FH_RFCommunication_Send(FH_RFCommunication_SendBuf);    // Send the result back to the Robot Framework
			}

			sprintf(FH_RFCommunication_SendBuf,"|\n");    // set FH_RFCommunication_SendBuf buffer
			FH_RFCommunication_Send(FH_RFCommunication_SendBuf);    // Send the result back to the Robot Framework
			break;
		case FH_CAN_Commands_GSD16:    // If the command is FH_CAN_Commands_GSD16
			fh_ErrorInfo = FH_CAN_ProcessCommand_GSD16 (fh_RFCommunication_Message, FH_DataSize_Ptr, FH_DataBuffer_Ptr);    // Handle FH_CAN_Commands_GSD16 command

			sprintf(FH_RFCommunication_SendBuf,"%02x|CAN|GSD16|%02x|%02x|",FH_RFCommunication_DeviceAddress,fh_ErrorInfo.error_code,FH_DataSize);    // set FH_RFCommunication_SendBuf buffer
			FH_RFCommunication_Send(FH_RFCommunication_SendBuf);    // Send the result back to the Robot Framework

			for (uint8_t i = 0; i < FH_DataSize ; i++)    // Iteration within the length of the FH_DataSize
			{
				sprintf(FH_RFCommunication_SendBuf,"%02x",TemporaryCollectDataBuffer[i]);    // set FH_RFCommunication_SendBuf buffer
				FH_RFCommunication_Send(FH_RFCommunication_SendBuf);    // Send the result back to the Robot Framework
			}

			sprintf(FH_RFCommunication_SendBuf,"|\n");    // set FH_RFCommunication_SendBuf buffer
			FH_RFCommunication_Send(FH_RFCommunication_SendBuf);    // Send the result back to the Robot Framework
			break;
		case FH_CAN_Commands_GSD32:    // If the command is FH_CAN_Commands_GSD32
			fh_ErrorInfo = FH_CAN_ProcessCommand_GSD32 (fh_RFCommunication_Message, FH_DataSize_Ptr, FH_DataBuffer_Ptr);    // Handle FH_CAN_Commands_GSD32 command

			sprintf(FH_RFCommunication_SendBuf,"%02x|CAN|GSD32|%02x|%02x|",FH_RFCommunication_DeviceAddress,fh_ErrorInfo.error_code,FH_DataSize);    // set FH_RFCommunication_SendBuf buffer
			FH_RFCommunication_Send(FH_RFCommunication_SendBuf);    // Send the result back to the Robot Framework

			for (uint8_t i = 0; i < FH_DataSize ; i++)    // Iteration within the length of the FH_DataSize
			{
				sprintf(FH_RFCommunication_SendBuf,"%02x",TemporaryCollectDataBuffer[i]);    // set FH_RFCommunication_SendBuf buffer
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
 * @brief This function handles <b>FH_CAN_Commands_Init</b> command\n
 *        There are 3 main items handled in this function as following:\n
 *        1 - Verifying the health of the received message\n
 *        2 - Setting the addresses of the functions in <b>FH_Functions</b>, Section <b>FH_CAN</b> to an array of function pointer\n
 *        3 - Calling the related function in <b>FH_Functions</b>, Section <b>FH_CAN</b> according to the first parameter of the Data in the message frame
 *
 * @param  fh_RFCommunication_Message
 *         The message frame set by <b>RobotFramework</b>
 *
 * @verbatim
    ==============================================================================
                          ##### RobotFramework Example #####
    ==============================================================================
    @{MessageData} =    Create List    ${CAN01}
    &{Message}     =    Create Dictionary    DeviceAddress=${DeviceAddress_01}    Function=${Function_CAN}    Command=${CAN_Commands_Init}    Data=@{MessageData}
    ${Result}    SendMessage    &{Message}

    Comments:

    CAN01 => It indicates the CAN 01
    DeviceAddress_01 => It shall be equal to the address of the device: FH_RFCommunication_DeviceAddress
    Function_CAN => It is the function in the message frame
    CAN_Commands_Init => It is the command of the function in the message frame
  @endverbatim
 *
 * @return FH_ErrorInfo is returned
 *

*/
FH_ErrorInfo FH_CAN_ProcessCommand_Init(FH_RFCommunication_Message* fh_RFCommunication_Message)
{
	FH_ErrorInfo fh_ErrorInfo;    // Error Information
	FH_ResetErrorInfo(&fh_ErrorInfo);    // Reset Error Information to default

	// 1 - Verifying the health of the received message
	fh_ErrorInfo = FH_CAN_Init_H(fh_RFCommunication_Message);
	if (fh_ErrorInfo.error_code != FH_ERROR_OK)    // Check if the message is healthy or not
	{
		return fh_ErrorInfo;    // Return the error
	}

	// 2 - Setting the addresses of the functions in <b>FH_Functions</b>, Section <b>FH_CAN</b> to an array of function pointer
	FH_CAN_Init_FuncPtrModel FH_CAN_Init_FuncPtr[FH_CAN_MaxPeripheralNumber];    // An array of function pointer FH_CAN_Init_FuncPtrModel
	FH_CAN_Init_S(FH_CAN_Init_FuncPtr);    // Setting the address of the functions

	// 3 - Calling the related function in <b>FH_Functions</b>, Section <b>FH_CAN</b> according to the first parameter of the Data in the message frame
	FH_ResetErrorInfo(&fh_ErrorInfo);    // Reset Error Information to default
	fh_ErrorInfo = FH_CAN_Init_C(fh_RFCommunication_Message, FH_CAN_Init_FuncPtr);    // Calling the related function according to the first parameter of the Data in the message frame
	return fh_ErrorInfo;
}

/**
 * @brief This function handles <b>FH_CAN_Commands_Send</b> command\n
 *        There are 3 main items handled in this function as following:\n
 *        1 - Verifying the health of the received message\n
 *        2 - Setting the addresses of the functions in <b>FH_Functions</b>, Section <b>FH_CAN</b> to an array of function pointer\n
 *        3 - Calling the related function in <b>FH_Functions</b>, Section <b>FH_CAN</b> according to the first parameter of the Data in the message frame
 *            (The next parameters after the first one, resemble the data to be sent)
 *
 * @param  fh_RFCommunication_Message
 *         The message frame set by <b>RobotFramework</b>
 *
 * @verbatim
    ==============================================================================
                          ##### RobotFramework Example #####
    ==============================================================================
    @{MessageData} =    Create List    ${CAN01}    02    B1     FF
    &{Message}     =    Create Dictionary    DeviceAddress=${DeviceAddress_01}    Function=${Function_CAN}    Command=${CAN_Commands_Send}    Data=@{MessageData}
    ${Result}    SendMessage    &{Message}

    Comments:

    CAN01 => It indicates the CAN 01
    02 => Example length of the data to be sent
    B1     FF => Example data (0xB1, 0xFF) to be sent (or apart from the data to be sent, it may include some other data like ID, Filter, ... to be processed too, if need be) through the <b>CAN 01</b>\n
    DeviceAddress_01 => It shall be equal to the address of the device: FH_RFCommunication_DeviceAddress
    Function_CAN => It is the function in the message frame
    CAN_Commands_Send => It is the command of the function in the message frame
  @endverbatim
 *
 * @return FH_ErrorInfo is returned
 *

*/
FH_ErrorInfo FH_CAN_ProcessCommand_Send(FH_RFCommunication_Message* fh_RFCommunication_Message)
{
	FH_ErrorInfo fh_ErrorInfo;    // Error Information
	FH_ResetErrorInfo(&fh_ErrorInfo);    // Reset Error Information to default

	// 1 - Verifying the health of the received message
	fh_ErrorInfo = FH_CAN_Send_H(fh_RFCommunication_Message);
	if (fh_ErrorInfo.error_code != FH_ERROR_OK)    // Check if the message is healthy or not
	{
		return fh_ErrorInfo;    // Return the error
	}

	// 2 - Setting the addresses of the functions in <b>FH_Functions</b>, Section <b>FH_CAN</b> to an array of function pointer
	FH_CAN_Send_FuncPtrModel FH_CAN_Send_FuncPtr[FH_CAN_MaxPeripheralNumber];    // An array of function pointer FH_CAN_Send_FuncPtrModel
	FH_CAN_Send_S(FH_CAN_Send_FuncPtr);    // Setting the address of the functions

	// 3 - Calling the related function in <b>FH_Functions</b>, Section <b>FH_CAN</b> according to the first parameter of the Data in the message frame
	//     (The next parameters after the first one, resemble the data to be sent)
	FH_ResetErrorInfo(&fh_ErrorInfo);    // Reset Error Information to default
	fh_ErrorInfo = FH_CAN_Send_C(fh_RFCommunication_Message, FH_CAN_Send_FuncPtr);    // Calling the related function according to the first parameter of the Data in the message frame
	return fh_ErrorInfo;
}

/**
 * @brief This function handles <b>FH_CAN_Commands_Receive</b> command\n
 *        There are 3 main items handled in this function as following:\n
 *        1 - Verifying the health of the received message\n
 *        2 - Setting the addresses of the functions in <b>FH_Functions</b>, Section <b>FH_CAN</b> to an array of function pointer\n
 *        3 - Calling the related function in <b>FH_Functions</b>, Section <b>FH_CAN</b> according to the first parameter of the Data in the message frame
 *
 * @param  fh_RFCommunication_Message
 *         The message frame set by <b>RobotFramework</b>
 *
 * @verbatim
    ==============================================================================
                          ##### RobotFramework Example #####
    ==============================================================================
    @{MessageData} =    Create List    ${CAN01}
    &{Message}     =    Create Dictionary    DeviceAddress=${DeviceAddress_01}    Function=${Function_CAN}    Command=${CAN_Commands_Receive}    Data=@{MessageData}
    ${Result}    SendMessage    &{Message}

    Comments:

    CAN01 => It indicates the CAN 01
    DeviceAddress_01 => It shall be equal to the address of the device: FH_RFCommunication_DeviceAddress
    Function_CAN => It is the function in the message frame
    CAN_Commands_Receive => It is the command of the function in the message frame
  @endverbatim
 *
 * @return FH_ErrorInfo is returned
 *

*/
FH_ErrorInfo FH_CAN_ProcessCommand_Receive(FH_RFCommunication_Message* fh_RFCommunication_Message, uint8_t* FH_CAN_ReceiveData, uint8_t* FH_CAN_DataSize)
{
	FH_ErrorInfo fh_ErrorInfo;    // Error Information
	FH_ResetErrorInfo(&fh_ErrorInfo);    // Reset Error Information to default

	// 1 - Verifying the health of the received message
	fh_ErrorInfo = FH_CAN_Receive_H(fh_RFCommunication_Message);
	if (fh_ErrorInfo.error_code != FH_ERROR_OK)    // Check if the message is healthy or not
	{
		return fh_ErrorInfo;    // Return the error
	}

	// 2 - Setting the addresses of the functions in <b>FH_Functions</b>, Section <b>FH_CAN</b> to an array of function pointer
	FH_CAN_Receive_FuncPtrModel FH_CAN_Receive_FuncPtr[FH_CAN_MaxPeripheralNumber];    // An array of function pointer FH_CAN_Receive_FuncPtrModel
	FH_CAN_Receive_S(FH_CAN_Receive_FuncPtr);    // Setting the address of the functions

	// 3 - Calling the related function in <b>FH_Functions</b>, Section <b>FH_CAN</b> according to the first parameter of the Data in the message frame
	FH_ResetErrorInfo(&fh_ErrorInfo);    // Reset Error Information to default
	fh_ErrorInfo = FH_CAN_Receive_C(fh_RFCommunication_Message, FH_CAN_ReceiveData,FH_CAN_DataSize,FH_CAN_Receive_FuncPtr);    // Calling the related function according to the first parameter of the Data in the message frame

	return fh_ErrorInfo;
}

/**
 * @brief This function handles <b>FH_CAN_Commands_ReceiveW</b> command\n
 *        There are 3 main items handled in this function as following:\n
 *        1 - Verifying the health of the received message\n
 *        2 - Setting the addresses of the functions in <b>FH_Functions</b>, Section <b>FH_CAN</b> to an array of function pointer\n
 *        3 - Calling the related function in <b>FH_Functions</b>, Section <b>FH_CAN</b> according to the first parameter of the Data in the message frame\n
 *            (The 2nd parameter after the first one, resembles the expected number of bytes of data to be received)\n
 *            (The next 4 parameters, resemble the timeout of receiving the expected number of bytes)
 *
 * @param  fh_RFCommunication_Message
 *         The message frame set by <b>RobotFramework</b>
 *
 * @verbatim
    ==============================================================================
                          ##### RobotFramework Example #####
    ==============================================================================
    @{MessageData} =    Create List    ${CAN01}    05    00    00    0B    B8
    &{Message}     =    Create Dictionary    DeviceAddress=${DeviceAddress_01}    Function=${Function_CAN}    Command=${CAN_Commands_ReceiveW}    Data=@{MessageData}
    ${Result}    SendMessage    &{Message}

    Comments:

    CAN01 => It indicates the CAN 01
    05 => The expected number of bytes of data to be received through the <b>ISR</b> (Interrupt Service Routine) receive buffer (FH_CAN01_ReceiveBuf) of the <b>CAN 01</b>
    00    00    0B    B8 => Example data (0x00000BB8 mili-seconds) as timeout of receiving the expected number of bytes
                            FH_GlobalTimeCounter which is a global variable is utilized to calculate the timeout
                            FH_GlobalTimeCounter shall be incremented every <b>1 mili-second</b> in an interested timer <b>ISR</b> (Interrupt Service Routine) by <b>FH</b> user
                            For this to happen, <b>FH_GlobalTimerCount.h</b> shall be included in the interested timer <b>ISR</b> (Interrupt Service Routine) file
                            If the expected number of bytes are received, the function does not wait anymore for the remaining time of the timeout
    DeviceAddress_01 => It shall be equal to the address of the device: FH_RFCommunication_DeviceAddress
    Function_CAN => It is the function in the message frame
    CAN_Commands_ReceiveW => It is the command of the function in the message frame
  @endverbatim
 *
 * @return FH_ErrorInfo is returned
 *

*/
FH_ErrorInfo FH_CAN_ProcessCommand_ReceiveW(FH_RFCommunication_Message* fh_RFCommunication_Message, uint8_t* FH_CAN_ReceiveData, uint8_t* FH_CAN_DataSize)
{
	FH_ErrorInfo fh_ErrorInfo;    // Error Information
	FH_ResetErrorInfo(&fh_ErrorInfo);    // Reset Error Information to default

	// 1 - Verifying the health of the received message
	fh_ErrorInfo = FH_CAN_ReceiveW_H(fh_RFCommunication_Message);
	if (fh_ErrorInfo.error_code != FH_ERROR_OK)    // Check if the message is healthy or not
	{
		return fh_ErrorInfo;    // Return the error
	}

	// 2 - Setting the addresses of the functions in <b>FH_Functions</b>, Section <b>FH_CAN</b> to an array of function pointer\n
	FH_CAN_ReceiveW_FuncPtrModel FH_CAN_ReceiveW_FuncPtr[FH_CAN_MaxPeripheralNumber];    // An array of function pointer FH_CAN_ReceiveW_FuncPtrModel
	FH_CAN_ReceiveW_S(FH_CAN_ReceiveW_FuncPtr);    // Setting the address of the functions

	// 3 - Calling the related function in <b>FH_Functions</b>, Section <b>FH_CAN</b> according to the first parameter of the Data in the message frame\n
	//     (The 2nd parameter after the first one, resembles the expected number of bytes of data to be received)\n
	//     (The next 4 parameters, resemble the timeout of receiving the expected number of bytes)
	FH_ResetErrorInfo(&fh_ErrorInfo);    // Reset Error Information to default
	fh_ErrorInfo = FH_CAN_ReceiveW_C(fh_RFCommunication_Message, FH_CAN_ReceiveData, FH_CAN_DataSize, FH_CAN_ReceiveW_FuncPtr);    // Calling the related function according to the first parameter of the Data in the message frame

	return fh_ErrorInfo;
}

/**
 * @brief This function handles <b>FH_CAN_Commands_ResetRB</b> command\n
 *        There are 3 main items handled in this function as following:\n
 *        1 - Verifying the health of the received message\n
 *        2 - Setting the addresses of the functions in <b>FH_Functions</b>, Section <b>FH_CAN</b> to an array of function pointer\n
 *        3 - Calling the related function in <b>FH_Functions</b>, Section <b>FH_CAN</b> according to the first parameter of the Data in the message frame
 *
 * @param  fh_RFCommunication_Message
 *         The message frame set by <b>RobotFramework</b>
 *
 * @verbatim
    ==============================================================================
                          ##### RobotFramework Example #####
    ==============================================================================
    @{MessageData} =    Create List    ${CAN01}
    &{Message}     =    Create Dictionary    DeviceAddress=${DeviceAddress_01}    Function=${Function_CAN}    Command=${CAN_Commands_ResetRB}    Data=@{MessageData}
    ${Result}    SendMessage    &{Message}

    Comments:

    CAN01 => It indicates the CAN 01
    DeviceAddress_01 => It shall be equal to the address of the device: FH_RFCommunication_DeviceAddress
    Function_CAN => It is the function in the message frame
    CAN_Commands_ResetRB => It is the command of the function in the message frame
  @endverbatim
 *
 * @return FH_ErrorInfo is returned
 *

*/
FH_ErrorInfo FH_CAN_ProcessCommand_ResetRB(FH_RFCommunication_Message* fh_RFCommunication_Message)
{
	FH_ErrorInfo fh_ErrorInfo;    // Error Information
	FH_ResetErrorInfo(&fh_ErrorInfo);    // Reset Error Information to default

	// 1 - Verifying the health of the received message
	fh_ErrorInfo = FH_CAN_ResetRB_H(fh_RFCommunication_Message);
	if (fh_ErrorInfo.error_code != FH_ERROR_OK)    // Check if the message is healthy or not
	{
		return fh_ErrorInfo;    // Return the error
	}

	// 2 - Setting the addresses of the functions in <b>FH_Functions</b>, Section <b>FH_CAN</b> to an array of function pointer
	FH_CAN_ResetRB_FuncPtrModel FH_CAN_ResetRB_FuncPtr[FH_CAN_MaxPeripheralNumber];    // An array of function pointer FH_CAN_ResetRB_FuncPtrModel
	FH_CAN_ResetRB_S (FH_CAN_ResetRB_FuncPtr);    // Setting the address of the functions

	// 3 - Calling the related function in <b>FH_Functions</b>, Section <b>FH_CAN</b> according to the first parameter of the Data in the message frame
	FH_ResetErrorInfo(&fh_ErrorInfo);    // Reset Error Information to default
	fh_ErrorInfo = FH_CAN_ResetRB_C(fh_RFCommunication_Message,FH_CAN_ResetRB_FuncPtr);    // Calling the related function according to the first parameter of the Data in the message frame

	return fh_ErrorInfo;
}

/**
 * @brief This function handles <b>FH_CAN_Commands_SSD8</b> command\n
 *        There are 3 main items handled in this function as following:\n
 *        1 - Verifying the health of the received message\n
 *        2 - Setting the addresses of the functions in <b>FH_Functions</b>, Section <b>FH_CAN</b> to an array of function pointer\n
 *        3 - Calling the related function in <b>FH_Functions</b>, Section <b>FH_CAN</b> according to the first parameter of the Data in the message frame\n
 *            (The 2nd parameter after the first one, resembles the interested length of the 8 bit data to be set)\n
 *            (The next parameters, resemble the data to be set in <b>FH_CAN01_SharedDataBuf_8Bits</b>)
 *
 * @param  fh_RFCommunication_Message
 *         The message frame set by <b>RobotFramework</b>
 *
 * @verbatim
    ==============================================================================
                          ##### RobotFramework Example #####
    ==============================================================================
    @{MessageData} =    Create List    ${CAN01}    04    AA    BB    CC    DD
    &{Message}     =    Create Dictionary    DeviceAddress=${DeviceAddress_01}    Function=${Function_CAN}    Command=${CAN_Commands_SSD8}    Data=@{MessageData}
    ${Result}    SendMessage    &{Message}

    Comments:

    CAN01 => It indicates the CAN 01
    04 => Example interested length of the 8 bit data to be set
    AA    BB    CC    DD => Example data (0xAA, 0xBB, 0xCC, 0xDD) to be set in <b>FH_CAN01_SharedDataBuf_8Bits</b>
    DeviceAddress_01 => It shall be equal to the address of the device: FH_RFCommunication_DeviceAddress
    Function_CAN => It is the function in the message frame
    CAN_Commands_SSD8 => It is the command of the function in the message frame
  @endverbatim
 *
 * @return FH_ErrorInfo is returned
 *

*/
FH_ErrorInfo FH_CAN_ProcessCommand_SSD8(FH_RFCommunication_Message* fh_RFCommunication_Message)
{
	FH_ErrorInfo fh_ErrorInfo;    // Error Information
	FH_ResetErrorInfo(&fh_ErrorInfo);    // Reset Error Information to default

	fh_ErrorInfo = FH_CAN_SSD8_H(fh_RFCommunication_Message);
	if (fh_ErrorInfo.error_code != FH_ERROR_OK)    // Check if the message is healthy or not
	{
		return fh_ErrorInfo;    // Return the error
	}

	FH_CAN_SSD8_FuncPtrModel FH_CAN_SSD8_FuncPtr[FH_CAN_MaxPeripheralNumber];    // An array of function pointer FH_CAN_SSD8_FuncPtrModel
	FH_CAN_SSD8_S (FH_CAN_SSD8_FuncPtr);    // Setting the address of the functions

	FH_ResetErrorInfo(&fh_ErrorInfo);    // Reset Error Information to default
	fh_ErrorInfo = FH_CAN_SSD8_C(fh_RFCommunication_Message, FH_CAN_SSD8_FuncPtr);    // Calling the related function according to the first parameter of the Data in the message frame

	return fh_ErrorInfo;
}

/**
 * @brief This function handles <b>FH_CAN_Commands_SSD16</b> command\n
 *        There are 3 main items handled in this function as following:\n
 *        1 - Verifying the health of the received message\n
 *        2 - Setting the addresses of the functions in <b>FH_Functions</b>, Section <b>FH_CAN</b> to an array of function pointer\n
 *        3 - Calling the related function in <b>FH_Functions</b>, Section <b>FH_CAN</b> according to the first parameter of the Data in the message frame\n
 *            (The 2nd parameter after the first one, resembles the interested length of the 16 bit data to be set)\n
 *            (The next parameters, resemble the data to be set in <b>FH_CAN01_SharedDataBuf_16Bits</b>)
 *
 * @param  fh_RFCommunication_Message
 *         The message frame set by <b>RobotFramework</b>
 *
 * @verbatim
    ==============================================================================
                          ##### RobotFramework Example #####
    ==============================================================================
    @{MessageData} =    Create List    ${CAN01}    02    AA    BB    CC    DD
    &{Message}     =    Create Dictionary    DeviceAddress=${DeviceAddress_01}    Function=${Function_CAN}    Command=${CAN_Commands_SSD16}    Data=@{MessageData}
    ${Result}    SendMessage    &{Message}

    Comments:

    CAN01 => It indicates the CAN 01
    02 => Example interested length of the 16 bit data to be set
    AA    BB    CC    DD => Example data (0xAABB and 0xCCDD) to be set in <b>FH_CAN01_SharedDataBuf_16Bits</b>
    DeviceAddress_01 => It shall be equal to the address of the device: FH_RFCommunication_DeviceAddress
    Function_CAN => It is the function in the message frame
    CAN_Commands_SSD16 => It is the command of the function in the message frame
  @endverbatim
 *
 * @return FH_ErrorInfo is returned
 *

*/
FH_ErrorInfo FH_CAN_ProcessCommand_SSD16(FH_RFCommunication_Message* fh_RFCommunication_Message)
{
	FH_ErrorInfo fh_ErrorInfo;    // Error Information
	FH_ResetErrorInfo(&fh_ErrorInfo);    // Reset Error Information to default

	fh_ErrorInfo = FH_CAN_SSD16_H(fh_RFCommunication_Message);
	if (fh_ErrorInfo.error_code != FH_ERROR_OK)    // Check if the message is healthy or not
	{
		return fh_ErrorInfo;    // Return the error
	}

	FH_CAN_SSD16_FuncPtrModel FH_CAN_SSD16_FuncPtr[FH_CAN_MaxPeripheralNumber];    // An array of function pointer FH_CAN_SSD16_FuncPtrModel
	FH_CAN_SSD16_S(FH_CAN_SSD16_FuncPtr);    // Setting the address of the functions

	FH_ResetErrorInfo(&fh_ErrorInfo);    // Reset Error Information to default
	fh_ErrorInfo = FH_CAN_SSD16_C(fh_RFCommunication_Message, FH_CAN_SSD16_FuncPtr);    // Calling the related function according to the first parameter of the Data in the message frame

	return fh_ErrorInfo;
}

/**
 * @brief This function handles <b>FH_CAN_Commands_SSD32</b> command\n
 *        There are 3 main items handled in this function as following:\n
 *        1 - Verifying the health of the received message\n
 *        2 - Setting the addresses of the functions in <b>FH_Functions</b>, Section <b>FH_CAN</b> to an array of function pointer\n
 *        3 - Calling the related function in <b>FH_Functions</b>, Section <b>FH_CAN</b> according to the first parameter of the Data in the message frame\n
 *            (The 2nd parameter after the first one, resembles the interested length of the 32 bit data to be set)\n
 *            (The next parameters, resemble the data to be set in <b>FH_CAN01_SharedDataBuf_32Bits</b>)
 *
 * @param  fh_RFCommunication_Message
 *         The message frame set by <b>RobotFramework</b>
 *
 * @verbatim
    ==============================================================================
                          ##### RobotFramework Example #####
    ==============================================================================
    @{MessageData} =    Create List    ${CAN01}    02    AA    BB    CC    DD    01    02    03    04
    &{Message}     =    Create Dictionary    DeviceAddress=${DeviceAddress_01}    Function=${Function_CAN}    Command=${CAN_Commands_SSD32}    Data=@{MessageData}
    ${Result}    SendMessage    &{Message}

    Comments:

    CAN01 => It indicates the CAN 01
    02 => Example interested length of the 32 bit data to be set
    AA    BB    CC    DD    01    02    03    04 => Example data (0xAABBCCDD and 0x01020304) to be set in <b>FH_CAN01_SharedDataBuf_32Bits</b>
    DeviceAddress_01 => It shall be equal to the address of the device: FH_RFCommunication_DeviceAddress
    Function_CAN => It is the function in the message frame
    CAN_Commands_SSD32 => It is the command of the function in the message frame
  @endverbatim
 *
 * @return FH_ErrorInfo is returned
 *

*/
FH_ErrorInfo FH_CAN_ProcessCommand_SSD32(FH_RFCommunication_Message* fh_RFCommunication_Message)
{
	FH_ErrorInfo fh_ErrorInfo;    // Error Information
	FH_ResetErrorInfo(&fh_ErrorInfo);    // Reset Error Information to default

	fh_ErrorInfo = FH_CAN_SSD32_H(fh_RFCommunication_Message);
	if (fh_ErrorInfo.error_code != FH_ERROR_OK)    // Check if the message is healthy or not
	{
		return fh_ErrorInfo;    // Return the error
	}

	FH_CAN_SSD32_FuncPtrModel FH_CAN_SSD32_FuncPtr[FH_CAN_MaxPeripheralNumber];    // An array of function pointer FH_CAN_SSD32_FuncPtrModel
	FH_CAN_SSD32_S(FH_CAN_SSD32_FuncPtr);    // Setting the address of the functions

	FH_ResetErrorInfo(&fh_ErrorInfo);    // Reset Error Information to default
	fh_ErrorInfo = FH_CAN_SSD32_C(fh_RFCommunication_Message, FH_CAN_SSD32_FuncPtr);    // Calling the related function according to the first parameter of the Data in the message frame

	return fh_ErrorInfo;
}

/**
 * @brief This function handles <b>FH_CAN_Commands_GSD8</b> command\n
 *        There are 3 main items handled in this function as following:\n
 *        1 - Verifying the health of the received message\n
 *        2 - Setting the addresses of the functions in <b>FH_Functions</b>, Section <b>FH_CAN</b> to an array of function pointer\n
 *        3 - Calling the related function in <b>FH_Functions</b>, Section <b>FH_CAN</b> according to the first parameter of the Data in the message frame
 *
 * @param  fh_RFCommunication_Message
 *         The message frame set by <b>RobotFramework</b>
 *
 * @verbatim
    ==============================================================================
                          ##### RobotFramework Example #####
    ==============================================================================
    @{MessageData} =    Create List    ${CAN01}
    &{Message}     =    Create Dictionary    DeviceAddress=${DeviceAddress_01}    Function=${Function_CAN}    Command=${CAN_Commands_GSD8}    Data=@{MessageData}
    ${Result}    SendMessage    &{Message}

    Comments:

    CAN01 => It indicates the CAN 01
    DeviceAddress_01 => It shall be equal to the address of the device: FH_RFCommunication_DeviceAddress
    Function_CAN => It is the function in the message frame
    CAN_Commands_GSD8 => It is the command of the function in the message frame
  @endverbatim
 *
 * @return FH_ErrorInfo is returned
 *

*/
FH_ErrorInfo FH_CAN_ProcessCommand_GSD8(FH_RFCommunication_Message* fh_RFCommunication_Message, uint8_t* FH_CAN_DataLength, uint8_t* FH_CAN_FH_CAN_Data)
{
	FH_ErrorInfo fh_ErrorInfo;    // Error Information
	FH_ResetErrorInfo(&fh_ErrorInfo);    // Reset Error Information to default

	// 1 - Verifying the health of the received message\n
	fh_ErrorInfo = FH_CAN_GSD8_H(fh_RFCommunication_Message);
	if (fh_ErrorInfo.error_code != FH_ERROR_OK)    // Check if the message is healthy or not
	{
		return fh_ErrorInfo;    // Return the error
	}

	// 2 - Setting the addresses of the functions in <b>FH_Functions</b>, Section <b>FH_CAN</b> to an array of function pointer
	FH_CAN_GSD8_FuncPtrModel FH_CAN_GSD8_FuncPtr[FH_CAN_MaxPeripheralNumber];    // An array of function pointer FH_CAN_GSD8_FuncPtrModel
	FH_CAN_GSD8_S(FH_CAN_GSD8_FuncPtr);    // Setting the address of the functions

	// 3 - Calling the related function in <b>FH_Functions</b>, Section <b>FH_CAN</b> according to the first parameter of the Data in the message frame
	FH_ResetErrorInfo(&fh_ErrorInfo);    // Reset Error Information to default
	fh_ErrorInfo = FH_CAN_GSD8_C(fh_RFCommunication_Message, FH_CAN_DataLength, FH_CAN_FH_CAN_Data, FH_CAN_GSD8_FuncPtr);    // Calling the related function according to the first parameter of the Data in the message frame

	return fh_ErrorInfo;
}

/**
 * @brief This function handles <b>FH_CAN_Commands_GSD16</b> command\n
 *        There are 3 main items handled in this function as following:\n
 *        1 - Verifying the health of the received message\n
 *        2 - Setting the addresses of the functions in <b>FH_Functions</b>, Section <b>FH_CAN</b> to an array of function pointer\n
 *        3 - Calling the related function in <b>FH_Functions</b>, Section <b>FH_CAN</b> according to the first parameter of the Data in the message frame
 *
 * @param  fh_RFCommunication_Message
 *         The message frame set by <b>RobotFramework</b>
 *
 * @verbatim
    ==============================================================================
                          ##### RobotFramework Example #####
    ==============================================================================
    @{MessageData} =    Create List    ${CAN01}
    &{Message}     =    Create Dictionary    DeviceAddress=${DeviceAddress_01}    Function=${Function_CAN}    Command=${CAN_Commands_GSD16}    Data=@{MessageData}
    ${Result}    SendMessage    &{Message}

    Comments:

    CAN01 => It indicates the CAN 01
    DeviceAddress_01 => It shall be equal to the address of the device: FH_RFCommunication_DeviceAddress
    Function_CAN => It is the function in the message frame
    CAN_Commands_GSD16 => It is the command of the function in the message frame
  @endverbatim
 *
 * @return FH_ErrorInfo is returned
 *

*/
FH_ErrorInfo FH_CAN_ProcessCommand_GSD16(FH_RFCommunication_Message* fh_RFCommunication_Message, uint8_t* FH_CAN_DataLength, uint8_t* FH_CAN_FH_CAN_Data)
{
	FH_ErrorInfo fh_ErrorInfo;    // Error Information
	FH_ResetErrorInfo(&fh_ErrorInfo);    // Reset Error Information to default

	// 1 - Verifying the health of the received message
	fh_ErrorInfo = FH_CAN_GSD16_H(fh_RFCommunication_Message);
	if (fh_ErrorInfo.error_code != FH_ERROR_OK)    // Check if the message is healthy or not
	{
		return fh_ErrorInfo;    // Return the error
	}

	// 2 - Setting the addresses of the functions in <b>FH_Functions</b>, Section <b>FH_CAN</b> to an array of function pointer
	FH_CAN_GSD16_FuncPtrModel FH_CAN_GSD16_FuncPtr[FH_CAN_MaxPeripheralNumber];    // An array of function pointer FH_CAN_GSD16_FuncPtrModel
	FH_CAN_GSD16_S(FH_CAN_GSD16_FuncPtr);    // Setting the address of the functions

	// 3 - Calling the related function in <b>FH_Functions</b>, Section <b>FH_CAN</b> according to the first parameter of the Data in the message frame
	FH_ResetErrorInfo(&fh_ErrorInfo);    // Reset Error Information to default
	fh_ErrorInfo = FH_CAN_GSD16_C(fh_RFCommunication_Message, FH_CAN_DataLength, FH_CAN_FH_CAN_Data, FH_CAN_GSD16_FuncPtr);    // Calling the related function according to the first parameter of the Data in the message frame

	return fh_ErrorInfo;
}

/**
 * @brief This function handles <b>FH_CAN_Commands_GSD32</b> command\n
 *        There are 3 main items handled in this function as following:\n
 *        1 - Verifying the health of the received message\n
 *        2 - Setting the addresses of the functions in <b>FH_Functions</b>, Section <b>FH_CAN</b> to an array of function pointer\n
 *        3 - Calling the related function in <b>FH_Functions</b>, Section <b>FH_CAN</b> according to the first parameter of the Data in the message frame
 *
 * @param  fh_RFCommunication_Message
 *         The message frame set by <b>RobotFramework</b>
 *
 * @verbatim
    ==============================================================================
                          ##### RobotFramework Example #####
    ==============================================================================
    @{MessageData} =    Create List    ${CAN01}
    &{Message}     =    Create Dictionary    DeviceAddress=${DeviceAddress_01}    Function=${Function_CAN}    Command=${CAN_Commands_GSD32}    Data=@{MessageData}
    ${Result}    SendMessage    &{Message}

    Comments:

    CAN01 => It indicates the CAN 01
    DeviceAddress_01 => It shall be equal to the address of the device: FH_RFCommunication_DeviceAddress
    Function_CAN => It is the function in the message frame
    CAN_Commands_GSD32 => It is the command of the function in the message frame
  @endverbatim
 *
 * @return FH_ErrorInfo is returned
 *

*/
FH_ErrorInfo FH_CAN_ProcessCommand_GSD32(FH_RFCommunication_Message* fh_RFCommunication_Message, uint8_t* FH_CAN_DataLength, uint8_t* FH_CAN_FH_CAN_Data)
{
	FH_ErrorInfo fh_ErrorInfo;    // Error Information
	FH_ResetErrorInfo(&fh_ErrorInfo);    // Reset Error Information to default

	fh_ErrorInfo = FH_CAN_GSD32_H(fh_RFCommunication_Message);
	if (fh_ErrorInfo.error_code != FH_ERROR_OK)    // Check if the message is healthy or not
	{
		return fh_ErrorInfo;    // Return the error
	}

	FH_CAN_GSD32_FuncPtrModel FH_CAN_GSD32_FuncPtr[FH_CAN_MaxPeripheralNumber];    // An array of function pointer FH_CAN_GSD32_FuncPtrModel
	FH_CAN_GSD32_S(FH_CAN_GSD32_FuncPtr);    // Setting the address of the functions

	FH_ResetErrorInfo(&fh_ErrorInfo);    // Reset Error Information to default
	fh_ErrorInfo = FH_CAN_GSD32_C(fh_RFCommunication_Message, FH_CAN_DataLength, FH_CAN_FH_CAN_Data, FH_CAN_GSD32_FuncPtr);    // Calling the related function according to the first parameter of the Data in the message frame

	return fh_ErrorInfo;
}

#endif
