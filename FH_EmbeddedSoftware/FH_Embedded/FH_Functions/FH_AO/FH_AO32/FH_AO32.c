/**
  * @file
  * @brief
  *       <b>File Map:</b>\n
  *       <b>FH_Functions</b>, Section <b>FH_AO</b> (Analog Output), Peripheral <b>FH_AO32</b> (Analog Output 32)\n
  *       (The <b>AO32 (Analog Output 32)</b> could be any interested Analog Output of the micro-controller on which <b>FH</b> source code is ported)\n
  *
  * @note To have a clean code, <b>FH</b> user should have the implementation of the initialization and set function of the <b>Analog Output 32</b> in a separate c file\n
  *       Then <b>FH</b> user should include the header file <b>(.h)</b> of the related source file <b>(.c)</b> here\n
  *       This header file shall include the following items:\n
  *       The declaration of the initialization function of the <b>Analog Output 32</b>\n
  *       The declaration of the set function of the <b>Analog Output 32</b>
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
#include "../../../../FH_Embedded/FH_Functions/FH_AO/FH_AO32/FH_AO32.h"

#ifdef FH_AO32    // It is configurable in FH_AO_Configs.h

#if FH_AO_MaxPeripheralNumber > 0    // It is configurable in FH_DevicePeripherals.h

/* Secondary Includes ------------------------------------------------------------------*/
#include "../../../../FH_Embedded/FH_Root/FH_Perif/FH_AO/FH_AO.h"
#include "../../../../FH_Embedded/FH_Root/FH_General/FH_GlobalTimerCount/FH_GlobalTimerCount.h"
#include "../../../../FH_Embedded/FH_Root/FH_General/FH_GeneralFunctions/FH_GeneralFunctions.h"

/**
 * @brief This function initializes the <b>Analog Output 32</b>\n
 *        The <b>Analog Output 32</b> could be any interested Analog Output of the micro-controller on which <b>FH</b> source code is ported\n
 *        <b>FH</b> user should call the initialization function of the interested Analog Output here
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
    @{MessageData} =    Create List    ${AO32}
    &{Message}     =    Create Dictionary    DeviceAddress=${DeviceAddress_01}    Function=${Function_AO}    Command=${AO_Commands_Init}    Data=@{MessageData}
    ${Result}    SendMessage    &{Message}

    Comments:

    AO32 => It indicates the Analog Output 32
    DeviceAddress_01 => It shall be equal to the address of the device: FH_RFCommunication_DeviceAddress
    Function_AO => It is the function in the message frame
    AO_Commands_Init => It is the command of the function in the message frame
  @endverbatim
 *
 *
 * @warning
 * To be able to set or reset the <b>Analog Output 32</b> of the micro-controller on which <b>FH</b> source code is ported, this function shall be invoked once by <b>RobotFramework</b> firstly\n
 * In other words, before invoking <b>FH_AO_SetStatus_AO32</b> function from <b>RobotFramework</b>, this function shall be invoked in order to initialize the Analog Output
 *

*/
FH_ErrorInfo FH_AO_Init_AO32(FH_RFCommunication_Message* fh_RFCommunication_Message)
{
	FH_ErrorInfo fh_ErrorInfo;    // Error Information
	FH_ResetErrorInfo(&fh_ErrorInfo);    // Reset Error Information to default

	// Attention 2: FH user defined code (call the initialization function of the Analog Output 32 here)

	// YourInitializationFunctionName ();

	//

	return fh_ErrorInfo;
}

/**
 * @brief This function sets the <b>Analog Output 32</b>\n
 *        The <b>Analog Output 32</b> could be any interested Analog Output of the micro-controller on which <b>FH</b> source code is ported\n
 *        <b>FH</b> user should call the set function of the interested Analog Output here
 *
 * @param  fh_RFCommunication_Message
 *         The message frame set by <b>RobotFramework</b>
 *
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
    @{MessageData} =    Create List    ${AO32}    F1    C2    01    08
    &{Message}     =    Create Dictionary    DeviceAddress=${DeviceAddress_01}    Function=${Function_AO}    Command=${AO_Commands_SetStatus}    Data=@{MessageData}
    ${Result}    SendMessage    &{Message}

    Comments:

    AO32 => It indicates the Analog Output 32
    F1    C2    01    08 => Example data as analog value (0xF1C20108) to be set through the <b>Analog Output 32</b>\n
    DeviceAddress_01 => It shall be equal to the address of the device: FH_RFCommunication_DeviceAddress
    Function_AO => It is the function in the message frame
    AO_Commands_SetStatus => It is the command of the function in the message frame
  @endverbatim
 *
 *
 * @warning
 * To be able to set the <b>Analog Output 32</b> of the micro-controller on which <b>FH</b> source code is ported, the <b>FH_AO_Init_AO32</b> function shall be invoked once by <b>RobotFramework</b> firstly\n
 * In other words, before invoking <b>FH_AO_SetStatus_AO32</b> function from <b>RobotFramework</b>, <b>FH_AO_Init_AO32</b> function shall be invoked in order to initialize the Analog Output
 *

*/
FH_ErrorInfo FH_AO_SetStatus_AO32(FH_RFCommunication_Message* fh_RFCommunication_Message)
{
	FH_ErrorInfo fh_ErrorInfo;    // Error Information
	FH_ResetErrorInfo(&fh_ErrorInfo);    // Reset Error Information to default

	// Attention 3: FH user defined code (call the set function the Analog Output 32 here with fh_RFCommunication_Message -> Data[...] as argument)
	// Hint: The prototype of the set function should be something like YourSetFunctionName(uint32_t Data);

	// YourSetFunctionName (FH_ConvertUint8ToUint32(&fh_RFCommunication_Message -> Data[AO_SetStatus_StatusByte4]));    // One 4 bytes analog data out of four 1 byte data is sent as argument

	//

	return fh_ErrorInfo;
}
	
#endif

#endif
