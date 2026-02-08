/**
  * @file
  * @brief
  *       <b>File Map:</b>\n
  *       <b>FH_Root</b>, Section <b>FH_Perif</b>, <b>FH_PWMO</b> (PWM Output), <b>Cmd</b> (Command), <b>Init</b>, <b>Init_S</b> (Init Set Address)\n
  *       Functions in this file, set the address of the defined <b>FH_Functions</b>, Section <b>FH_PWMO</b> (PWM Output), <b>FH_PWMO_Init_PWMO01-...</b> to an array of function pointers
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
#include "../../../../../../../FH_Embedded/FH_Root/FH_Perif/FH_PWMO/Cmd/Init/Init_S/FH_PWMO_Init_S.h"

#include "../../../../../../../FH_Embedded/FH_Root/FH_General/FH_GeneralFunctions/FH_GeneralFunctions.h"

#ifdef FH_PWMO01
#include "../../../../../../../FH_Embedded/FH_Functions/FH_PWMO/FH_PWMO01/FH_PWMO01.h"
#endif
#ifdef FH_PWMO02
#include "../../../../../../../FH_Embedded/FH_Functions/FH_PWMO/FH_PWMO02/FH_PWMO02.h"
#endif
#ifdef FH_PWMO03
#include "../../../../../../../FH_Embedded/FH_Functions/FH_PWMO/FH_PWMO03/FH_PWMO03.h"
#endif
#ifdef FH_PWMO04
#include "../../../../../../../FH_Embedded/FH_Functions/FH_PWMO/FH_PWMO04/FH_PWMO04.h"
#endif
#ifdef FH_PWMO05
#include "../../../../../../../FH_Embedded/FH_Functions/FH_PWMO/FH_PWMO05/FH_PWMO05.h"
#endif
#ifdef FH_PWMO06
#include "../../../../../../../FH_Embedded/FH_Functions/FH_PWMO/FH_PWMO06/FH_PWMO06.h"
#endif
#ifdef FH_PWMO07
#include "../../../../../../../FH_Embedded/FH_Functions/FH_PWMO/FH_PWMO07/FH_PWMO07.h"
#endif
#ifdef FH_PWMO08
#include "../../../../../../../FH_Embedded/FH_Functions/FH_PWMO/FH_PWMO08/FH_PWMO08.h"
#endif
#ifdef FH_PWMO09
#include "../../../../../../../FH_Embedded/FH_Functions/FH_PWMO/FH_PWMO09/FH_PWMO09.h"
#endif
#ifdef FH_PWMO10
#include "../../../../../../../FH_Embedded/FH_Functions/FH_PWMO/FH_PWMO10/FH_PWMO10.h"
#endif
#ifdef FH_PWMO11
#include "../../../../../../../FH_Embedded/FH_Functions/FH_PWMO/FH_PWMO11/FH_PWMO11.h"
#endif
#ifdef FH_PWMO12
#include "../../../../../../../FH_Embedded/FH_Functions/FH_PWMO/FH_PWMO12/FH_PWMO12.h"
#endif
#ifdef FH_PWMO13
#include "../../../../../../../FH_Embedded/FH_Functions/FH_PWMO/FH_PWMO13/FH_PWMO13.h"
#endif
#ifdef FH_PWMO14
#include "../../../../../../../FH_Embedded/FH_Functions/FH_PWMO/FH_PWMO14/FH_PWMO14.h"
#endif
#ifdef FH_PWMO15
#include "../../../../../../../FH_Embedded/FH_Functions/FH_PWMO/FH_PWMO15/FH_PWMO15.h"
#endif
#ifdef FH_PWMO16
#include "../../../../../../../FH_Embedded/FH_Functions/FH_PWMO/FH_PWMO16/FH_PWMO16.h"
#endif
#ifdef FH_PWMO17
#include "../../../../../../../FH_Embedded/FH_Functions/FH_PWMO/FH_PWMO17/FH_PWMO17.h"
#endif
#ifdef FH_PWMO18
#include "../../../../../../../FH_Embedded/FH_Functions/FH_PWMO/FH_PWMO18/FH_PWMO18.h"
#endif
#ifdef FH_PWMO19
#include "../../../../../../../FH_Embedded/FH_Functions/FH_PWMO/FH_PWMO19/FH_PWMO19.h"
#endif
#ifdef FH_PWMO20
#include "../../../../../../../FH_Embedded/FH_Functions/FH_PWMO/FH_PWMO20/FH_PWMO20.h"
#endif
#ifdef FH_PWMO21
#include "../../../../../../../FH_Embedded/FH_Functions/FH_PWMO/FH_PWMO21/FH_PWMO21.h"
#endif
#ifdef FH_PWMO22
#include "../../../../../../../FH_Embedded/FH_Functions/FH_PWMO/FH_PWMO22/FH_PWMO22.h"
#endif
#ifdef FH_PWMO23
#include "../../../../../../../FH_Embedded/FH_Functions/FH_PWMO/FH_PWMO23/FH_PWMO23.h"
#endif
#ifdef FH_PWMO24
#include "../../../../../../../FH_Embedded/FH_Functions/FH_PWMO/FH_PWMO24/FH_PWMO24.h"
#endif
#ifdef FH_PWMO25
#include "../../../../../../../FH_Embedded/FH_Functions/FH_PWMO/FH_PWMO25/FH_PWMO25.h"
#endif
#ifdef FH_PWMO26
#include "../../../../../../../FH_Embedded/FH_Functions/FH_PWMO/FH_PWMO26/FH_PWMO26.h"
#endif
#ifdef FH_PWMO27
#include "../../../../../../../FH_Embedded/FH_Functions/FH_PWMO/FH_PWMO27/FH_PWMO27.h"
#endif
#ifdef FH_PWMO28
#include "../../../../../../../FH_Embedded/FH_Functions/FH_PWMO/FH_PWMO28/FH_PWMO28.h"
#endif
#ifdef FH_PWMO29
#include "../../../../../../../FH_Embedded/FH_Functions/FH_PWMO/FH_PWMO29/FH_PWMO29.h"
#endif
#ifdef FH_PWMO30
#include "../../../../../../../FH_Embedded/FH_Functions/FH_PWMO/FH_PWMO30/FH_PWMO30.h"
#endif
#ifdef FH_PWMO31
#include "../../../../../../../FH_Embedded/FH_Functions/FH_PWMO/FH_PWMO31/FH_PWMO31.h"
#endif
#ifdef FH_PWMO32
#include "../../../../../../../FH_Embedded/FH_Functions/FH_PWMO/FH_PWMO32/FH_PWMO32.h"
#endif
#ifdef FH_PWMO33
#include "../../../../../../../FH_Embedded/FH_Functions/FH_PWMO/FH_PWMO33/FH_PWMO33.h"
#endif
#ifdef FH_PWMO34
#include "../../../../../../../FH_Embedded/FH_Functions/FH_PWMO/FH_PWMO34/FH_PWMO34.h"
#endif
#ifdef FH_PWMO35
#include "../../../../../../../FH_Embedded/FH_Functions/FH_PWMO/FH_PWMO35/FH_PWMO35.h"
#endif
#ifdef FH_PWMO36
#include "../../../../../../../FH_Embedded/FH_Functions/FH_PWMO/FH_PWMO36/FH_PWMO36.h"
#endif
#ifdef FH_PWMO37
#include "../../../../../../../FH_Embedded/FH_Functions/FH_PWMO/FH_PWMO37/FH_PWMO37.h"
#endif
#ifdef FH_PWMO38
#include "../../../../../../../FH_Embedded/FH_Functions/FH_PWMO/FH_PWMO38/FH_PWMO38.h"
#endif
#ifdef FH_PWMO39
#include "../../../../../../../FH_Embedded/FH_Functions/FH_PWMO/FH_PWMO39/FH_PWMO39.h"
#endif
#ifdef FH_PWMO40
#include "../../../../../../../FH_Embedded/FH_Functions/FH_PWMO/FH_PWMO40/FH_PWMO40.h"
#endif
#ifdef FH_PWMO41
#include "../../../../../../../FH_Embedded/FH_Functions/FH_PWMO/FH_PWMO41/FH_PWMO41.h"
#endif
#ifdef FH_PWMO42
#include "../../../../../../../FH_Embedded/FH_Functions/FH_PWMO/FH_PWMO42/FH_PWMO42.h"
#endif
#ifdef FH_PWMO43
#include "../../../../../../../FH_Embedded/FH_Functions/FH_PWMO/FH_PWMO43/FH_PWMO43.h"
#endif
#ifdef FH_PWMO44
#include "../../../../../../../FH_Embedded/FH_Functions/FH_PWMO/FH_PWMO44/FH_PWMO44.h"
#endif
#ifdef FH_PWMO45
#include "../../../../../../../FH_Embedded/FH_Functions/FH_PWMO/FH_PWMO45/FH_PWMO45.h"
#endif
#ifdef FH_PWMO46
#include "../../../../../../../FH_Embedded/FH_Functions/FH_PWMO/FH_PWMO46/FH_PWMO46.h"
#endif
#ifdef FH_PWMO47
#include "../../../../../../../FH_Embedded/FH_Functions/FH_PWMO/FH_PWMO47/FH_PWMO47.h"
#endif
#ifdef FH_PWMO48
#include "../../../../../../../FH_Embedded/FH_Functions/FH_PWMO/FH_PWMO48/FH_PWMO48.h"
#endif
#ifdef FH_PWMO49
#include "../../../../../../../FH_Embedded/FH_Functions/FH_PWMO/FH_PWMO49/FH_PWMO49.h"
#endif
#ifdef FH_PWMO50
#include "../../../../../../../FH_Embedded/FH_Functions/FH_PWMO/FH_PWMO50/FH_PWMO50.h"
#endif
#ifdef FH_PWMO51
#include "../../../../../../../FH_Embedded/FH_Functions/FH_PWMO/FH_PWMO51/FH_PWMO51.h"
#endif
#ifdef FH_PWMO52
#include "../../../../../../../FH_Embedded/FH_Functions/FH_PWMO/FH_PWMO52/FH_PWMO52.h"
#endif
#ifdef FH_PWMO53
#include "../../../../../../../FH_Embedded/FH_Functions/FH_PWMO/FH_PWMO53/FH_PWMO53.h"
#endif
#ifdef FH_PWMO54
#include "../../../../../../../FH_Embedded/FH_Functions/FH_PWMO/FH_PWMO54/FH_PWMO54.h"
#endif
#ifdef FH_PWMO55
#include "../../../../../../../FH_Embedded/FH_Functions/FH_PWMO/FH_PWMO55/FH_PWMO55.h"
#endif
#ifdef FH_PWMO56
#include "../../../../../../../FH_Embedded/FH_Functions/FH_PWMO/FH_PWMO56/FH_PWMO56.h"
#endif
#ifdef FH_PWMO57
#include "../../../../../../../FH_Embedded/FH_Functions/FH_PWMO/FH_PWMO57/FH_PWMO57.h"
#endif
#ifdef FH_PWMO58
#include "../../../../../../../FH_Embedded/FH_Functions/FH_PWMO/FH_PWMO58/FH_PWMO58.h"
#endif
#ifdef FH_PWMO59
#include "../../../../../../../FH_Embedded/FH_Functions/FH_PWMO/FH_PWMO59/FH_PWMO59.h"
#endif
#ifdef FH_PWMO60
#include "../../../../../../../FH_Embedded/FH_Functions/FH_PWMO/FH_PWMO60/FH_PWMO60.h"
#endif
#ifdef FH_PWMO61
#include "../../../../../../../FH_Embedded/FH_Functions/FH_PWMO/FH_PWMO61/FH_PWMO61.h"
#endif
#ifdef FH_PWMO62
#include "../../../../../../../FH_Embedded/FH_Functions/FH_PWMO/FH_PWMO62/FH_PWMO62.h"
#endif
#ifdef FH_PWMO63
#include "../../../../../../../FH_Embedded/FH_Functions/FH_PWMO/FH_PWMO63/FH_PWMO63.h"
#endif
#ifdef FH_PWMO64
#include "../../../../../../../FH_Embedded/FH_Functions/FH_PWMO/FH_PWMO64/FH_PWMO64.h"
#endif

#if FH_PWMO_MaxPeripheralNumber > 0    // It is configurable in FH_DevicePeripherals.h

/**
 * @brief This function sets the address of the defined <b>FH_Functions</b>, Section <b>FH_PWMO</b> (PWM Output), <b>FH_PWMO_Init_PWMO01-...</b> to an array of function pointers
 *
 * @param  FH_PWMO_Init_FuncPtr
 *         An array of function pointers with FH_PWMO_Init_FuncPtrModel model
 *
 * @return None
 *

*/
void FH_PWMO_Init_S(FH_PWMO_Init_FuncPtrModel *FH_PWMO_Init_FuncPtr)
{
	for (uint8_t i = 0; i < FH_PWMO_MaxPeripheralNumber; i++)    // if FH_PWMO_MaxPeripheralNumber > 0
	{
		FH_PWMO_Init_FuncPtr[i] = NULL_PTR;    // Initialization of the function pointers with null pointer to prevent pointing to undefined addresses
	}

	#ifdef FH_PWMO01
	FH_PWMO_Init_FuncPtr[0] = FH_PWMO_Init_PWMO01;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_PWMO02
	FH_PWMO_Init_FuncPtr[1] = FH_PWMO_Init_PWMO02;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_PWMO03
	FH_PWMO_Init_FuncPtr[2] = FH_PWMO_Init_PWMO03;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_PWMO04
	FH_PWMO_Init_FuncPtr[3] = FH_PWMO_Init_PWMO04;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_PWMO05
	FH_PWMO_Init_FuncPtr[4] = FH_PWMO_Init_PWMO05;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_PWMO06
	FH_PWMO_Init_FuncPtr[5] = FH_PWMO_Init_PWMO06;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_PWMO07
	FH_PWMO_Init_FuncPtr[6] = FH_PWMO_Init_PWMO07;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_PWMO08
	FH_PWMO_Init_FuncPtr[7] = FH_PWMO_Init_PWMO08;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_PWMO09
	FH_PWMO_Init_FuncPtr[8] = FH_PWMO_Init_PWMO09;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_PWMO10
	FH_PWMO_Init_FuncPtr[9] = FH_PWMO_Init_PWMO10;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_PWMO11
	FH_PWMO_Init_FuncPtr[10] = FH_PWMO_Init_PWMO11;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_PWMO12
	FH_PWMO_Init_FuncPtr[11] = FH_PWMO_Init_PWMO12;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_PWMO13
	FH_PWMO_Init_FuncPtr[12] = FH_PWMO_Init_PWMO13;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_PWMO14
	FH_PWMO_Init_FuncPtr[13] = FH_PWMO_Init_PWMO14;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_PWMO15
	FH_PWMO_Init_FuncPtr[14] = FH_PWMO_Init_PWMO15;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_PWMO16
	FH_PWMO_Init_FuncPtr[15] = FH_PWMO_Init_PWMO16;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_PWMO17
	FH_PWMO_Init_FuncPtr[16] = FH_PWMO_Init_PWMO17;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_PWMO18
	FH_PWMO_Init_FuncPtr[17] = FH_PWMO_Init_PWMO18;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_PWMO19
	FH_PWMO_Init_FuncPtr[18] = FH_PWMO_Init_PWMO19;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_PWMO20
	FH_PWMO_Init_FuncPtr[19] = FH_PWMO_Init_PWMO20;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_PWMO21
	FH_PWMO_Init_FuncPtr[20] = FH_PWMO_Init_PWMO21;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_PWMO22
	FH_PWMO_Init_FuncPtr[21] = FH_PWMO_Init_PWMO22;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_PWMO23
	FH_PWMO_Init_FuncPtr[22] = FH_PWMO_Init_PWMO23;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_PWMO24
	FH_PWMO_Init_FuncPtr[23] = FH_PWMO_Init_PWMO24;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_PWMO25
	FH_PWMO_Init_FuncPtr[24] = FH_PWMO_Init_PWMO25;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_PWMO26
	FH_PWMO_Init_FuncPtr[25] = FH_PWMO_Init_PWMO26;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_PWMO27
	FH_PWMO_Init_FuncPtr[26] = FH_PWMO_Init_PWMO27;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_PWMO28
	FH_PWMO_Init_FuncPtr[27] = FH_PWMO_Init_PWMO28;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_PWMO29
	FH_PWMO_Init_FuncPtr[28] = FH_PWMO_Init_PWMO29;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_PWMO30
	FH_PWMO_Init_FuncPtr[29] = FH_PWMO_Init_PWMO30;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_PWMO31
	FH_PWMO_Init_FuncPtr[30] = FH_PWMO_Init_PWMO31;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_PWMO32
	FH_PWMO_Init_FuncPtr[31] = FH_PWMO_Init_PWMO32;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_PWMO33
	FH_PWMO_Init_FuncPtr[32] = FH_PWMO_Init_PWMO33;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_PWMO34
	FH_PWMO_Init_FuncPtr[33] = FH_PWMO_Init_PWMO34;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_PWMO35
	FH_PWMO_Init_FuncPtr[34] = FH_PWMO_Init_PWMO35;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_PWMO36
	FH_PWMO_Init_FuncPtr[35] = FH_PWMO_Init_PWMO36;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_PWMO37
	FH_PWMO_Init_FuncPtr[36] = FH_PWMO_Init_PWMO37;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_PWMO38
	FH_PWMO_Init_FuncPtr[37] = FH_PWMO_Init_PWMO38;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_PWMO39
	FH_PWMO_Init_FuncPtr[38] = FH_PWMO_Init_PWMO39;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_PWMO40
	FH_PWMO_Init_FuncPtr[39] = FH_PWMO_Init_PWMO40;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_PWMO41
	FH_PWMO_Init_FuncPtr[40] = FH_PWMO_Init_PWMO41;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_PWMO42
	FH_PWMO_Init_FuncPtr[41] = FH_PWMO_Init_PWMO42;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_PWMO43
	FH_PWMO_Init_FuncPtr[42] = FH_PWMO_Init_PWMO43;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_PWMO44
	FH_PWMO_Init_FuncPtr[43] = FH_PWMO_Init_PWMO44;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_PWMO45
	FH_PWMO_Init_FuncPtr[44] = FH_PWMO_Init_PWMO45;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_PWMO46
	FH_PWMO_Init_FuncPtr[45] = FH_PWMO_Init_PWMO46;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_PWMO47
	FH_PWMO_Init_FuncPtr[46] = FH_PWMO_Init_PWMO47;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_PWMO48
	FH_PWMO_Init_FuncPtr[47] = FH_PWMO_Init_PWMO48;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_PWMO49
	FH_PWMO_Init_FuncPtr[48] = FH_PWMO_Init_PWMO49;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_PWMO50
	FH_PWMO_Init_FuncPtr[49] = FH_PWMO_Init_PWMO50;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_PWMO51
	FH_PWMO_Init_FuncPtr[50] = FH_PWMO_Init_PWMO51;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_PWMO52
	FH_PWMO_Init_FuncPtr[51] = FH_PWMO_Init_PWMO52;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_PWMO53
	FH_PWMO_Init_FuncPtr[52] = FH_PWMO_Init_PWMO53;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_PWMO54
	FH_PWMO_Init_FuncPtr[53] = FH_PWMO_Init_PWMO54;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_PWMO55
	FH_PWMO_Init_FuncPtr[54] = FH_PWMO_Init_PWMO55;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_PWMO56
	FH_PWMO_Init_FuncPtr[55] = FH_PWMO_Init_PWMO56;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_PWMO57
	FH_PWMO_Init_FuncPtr[56] = FH_PWMO_Init_PWMO57;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_PWMO58
	FH_PWMO_Init_FuncPtr[57] = FH_PWMO_Init_PWMO58;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_PWMO59
	FH_PWMO_Init_FuncPtr[58] = FH_PWMO_Init_PWMO59;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_PWMO60
	FH_PWMO_Init_FuncPtr[59] = FH_PWMO_Init_PWMO60;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_PWMO61
	FH_PWMO_Init_FuncPtr[60] = FH_PWMO_Init_PWMO61;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_PWMO62
	FH_PWMO_Init_FuncPtr[61] = FH_PWMO_Init_PWMO62;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_PWMO63
	FH_PWMO_Init_FuncPtr[62] = FH_PWMO_Init_PWMO63;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_PWMO64
	FH_PWMO_Init_FuncPtr[63] = FH_PWMO_Init_PWMO64;    // Set the function pointer address with the related function address
	#endif
}

#endif
