/**
  * @file
  * @brief
  *       <b>File Map:</b>\n
  *       <b>FH_Root</b>, Section <b>FH_Perif</b>, <b>FH_CAN</b>, <b>FH_CAN_Configs</b>\n
  *       In this file, different configurations of <b>FH_CAN</b> could be set
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
#ifndef FH_CAN_Configs_H
#define FH_CAN_Configs_H

/* Includes ------------------------------------------------------------------*/
#include "../../../../../FH_Embedded/FH_Setup/FH_DevicePeripherals/FH_DevicePeripherals.h"
#include "../../../../../FH_Embedded/FH_Root/FH_General/FH_ErrorInfo/FH_ErrorInfo.h"
#include "../../../../../FH_Embedded/FH_Setup/FH_RFCommunication/FH_RFCommunication_GlobalVariables.h"

/*!
  <b>FH_CAN01 - FH_CAN08</b> shall be defined here to be utilized in different parts of the <b>FH</b> source code\n
  <b>FH_CAN_MaxPeripheralNumber</b> is the maximum number of the <b>FH_CAN</b>
*/

#if FH_CAN_MaxPeripheralNumber > 0
#define FH_CAN01
#endif
#if FH_CAN_MaxPeripheralNumber > 1
#define FH_CAN02
#endif
#if FH_CAN_MaxPeripheralNumber > 2
#define FH_CAN03
#endif
#if FH_CAN_MaxPeripheralNumber > 3
#define FH_CAN04
#endif
#if FH_CAN_MaxPeripheralNumber > 4
#define FH_CAN05
#endif
#if FH_CAN_MaxPeripheralNumber > 5
#define FH_CAN06
#endif
#if FH_CAN_MaxPeripheralNumber > 6
#define FH_CAN07
#endif
#if FH_CAN_MaxPeripheralNumber > 7
#define FH_CAN08
#endif

#if FH_CAN_MaxPeripheralNumber > 0    // If at least one <b>FH_CAN</b> is defined

/*!
  <b>FH_CAN_Init_FuncPtrModel</b> Function pointer definition
*/
typedef FH_ErrorInfo (*FH_CAN_Init_FuncPtrModel)                (FH_RFCommunication_Message* fh_RFCommunication_Message);

/*!
  <b>FH_CAN_Send_FuncPtrModel</b> Function pointer definition
*/
typedef FH_ErrorInfo (*FH_CAN_Send_FuncPtrModel)                (FH_RFCommunication_Message* fh_RFCommunication_Message);

/*!
  <b>FH_CAN_Receive_FuncPtrModel</b> Function pointer definition
*/
typedef FH_ErrorInfo (*FH_CAN_Receive_FuncPtrModel)             (FH_RFCommunication_Message* fh_RFCommunication_Message, uint8_t* FH_CAN_DataSize, uint8_t* FH_CAN_Data);

/*!
  <b>FH_CAN_ReceiveW_FuncPtrModel</b> Function pointer definition
*/
typedef FH_ErrorInfo (*FH_CAN_ReceiveW_FuncPtrModel)      (FH_RFCommunication_Message* fh_RFCommunication_Message, uint8_t* FH_CAN_DataSize, uint8_t* FH_CAN_Data);

/*!
  <b>FH_CAN_ResetRB_FuncPtrModel</b> Function pointer definition
*/
typedef FH_ErrorInfo (*FH_CAN_ResetRB_FuncPtrModel)     (FH_RFCommunication_Message* fh_RFCommunication_Message);

/*!
  <b>FH_CAN_SSD8_FuncPtrModel</b> Function pointer definition
*/
typedef FH_ErrorInfo (*FH_CAN_SSD8_FuncPtrModel)  (FH_RFCommunication_Message* fh_RFCommunication_Message);

/*!
  <b>FH_CAN_SSD16_FuncPtrModel</b> Function pointer definition
*/
typedef FH_ErrorInfo (*FH_CAN_SSD16_FuncPtrModel) (FH_RFCommunication_Message* fh_RFCommunication_Message);

/*!
  <b>FH_CAN_SSD32_FuncPtrModel</b> Function pointer definition
*/
typedef FH_ErrorInfo (*FH_CAN_SSD32_FuncPtrModel) (FH_RFCommunication_Message* fh_RFCommunication_Message);

