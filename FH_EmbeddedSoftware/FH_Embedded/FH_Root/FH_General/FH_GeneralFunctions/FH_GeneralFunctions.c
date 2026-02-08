/**
  * @file
  * @brief
  *       <b>File Map:</b>\n
  *       <b>FH_Root</b>, Section <b>FH_General</b>, <b>FH_GeneralFunctions</b> \n
  *       All different possible general functions utilized in different parts of the code, go here\n
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
/* Includes ------------------------------------------------------------------*/
#include "../../../../FH_Embedded/FH_Root/FH_General/FH_GeneralFunctions/FH_GeneralFunctions.h"

/**
 * @brief This function converts two 8 bits data (uint8_t) to one 16 bits data (uint16_t)
 *
 * @param  fh_Uint8
 *         Pointer to the two 8 bits data (uint8_t)
 *
 * @return The one 16 bits data (uint16_t)
 *
 * @note
 * For this to happen, FH_Uint8Uint16 enumeration defined in <b>FH_GeneralFunctions.h</b> is utilized \n
 *

*/
uint16_t FH_ConvertUint8ToUint16(uint8_t* fh_Uint8)
{
	FH_Uint8Uint16 fh_Uint8Uint16;    // FH_Uint8Uint16 enumeration
	fh_Uint8Uint16.bytes[1] = fh_Uint8[0];
	fh_Uint8Uint16.bytes[0] = fh_Uint8[1];
    return fh_Uint8Uint16.value;
}

/**
 * @brief This function converts four 8 bits data (uint8_t) to one 32 bits data (uint32_t)
 *
 * @param  fh_Uint8
 *         Pointer to the four 8 bits data (uint8_t)
 *
 * @return The one 32 bits data (uint32_t)
 *
 * @note
 * For this to happen, FH_Uint8Uint32 enumeration defined in <b>FH_GeneralFunctions.h</b> is utilized \n
 *

*/
uint32_t FH_ConvertUint8ToUint32(uint8_t* fh_Uint8)
{
	FH_Uint8Uint32 fh_Uint8Uint32;    // FH_Uint8Uint32 enumeration
	fh_Uint8Uint32.bytes[3] = fh_Uint8[0];
	fh_Uint8Uint32.bytes[2] = fh_Uint8[1];
	fh_Uint8Uint32.bytes[1] = fh_Uint8[2];
	fh_Uint8Uint32.bytes[0] = fh_Uint8[3];
    return fh_Uint8Uint32.value;
}
