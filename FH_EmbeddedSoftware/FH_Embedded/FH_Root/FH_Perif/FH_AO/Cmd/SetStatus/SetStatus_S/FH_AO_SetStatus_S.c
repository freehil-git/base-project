/**
  * @file
  * @brief
  *       <b>File Map:</b>\n
  *       <b>FH_Root</b>, Section <b>FH_Perif</b>, <b>FH_AO</b> (Analog Output), <b>Cmd</b> (Command), <b>SetStatus</b>, <b>SetStatus_S</b> (SetStatus Set Address)\n
  *       Functions in this file, set the address of the defined <b>FH_Functions</b>, Section <b>FH_AO</b> (Analog Output), <b>FH_AO_SetStatus_AO01-...</b> to an array of function pointers
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
#include "../../../../../../../FH_Embedded/FH_Root/FH_Perif/FH_AO/Cmd/SetStatus/SetStatus_S/FH_AO_SetStatus_S.h"

#include "../../../../../../../FH_Embedded/FH_Root/FH_General/FH_GeneralFunctions/FH_GeneralFunctions.h"

#ifdef FH_AO01
#include "../../../../../../../FH_Embedded/FH_Functions/FH_AO/FH_AO01/FH_AO01.h"
#endif
#ifdef FH_AO02
#include "../../../../../../../FH_Embedded/FH_Functions/FH_AO/FH_AO02/FH_AO02.h"
#endif
#ifdef FH_AO03
#include "../../../../../../../FH_Embedded/FH_Functions/FH_AO/FH_AO03/FH_AO03.h"
#endif
#ifdef FH_AO04
#include "../../../../../../../FH_Embedded/FH_Functions/FH_AO/FH_AO04/FH_AO04.h"
#endif
#ifdef FH_AO05
#include "../../../../../../../FH_Embedded/FH_Functions/FH_AO/FH_AO05/FH_AO05.h"
#endif
#ifdef FH_AO06
#include "../../../../../../../FH_Embedded/FH_Functions/FH_AO/FH_AO06/FH_AO06.h"
#endif
#ifdef FH_AO07
#include "../../../../../../../FH_Embedded/FH_Functions/FH_AO/FH_AO07/FH_AO07.h"
#endif
#ifdef FH_AO08
#include "../../../../../../../FH_Embedded/FH_Functions/FH_AO/FH_AO08/FH_AO08.h"
#endif
#ifdef FH_AO09
#include "../../../../../../../FH_Embedded/FH_Functions/FH_AO/FH_AO09/FH_AO09.h"
#endif
#ifdef FH_AO10
#include "../../../../../../../FH_Embedded/FH_Functions/FH_AO/FH_AO10/FH_AO10.h"
#endif
#ifdef FH_AO11
#include "../../../../../../../FH_Embedded/FH_Functions/FH_AO/FH_AO11/FH_AO11.h"
#endif
#ifdef FH_AO12
#include "../../../../../../../FH_Embedded/FH_Functions/FH_AO/FH_AO12/FH_AO12.h"
#endif
#ifdef FH_AO13
#include "../../../../../../../FH_Embedded/FH_Functions/FH_AO/FH_AO13/FH_AO13.h"
#endif
#ifdef FH_AO14
#include "../../../../../../../FH_Embedded/FH_Functions/FH_AO/FH_AO14/FH_AO14.h"
#endif
#ifdef FH_AO15
#include "../../../../../../../FH_Embedded/FH_Functions/FH_AO/FH_AO15/FH_AO15.h"
#endif
#ifdef FH_AO16
#include "../../../../../../../FH_Embedded/FH_Functions/FH_AO/FH_AO16/FH_AO16.h"
#endif
#ifdef FH_AO17
#include "../../../../../../../FH_Embedded/FH_Functions/FH_AO/FH_AO17/FH_AO17.h"
#endif
#ifdef FH_AO18
#include "../../../../../../../FH_Embedded/FH_Functions/FH_AO/FH_AO18/FH_AO18.h"
#endif
#ifdef FH_AO19
#include "../../../../../../../FH_Embedded/FH_Functions/FH_AO/FH_AO19/FH_AO19.h"
#endif
#ifdef FH_AO20
#include "../../../../../../../FH_Embedded/FH_Functions/FH_AO/FH_AO20/FH_AO20.h"
#endif
#ifdef FH_AO21
#include "../../../../../../../FH_Embedded/FH_Functions/FH_AO/FH_AO21/FH_AO21.h"
#endif
#ifdef FH_AO22
#include "../../../../../../../FH_Embedded/FH_Functions/FH_AO/FH_AO22/FH_AO22.h"
#endif
#ifdef FH_AO23
#include "../../../../../../../FH_Embedded/FH_Functions/FH_AO/FH_AO23/FH_AO23.h"
#endif
#ifdef FH_AO24
#include "../../../../../../../FH_Embedded/FH_Functions/FH_AO/FH_AO24/FH_AO24.h"
#endif
#ifdef FH_AO25
#include "../../../../../../../FH_Embedded/FH_Functions/FH_AO/FH_AO25/FH_AO25.h"
#endif
#ifdef FH_AO26
#include "../../../../../../../FH_Embedded/FH_Functions/FH_AO/FH_AO26/FH_AO26.h"
#endif
#ifdef FH_AO27
#include "../../../../../../../FH_Embedded/FH_Functions/FH_AO/FH_AO27/FH_AO27.h"
#endif
#ifdef FH_AO28
#include "../../../../../../../FH_Embedded/FH_Functions/FH_AO/FH_AO28/FH_AO28.h"
#endif
#ifdef FH_AO29
#include "../../../../../../../FH_Embedded/FH_Functions/FH_AO/FH_AO29/FH_AO29.h"
#endif
#ifdef FH_AO30
#include "../../../../../../../FH_Embedded/FH_Functions/FH_AO/FH_AO30/FH_AO30.h"
#endif
#ifdef FH_AO31
#include "../../../../../../../FH_Embedded/FH_Functions/FH_AO/FH_AO31/FH_AO31.h"
#endif
#ifdef FH_AO32
#include "../../../../../../../FH_Embedded/FH_Functions/FH_AO/FH_AO32/FH_AO32.h"
#endif
#ifdef FH_AO33
#include "../../../../../../../FH_Embedded/FH_Functions/FH_AO/FH_AO33/FH_AO33.h"
#endif
#ifdef FH_AO34
#include "../../../../../../../FH_Embedded/FH_Functions/FH_AO/FH_AO34/FH_AO34.h"
#endif
#ifdef FH_AO35
#include "../../../../../../../FH_Embedded/FH_Functions/FH_AO/FH_AO35/FH_AO35.h"
#endif
#ifdef FH_AO36
#include "../../../../../../../FH_Embedded/FH_Functions/FH_AO/FH_AO36/FH_AO36.h"
#endif
#ifdef FH_AO37
#include "../../../../../../../FH_Embedded/FH_Functions/FH_AO/FH_AO37/FH_AO37.h"
#endif
#ifdef FH_AO38
#include "../../../../../../../FH_Embedded/FH_Functions/FH_AO/FH_AO38/FH_AO38.h"
#endif
#ifdef FH_AO39
#include "../../../../../../../FH_Embedded/FH_Functions/FH_AO/FH_AO39/FH_AO39.h"
#endif
#ifdef FH_AO40
#include "../../../../../../../FH_Embedded/FH_Functions/FH_AO/FH_AO40/FH_AO40.h"
#endif
#ifdef FH_AO41
#include "../../../../../../../FH_Embedded/FH_Functions/FH_AO/FH_AO41/FH_AO41.h"
#endif
#ifdef FH_AO42
#include "../../../../../../../FH_Embedded/FH_Functions/FH_AO/FH_AO42/FH_AO42.h"
#endif
#ifdef FH_AO43
#include "../../../../../../../FH_Embedded/FH_Functions/FH_AO/FH_AO43/FH_AO43.h"
#endif
#ifdef FH_AO44
#include "../../../../../../../FH_Embedded/FH_Functions/FH_AO/FH_AO44/FH_AO44.h"
#endif
#ifdef FH_AO45
#include "../../../../../../../FH_Embedded/FH_Functions/FH_AO/FH_AO45/FH_AO45.h"
#endif
#ifdef FH_AO46
#include "../../../../../../../FH_Embedded/FH_Functions/FH_AO/FH_AO46/FH_AO46.h"
#endif
#ifdef FH_AO47
#include "../../../../../../../FH_Embedded/FH_Functions/FH_AO/FH_AO47/FH_AO47.h"
#endif
#ifdef FH_AO48
#include "../../../../../../../FH_Embedded/FH_Functions/FH_AO/FH_AO48/FH_AO48.h"
#endif
#ifdef FH_AO49
#include "../../../../../../../FH_Embedded/FH_Functions/FH_AO/FH_AO49/FH_AO49.h"
#endif
#ifdef FH_AO50
#include "../../../../../../../FH_Embedded/FH_Functions/FH_AO/FH_AO50/FH_AO50.h"
#endif
#ifdef FH_AO51
#include "../../../../../../../FH_Embedded/FH_Functions/FH_AO/FH_AO51/FH_AO51.h"
#endif
#ifdef FH_AO52
#include "../../../../../../../FH_Embedded/FH_Functions/FH_AO/FH_AO52/FH_AO52.h"
#endif
#ifdef FH_AO53
#include "../../../../../../../FH_Embedded/FH_Functions/FH_AO/FH_AO53/FH_AO53.h"
#endif
#ifdef FH_AO54
#include "../../../../../../../FH_Embedded/FH_Functions/FH_AO/FH_AO54/FH_AO54.h"
#endif
#ifdef FH_AO55
#include "../../../../../../../FH_Embedded/FH_Functions/FH_AO/FH_AO55/FH_AO55.h"
#endif
#ifdef FH_AO56
#include "../../../../../../../FH_Embedded/FH_Functions/FH_AO/FH_AO56/FH_AO56.h"
#endif
#ifdef FH_AO57
#include "../../../../../../../FH_Embedded/FH_Functions/FH_AO/FH_AO57/FH_AO57.h"
#endif
#ifdef FH_AO58
#include "../../../../../../../FH_Embedded/FH_Functions/FH_AO/FH_AO58/FH_AO58.h"
#endif
#ifdef FH_AO59
#include "../../../../../../../FH_Embedded/FH_Functions/FH_AO/FH_AO59/FH_AO59.h"
#endif
#ifdef FH_AO60
#include "../../../../../../../FH_Embedded/FH_Functions/FH_AO/FH_AO60/FH_AO60.h"
#endif
#ifdef FH_AO61
#include "../../../../../../../FH_Embedded/FH_Functions/FH_AO/FH_AO61/FH_AO61.h"
#endif
#ifdef FH_AO62
#include "../../../../../../../FH_Embedded/FH_Functions/FH_AO/FH_AO62/FH_AO62.h"
#endif
#ifdef FH_AO63
#include "../../../../../../../FH_Embedded/FH_Functions/FH_AO/FH_AO63/FH_AO63.h"
#endif
#ifdef FH_AO64
#include "../../../../../../../FH_Embedded/FH_Functions/FH_AO/FH_AO64/FH_AO64.h"
#endif

#if FH_AO_MaxPeripheralNumber > 0    // It is configurable in FH_DevicePeripherals.h

/**
 * @brief This function sets the address of the defined <b>FH_Functions</b>, Section <b>FH_AO</b> (Analog Output), <b>FH_AO_SetStatus_AO01-...</b> to an array of function pointers
 *
 * @param  FH_AO_SetStatus_FuncPtr
 *         An array of function pointers with FH_AO_SetStatus_FuncPtrModel model
 *
 * @return None
 *

*/
void FH_AO_SetStatus_S(FH_AO_SetStatus_FuncPtrModel *FH_AO_SetStatus_FuncPtr)
{
	for (uint8_t i = 0; i < FH_AO_MaxPeripheralNumber; i++)    // if FH_AO_MaxPeripheralNumber > 0
	{
		FH_AO_SetStatus_FuncPtr[i] = NULL_PTR;    // Initialization of the function pointers with null pointer to prevent pointing to undefined addresses
	}

	#ifdef FH_AO01
	FH_AO_SetStatus_FuncPtr[0] = FH_AO_SetStatus_AO01;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_AO02
	FH_AO_SetStatus_FuncPtr[1] = FH_AO_SetStatus_AO02;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_AO03
	FH_AO_SetStatus_FuncPtr[2] = FH_AO_SetStatus_AO03;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_AO04
	FH_AO_SetStatus_FuncPtr[3] = FH_AO_SetStatus_AO04;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_AO05
	FH_AO_SetStatus_FuncPtr[4] = FH_AO_SetStatus_AO05;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_AO06
	FH_AO_SetStatus_FuncPtr[5] = FH_AO_SetStatus_AO06;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_AO07
	FH_AO_SetStatus_FuncPtr[6] = FH_AO_SetStatus_AO07;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_AO08
	FH_AO_SetStatus_FuncPtr[7] = FH_AO_SetStatus_AO08;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_AO09
	FH_AO_SetStatus_FuncPtr[8] = FH_AO_SetStatus_AO09;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_AO10
	FH_AO_SetStatus_FuncPtr[9] = FH_AO_SetStatus_AO10;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_AO11
	FH_AO_SetStatus_FuncPtr[10] = FH_AO_SetStatus_AO11;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_AO12
	FH_AO_SetStatus_FuncPtr[11] = FH_AO_SetStatus_AO12;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_AO13
	FH_AO_SetStatus_FuncPtr[12] = FH_AO_SetStatus_AO13;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_AO14
	FH_AO_SetStatus_FuncPtr[13] = FH_AO_SetStatus_AO14;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_AO15
	FH_AO_SetStatus_FuncPtr[14] = FH_AO_SetStatus_AO15;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_AO16
	FH_AO_SetStatus_FuncPtr[15] = FH_AO_SetStatus_AO16;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_AO17
	FH_AO_SetStatus_FuncPtr[16] = FH_AO_SetStatus_AO17;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_AO18
	FH_AO_SetStatus_FuncPtr[17] = FH_AO_SetStatus_AO18;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_AO19
	FH_AO_SetStatus_FuncPtr[18] = FH_AO_SetStatus_AO19;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_AO20
	FH_AO_SetStatus_FuncPtr[19] = FH_AO_SetStatus_AO20;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_AO21
	FH_AO_SetStatus_FuncPtr[20] = FH_AO_SetStatus_AO21;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_AO22
	FH_AO_SetStatus_FuncPtr[21] = FH_AO_SetStatus_AO22;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_AO23
	FH_AO_SetStatus_FuncPtr[22] = FH_AO_SetStatus_AO23;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_AO24
	FH_AO_SetStatus_FuncPtr[23] = FH_AO_SetStatus_AO24;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_AO25
	FH_AO_SetStatus_FuncPtr[24] = FH_AO_SetStatus_AO25;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_AO26
	FH_AO_SetStatus_FuncPtr[25] = FH_AO_SetStatus_AO26;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_AO27
	FH_AO_SetStatus_FuncPtr[26] = FH_AO_SetStatus_AO27;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_AO28
	FH_AO_SetStatus_FuncPtr[27] = FH_AO_SetStatus_AO28;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_AO29
	FH_AO_SetStatus_FuncPtr[28] = FH_AO_SetStatus_AO29;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_AO30
	FH_AO_SetStatus_FuncPtr[29] = FH_AO_SetStatus_AO30;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_AO31
	FH_AO_SetStatus_FuncPtr[30] = FH_AO_SetStatus_AO31;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_AO32
	FH_AO_SetStatus_FuncPtr[31] = FH_AO_SetStatus_AO32;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_AO33
	FH_AO_SetStatus_FuncPtr[32] = FH_AO_SetStatus_AO33;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_AO34
	FH_AO_SetStatus_FuncPtr[33] = FH_AO_SetStatus_AO34;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_AO35
	FH_AO_SetStatus_FuncPtr[34] = FH_AO_SetStatus_AO35;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_AO36
	FH_AO_SetStatus_FuncPtr[35] = FH_AO_SetStatus_AO36;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_AO37
	FH_AO_SetStatus_FuncPtr[36] = FH_AO_SetStatus_AO37;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_AO38
	FH_AO_SetStatus_FuncPtr[37] = FH_AO_SetStatus_AO38;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_AO39
	FH_AO_SetStatus_FuncPtr[38] = FH_AO_SetStatus_AO39;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_AO40
	FH_AO_SetStatus_FuncPtr[39] = FH_AO_SetStatus_AO40;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_AO41
	FH_AO_SetStatus_FuncPtr[40] = FH_AO_SetStatus_AO41;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_AO42
	FH_AO_SetStatus_FuncPtr[41] = FH_AO_SetStatus_AO42;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_AO43
	FH_AO_SetStatus_FuncPtr[42] = FH_AO_SetStatus_AO43;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_AO44
	FH_AO_SetStatus_FuncPtr[43] = FH_AO_SetStatus_AO44;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_AO45
	FH_AO_SetStatus_FuncPtr[44] = FH_AO_SetStatus_AO45;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_AO46
	FH_AO_SetStatus_FuncPtr[45] = FH_AO_SetStatus_AO46;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_AO47
	FH_AO_SetStatus_FuncPtr[46] = FH_AO_SetStatus_AO47;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_AO48
	FH_AO_SetStatus_FuncPtr[47] = FH_AO_SetStatus_AO48;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_AO49
	FH_AO_SetStatus_FuncPtr[48] = FH_AO_SetStatus_AO49;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_AO50
	FH_AO_SetStatus_FuncPtr[49] = FH_AO_SetStatus_AO50;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_AO51
	FH_AO_SetStatus_FuncPtr[50] = FH_AO_SetStatus_AO51;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_AO52
	FH_AO_SetStatus_FuncPtr[51] = FH_AO_SetStatus_AO52;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_AO53
	FH_AO_SetStatus_FuncPtr[52] = FH_AO_SetStatus_AO53;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_AO54
	FH_AO_SetStatus_FuncPtr[53] = FH_AO_SetStatus_AO54;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_AO55
	FH_AO_SetStatus_FuncPtr[54] = FH_AO_SetStatus_AO55;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_AO56
	FH_AO_SetStatus_FuncPtr[55] = FH_AO_SetStatus_AO56;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_AO57
	FH_AO_SetStatus_FuncPtr[56] = FH_AO_SetStatus_AO57;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_AO58
	FH_AO_SetStatus_FuncPtr[57] = FH_AO_SetStatus_AO58;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_AO59
	FH_AO_SetStatus_FuncPtr[58] = FH_AO_SetStatus_AO59;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_AO60
	FH_AO_SetStatus_FuncPtr[59] = FH_AO_SetStatus_AO60;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_AO61
	FH_AO_SetStatus_FuncPtr[60] = FH_AO_SetStatus_AO61;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_AO62
	FH_AO_SetStatus_FuncPtr[61] = FH_AO_SetStatus_AO62;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_AO63
	FH_AO_SetStatus_FuncPtr[62] = FH_AO_SetStatus_AO63;    // Set the function pointer address with the related function address
	#endif
	#ifdef FH_AO64
	FH_AO_SetStatus_FuncPtr[63] = FH_AO_SetStatus_AO64;    // Set the function pointer address with the related function address
	#endif
}

#endif
