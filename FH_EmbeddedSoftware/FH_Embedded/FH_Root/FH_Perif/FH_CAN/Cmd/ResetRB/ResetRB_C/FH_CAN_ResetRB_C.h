/**
  * @file
  * @brief
  *       <b>File Map:</b>\n
  *       <b>FH_Root</b>, Section <b>FH_Perif</b>, <b>FH_CAN</b>, <b>Cmd</b> (Command), <b>ResetRB</b>, <b>ResetRB_C</b> (ResetRB Call)\n
  *       Functions in this file, Call the related function in <b>FH_Functions</b>, Section <b>FH_CAN</b> according to the first parameter of the Data in the message frame
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
#ifndef FH_CAN_ResetRB_R_H
#define FH_CAN_ResetRB_R_H

/* Includes ------------------------------------------------------------------*/
#include "../../../../../../../FH_Embedded/FH_Root/FH_Perif/FH_CAN/FH_CAN_Configs/FH_CAN_Configs.h"

#if FH_CAN_MaxPeripheralNumber > 0    // It is configurable in FH_DevicePeripherals.h

/* Function Prototypes -----------------------------------------------------*/
FH_ErrorInfo FH_CAN_ResetRB_C (FH_RFCommunication_Message* fh_RFCommunication_Message, FH_CAN_ResetRB_FuncPtrModel *fH_CAN_ResetRB_FuncPtr);

#endif

#endif
