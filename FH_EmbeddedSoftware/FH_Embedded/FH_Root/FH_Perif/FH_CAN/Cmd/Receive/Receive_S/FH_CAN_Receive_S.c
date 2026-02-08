/**
  * @file
  * @brief
  *       <b>File Map:</b>\n
  *       <b>FH_Root</b>, Section <b>FH_Perif</b>, <b>FH_CAN</b> (Digital Output), <b>Cmd</b> (Command), <b>Receive</b>, <b>Receive_S</b> (Receive Set Address)\n
  *       Functions in this file, set the address of the defined <b>FH_Functions</b>, Section <b>FH_CAN</b> (CAN), <b>FH_CAN_Receive_CAN01-...</b> to an array of function pointers
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
#include "../../../../../../../FH_Embedded/FH_Root/FH_Perif/FH_CAN/Cmd/Receive/Receive_S/FH_CAN_Receive_S.h"

#include "../../../../../../../FH_Embedded/FH_Root/FH_General/FH_GeneralFunctions/FH_GeneralFunctions.h"

#ifdef FH_CAN01
#include "../../../../../../../FH_Embedded/FH_Functions/FH_CAN/FH_CAN01/FH_CAN01.h"
#endif
#ifdef FH_CAN02
#include "../../../../../../../FH_Embedded/FH_Functions/FH_CAN/FH_CAN02/FH_CAN02.h"
#endif
#ifdef FH_CAN03
#include "../../../../../../../FH_Embedded/FH_Functions/FH_CAN/FH_CAN03/FH_CAN03.h"
#endif
#ifdef FH_CAN04
#include "../../../../../../../FH_Embedded/FH_Functions/FH_CAN/FH_CAN04/FH_CAN04.h"
#endif
#ifdef FH_CAN05
#include "../../../../../../../FH_Embedded/FH_Functions/FH_CAN/FH_CAN05/FH_CAN05.h"
#endif
#ifdef FH_CAN06
#include "../../../../../../../FH_Embedded/FH_Functions/FH_CAN/FH_CAN06/FH_CAN06.h"
#endif
#ifdef FH_CAN07
#include "../../../../../../../FH_Embedded/FH_Functions/FH_CAN/FH_CAN07/FH_CAN07.h"
#endif
#ifdef FH_CAN08
#include "../../../../../../../FH_Embedded/FH_Functions/FH_CAN/FH_CAN08/FH_CAN08.h"
#endif

#if FH_CAN_MaxPeripheralNumber > 0    // It is configurable in FH_DevicePeripherals.h

/**
 * @brief This function sets the address of the defined <b>FH_Functions</b>, Section <b>FH_CAN</b> (CAN), <b>FH_CAN_Receive_CAN01-...</b> to an array of function pointers
 *
 * @param  FH_CAN_Receive_FuncPtr
 *         An array of function pointers with FH_CAN_Receive_FuncPtrModel model
 *
 * @return None
 *

*/
void FH_CAN_Receive_S(FH_CAN_Receive_FuncPtrModel *FH_CAN_Receive_FuncPtr)
{
	for (uint8_t i = 0; i < FH_CAN_MaxPeripheralNumber; i++)    // if FH_CAN_MaxPeripheralNumber > 0
	{
		FH_CAN_Receive_FuncPtr[i] = NULL_PTR;    // Initialization of the function pointers with null pointer to prevent pointing to undefined addresses
	}

	#ifdef FH_CAN01
	FH_CAN_Receive_FuncPtr[0] = FH_CAN_Receive_CAN01;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_CAN02
	FH_CAN_Receive_FuncPtr[1] = FH_CAN_Receive_CAN02;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_CAN03
	FH_CAN_Receive_FuncPtr[2] = FH_CAN_Receive_CAN03;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_CAN04
	FH_CAN_Receive_FuncPtr[3] = FH_CAN_Receive_CAN04;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_CAN05
	FH_CAN_Receive_FuncPtr[4] = FH_CAN_Receive_CAN05;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_CAN06
	FH_CAN_Receive_FuncPtr[5] = FH_CAN_Receive_CAN06;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_CAN07
	FH_CAN_Receive_FuncPtr[6] = FH_CAN_Receive_CAN07;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_CAN08
	FH_CAN_Receive_FuncPtr[7] = FH_CAN_Receive_CAN08;    // Set the function pointer address with the related function address
	#endif
}

#endif
