/**
  * @file
  * @brief
  *       <b>File Map:</b>\n
  *       <b>FH_Root</b>, Section <b>FH_Perif</b>, <b>FH_DI</b> (Digital Input), <b>FH_DI_Configs</b>\n
  *       In this file, different configurations of <b>FH_DI</b> (Digital Input) could be set
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
#ifndef FH_DI_Configs_H
#define FH_DI_Configs_H

/* Includes ------------------------------------------------------------------*/
#include "../../../../../FH_Embedded/FH_Setup/FH_DevicePeripherals/FH_DevicePeripherals.h"
#include "../../../../../FH_Embedded/FH_Root/FH_General/FH_ErrorInfo/FH_ErrorInfo.h"
#include "../../../../../FH_Embedded/FH_Setup/FH_RFCommunication/FH_RFCommunication_GlobalVariables.h"

/*!
  <b>FH_DI01 - FH_DI64</b> shall be defined here to be utilized in different parts of the <b>FH</b> source code\n
  <b>FH_DI_MaxPeripheralNumber</b> is the maximum number of the <b>FH_DI</b> (Digital Input)
*/

#if FH_DI_MaxPeripheralNumber > 0
#define FH_DI01
#endif
#if FH_DI_MaxPeripheralNumber > 1
#define FH_DI02
#endif
#if FH_DI_MaxPeripheralNumber > 2
#define FH_DI03
#endif
#if FH_DI_MaxPeripheralNumber > 3
#define FH_DI04
#endif
#if FH_DI_MaxPeripheralNumber > 4
#define FH_DI05
#endif
#if FH_DI_MaxPeripheralNumber > 5
#define FH_DI06
#endif
#if FH_DI_MaxPeripheralNumber > 6
#define FH_DI07
#endif
#if FH_DI_MaxPeripheralNumber > 7
#define FH_DI08
#endif
#if FH_DI_MaxPeripheralNumber > 8
#define FH_DI09
#endif
#if FH_DI_MaxPeripheralNumber > 9
#define FH_DI10
#endif
#if FH_DI_MaxPeripheralNumber > 10
#define FH_DI11
#endif
#if FH_DI_MaxPeripheralNumber > 11
#define FH_DI12
#endif
#if FH_DI_MaxPeripheralNumber > 12
#define FH_DI13
#endif
#if FH_DI_MaxPeripheralNumber > 13
#define FH_DI14
#endif
#if FH_DI_MaxPeripheralNumber > 14
#define FH_DI15
#endif
#if FH_DI_MaxPeripheralNumber > 15
#define FH_DI16
#endif
#if FH_DI_MaxPeripheralNumber > 16
#define FH_DI17
#endif
#if FH_DI_MaxPeripheralNumber > 17
#define FH_DI18
#endif
#if FH_DI_MaxPeripheralNumber > 18
#define FH_DI19
#endif
#if FH_DI_MaxPeripheralNumber > 19
#define FH_DI20
#endif
#if FH_DI_MaxPeripheralNumber > 20
#define FH_DI21
#endif
#if FH_DI_MaxPeripheralNumber > 21
#define FH_DI22
#endif
#if FH_DI_MaxPeripheralNumber > 22
#define FH_DI23
#endif
#if FH_DI_MaxPeripheralNumber > 23
#define FH_DI24
#endif
#if FH_DI_MaxPeripheralNumber > 24
#define FH_DI25
#endif
#if FH_DI_MaxPeripheralNumber > 25
#define FH_DI26
#endif
#if FH_DI_MaxPeripheralNumber > 26
#define FH_DI27
#endif
#if FH_DI_MaxPeripheralNumber > 27
#define FH_DI28
#endif
#if FH_DI_MaxPeripheralNumber > 28
#define FH_DI29
#endif
#if FH_DI_MaxPeripheralNumber > 29
#define FH_DI30
#endif
#if FH_DI_MaxPeripheralNumber > 30
#define FH_DI31
#endif
#if FH_DI_MaxPeripheralNumber > 31
#define FH_DI32
#endif
#if FH_DI_MaxPeripheralNumber > 32
#define FH_DI33
#endif
#if FH_DI_MaxPeripheralNumber > 33
#define FH_DI34
#endif
#if FH_DI_MaxPeripheralNumber > 34
#define FH_DI35
#endif
#if FH_DI_MaxPeripheralNumber > 35
#define FH_DI36
#endif
#if FH_DI_MaxPeripheralNumber > 36
#define FH_DI37
#endif
#if FH_DI_MaxPeripheralNumber > 37
#define FH_DI38
#endif
#if FH_DI_MaxPeripheralNumber > 38
#define FH_DI39
#endif
#if FH_DI_MaxPeripheralNumber > 39
#define FH_DI40
#endif
#if FH_DI_MaxPeripheralNumber > 40
#define FH_DI41
#endif
#if FH_DI_MaxPeripheralNumber > 41
#define FH_DI42
#endif
#if FH_DI_MaxPeripheralNumber > 42
#define FH_DI43
#endif
#if FH_DI_MaxPeripheralNumber > 43
#define FH_DI44
#endif
#if FH_DI_MaxPeripheralNumber > 44
#define FH_DI45
#endif
#if FH_DI_MaxPeripheralNumber > 45
#define FH_DI46
#endif
#if FH_DI_MaxPeripheralNumber > 46
#define FH_DI47
#endif
#if FH_DI_MaxPeripheralNumber > 47
#define FH_DI48
#endif
#if FH_DI_MaxPeripheralNumber > 48
#define FH_DI49
#endif
#if FH_DI_MaxPeripheralNumber > 49
#define FH_DI50
#endif
#if FH_DI_MaxPeripheralNumber > 50
#define FH_DI51
#endif
#if FH_DI_MaxPeripheralNumber > 51
#define FH_DI52
#endif
#if FH_DI_MaxPeripheralNumber > 52
#define FH_DI53
#endif
#if FH_DI_MaxPeripheralNumber > 53
#define FH_DI54
#endif
#if FH_DI_MaxPeripheralNumber > 54
#define FH_DI55
#endif
#if FH_DI_MaxPeripheralNumber > 55
#define FH_DI56
#endif
#if FH_DI_MaxPeripheralNumber > 56
#define FH_DI57
#endif
#if FH_DI_MaxPeripheralNumber > 57
#define FH_DI58
#endif
#if FH_DI_MaxPeripheralNumber > 58
#define FH_DI59
#endif
#if FH_DI_MaxPeripheralNumber > 59
#define FH_DI60
#endif
#if FH_DI_MaxPeripheralNumber > 60
#define FH_DI61
#endif
#if FH_DI_MaxPeripheralNumber > 61
#define FH_DI62
#endif
#if FH_DI_MaxPeripheralNumber > 62
#define FH_DI63
#endif
#if FH_DI_MaxPeripheralNumber > 63
#define FH_DI64
#endif

