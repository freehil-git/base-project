/**
  * @file
  * @brief
  *       <b>File Map:</b>\n
  *       <b>FH_Setup</b>, Section <b>FH_RFCommunication</b>\n
  *       This file is header file of the main source file of the communication between <b>RobotFramework</b> and the micro-controller on which <b>FH</b> source code is ported\n
  *       The micro-controller on which <b>FH</b> source code is ported, could be simply utilized in a <b>RS485 network</b>\n
  *       In other word, multiple devices or multiple cards could be simply utilized where every device or every card has its own address\n
  *       Address of the device (or card) for every device (or card) is set by <b>FH</b> user in <b>FH_DeviceAddress.h</b>\n
  *       An interested UART (called <b>Communication Dedicated UART</b>) by the <b>FH</b> user for the communication between <b>RobotFramework</b> and the micro-controller on which <b>FH</b> source code is ported, shall be dedicated\n
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
#ifndef FH_CommandCenter_H
#define FH_CommandCenter_H

/* Includes ------------------------------------------------------------------*/
#include "../../../FH_Embedded/FH_Root/FH_General/FH_ErrorInfo/FH_ErrorInfo.h"

/* Function Prototypes -----------------------------------------------------*/
FH_ErrorInfo FH_RFCommunication ();
FH_ErrorInfo FH_RFCommunication_Init ();
FH_ErrorInfo FH_RFCommunication_Send (char* DataString);
FH_ErrorInfo FH_RFCommunication_Receive ();

#endif