/*!
  <b>FH_CAN_GSD8_FuncPtrModel</b> Function pointer definition
*/
typedef FH_ErrorInfo (*FH_CAN_GSD8_FuncPtrModel)  (FH_RFCommunication_Message* fh_RFCommunication_Message, uint8_t* FH_CAN_DataLength, uint8_t* FH_CAN_FH_CAN_Data);

/*!
  <b>FH_CAN_GSD16_FuncPtrModel</b> Function pointer definition
*/
typedef FH_ErrorInfo (*FH_CAN_GSD16_FuncPtrModel) (FH_RFCommunication_Message* fh_RFCommunication_Message, uint8_t* FH_CAN_DataLength, uint8_t* FH_CAN_FH_CAN_Data);

/*!
  <b>FH_CAN_GSD32_FuncPtrModel</b> Function pointer definition
*/
typedef FH_ErrorInfo (*FH_CAN_GSD32_FuncPtrModel) (FH_RFCommunication_Message* fh_RFCommunication_Message, uint8_t* FH_CAN_DataLength, uint8_t* FH_CAN_FH_CAN_Data);

/*!
  Different commands for <b>CAN</b> Function
*/
enum FH_CAN_Commands
{
	FH_CAN_Commands_Init        = 0,
	FH_CAN_Commands_Send        = 1,
	FH_CAN_Commands_Receive     = 2,
	FH_CAN_Commands_ReceiveW    = 3,
	FH_CAN_Commands_ResetRB     = 4,
	FH_CAN_Commands_SSD8        = 5,
	FH_CAN_Commands_SSD16       = 6,
	FH_CAN_Commands_SSD32       = 7,
	FH_CAN_Commands_GSD8        = 8,
	FH_CAN_Commands_GSD16       = 9,
	FH_CAN_Commands_GSD32       = 10,
};

/*!
  Minimum size of the <b>Data</b> part in the message frame (<b>FH_RFCommunication_Message</b>) for the <b>Init</b> command of <b>CAN</b> Function, are defined here
*/
#define FH_CAN_MinCommandSize_Init     1

/*!
  Minimum size of the <b>Data</b> part in the message frame (<b>FH_RFCommunication_Message</b>) for the <b>Send</b> command of <b>CAN</b> Function, are defined here
*/
#define FH_CAN_MinCommandSize_Send     3

/*!
  Minimum size of the <b>Data</b> part in the message frame (<b>FH_RFCommunication_Message</b>) for the <b>Receive</b> command of <b>CAN</b> Function, are defined here
*/
#define FH_CAN_MinCommandSize_Receive  1

/*!
  Minimum size of the <b>Data</b> part in the message frame (<b>FH_RFCommunication_Message</b>) for the <b>ReceiveW</b> command of <b>CAN</b> Function, are defined here
*/
#define FH_CAN_MinCommandSize_ReceiveW 6

/*!
  Minimum size of the <b>Data</b> part in the message frame (<b>FH_RFCommunication_Message</b>) for the <b>ResetRB</b> command of <b>CAN</b> Function, are defined here
*/
#define FH_CAN_MinCommandSize_ResetRB  1

/*!
  Minimum size of the <b>Data</b> part in the message frame (<b>FH_RFCommunication_Message</b>) for the <b>SSD8</b> command of <b>CAN</b> Function, are defined here
*/
#define FH_CAN_MinCommandSize_SSD8     3

/*!
  Minimum size of the <b>Data</b> part in the message frame (<b>FH_RFCommunication_Message</b>) for the <b>SSD16</b> command of <b>CAN</b> Function, are defined here
*/
#define FH_CAN_MinCommandSize_SSD16    4

/*!
  Minimum size of the <b>Data</b> part in the message frame (<b>FH_RFCommunication_Message</b>) for the <b>SSD32</b> command of <b>CAN</b> Function, are defined here
*/
#define FH_CAN_MinCommandSize_SSD32    6

/*!
  Minimum size of the <b>Data</b> part in the message frame (<b>FH_RFCommunication_Message</b>) for the <b>GSD8</b> command of <b>CAN</b> Function, are defined here
*/
#define FH_CAN_MinCommandSize_GSD8     1

