/**
  * @file
  * @brief
  *       <b>File Map:</b>\n
  *       <b>FH_Setup</b>, Section <b>FH_RFCommunication</b>\n
  *       The micro-controller on which <b>FH</b> source code is ported, could be simply utilized in a <b>RS485 network</b>\n
  *       In other word, multiple devices or multiple cards could be simply utilized where every device or every card has its own address\n
  *       Address of the device (or card) for every device (or card) is set by <b>FH</b> user in <b>FH_DeviceAddress.h</b>\n
  *       An interested UART (called <b>Communication Dedicated UART</b>) by the <b>FH</b> user for the communication between <b>RobotFramework</b> and the micro-controller on which <b>FH</b> source code is ported, shall be dedicated\n
  *       Different configuration on the communication between <b>RobotFramework</b> and the micro-controller are defined here
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
#ifndef FH_RFCommunication_Configs_H
#define FH_RFCommunication_Configs_H

/* Includes ------------------------------------------------------------------*/
#include "../../../FH_Embedded/FH_Root/FH_General/FH_ErrorInfo/FH_ErrorInfo.h"

/*!
  <b>FH_RFCommunication_MinCommandSize</b> is the minimum size of the message frame (<b>FH_RFCommunication_Message</b>) from <b>RobotFramework</b> (When DataLength is zero and there is no Data)\n
    The minimum size includes the following items:
    1 - DeviceAddress (1 byte)
	2 - Function (1 byte)
	3 - Command (1 byte)
	4 - DataLength (1 byte) which is 0 for minimum size message
	5 - Data (0 byte) which is not available for minimum size message
	6 - Checksum (1 byte)
	=> Total 5 bytes of data
*/
#define FH_RFCommunication_MinCommandSize      5

/*!
  <b>FH_RFCommunication_ReceiveBufLength</b> is the receive buffer length of the buffer which is filled in the ISR (Interrupt Service Routine) <b>Communication Dedicated UART</b>\n
  255 is added to FH_RFCommunication_MinCommandSize to guarantee the maximum possible Data Length of 255 bytes in the Data part of the message
*/
#define FH_RFCommunication_ReceiveBufLength     255 + FH_RFCommunication_MinCommandSize

/*!
  If at least one byte of data is received through the <b>ISR</b> (Interrupt Service Routine) of the <b>Communication Dedicated UART</b> by the <b>FH</b> user, a complete message shall be received in a maximum defined timeout\n
  The received data in the <b>ISR</b> (Interrupt Service Routine) will be ignored if the complete message will not be received within the defined timeout\nFor this to happen, <b>FH_GlobalTimeCounter</b> is utilized to calculate the maximum timeout\n
  FH_RFCommunication_ReceiveBufMaxTimeout</b> is the defined maximum timeout for every byte\n
  In the <b>ISR</b> (Interrupt Service Routine) of the <b>Communication Dedicated UART</b> by the <b>FH</b> user, <b>FH_GlobalTimeCounter</b> shall be reset after receiving every byte of data\n
  For example, 100 is set to have 100ms timeout (When the heart beat of the system is 1 mili-second) to receive a complete message when there is no longer any data being received
*/
#define FH_RFCommunication_ReceiveBufMaxTimeout 100

#define FH_RFCommunication_SendBufLength       255 + FH_RFCommunication_MinCommandSize

