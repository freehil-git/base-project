/**
  * @file
  * @brief
  *       <b>File Map:</b>\n
  *       <b>FH_Root</b>, Section <b>FH_General</b>, <b>FH_ErrorInfo</b> \n
  *       To monitor different possible errors in different parts of the code, <b>FH_ErrorInfo</b> structure is utilized\n
  *       The <b>FH_ErrorInfo</b> is a structure where <b>error_code</b> and <b>error_message</b> are the members \n
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
#include "../../../../FH_Embedded/FH_Root/FH_General/FH_ErrorInfo/FH_ErrorInfo.h"

/**
 * @brief This function initializes the error information before calling different functions\n
 *        The <b>FH_ErrorInfo</b> is a structure where <b>error_code</b> and <b>error_message</b> are the members \n
 *        There are different error codes available which are all defined in <b>FH_ErrorInfo.h</b>\n
 *        This function initializes the <b>error code</b> with <b>FH_ERROR_NoInfo</b> and the <b>error message</b> with <b>""</b>
 *
 * @param fh_ErrorInfo
 *        it is a pointer to the structure <b>FH_ErrorInfo</b>
 *
 * @return None
 *
 * @note
 * In order not to initialize the fh_ErrorInfo repeatedly (whenever needed), this function is utilized\n
 *

*/
void FH_ResetErrorInfo(FH_ErrorInfo* fh_ErrorInfo)
{
	fh_ErrorInfo -> error_code = FH_ERROR_NoInfo;    // Initialize the error code with FH_ERROR_NoInfo as No Information
	fh_ErrorInfo -> error_message = "";    // Initialize the error message with "" as null human readable message
}
