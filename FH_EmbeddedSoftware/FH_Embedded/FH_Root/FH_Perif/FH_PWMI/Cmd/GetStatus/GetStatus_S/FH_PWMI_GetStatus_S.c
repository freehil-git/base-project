/**
  * @file
  * @brief
  *       <b>File Map:</b>\n
  *       <b>FH_Root</b>, Section <b>FH_Perif</b>, <b>FH_PWMI</b> (PWM Input), <b>Cmd</b> (Command), <b>GetStatus</b>, <b>GetStatus_S</b> (GetStatus Set Address)\n
  *       Functions in this file, set the address of the defined <b>FH_Functions</b>, Section <b>FH_PWMI</b> (PWM Input), <b>FH_PWMI_GetStatus_PWMI01-...</b> to an array of function pointers
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
#include "../../../../../../../FH_Embedded/FH_Root/FH_Perif/FH_PWMI/Cmd/GetStatus/GetStatus_S/FH_PWMI_GetStatus_S.h"

#include "../../../../../../../FH_Embedded/FH_Root/FH_General/FH_GeneralFunctions/FH_GeneralFunctions.h"

#ifdef FH_PWMI01
#include "../../../../../../../FH_Embedded/FH_Functions/FH_PWMI/FH_PWMI01/FH_PWMI01.h"
#endif
#ifdef FH_PWMI02
#include "../../../../../../../FH_Embedded/FH_Functions/FH_PWMI/FH_PWMI02/FH_PWMI02.h"
#endif
#ifdef FH_PWMI03
#include "../../../../../../../FH_Embedded/FH_Functions/FH_PWMI/FH_PWMI03/FH_PWMI03.h"
#endif
#ifdef FH_PWMI04
#include "../../../../../../../FH_Embedded/FH_Functions/FH_PWMI/FH_PWMI04/FH_PWMI04.h"
#endif
#ifdef FH_PWMI05
#include "../../../../../../../FH_Embedded/FH_Functions/FH_PWMI/FH_PWMI05/FH_PWMI05.h"
#endif
#ifdef FH_PWMI06
#include "../../../../../../../FH_Embedded/FH_Functions/FH_PWMI/FH_PWMI06/FH_PWMI06.h"
#endif
#ifdef FH_PWMI07
#include "../../../../../../../FH_Embedded/FH_Functions/FH_PWMI/FH_PWMI07/FH_PWMI07.h"
#endif
#ifdef FH_PWMI08
#include "../../../../../../../FH_Embedded/FH_Functions/FH_PWMI/FH_PWMI08/FH_PWMI08.h"
#endif
#ifdef FH_PWMI09
#include "../../../../../../../FH_Embedded/FH_Functions/FH_PWMI/FH_PWMI09/FH_PWMI09.h"
#endif
#ifdef FH_PWMI10
#include "../../../../../../../FH_Embedded/FH_Functions/FH_PWMI/FH_PWMI10/FH_PWMI10.h"
#endif
#ifdef FH_PWMI11
#include "../../../../../../../FH_Embedded/FH_Functions/FH_PWMI/FH_PWMI11/FH_PWMI11.h"
#endif
#ifdef FH_PWMI12
#include "../../../../../../../FH_Embedded/FH_Functions/FH_PWMI/FH_PWMI12/FH_PWMI12.h"
#endif
#ifdef FH_PWMI13
#include "../../../../../../../FH_Embedded/FH_Functions/FH_PWMI/FH_PWMI13/FH_PWMI13.h"
#endif
#ifdef FH_PWMI14
#include "../../../../../../../FH_Embedded/FH_Functions/FH_PWMI/FH_PWMI14/FH_PWMI14.h"
#endif
#ifdef FH_PWMI15
#include "../../../../../../../FH_Embedded/FH_Functions/FH_PWMI/FH_PWMI15/FH_PWMI15.h"
#endif
#ifdef FH_PWMI16
#include "../../../../../../../FH_Embedded/FH_Functions/FH_PWMI/FH_PWMI16/FH_PWMI16.h"
#endif
#ifdef FH_PWMI17
#include "../../../../../../../FH_Embedded/FH_Functions/FH_PWMI/FH_PWMI17/FH_PWMI17.h"
#endif
#ifdef FH_PWMI18
#include "../../../../../../../FH_Embedded/FH_Functions/FH_PWMI/FH_PWMI18/FH_PWMI18.h"
#endif
#ifdef FH_PWMI19
#include "../../../../../../../FH_Embedded/FH_Functions/FH_PWMI/FH_PWMI19/FH_PWMI19.h"
#endif
#ifdef FH_PWMI20
#include "../../../../../../../FH_Embedded/FH_Functions/FH_PWMI/FH_PWMI20/FH_PWMI20.h"
#endif
#ifdef FH_PWMI21
#include "../../../../../../../FH_Embedded/FH_Functions/FH_PWMI/FH_PWMI21/FH_PWMI21.h"
#endif
#ifdef FH_PWMI22
#include "../../../../../../../FH_Embedded/FH_Functions/FH_PWMI/FH_PWMI22/FH_PWMI22.h"
#endif
#ifdef FH_PWMI23
#include "../../../../../../../FH_Embedded/FH_Functions/FH_PWMI/FH_PWMI23/FH_PWMI23.h"
#endif
#ifdef FH_PWMI24
#include "../../../../../../../FH_Embedded/FH_Functions/FH_PWMI/FH_PWMI24/FH_PWMI24.h"
#endif
#ifdef FH_PWMI25
#include "../../../../../../../FH_Embedded/FH_Functions/FH_PWMI/FH_PWMI25/FH_PWMI25.h"
#endif
#ifdef FH_PWMI26
#include "../../../../../../../FH_Embedded/FH_Functions/FH_PWMI/FH_PWMI26/FH_PWMI26.h"
#endif
#ifdef FH_PWMI27
#include "../../../../../../../FH_Embedded/FH_Functions/FH_PWMI/FH_PWMI27/FH_PWMI27.h"
#endif
#ifdef FH_PWMI28
#include "../../../../../../../FH_Embedded/FH_Functions/FH_PWMI/FH_PWMI28/FH_PWMI28.h"
#endif
#ifdef FH_PWMI29
#include "../../../../../../../FH_Embedded/FH_Functions/FH_PWMI/FH_PWMI29/FH_PWMI29.h"
#endif
#ifdef FH_PWMI30
#include "../../../../../../../FH_Embedded/FH_Functions/FH_PWMI/FH_PWMI30/FH_PWMI30.h"
#endif
#ifdef FH_PWMI31
#include "../../../../../../../FH_Embedded/FH_Functions/FH_PWMI/FH_PWMI31/FH_PWMI31.h"
#endif
#ifdef FH_PWMI32
#include "../../../../../../../FH_Embedded/FH_Functions/FH_PWMI/FH_PWMI32/FH_PWMI32.h"
#endif
#ifdef FH_PWMI33
#include "../../../../../../../FH_Embedded/FH_Functions/FH_PWMI/FH_PWMI33/FH_PWMI33.h"
#endif
#ifdef FH_PWMI34
#include "../../../../../../../FH_Embedded/FH_Functions/FH_PWMI/FH_PWMI34/FH_PWMI34.h"
#endif
#ifdef FH_PWMI35
#include "../../../../../../../FH_Embedded/FH_Functions/FH_PWMI/FH_PWMI35/FH_PWMI35.h"
#endif
#ifdef FH_PWMI36
#include "../../../../../../../FH_Embedded/FH_Functions/FH_PWMI/FH_PWMI36/FH_PWMI36.h"
#endif
#ifdef FH_PWMI37
#include "../../../../../../../FH_Embedded/FH_Functions/FH_PWMI/FH_PWMI37/FH_PWMI37.h"
#endif
#ifdef FH_PWMI38
#include "../../../../../../../FH_Embedded/FH_Functions/FH_PWMI/FH_PWMI38/FH_PWMI38.h"
#endif
#ifdef FH_PWMI39
#include "../../../../../../../FH_Embedded/FH_Functions/FH_PWMI/FH_PWMI39/FH_PWMI39.h"
#endif
#ifdef FH_PWMI40
#include "../../../../../../../FH_Embedded/FH_Functions/FH_PWMI/FH_PWMI40/FH_PWMI40.h"
#endif
#ifdef FH_PWMI41
#include "../../../../../../../FH_Embedded/FH_Functions/FH_PWMI/FH_PWMI41/FH_PWMI41.h"
#endif
#ifdef FH_PWMI42
#include "../../../../../../../FH_Embedded/FH_Functions/FH_PWMI/FH_PWMI42/FH_PWMI42.h"
#endif
#ifdef FH_PWMI43
#include "../../../../../../../FH_Embedded/FH_Functions/FH_PWMI/FH_PWMI43/FH_PWMI43.h"
#endif
#ifdef FH_PWMI44
#include "../../../../../../../FH_Embedded/FH_Functions/FH_PWMI/FH_PWMI44/FH_PWMI44.h"
#endif
#ifdef FH_PWMI45
#include "../../../../../../../FH_Embedded/FH_Functions/FH_PWMI/FH_PWMI45/FH_PWMI45.h"
#endif
#ifdef FH_PWMI46
#include "../../../../../../../FH_Embedded/FH_Functions/FH_PWMI/FH_PWMI46/FH_PWMI46.h"
#endif
#ifdef FH_PWMI47
#include "../../../../../../../FH_Embedded/FH_Functions/FH_PWMI/FH_PWMI47/FH_PWMI47.h"
#endif
#ifdef FH_PWMI48
#include "../../../../../../../FH_Embedded/FH_Functions/FH_PWMI/FH_PWMI48/FH_PWMI48.h"
#endif
#ifdef FH_PWMI49
#include "../../../../../../../FH_Embedded/FH_Functions/FH_PWMI/FH_PWMI49/FH_PWMI49.h"
#endif
#ifdef FH_PWMI50
#include "../../../../../../../FH_Embedded/FH_Functions/FH_PWMI/FH_PWMI50/FH_PWMI50.h"
#endif
#ifdef FH_PWMI51
#include "../../../../../../../FH_Embedded/FH_Functions/FH_PWMI/FH_PWMI51/FH_PWMI51.h"
#endif
#ifdef FH_PWMI52
#include "../../../../../../../FH_Embedded/FH_Functions/FH_PWMI/FH_PWMI52/FH_PWMI52.h"
#endif
#ifdef FH_PWMI53
#include "../../../../../../../FH_Embedded/FH_Functions/FH_PWMI/FH_PWMI53/FH_PWMI53.h"
#endif
#ifdef FH_PWMI54
#include "../../../../../../../FH_Embedded/FH_Functions/FH_PWMI/FH_PWMI54/FH_PWMI54.h"
#endif
#ifdef FH_PWMI55
#include "../../../../../../../FH_Embedded/FH_Functions/FH_PWMI/FH_PWMI55/FH_PWMI55.h"
#endif
#ifdef FH_PWMI56
#include "../../../../../../../FH_Embedded/FH_Functions/FH_PWMI/FH_PWMI56/FH_PWMI56.h"
#endif
#ifdef FH_PWMI57
#include "../../../../../../../FH_Embedded/FH_Functions/FH_PWMI/FH_PWMI57/FH_PWMI57.h"
#endif
#ifdef FH_PWMI58
#include "../../../../../../../FH_Embedded/FH_Functions/FH_PWMI/FH_PWMI58/FH_PWMI58.h"
#endif
#ifdef FH_PWMI59
#include "../../../../../../../FH_Embedded/FH_Functions/FH_PWMI/FH_PWMI59/FH_PWMI59.h"
#endif
#ifdef FH_PWMI60
#include "../../../../../../../FH_Embedded/FH_Functions/FH_PWMI/FH_PWMI60/FH_PWMI60.h"
#endif
#ifdef FH_PWMI61
#include "../../../../../../../FH_Embedded/FH_Functions/FH_PWMI/FH_PWMI61/FH_PWMI61.h"
#endif
#ifdef FH_PWMI62
#include "../../../../../../../FH_Embedded/FH_Functions/FH_PWMI/FH_PWMI62/FH_PWMI62.h"
#endif
#ifdef FH_PWMI63
#include "../../../../../../../FH_Embedded/FH_Functions/FH_PWMI/FH_PWMI63/FH_PWMI63.h"
#endif
#ifdef FH_PWMI64
#include "../../../../../../../FH_Embedded/FH_Functions/FH_PWMI/FH_PWMI64/FH_PWMI64.h"
#endif

#if FH_PWMI_MaxPeripheralNumber > 0    // It is configurable in FH_DevicePeripherals.h

/**
 * @brief This function sets the address of the defined <b>FH_Functions</b>, Section <b>FH_PWMI</b> (PWM Input), <b>FH_PWMI_GetStatus_PWMI01-...</b> to an array of function pointers
 *
 * @param  FH_PWMI_GetStatus_FuncPtr
 *         An array of function pointers with FH_PWMI_GetStatus_FuncPtrModel model
 *
 * @return None
 *

*/
void FH_PWMI_GetStatus_S(FH_PWMI_GetStatus_FuncPtrModel *FH_PWMI_GetStatus_FuncPtr)
{
	for (uint8_t i = 0; i < FH_PWMI_MaxPeripheralNumber; i++)    // if FH_PWMI_MaxPeripheralNumber > 0
	{
		FH_PWMI_GetStatus_FuncPtr[i] = NULL_PTR;    // Initialization of the function pointers with null pointer to prevent pointing to undefined addresses
	}

	#ifdef FH_PWMI01
	FH_PWMI_GetStatus_FuncPtr[0] = FH_PWMI_GetStatus_PWMI01;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_PWMI02
	FH_PWMI_GetStatus_FuncPtr[1] = FH_PWMI_GetStatus_PWMI02;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_PWMI03
	FH_PWMI_GetStatus_FuncPtr[2] = FH_PWMI_GetStatus_PWMI03;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_PWMI04
	FH_PWMI_GetStatus_FuncPtr[3] = FH_PWMI_GetStatus_PWMI04;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_PWMI05
	FH_PWMI_GetStatus_FuncPtr[4] = FH_PWMI_GetStatus_PWMI05;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_PWMI06
	FH_PWMI_GetStatus_FuncPtr[5] = FH_PWMI_GetStatus_PWMI06;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_PWMI07
	FH_PWMI_GetStatus_FuncPtr[6] = FH_PWMI_GetStatus_PWMI07;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_PWMI08
	FH_PWMI_GetStatus_FuncPtr[7] = FH_PWMI_GetStatus_PWMI08;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_PWMI09
	FH_PWMI_GetStatus_FuncPtr[8] = FH_PWMI_GetStatus_PWMI09;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_PWMI10
	FH_PWMI_GetStatus_FuncPtr[9] = FH_PWMI_GetStatus_PWMI10;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_PWMI11
	FH_PWMI_GetStatus_FuncPtr[10] = FH_PWMI_GetStatus_PWMI11;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_PWMI12
	FH_PWMI_GetStatus_FuncPtr[11] = FH_PWMI_GetStatus_PWMI12;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_PWMI13
	FH_PWMI_GetStatus_FuncPtr[12] = FH_PWMI_GetStatus_PWMI13;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_PWMI14
	FH_PWMI_GetStatus_FuncPtr[13] = FH_PWMI_GetStatus_PWMI14;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_PWMI15
	FH_PWMI_GetStatus_FuncPtr[14] = FH_PWMI_GetStatus_PWMI15;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_PWMI16
	FH_PWMI_GetStatus_FuncPtr[15] = FH_PWMI_GetStatus_PWMI16;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_PWMI17
	FH_PWMI_GetStatus_FuncPtr[16] = FH_PWMI_GetStatus_PWMI17;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_PWMI18
	FH_PWMI_GetStatus_FuncPtr[17] = FH_PWMI_GetStatus_PWMI18;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_PWMI19
	FH_PWMI_GetStatus_FuncPtr[18] = FH_PWMI_GetStatus_PWMI19;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_PWMI20
	FH_PWMI_GetStatus_FuncPtr[19] = FH_PWMI_GetStatus_PWMI20;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_PWMI21
	FH_PWMI_GetStatus_FuncPtr[20] = FH_PWMI_GetStatus_PWMI21;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_PWMI22
	FH_PWMI_GetStatus_FuncPtr[21] = FH_PWMI_GetStatus_PWMI22;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_PWMI23
	FH_PWMI_GetStatus_FuncPtr[22] = FH_PWMI_GetStatus_PWMI23;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_PWMI24
	FH_PWMI_GetStatus_FuncPtr[23] = FH_PWMI_GetStatus_PWMI24;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_PWMI25
	FH_PWMI_GetStatus_FuncPtr[24] = FH_PWMI_GetStatus_PWMI25;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_PWMI26
	FH_PWMI_GetStatus_FuncPtr[25] = FH_PWMI_GetStatus_PWMI26;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_PWMI27
	FH_PWMI_GetStatus_FuncPtr[26] = FH_PWMI_GetStatus_PWMI27;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_PWMI28
	FH_PWMI_GetStatus_FuncPtr[27] = FH_PWMI_GetStatus_PWMI28;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_PWMI29
	FH_PWMI_GetStatus_FuncPtr[28] = FH_PWMI_GetStatus_PWMI29;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_PWMI30
	FH_PWMI_GetStatus_FuncPtr[29] = FH_PWMI_GetStatus_PWMI30;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_PWMI31
	FH_PWMI_GetStatus_FuncPtr[30] = FH_PWMI_GetStatus_PWMI31;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_PWMI32
	FH_PWMI_GetStatus_FuncPtr[31] = FH_PWMI_GetStatus_PWMI32;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_PWMI33
	FH_PWMI_GetStatus_FuncPtr[32] = FH_PWMI_GetStatus_PWMI33;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_PWMI34
	FH_PWMI_GetStatus_FuncPtr[33] = FH_PWMI_GetStatus_PWMI34;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_PWMI35
	FH_PWMI_GetStatus_FuncPtr[34] = FH_PWMI_GetStatus_PWMI35;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_PWMI36
	FH_PWMI_GetStatus_FuncPtr[35] = FH_PWMI_GetStatus_PWMI36;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_PWMI37
	FH_PWMI_GetStatus_FuncPtr[36] = FH_PWMI_GetStatus_PWMI37;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_PWMI38
	FH_PWMI_GetStatus_FuncPtr[37] = FH_PWMI_GetStatus_PWMI38;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_PWMI39
	FH_PWMI_GetStatus_FuncPtr[38] = FH_PWMI_GetStatus_PWMI39;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_PWMI40
	FH_PWMI_GetStatus_FuncPtr[39] = FH_PWMI_GetStatus_PWMI40;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_PWMI41
	FH_PWMI_GetStatus_FuncPtr[40] = FH_PWMI_GetStatus_PWMI41;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_PWMI42
	FH_PWMI_GetStatus_FuncPtr[41] = FH_PWMI_GetStatus_PWMI42;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_PWMI43
	FH_PWMI_GetStatus_FuncPtr[42] = FH_PWMI_GetStatus_PWMI43;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_PWMI44
	FH_PWMI_GetStatus_FuncPtr[43] = FH_PWMI_GetStatus_PWMI44;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_PWMI45
	FH_PWMI_GetStatus_FuncPtr[44] = FH_PWMI_GetStatus_PWMI45;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_PWMI46
	FH_PWMI_GetStatus_FuncPtr[45] = FH_PWMI_GetStatus_PWMI46;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_PWMI47
	FH_PWMI_GetStatus_FuncPtr[46] = FH_PWMI_GetStatus_PWMI47;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_PWMI48
	FH_PWMI_GetStatus_FuncPtr[47] = FH_PWMI_GetStatus_PWMI48;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_PWMI49
	FH_PWMI_GetStatus_FuncPtr[48] = FH_PWMI_GetStatus_PWMI49;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_PWMI50
	FH_PWMI_GetStatus_FuncPtr[49] = FH_PWMI_GetStatus_PWMI50;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_PWMI51
	FH_PWMI_GetStatus_FuncPtr[50] = FH_PWMI_GetStatus_PWMI51;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_PWMI52
	FH_PWMI_GetStatus_FuncPtr[51] = FH_PWMI_GetStatus_PWMI52;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_PWMI53
	FH_PWMI_GetStatus_FuncPtr[52] = FH_PWMI_GetStatus_PWMI53;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_PWMI54
	FH_PWMI_GetStatus_FuncPtr[53] = FH_PWMI_GetStatus_PWMI54;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_PWMI55
	FH_PWMI_GetStatus_FuncPtr[54] = FH_PWMI_GetStatus_PWMI55;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_PWMI56
	FH_PWMI_GetStatus_FuncPtr[55] = FH_PWMI_GetStatus_PWMI56;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_PWMI57
	FH_PWMI_GetStatus_FuncPtr[56] = FH_PWMI_GetStatus_PWMI57;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_PWMI58
	FH_PWMI_GetStatus_FuncPtr[57] = FH_PWMI_GetStatus_PWMI58;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_PWMI59
	FH_PWMI_GetStatus_FuncPtr[58] = FH_PWMI_GetStatus_PWMI59;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_PWMI60
	FH_PWMI_GetStatus_FuncPtr[59] = FH_PWMI_GetStatus_PWMI60;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_PWMI61
	FH_PWMI_GetStatus_FuncPtr[60] = FH_PWMI_GetStatus_PWMI61;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_PWMI62
	FH_PWMI_GetStatus_FuncPtr[61] = FH_PWMI_GetStatus_PWMI62;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_PWMI63
	FH_PWMI_GetStatus_FuncPtr[62] = FH_PWMI_GetStatus_PWMI63;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_PWMI64
	FH_PWMI_GetStatus_FuncPtr[63] = FH_PWMI_GetStatus_PWMI64;    // Set the function pointer address with the related function address
	#endif
}

#endif
