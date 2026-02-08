/**
  * @file
  * @brief
  *       <b>File Map:</b>\n
  *       <b>FH_Functions</b>, Section <b>FH_DO</b> (Digital Output), Peripheral <b>FH_DO21</b> (Digital Output 21)\n
  *       (The <b>DO21 (Digital Output 21)</b> could be any interested digital output of the micro-controller on which <b>FH</b> source code is ported)\n
  *
  * @note To have a clean code, <b>FH</b> user should have the implementation of the initialization, set and reset functions of the <b>Digital Output 21</b> in a separate c file\n
  *       Then <b>FH</b> user should include the header file <b>(.h)</b> of the related source file <b>(.c)</b> here\n
  *       This header file shall include the following items:\n
  *       The declaration of the initialization function of the <b>Digital Output 21</b>\n
  *       The declaration of the set and reset functions of the <b>Digital Output 21</b>
  *
  * @attention There are a total number of <b>4 attentions</b> (<b>FH</b> user defined code) in this file where <b>FH</b> user shall insert some code\n
  *            Other parts could be left intact
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
// Attention 1: FH user defined code (include the mentioned header file here)

//
#include "../../../../FH_Embedded/FH_Functions/FH_DO/FH_DO21/FH_DO21.h"

#ifdef FH_DO21    // It is configurable in FH_DO_Configs.h

#if FH_DO_MaxPeripheralNumber > 0    // It is configurable in FH_DevicePeripherals.h

/* Secondary Includes ------------------------------------------------------------------*/
#include "../../../../FH_Embedded/FH_Root/FH_Perif/FH_DO/FH_DO.h"
#include "../../../../FH_Embedded/FH_Root/FH_General/FH_GlobalTimerCount/FH_GlobalTimerCount.h"
#include "../../../../FH_Embedded/FH_Root/FH_General/FH_GeneralFunctions/FH_GeneralFunctions.h"

/**
 * @brief This function initializes the <b>Digital Output 21</b>\n
 *        The <b>Digital Output 21</b> could be any interested digital output of the micro-controller on which <b>FH</b> source code is ported\n
 *        <b>FH</b> user should call the initialization function of the interested digital output here
 *
 * @param  None
 * @return FH_ErrorInfo is returned
 *
 * @note
 * To have a clean code, just include the related header file\n
 * Then just call the function here
 *
 * @verbatim
    ==============================================================================
                          ##### RobotFramework Example #####
    ==============================================================================
    @{MessageData} =    Create List    ${DO21}
    &{Message}     =    Create Dictionary    DeviceAddress=${DeviceAddress_01}    Function=${Function_DO}    Command=${DO_Commands_Init}    Data=@{MessageData}
    ${Result}    SendMessage    &{Message}

    Comments:

    DO21 => It indicates the Digital Output 21
    DeviceAddress_01 => It shall be equal to the address of the device: FH_RFCommunication_DeviceAddress
    Function_DO => It is the function in the message frame
    DO_Commands_Init => It is the command of the function in the message frame
  @endverbatim
 *
 *
 * @warning
 * To be able to set or reset the <b>Digital Output 21</b> of the micro-controller on which <b>FH</b> source code is ported, this function shall be invoked once by <b>RobotFramework</b> firstly\n
 * In other words, before invoking <b>FH_DO_SetStatus_DO21</b> function from <b>RobotFramework</b>, this function shall be invoked in order to initialize the digital output
 *

*/
FH_ErrorInfo FH_DO_Init_DO21()
{
	FH_ErrorInfo fh_ErrorInfo;    // Error Information
	FH_ResetErrorInfo(&fh_ErrorInfo);    // Reset Error Information to default

	// Attention 2: FH user defined code (call the initialization function of the Digital Output 21 here)

	// YourInitializationFunctionName ();

	//

	return fh_ErrorInfo;
}

/**
 * @brief This function sets or resets the <b>Digital Output 21</b>\n
 *        The <b>Digital Output 21</b> could be any interested digital output of the micro-controller on which <b>FH</b> source code is ported\n
 *        <b>FH</b> user should call the set and reset functions of the interested digital output here
 *
 * @param  Status
 *         If Status is 1, the set function of the <b>Digital Output 21</b> shall be called\n
 *         If Status is 0, the reset function of the <b>Digital Output 21</b> shall be called
 * @return FH_ErrorInfo is returned
 *
 * @note
 * To have a clean code, just include the related header file\n
 * Then just call the function here
 *
 * @verbatim
    ==============================================================================
                          ##### RobotFramework Example #####
    ==============================================================================
    @{MessageData} =    Create List    ${DO21}    ${DO_Set}
    &{Message}     =    Create Dictionary    DeviceAddress=${DeviceAddress_01}    Function=${Function_DO}    Command=${DO_Commands_SetStatus}    Data=@{MessageData}
    ${Result}    SendMessage    &{Message}

    Comments:

    DO21 => It indicates the Digital Output 21
    DO_Set => It indicates the Digital Output 21 shall be Set (DO_Reset indicates the Digital Output 21 shall be Reset)
    DeviceAddress_01 => It shall be equal to the address of the device: FH_RFCommunication_DeviceAddress
    Function_DO => It is the function in the message frame
    DO_Commands_SetStatus => It is the command of the function in the message frame
  @endverbatim
 *
 *
 * @warning
 * To be able to set or reset the <b>Digital Output 21</b> of the micro-controller on which <b>FH</b> source code is ported, the <b>FH_DO_Init_DO21</b> function shall be invoked once by <b>RobotFramework</b> firstly\n
 * In other words, before invoking <b>FH_DO_SetStatus_DO21</b> function from <b>RobotFramework</b>, <b>FH_DO_Init_DO21</b> function shall be invoked in order to initialize the digital output
 *

*/
FH_ErrorInfo FH_DO_SetStatus_DO21(uint8_t Status)
{
	FH_ErrorInfo fh_ErrorInfo;    // Error Information
	FH_ResetErrorInfo(&fh_ErrorInfo);    // Reset Error Information to default
	
	if (Status == 1)    // If Status is 1, the set function of the Digital Output 21 shall be called
	{
		// Attention 3: FH user defined code (call the set function the Digital Output 21 here)

		// YourSetFunctionName();

		//
	}
	else if (Status == 0)    // If Status is 0, the reset function of the Digital Output 21 shall be called
	{
		// Attention 4: FH user defined code (call the reset function the Digital Output 21 here)

		// YourResetFunctionName();

		//
	}
	else
	{
		fh_ErrorInfo.error_code = FH_ERROR_MessageFrame;
	}

	return fh_ErrorInfo;
}
	
#endif

#endif
