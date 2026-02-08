/**
  * @file
  * @brief
  *       <b>File Map:</b>\n
  *       <b>FH_Root</b>, Section <b>FH_Perif</b>, <b>FH_AI</b> (Analog Input), <b>Cmd</b> (Command), <b>GetStatus</b>, <b>GetStatus_S</b> (GetStatus Set Address)\n
  *       Functions in this file, set the address of the defined <b>FH_Functions</b>, Section <b>FH_AI</b> (Analog Input), <b>FH_AI_GetStatus_AI01-...</b> to an array of function pointers
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
#include "../../../../../../../FH_Embedded/FH_Root/FH_Perif/FH_AI/Cmd/GetStatus/GetStatus_S/FH_AI_GetStatus_S.h"

#include "../../../../../../../FH_Embedded/FH_Root/FH_General/FH_GeneralFunctions/FH_GeneralFunctions.h"

#ifdef FH_AI01
#include "../../../../../../../FH_Embedded/FH_Functions/FH_AI/FH_AI01/FH_AI01.h"
#endif
#ifdef FH_AI02
#include "../../../../../../../FH_Embedded/FH_Functions/FH_AI/FH_AI02/FH_AI02.h"
#endif
#ifdef FH_AI03
#include "../../../../../../../FH_Embedded/FH_Functions/FH_AI/FH_AI03/FH_AI03.h"
#endif
#ifdef FH_AI04
#include "../../../../../../../FH_Embedded/FH_Functions/FH_AI/FH_AI04/FH_AI04.h"
#endif
#ifdef FH_AI05
#include "../../../../../../../FH_Embedded/FH_Functions/FH_AI/FH_AI05/FH_AI05.h"
#endif
#ifdef FH_AI06
#include "../../../../../../../FH_Embedded/FH_Functions/FH_AI/FH_AI06/FH_AI06.h"
#endif
#ifdef FH_AI07
#include "../../../../../../../FH_Embedded/FH_Functions/FH_AI/FH_AI07/FH_AI07.h"
#endif
#ifdef FH_AI08
#include "../../../../../../../FH_Embedded/FH_Functions/FH_AI/FH_AI08/FH_AI08.h"
#endif
#ifdef FH_AI09
#include "../../../../../../../FH_Embedded/FH_Functions/FH_AI/FH_AI09/FH_AI09.h"
#endif
#ifdef FH_AI10
#include "../../../../../../../FH_Embedded/FH_Functions/FH_AI/FH_AI10/FH_AI10.h"
#endif
#ifdef FH_AI11
#include "../../../../../../../FH_Embedded/FH_Functions/FH_AI/FH_AI11/FH_AI11.h"
#endif
#ifdef FH_AI12
#include "../../../../../../../FH_Embedded/FH_Functions/FH_AI/FH_AI12/FH_AI12.h"
#endif
#ifdef FH_AI13
#include "../../../../../../../FH_Embedded/FH_Functions/FH_AI/FH_AI13/FH_AI13.h"
#endif
#ifdef FH_AI14
#include "../../../../../../../FH_Embedded/FH_Functions/FH_AI/FH_AI14/FH_AI14.h"
#endif
#ifdef FH_AI15
#include "../../../../../../../FH_Embedded/FH_Functions/FH_AI/FH_AI15/FH_AI15.h"
#endif
#ifdef FH_AI16
#include "../../../../../../../FH_Embedded/FH_Functions/FH_AI/FH_AI16/FH_AI16.h"
#endif
#ifdef FH_AI17
#include "../../../../../../../FH_Embedded/FH_Functions/FH_AI/FH_AI17/FH_AI17.h"
#endif
#ifdef FH_AI18
#include "../../../../../../../FH_Embedded/FH_Functions/FH_AI/FH_AI18/FH_AI18.h"
#endif
#ifdef FH_AI19
#include "../../../../../../../FH_Embedded/FH_Functions/FH_AI/FH_AI19/FH_AI19.h"
#endif
#ifdef FH_AI20
#include "../../../../../../../FH_Embedded/FH_Functions/FH_AI/FH_AI20/FH_AI20.h"
#endif
#ifdef FH_AI21
#include "../../../../../../../FH_Embedded/FH_Functions/FH_AI/FH_AI21/FH_AI21.h"
#endif
#ifdef FH_AI22
#include "../../../../../../../FH_Embedded/FH_Functions/FH_AI/FH_AI22/FH_AI22.h"
#endif
#ifdef FH_AI23
#include "../../../../../../../FH_Embedded/FH_Functions/FH_AI/FH_AI23/FH_AI23.h"
#endif
#ifdef FH_AI24
#include "../../../../../../../FH_Embedded/FH_Functions/FH_AI/FH_AI24/FH_AI24.h"
#endif
#ifdef FH_AI25
#include "../../../../../../../FH_Embedded/FH_Functions/FH_AI/FH_AI25/FH_AI25.h"
#endif
#ifdef FH_AI26
#include "../../../../../../../FH_Embedded/FH_Functions/FH_AI/FH_AI26/FH_AI26.h"
#endif
#ifdef FH_AI27
#include "../../../../../../../FH_Embedded/FH_Functions/FH_AI/FH_AI27/FH_AI27.h"
#endif
#ifdef FH_AI28
#include "../../../../../../../FH_Embedded/FH_Functions/FH_AI/FH_AI28/FH_AI28.h"
#endif
#ifdef FH_AI29
#include "../../../../../../../FH_Embedded/FH_Functions/FH_AI/FH_AI29/FH_AI29.h"
#endif
#ifdef FH_AI30
#include "../../../../../../../FH_Embedded/FH_Functions/FH_AI/FH_AI30/FH_AI30.h"
#endif
#ifdef FH_AI31
#include "../../../../../../../FH_Embedded/FH_Functions/FH_AI/FH_AI31/FH_AI31.h"
#endif
#ifdef FH_AI32
#include "../../../../../../../FH_Embedded/FH_Functions/FH_AI/FH_AI32/FH_AI32.h"
#endif
#ifdef FH_AI33
#include "../../../../../../../FH_Embedded/FH_Functions/FH_AI/FH_AI33/FH_AI33.h"
#endif
#ifdef FH_AI34
#include "../../../../../../../FH_Embedded/FH_Functions/FH_AI/FH_AI34/FH_AI34.h"
#endif
#ifdef FH_AI35
#include "../../../../../../../FH_Embedded/FH_Functions/FH_AI/FH_AI35/FH_AI35.h"
#endif
#ifdef FH_AI36
#include "../../../../../../../FH_Embedded/FH_Functions/FH_AI/FH_AI36/FH_AI36.h"
#endif
#ifdef FH_AI37
#include "../../../../../../../FH_Embedded/FH_Functions/FH_AI/FH_AI37/FH_AI37.h"
#endif
#ifdef FH_AI38
#include "../../../../../../../FH_Embedded/FH_Functions/FH_AI/FH_AI38/FH_AI38.h"
#endif
#ifdef FH_AI39
#include "../../../../../../../FH_Embedded/FH_Functions/FH_AI/FH_AI39/FH_AI39.h"
#endif
#ifdef FH_AI40
#include "../../../../../../../FH_Embedded/FH_Functions/FH_AI/FH_AI40/FH_AI40.h"
#endif
#ifdef FH_AI41
#include "../../../../../../../FH_Embedded/FH_Functions/FH_AI/FH_AI41/FH_AI41.h"
#endif
#ifdef FH_AI42
#include "../../../../../../../FH_Embedded/FH_Functions/FH_AI/FH_AI42/FH_AI42.h"
#endif
#ifdef FH_AI43
#include "../../../../../../../FH_Embedded/FH_Functions/FH_AI/FH_AI43/FH_AI43.h"
#endif
#ifdef FH_AI44
#include "../../../../../../../FH_Embedded/FH_Functions/FH_AI/FH_AI44/FH_AI44.h"
#endif
#ifdef FH_AI45
#include "../../../../../../../FH_Embedded/FH_Functions/FH_AI/FH_AI45/FH_AI45.h"
#endif
#ifdef FH_AI46
#include "../../../../../../../FH_Embedded/FH_Functions/FH_AI/FH_AI46/FH_AI46.h"
#endif
#ifdef FH_AI47
#include "../../../../../../../FH_Embedded/FH_Functions/FH_AI/FH_AI47/FH_AI47.h"
#endif
#ifdef FH_AI48
#include "../../../../../../../FH_Embedded/FH_Functions/FH_AI/FH_AI48/FH_AI48.h"
#endif
#ifdef FH_AI49
#include "../../../../../../../FH_Embedded/FH_Functions/FH_AI/FH_AI49/FH_AI49.h"
#endif
#ifdef FH_AI50
#include "../../../../../../../FH_Embedded/FH_Functions/FH_AI/FH_AI50/FH_AI50.h"
#endif
#ifdef FH_AI51
#include "../../../../../../../FH_Embedded/FH_Functions/FH_AI/FH_AI51/FH_AI51.h"
#endif
#ifdef FH_AI52
#include "../../../../../../../FH_Embedded/FH_Functions/FH_AI/FH_AI52/FH_AI52.h"
#endif
#ifdef FH_AI53
#include "../../../../../../../FH_Embedded/FH_Functions/FH_AI/FH_AI53/FH_AI53.h"
#endif
#ifdef FH_AI54
#include "../../../../../../../FH_Embedded/FH_Functions/FH_AI/FH_AI54/FH_AI54.h"
#endif
#ifdef FH_AI55
#include "../../../../../../../FH_Embedded/FH_Functions/FH_AI/FH_AI55/FH_AI55.h"
#endif
#ifdef FH_AI56
#include "../../../../../../../FH_Embedded/FH_Functions/FH_AI/FH_AI56/FH_AI56.h"
#endif
#ifdef FH_AI57
#include "../../../../../../../FH_Embedded/FH_Functions/FH_AI/FH_AI57/FH_AI57.h"
#endif
#ifdef FH_AI58
#include "../../../../../../../FH_Embedded/FH_Functions/FH_AI/FH_AI58/FH_AI58.h"
#endif
#ifdef FH_AI59
#include "../../../../../../../FH_Embedded/FH_Functions/FH_AI/FH_AI59/FH_AI59.h"
#endif
#ifdef FH_AI60
#include "../../../../../../../FH_Embedded/FH_Functions/FH_AI/FH_AI60/FH_AI60.h"
#endif
#ifdef FH_AI61
#include "../../../../../../../FH_Embedded/FH_Functions/FH_AI/FH_AI61/FH_AI61.h"
#endif
#ifdef FH_AI62
#include "../../../../../../../FH_Embedded/FH_Functions/FH_AI/FH_AI62/FH_AI62.h"
#endif
#ifdef FH_AI63
#include "../../../../../../../FH_Embedded/FH_Functions/FH_AI/FH_AI63/FH_AI63.h"
#endif
#ifdef FH_AI64
#include "../../../../../../../FH_Embedded/FH_Functions/FH_AI/FH_AI64/FH_AI64.h"
#endif

#if FH_AI_MaxPeripheralNumber > 0    // It is configurable in FH_DevicePeripherals.h

/**
 * @brief This function sets the address of the defined <b>FH_Functions</b>, Section <b>FH_AI</b> (Analog Input), <b>FH_AI_GetStatus_AI01-...</b> to an array of function pointers
 *
 * @param  FH_AI_GetStatus_FuncPtr
 *         An array of function pointers with FH_AI_GetStatus_FuncPtrModel model
 *
 * @return None
 *

*/
void FH_AI_GetStatus_S(FH_AI_GetStatus_FuncPtrModel *FH_AI_GetStatus_FuncPtr)
{
	for (uint8_t i = 0; i < FH_AI_MaxPeripheralNumber; i++)    // if FH_AI_MaxPeripheralNumber > 0
	{
		FH_AI_GetStatus_FuncPtr[i] = NULL_PTR;    // Initialization of the function pointers with null pointer to prevent pointing to undefined addresses
	}

	#ifdef FH_AI01
	FH_AI_GetStatus_FuncPtr[0] = FH_AI_GetStatus_AI01;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_AI02
	FH_AI_GetStatus_FuncPtr[1] = FH_AI_GetStatus_AI02;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_AI03
	FH_AI_GetStatus_FuncPtr[2] = FH_AI_GetStatus_AI03;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_AI04
	FH_AI_GetStatus_FuncPtr[3] = FH_AI_GetStatus_AI04;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_AI05
	FH_AI_GetStatus_FuncPtr[4] = FH_AI_GetStatus_AI05;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_AI06
	FH_AI_GetStatus_FuncPtr[5] = FH_AI_GetStatus_AI06;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_AI07
	FH_AI_GetStatus_FuncPtr[6] = FH_AI_GetStatus_AI07;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_AI08
	FH_AI_GetStatus_FuncPtr[7] = FH_AI_GetStatus_AI08;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_AI09
	FH_AI_GetStatus_FuncPtr[8] = FH_AI_GetStatus_AI09;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_AI10
	FH_AI_GetStatus_FuncPtr[9] = FH_AI_GetStatus_AI10;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_AI11
	FH_AI_GetStatus_FuncPtr[10] = FH_AI_GetStatus_AI11;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_AI12
	FH_AI_GetStatus_FuncPtr[11] = FH_AI_GetStatus_AI12;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_AI13
	FH_AI_GetStatus_FuncPtr[12] = FH_AI_GetStatus_AI13;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_AI14
	FH_AI_GetStatus_FuncPtr[13] = FH_AI_GetStatus_AI14;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_AI15
	FH_AI_GetStatus_FuncPtr[14] = FH_AI_GetStatus_AI15;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_AI16
	FH_AI_GetStatus_FuncPtr[15] = FH_AI_GetStatus_AI16;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_AI17
	FH_AI_GetStatus_FuncPtr[16] = FH_AI_GetStatus_AI17;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_AI18
	FH_AI_GetStatus_FuncPtr[17] = FH_AI_GetStatus_AI18;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_AI19
	FH_AI_GetStatus_FuncPtr[18] = FH_AI_GetStatus_AI19;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_AI20
	FH_AI_GetStatus_FuncPtr[19] = FH_AI_GetStatus_AI20;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_AI21
	FH_AI_GetStatus_FuncPtr[20] = FH_AI_GetStatus_AI21;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_AI22
	FH_AI_GetStatus_FuncPtr[21] = FH_AI_GetStatus_AI22;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_AI23
	FH_AI_GetStatus_FuncPtr[22] = FH_AI_GetStatus_AI23;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_AI24
	FH_AI_GetStatus_FuncPtr[23] = FH_AI_GetStatus_AI24;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_AI25
	FH_AI_GetStatus_FuncPtr[24] = FH_AI_GetStatus_AI25;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_AI26
	FH_AI_GetStatus_FuncPtr[25] = FH_AI_GetStatus_AI26;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_AI27
	FH_AI_GetStatus_FuncPtr[26] = FH_AI_GetStatus_AI27;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_AI28
	FH_AI_GetStatus_FuncPtr[27] = FH_AI_GetStatus_AI28;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_AI29
	FH_AI_GetStatus_FuncPtr[28] = FH_AI_GetStatus_AI29;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_AI30
	FH_AI_GetStatus_FuncPtr[29] = FH_AI_GetStatus_AI30;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_AI31
	FH_AI_GetStatus_FuncPtr[30] = FH_AI_GetStatus_AI31;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_AI32
	FH_AI_GetStatus_FuncPtr[31] = FH_AI_GetStatus_AI32;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_AI33
	FH_AI_GetStatus_FuncPtr[32] = FH_AI_GetStatus_AI33;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_AI34
	FH_AI_GetStatus_FuncPtr[33] = FH_AI_GetStatus_AI34;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_AI35
	FH_AI_GetStatus_FuncPtr[34] = FH_AI_GetStatus_AI35;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_AI36
	FH_AI_GetStatus_FuncPtr[35] = FH_AI_GetStatus_AI36;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_AI37
	FH_AI_GetStatus_FuncPtr[36] = FH_AI_GetStatus_AI37;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_AI38
	FH_AI_GetStatus_FuncPtr[37] = FH_AI_GetStatus_AI38;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_AI39
	FH_AI_GetStatus_FuncPtr[38] = FH_AI_GetStatus_AI39;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_AI40
	FH_AI_GetStatus_FuncPtr[39] = FH_AI_GetStatus_AI40;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_AI41
	FH_AI_GetStatus_FuncPtr[40] = FH_AI_GetStatus_AI41;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_AI42
	FH_AI_GetStatus_FuncPtr[41] = FH_AI_GetStatus_AI42;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_AI43
	FH_AI_GetStatus_FuncPtr[42] = FH_AI_GetStatus_AI43;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_AI44
	FH_AI_GetStatus_FuncPtr[43] = FH_AI_GetStatus_AI44;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_AI45
	FH_AI_GetStatus_FuncPtr[44] = FH_AI_GetStatus_AI45;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_AI46
	FH_AI_GetStatus_FuncPtr[45] = FH_AI_GetStatus_AI46;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_AI47
	FH_AI_GetStatus_FuncPtr[46] = FH_AI_GetStatus_AI47;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_AI48
	FH_AI_GetStatus_FuncPtr[47] = FH_AI_GetStatus_AI48;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_AI49
	FH_AI_GetStatus_FuncPtr[48] = FH_AI_GetStatus_AI49;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_AI50
	FH_AI_GetStatus_FuncPtr[49] = FH_AI_GetStatus_AI50;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_AI51
	FH_AI_GetStatus_FuncPtr[50] = FH_AI_GetStatus_AI51;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_AI52
	FH_AI_GetStatus_FuncPtr[51] = FH_AI_GetStatus_AI52;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_AI53
	FH_AI_GetStatus_FuncPtr[52] = FH_AI_GetStatus_AI53;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_AI54
	FH_AI_GetStatus_FuncPtr[53] = FH_AI_GetStatus_AI54;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_AI55
	FH_AI_GetStatus_FuncPtr[54] = FH_AI_GetStatus_AI55;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_AI56
	FH_AI_GetStatus_FuncPtr[55] = FH_AI_GetStatus_AI56;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_AI57
	FH_AI_GetStatus_FuncPtr[56] = FH_AI_GetStatus_AI57;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_AI58
	FH_AI_GetStatus_FuncPtr[57] = FH_AI_GetStatus_AI58;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_AI59
	FH_AI_GetStatus_FuncPtr[58] = FH_AI_GetStatus_AI59;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_AI60
	FH_AI_GetStatus_FuncPtr[59] = FH_AI_GetStatus_AI60;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_AI61
	FH_AI_GetStatus_FuncPtr[60] = FH_AI_GetStatus_AI61;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_AI62
	FH_AI_GetStatus_FuncPtr[61] = FH_AI_GetStatus_AI62;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_AI63
	FH_AI_GetStatus_FuncPtr[62] = FH_AI_GetStatus_AI63;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_AI64
	FH_AI_GetStatus_FuncPtr[63] = FH_AI_GetStatus_AI64;    // Set the function pointer address with the related function address
	#endif
}

#endif
