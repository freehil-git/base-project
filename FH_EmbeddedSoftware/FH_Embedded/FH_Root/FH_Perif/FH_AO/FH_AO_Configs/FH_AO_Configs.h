/**
  * @file
  * @brief
  *       <b>File Map:</b>\n
  *       <b>FH_Root</b>, Section <b>FH_Perif</b>, <b>FH_AO</b> (Analog Output), <b>FH_AO_Configs</b>\n
  *       In this file, different configurations of <b>FH_AO</b> (Analog Output) could be set
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
#ifndef FH_AO_Configs_H
#define FH_AO_Configs_H

/* Includes ------------------------------------------------------------------*/
#include "../../../../../FH_Embedded/FH_Setup/FH_DevicePeripherals/FH_DevicePeripherals.h"
#include "../../../../../FH_Embedded/FH_Root/FH_General/FH_ErrorInfo/FH_ErrorInfo.h"
#include "../../../../../FH_Embedded/FH_Setup/FH_RFCommunication/FH_RFCommunication_GlobalVariables.h"

/*!
  <b>FH_AO01 - FH_AO64</b> shall be defined here to be utilized in different parts of the <b>FH</b> source code\n
  <b>FH_AO_MaxPeripheralNumber</b> is the maximum number of the <b>FH_AO</b> (Analog Output)
*/

#if FH_AO_MaxPeripheralNumber > 0
#define FH_AO01
#endif
#if FH_AO_MaxPeripheralNumber > 1
#define FH_AO02
#endif
#if FH_AO_MaxPeripheralNumber > 2
#define FH_AO03
#endif
#if FH_AO_MaxPeripheralNumber > 3
#define FH_AO04
#endif
#if FH_AO_MaxPeripheralNumber > 4
#define FH_AO05
#endif
#if FH_AO_MaxPeripheralNumber > 5
#define FH_AO06
#endif
#if FH_AO_MaxPeripheralNumber > 6
#define FH_AO07
#endif
#if FH_AO_MaxPeripheralNumber > 7
#define FH_AO08
#endif
#if FH_AO_MaxPeripheralNumber > 8
#define FH_AO09
#endif
#if FH_AO_MaxPeripheralNumber > 9
#define FH_AO10
#endif
#if FH_AO_MaxPeripheralNumber > 10
#define FH_AO11
#endif
#if FH_AO_MaxPeripheralNumber > 11
#define FH_AO12
#endif
#if FH_AO_MaxPeripheralNumber > 12
#define FH_AO13
#endif
#if FH_AO_MaxPeripheralNumber > 13
#define FH_AO14
#endif
#if FH_AO_MaxPeripheralNumber > 14
#define FH_AO15
#endif
#if FH_AO_MaxPeripheralNumber > 15
#define FH_AO16
#endif
#if FH_AO_MaxPeripheralNumber > 16
#define FH_AO17
#endif
#if FH_AO_MaxPeripheralNumber > 17
#define FH_AO18
#endif
#if FH_AO_MaxPeripheralNumber > 18
#define FH_AO19
#endif
#if FH_AO_MaxPeripheralNumber > 19
#define FH_AO20
#endif
#if FH_AO_MaxPeripheralNumber > 20
#define FH_AO21
#endif
#if FH_AO_MaxPeripheralNumber > 21
#define FH_AO22
#endif
#if FH_AO_MaxPeripheralNumber > 22
#define FH_AO23
#endif
#if FH_AO_MaxPeripheralNumber > 23
#define FH_AO24
#endif
#if FH_AO_MaxPeripheralNumber > 24
#define FH_AO25
#endif
#if FH_AO_MaxPeripheralNumber > 25
#define FH_AO26
#endif
#if FH_AO_MaxPeripheralNumber > 26
#define FH_AO27
#endif
#if FH_AO_MaxPeripheralNumber > 27
#define FH_AO28
#endif
#if FH_AO_MaxPeripheralNumber > 28
#define FH_AO29
#endif
#if FH_AO_MaxPeripheralNumber > 29
#define FH_AO30
#endif
#if FH_AO_MaxPeripheralNumber > 30
#define FH_AO31
#endif
#if FH_AO_MaxPeripheralNumber > 31
#define FH_AO32
#endif
#if FH_AO_MaxPeripheralNumber > 32
#define FH_AO33
#endif
#if FH_AO_MaxPeripheralNumber > 33
#define FH_AO34
#endif
#if FH_AO_MaxPeripheralNumber > 34
#define FH_AO35
#endif
#if FH_AO_MaxPeripheralNumber > 35
#define FH_AO36
#endif
#if FH_AO_MaxPeripheralNumber > 36
#define FH_AO37
#endif
#if FH_AO_MaxPeripheralNumber > 37
#define FH_AO38
#endif
#if FH_AO_MaxPeripheralNumber > 38
#define FH_AO39
#endif
#if FH_AO_MaxPeripheralNumber > 39
#define FH_AO40
#endif
#if FH_AO_MaxPeripheralNumber > 40
#define FH_AO41
#endif
#if FH_AO_MaxPeripheralNumber > 41
#define FH_AO42
#endif
#if FH_AO_MaxPeripheralNumber > 42
#define FH_AO43
#endif
#if FH_AO_MaxPeripheralNumber > 43
#define FH_AO44
#endif
#if FH_AO_MaxPeripheralNumber > 44
#define FH_AO45
#endif
#if FH_AO_MaxPeripheralNumber > 45
#define FH_AO46
#endif
#if FH_AO_MaxPeripheralNumber > 46
#define FH_AO47
#endif
#if FH_AO_MaxPeripheralNumber > 47
#define FH_AO48
#endif
#if FH_AO_MaxPeripheralNumber > 48
#define FH_AO49
#endif
#if FH_AO_MaxPeripheralNumber > 49
#define FH_AO50
#endif
#if FH_AO_MaxPeripheralNumber > 50
#define FH_AO51
#endif
#if FH_AO_MaxPeripheralNumber > 51
#define FH_AO52
#endif
#if FH_AO_MaxPeripheralNumber > 52
#define FH_AO53
#endif
#if FH_AO_MaxPeripheralNumber > 53
#define FH_AO54
#endif
#if FH_AO_MaxPeripheralNumber > 54
#define FH_AO55
#endif
#if FH_AO_MaxPeripheralNumber > 55
#define FH_AO56
#endif
#if FH_AO_MaxPeripheralNumber > 56
#define FH_AO57
#endif
#if FH_AO_MaxPeripheralNumber > 57
#define FH_AO58
#endif
#if FH_AO_MaxPeripheralNumber > 58
#define FH_AO59
#endif
#if FH_AO_MaxPeripheralNumber > 59
#define FH_AO60
#endif
#if FH_AO_MaxPeripheralNumber > 60
#define FH_AO61
#endif
#if FH_AO_MaxPeripheralNumber > 61
#define FH_AO62
#endif
#if FH_AO_MaxPeripheralNumber > 62
#define FH_AO63
#endif
#if FH_AO_MaxPeripheralNumber > 63
#define FH_AO64
#endif

