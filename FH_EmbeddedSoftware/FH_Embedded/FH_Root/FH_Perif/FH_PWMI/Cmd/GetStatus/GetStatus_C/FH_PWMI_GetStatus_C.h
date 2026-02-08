/**
  * @file
  * @brief
  *       <b>File Map:</b>\n
  *       <b>FH_Root</b>, Section <b>FH_Perif</b>, <b>FH_PWMI</b> (PWM Input), <b>Cmd</b> (Command), <b>GetStatus</b>, <b>GetStatus_C</b> (GetStatus Call)\n
  *       Functions in this file, Call the related function in <b>FH_Functions</b>, Section <b>FH_PWMI</b> (PWM Input) according to the first parameter of the Data in the message frame
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
#ifndef FH_PWMI_GetStatus_R_H
#define FH_PWMI_GetStatus_R_H

/* Includes ------------------------------------------------------------------*/
#include "../../../../../../../FH_Embedded/FH_Root/FH_Perif/FH_PWMI/FH_PWMI_Configs/FH_PWMI_Configs.h"

#if FH_PWMI_MaxPeripheralNumber > 0    // It is configurable in FH_DevicePeripherals.h

/* Function Prototypes -----------------------------------------------------*/
FH_ErrorInfo FH_PWMI_GetStatus_C (FH_RFCommunication_Message* fh_RFCommunication_Message, uint32_t* fH_PWMI_Frequecncy, uint8_t* fH_PWMI_DutyCycle, FH_PWMI_GetStatus_FuncPtrModel *fH_PWMI_GetStatus_FuncPtr);

#endif

#endif
