/**
  * @file
  * @brief
  *       <b>File Map:</b>\n
  *       <b>FH_Root</b>, Section <b>FH_Perif</b>, <b>FH_AI</b> (Analog Input), <b>FH_AI_Configs</b>\n
  *       In this file, different configurations of <b>FH_AI</b> (Analog Input) could be set
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
#ifndef FH_AI_Configs_H
#define FH_AI_Configs_H

/* Includes ------------------------------------------------------------------*/
#include "../../../../../FH_Embedded/FH_Setup/FH_DevicePeripherals/FH_DevicePeripherals.h"
#include "../../../../../FH_Embedded/FH_Root/FH_General/FH_ErrorInfo/FH_ErrorInfo.h"
#include "../../../../../FH_Embedded/FH_Setup/FH_RFCommunication/FH_RFCommunication_GlobalVariables.h"

/*!
  <b>FH_AI01 - FH_AI64</b> shall be defined here to be utilized in different parts of the <b>FH</b> source code\n
  <b>FH_AI_MaxPeripheralNumber</b> is the maximum number of the <b>FH_AI</b> (Analog Input)
*/

#if FH_AI_MaxPeripheralNumber > 0
#define FH_AI01
#endif
#if FH_AI_MaxPeripheralNumber > 1
#define FH_AI02
#endif
#if FH_AI_MaxPeripheralNumber > 2
#define FH_AI03
#endif
#if FH_AI_MaxPeripheralNumber > 3
#define FH_AI04
#endif
#if FH_AI_MaxPeripheralNumber > 4
#define FH_AI05
#endif
#if FH_AI_MaxPeripheralNumber > 5
#define FH_AI06
#endif
#if FH_AI_MaxPeripheralNumber > 6
#define FH_AI07
#endif
#if FH_AI_MaxPeripheralNumber > 7
#define FH_AI08
#endif
#if FH_AI_MaxPeripheralNumber > 8
#define FH_AI09
#endif
#if FH_AI_MaxPeripheralNumber > 9
#define FH_AI10
#endif
#if FH_AI_MaxPeripheralNumber > 10
#define FH_AI11
#endif
#if FH_AI_MaxPeripheralNumber > 11
#define FH_AI12
#endif
#if FH_AI_MaxPeripheralNumber > 12
#define FH_AI13
#endif
#if FH_AI_MaxPeripheralNumber > 13
#define FH_AI14
#endif
#if FH_AI_MaxPeripheralNumber > 14
#define FH_AI15
#endif
#if FH_AI_MaxPeripheralNumber > 15
#define FH_AI16
#endif
#if FH_AI_MaxPeripheralNumber > 16
#define FH_AI17
#endif
#if FH_AI_MaxPeripheralNumber > 17
#define FH_AI18
#endif
#if FH_AI_MaxPeripheralNumber > 18
#define FH_AI19
#endif
#if FH_AI_MaxPeripheralNumber > 19
#define FH_AI20
#endif
#if FH_AI_MaxPeripheralNumber > 20
#define FH_AI21
#endif
#if FH_AI_MaxPeripheralNumber > 21
#define FH_AI22
#endif
#if FH_AI_MaxPeripheralNumber > 22
#define FH_AI23
#endif
#if FH_AI_MaxPeripheralNumber > 23
#define FH_AI24
#endif
#if FH_AI_MaxPeripheralNumber > 24
#define FH_AI25
#endif
#if FH_AI_MaxPeripheralNumber > 25
#define FH_AI26
#endif
#if FH_AI_MaxPeripheralNumber > 26
#define FH_AI27
#endif
#if FH_AI_MaxPeripheralNumber > 27
#define FH_AI28
#endif
#if FH_AI_MaxPeripheralNumber > 28
#define FH_AI29
#endif
#if FH_AI_MaxPeripheralNumber > 29
#define FH_AI30
#endif
#if FH_AI_MaxPeripheralNumber > 30
#define FH_AI31
#endif
#if FH_AI_MaxPeripheralNumber > 31
#define FH_AI32
#endif
#if FH_AI_MaxPeripheralNumber > 32
#define FH_AI33
#endif
#if FH_AI_MaxPeripheralNumber > 33
#define FH_AI34
#endif
#if FH_AI_MaxPeripheralNumber > 34
#define FH_AI35
#endif
#if FH_AI_MaxPeripheralNumber > 35
#define FH_AI36
#endif
#if FH_AI_MaxPeripheralNumber > 36
#define FH_AI37
#endif
#if FH_AI_MaxPeripheralNumber > 37
#define FH_AI38
#endif
#if FH_AI_MaxPeripheralNumber > 38
#define FH_AI39
#endif
#if FH_AI_MaxPeripheralNumber > 39
#define FH_AI40
#endif
#if FH_AI_MaxPeripheralNumber > 40
#define FH_AI41
#endif
#if FH_AI_MaxPeripheralNumber > 41
#define FH_AI42
#endif
#if FH_AI_MaxPeripheralNumber > 42
#define FH_AI43
#endif
#if FH_AI_MaxPeripheralNumber > 43
#define FH_AI44
#endif
#if FH_AI_MaxPeripheralNumber > 44
#define FH_AI45
#endif
#if FH_AI_MaxPeripheralNumber > 45
#define FH_AI46
#endif
#if FH_AI_MaxPeripheralNumber > 46
#define FH_AI47
#endif
#if FH_AI_MaxPeripheralNumber > 47
#define FH_AI48
#endif
#if FH_AI_MaxPeripheralNumber > 48
#define FH_AI49
#endif
#if FH_AI_MaxPeripheralNumber > 49
#define FH_AI50
#endif
#if FH_AI_MaxPeripheralNumber > 50
#define FH_AI51
#endif
#if FH_AI_MaxPeripheralNumber > 51
#define FH_AI52
#endif
#if FH_AI_MaxPeripheralNumber > 52
#define FH_AI53
#endif
#if FH_AI_MaxPeripheralNumber > 53
#define FH_AI54
#endif
#if FH_AI_MaxPeripheralNumber > 54
#define FH_AI55
#endif
#if FH_AI_MaxPeripheralNumber > 55
#define FH_AI56
#endif
#if FH_AI_MaxPeripheralNumber > 56
#define FH_AI57
#endif
#if FH_AI_MaxPeripheralNumber > 57
#define FH_AI58
#endif
#if FH_AI_MaxPeripheralNumber > 58
#define FH_AI59
#endif
#if FH_AI_MaxPeripheralNumber > 59
#define FH_AI60
#endif
#if FH_AI_MaxPeripheralNumber > 60
#define FH_AI61
#endif
#if FH_AI_MaxPeripheralNumber > 61
#define FH_AI62
#endif
#if FH_AI_MaxPeripheralNumber > 62
#define FH_AI63
#endif
#if FH_AI_MaxPeripheralNumber > 63
#define FH_AI64
#endif

