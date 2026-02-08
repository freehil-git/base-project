/**
  * @file
  * @brief
  *       <b>File Map:</b>\n
  *       <b>FH_Root</b>, Section <b>FH_Perif</b>, <b>FH_AI</b> (Analog Input), <b>Cmd</b> (Command), <b>GetStatus</b>, <b>GetStatus_C</b> (GetStatus Call)\n
  *       Functions in this file, Call the related function in <b>FH_Functions</b>, Section <b>FH_AI</b> (Analog Input) according to the first parameter of the Data in the message frame
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
#include "../../../../../../../FH_Embedded/FH_Root/FH_Perif/FH_AI/Cmd/GetStatus/GetStatus_C/FH_AI_GetStatus_C.h"

#include "../../../../../../../FH_Embedded/FH_Root/FH_General/FH_GeneralFunctions/FH_GeneralFunctions.h"
#include "../../../../../../../FH_Embedded/FH_Setup/FH_DeviceAddress/FH_DeviceAddress.h"

#if FH_AI_MaxPeripheralNumber > 0    // It is configurable in FH_DevicePeripherals.h

/**
 * @brief This function calls the related function in <b>FH_Functions</b>, Section <b>FH_AI</b> (Analog Input) according to the first parameter of the Data in the message frame
 *
 * @param  fh_RFCommunication_Message
 *         The message frame set by <b>RobotFramework</b>
 * @param  fH_AI_Data
 *         *fH_AI_Data will be set with the value of the related <b>Analog Input</b>
 * @param  fH_AI_GetStatus_FuncPtr
 *         The array of function pointers
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
FH_ErrorInfo FH_AI_GetStatus_C (FH_RFCommunication_Message* fh_RFCommunication_Message, uint32_t* fH_AI_Data, FH_AI_GetStatus_FuncPtrModel *fH_AI_GetStatus_FuncPtr)
{
	FH_ErrorInfo fh_ErrorInfo;    // Error Information
	FH_ResetErrorInfo(&fh_ErrorInfo);    // Reset Error Information to default

	for (uint8_t i = 1; i <= FH_AI_MaxPeripheralNumber; i++)    // Iteration through all defined  peripherals
	{
		if (i == fh_RFCommunication_Message -> Data[AI_GetStatus_PeripheralNumber])    // If the PeripheralNumber in the message frame is met
		{
			if (fH_AI_GetStatus_FuncPtr[i-1] != NULL_PTR)    // If the address of the function is truly assigned
			{
				fh_ErrorInfo = fH_AI_GetStatus_FuncPtr[i-1](fh_RFCommunication_Message, fH_AI_Data);    // Call the related function
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

#endif
