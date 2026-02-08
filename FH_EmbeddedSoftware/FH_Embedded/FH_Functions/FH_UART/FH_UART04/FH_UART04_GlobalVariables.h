/**
  * @file
  * @brief
  *       <b>File Map:</b>\n
  *       <b>FH_Functions</b>, Section <b>FH_UART</b>, Peripheral <b>FH_UART04</b> (UART 04)\n
  *       (The <b>UART04 (UART 04)</b> could be any interested UART of the micro-controller on which <b>FH</b> source code is ported)\n
  *       Global variables and arrays of UART04 are defined here
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
#ifndef FH_UART04_GlobalVariables_H
#define FH_UART04_GlobalVariables_H

/* Includes ------------------------------------------------------------------*/
#include "../../../../FH_Embedded/FH_Root/FH_Perif/FH_UART/FH_UART_Configs/FH_UART_Configs.h"

#ifdef FH_UART04    // It is configurable in FH_UART_Configs.h

#if FH_UART_MaxPeripheralNumber > 0    // It is configurable in FH_DevicePeripherals.h

	extern volatile uint8_t FH_UART04_ReceiveBuf[];
	extern volatile uint16_t FH_UART04_ReceiveBufIndex;

	extern volatile uint8_t  FH_UART04_SharedDataBuf_8Bits [];
	extern volatile uint16_t FH_UART04_SharedDataBuf_16Bits[];
	extern volatile uint32_t FH_UART04_SharedDataBuf_32Bits[];

#endif

#endif

#endif
