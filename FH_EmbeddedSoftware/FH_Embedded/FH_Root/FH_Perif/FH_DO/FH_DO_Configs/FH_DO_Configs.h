/**
  * @file
  * @brief
  *       <b>File Map:</b>\n
  *       <b>FH_Root</b>, Section <b>FH_Perif</b>, <b>FH_DO</b> (Digital Output), <b>FH_DO_Configs</b>\n
  *       In this file, different configurations of <b>FH_DO</b> (Digital Output) could be set
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
#ifndef FH_DO_Configs_H
#define FH_DO_Configs_H

/* Includes ------------------------------------------------------------------*/
#include "../../../../FH_Setup/FH_DevicePeripherals/FH_DevicePeripherals.h"
#include "../../../../../FH_Embedded/FH_Root/FH_General/FH_ErrorInfo/FH_ErrorInfo.h"
#include "../../../../../FH_Embedded/FH_Setup/FH_RFCommunication/FH_RFCommunication_GlobalVariables.h"

/*!
  <b>FH_DO01 - FH_DO64</b> shall be defined here to be utilized in different parts of the <b>FH</b> source code\n
  <b>FH_DO_MaxPeripheralNumber</b> is the maximum number of the <b>FH_DO</b> (Digital Output)
*/

#if FH_DO_MaxPeripheralNumber > 0
#define FH_DO01
#endif
#if FH_DO_MaxPeripheralNumber > 1
#define FH_DO02
#endif
#if FH_DO_MaxPeripheralNumber > 2
#define FH_DO03
#endif
#if FH_DO_MaxPeripheralNumber > 3
#define FH_DO04
#endif
#if FH_DO_MaxPeripheralNumber > 4
#define FH_DO05
#endif
#if FH_DO_MaxPeripheralNumber > 5
#define FH_DO06
#endif
#if FH_DO_MaxPeripheralNumber > 6
#define FH_DO07
#endif
#if FH_DO_MaxPeripheralNumber > 7
#define FH_DO08
#endif
#if FH_DO_MaxPeripheralNumber > 8
#define FH_DO09
#endif
#if FH_DO_MaxPeripheralNumber > 9
#define FH_DO10
#endif
#if FH_DO_MaxPeripheralNumber > 10
#define FH_DO11
#endif
#if FH_DO_MaxPeripheralNumber > 11
#define FH_DO12
#endif
#if FH_DO_MaxPeripheralNumber > 12
#define FH_DO13
#endif
#if FH_DO_MaxPeripheralNumber > 13
#define FH_DO14
#endif
#if FH_DO_MaxPeripheralNumber > 14
#define FH_DO15
#endif
#if FH_DO_MaxPeripheralNumber > 15
#define FH_DO16
#endif
#if FH_DO_MaxPeripheralNumber > 16
#define FH_DO17
#endif
#if FH_DO_MaxPeripheralNumber > 17
#define FH_DO18
#endif
#if FH_DO_MaxPeripheralNumber > 18
#define FH_DO19
#endif
#if FH_DO_MaxPeripheralNumber > 19
#define FH_DO20
#endif
#if FH_DO_MaxPeripheralNumber > 20
#define FH_DO21
#endif
#if FH_DO_MaxPeripheralNumber > 21
#define FH_DO22
#endif
#if FH_DO_MaxPeripheralNumber > 22
#define FH_DO23
#endif
#if FH_DO_MaxPeripheralNumber > 23
#define FH_DO24
#endif
#if FH_DO_MaxPeripheralNumber > 24
#define FH_DO25
#endif
#if FH_DO_MaxPeripheralNumber > 25
#define FH_DO26
#endif
#if FH_DO_MaxPeripheralNumber > 26
#define FH_DO27
#endif
#if FH_DO_MaxPeripheralNumber > 27
#define FH_DO28
#endif
#if FH_DO_MaxPeripheralNumber > 28
#define FH_DO29
#endif
#if FH_DO_MaxPeripheralNumber > 29
#define FH_DO30
#endif
#if FH_DO_MaxPeripheralNumber > 30
#define FH_DO31
#endif
#if FH_DO_MaxPeripheralNumber > 31
#define FH_DO32
#endif
#if FH_DO_MaxPeripheralNumber > 32
#define FH_DO33
#endif
#if FH_DO_MaxPeripheralNumber > 33
#define FH_DO34
#endif
#if FH_DO_MaxPeripheralNumber > 34
#define FH_DO35
#endif
#if FH_DO_MaxPeripheralNumber > 35
#define FH_DO36
#endif
#if FH_DO_MaxPeripheralNumber > 36
#define FH_DO37
#endif
#if FH_DO_MaxPeripheralNumber > 37
#define FH_DO38
#endif
#if FH_DO_MaxPeripheralNumber > 38
#define FH_DO39
#endif
#if FH_DO_MaxPeripheralNumber > 39
#define FH_DO40
#endif
#if FH_DO_MaxPeripheralNumber > 40
#define FH_DO41
#endif
#if FH_DO_MaxPeripheralNumber > 41
#define FH_DO42
#endif
#if FH_DO_MaxPeripheralNumber > 42
#define FH_DO43
#endif
#if FH_DO_MaxPeripheralNumber > 43
#define FH_DO44
#endif
#if FH_DO_MaxPeripheralNumber > 44
#define FH_DO45
#endif
#if FH_DO_MaxPeripheralNumber > 45
#define FH_DO46
#endif
#if FH_DO_MaxPeripheralNumber > 46
#define FH_DO47
#endif
#if FH_DO_MaxPeripheralNumber > 47
#define FH_DO48
#endif
#if FH_DO_MaxPeripheralNumber > 48
#define FH_DO49
#endif
#if FH_DO_MaxPeripheralNumber > 49
#define FH_DO50
#endif
#if FH_DO_MaxPeripheralNumber > 50
#define FH_DO51
#endif
#if FH_DO_MaxPeripheralNumber > 51
#define FH_DO52
#endif
#if FH_DO_MaxPeripheralNumber > 52
#define FH_DO53
#endif
#if FH_DO_MaxPeripheralNumber > 53
#define FH_DO54
#endif
#if FH_DO_MaxPeripheralNumber > 54
#define FH_DO55
#endif
#if FH_DO_MaxPeripheralNumber > 55
#define FH_DO56
#endif
#if FH_DO_MaxPeripheralNumber > 56
#define FH_DO57
#endif
#if FH_DO_MaxPeripheralNumber > 57
#define FH_DO58
#endif
#if FH_DO_MaxPeripheralNumber > 58
#define FH_DO59
#endif
#if FH_DO_MaxPeripheralNumber > 59
#define FH_DO60
#endif
#if FH_DO_MaxPeripheralNumber > 60
#define FH_DO61
#endif
#if FH_DO_MaxPeripheralNumber > 61
#define FH_DO62
#endif
#if FH_DO_MaxPeripheralNumber > 62
#define FH_DO63
#endif
#if FH_DO_MaxPeripheralNumber > 63
#define FH_DO64
#endif

