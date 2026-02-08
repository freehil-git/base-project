/**
  * @file
  * @brief
  *       <b>File Map:</b>\n
  *       <b>FH_Root</b>, Section <b>FH_Perif</b>, <b>FH_PWMO</b> (PWM Output), <b>FH_PWMO_Configs</b>\n
  *       In this file, different configurations of <b>FH_PWMO</b> (PWM Output) could be set
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
#ifndef FH_PWMO_Configs_H
#define FH_PWMO_Configs_H

/* Includes ------------------------------------------------------------------*/
#include "../../../../../FH_Embedded/FH_Setup/FH_DevicePeripherals/FH_DevicePeripherals.h"
#include "../../../../../FH_Embedded/FH_Root/FH_General/FH_ErrorInfo/FH_ErrorInfo.h"
#include "../../../../../FH_Embedded/FH_Setup/FH_RFCommunication/FH_RFCommunication_GlobalVariables.h"

/*!
  <b>FH_PWMO01 - FH_PWMO64</b> shall be defined here to be utilized in different parts of the <b>FH</b> source code\n
  <b>FH_PWMO_MaxPeripheralNumber</b> is the maximum number of the <b>FH_PWMO</b> (PWM Output)
*/

#if FH_PWMO_MaxPeripheralNumber > 0
#define FH_PWMO01
#endif
#if FH_PWMO_MaxPeripheralNumber > 1
#define FH_PWMO02
#endif
#if FH_PWMO_MaxPeripheralNumber > 2
#define FH_PWMO03
#endif
#if FH_PWMO_MaxPeripheralNumber > 3
#define FH_PWMO04
#endif
#if FH_PWMO_MaxPeripheralNumber > 4
#define FH_PWMO05
#endif
#if FH_PWMO_MaxPeripheralNumber > 5
#define FH_PWMO06
#endif
#if FH_PWMO_MaxPeripheralNumber > 6
#define FH_PWMO07
#endif
#if FH_PWMO_MaxPeripheralNumber > 7
#define FH_PWMO08
#endif
#if FH_PWMO_MaxPeripheralNumber > 8
#define FH_PWMO09
#endif
#if FH_PWMO_MaxPeripheralNumber > 9
#define FH_PWMO10
#endif
#if FH_PWMO_MaxPeripheralNumber > 10
#define FH_PWMO11
#endif
#if FH_PWMO_MaxPeripheralNumber > 11
#define FH_PWMO12
#endif
#if FH_PWMO_MaxPeripheralNumber > 12
#define FH_PWMO13
#endif
#if FH_PWMO_MaxPeripheralNumber > 13
#define FH_PWMO14
#endif
#if FH_PWMO_MaxPeripheralNumber > 14
#define FH_PWMO15
#endif
#if FH_PWMO_MaxPeripheralNumber > 15
#define FH_PWMO16
#endif
#if FH_PWMO_MaxPeripheralNumber > 16
#define FH_PWMO17
#endif
#if FH_PWMO_MaxPeripheralNumber > 17
#define FH_PWMO18
#endif
#if FH_PWMO_MaxPeripheralNumber > 18
#define FH_PWMO19
#endif
#if FH_PWMO_MaxPeripheralNumber > 19
#define FH_PWMO20
#endif
#if FH_PWMO_MaxPeripheralNumber > 20
#define FH_PWMO21
#endif
#if FH_PWMO_MaxPeripheralNumber > 21
#define FH_PWMO22
#endif
#if FH_PWMO_MaxPeripheralNumber > 22
#define FH_PWMO23
#endif
#if FH_PWMO_MaxPeripheralNumber > 23
#define FH_PWMO24
#endif
#if FH_PWMO_MaxPeripheralNumber > 24
#define FH_PWMO25
#endif
#if FH_PWMO_MaxPeripheralNumber > 25
#define FH_PWMO26
#endif
#if FH_PWMO_MaxPeripheralNumber > 26
#define FH_PWMO27
#endif
#if FH_PWMO_MaxPeripheralNumber > 27
#define FH_PWMO28
#endif
#if FH_PWMO_MaxPeripheralNumber > 28
#define FH_PWMO29
#endif
#if FH_PWMO_MaxPeripheralNumber > 29
#define FH_PWMO30
#endif
#if FH_PWMO_MaxPeripheralNumber > 30
#define FH_PWMO31
#endif
#if FH_PWMO_MaxPeripheralNumber > 31
#define FH_PWMO32
#endif
#if FH_PWMO_MaxPeripheralNumber > 32
#define FH_PWMO33
#endif
#if FH_PWMO_MaxPeripheralNumber > 33
#define FH_PWMO34
#endif
#if FH_PWMO_MaxPeripheralNumber > 34
#define FH_PWMO35
#endif
#if FH_PWMO_MaxPeripheralNumber > 35
#define FH_PWMO36
#endif
#if FH_PWMO_MaxPeripheralNumber > 36
#define FH_PWMO37
#endif
#if FH_PWMO_MaxPeripheralNumber > 37
#define FH_PWMO38
#endif
#if FH_PWMO_MaxPeripheralNumber > 38
#define FH_PWMO39
#endif
#if FH_PWMO_MaxPeripheralNumber > 39
#define FH_PWMO40
#endif
#if FH_PWMO_MaxPeripheralNumber > 40
#define FH_PWMO41
#endif
#if FH_PWMO_MaxPeripheralNumber > 41
#define FH_PWMO42
#endif
#if FH_PWMO_MaxPeripheralNumber > 42
#define FH_PWMO43
#endif
#if FH_PWMO_MaxPeripheralNumber > 43
#define FH_PWMO44
#endif
#if FH_PWMO_MaxPeripheralNumber > 44
#define FH_PWMO45
#endif
#if FH_PWMO_MaxPeripheralNumber > 45
#define FH_PWMO46
#endif
#if FH_PWMO_MaxPeripheralNumber > 46
#define FH_PWMO47
#endif
#if FH_PWMO_MaxPeripheralNumber > 47
#define FH_PWMO48
#endif
#if FH_PWMO_MaxPeripheralNumber > 48
#define FH_PWMO49
#endif
#if FH_PWMO_MaxPeripheralNumber > 49
#define FH_PWMO50
#endif
#if FH_PWMO_MaxPeripheralNumber > 50
#define FH_PWMO51
#endif
#if FH_PWMO_MaxPeripheralNumber > 51
#define FH_PWMO52
#endif
#if FH_PWMO_MaxPeripheralNumber > 52
#define FH_PWMO53
#endif
#if FH_PWMO_MaxPeripheralNumber > 53
#define FH_PWMO54
#endif
#if FH_PWMO_MaxPeripheralNumber > 54
#define FH_PWMO55
#endif
#if FH_PWMO_MaxPeripheralNumber > 55
#define FH_PWMO56
#endif
#if FH_PWMO_MaxPeripheralNumber > 56
#define FH_PWMO57
#endif
#if FH_PWMO_MaxPeripheralNumber > 57
#define FH_PWMO58
#endif
#if FH_PWMO_MaxPeripheralNumber > 58
#define FH_PWMO59
#endif
#if FH_PWMO_MaxPeripheralNumber > 59
#define FH_PWMO60
#endif
#if FH_PWMO_MaxPeripheralNumber > 60
#define FH_PWMO61
#endif
#if FH_PWMO_MaxPeripheralNumber > 61
#define FH_PWMO62
#endif
#if FH_PWMO_MaxPeripheralNumber > 62
#define FH_PWMO63
#endif
#if FH_PWMO_MaxPeripheralNumber > 63
#define FH_PWMO64
#endif

