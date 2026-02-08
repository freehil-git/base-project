/**
  * @file
  * @brief
  *       <b>File Map:</b>\n
  *       <b>FH_Functions</b>, Section <b>FH_PWMI</b> (PWM Input), Peripheral <b>FH_PWMI04</b> (PWM Input 04)\n
  *       (The <b>PWMI04 (PWM Input 04)</b> could be any interested PWM Input of the micro-controller on which <b>FH</b> source code is ported)\n
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
#ifndef FH_PWMI04_H
#define FH_PWMI04_H

/* Includes ------------------------------------------------------------------*/
#include "../../../../FH_Embedded/FH_Root/FH_Perif/FH_PWMI/FH_PWMI_Configs/FH_PWMI_Configs.h"
#include "../../../../FH_Embedded/FH_Setup/FH_RFCommunication/FH_RFCommunication_GlobalVariables.h"

#ifdef FH_PWMI04    // It is configurable in FH_PWMI_Configs.h

#if FH_PWMI_MaxPeripheralNumber > 0    // It is configurable in FH_DevicePeripherals.h

    FH_ErrorInfo FH_PWMI_Init_PWMI04 (FH_RFCommunication_Message* fh_RFCommunication_Message);
	FH_ErrorInfo FH_PWMI_GetStatus_PWMI04(FH_RFCommunication_Message* fh_RFCommunication_Message, uint32_t* fh_Frequency, uint8_t* fh_DutyCycle);

#endif

#endif

#endif
