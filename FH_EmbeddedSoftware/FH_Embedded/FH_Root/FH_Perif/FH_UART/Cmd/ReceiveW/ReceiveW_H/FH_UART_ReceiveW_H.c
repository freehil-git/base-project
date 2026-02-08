/**
  * @file
  * @brief
  *       <b>File Map:</b>\n
  *       <b>FH_Root</b>, Section <b>FH_Perif</b>, <b>FH_UART</b>, <b>Cmd</b> (Command), <b>ReceiveW</b>, <b>ReceiveW_H</b> (ReceiveW Health)\n
  *       Functions in this file, verify the health of the different message frames related to <b>UART</b>
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
#include "../../../../../../../FH_Embedded/FH_Root/FH_Perif/FH_UART/Cmd/ReceiveW/ReceiveW_H/FH_UART_ReceiveW_H.h"

#include "../../../../../../../FH_Embedded/FH_Root/FH_General/FH_GeneralFunctions/FH_GeneralFunctions.h"
#include "../../../../../../../FH_Embedded/FH_Setup/FH_DeviceAddress/FH_DeviceAddress.h"

#if FH_UART_MaxPeripheralNumber > 0    // It is configurable in FH_DevicePeripherals.h

/**
 * @brief This function verifies the health of <b>FH_UART_Commands_ReceiveW</b> command
 *
 * @param  fh_RFCommunication_Message
 *         The message frame set by <b>RobotFramework</b>
 *
 * @verbatim
    ==============================================================================
                          ##### RobotFramework Example #####
    ==============================================================================
    @{MessageData} =    Create List    ${UART01}    05    00    00    0B    B8
    &{Message}     =    Create Dictionary    DeviceAddress=${DeviceAddress_01}    Function=${Function_UART}    Command=${UART_Commands_ReceiveW}    Data=@{MessageData}
    ${Result}    SendMessage    &{Message}

    Comments:

    UART01 => It indicates the UART 01
    05 => The expected number of bytes of data to be received through the <b>ISR</b> (Interrupt Service Routine) receive buffer (FH_UART01_ReceiveBuf) of the <b>UART 01</b>
    00    00    0B    B8 => Example data (0x00000BB8 mili-seconds) as timeout of receiving the expected number of bytes
                            FH_GlobalTimeCounter which is a global variable is utilized to calculate the timeout
                            FH_GlobalTimeCounter shall be incremented every <b>1 mili-second</b> in an interested timer <b>ISR</b> (Interrupt Service Routine) by <b>FH</b> user
                            For this to happen, <b>FH_GlobalTimerCount.h</b> shall be included in the interested timer <b>ISR</b> (Interrupt Service Routine) file
                            If the expected number of bytes are received, the function does not wait anymore for the remaining time of the timeout
    DeviceAddress_01 => It shall be equal to the address of the device: FH_RFCommunication_DeviceAddress
    Function_UART => It is the function in the message frame
    UART_Commands_ReceiveW => It is the command of the function in the message frame
  @endverbatim
 *
 * @return FH_ErrorInfo is returned
 *

*/
FH_ErrorInfo FH_UART_ReceiveW_H(FH_RFCommunication_Message* fh_RFCommunication_Message)
{
	FH_ErrorInfo fh_ErrorInfo;    // Error Information
	FH_ResetErrorInfo(&fh_ErrorInfo);    // Reset Error Information to default

	uint8_t FH_MessageDataLength;    // It temporarily stores the DataLength in the message frame
	uint8_t FH_PeripheralNumber;    // It temporarily stores the PeripheralNumber (Data[0]) in the message frame
	uint32_t FH_MaxTimerCount;    // It temporarily stores the MaxTimerCount (Data[2]-Data[5]) in the message frame

	// Verifying the minimum possible length in the message frame
	FH_MessageDataLength =  fh_RFCommunication_Message -> DataLength;
	if (FH_MessageDataLength < FH_UART_MinCommandSize_ReceiveW)    // If the length is less than expected value
	{
		fh_ErrorInfo.error_code = FH_ERROR_MessageFrame;    // There is message frame error
		return fh_ErrorInfo;
	}

	// Verifying the possible PeripheralNumber in the message frame
	FH_PeripheralNumber = fh_RFCommunication_Message -> Data[UART_ReceiveW_PeripheralNumber] ;
	if (FH_PeripheralNumber == 0 || FH_PeripheralNumber > FH_UART_MaxPeripheralNumber)    // If the PeripheralNumber is not within the expected value
	{
		fh_ErrorInfo.error_code = FH_ERROR_MessageFrame;    // There is message frame error
		return fh_ErrorInfo;
	}

	// Verifying the possible MaxTimerCount in the message frame
	FH_MaxTimerCount = FH_ConvertUint8ToUint32(&fh_RFCommunication_Message -> Data[UART_ReceiveW_MaxTimerCount]);
	if (FH_MaxTimerCount == 0)
	{
		fh_ErrorInfo.error_code = FH_ERROR_MessageFrame;    // There is message frame error
		return fh_ErrorInfo;
	}

	fh_ErrorInfo.error_code = FH_ERROR_OK;    // There is no error
	return fh_ErrorInfo;
}

#endif
