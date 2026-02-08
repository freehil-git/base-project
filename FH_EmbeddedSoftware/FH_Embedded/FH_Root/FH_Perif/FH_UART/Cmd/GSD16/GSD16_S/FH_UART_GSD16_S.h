/**
  * @file
  * @brief
  *       <b>File Map:</b>\n
  *       <b>FH_Root</b>, Section <b>FH_Perif</b>, <b>FH_UART</b> (Digital Output), <b>Cmd</b> (Command), <b>GSD16</b>, <b>GSD16_S</b> (Get Shared Data 16 Set Address)\n
  *       Functions in this file, set the address of the defined <b>FH_Functions</b>, Section <b>FH_UART</b> (UART), <b>FH_UART_GSD16_UART01-...</b> to an array of function pointers
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
#ifndef GSD16_S_H
#define GSD16_S_H

/* Includes ------------------------------------------------------------------*/
#include "../../../../../../../FH_Embedded/FH_Root/FH_Perif/FH_UART/FH_UART_Configs/FH_UART_Configs.h"

#if FH_UART_MaxPeripheralNumber > 0    // It is configurable in FH_DevicePeripherals.h

/* Function Prototypes -----------------------------------------------------*/
void FH_UART_GSD16_S(FH_UART_GSD16_FuncPtrModel *FH_UART_GSD16_FuncPtr);

#endif

#endif
