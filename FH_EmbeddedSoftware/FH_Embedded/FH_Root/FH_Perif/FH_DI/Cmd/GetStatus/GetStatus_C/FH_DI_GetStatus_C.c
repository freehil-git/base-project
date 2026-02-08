/**
  * @file
  * @brief
  *       <b>File Map:</b>\n
  *       <b>FH_Root</b>, Section <b>FH_Perif</b>, <b>FH_DI</b> (Digital Input), <b>Cmd</b> (Command), <b>GetStatus</b>, <b>GetStatus_C</b> (GetStatus Call)\n
  *       Functions in this file, Call the related function in <b>FH_Functions</b>, Section <b>FH_DI</b> (Digital Input)
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
#include "../../../../../../../FH_Embedded/FH_Root/FH_Perif/FH_DI/Cmd/GetStatus/GetStatus_C/FH_DI_GetStatus_C.h"

#include "../../../../../../../FH_Embedded/FH_Root/FH_General/FH_GeneralFunctions/FH_GeneralFunctions.h"
#include "../../../../../../../FH_Embedded/FH_Setup/FH_DeviceAddress/FH_DeviceAddress.h"

#if FH_DI_MaxPeripheralNumber > 0    // It is configurable in FH_DevicePeripherals.h

/**
 * @brief This function calls the related function in <b>FH_Functions</b>, Section <b>FH_DI</b> (Digital Input) according to the first parameter of the Data in the message frame
 *
 * @param  fh_RFCommunication_Message
 *         The message frame set by <b>RobotFramework</b>
 * @param  fH_DI_Data
 *         *fH_DI_Data will be set with the value of the related <b>Digital Input</b>
 * @param  fH_DI_GetStatus_FuncPtr
 *         The array of function pointers
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
 * @return FH_ErrorInfo is returned
 *

*/
FH_ErrorInfo FH_DI_GetStatus_C (FH_RFCommunication_Message* fh_RFCommunication_Message, uint8_t* fH_DI_Data, FH_DI_GetStatus_FuncPtrModel *fH_DI_GetStatus_FuncPtr)
{
	FH_ErrorInfo fh_ErrorInfo;    // Error Information
	FH_ResetErrorInfo(&fh_ErrorInfo);    // Reset Error Information to default

	for (uint8_t i = 1; i <= FH_DI_MaxPeripheralNumber; i++)    // Iteration through all defined  peripherals
	{
		if (i == fh_RFCommunication_Message -> Data[DI_GetStatus_PeripheralNumber])    // If the PeripheralNumber in the message frame is met
		{
			if (fH_DI_GetStatus_FuncPtr[i-1] != NULL_PTR)    // If the address of the function is truly assigned
			{
				fh_ErrorInfo = fH_DI_GetStatus_FuncPtr[i-1](fH_DI_Data);    // Call the related function
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
 * @brief  This function Calls the related function in <b>FH_Functions</b>, Section <b>FH_DI</b> (Digital Input) according to the 8 first parameters of the Data in the message frame\n
 *         (The first 8 parameters as mask resemble 64 bits and each bit resembles 1 <b>DI</b> (Digital Input) and if the bit is 1, the related <b>DI</b> (Digital Input) function will be called)
 *
 * @param  fh_RFCommunication_Message
 *         The message frame set by <b>RobotFramework</b>
 * @param  fH_DI_MULTIData
 *         *fH_DI_MULTIData will be set with 8 bytes as 64 bits as 64 <b>Digital Input</b>
 * @param  fH_DI_GetStatus_FuncPtr
 *         The array of function pointers
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
 * @warning
 *	   By default, in <b>GetStatusMULTI</b> (Which is mass status get of up to 64 <b>DI</b> (Digital Input)) command, 8 bytes which is 64 bits (which means 64 <b>DI</b> (Digital Input)) is used in the command\n
 *     To use <b>GetStatusMULTI</b> (Which is mass status get of up to 64 <b>DI</b> (Digital Input)) command, <b>FH_DI_MaxPeripheralNumber</b> and <b>FH_DI_MULTI_MaxPeripheralNumberLimit</b> shall be set to 64
 *

*/
FH_ErrorInfo FH_DI_GetStatusMULTI_C (FH_RFCommunication_Message* fh_RFCommunication_Message, uint8_t* fH_DI_MULTIData, FH_DI_GetStatus_FuncPtrModel *FH_DI_GetStatus_FuncPtr)
{
	FH_ErrorInfo fh_ErrorInfo;    // Error Information
	FH_ResetErrorInfo(&fh_ErrorInfo);    // Reset Error Information to default

	uint8_t FH_DI_Data = 0;    // The status of the related digital input
	uint8_t* FH_DI_Data_Ptr = &FH_DI_Data;    // Pointer with &FH_DI_Data address

	uint8_t DI_GetStatusMULTI_StatusMaskByteCounter = 0;    // It temporarily stores the index (0 - 7) of the 8 bytes of mask in the Data part of the message frame
	uint8_t DI_GetStatusMULTI_StatusMaskByte = 0;    // It temporarily stores the byte value with the index number (DI_GetStatusMULTI_StatusMaskByteCounter) of the 8 bytes of mask in the Data part of the message frame
	uint8_t DI_GetStatusMULTI_StatusMaskBitCounter = 0;    // It temporarily stores the index (0 - 7) of the every bit in the byte of mask in the Data part of the message frame
	uint8_t DI_GetStatusMULTI_StatusMaskBit = 0;    // It temporarily stores the bit value with the index number (DI_InitMULTI_MaskBitCounter) of every bit in the byte of mask in the Data part of the message frame

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
		DI_GetStatusMULTI_StatusMaskByte = fh_RFCommunication_Message -> Data[DI_GetStatusMULTI_StatusMaskByteCounter];    // Temporarily store the related byte value with the related index number of the 8 bytes of mask
		DI_GetStatusMULTI_StatusMaskBit  = DI_GetStatusMULTI_StatusMaskByte & (0x80 >> DI_GetStatusMULTI_StatusMaskBitCounter);    // Temporarily store the related bit value from the related byte value from the 8 bytes of mask

		if (DI_GetStatusMULTI_StatusMaskBit != 0)    // If the specified bit is 1, start the related process (If it is 0, it shall be neglected)
		{
			if (FH_DI_GetStatus_FuncPtr[i-1] != NULL_PTR)    // If the address of the function is truly assigned
			{
				FH_DI_Data = 0;    // The status of the related digital input
				FH_DI_GetStatus_FuncPtr[i-1](FH_DI_Data_Ptr);    // Call the related function

				if (FH_DI_Data == 1)    // If the Status is 1, store 1 in the specific bit position in fH_DI_MULTIData
				{
					*(fH_DI_MULTIData + DI_GetStatusMULTI_StatusMaskByteCounter) = *(fH_DI_MULTIData + DI_GetStatusMULTI_StatusMaskByteCounter) |
							                                                       (0x80 >> DI_GetStatusMULTI_StatusMaskBitCounter);

				}
				else    // If the Status is 0, store 0 in the specific bit position in fH_DI_MULTIData
				{
					*(fH_DI_MULTIData + DI_GetStatusMULTI_StatusMaskByteCounter) = *(fH_DI_MULTIData + DI_GetStatusMULTI_StatusMaskByteCounter) &
							                                                       ~ (0x80 >> DI_GetStatusMULTI_StatusMaskBitCounter);
				}
			}
			else
			{
			}
		}
		DI_GetStatusMULTI_StatusMaskBitCounter++;    // Increase the DI_GetStatusMULTI_StatusMaskBitCounter
		if (DI_GetStatusMULTI_StatusMaskBitCounter == 8)    // If the whole bits of the byte are already processed
		{
			DI_GetStatusMULTI_StatusMaskBitCounter = 0;    // Reset DI_GetStatusMULTI_StatusMaskBitCounter
			DI_GetStatusMULTI_StatusMaskByteCounter++;    // Increase DI_GetStatusMULTI_StatusMaskByteCounter
		}
	}

	return fh_ErrorInfo;
}

#endif
