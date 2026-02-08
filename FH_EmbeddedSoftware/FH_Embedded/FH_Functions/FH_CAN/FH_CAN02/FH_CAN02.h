/**
  * @file
  * @brief
  *       <b>File Map:</b>\n
  *       <b>FH_Functions</b>, Section <b>FH_CAN</b> (CAN), Peripheral <b>FH_CAN02</b> (CAN 02)\n
  *       (The <b>CAN02 (CAN 02)</b> could be any interested CAN of the micro-controller on which <b>FH</b> source code is ported)\n
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
#ifndef FH_CAN02_H
#define FH_CAN02_H

/* Includes ------------------------------------------------------------------*/
#include "../../../../FH_Embedded/FH_Root/FH_Perif/FH_CAN/FH_CAN_Configs/FH_CAN_Configs.h"
#include "../../../../FH_Embedded/FH_Setup/FH_RFCommunication/FH_RFCommunication_GlobalVariables.h"

#ifdef FH_CAN02    // It is configurable in FH_CAN_Configs.h

#if FH_CAN_MaxPeripheralNumber > 0    // It is configurable in FH_DevicePeripherals.h

/* Function Prototypes -----------------------------------------------------*/
FH_ErrorInfo FH_CAN_Init_CAN02 (FH_RFCommunication_Message* fh_RFCommunication_Message);
FH_ErrorInfo FH_CAN_Send_CAN02 (FH_RFCommunication_Message* fh_RFCommunication_Message);
FH_ErrorInfo FH_CAN_Receive_CAN02 (FH_RFCommunication_Message* fh_RFCommunication_Message, uint8_t* FH_DataSize, uint8_t* FH_Data);
FH_ErrorInfo FH_CAN_ReceiveW_CAN02 (FH_RFCommunication_Message* fh_RFCommunication_Message, uint8_t* FH_DataSize, uint8_t* FH_Data);
FH_ErrorInfo FH_CAN_ResetRB_CAN02 (FH_RFCommunication_Message* fh_RFCommunication_Message);
FH_ErrorInfo FH_CAN_SSD8_CAN02  (FH_RFCommunication_Message* fh_RFCommunication_Message);
FH_ErrorInfo FH_CAN_SSD16_CAN02 (FH_RFCommunication_Message* fh_RFCommunication_Message);
FH_ErrorInfo FH_CAN_SSD32_CAN02 (FH_RFCommunication_Message* fh_RFCommunication_Message);
FH_ErrorInfo FH_CAN_GSD8_CAN02  (FH_RFCommunication_Message* fh_RFCommunication_Message, uint8_t* SharedDataLength, uint8_t* SharedData);
FH_ErrorInfo FH_CAN_GSD16_CAN02 (FH_RFCommunication_Message* fh_RFCommunication_Message, uint8_t* SharedDataLength, uint8_t* SharedData);
FH_ErrorInfo FH_CAN_GSD32_CAN02 (FH_RFCommunication_Message* fh_RFCommunication_Message, uint8_t* SharedDataLength, uint8_t* SharedData);

#endif

#endif

#endif
