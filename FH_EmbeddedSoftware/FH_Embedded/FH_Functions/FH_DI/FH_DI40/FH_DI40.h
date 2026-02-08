/**
  * @file
  * @brief
  *       <b>File Map:</b>\n
  *       <b>FH_Functions</b>, Section <b>FH_DI</b> (Digital Input), Peripheral <b>FH_DI40</b> (Digital Input 40)\n
  *       (The <b>DI40 (Digital Input 40)</b> could be any interested digital Input of the micro-controller on which <b>FH</b> source code is ported)\n
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
#ifndef FH_DI40_H
#define FH_DI40_H

/* Includes ------------------------------------------------------------------*/
#include "../../../../FH_Embedded/FH_Root/FH_Perif/FH_DI/FH_DI_Configs/FH_DI_Configs.h"

#ifdef FH_DI40    // It is configurable in FH_DI_Configs.h

#if FH_DI_MaxPeripheralNumber > 0    // It is configurable in FH_DevicePeripherals.h

	FH_ErrorInfo FH_DI_Init_DI40 ();
	FH_ErrorInfo FH_DI_GetStatus_DI40 (uint8_t* Data);

#endif

#endif

#endif
