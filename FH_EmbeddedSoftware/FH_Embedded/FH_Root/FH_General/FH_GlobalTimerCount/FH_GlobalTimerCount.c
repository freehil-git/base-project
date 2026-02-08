/**
  * @file
  * @brief
  *       <b>File Map:</b>\n
  *       <b>FH_Root</b>, Section <b>FH_General</b>, <b>FH_GlobalTimerCount</b> \n
  *       There are a diverse range of different situations where a precise timing is a necessity\n
  *       To have a general heart beat (1 mili-second) for all different parts of the code, a timer in the micro-controller on which <b>FH</b> source code is ported, shall be utilized\n
  *       <b>FH_GlobalTimeCounter</b> here shall be incremented every <b>1 mili-second</b> in an interested timer <b>ISR</b> (Interrupt Service Routine) by <b>FH</b> user\n
  *       For this to happen, <b>FH_GlobalTimerCount.h</b> shall be included in the interested timer <b>ISR</b> (Interrupt Service Routine) file
  *
  * @warning If <b>FH</b> user would not increment the <b>FH_GlobalTimeCounter</b> in a timer <b>ISR</b> (Interrupt Service Routine) every 1 mili-second, the related commands (which require timing) will have malfunction
  *
  * @attention <b>FH</b> user could left this file intact but shall include <b>FH_GlobalTimerCount.h</b> in the interested timer <b>ISR</b> (Interrupt Service Routine) file
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
/* Includes ------------------------------------------------------------------*/
#include "../../../../FH_Embedded/FH_Root/FH_General/FH_GlobalTimerCount/FH_GlobalTimerCount.h"

/*!
  There are a diverse range of different situations where a precise timing is a necessity\n
  To have a general heart beat (1 mili-second) for all different parts of the code, a timer in the micro-controller on which <b>FH</b> source code is ported, shall be utilized\n
  <b>FH_GlobalTimeCounter</b> here shall be incremented every <b>1 mili-second</b> in an interested timer <b>ISR</b> (Interrupt Service Routine) by <b>FH</b> user\n
  For this to happen, <b>FH_GlobalTimerCount.h</b> shall be included in the interested timer <b>ISR</b> (Interrupt Service Routine) file

  @warning If <b>FH</b> user would not increment the <b>FH_GlobalTimeCounter</b> in a timer <b>ISR</b> (Interrupt Service Routine) every 1 mili-second, the related commands (which require timing) will have malfunction
*/
volatile uint32_t FH_GlobalTimeCounter = 0;

/**
 * @brief This function resets the <b>FH_GlobalTimeCounter</b> if need be\n
 *        <b>FH_GlobalTimeCounter</b> here shall be incremented every <b>1 mili-second</b> in an interested timer <b>ISR</b> (Interrupt Service Routine) by <b>FH</b> user\n
 *        For this to happen, <b>FH_GlobalTimerCount.h</b> shall be included in the interested timer <b>ISR</b> (Interrupt Service Routine) file
 *
 * @param None
 *
 * @return None
 *
 * @note
 * Since the mere heart beat of the <b>FH</b> code is <b>FH_GlobalTimeCounter</b> and it is getting incremented every 1 mili-second, it is normally required to reset it to start a new time calculation
 *

*/
void FH_Reset_GlobalTimeCounter()
{
	FH_GlobalTimeCounter = 0;    // The mere heart beat of <b>FH</b> code is reset here
}
