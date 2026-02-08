/**
  * @file
  * @brief
  *       <b>File Map:</b>\n
  *       <b>FH_Root</b>, Section <b>FH_General</b>, <b>FH_GeneralFunctions</b> \n
  *       All different possible general defines, unions, structures , ... utilized in different parts of the code, go here\n
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
#ifndef FH_GeneralFunctions_H
#define FH_GeneralFunctions_H

/* Includes ------------------------------------------------------------------*/
#include "stdint.h"

/*!
    Null pointer to initialize different pointers in different parts of the code, if need be\n
*/
#define NULL_PTR ((void*)0)

/*!
    Union to convert two 8 bits data (uint8_t) to one 16 bits data (uint16_t) and vice verse
*/
typedef union
{
	/*!
	    Two 8 bits data (uint8_t)
	*/
	uint8_t  bytes[2];
	/*!
	    One 16 bits data (uint16_t)
	*/
	uint16_t value;
}FH_Uint8Uint16;

/*!
    Union to convert four 8 bits data (uint8_t) to one 32 bits data (uint32_t) and vice verse
*/
typedef union
{
	/*!
	    Four 8 bits data (uint8_t)
	*/
	uint8_t  bytes[4];
	/*!
	    One 32 bits data (uint32_t)
	*/
	uint32_t value;
}FH_Uint8Uint32;

/* Function Prototypes -----------------------------------------------------*/
uint16_t FH_ConvertUint8ToUint16(uint8_t* fh_Uint8);
uint32_t FH_ConvertUint8ToUint32(uint8_t* fh_Uint8);

#endif // FH_GeneralFunctions_H