/*!
  Minimum size of the <b>Data</b> part in the message frame (<b>FH_RFCommunication_Message</b>) for the <b>GSD16</b> command of <b>CAN</b> Function, are defined here
*/
#define FH_CAN_MinCommandSize_GSD16    1

/*!
  Minimum size of the <b>Data</b> part in the message frame (<b>FH_RFCommunication_Message</b>) for the <b>GSD32</b> command of <b>CAN</b> Function, are defined here
*/
#define FH_CAN_MinCommandSize_GSD32    1

/*!
  Different elements of the Data part in the message frame (<b>FH_RFCommunication_Message</b>) for the Init command of <b>CAN</b> Function, are defined here
*/
enum FH_CAN_Commandelements_Init
{
	CAN_Init_PeripheralNumber   = 0,
};

/*!
  Different elements of the Data part in the message frame (<b>FH_RFCommunication_Message</b>) for the Send command of <b>CAN</b> Function, are defined here
*/
enum FH_CAN_Commandelements_Send
{
	CAN_Send_PeripheralNumber   = 0,
	CAN_Send_DataLength         = 1,
	CAN_Send_Data               = 2
};

/*!
  Different elements of the Data part in the message frame (<b>FH_RFCommunication_Message</b>) for the Receive command of <b>CAN</b> Function, are defined here
*/
enum FH_CAN_Commandelements_Receive
{
	CAN_Receive_PeripheralNumber   = 0,
};

/*!
  Different elements of the Data part in the message frame (<b>FH_RFCommunication_Message</b>) for the ReceiveW command of <b>CAN</b> Function, are defined here
*/
enum FH_CAN_Commandelements_ReceiveW
{
	CAN_ReceiveW_PeripheralNumber   = 0,
	CAN_ReceiveW_ExpectedDataLength = 1,
	CAN_ReceiveW_MaxTimerCount      = 2,
};

/*!
  Different elements of the Data part in the message frame (<b>FH_RFCommunication_Message</b>) for the ResetRB command of <b>CAN</b> Function, are defined here
*/
enum FH_CAN_Commandelements_ResetRB
{
	CAN_ResetRB_PeripheralNumber   = 0,
};

/*!
  Different elements of the Data part in the message frame (<b>FH_RFCommunication_Message</b>) for the SSD8 command of <b>CAN</b> Function, are defined here
*/
enum FH_CAN_Commandelements_SSD8
{
	CAN_SSD8_PeripheralNumber   = 0,
	CAN_SSD8_SharedDataLength   = 1,
	CAN_SSD8_SharedData         = 2,
};

/*!
  Different elements of the Data part in the message frame (<b>FH_RFCommunication_Message</b>) for the SSD16 command of <b>CAN</b> Function, are defined here
*/
enum FH_CAN_Commandelements_SSD16
{
	CAN_SSD16_PeripheralNumber   = 0,
	CAN_SSD16_SharedDataLength   = 1,
	CAN_SSD16_SharedData         = 2,
};

/*!
  Different elements of the Data part in the message frame (<b>FH_RFCommunication_Message</b>) for the SSD32 command of <b>CAN</b> Function, are defined here
*/
enum FH_CAN_Commandelements_SSD32
{
	CAN_SSD32_PeripheralNumber   = 0,
	CAN_SSD32_SharedDataLength   = 1,
	CAN_SSD32_SharedData         = 2,
};

/*!
  Different elements of the Data part in the message frame (<b>FH_RFCommunication_Message</b>) for the GSD8 command of <b>CAN</b> Function, are defined here
*/
enum FH_CAN_Commandelements_GSD8
{
	CAN_GSD8_PeripheralNumber   = 0,
};

/*!
  Different elements of the Data part in the message frame (<b>FH_RFCommunication_Message</b>) for the GSD16 command of <b>CAN</b> Function, are defined here
*/
enum FH_CAN_Commandelements_GSD16
{
	CAN_GSD16_PeripheralNumber   = 0,
};

/*!
  Different elements of the Data part in the message frame (<b>FH_RFCommunication_Message</b>) for the GSD32 command of <b>CAN</b> Function, are defined here
*/
enum FH_CAN_Commandelements_GSD32
{
	CAN_GSD32_PeripheralNumber   = 0,
};

#endif

#endif
