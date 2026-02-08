/**
  * @file
  * @brief
  *       <b>File Map:</b>\n
  *       <b>FH_Functions</b>, Section <b>FH_DI</b> (Digital Input), Peripheral <b>FH_DI50</b> (Digital Input 50)\n
  *       (The <b>DI50 (Digital Input 50)</b> could be any interested Digital Input of the micro-controller on which <b>FH</b> source code is ported)\n
  *
  * @note To have a clean code, <b>FH</b> user should have the implementation of the initialization and read functions of the <b>Digital Input 50</b> in a separate c file\n
  *       Then <b>FH</b> user should include the header file <b>(.h)</b> of the related source file <b>(.c)</b> here\n
  *       This header file shall include the following items:\n
  *       The declaration of the initialization function of the <b>Digital Input 50</b>\n
  *       The declaration of the read function of the <b>Digital Input 50</b>
  *
  * @attention There are a total number of <b>3 attentions</b> (<b>FH</b> user defined code) in this file where <b>FH</b> user shall insert some code\n
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
#include "../../../../FH_Embedded/FH_Functions/FH_DI/FH_DI50/FH_DI50.h"

#ifdef FH_DI50    // It is configurable in FH_DI_Configs.h

#if FH_DI_MaxPeripheralNumber > 0    // It is configurable in FH_DevicePeripherals.h

/* Secondary Includes ------------------------------------------------------------------*/
#include "../../../../FH_Embedded/FH_Root/FH_Perif/FH_DI/FH_DI.h"
#include "../../../../FH_Embedded/FH_Root/FH_General/FH_GlobalTimerCount/FH_GlobalTimerCount.h"
#include "../../../../FH_Embedded/FH_Root/FH_General/FH_GeneralFunctions/FH_GeneralFunctions.h"

/**
 * @brief This function initializes the <b>Digital Input 50</b>\n
 *        The <b>Digital Input 50</b> could be any interested Digital Input of the micro-controller on which <b>FH</b> source code is ported\n
 *        <b>FH</b> user should call the initialization function of the interested Digital Input here
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
    @{MessageData} =    Create List    ${DI50}
    &{Message}     =    Create Dictionary    DeviceAddress=${DeviceAddress_01}    Function=${Function_DI}    Command=${DI_Commands_Init}    Data=@{MessageData}
    ${Result}    SendMessage    &{Message}

    Comments:

    DI50 => It indicates the Digital Input 50
    DeviceAddress_01 => It shall be equal to the address of the device: FH_RFCommunication_DeviceAddress
    Function_DI => It is the function in the message frame
    DI_Commands_Init => It is the command of the function in the message frame
  @endverbatim
 *
 *
 * @warning
 * To be able to read the <b>Digital Input 50</b> of the micro-controller on which <b>FH</b> source code is ported, this function shall be invoked once by <b>RobotFramework</b> firstly\n
 * In other words, before invoking <b>FH_DI_GetStatus_DI50</b> function from <b>RobotFramework</b>, this function shall be invoked in order to initialize the Digital Input
 *

*/
FH_ErrorInfo FH_DI_Init_DI50()
{
	FH_ErrorInfo fh_ErrorInfo;    // Error Information
	FH_ResetErrorInfo(&fh_ErrorInfo);    // Reset Error Information to default

	// Attention 2: FH user defined code (call the initialization function of the Digital Input 50 here)
	
	// YourInitializationFunctionName ();

	//

	return fh_ErrorInfo;
}

/**
 * @brief This function reads the <b>Digital Input 50</b>\n
 *        The <b>Digital Input 50</b> could be any interested Digital Input of the micro-controller on which <b>FH</b> source code is ported\n
 *        <b>FH</b> user should call the read function of the interested Digital Input here
 *
 * @param  Data
 *         If the read data of the <b>Digital Input 50</b> is 1, *Data will be set to 1\n
 *         If the read data of the <b>Digital Input 50</b> is 0, *Data will be set to 0
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
    @{MessageData} =    Create List    ${DI50}
    &{Message}     =    Create Dictionary    DeviceAddress=${DeviceAddress_01}    Function=${Function_DI}    Command=${DI_Commands_GetStatus}    Data=@{MessageData}
    ${Result}    SendMessage    &{Message}

    Comments:

    DI50 => It indicates the Digital Input 50
    DeviceAddress_01 => It shall be equal to the address of the device: FH_RFCommunication_DeviceAddress
    Function_DI => It is the function in the message frame
    DI_Commands_GetStatus => It is the command of the function in the message frame
  @endverbatim
 *
 *
 * @warning
 * To be able to read the <b>Digital Input 50</b> of the micro-controller on which <b>FH</b> source code is ported, the <b>FH_DI_Init_DI50</b> function shall be invoked once by <b>RobotFramework</b> firstly\n
 * In other words, before invoking <b>FH_DI_GetStatus_DI50</b> function from <b>RobotFramework</b>, <b>FH_DI_Init_DI50</b> function shall be invoked in order to initialize the Digital Input
 *

*/

FH_ErrorInfo FH_DI_GetStatus_DI50(uint8_t* Data)
{
	FH_ErrorInfo fh_ErrorInfo;    // Error Information
	FH_ResetErrorInfo(&fh_ErrorInfo);    // Reset Error Information to default
	uint8_t readData = 0;    // Read data of the Digital Input 50
	
	// Attention 3: FH user defined code (call the read function the Digital Input 50 here)

	// readData = YourReadFunctionName();

	//

	if (readData == 1)
	{
		*Data = 1;
	}
	else
	{
	    *Data = 0;
	}
	
	return fh_ErrorInfo;
}

#endif

#endif
