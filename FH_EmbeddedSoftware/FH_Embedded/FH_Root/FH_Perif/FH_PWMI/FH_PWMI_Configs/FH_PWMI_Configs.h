/**
  * @file
  * @brief
  *       <b>File Map:</b>\n
  *       <b>FH_Root</b>, Section <b>FH_Perif</b>, <b>FH_PWMI</b> (PWM Input), <b>FH_PWMI_Configs</b>\n
  *       In this file, different configurations of <b>FH_PWMI</b> (PWM Input) could be set
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
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef FH_PWMI_Configs_H
#define FH_PWMI_Configs_H

/* Includes ------------------------------------------------------------------*/
#include "../../../../../FH_Embedded/FH_Setup/FH_DevicePeripherals/FH_DevicePeripherals.h"
#include "../../../../../FH_Embedded/FH_Root/FH_General/FH_ErrorInfo/FH_ErrorInfo.h"
#include "../../../../../FH_Embedded/FH_Setup/FH_RFCommunication/FH_RFCommunication_GlobalVariables.h"

/*!
  <b>FH_PWMI01 - FH_PWMI64</b> shall be defined here to be utilized in different parts of the <b>FH</b> source code\n
  <b>FH_PWMI_MaxPeripheralNumber</b> is the maximum number of the <b>FH_PWMI</b> (PWM Input)
*/

#if FH_PWMI_MaxPeripheralNumber > 0
#define FH_PWMI01
#endif
#if FH_PWMI_MaxPeripheralNumber > 1
#define FH_PWMI02
#endif
#if FH_PWMI_MaxPeripheralNumber > 2
#define FH_PWMI03
#endif
#if FH_PWMI_MaxPeripheralNumber > 3
#define FH_PWMI04
#endif
#if FH_PWMI_MaxPeripheralNumber > 4
#define FH_PWMI05
#endif
#if FH_PWMI_MaxPeripheralNumber > 5
#define FH_PWMI06
#endif
#if FH_PWMI_MaxPeripheralNumber > 6
#define FH_PWMI07
#endif
#if FH_PWMI_MaxPeripheralNumber > 7
#define FH_PWMI08
#endif
#if FH_PWMI_MaxPeripheralNumber > 8
#define FH_PWMI09
#endif
#if FH_PWMI_MaxPeripheralNumber > 9
#define FH_PWMI10
#endif
#if FH_PWMI_MaxPeripheralNumber > 10
#define FH_PWMI11
#endif
#if FH_PWMI_MaxPeripheralNumber > 11
#define FH_PWMI12
#endif
#if FH_PWMI_MaxPeripheralNumber > 12
#define FH_PWMI13
#endif
#if FH_PWMI_MaxPeripheralNumber > 13
#define FH_PWMI14
#endif
#if FH_PWMI_MaxPeripheralNumber > 14
#define FH_PWMI15
#endif
#if FH_PWMI_MaxPeripheralNumber > 15
#define FH_PWMI16
#endif
#if FH_PWMI_MaxPeripheralNumber > 16
#define FH_PWMI17
#endif
#if FH_PWMI_MaxPeripheralNumber > 17
#define FH_PWMI18
#endif
#if FH_PWMI_MaxPeripheralNumber > 18
#define FH_PWMI19
#endif
#if FH_PWMI_MaxPeripheralNumber > 19
#define FH_PWMI20
#endif
#if FH_PWMI_MaxPeripheralNumber > 20
#define FH_PWMI21
#endif
#if FH_PWMI_MaxPeripheralNumber > 21
#define FH_PWMI22
#endif
#if FH_PWMI_MaxPeripheralNumber > 22
#define FH_PWMI23
#endif
#if FH_PWMI_MaxPeripheralNumber > 23
#define FH_PWMI24
#endif
#if FH_PWMI_MaxPeripheralNumber > 24
#define FH_PWMI25
#endif
#if FH_PWMI_MaxPeripheralNumber > 25
#define FH_PWMI26
#endif
#if FH_PWMI_MaxPeripheralNumber > 26
#define FH_PWMI27
#endif
#if FH_PWMI_MaxPeripheralNumber > 27
#define FH_PWMI28
#endif
#if FH_PWMI_MaxPeripheralNumber > 28
#define FH_PWMI29
#endif
#if FH_PWMI_MaxPeripheralNumber > 29
#define FH_PWMI30
#endif
#if FH_PWMI_MaxPeripheralNumber > 30
#define FH_PWMI31
#endif
#if FH_PWMI_MaxPeripheralNumber > 31
#define FH_PWMI32
#endif
#if FH_PWMI_MaxPeripheralNumber > 32
#define FH_PWMI33
#endif
#if FH_PWMI_MaxPeripheralNumber > 33
#define FH_PWMI34
#endif
#if FH_PWMI_MaxPeripheralNumber > 34
#define FH_PWMI35
#endif
#if FH_PWMI_MaxPeripheralNumber > 35
#define FH_PWMI36
#endif
#if FH_PWMI_MaxPeripheralNumber > 36
#define FH_PWMI37
#endif
#if FH_PWMI_MaxPeripheralNumber > 37
#define FH_PWMI38
#endif
#if FH_PWMI_MaxPeripheralNumber > 38
#define FH_PWMI39
#endif
#if FH_PWMI_MaxPeripheralNumber > 39
#define FH_PWMI40
#endif
#if FH_PWMI_MaxPeripheralNumber > 40
#define FH_PWMI41
#endif
#if FH_PWMI_MaxPeripheralNumber > 41
#define FH_PWMI42
#endif
#if FH_PWMI_MaxPeripheralNumber > 42
#define FH_PWMI43
#endif
#if FH_PWMI_MaxPeripheralNumber > 43
#define FH_PWMI44
#endif
#if FH_PWMI_MaxPeripheralNumber > 44
#define FH_PWMI45
#endif
#if FH_PWMI_MaxPeripheralNumber > 45
#define FH_PWMI46
#endif
#if FH_PWMI_MaxPeripheralNumber > 46
#define FH_PWMI47
#endif
#if FH_PWMI_MaxPeripheralNumber > 47
#define FH_PWMI48
#endif
#if FH_PWMI_MaxPeripheralNumber > 48
#define FH_PWMI49
#endif
#if FH_PWMI_MaxPeripheralNumber > 49
#define FH_PWMI50
#endif
#if FH_PWMI_MaxPeripheralNumber > 50
#define FH_PWMI51
#endif
#if FH_PWMI_MaxPeripheralNumber > 51
#define FH_PWMI52
#endif
#if FH_PWMI_MaxPeripheralNumber > 52
#define FH_PWMI53
#endif
#if FH_PWMI_MaxPeripheralNumber > 53
#define FH_PWMI54
#endif
#if FH_PWMI_MaxPeripheralNumber > 54
#define FH_PWMI55
#endif
#if FH_PWMI_MaxPeripheralNumber > 55
#define FH_PWMI56
#endif
#if FH_PWMI_MaxPeripheralNumber > 56
#define FH_PWMI57
#endif
#if FH_PWMI_MaxPeripheralNumber > 57
#define FH_PWMI58
#endif
#if FH_PWMI_MaxPeripheralNumber > 58
#define FH_PWMI59
#endif
#if FH_PWMI_MaxPeripheralNumber > 59
#define FH_PWMI60
#endif
#if FH_PWMI_MaxPeripheralNumber > 60
#define FH_PWMI61
#endif
#if FH_PWMI_MaxPeripheralNumber > 61
#define FH_PWMI62
#endif
#if FH_PWMI_MaxPeripheralNumber > 62
#define FH_PWMI63
#endif
#if FH_PWMI_MaxPeripheralNumber > 63
#define FH_PWMI64
#endif

