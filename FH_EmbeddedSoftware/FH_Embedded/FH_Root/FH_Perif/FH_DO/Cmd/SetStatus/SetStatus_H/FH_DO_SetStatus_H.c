/**
  * @file
  * @brief
  *       <b>File Map:</b>\n
  *       <b>FH_Root</b>, Section <b>FH_Perif</b>, <b>FH_DO</b> (Digital Output), <b>Cmd</b> (Command), <b>SetStatus</b>, <b>SetStatus_H</b> (SetStatus Health)\n
  *       Functions in this file, verify the health of the different message frames related to <b>DO</b> (Digital Output)
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
#include "../../../../../../../FH_Embedded/FH_Root/FH_Perif/FH_DO/Cmd/SetStatus/SetStatus_H/FH_DO_SetStatus_H.h"

#include "../../../../../../../FH_Embedded/FH_Root/FH_General/FH_GeneralFunctions/FH_GeneralFunctions.h"
#include "../../../../../../../FH_Embedded/FH_Setup/FH_DeviceAddress/FH_DeviceAddress.h"

#if FH_DO_MaxPeripheralNumber > 0    // It is configurable in FH_DevicePeripherals.h

/**
 * @brief This function verifies the health of <b>FH_DO_Commands_SetStatus</b> command
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
 * @return FH_ErrorInfo is returned
 *

*/
FH_ErrorInfo FH_DO_SetStatus_H(FH_RFCommunication_Message* fh_RFCommunication_Message)
{
	FH_ErrorInfo fh_ErrorInfo;    // Error Information
	FH_ResetErrorInfo(&fh_ErrorInfo);    // Reset Error Information to default

	uint8_t FH_MessageDataLength;    // It temporarily stores the DataLength in the message frame
	uint8_t FH_PeripheralNumber;    // It temporarily stores the PeripheralNumber (Data[0]) in the message frame
	uint8_t FH_Status;    // It temporarily stores the Status (Data[1]) in the message frame

	// Verifying the minimum possible length in the message frame
	FH_MessageDataLength =  fh_RFCommunication_Message -> DataLength;
	if (FH_MessageDataLength < FH_DO_MinCommandSize_SetStatus)    // If the length is less than expected value
	{
		fh_ErrorInfo.error_code = FH_ERROR_MessageFrame;    // There is message frame error
		return fh_ErrorInfo;
	}

	// Verifying the possible PeripheralNumber in the message frame
	FH_PeripheralNumber = fh_RFCommunication_Message -> Data[0];
	if (FH_PeripheralNumber == 0 || FH_PeripheralNumber > FH_DO_MaxPeripheralNumber)    // If the PeripheralNumber is not within the expected value
	{
		fh_ErrorInfo.error_code = FH_ERROR_MessageFrame;    // There is message frame error
		return fh_ErrorInfo;
	}

    // Verifying the possible Status in the message frame
	FH_Status = fh_RFCommunication_Message -> Data[1];
	if (FH_Status != 0 && FH_Status != 1)    // If the Status is not within the expected value
	{
		fh_ErrorInfo.error_code = FH_ERROR_MessageFrame;    // There is message frame error
		return fh_ErrorInfo;
	}

	fh_ErrorInfo.error_code = FH_ERROR_OK;    // There is no error
	return fh_ErrorInfo;
}

/**
 * @brief This function verifies the health of <b>FH_DO_Commands_SetStatusMULTI</b> command
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

	FF    FF    FF    FF    FF    FF    FF    FF => Example data as the first 8 parameters of the Data in the message frame utilized as mask (In this example it means all 64 digital outputs shall set status
	01    02    03    04    05    06    07    08 => Example data as the second 8 parameters of the Data in the message frame as data value of 1 or 0, corresponding to the first 8 bytes)
    DeviceAddress_01 => It shall be equal to the address of the device: FH_RFCommunication_DeviceAddress
    Function_DO => It is the function in the message frame
    DO_Commands_SetStatusMULTI => It is the command of the function in the message frame
  @endverbatim
 *
 * @return FH_ErrorInfo is returned
 *

*/
FH_ErrorInfo FH_DO_SetStatusMULTI_H(FH_RFCommunication_Message* fh_RFCommunication_Message)
{
	FH_ErrorInfo fh_ErrorInfo;    // Error Information
	FH_ResetErrorInfo(&fh_ErrorInfo);    // Reset Error Information to default

	uint8_t FH_MessageDataLength;    // It temporarily stores the DataLength in the message frame

	// Verifying the minimum possible length in the message frame
	FH_MessageDataLength =	fh_RFCommunication_Message -> DataLength;
	if (FH_MessageDataLength < FH_DO_MinCommandSize_SetStatusMULTI)    // If the length is less than expected value
	{
		fh_ErrorInfo.error_code = FH_ERROR_MessageFrame;    // There is message frame error
		return fh_ErrorInfo;
	}

	fh_ErrorInfo.error_code = FH_ERROR_OK;    // There is no error
	return fh_ErrorInfo;
}

#endif
