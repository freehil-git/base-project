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

/* Includes ------------------------------------------------------------------*/
#include "../../../../../../../FH_Embedded/FH_Root/FH_Perif/FH_UART/Cmd/GSD16/GSD16_S/FH_UART_GSD16_S.h"

#include "../../../../../../../FH_Embedded/FH_Root/FH_General/FH_GeneralFunctions/FH_GeneralFunctions.h"

#ifdef FH_UART01
#include "../../../../../../../FH_Embedded/FH_Functions/FH_UART/FH_UART01/FH_UART01.h"
#endif
#ifdef FH_UART02
#include "../../../../../../../FH_Embedded/FH_Functions/FH_UART/FH_UART02/FH_UART02.h"
#endif
#ifdef FH_UART03
#include "../../../../../../../FH_Embedded/FH_Functions/FH_UART/FH_UART03/FH_UART03.h"
#endif
#ifdef FH_UART04
#include "../../../../../../../FH_Embedded/FH_Functions/FH_UART/FH_UART04/FH_UART04.h"
#endif
#ifdef FH_UART05
#include "../../../../../../../FH_Embedded/FH_Functions/FH_UART/FH_UART05/FH_UART05.h"
#endif
#ifdef FH_UART06
#include "../../../../../../../FH_Embedded/FH_Functions/FH_UART/FH_UART06/FH_UART06.h"
#endif
#ifdef FH_UART07
#include "../../../../../../../FH_Embedded/FH_Functions/FH_UART/FH_UART07/FH_UART07.h"
#endif
#ifdef FH_UART08
#include "../../../../../../../FH_Embedded/FH_Functions/FH_UART/FH_UART08/FH_UART08.h"
#endif

#if FH_UART_MaxPeripheralNumber > 0    // It is configurable in FH_DevicePeripherals.h

/**
 * @brief This function sets the address of the defined <b>FH_Functions</b>, Section <b>FH_UART</b> (UART), <b>FH_UART_GSD16_UART01-...</b> to an array of function pointers
 *
 * @param  FH_UART_GSD16_FuncPtr
 *         An array of function pointers with FH_UART_GSD16_FuncPtrModel model
 *
 * @return None
 *

*/
void FH_UART_GSD16_S(FH_UART_GSD16_FuncPtrModel *FH_UART_GSD16_FuncPtr)
{
	for (uint8_t i = 0; i < FH_UART_MaxPeripheralNumber; i++)    // if FH_UART_MaxPeripheralNumber > 0
	{
		FH_UART_GSD16_FuncPtr[i] = NULL_PTR;    // Initialization of the function pointers with null pointer to prevent pointing to undefined addresses
	}

	#ifdef FH_UART01
	FH_UART_GSD16_FuncPtr[0] = FH_UART_GSD16_UART01;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_UART02
	FH_UART_GSD16_FuncPtr[1] = FH_UART_GSD16_UART02;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_UART03
	FH_UART_GSD16_FuncPtr[2] = FH_UART_GSD16_UART03;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_UART04
	FH_UART_GSD16_FuncPtr[3] = FH_UART_GSD16_UART04;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_UART05
	FH_UART_GSD16_FuncPtr[4] = FH_UART_GSD16_UART05;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_UART06
	FH_UART_GSD16_FuncPtr[5] = FH_UART_GSD16_UART06;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_UART07
	FH_UART_GSD16_FuncPtr[6] = FH_UART_GSD16_UART07;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_UART08
	FH_UART_GSD16_FuncPtr[7] = FH_UART_GSD16_UART08;    // Set the function pointer address with the related function address
	#endif
}

#endif
