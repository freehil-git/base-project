/**
  * @file
  * @brief
  *       <b>File Map:</b>\n
  *       <b>FH_Root</b>, Section <b>FH_Perif</b>, <b>FH_DO</b> (Digital Output), <b>Cmd</b> (Command), <b>SetStatus</b>, <b>SetStatus_C</b> (SetStatus Call)\n
  *       Functions in this file, Call the related function in <b>FH_Functions</b>, Section <b>FH_DO</b> (Digital Output)
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

/* Includes ------------------------------------------------------------------*/
#include "../../../../../../../FH_Embedded/FH_Root/FH_Perif/FH_DO/Cmd/SetStatus/SetStatus_C/FH_DO_SetStatus_C.h"

#include "../../../../../../../FH_Embedded/FH_Root/FH_General/FH_GeneralFunctions/FH_GeneralFunctions.h"
#include "../../../../../../../FH_Embedded/FH_Setup/FH_DeviceAddress/FH_DeviceAddress.h"

#if FH_DO_MaxPeripheralNumber > 0    // It is configurable in FH_DevicePeripherals.h

/**
 * @brief This function calls the related function in <b>FH_Functions</b>, Section <b>FH_DO</b> (Digital Output) according to the first parameter of the Data in the message frame
 *
 * @param  fh_RFCommunication_Message
 *         The message frame set by <b>RobotFramework</b>
 * @param  fH_DO_SetStatus_FuncPtr
 *         The array of function pointers
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
 * @return FH_ErrorInfo is returned
 *

*/
FH_ErrorInfo FH_DO_SetStatus_C (FH_RFCommunication_Message* fh_RFCommunication_Message, FH_DO_SetStatus_FuncPtrModel *FH_DO_SetStatus_FuncPtr)
{
	FH_ErrorInfo fh_ErrorInfo;    // Error Information
	FH_ResetErrorInfo(&fh_ErrorInfo);    // Reset Error Information to default

	for (uint8_t i = 1; i <= FH_DO_MaxPeripheralNumber; i++)    // Iteration through all defined  peripherals
	{
		if (i == fh_RFCommunication_Message -> Data[DO_SetStatus_PeripheralNumber])    // If the PeripheralNumber in the message frame is met
		{
			if (FH_DO_SetStatus_FuncPtr[i-1] != NULL_PTR)    // If the address of the function is truly assigned
			{
				fh_ErrorInfo = FH_DO_SetStatus_FuncPtr[i-1](fh_RFCommunication_Message -> Data[1]);    // Call the related function
			}
			else
			{
				fh_ErrorInfo.error_code = FH_ERROR_Root;    // There is Root error
			}
			return fh_ErrorInfo;
		}
	}
	fh_ErrorInfo.error_code = FH_ERROR_MessageFrame;    // There is message frame error
	return fh_ErrorInfo;
}