#if FH_PWMO_MaxPeripheralNumber > 0    // If at least one <b>FH_PWMO</b> (PWM Output) is defined

/*!
  <b>FH_PWMO_Init_FuncPtrModel</b> Function pointer definition
*/
typedef FH_ErrorInfo (*FH_PWMO_Init_FuncPtrModel) (FH_RFCommunication_Message* fh_RFCommunication_Message);

/*!
<b>FH_PWMO_SetStatus_FuncPtrModel</b> Function pointer definition
*/
typedef FH_ErrorInfo (*FH_PWMO_SetStatus_FuncPtrModel) (FH_RFCommunication_Message* fh_RFCommunication_Message);

/*!
  Different commands for <b>PWMO_</b> (PWM Output) Function
*/
enum FH_PWMO_Commands
{
	FH_PWMO_Commands_Init         = 0,
	FH_PWMO_Commands_SetStatus    = 1,
};

/*!
  Minimum size of the <b>Data</b> part in the message frame (<b>FH_RFCommunication_Message</b>) for the <b>Init</b> command of <b>PWMO</b> Function, are defined here
*/
#define FH_PWMO_MinCommandSize_Init        		      1

/*!
  Minimum size of the <b>Data</b> part in the message frame (<b>FH_RFCommunication_Message</b>) for the <b>SetStatus</b> command of <b>PWMO</b> Function, are defined here
*/
#define FH_PWMO_MinCommandSize_SetStatus      		  6

/*!
  Different elements of the Data part in the message frame (<b>FH_RFCommunication_Message</b>) for the Init command of <b>PWMO</b> Function, are defined here
*/
enum FH_PWMO_Commandelements_Init
{
	PWMO_Init_PeripheralNumber   = 0,
};

/*!
  Different elements of the Data part in the message frame (<b>FH_RFCommunication_Message</b>) for the SetStatus command of <b>PWMO</b> Function, are defined here
*/
enum FH_PWMO_Commandelements_SetStatus
{
	PWMO_SetStatus_PeripheralNumber    = 0,
	PWMO_SetStatus_FrequencyByte4      = 1,    // Total 4 bytes as uint32_t
	PWMO_SetStatus_FrequencyByte3      = 2,
	PWMO_SetStatus_FrequencyByte2      = 3,
	PWMO_SetStatus_FrequencyByte1      = 4,
	PWMO_SetStatus_DutyCycle           = 5,
};

#endif

#endif
