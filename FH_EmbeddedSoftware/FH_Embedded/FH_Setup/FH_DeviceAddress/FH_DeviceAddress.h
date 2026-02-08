/**
  * @file
  * @brief
  *       <b>File Map:</b>\n
  *       <b>FH_Setup</b>, Section <b>FH_DeviceAddress</b> \n
  *       <b>FH</b> user should set the device (or card) address here\n
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
#ifndef FH_DeviceAddress_H
#define FH_DeviceAddress_H

/*!
    The micro-controller on which <b>FH</b> source code is ported, could be simply utilized in a <b>RS485 network</b>\n
    In other word, multiple devices or multiple cards could be simply utilized where every device or every card has its own address\n
    Address of the device (or card) for every device (or card) is set here\n

    @attention
    FH_RFCommunication_Message is the structure for receiving the message frame from <b>RobotFramework</b>\n
    The first data in this structure is the <b>DeviceAddress</b>\n
    If a message (from <b>RobotFramework</b>) with a different <b>DeviceAddress</b> than the one set here is received, it will be ignored and not processed

    @note
    If there is just one device (or card), there is no need for the <b>FH</b> user to change the default address which is already <b>0x01</b>\n
    In this case, the address of the message in the message frame (in <b>RobotFramework</b>) shall be set to <b>01</b>

    @verbatim
    ==============================================================================
                          ##### RobotFramework Example #####
    ==============================================================================
    @{MessageData} =    Create List    ${DO01}    ${DO_Set}
    &{Message}     =    Create Dictionary    DeviceAddress=${DeviceAddress_01}    Function=${Function_DO}    Command=${DO_Commands_SetStatus}    Data=@{MessageData}
    ${Result}    SendMessage    &{Message}

    Comments:

    DO01 => It indicates the Digital Output 01
    DO_Set => It indicates the Digital Output 01 shall be Set (DO_Reset indicates the Digital Output 01 shall be Reset)
    DeviceAddress_01 => It shall be equal to the address of the device: FH_RFCommunication_DeviceAddress
    Function_DO => It is the function in the message frame
    DO_Commands_SetStatus => It is the command of the function in the message frame
    @endverbatim
*/

// Attention 1: FH user defined data (set the device or card address here: Maximum Possible Value is 0xFF)

#define FH_RFCommunication_DeviceAddress       0x01

//

#endif // FH_DeviceAddress_H