/**
 * @brief  This function calls the related function in <b>FH_Functions</b>, Section <b>FH_DO</b> (Digital Output) according to the 16 first parameters of the Data in the message frame\n
 *         (The first  8 bytes as mask resemble 64 bits and each bit resembles 1 <b>DO</b> (Digital Output) and if the bit is 1, the related <b>DO</b> (Digital Output) function will be called)\n
 *         (The second 8 bytes as data resemble 64 bits and each bit resembles status of 1 <b>DO</b> (Digital Output) as 1 or 0 of the corresponding bit in the first 8 bytes)
 *
 * @param  fh_RFCommunication_Message
 *         The message frame set by <b>RobotFramework</b>
 * @param  fH_DO_SetStatus_FuncPtr
 *         The array of function pointers
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
 * @warning
 *	   By default, in <b>SetStatusMULTI</b> (Which is mass status set of up to 64 <b>DO</b> (Digital Output)) command, 8 bytes which is 64 bits (which means 64 <b>DO</b> (Digital Output)) is used in the command\n
 *     To use <b>SetStatusMULTI</b> (Which is mass status set of up to 64 <b>DO</b> (Digital Output)) command, <b>FH_DO_MaxPeripheralNumber</b> and <b>FH_DO_MULTI_MaxPeripheralNumberLimit</b> shall be set to 64
 *

*/
FH_ErrorInfo FH_DO_SetStatusMULTI_C (FH_RFCommunication_Message* fh_RFCommunication_Message, FH_DO_SetStatus_FuncPtrModel *FH_DO_SetStatus_FuncPtr)
{
	FH_ErrorInfo fh_ErrorInfo;    // Error Information
	FH_ResetErrorInfo(&fh_ErrorInfo);    // Reset Error Information to default

	uint8_t DO_SetStatusMULTI_StatusMaskByteCounter = 0;    // It temporarily stores the index (0 - 7) of the 8 bytes of mask in the Data part of the message frame
	uint8_t DO_SetStatusMULTI_StatusMaskByte = 0;    // It temporarily stores the byte value with the index number (DO_SetStatusMULTI_StatusMaskByteCounter) of the 8 bytes of mask in the Data part of the message frame
	uint8_t DO_SetStatusMULTI_StatusMaskBitCounter = 0;    // It temporarily stores the index (0 - 7) of the every bit in the byte of mask in the Data part of the message frame
	uint8_t DO_SetStatusMULTI_StatusMaskBit = 0;    // It temporarily stores the bit value with the index number (DO_SetStatusMULTI_StatusMaskBitCounter) of every bit in the byte of mask in the Data part of the message frame

	uint8_t DO_SetStatusMULTI_StatusByteCounter = 0;    // It temporarily stores the index (0 - 7) of the 8 bytes of data after mask in the Data part of the message frame
	uint8_t DO_SetStatusMULTI_StatusByte = 0;    // It temporarily stores the byte value with the index number (DO_SetStatusMULTI_StatusByteCounter) of the 8 bytes of data after mask in the Data part of the message frame
	uint8_t DO_SetStatusMULTI_StatusBitCounter = 0;    // It temporarily stores the index (0 - 7) of the every bit in the byte of data after mask in the Data part of the message frame
	uint8_t DO_SetStatusMULTI_StatusBit = 0;    // It temporarily stores the bit value with the index number (DO_SetStatusMULTI_StatusBitCounter) of every bit in the byte of data after mask in the Data part of the message frame

	uint8_t MaxPeripheralNumber = 0;    // MaxPeripheralNumber shall be the minimum of FH_DO_MaxPeripheralNumber and FH_DO_MULTI_MaxPeripheralNumberLimit to prevent calling an undefined function (with wrong address)
	if (FH_DO_MaxPeripheralNumber > FH_DO_MULTI_MaxPeripheralNumberLimit)    // If FH_DO_MaxPeripheralNumber is bigger than FH_DO_MULTI_MaxPeripheralNumberLimit (while both shall be 64)
	{
		MaxPeripheralNumber = FH_DO_MULTI_MaxPeripheralNumberLimit;    // The minimum is FH_DO_MULTI_MaxPeripheralNumberLimit
	}
	else
	{
		MaxPeripheralNumber = FH_DO_MaxPeripheralNumber;    // The minimum is FH_DO_MaxPeripheralNumber
	}

	for (uint8_t i = 1; i <= MaxPeripheralNumber; i++)    // Iteration through all defined  peripherals
	{
		DO_SetStatusMULTI_StatusMaskByte = fh_RFCommunication_Message -> Data[DO_SetStatusMULTI_StatusMaskByteCounter];    // Temporarily store the related byte value with the related index number of the 8 bytes of mask
		DO_SetStatusMULTI_StatusMaskBit  = DO_SetStatusMULTI_StatusMaskByte & (0x80 >> DO_SetStatusMULTI_StatusMaskBitCounter);    // Temporarily store the related bit value from the related byte value from the 8 bytes of mask

		if (DO_SetStatusMULTI_StatusMaskBit != 0)    // If the specified bit is 1, start the related process (If it is 0, it shall be neglected)
		{
			if (FH_DO_SetStatus_FuncPtr[i-1] != NULL_PTR)    // If the address of the function is truly assigned
			{
				DO_SetStatusMULTI_StatusByteCounter = DO_SetStatusMULTI_StatusMaskByteCounter + 8;    // 8 bytes ahead is the position of the data byte related to a mask byte
				DO_SetStatusMULTI_StatusByte = fh_RFCommunication_Message -> Data[DO_SetStatusMULTI_StatusByteCounter];    // Temporarily store the related byte value with the related index number of the 8 bytes of data after mask
				DO_SetStatusMULTI_StatusBit  = DO_SetStatusMULTI_StatusByte & (0x80 >> DO_SetStatusMULTI_StatusBitCounter);    // Temporarily store the related bit value from the related byte value from the 8 bytes of data after mask

				if (DO_SetStatusMULTI_StatusBit != 0)
				{
					DO_SetStatusMULTI_StatusBit = 1;    // Status is Set (1)
				}
				else
				{
					DO_SetStatusMULTI_StatusBit = 0;    // Status is Reset (0)
				}
				FH_DO_SetStatus_FuncPtr[i-1](DO_SetStatusMULTI_StatusBit);    // Call the related function with the specified bit value as argument
			}
			else
			{
			}
		}
		DO_SetStatusMULTI_StatusBitCounter++;    // Increase the DO_SetStatusMULTI_StatusBitCounter
		DO_SetStatusMULTI_StatusMaskBitCounter++;    // Increase the DO_SetStatusMULTI_StatusMaskBitCounter
		if (DO_SetStatusMULTI_StatusMaskBitCounter == 8)    // If the whole bits of the byte are already processed
		{
			DO_SetStatusMULTI_StatusMaskBitCounter = 0;    // Reset DO_SetStatusMULTI_StatusMaskBitCounter
			DO_SetStatusMULTI_StatusMaskByteCounter++;    // Increase DO_SetStatusMULTI_StatusMaskByteCounter
			DO_SetStatusMULTI_StatusBitCounter = 0;
		}
	}
	return fh_ErrorInfo;
}

#endif
