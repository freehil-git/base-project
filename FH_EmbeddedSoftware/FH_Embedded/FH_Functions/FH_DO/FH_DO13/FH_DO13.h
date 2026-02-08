/**
  * @file
  * @brief
  *       <b>File Map:</b>\n
  *       <b>FH_Functions</b>, Section <b>FH_DO</b> (Digital Output), Peripheral <b>FH_DO13</b> (Digital Output 13)\n
  *       (The <b>DO13 (Digital Output 13)</b> could be any interested digital output of the micro-controller on which <b>FH</b> source code is ported)\n
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
#ifndef FH_DO13_H
#define FH_DO13_H

/* Includes ------------------------------------------------------------------*/
#include "../../../../FH_Embedded/FH_Root/FH_Perif/FH_DO/FH_DO_Configs/FH_DO_Configs.h"

#ifdef FH_DO13    // It is configurable in FH_DO_Configs.h

#if FH_DO_MaxPeripheralNumber > 0    // It is configurable in FH_DevicePeripherals.h

	FH_ErrorInfo FH_DO_Init_DO13 ();
	FH_ErrorInfo FH_DO_SetStatus_DO13 (uint8_t Status);

#endif

#endif

#endif
