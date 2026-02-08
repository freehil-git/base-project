/**
  * @file
  * @brief
  *       <b>File Map:</b>\n
  *       <b>FH_Setup</b>, Section <b>FH_RFCommunication</b>\n
  *       The micro-controller on which <b>FH</b> source code is ported, could be simply utilized in a <b>RS485 network</b>\n
  *       In other word, multiple devices or multiple cards could be simply utilized where every device or every card has its own address\n
  *       Address of the device (or card) for every device (or card) is set by <b>FH</b> user in <b>FH_DeviceAddress.h</b>\n
  *       An interested UART (called <b>Communication Dedicated UART</b>) by the <b>FH</b> user for the communication between <b>RobotFramework</b> and the micro-controller on which <b>FH</b> source code is ported, shall be dedicated\n
  *       Global variables and arrays of <b>Communication Dedicated UART</b> are defined here
  *       This header file could be included whenever interested by <b>FH user</b>
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
#ifndef FH_RFCommunication_GlobalVariables_H
#define FH_RFCommunication_GlobalVariables_H

/* Includes ------------------------------------------------------------------*/
#include "../../../FH_Embedded/FH_Root/FH_General/FH_ErrorInfo/FH_ErrorInfo.h"
#include "../../../FH_Embedded/FH_Setup/FH_RFCommunication/FH_RFCommunication_Configs.h"

/*!
  <b>FH_RFCommunication_Message</b> is the structure for receiving the message frame from <b>RobotFramework</b>\n
*/
typedef struct
{
	/*!
      The 1st data in the message frame is the <b>DeviceAddress</b>\n
      If a message (from <b>RobotFramework</b>) with a different <b>DeviceAddress</b> than the one set in <b>FH_DeviceAddress.h</b> is received, it will be ignored and not processed
	*/
	uint8_t DeviceAddress;
	/*!
      The 2nd data in the message frame is the <b>Function</b>\n
      <b>Function</b> could be <b>DO</b> (Digital Output), <b>DI</b> (Digital Input), <b>AO</b> (Analog Output), <b>AI</b> (Analog Input), <b>UART</b>, <b>CAN</b> , ... in <b>FH_RFCommunication_Function<b>
	*/
	uint8_t Function;
	/*!
      The 3rd data in the message frame is the <b>Command</b>\n
      There are different commands for <b>DO</b> (Digital Output), <b>DI</b> (Digital Input), <b>AO</b> (Analog Output), <b>AI</b> (Analog Input), <b>UART</b>, <b>CAN</b> , ...\n
      For example for <b>DO</b> (Digital Output), different commands are available in <b>FH_DO_Configs.h</b>
	*/
	uint8_t Command;
	/*!
      The 4th data in the message frame is the <b>DataLength</b>\n
      It is the length of the Data in the message frame\n
      Since DataLength is just one byte, <b>Data</b> bytes can't be more than 255
	*/
	uint8_t DataLength;
	/*!
      The <b>Data</b> could be from 0 byte to up to (FH_RFCommunication_ReceiveBufLength - FH_RFCommunication_MinCommandSize) bytes\n
      Since DataLength is just one byte, <b>Data</b> bytes can't be more than 255\n
      <b>FH_RFCommunication_ReceiveBufLength</b> and <b>FH_RFCommunication_MinCommandSize</b> are configurable in <b>FH_RFCommunication_Configs.h</b>
	*/
	uint8_t Data[FH_RFCommunication_ReceiveBufLength - FH_RFCommunication_MinCommandSize];
	/*!
      The checksum of the message\n
	*/
	uint8_t Checksum;
}FH_RFCommunication_Message;

extern FH_RFCommunication_Message* fh_RFCommunication_Message;
extern volatile uint8_t FH_RFCommunication_ReceiveBuf[];
extern volatile uint16_t FH_RFCommunication_ReceiveBufIndex;
extern char FH_RFCommunication_SendBuf[];

#endif
