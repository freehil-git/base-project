/**
  * @file
  * @brief
  *       <b>File Map:</b>\n
  *       <b>FH_Setup</b>, Section <b>FH_DevicePeripherals</b> \n
  *       <b>FH</b> user should set the maximum number of peripherals for his/her interested HIL Simulator here\n
  *
  *@note
  *Regarding the limitations of the interested micro-controller on which <b>FH</b> source code is ported (Memory, Peripherals , ...),\n
  *The number of the peripherals could be decreased to the minimum possible values\n
  *
  * @attention There are a total number of <b>1 attention</b> (Attention 1) (<b>FH</b> user defined data) in this file where <b>FH</b> user shall insert some data\n
  *            Other parts could be left intact
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
#ifndef FH_DevicePeripherals_H
#define FH_DevicePeripherals_H

// Attention 1: FH user defined data (set the maximum number of peripherals here)

/*!
  <b>FH_DO_MaxPeripheralNumber</b> is the maximum number of the DO (Digital Output)\n
  Minimum Possible Value is 0 and Maximum Possible Value is 64\n
*/
#define FH_DO_MaxPeripheralNumber      64

/*!
  <b>FH_DI_MaxPeripheralNumber</b> is the maximum number of the DI (Digital Input)\n
  Minimum Possible Value is 0 and Maximum Possible Value is 64\n
*/
#define FH_DI_MaxPeripheralNumber      64

/*!
  <b>FH_AO_MaxPeripheralNumber</b> is the maximum number of the AO (Analog Output)\n
  Minimum Possible Value is 0 and Maximum Possible Value is 64\n
*/
#define FH_AO_MaxPeripheralNumber      64

/*!
  <b>FH_AI_MaxPeripheralNumber</b> is the maximum number of the AI (Analog Input)\n
  Minimum Possible Value is 0 and Maximum Possible Value is 64\n
*/
#define FH_AI_MaxPeripheralNumber      64

/*!
  <b>FH_PWMO_MaxPeripheralNumber</b> is the maximum number of the PWMO (PWM Output)\n
  Minimum Possible Value is 0 and Maximum Possible Value is 64\n
*/
#define FH_PWMO_MaxPeripheralNumber    64

/*!
  <b>FH_PWMI_MaxPeripheralNumber</b> is the maximum number of the PWMI (PWM Input)\n
  Minimum Possible Value is 0 and Maximum Possible Value is 64\n
*/
#define FH_PWMI_MaxPeripheralNumber    64

/*!
  <b>FH_UART_MaxPeripheralNumber</b> is the maximum number of the UART\n
  Minimum Possible Value is 0 and Maximum Possible Value is 8\n
*/
#define FH_UART_MaxPeripheralNumber    8

/*!
  <b>FH_CAN_MaxPeripheralNumber</b> is the maximum number of the CAN\n
  Minimum Possible Value is 0 and Maximum Possible Value is 8\n
*/
#define FH_CAN_MaxPeripheralNumber     8

//

#endif // FH_DevicePeripherals_H