/*!
  <b>FH_RFCommunication_Commandelements</b> includes the position of different parts of the message in the message frame (<b>FH_RFCommunication_Message</b>)
  Since the Data part may have different sizes, the checksum position may be different
*/
enum FH_RFCommunication_Commandelements
{
	/*!
      The 1st data in the message frame is the <b>DeviceAddress</b>\n
      If a message (from <b>RobotFramework</b>) with a different <b>DeviceAddress</b> than the one set in <b>FH_DeviceAddress.h</b> is received, it will be ignored and not processed
	*/
	RFCommunication_DeviceAddress      = 0,
	/*!
      The 2nd data in the message frame is the <b>Function</b>\n
      <b>Function</b> could be <b>DO</b> (Digital Output), <b>DI</b> (Digital Input), <b>AO</b> (Anolog Output), <b>AI</b> (Analog Input), <b>UART</b>, <b>CAN</b> , ... in <b>FH_RFCommunication_Function<b>
	*/
	RFCommunication_Function           = 1,
	/*!
      The 3rd data in the message frame is the <b>Command</b>\n
      There are different commands for <b>DO</b> (Digital Output), <b>DI</b> (Digital Input), <b>AO</b> (Anolog Output), <b>AI</b> (Analog Input), <b>UART</b>, <b>CAN</b> , ...\n
      For example for <b>DO</b> (Digital Output), different commands are available in <b>FH_DO_Configs.h</b>
	*/
	RFCommunication_Command            = 2,
	/*!
      The 4th data in the message frame is the <b>DataLength</b>\n
      It is the length of the Data in the message frame\n
      Since DataLength is just one byte, <b>Data</b> bytes can't be more than 255
	*/
	RFCommunication_DataLength         = 3,
	/*!
      The <b>Data</b> could be from 0 byte to up to (FH_RFCommunication_ReceiveBufLength - FH_RFCommunication_MinCommandSize) bytes\n
      Since DataLength is just one byte, <b>Data</b> bytes can't be more than 255\n
      <b>FH_RFCommunication_ReceiveBufLength</b> and <b>FH_RFCommunication_MinCommandSize</b> are configurable in this file (<b>FH_RFCommunication_Configs.h</b>)
	*/
	RFCommunication_Data               = 4,
	/*!
      The checksum of the message\n
	*/
	// RFCommunication_Checksum           = ?
};

/*!
  <b>FH_RFCommunication_Function</b> includes different possible functions of the message in the message frame (<b>FH_RFCommunication_Message</b>)
*/
enum FH_RFCommunication_Function
{
	/*!
      <b>DO</b> (Digital Output)
	*/
	RFCommunication_Function_DO      = 0,
	/*!
      <b>DI</b> (Digital Input)
	*/
	RFCommunication_Function_DI      = 1,
	/*!
      <b>AO</b> (Analog Output)
	*/
	RFCommunication_Function_AO      = 2,
	/*!
      <b>AI</b> (Analog Input)
	*/
	RFCommunication_Function_AI      = 3,
	/*!
      <b>PWMO</b> (PWM Output)
	*/
	RFCommunication_Function_PWMO    = 4,
	/*!
      <b>PWMI</b> (PWM Input)
	*/
	RFCommunication_Function_PWMI    = 5,
	/*!
      <b>UART</b>
	*/
	RFCommunication_Function_UART    = 6,
	/*!
      <b>CAN</b>
	*/
	RFCommunication_Function_CAN     = 7,
};

/*!
  <b>FH_RFCommunication_Message</b> is the structure for receiving the message frame from <b>RobotFramework</b>\n
  <b>FH_RFCommunication_State</b> is the enumeration utilized as state machine to collect the different blocks of the message frame from <b>RobotFramework</b>\n
  It is initialized with <b>RFCommunication_STATE_IDLE</b> to be ready to collect a new message from <b>RobotFramework</b>
*/
typedef enum
{
	/*!
      State to receive a new message
	*/
	RFCommunication_STATE_IDLE = 0           ,
	/*!
      State to receive DeviceAddress
	*/
	RFCommunication_STATE_DeviceAddress      ,
	/*!
      State to receive Function
	*/
	RFCommunication_STATE_Function           ,
	/*!
      State to receive Command
	*/
	RFCommunication_STATE_Command            ,
	/*!
      State to receive DataLength
	*/
	RFCommunication_STATE_DataLength         ,
	/*!
      State to receive Data
	*/
	RFCommunication_STATE_Data               ,
	/*!
      State to receive Checksum
	*/
	RFCommunication_STATE_Checksum           ,
	/*!
      State to indicate a complete message is already received
	*/
	RFCommunication_STATE_MessageReceived
} FH_RFCommunication_State;

#endif
