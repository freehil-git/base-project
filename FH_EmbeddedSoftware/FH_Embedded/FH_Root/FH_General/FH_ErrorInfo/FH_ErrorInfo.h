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
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef FH_ErrorInfo_H
#define FH_ErrorInfo_H

/* Includes ------------------------------------------------------------------*/
#include "stdint.h"

/*!
  To monitor different possible errors in different parts of the code, <b>FH_ErrorInfo</b> structure is utilized\n
  The <b>FH_ErrorInfo</b> is a structure where <b>error_code</b> and <b>error_message</b> are the members
  The error codes are all defined in FH_ErrorInfo.h
*/
typedef struct {
	/*!
	  Different unique error codes to monitor different possible errors in different parts of the code\n
	  The error codes are all defined in <b>FH_ErrorInfo.h</b>
	*/
	uint8_t error_code;
	/*!
	  Different human-readable error messages to monitor different possible errors in different parts of the code
	*/
	char   *error_message;
} FH_ErrorInfo;

//

/*!
  No information (Error codes related to <b>FH_ErrorInfo</b> structure)
*/
#define FH_ERROR_NoInfo          0
/*!
  No error (Error codes related to <b>FH_ErrorInfo</b> structure)
*/
#define FH_ERROR_OK              1
/*!
  User defined function error (in compared with FH defined error) (Error codes related to <b>FH_ErrorInfo</b> structure)
*/
#define FH_ERROR_Functions       2
/*!
  Timeout error (Error codes related to <b>FH_ErrorInfo</b> structure)
*/
#define FH_ERROR_Timeout         3
/*!
  Message Frame error (Error codes related to <b>FH_ErrorInfo</b> structure)
*/
#define FH_ERROR_MessageFrame    4
/*!
  FH defined function error (in compared with user defined error) (Error codes related to <b>FH_ErrorInfo</b> structure)
*/
#define FH_ERROR_Root            5
/*!
  General error (Error codes related to <b>FH_ErrorInfo</b> structure)
*/
#define FH_ERROR_General         6

/* Function Prototypes -----------------------------------------------------*/
void FH_ResetErrorInfo(FH_ErrorInfo *fh_ErrorInfo);

#endif // FH_ErrorInfo_H
