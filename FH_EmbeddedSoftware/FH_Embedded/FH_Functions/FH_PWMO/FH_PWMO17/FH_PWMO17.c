/**
  * @file
  * @brief
  *       <b>File Map:</b>\n
  *       <b>FH_Functions</b>, Section <b>FH_PWMO</b> (PWM Output), Peripheral <b>FH_PWMO17</b> (PWM Output 17)\n
  *       (The <b>PWMO17 (PWM Output 17)</b> could be any interested PWM Output of the micro-controller on which <b>FH</b> source code is ported)\n
  *
  * @note To have a clean code, <b>FH</b> user should have the implementation of the initialization and set function of the <b>PWM Output 17</b> in a separate c file\n
  *       Then <b>FH</b> user should include the header file <b>(.h)</b> of the related source file <b>(.c)</b> here\n
  *       This header file shall include the following items:\n
  *       The declaration of the initialization function of the <b>PWM Output 17</b>\n
  *       The declaration of the set function of the <b>PWM Output 17</b>
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
#include "../../../../FH_Embedded/FH_Functions/FH_PWMO/FH_PWMO17/FH_PWMO17.h"

#ifdef FH_PWMO17    // It is configurable in FH_PWMO_Configs.h

#if FH_PWMO_MaxPeripheralNumber > 0    // It is configurable in FH_DevicePeripherals.h

/* Secondary Includes ------------------------------------------------------------------*/
#include "../../../../FH_Embedded/FH_Root/FH_Perif/FH_PWMO/FH_PWMO.h"
#include "../../../../FH_Embedded/FH_Root/FH_General/FH_GlobalTimerCount/FH_GlobalTimerCount.h"
#include "../../../../FH_Embedded/FH_Root/FH_General/FH_GeneralFunctions/FH_GeneralFunctions.h"

/**
 * @brief This function initializes the <b>PWM Output 17</b>\n
 *        The <b>PWM Output 17</b> could be any interested PWM Output of the micro-controller on which <b>FH</b> source code is ported\n
 *        <b>FH</b> user should call the initialization function of the interested PWM Output here
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
    @{MessageData} =    Create List    ${PWMO17}
    &{Message}     =    Create Dictionary    DeviceAddress=${DeviceAddress_01}    Function=${Function_PWMO}    Command=${PWMO_Commands_Init}    Data=@{MessageData}
    ${Result}    SendMessage    &{Message}

    Comments:

    PWMO17 => It indicates the PWM Output 17
    DeviceAddress_01 => It shall be equal to the address of the device: FH_RFCommunication_DeviceAddress
    Function_PWMO => It is the function in the message frame
    PWMO_Commands_Init => It is the command of the function in the message frame
  @endverbatim
 *
 *
 * @warning
 * To be able to set or reset the <b>PWM Output 17</b> of the micro-controller on which <b>FH</b> source code is ported, this function shall be invoked once by <b>RobotFramework</b> firstly\n
 * In other words, before invoking <b>FH_PWMO_SetStatus_PWMO17</b> function from <b>RobotFramework</b>, this function shall be invoked in order to initialize the PWM Output
 *

*/
FH_ErrorInfo FH_PWMO_Init_PWMO17(FH_RFCommunication_Message* fh_RFCommunication_Message)
{
	FH_ErrorInfo fh_ErrorInfo;    // Error Information
	FH_ResetErrorInfo(&fh_ErrorInfo);    // Reset Error Information to default

	// Attention 2: FH user defined code (call the initialization function of the PWM Output 17 here)

	// YourInitializationFunctionName ();

	//

	return fh_ErrorInfo;
}

/**
 * @brief This function sets the <b>PWM Output 17</b>\n
 *        The <b>PWM Output 17</b> could be any interested PWM Output of the micro-controller on which <b>FH</b> source code is ported\n
 *        <b>FH</b> user should call the set function of the interested PWM Output here
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
    @{MessageData} =    Create List    ${PWMO17}    00    00    00    F0    32
    &{Message}     =    Create Dictionary    DeviceAddress=${DeviceAddress_01}    Function=${Function_PWMO}    Command=${PWMO_Commands_SetStatus}    Data=@{MessageData}
    ${Result}    SendMessage    &{Message}

    Comments:

    PWMO17 => It indicates the PWM Output 17
    00    00    00    F0 => Example data as PWM frequency (0x000000F0) to be set through the <b>PWM Output 17</b>\n
    32 => Example data as PWM duty cycle (0x32 => as 50% duty cycle) to be set through the <b>PWM Output 17</b>\n
    DeviceAddress_01 => It shall be equal to the address of the device: FH_RFCommunication_DeviceAddress
    Function_PWMO => It is the function in the message frame
    PWMO_Commands_SetStatus => It is the command of the function in the message frame
  @endverbatim
 *
 *
 * @warning
 * To be able to set the <b>PWM Output 17</b> of the micro-controller on which <b>FH</b> source code is ported, the <b>FH_PWMO_Init_PWMO17</b> function shall be invoked once by <b>RobotFramework</b> firstly\n
 * In other words, before invoking <b>FH_PWMO_SetStatus_PWMO17</b> function from <b>RobotFramework</b>, <b>FH_PWMO_Init_PWMO17</b> function shall be invoked in order to initialize the PWM Output
 *

*/
FH_ErrorInfo FH_PWMO_SetStatus_PWMO17(FH_RFCommunication_Message* fh_RFCommunication_Message)
{
	FH_ErrorInfo fh_ErrorInfo;    // Error Information
	FH_ResetErrorInfo(&fh_ErrorInfo);    // Reset Error Information to default

	// Attention 3: FH user defined code (call the set function of the PWM Output 17 here with fh_RFCommunication_Message -> Data[...] as argument)
	// Hint: The prototype of the set function should be something like YourSetFunctionName(uint32_t Frequency, uint8_t DutyCycle);

	//YourSetFunctionName (FH_ConvertUint8ToUint32(&fh_RFCommunication_Message -> Data[PWMO_SetStatus_FrequencyByte4]),    // One 4 bytes PWM data out of four 1 byte data is sent as frequency argument
	//		                                     fh_RFCommunication_Message -> Data[PWMO_SetStatus_DutyCycle]);    // One byte as duty cycle argument

	//

	return fh_ErrorInfo;
}
	
#endif

#endif
