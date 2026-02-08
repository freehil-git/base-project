/**
  * @file
  * @brief
  *       <b>File Map:</b>\n
  *       <b>FH_Functions</b>, Section <b>FH_CAN</b> (CAN), Peripheral <b>FH_CAN03</b> (CAN 03)\n
  *       (The <b>CAN03 (CAN 03)</b> could be any interested CAN of the micro-controller on which <b>FH</b> source code is ported)\n
  *       Global variables and arrays of CAN03 are defined here
  *       This header file could be included whenever interested by <b>FH user</b>
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
#ifndef FH_CAN03_GlobalVariables_H
#define FH_CAN03_GlobalVariables_H

/* Includes ------------------------------------------------------------------*/
#include "../../../../FH_Embedded/FH_Root/FH_Perif/FH_CAN/FH_CAN_Configs/FH_CAN_Configs.h"

#ifdef FH_CAN03    // It is configurable in FH_CAN_Configs.h

#if FH_CAN_MaxPeripheralNumber > 0    // It is configurable in FH_DevicePeripherals.h

	extern volatile uint8_t FH_CAN03_ReceiveBuf[];
	extern volatile uint16_t FH_CAN03_ReceiveBufIndex;

	extern volatile uint8_t  FH_CAN03_SharedDataBuf_8Bits [];
	extern volatile uint16_t FH_CAN03_SharedDataBuf_16Bits[];
	extern volatile uint32_t FH_CAN03_SharedDataBuf_32Bits[];

#endif

#endif

#endif
