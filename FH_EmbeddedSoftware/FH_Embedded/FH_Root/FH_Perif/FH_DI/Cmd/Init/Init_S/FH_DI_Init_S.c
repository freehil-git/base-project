/**
  * @file
  * @brief
  *       <b>File Map:</b>\n
  *       <b>FH_Root</b>, Section <b>FH_Perif</b>, <b>FH_DI</b> (Digital Input), <b>Cmd</b> (Command), <b>Init</b>, <b>Init_S</b> (Init Set Address)\n
  *       Functions in this file, set the address of the defined <b>FH_Functions</b>, Section <b>FH_DI</b> (Digital Input), <b>FH_DI_Init_DI01-...</b> to an array of function pointers
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
#include "../../../../../../../FH_Embedded/FH_Root/FH_Perif/FH_DI/Cmd/Init/Init_S/FH_DI_Init_S.h"

#include "../../../../../../../FH_Embedded/FH_Root/FH_General/FH_GeneralFunctions/FH_GeneralFunctions.h"

#ifdef FH_DI01
#include "../../../../../../../FH_Embedded/FH_Functions/FH_DI/FH_DI01/FH_DI01.h"
#endif
#ifdef FH_DI02
#include "../../../../../../../FH_Embedded/FH_Functions/FH_DI/FH_DI02/FH_DI02.h"
#endif
#ifdef FH_DI03
#include "../../../../../../../FH_Embedded/FH_Functions/FH_DI/FH_DI03/FH_DI03.h"
#endif
#ifdef FH_DI04
#include "../../../../../../../FH_Embedded/FH_Functions/FH_DI/FH_DI04/FH_DI04.h"
#endif
#ifdef FH_DI05
#include "../../../../../../../FH_Embedded/FH_Functions/FH_DI/FH_DI05/FH_DI05.h"
#endif
#ifdef FH_DI06
#include "../../../../../../../FH_Embedded/FH_Functions/FH_DI/FH_DI06/FH_DI06.h"
#endif
#ifdef FH_DI07
#include "../../../../../../../FH_Embedded/FH_Functions/FH_DI/FH_DI07/FH_DI07.h"
#endif
#ifdef FH_DI08
#include "../../../../../../../FH_Embedded/FH_Functions/FH_DI/FH_DI08/FH_DI08.h"
#endif
#ifdef FH_DI09
#include "../../../../../../../FH_Embedded/FH_Functions/FH_DI/FH_DI09/FH_DI09.h"
#endif
#ifdef FH_DI10
#include "../../../../../../../FH_Embedded/FH_Functions/FH_DI/FH_DI10/FH_DI10.h"
#endif
#ifdef FH_DI11
#include "../../../../../../../FH_Embedded/FH_Functions/FH_DI/FH_DI11/FH_DI11.h"
#endif
#ifdef FH_DI12
#include "../../../../../../../FH_Embedded/FH_Functions/FH_DI/FH_DI12/FH_DI12.h"
#endif
#ifdef FH_DI13
#include "../../../../../../../FH_Embedded/FH_Functions/FH_DI/FH_DI13/FH_DI13.h"
#endif
#ifdef FH_DI14
#include "../../../../../../../FH_Embedded/FH_Functions/FH_DI/FH_DI14/FH_DI14.h"
#endif
#ifdef FH_DI15
#include "../../../../../../../FH_Embedded/FH_Functions/FH_DI/FH_DI15/FH_DI15.h"
#endif
#ifdef FH_DI16
#include "../../../../../../../FH_Embedded/FH_Functions/FH_DI/FH_DI16/FH_DI16.h"
#endif
#ifdef FH_DI17
#include "../../../../../../../FH_Embedded/FH_Functions/FH_DI/FH_DI17/FH_DI17.h"
#endif
#ifdef FH_DI18
#include "../../../../../../../FH_Embedded/FH_Functions/FH_DI/FH_DI18/FH_DI18.h"
#endif
#ifdef FH_DI19
#include "../../../../../../../FH_Embedded/FH_Functions/FH_DI/FH_DI19/FH_DI19.h"
#endif
#ifdef FH_DI20
#include "../../../../../../../FH_Embedded/FH_Functions/FH_DI/FH_DI20/FH_DI20.h"
#endif
#ifdef FH_DI21
#include "../../../../../../../FH_Embedded/FH_Functions/FH_DI/FH_DI21/FH_DI21.h"
#endif
#ifdef FH_DI22
#include "../../../../../../../FH_Embedded/FH_Functions/FH_DI/FH_DI22/FH_DI22.h"
#endif
#ifdef FH_DI23
#include "../../../../../../../FH_Embedded/FH_Functions/FH_DI/FH_DI23/FH_DI23.h"
#endif
#ifdef FH_DI24
#include "../../../../../../../FH_Embedded/FH_Functions/FH_DI/FH_DI24/FH_DI24.h"
#endif
#ifdef FH_DI25
#include "../../../../../../../FH_Embedded/FH_Functions/FH_DI/FH_DI25/FH_DI25.h"
#endif
#ifdef FH_DI26
#include "../../../../../../../FH_Embedded/FH_Functions/FH_DI/FH_DI26/FH_DI26.h"
#endif
#ifdef FH_DI27
#include "../../../../../../../FH_Embedded/FH_Functions/FH_DI/FH_DI27/FH_DI27.h"
#endif
#ifdef FH_DI28
#include "../../../../../../../FH_Embedded/FH_Functions/FH_DI/FH_DI28/FH_DI28.h"
#endif
#ifdef FH_DI29
#include "../../../../../../../FH_Embedded/FH_Functions/FH_DI/FH_DI29/FH_DI29.h"
#endif
#ifdef FH_DI30
#include "../../../../../../../FH_Embedded/FH_Functions/FH_DI/FH_DI30/FH_DI30.h"
#endif
#ifdef FH_DI31
#include "../../../../../../../FH_Embedded/FH_Functions/FH_DI/FH_DI31/FH_DI31.h"
#endif
#ifdef FH_DI32
#include "../../../../../../../FH_Embedded/FH_Functions/FH_DI/FH_DI32/FH_DI32.h"
#endif
#ifdef FH_DI33
#include "../../../../../../../FH_Embedded/FH_Functions/FH_DI/FH_DI33/FH_DI33.h"
#endif
#ifdef FH_DI34
#include "../../../../../../../FH_Embedded/FH_Functions/FH_DI/FH_DI34/FH_DI34.h"
#endif
#ifdef FH_DI35
#include "../../../../../../../FH_Embedded/FH_Functions/FH_DI/FH_DI35/FH_DI35.h"
#endif
#ifdef FH_DI36
#include "../../../../../../../FH_Embedded/FH_Functions/FH_DI/FH_DI36/FH_DI36.h"
#endif
#ifdef FH_DI37
#include "../../../../../../../FH_Embedded/FH_Functions/FH_DI/FH_DI37/FH_DI37.h"
#endif
#ifdef FH_DI38
#include "../../../../../../../FH_Embedded/FH_Functions/FH_DI/FH_DI38/FH_DI38.h"
#endif
#ifdef FH_DI39
#include "../../../../../../../FH_Embedded/FH_Functions/FH_DI/FH_DI39/FH_DI39.h"
#endif
#ifdef FH_DI40
#include "../../../../../../../FH_Embedded/FH_Functions/FH_DI/FH_DI40/FH_DI40.h"
#endif
#ifdef FH_DI41
#include "../../../../../../../FH_Embedded/FH_Functions/FH_DI/FH_DI41/FH_DI41.h"
#endif
#ifdef FH_DI42
#include "../../../../../../../FH_Embedded/FH_Functions/FH_DI/FH_DI42/FH_DI42.h"
#endif
#ifdef FH_DI43
#include "../../../../../../../FH_Embedded/FH_Functions/FH_DI/FH_DI43/FH_DI43.h"
#endif
#ifdef FH_DI44
#include "../../../../../../../FH_Embedded/FH_Functions/FH_DI/FH_DI44/FH_DI44.h"
#endif
#ifdef FH_DI45
#include "../../../../../../../FH_Embedded/FH_Functions/FH_DI/FH_DI45/FH_DI45.h"
#endif
#ifdef FH_DI46
#include "../../../../../../../FH_Embedded/FH_Functions/FH_DI/FH_DI46/FH_DI46.h"
#endif
#ifdef FH_DI47
#include "../../../../../../../FH_Embedded/FH_Functions/FH_DI/FH_DI47/FH_DI47.h"
#endif
#ifdef FH_DI48
#include "../../../../../../../FH_Embedded/FH_Functions/FH_DI/FH_DI48/FH_DI48.h"
#endif
#ifdef FH_DI49
#include "../../../../../../../FH_Embedded/FH_Functions/FH_DI/FH_DI49/FH_DI49.h"
#endif
#ifdef FH_DI50
#include "../../../../../../../FH_Embedded/FH_Functions/FH_DI/FH_DI50/FH_DI50.h"
#endif
#ifdef FH_DI51
#include "../../../../../../../FH_Embedded/FH_Functions/FH_DI/FH_DI51/FH_DI51.h"
#endif
#ifdef FH_DI52
#include "../../../../../../../FH_Embedded/FH_Functions/FH_DI/FH_DI52/FH_DI52.h"
#endif
#ifdef FH_DI53
#include "../../../../../../../FH_Embedded/FH_Functions/FH_DI/FH_DI53/FH_DI53.h"
#endif
#ifdef FH_DI54
#include "../../../../../../../FH_Embedded/FH_Functions/FH_DI/FH_DI54/FH_DI54.h"
#endif
#ifdef FH_DI55
#include "../../../../../../../FH_Embedded/FH_Functions/FH_DI/FH_DI55/FH_DI55.h"
#endif
#ifdef FH_DI56
#include "../../../../../../../FH_Embedded/FH_Functions/FH_DI/FH_DI56/FH_DI56.h"
#endif
#ifdef FH_DI57
#include "../../../../../../../FH_Embedded/FH_Functions/FH_DI/FH_DI57/FH_DI57.h"
#endif
#ifdef FH_DI58
#include "../../../../../../../FH_Embedded/FH_Functions/FH_DI/FH_DI58/FH_DI58.h"
#endif
#ifdef FH_DI59
#include "../../../../../../../FH_Embedded/FH_Functions/FH_DI/FH_DI59/FH_DI59.h"
#endif
#ifdef FH_DI60
#include "../../../../../../../FH_Embedded/FH_Functions/FH_DI/FH_DI60/FH_DI60.h"
#endif
#ifdef FH_DI61
#include "../../../../../../../FH_Embedded/FH_Functions/FH_DI/FH_DI61/FH_DI61.h"
#endif
#ifdef FH_DI62
#include "../../../../../../../FH_Embedded/FH_Functions/FH_DI/FH_DI62/FH_DI62.h"
#endif
#ifdef FH_DI63
#include "../../../../../../../FH_Embedded/FH_Functions/FH_DI/FH_DI63/FH_DI63.h"
#endif
#ifdef FH_DI64
#include "../../../../../../../FH_Embedded/FH_Functions/FH_DI/FH_DI64/FH_DI64.h"
#endif

#if FH_DI_MaxPeripheralNumber > 0    // It is configurable in FH_DevicePeripherals.h

/**
 * @brief This function sets the address of the defined <b>FH_Functions</b>, Section <b>FH_DI</b> (Digital Input), <b>FH_DI_Init_DI01-...</b> to an array of function pointers
 *
 * @param  FH_DI_Init_FuncPtr
 *         An array of function pointers with FH_DI_Init_FuncPtrModel model
 *
 * @return None
 *

*/
void FH_DI_Init_S(FH_DI_Init_FuncPtrModel *FH_DI_Init_FuncPtr)
{
	for (uint8_t i = 0; i < FH_DI_MaxPeripheralNumber; i++)    // if FH_DI_MaxPeripheralNumber > 0
	{
		FH_DI_Init_FuncPtr[i] = NULL_PTR;    // Initialization of the function pointers with null pointer to prevent pointing to undefined addresses
	}

	#ifdef FH_DI01
	FH_DI_Init_FuncPtr[0] = FH_DI_Init_DI01;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_DI02
	FH_DI_Init_FuncPtr[1] = FH_DI_Init_DI02;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_DI03
	FH_DI_Init_FuncPtr[2] = FH_DI_Init_DI03;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_DI04
	FH_DI_Init_FuncPtr[3] = FH_DI_Init_DI04;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_DI05
	FH_DI_Init_FuncPtr[4] = FH_DI_Init_DI05;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_DI06
	FH_DI_Init_FuncPtr[5] = FH_DI_Init_DI06;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_DI07
	FH_DI_Init_FuncPtr[6] = FH_DI_Init_DI07;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_DI08
	FH_DI_Init_FuncPtr[7] = FH_DI_Init_DI08;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_DI09
	FH_DI_Init_FuncPtr[8] = FH_DI_Init_DI09;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_DI10
	FH_DI_Init_FuncPtr[9] = FH_DI_Init_DI10;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_DI11
	FH_DI_Init_FuncPtr[10] = FH_DI_Init_DI11;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_DI12
	FH_DI_Init_FuncPtr[11] = FH_DI_Init_DI12;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_DI13
	FH_DI_Init_FuncPtr[12] = FH_DI_Init_DI13;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_DI14
	FH_DI_Init_FuncPtr[13] = FH_DI_Init_DI14;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_DI15
	FH_DI_Init_FuncPtr[14] = FH_DI_Init_DI15;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_DI16
	FH_DI_Init_FuncPtr[15] = FH_DI_Init_DI16;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_DI17
	FH_DI_Init_FuncPtr[16] = FH_DI_Init_DI17;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_DI18
	FH_DI_Init_FuncPtr[17] = FH_DI_Init_DI18;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_DI19
	FH_DI_Init_FuncPtr[18] = FH_DI_Init_DI19;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_DI20
	FH_DI_Init_FuncPtr[19] = FH_DI_Init_DI20;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_DI21
	FH_DI_Init_FuncPtr[20] = FH_DI_Init_DI21;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_DI22
	FH_DI_Init_FuncPtr[21] = FH_DI_Init_DI22;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_DI23
	FH_DI_Init_FuncPtr[22] = FH_DI_Init_DI23;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_DI24
	FH_DI_Init_FuncPtr[23] = FH_DI_Init_DI24;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_DI25
	FH_DI_Init_FuncPtr[24] = FH_DI_Init_DI25;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_DI26
	FH_DI_Init_FuncPtr[25] = FH_DI_Init_DI26;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_DI27
	FH_DI_Init_FuncPtr[26] = FH_DI_Init_DI27;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_DI28
	FH_DI_Init_FuncPtr[27] = FH_DI_Init_DI28;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_DI29
	FH_DI_Init_FuncPtr[28] = FH_DI_Init_DI29;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_DI30
	FH_DI_Init_FuncPtr[29] = FH_DI_Init_DI30;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_DI31
	FH_DI_Init_FuncPtr[30] = FH_DI_Init_DI31;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_DI32
	FH_DI_Init_FuncPtr[31] = FH_DI_Init_DI32;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_DI33
	FH_DI_Init_FuncPtr[32] = FH_DI_Init_DI33;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_DI34
	FH_DI_Init_FuncPtr[33] = FH_DI_Init_DI34;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_DI35
	FH_DI_Init_FuncPtr[34] = FH_DI_Init_DI35;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_DI36
	FH_DI_Init_FuncPtr[35] = FH_DI_Init_DI36;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_DI37
	FH_DI_Init_FuncPtr[36] = FH_DI_Init_DI37;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_DI38
	FH_DI_Init_FuncPtr[37] = FH_DI_Init_DI38;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_DI39
	FH_DI_Init_FuncPtr[38] = FH_DI_Init_DI39;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_DI40
	FH_DI_Init_FuncPtr[39] = FH_DI_Init_DI40;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_DI41
	FH_DI_Init_FuncPtr[40] = FH_DI_Init_DI41;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_DI42
	FH_DI_Init_FuncPtr[41] = FH_DI_Init_DI42;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_DI43
	FH_DI_Init_FuncPtr[42] = FH_DI_Init_DI43;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_DI44
	FH_DI_Init_FuncPtr[43] = FH_DI_Init_DI44;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_DI45
	FH_DI_Init_FuncPtr[44] = FH_DI_Init_DI45;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_DI46
	FH_DI_Init_FuncPtr[45] = FH_DI_Init_DI46;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_DI47
	FH_DI_Init_FuncPtr[46] = FH_DI_Init_DI47;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_DI48
	FH_DI_Init_FuncPtr[47] = FH_DI_Init_DI48;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_DI49
	FH_DI_Init_FuncPtr[48] = FH_DI_Init_DI49;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_DI50
	FH_DI_Init_FuncPtr[49] = FH_DI_Init_DI50;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_DI51
	FH_DI_Init_FuncPtr[50] = FH_DI_Init_DI51;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_DI52
	FH_DI_Init_FuncPtr[51] = FH_DI_Init_DI52;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_DI53
	FH_DI_Init_FuncPtr[52] = FH_DI_Init_DI53;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_DI54
	FH_DI_Init_FuncPtr[53] = FH_DI_Init_DI54;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_DI55
	FH_DI_Init_FuncPtr[54] = FH_DI_Init_DI55;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_DI56
	FH_DI_Init_FuncPtr[55] = FH_DI_Init_DI56;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_DI57
	FH_DI_Init_FuncPtr[56] = FH_DI_Init_DI57;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_DI58
	FH_DI_Init_FuncPtr[57] = FH_DI_Init_DI58;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_DI59
	FH_DI_Init_FuncPtr[58] = FH_DI_Init_DI59;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_DI60
	FH_DI_Init_FuncPtr[59] = FH_DI_Init_DI60;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_DI61
	FH_DI_Init_FuncPtr[60] = FH_DI_Init_DI61;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_DI62
	FH_DI_Init_FuncPtr[61] = FH_DI_Init_DI62;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_DI63
	FH_DI_Init_FuncPtr[62] = FH_DI_Init_DI63;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_DI64
	FH_DI_Init_FuncPtr[63] = FH_DI_Init_DI64;    // Set the function pointer address with the related function address
	#endif
}

#endif
