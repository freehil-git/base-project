/**
  * @file
  * @brief
  *       <b>File Map:</b>\n
  *       <b>FH_Functions</b>, Section <b>FH_UART</b>, Peripheral <b>FH_UART06</b> (UART 06)\n
  *       (The <b>UART06 (UART 06)</b> could be any interested UART of the micro-controller on which <b>FH</b> source code is ported)\n
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
#ifndef FH_UART06_H
#define FH_UART06_H

/* Includes ------------------------------------------------------------------*/
#include "../../../../FH_Embedded/FH_Root/FH_Perif/FH_UART/FH_UART_Configs/FH_UART_Configs.h"
#include "../../../../FH_Embedded/FH_Setup/FH_RFCommunication/FH_RFCommunication_GlobalVariables.h"

#ifdef FH_UART06    // It is configurable in FH_UART_Configs.h

#if FH_UART_MaxPeripheralNumber > 0    // It is configurable in FH_DevicePeripherals.h

/* Function Prototypes -----------------------------------------------------*/
FH_ErrorInfo FH_UART_Init_UART06 (FH_RFCommunication_Message* fh_RFCommunication_Message);
FH_ErrorInfo FH_UART_Send_UART06 (FH_RFCommunication_Message* fh_RFCommunication_Message);
FH_ErrorInfo FH_UART_Receive_UART06 (FH_RFCommunication_Message* fh_RFCommunication_Message, uint8_t* FH_DataSize, uint8_t* FH_Data);
FH_ErrorInfo FH_UART_ReceiveW_UART06 (FH_RFCommunication_Message* fh_RFCommunication_Message, uint8_t* FH_DataSize, uint8_t* FH_Data);
FH_ErrorInfo FH_UART_ResetRB_UART06 (FH_RFCommunication_Message* fh_RFCommunication_Message);
FH_ErrorInfo FH_UART_SSD8_UART06  (FH_RFCommunication_Message* fh_RFCommunication_Message);
FH_ErrorInfo FH_UART_SSD16_UART06 (FH_RFCommunication_Message* fh_RFCommunication_Message);
FH_ErrorInfo FH_UART_SSD32_UART06 (FH_RFCommunication_Message* fh_RFCommunication_Message);
FH_ErrorInfo FH_UART_GSD8_UART06  (FH_RFCommunication_Message* fh_RFCommunication_Message, uint8_t* SharedDataLength, uint8_t* SharedData);
FH_ErrorInfo FH_UART_GSD16_UART06 (FH_RFCommunication_Message* fh_RFCommunication_Message, uint8_t* SharedDataLength, uint8_t* SharedData);
FH_ErrorInfo FH_UART_GSD32_UART06 (FH_RFCommunication_Message* fh_RFCommunication_Message, uint8_t* SharedDataLength, uint8_t* SharedData);

#endif

#endif

#endif