#if FH_AO_MaxPeripheralNumber > 0    // If at least one <b>FH_AO</b> (Analog Output) is defined

/*!
  <b>FH_AO_Init_FuncPtrModel</b> Function pointer definition
*/
typedef FH_ErrorInfo (*FH_AO_Init_FuncPtrModel) (FH_RFCommunication_Message* fh_RFCommunication_Message);

/*!
<b>FH_AO_SetStatus_FuncPtrModel</b> Function pointer definition
*/
typedef FH_ErrorInfo (*FH_AO_SetStatus_FuncPtrModel) (FH_RFCommunication_Message* fh_RFCommunication_Message);

/*!
  Different commands for <b>AO</b> (Analog Output) Function
*/
enum FH_AO_Commands
{
	FH_AO_Commands_Init         = 0,
	FH_AO_Commands_SetStatus    = 1,
};

/*!
  Minimum size of the <b>Data</b> part in the message frame (<b>FH_RFCommunication_Message</b>) for the <b>Init</b> command of <b>AO</b> Function, are defined here
*/
#define FH_AO_MinCommandSize_Init        		      1

/*!
  Minimum size of the <b>Data</b> part in the message frame (<b>FH_RFCommunication_Message</b>) for the <b>SetStatus</b> command of <b>AO</b> Function, are defined here
*/
#define FH_AO_MinCommandSize_SetStatus      		  5

/*!
  Different elements of the Data part in the message frame (<b>FH_RFCommunication_Message</b>) for the Init command of <b>AO</b> Function, are defined here
*/
enum FH_AO_Commandelements_Init
{
	AO_Init_PeripheralNumber   = 0,
};

/*!
  Different elements of the Data part in the message frame (<b>FH_RFCommunication_Message</b>) for the SetStatus command of <b>AO</b> Function, are defined here
*/
enum FH_AO_Commandelements_SetStatus
{
	AO_SetStatus_PeripheralNumber   = 0,
	AO_SetStatus_StatusByte4        = 1,    // Total 4 bytes as floating point
	AO_SetStatus_StatusByte3        = 2,
	AO_SetStatus_StatusByte2        = 3,
	AO_SetStatus_StatusByte1        = 4,
};

#endif

#endif