#if FH_DI_MaxPeripheralNumber > 0    // If at least one <b>FH_DI</b> (Digital Input) is defined

/*!
  <b>FH_DI_Init_FuncPtrModel</b> Function pointer definition
*/
typedef FH_ErrorInfo (*FH_DI_Init_FuncPtrModel) ();

/*!
<b>FH_DI_GetStatus_FuncPtrModel</b> Function pointer definition
*/
typedef FH_ErrorInfo (*FH_DI_GetStatus_FuncPtrModel) (uint8_t* FH_DI_Data);

/*!
  Different commands for <b>DI</b> (Digital Input) Function
*/
enum FH_DI_Commands
{
	FH_DI_Commands_Init            = 0,
	FH_DI_Commands_GetStatus       = 1,
	FH_DI_Commands_InitMULTI	   = 2,
	FH_DI_Commands_GetStatusMULTI  = 3,
};

/*!
  By default, in <b>InitMULTI</b> (Which is mass initialization of up to 64 <b>DI</b> (Digital Input)) and <b>GetStatusMULTI</b> (Which is mass status get of up to 64 <b>DI</b> (Digital Input)) commands, 8 bytes which is 64 bits (which means 64 <b>DI</b> (Digital Input)) is used in these commands\n
  This value is set here as <b>FH_DI_MULTI_MaxPeripheralNumberLimit</b>\n
  On the other hand, <b>FH_DI_MaxPeripheralNumber</b> is the maximum number of the <b>FH_DI</b> (Digital Input)\n

  @warning
       To use <b>InitMULTI</b> (Which is mass initialization of up to 64 <b>DI</b> (Digital Input)) and <b>GetStatusMULTI</b> (Which is mass status get of up to 64 <b>DI</b> (Digital Input)) commands, <b>FH_DI_MaxPeripheralNumber</b> and <b>FH_DI_MULTI_MaxPeripheralNumberLimit</b> shall be set to 64\n
*/
#define FH_DI_MULTI_MaxPeripheralNumberLimit	 64

