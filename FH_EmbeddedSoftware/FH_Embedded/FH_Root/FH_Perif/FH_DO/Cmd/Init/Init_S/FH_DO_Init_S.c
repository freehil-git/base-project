/**
  * @file
  * @brief
  *       <b>File Map:</b>\n
  *       <b>FH_Root</b>, Section <b>FH_Perif</b>, <b>FH_DO</b> (Digital Output), <b>Cmd</b> (Command), <b>Init</b>, <b>Init_S</b> (Init Set Address)\n
  *       Functions in this file, set the address of the defined <b>FH_Functions</b>, Section <b>FH_DO</b> (Digital Output), <b>FH_DO_Init_DO01-...</b> to an array of function pointers
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
#include "../../../../../../../FH_Embedded/FH_Root/FH_Perif/FH_DO/Cmd/Init/Init_S/FH_DO_Init_S.h"

#include "../../../../../../../FH_Embedded/FH_Root/FH_General/FH_GeneralFunctions/FH_GeneralFunctions.h"

#ifdef FH_DO01
#include "../../../../../../../FH_Embedded/FH_Functions/FH_DO/FH_DO01/FH_DO01.h"
#endif
#ifdef FH_DO02
#include "../../../../../../../FH_Embedded/FH_Functions/FH_DO/FH_DO02/FH_DO02.h"
#endif
#ifdef FH_DO03
#include "../../../../../../../FH_Embedded/FH_Functions/FH_DO/FH_DO03/FH_DO03.h"
#endif
#ifdef FH_DO04
#include "../../../../../../../FH_Embedded/FH_Functions/FH_DO/FH_DO04/FH_DO04.h"
#endif
#ifdef FH_DO05
#include "../../../../../../../FH_Embedded/FH_Functions/FH_DO/FH_DO05/FH_DO05.h"
#endif
#ifdef FH_DO06
#include "../../../../../../../FH_Embedded/FH_Functions/FH_DO/FH_DO06/FH_DO06.h"
#endif
#ifdef FH_DO07
#include "../../../../../../../FH_Embedded/FH_Functions/FH_DO/FH_DO07/FH_DO07.h"
#endif
#ifdef FH_DO08
#include "../../../../../../../FH_Embedded/FH_Functions/FH_DO/FH_DO08/FH_DO08.h"
#endif
#ifdef FH_DO09
#include "../../../../../../../FH_Embedded/FH_Functions/FH_DO/FH_DO09/FH_DO09.h"
#endif
#ifdef FH_DO10
#include "../../../../../../../FH_Embedded/FH_Functions/FH_DO/FH_DO10/FH_DO10.h"
#endif
#ifdef FH_DO11
#include "../../../../../../../FH_Embedded/FH_Functions/FH_DO/FH_DO11/FH_DO11.h"
#endif
#ifdef FH_DO12
#include "../../../../../../../FH_Embedded/FH_Functions/FH_DO/FH_DO12/FH_DO12.h"
#endif
#ifdef FH_DO13
#include "../../../../../../../FH_Embedded/FH_Functions/FH_DO/FH_DO13/FH_DO13.h"
#endif
#ifdef FH_DO14
#include "../../../../../../../FH_Embedded/FH_Functions/FH_DO/FH_DO14/FH_DO14.h"
#endif
#ifdef FH_DO15
#include "../../../../../../../FH_Embedded/FH_Functions/FH_DO/FH_DO15/FH_DO15.h"
#endif
#ifdef FH_DO16
#include "../../../../../../../FH_Embedded/FH_Functions/FH_DO/FH_DO16/FH_DO16.h"
#endif
#ifdef FH_DO17
#include "../../../../../../../FH_Embedded/FH_Functions/FH_DO/FH_DO17/FH_DO17.h"
#endif
#ifdef FH_DO18
#include "../../../../../../../FH_Embedded/FH_Functions/FH_DO/FH_DO18/FH_DO18.h"
#endif
#ifdef FH_DO19
#include "../../../../../../../FH_Embedded/FH_Functions/FH_DO/FH_DO19/FH_DO19.h"
#endif
#ifdef FH_DO20
#include "../../../../../../../FH_Embedded/FH_Functions/FH_DO/FH_DO20/FH_DO20.h"
#endif
#ifdef FH_DO21
#include "../../../../../../../FH_Embedded/FH_Functions/FH_DO/FH_DO21/FH_DO21.h"
#endif
#ifdef FH_DO22
#include "../../../../../../../FH_Embedded/FH_Functions/FH_DO/FH_DO22/FH_DO22.h"
#endif
#ifdef FH_DO23
#include "../../../../../../../FH_Embedded/FH_Functions/FH_DO/FH_DO23/FH_DO23.h"
#endif
#ifdef FH_DO24
#include "../../../../../../../FH_Embedded/FH_Functions/FH_DO/FH_DO24/FH_DO24.h"
#endif
#ifdef FH_DO25
#include "../../../../../../../FH_Embedded/FH_Functions/FH_DO/FH_DO25/FH_DO25.h"
#endif
#ifdef FH_DO26
#include "../../../../../../../FH_Embedded/FH_Functions/FH_DO/FH_DO26/FH_DO26.h"
#endif
#ifdef FH_DO27
#include "../../../../../../../FH_Embedded/FH_Functions/FH_DO/FH_DO27/FH_DO27.h"
#endif
#ifdef FH_DO28
#include "../../../../../../../FH_Embedded/FH_Functions/FH_DO/FH_DO28/FH_DO28.h"
#endif
#ifdef FH_DO29
#include "../../../../../../../FH_Embedded/FH_Functions/FH_DO/FH_DO29/FH_DO29.h"
#endif
#ifdef FH_DO30
#include "../../../../../../../FH_Embedded/FH_Functions/FH_DO/FH_DO30/FH_DO30.h"
#endif
#ifdef FH_DO31
#include "../../../../../../../FH_Embedded/FH_Functions/FH_DO/FH_DO31/FH_DO31.h"
#endif
#ifdef FH_DO32
#include "../../../../../../../FH_Embedded/FH_Functions/FH_DO/FH_DO32/FH_DO32.h"
#endif
#ifdef FH_DO33
#include "../../../../../../../FH_Embedded/FH_Functions/FH_DO/FH_DO33/FH_DO33.h"
#endif
#ifdef FH_DO34
#include "../../../../../../../FH_Embedded/FH_Functions/FH_DO/FH_DO34/FH_DO34.h"
#endif
#ifdef FH_DO35
#include "../../../../../../../FH_Embedded/FH_Functions/FH_DO/FH_DO35/FH_DO35.h"
#endif
#ifdef FH_DO36
#include "../../../../../../../FH_Embedded/FH_Functions/FH_DO/FH_DO36/FH_DO36.h"
#endif
#ifdef FH_DO37
#include "../../../../../../../FH_Embedded/FH_Functions/FH_DO/FH_DO37/FH_DO37.h"
#endif
#ifdef FH_DO38
#include "../../../../../../../FH_Embedded/FH_Functions/FH_DO/FH_DO38/FH_DO38.h"
#endif
#ifdef FH_DO39
#include "../../../../../../../FH_Embedded/FH_Functions/FH_DO/FH_DO39/FH_DO39.h"
#endif
#ifdef FH_DO40
#include "../../../../../../../FH_Embedded/FH_Functions/FH_DO/FH_DO40/FH_DO40.h"
#endif
#ifdef FH_DO41
#include "../../../../../../../FH_Embedded/FH_Functions/FH_DO/FH_DO41/FH_DO41.h"
#endif
#ifdef FH_DO42
#include "../../../../../../../FH_Embedded/FH_Functions/FH_DO/FH_DO42/FH_DO42.h"
#endif
#ifdef FH_DO43
#include "../../../../../../../FH_Embedded/FH_Functions/FH_DO/FH_DO43/FH_DO43.h"
#endif
#ifdef FH_DO44
#include "../../../../../../../FH_Embedded/FH_Functions/FH_DO/FH_DO44/FH_DO44.h"
#endif
#ifdef FH_DO45
#include "../../../../../../../FH_Embedded/FH_Functions/FH_DO/FH_DO45/FH_DO45.h"
#endif
#ifdef FH_DO46
#include "../../../../../../../FH_Embedded/FH_Functions/FH_DO/FH_DO46/FH_DO46.h"
#endif
#ifdef FH_DO47
#include "../../../../../../../FH_Embedded/FH_Functions/FH_DO/FH_DO47/FH_DO47.h"
#endif
#ifdef FH_DO48
#include "../../../../../../../FH_Embedded/FH_Functions/FH_DO/FH_DO48/FH_DO48.h"
#endif
#ifdef FH_DO49
#include "../../../../../../../FH_Embedded/FH_Functions/FH_DO/FH_DO49/FH_DO49.h"
#endif
#ifdef FH_DO50
#include "../../../../../../../FH_Embedded/FH_Functions/FH_DO/FH_DO50/FH_DO50.h"
#endif
#ifdef FH_DO51
#include "../../../../../../../FH_Embedded/FH_Functions/FH_DO/FH_DO51/FH_DO51.h"
#endif
#ifdef FH_DO52
#include "../../../../../../../FH_Embedded/FH_Functions/FH_DO/FH_DO52/FH_DO52.h"
#endif
#ifdef FH_DO53
#include "../../../../../../../FH_Embedded/FH_Functions/FH_DO/FH_DO53/FH_DO53.h"
#endif
#ifdef FH_DO54
#include "../../../../../../../FH_Embedded/FH_Functions/FH_DO/FH_DO54/FH_DO54.h"
#endif
#ifdef FH_DO55
#include "../../../../../../../FH_Embedded/FH_Functions/FH_DO/FH_DO55/FH_DO55.h"
#endif
#ifdef FH_DO56
#include "../../../../../../../FH_Embedded/FH_Functions/FH_DO/FH_DO56/FH_DO56.h"
#endif
#ifdef FH_DO57
#include "../../../../../../../FH_Embedded/FH_Functions/FH_DO/FH_DO57/FH_DO57.h"
#endif
#ifdef FH_DO58
#include "../../../../../../../FH_Embedded/FH_Functions/FH_DO/FH_DO58/FH_DO58.h"
#endif
#ifdef FH_DO59
#include "../../../../../../../FH_Embedded/FH_Functions/FH_DO/FH_DO59/FH_DO59.h"
#endif
#ifdef FH_DO60
#include "../../../../../../../FH_Embedded/FH_Functions/FH_DO/FH_DO60/FH_DO60.h"
#endif
#ifdef FH_DO61
#include "../../../../../../../FH_Embedded/FH_Functions/FH_DO/FH_DO61/FH_DO61.h"
#endif
#ifdef FH_DO62
#include "../../../../../../../FH_Embedded/FH_Functions/FH_DO/FH_DO62/FH_DO62.h"
#endif
#ifdef FH_DO63
#include "../../../../../../../FH_Embedded/FH_Functions/FH_DO/FH_DO63/FH_DO63.h"
#endif
#ifdef FH_DO64
#include "../../../../../../../FH_Embedded/FH_Functions/FH_DO/FH_DO64/FH_DO64.h"
#endif

#if FH_DO_MaxPeripheralNumber > 0    // It is configurable in FH_DevicePeripherals.h

/**
 * @brief This function sets the address of the defined <b>FH_Functions</b>, Section <b>FH_DO</b> (Digital Output), <b>FH_DO_Init_DO01-...</b> to an array of function pointers
 *
 * @param  FH_DO_Init_FuncPtr
 *         An array of function pointers with FH_DO_Init_FuncPtrModel model
 *
 * @return None
 *

*/
void FH_DO_Init_S(FH_DO_Init_FuncPtrModel *FH_DO_Init_FuncPtr)
{
	for (uint8_t i = 0; i < FH_DO_MaxPeripheralNumber; i++)    // if FH_DO_MaxPeripheralNumber > 0
	{
		FH_DO_Init_FuncPtr[i] = NULL_PTR;    // Initialization of the function pointers with null pointer to prevent pointing to undefined addresses
	}

	#ifdef FH_DO01
	FH_DO_Init_FuncPtr[0] = FH_DO_Init_DO01;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_DO02
	FH_DO_Init_FuncPtr[1] = FH_DO_Init_DO02;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_DO03
	FH_DO_Init_FuncPtr[2] = FH_DO_Init_DO03;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_DO04
	FH_DO_Init_FuncPtr[3] = FH_DO_Init_DO04;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_DO05
	FH_DO_Init_FuncPtr[4] = FH_DO_Init_DO05;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_DO06
	FH_DO_Init_FuncPtr[5] = FH_DO_Init_DO06;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_DO07
	FH_DO_Init_FuncPtr[6] = FH_DO_Init_DO07;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_DO08
	FH_DO_Init_FuncPtr[7] = FH_DO_Init_DO08;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_DO09
	FH_DO_Init_FuncPtr[8] = FH_DO_Init_DO09;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_DO10
	FH_DO_Init_FuncPtr[9] = FH_DO_Init_DO10;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_DO11
	FH_DO_Init_FuncPtr[10] = FH_DO_Init_DO11;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_DO12
	FH_DO_Init_FuncPtr[11] = FH_DO_Init_DO12;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_DO13
	FH_DO_Init_FuncPtr[12] = FH_DO_Init_DO13;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_DO14
	FH_DO_Init_FuncPtr[13] = FH_DO_Init_DO14;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_DO15
	FH_DO_Init_FuncPtr[14] = FH_DO_Init_DO15;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_DO16
	FH_DO_Init_FuncPtr[15] = FH_DO_Init_DO16;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_DO17
	FH_DO_Init_FuncPtr[16] = FH_DO_Init_DO17;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_DO18
	FH_DO_Init_FuncPtr[17] = FH_DO_Init_DO18;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_DO19
	FH_DO_Init_FuncPtr[18] = FH_DO_Init_DO19;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_DO20
	FH_DO_Init_FuncPtr[19] = FH_DO_Init_DO20;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_DO21
	FH_DO_Init_FuncPtr[20] = FH_DO_Init_DO21;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_DO22
	FH_DO_Init_FuncPtr[21] = FH_DO_Init_DO22;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_DO23
	FH_DO_Init_FuncPtr[22] = FH_DO_Init_DO23;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_DO24
	FH_DO_Init_FuncPtr[23] = FH_DO_Init_DO24;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_DO25
	FH_DO_Init_FuncPtr[24] = FH_DO_Init_DO25;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_DO26
	FH_DO_Init_FuncPtr[25] = FH_DO_Init_DO26;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_DO27
	FH_DO_Init_FuncPtr[26] = FH_DO_Init_DO27;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_DO28
	FH_DO_Init_FuncPtr[27] = FH_DO_Init_DO28;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_DO29
	FH_DO_Init_FuncPtr[28] = FH_DO_Init_DO29;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_DO30
	FH_DO_Init_FuncPtr[29] = FH_DO_Init_DO30;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_DO31
	FH_DO_Init_FuncPtr[30] = FH_DO_Init_DO31;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_DO32
	FH_DO_Init_FuncPtr[31] = FH_DO_Init_DO32;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_DO33
	FH_DO_Init_FuncPtr[32] = FH_DO_Init_DO33;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_DO34
	FH_DO_Init_FuncPtr[33] = FH_DO_Init_DO34;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_DO35
	FH_DO_Init_FuncPtr[34] = FH_DO_Init_DO35;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_DO36
	FH_DO_Init_FuncPtr[35] = FH_DO_Init_DO36;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_DO37
	FH_DO_Init_FuncPtr[36] = FH_DO_Init_DO37;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_DO38
	FH_DO_Init_FuncPtr[37] = FH_DO_Init_DO38;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_DO39
	FH_DO_Init_FuncPtr[38] = FH_DO_Init_DO39;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_DO40
	FH_DO_Init_FuncPtr[39] = FH_DO_Init_DO40;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_DO41
	FH_DO_Init_FuncPtr[40] = FH_DO_Init_DO41;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_DO42
	FH_DO_Init_FuncPtr[41] = FH_DO_Init_DO42;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_DO43
	FH_DO_Init_FuncPtr[42] = FH_DO_Init_DO43;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_DO44
	FH_DO_Init_FuncPtr[43] = FH_DO_Init_DO44;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_DO45
	FH_DO_Init_FuncPtr[44] = FH_DO_Init_DO45;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_DO46
	FH_DO_Init_FuncPtr[45] = FH_DO_Init_DO46;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_DO47
	FH_DO_Init_FuncPtr[46] = FH_DO_Init_DO47;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_DO48
	FH_DO_Init_FuncPtr[47] = FH_DO_Init_DO48;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_DO49
	FH_DO_Init_FuncPtr[48] = FH_DO_Init_DO49;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_DO50
	FH_DO_Init_FuncPtr[49] = FH_DO_Init_DO50;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_DO51
	FH_DO_Init_FuncPtr[50] = FH_DO_Init_DO51;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_DO52
	FH_DO_Init_FuncPtr[51] = FH_DO_Init_DO52;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_DO53
	FH_DO_Init_FuncPtr[52] = FH_DO_Init_DO53;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_DO54
	FH_DO_Init_FuncPtr[53] = FH_DO_Init_DO54;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_DO55
	FH_DO_Init_FuncPtr[54] = FH_DO_Init_DO55;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_DO56
	FH_DO_Init_FuncPtr[55] = FH_DO_Init_DO56;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_DO57
	FH_DO_Init_FuncPtr[56] = FH_DO_Init_DO57;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_DO58
	FH_DO_Init_FuncPtr[57] = FH_DO_Init_DO58;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_DO59
	FH_DO_Init_FuncPtr[58] = FH_DO_Init_DO59;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_DO60
	FH_DO_Init_FuncPtr[59] = FH_DO_Init_DO60;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_DO61
	FH_DO_Init_FuncPtr[60] = FH_DO_Init_DO61;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_DO62
	FH_DO_Init_FuncPtr[61] = FH_DO_Init_DO62;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_DO63
	FH_DO_Init_FuncPtr[62] = FH_DO_Init_DO63;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_DO64
	FH_DO_Init_FuncPtr[63] = FH_DO_Init_DO64;    // Set the function pointer address with the related function address
	#endif
}

#endif