#if FH_DO_MaxPeripheralNumber > 0    // If at least one <b>FH_DO</b> (Digital Output) is defined

/*!
  <b>FH_DO_Init_FuncPtrModel</b> Function pointer definition
*/
typedef FH_ErrorInfo (*FH_DO_Init_FuncPtrModel) ();

/*!
<b>FH_DO_SetStatus_FuncPtrModel</b> Function pointer definition
*/
typedef FH_ErrorInfo (*FH_DO_SetStatus_FuncPtrModel) (uint8_t status);

/*!
  Different commands for <b>DO</b> (Digital Output) Function
*/
enum FH_DO_Commands
{
	FH_DO_Commands_Init            = 0,
	FH_DO_Commands_SetStatus       = 1,
	FH_DO_Commands_InitMULTI 	   = 2,
	FH_DO_Commands_SetStatusMULTI  = 3,
};

/*!
  By default, in <b>InitMULTI</b> (Which is mass initialization of up to 64 <b>DO</b> (Digital Output)) and <b>SetStatusMULTI</b> (Which is mass status set of up to 64 <b>DO</b> (Digital Output)) commands, 8 bytes which is 64 bits (which means 64 <b>DO</b> (Digital Output)) is used in these commands\n
  This value is set here as <b>FH_DO_MULTI_MaxPeripheralNumberLimit</b>\n
  On the other hand, <b>FH_DO_MaxPeripheralNumber</b> is the maximum number of the <b>FH_DO</b> (Digital Output)\n

  @warning
       To use <b>InitMULTI</b> (Which is mass initialization of up to 64 <b>DO</b> (Digital Output)) and <b>SetStatusMULTI</b> (Which is mass status set of up to 64 <b>DO</b> (Digital Output)) commands, <b>FH_DO_MaxPeripheralNumber</b> and <b>FH_DO_MULTI_MaxPeripheralNumberLimit</b> shall be set to 64\n
*/
#define FH_DO_MULTI_MaxPeripheralNumberLimit	 64

