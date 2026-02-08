/**
  * @file
  * @brief
  *       <b>File Map:</b>\n
  *       <b>FH_Root</b>, Section <b>FH_Perif</b>, <b>FH_DI</b> (Digital Input), <b>Cmd</b> (Command), <b>Init</b>, <b>Init_C</b> (Init Call)\n
  *       Functions in this file, Call the related function in <b>FH_Functions</b>, Section <b>FH_DI</b> (Digital Input) according to the first parameter of the Data in the message frame
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
#include "../../../../../../FH_Setup/FH_DeviceAddress/FH_DeviceAddress.h"
#include "../../../../../../../FH_Embedded/FH_Root/FH_Perif/FH_DI/Cmd/Init/Init_C/FH_DI_Init_C.h"

#include "../../../../../../../FH_Embedded/FH_Root/FH_General/FH_GeneralFunctions/FH_GeneralFunctions.h"
#include "../../../../../../../FH_Embedded/FH_Setup/FH_DeviceAddress/FH_DeviceAddress.h"

#if FH_DI_MaxPeripheralNumber > 0    // It is configurable in FH_DevicePeripherals.h

/**
 * @brief This function calls the related function in <b>FH_Functions</b>, Section <b>FH_DI</b> (Digital Input) according to the first parameter of the Data in the message frame
 *
 * @param  fh_RFCommunication_Message
 *         The message frame set by <b>RobotFramework</b>
 * @param  fH_DI_Init_FuncPtr
 *         The array of function pointers
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
FH_ErrorInfo FH_DI_Init_C (FH_RFCommunication_Message* fh_RFCommunication_Message, FH_DI_Init_FuncPtrModel *FH_DI_Init_FuncPtr)
{
	FH_ErrorInfo fh_ErrorInfo;    // Error Information
	FH_ResetErrorInfo(&fh_ErrorInfo);    // Reset Error Information to default

	for (uint8_t i = 1; i <= FH_DI_MaxPeripheralNumber; i++)    // Iteration through all defined  peripherals
	{
		if (i == fh_RFCommunication_Message -> Data[DI_Init_PeripheralNumber])    // If the PeripheralNumber in the message frame is met
		{
			if (FH_DI_Init_FuncPtr[i-1] != NULL_PTR)    // If the address of the function is truly assigned
			{
				fh_ErrorInfo = FH_DI_Init_FuncPtr[i-1]();    // Call the related function
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
 * @brief This function calls the related function in <b>FH_Functions</b>, Section <b>FH_DI</b> (Digital Input) according to the first parameter of the Data in the message frame
 *
 * @param  fh_RFCommunication_Message
 *         The message frame set by <b>RobotFramework</b>
 * @param  fH_DI_Init_FuncPtr
 *         The array of function pointers
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
 * @warning
 *	   By default, in <b>InitMULTI</b> (Which is mass initialization of up to 64 <b>DI</b> (Digital Input)) command, 8 bytes which is 64 bits (which means 64 <b>DI</b> (Digital Input)) is used in the command\n
 *     To use <b>InitMULTI</b> (Which is mass initialization of up to 64 <b>DI</b> (Digital Input)) command, <b>FH_DI_MaxPeripheralNumber</b> and <b>FH_DI_MULTI_MaxPeripheralNumberLimit</b> shall be set to 64
 *

*/
FH_ErrorInfo FH_DI_InitMULTI_C (FH_RFCommunication_Message* fh_RFCommunication_Message, FH_DI_Init_FuncPtrModel *FH_DI_Init_FuncPtr)
{
	FH_ErrorInfo fh_ErrorInfo;    // Error Information
	FH_ResetErrorInfo(&fh_ErrorInfo);    // Reset Error Information to default

	uint8_t DI_InitMULTI_MaskByteCounter = 0;    // It temporarily stores the index (0 - 7) of the 8 bytes of mask in the Data part of the message frame
	uint8_t DI_InitMULTI_MaskByte = 0;    // It temporarily stores the byte value with the index number (DI_InitMULTI_MaskByteCounter) of the 8 bytes of mask in the Data part of the message frame
	uint8_t DI_InitMULTI_MaskBitCounter = 0;    // It temporarily stores the index (0 - 7) of the every bit in the byte of mask in the Data part of the message frame
	uint8_t DI_InitMULTI_MaskBit = 0;    // It temporarily stores the bit value with the index number (DI_InitMULTI_MaskBitCounter) of every bit in the byte of mask in the Data part of the message frame

	uint8_t MaxPeripheralNumber = 0;    // MaxPeripheralNumber shall be the minimum of FH_DI_MaxPeripheralNumber and FH_DI_MULTI_MaxPeripheralNumberLimit to prevent calling an undefined function (with wrong address)
	if (FH_DI_MaxPeripheralNumber > FH_DI_MULTI_MaxPeripheralNumberLimit)    // If FH_DI_MaxPeripheralNumber is bigger than FH_DI_MULTI_MaxPeripheralNumberLimit (while both shall be 64)
	{
		MaxPeripheralNumber = FH_DI_MULTI_MaxPeripheralNumberLimit;    // The minimum is FH_DI_MULTI_MaxPeripheralNumberLimit
	}
	else
	{
		MaxPeripheralNumber = FH_DI_MaxPeripheralNumber;    // The minimum is FH_DI_MaxPeripheralNumber
	}

	for (uint8_t i = 1; i <= MaxPeripheralNumber; i++)    // Iteration through all defined  peripherals
	{
		DI_InitMULTI_MaskByte = fh_RFCommunication_Message -> Data[DI_InitMULTI_MaskByteCounter];    // Temporarily store the related byte value with the related index number of the 8 bytes of mask
		DI_InitMULTI_MaskBit  = DI_InitMULTI_MaskByte & (0x80 >> DI_InitMULTI_MaskBitCounter);    // Temporarily store the related bit value from the related byte value from the 8 bytes of mask
		if (DI_InitMULTI_MaskBit != 0)    // If the specified bit is 1, start the related process (If it is 0, it shall be neglected)
		{
			if (FH_DI_Init_FuncPtr[i-1] != NULL_PTR)    // If the address of the function is truly assigned
			{
				FH_DI_Init_FuncPtr[i-1]();    // Call the related function
			}
			else
			{
			}
		}
		DI_InitMULTI_MaskBitCounter++;    // Increase the DI_InitMULTI_MaskBit
		if (DI_InitMULTI_MaskBitCounter == 8)    // If the whole bits of the byte are already processed
		{
			DI_InitMULTI_MaskBitCounter = 0;    // Reset DI_InitMULTI_MaskBit
			DI_InitMULTI_MaskByteCounter++;    // Increase DI_InitMULTI_MaskByteCounter
		}
	}
	return fh_ErrorInfo;
}

#endif