#if FH_PWMI_MaxPeripheralNumber > 0    // If at least one <b>FH_PWMI</b> (PWM Input) is defined

/*!
  <b>FH_PWMI_Init_FuncPtrModel</b> Function pointer definition
*/
typedef FH_ErrorInfo (*FH_PWMI_Init_FuncPtrModel)                (FH_RFCommunication_Message* fh_RFCommunication_Message);

/*!
<b>FH_PWMI_GetStatus_FuncPtrModel</b> Function pointer definition
*/
typedef FH_ErrorInfo (*FH_PWMI_GetStatus_FuncPtrModel)                (FH_RFCommunication_Message* fh_RFCommunication_Message, uint32_t* FH_PWMI_Frequency, uint8_t* FH_PWMI_DutyCycle);

/*!
  Different commands for <b>PWMI</b> (PWM Input) Function
*/
enum FH_PWMI_Commands
{
	FH_PWMI_Commands_Init         = 0,
	FH_PWMI_Commands_GetStatus    = 1,
};

/*!
  Minimum size of the <b>Data</b> part in the message frame (<b>FH_RFCommunication_Message</b>) for the <b>Init</b> command of <b>PWMI</b> Function, are defined here
*/
#define FH_PWMI_MinCommandSize_Init        		      1

/*!
  Minimum size of the <b>Data</b> part in the message frame (<b>FH_RFCommunication_Message</b>) for the <b>GetStatus</b> command of <b>PWMI</b> Function, are defined here
*/
#define FH_PWMI_MinCommandSize_GetStatus      		  1

/*!
  Different elements of the Data part in the message frame (<b>FH_RFCommunication_Message</b>) for the Init command of <b>PWMI</b> Function, are defined here
*/
enum FH_PWMI_Commandelements_Init
{
	PWMI_Init_PeripheralNumber   = 0,
};

/*!
  Different elements of the Data part in the message frame (<b>FH_RFCommunication_Message</b>) for the GetStatus command of <b>PWMI</b> Function, are defined here
*/
enum FH_PWMI_Commandelements_GetStatus
{
	PWMI_GetStatus_PeripheralNumber   = 0,
};

#endif

#endif
