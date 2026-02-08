/**
  * @file
  * @brief
  *       <b>File Map:</b>\n
  *       <b>FH_Root</b>, Section <b>FH_Perif</b>, <b>FH_UART</b>\n
  *       Functions in this file, handle RFCommunication (<b>RobotFramework</b> <b>C</b>ommunication) for all commands related to <b>UART</b>
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
#ifndef FH_UART_H
#define FH_UART_H

/* Includes ------------------------------------------------------------------*/
#include "../../../../FH_Embedded/FH_Root/FH_Perif/FH_UART/FH_UART_Configs/FH_UART_Configs.h"

#if FH_UART_MaxPeripheralNumber > 0    // It is configurable in FH_DevicePeripherals.h

/* Function Prototypes -----------------------------------------------------*/
FH_ErrorInfo FH_UART_RFCommunication         (FH_RFCommunication_Message* fh_RFCommunication_Message);
FH_ErrorInfo FH_UART_ProcessCommand_Init     (FH_RFCommunication_Message* fh_RFCommunication_Message);
FH_ErrorInfo FH_UART_ProcessCommand_Send     (FH_RFCommunication_Message* fh_RFCommunication_Message);
FH_ErrorInfo FH_UART_ProcessCommand_Receive  (FH_RFCommunication_Message* fh_RFCommunication_Message, uint8_t* FH_UART_ReceiveData, uint8_t* FH_UART_DataSize);
FH_ErrorInfo FH_UART_ProcessCommand_ReceiveW (FH_RFCommunication_Message* fh_RFCommunication_Message, uint8_t* FH_UART_ReceiveData, uint8_t* FH_UART_DataSize);
FH_ErrorInfo FH_UART_ProcessCommand_ResetRB  (FH_RFCommunication_Message* fh_RFCommunication_Message);
FH_ErrorInfo FH_UART_ProcessCommand_SSD8     (FH_RFCommunication_Message* fh_RFCommunication_Message);
FH_ErrorInfo FH_UART_ProcessCommand_SSD16    (FH_RFCommunication_Message* fh_RFCommunication_Message);
FH_ErrorInfo FH_UART_ProcessCommand_SSD32    (FH_RFCommunication_Message* fh_RFCommunication_Message);
FH_ErrorInfo FH_UART_ProcessCommand_GSD8     (FH_RFCommunication_Message* fh_RFCommunication_Message, uint8_t* FH_UART_DataLength, uint8_t* FH_UART_FH_UART_Data);
FH_ErrorInfo FH_UART_ProcessCommand_GSD16    (FH_RFCommunication_Message* fh_RFCommunication_Message, uint8_t* FH_UART_DataLength, uint8_t* FH_UART_FH_UART_Data);
FH_ErrorInfo FH_UART_ProcessCommand_GSD32    (FH_RFCommunication_Message* fh_RFCommunication_Message, uint8_t* FH_UART_DataLength, uint8_t* FH_UART_FH_UART_Data);

#endif

#endif