/*!
  Minimum size of the <b>Data</b> part in the message frame (<b>FH_RFCommunication_Message</b>) for the <b>Init</b> command of <b>DO</b> Function, are defined here
*/
#define FH_DO_MinCommandSize_Init        	   1

/*!
  Minimum size of the <b>Data</b> part in the message frame (<b>FH_RFCommunication_Message</b>) for the <b>SetStatus</b> command of <b>DO</b> Function, are defined here
*/
#define FH_DO_MinCommandSize_SetStatus         2

/*!
  Minimum size of the <b>Data</b> part in the message frame (<b>FH_RFCommunication_Message</b>) for the <b>InitMULTI</b> command of <b>DO</b> Function, are defined here
*/
#define FH_DO_MinCommandSize_InitMULTI		   8

/*!
  Minimum size of the <b>Data</b> part in the message frame (<b>FH_RFCommunication_Message</b>) for the <b>SetStatusMULTI</b> command of <b>DO</b> Function, are defined here
*/
#define FH_DO_MinCommandSize_SetStatusMULTI    16

/*!
  Different elements of the Data part in the message frame (<b>FH_RFCommunication_Message</b>) for the Init command of <b>DO</b> Function, are defined here
*/
enum FH_DO_Commandelements_Init
{
	DO_Init_PeripheralNumber   = 0,
};

/*!
  Different elements of the Data part in the message frame (<b>FH_RFCommunication_Message</b>) for the SetStatus command of <b>DO</b> Function, are defined here
*/
enum FH_DO_Commandelements_SetStatus
{
	DO_SetStatus_PeripheralNumber   = 0,
	DO_SetStatus_Status             = 1,
};

/*!
  Different elements of the Data part in the message frame (<b>FH_RFCommunication_Message</b>) for the InitMULTI command of <b>DO</b> Function, are defined here
*/
enum FH_DO_Commandelements_InitMULTI
{
	DO_InitMULTI_Byte0   = 0,
	DO_InitMULTI_Byte1   = 1,
	DO_InitMULTI_Byte2   = 2,
	DO_InitMULTI_Byte3   = 3,
	DO_InitMULTI_Byte4   = 4,
	DO_InitMULTI_Byte5   = 5,
	DO_InitMULTI_Byte6   = 6,
	DO_InitMULTI_Byte7   = 7,
};

/*!
  Different elements of the Data part in the message frame (<b>FH_RFCommunication_Message</b>) for the SetStatusMULTI command of <b>DO</b> Function, are defined here
*/
enum FH_DO_Commandelements_SetStatusMULTI
{
	DO_SetStatusMULTI_StatusMaskByte0   = 0,
	DO_SetStatusMULTI_StatusMaskByte1   = 1,
	DO_SetStatusMULTI_StatusMaskByte2   = 2,
	DO_SetStatusMULTI_StatusMaskByte3   = 3,
	DO_SetStatusMULTI_StatusMaskByte4   = 4,
	DO_SetStatusMULTI_StatusMaskByte5   = 5,
	DO_SetStatusMULTI_StatusMaskByte6   = 6,
	DO_SetStatusMULTI_StatusMaskByte7   = 7,

	DO_SetStatusMULTI_StatusByte0   = 8,
	DO_SetStatusMULTI_StatusByte1   = 9,
	DO_SetStatusMULTI_StatusByte2   = 10,
	DO_SetStatusMULTI_StatusByte3   = 11,
	DO_SetStatusMULTI_StatusByte4   = 12,
	DO_SetStatusMULTI_StatusByte5   = 13,
	DO_SetStatusMULTI_StatusByte6   = 14,
	DO_SetStatusMULTI_StatusByte7   = 15,
};

#endif

#endif
