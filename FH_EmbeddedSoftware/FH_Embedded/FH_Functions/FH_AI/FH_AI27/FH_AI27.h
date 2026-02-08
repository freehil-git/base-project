/**
  * @file
  * @brief
  *       <b>File Map:</b>\n
  *       <b>FH_Functions</b>, Section <b>FH_AI</b> (Analog Input), Peripheral <b>FH_AI27</b> (Analog Input 27)\n
  *       (The <b>AI27 (Analog Input 27)</b> could be any interested Analog Input of the micro-controller on which <b>FH</b> source code is ported)\n
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
#ifndef FH_AI27_H
#define FH_AI27_H

/* Includes ------------------------------------------------------------------*/
#include "../../../../FH_Embedded/FH_Root/FH_Perif/FH_AI/FH_AI_Configs/FH_AI_Configs.h"
#include "../../../../FH_Embedded/FH_Setup/FH_RFCommunication/FH_RFCommunication_GlobalVariables.h"

#ifdef FH_AI27    // It is configurable in FH_AI_Configs.h

#if FH_AI_MaxPeripheralNumber > 0    // It is configurable in FH_DevicePeripherals.h

	FH_ErrorInfo FH_AI_Init_AI27 (FH_RFCommunication_Message* fh_RFCommunication_Message);
	FH_ErrorInfo FH_AI_GetStatus_AI27 (FH_RFCommunication_Message* fh_RFCommunication_Message, uint32_t* Data);

#endif

#endif

#endif