/*!
  Minimum size of the <b>Data</b> part in the message frame (<b>FH_RFCommunication_Message</b>) for the <b>Init</b> command of <b>DI</b> Function, are defined here
*/
#define FH_DI_MinCommandSize_Init              1

/*!
  Minimum size of the <b>Data</b> part in the message frame (<b>FH_RFCommunication_Message</b>) for the <b>GetStatus</b> command of <b>DI</b> Function, are defined here
*/
#define FH_DI_MinCommandSize_GetStatus         1

/*!
  Minimum size of the <b>Data</b> part in the message frame (<b>FH_RFCommunication_Message</b>) for the <b>InitMULTI</b> command of <b>DI</b> Function, are defined here
*/
#define FH_DI_MinCommandSize_InitMULTI		   8

/*!
  Minimum size of the <b>Data</b> part in the message frame (<b>FH_RFCommunication_Message</b>) for the <b>GetStatusMULTI</b> command of <b>DI</b> Function, are defined here
*/
#define FH_DI_MinCommandSize_GetStatusMULTI    8

/*!
  Different elements of the Data part in the message frame (<b>FH_RFCommunication_Message</b>) for the Init command of <b>DI</b> Function, are defined here
*/
enum FH_DI_Commandelements_Init
{
	DI_Init_PeripheralNumber   = 0,
};

/*!
  Different elements of the Data part in the message frame (<b>FH_RFCommunication_Message</b>) for the GetStatus command of <b>DI</b> Function, are defined here
*/
enum FH_DI_Commandelements_GetStatus
{
	DI_GetStatus_PeripheralNumber   = 0,
};

/*!
  Different elements of the Data part in the message frame (<b>FH_RFCommunication_Message</b>) for the InitMULTI command of <b>DI</b> Function, are defined here
*/
enum FH_DI_Commandelements_InitMULTI
{
	DI_InitMULTI_Byte0	 = 0,
	DI_InitMULTI_Byte1	 = 1,
	DI_InitMULTI_Byte2	 = 2,
	DI_InitMULTI_Byte3	 = 3,
	DI_InitMULTI_Byte4	 = 4,
	DI_InitMULTI_Byte5	 = 5,
	DI_InitMULTI_Byte6	 = 6,
	DI_InitMULTI_Byte7	 = 7,
};

/*!
  Different elements of the Data part in the message frame (<b>FH_RFCommunication_Message</b>) for the GetStatusMULTI command of <b>DI</b> Function, are defined here
*/
enum FH_DI_Commandelements_GetStatusMULTI
{
	DI_GetStatusMULTI_StatusMaskByte0	= 0,
	DI_GetStatusMULTI_StatusMaskByte1	= 1,
	DI_GetStatusMULTI_StatusMaskByte2	= 2,
	DI_GetStatusMULTI_StatusMaskByte3	= 3,
	DI_GetStatusMULTI_StatusMaskByte4	= 4,
	DI_GetStatusMULTI_StatusMaskByte5	= 5,
	DI_GetStatusMULTI_StatusMaskByte6	= 6,
	DI_GetStatusMULTI_StatusMaskByte7	= 7,
};

#endif

#endif