#if FH_AI_MaxPeripheralNumber > 0    // If at least one <b>FH_AI</b> (Analog Input) is defined

/*!
  <b>FH_AI_Init_FuncPtrModel</b> Function pointer definition
*/
typedef FH_ErrorInfo (*FH_AI_Init_FuncPtrModel)                (FH_RFCommunication_Message* fh_RFCommunication_Message);

/*!
<b>FH_AI_GetStatus_FuncPtrModel</b> Function pointer definition
*/
typedef FH_ErrorInfo (*FH_AI_GetStatus_FuncPtrModel)                (FH_RFCommunication_Message* fh_RFCommunication_Message, uint32_t* FH_AI_Data);

/*!
  Different commands for <b>AI</b> (Analog Input) Function
*/
enum FH_AI_Commands
{
	FH_AI_Commands_Init         = 0,
	FH_AI_Commands_GetStatus    = 1,
};

/*!
  Minimum size of the <b>Data</b> part in the message frame (<b>FH_RFCommunication_Message</b>) for the <b>Init</b> command of <b>AI</b> Function, are defined here
*/
#define FH_AI_MinCommandSize_Init        		      1

/*!
  Minimum size of the <b>Data</b> part in the message frame (<b>FH_RFCommunication_Message</b>) for the <b>GetStatus</b> command of <b>AI</b> Function, are defined here
*/
#define FH_AI_MinCommandSize_GetStatus      		  1

/*!
  Different elements of the Data part in the message frame (<b>FH_RFCommunication_Message</b>) for the Init command of <b>AI</b> Function, are defined here
*/
enum FH_AI_Commandelements_Init
{
	AI_Init_PeripheralNumber   = 0,
};

/*!
  Different elements of the Data part in the message frame (<b>FH_RFCommunication_Message</b>) for the GetStatus command of <b>AI</b> Function, are defined here
*/
enum FH_AI_Commandelements_GetStatus
{
	AI_GetStatus_PeripheralNumber   = 0,
};

#endif

#endif
