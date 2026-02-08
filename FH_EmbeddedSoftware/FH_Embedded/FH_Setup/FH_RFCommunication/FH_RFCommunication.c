/**
  * @file
  * @brief
  *       <b>File Map:</b>\n
  *       <b>FH_Setup</b>, Section <b>FH_RFCommunication</b>\n
  *       This file is the main source of the communication between <b>RobotFramework</b> and the micro-controller on which <b>FH</b> source code is ported\n
  *       The micro-controller on which <b>FH</b> source code is ported, could be simply utilized in a <b>RS485 network</b>\n
  *       In other word, multiple devices or multiple cards could be simply utilized where every device or every card has its own address\n
  *       Address of the device (or card) for every device (or card) is set by <b>FH</b> user in <b>FH_DeviceAddress.h</b>\n
  *       An interested UART (called <b>Communication Dedicated UART</b>) by the <b>FH</b> user for the communication between <b>RobotFramework</b> and the micro-controller on which <b>FH</b> source code is ported, shall be dedicated\n
  *
  * @note To have a clean code, <b>FH</b> user should have the implementation of the initialization and send functions of the <b>Communication Dedicated UART</b> in a separate c file\n
  *       Then <b>FH</b> user should include the header file <b>(.h)</b> of the related source file <b>(.c)</b> here\n
  *       This header file shall include the following items:\n
  *       The declaration of the initialization function of the <b>Communication Dedicated UART</b>\n
  *       The declaration of the send function of the <b>Communication Dedicated UART</b>
  *
  * @note <b>FH</b> user shall use <b>FH_RFCommunication_ReceiveBuf</b> and <b>FH_RFCommunication_ReceiveBufIndex</b> in the receive <b>ISR</b> (Interrupt Service Routine) of the <b>Communication Dedicated UART</b> in a separate c file\n
  *       For this to happen, <b>FH</b> user shall just include <b>FH_RFCommunication_GlobalVariables.h</b> there\n
  *       In other word, <b>FH_RFCommunication_ReceiveBuf</b> array shall receive every byte of the received data there with <b>FH_RFCommunication_ReceiveBufIndex</b> as index of the array
  *
  * @attention
  *       <b>FH_RFCommunication_Message</b> is the structure for receiving the message frame from <b>RobotFramework</b>\n
  *       The first data in this structure is the <b>DeviceAddress</b>\n
  *       If a message (from <b>RobotFramework</b>) with a different <b>DeviceAddress</b> than the one set in <b>FH_DeviceAddress.h</b> is received, it will be ignored and not processed
  * @note
  *      If there is just one device (or card), there is no need for the <b>FH</b> user to change the default address which is already <b>0x01</b>\n
  *      In this case, the address of the message in the message frame (in <b>RobotFramework</b>) shall be set to <b>01</b>
  *
  * @verbatim
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
  *
  * @note If at least one byte of data is received through the <b>ISR</b> (Interrupt Service Routine) of the <b>Communication Dedicated UART</b> by the <b>FH</b> user, a complete message shall be received in a maximum defined timeout\n
  *       The received data in the <b>ISR</b> (Interrupt Service Routine) will be ignored if the complete message will not be received within the defined timeout\n
  *       For this to happen, <b>FH_GlobalTimeCounter</b> is utilized to calculate the maximum timeout\n
  *       <b>FH_RFCommunication_ReceiveBufMaxTimeout</b> is the defined maximum timeout for every byte\n
  *       In the <b>ISR</b> (Interrupt Service Routine) of the <b>Communication Dedicated UART</b> by the <b>FH</b> user, <b>FH_GlobalTimeCounter</b> shall be reset after receiving every byte of data
  *
  * @note If at least one byte of data is received through the <b>ISR</b> (Interrupt Service Routine) of the <b>Communication Dedicated UART</b> by the <b>FH</b> user, a complete message shall be received in a maximum defined timeout\n
  *       The received data in the <b>ISR</b> (Interrupt Service Routine) will be ignored if the complete message will not be received within the defined timeout\n
  *       For this to happen, <b>FH_GlobalTimeCounter</b> is utilized to calculate the maximum timeout\n
  *       <b>FH_RFCommunication_ReceiveBufMaxTimeout</b> is the defined maximum timeout for every byte\n
  *       In the <b>ISR</b> (Interrupt Service Routine) of the <b>Communication Dedicated UART</b> by the <b>FH</b> user, <b>FH_GlobalTimeCounter</b> shall be reset after receiving every byte of data
  *
  * @warning If <b>FH</b> user would not increment the <b>FH_GlobalTimeCounter</b> in a timer <b>ISR</b> (Interrupt Service Routine) every 1 mili-second, there will be a malfunction here
  *
  * @attention There are a total number of <b>3 attentions</b> (<b>FH</b> user defined code) in this file where <b>FH</b> user shall insert some code\n
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
/* Includes ------------------------------------------------------------------*/
#include "../../../FH_Embedded/FH_Setup/FH_RFCommunication/FH_RFCommunication.h"
// Attention 1: FH user defined code (include the mentioned header file here)

//
#include "../../FH_Root/FH_General/FH_GeneralFunctions/FH_GeneralFunctions.h"

#include "../../../FH_Embedded/FH_Root/FH_General/FH_GeneralFunctions/FH_GeneralFunctions.h"
#include "../../../FH_Embedded/FH_Root/FH_General/FH_GlobalTimerCount/FH_GlobalTimerCount.h"
#include "../../../FH_Embedded/FH_Root/FH_Perif/FH_AI/FH_AI.h"
#include "../../../FH_Embedded/FH_Root/FH_Perif/FH_AO/FH_AO.h"
#include "../../../FH_Embedded/FH_Root/FH_Perif/FH_CAN/FH_CAN.h"
#include "../../../FH_Embedded/FH_Root/FH_Perif/FH_DI/FH_DI.h"
#include "../../../FH_Embedded/FH_Root/FH_Perif/FH_DO/FH_DO.h"
#include "../../../FH_Embedded/FH_Root/FH_Perif/FH_PWMI/FH_PWMI.h"
#include "../../../FH_Embedded/FH_Root/FH_Perif/FH_PWMO/FH_PWMO.h"
#include "../../../FH_Embedded/FH_Root/FH_Perif/FH_UART/FH_UART.h"
#include "../../../FH_Embedded/FH_Setup/FH_DeviceAddress/FH_DeviceAddress.h"
#include "../../../FH_Embedded/FH_Setup/FH_RFCommunication/FH_RFCommunication_GlobalVariables.h"

/*!
  <b>FH</b> user shall use <b>FH_RFCommunication_ReceiveBuf</b> in the receive <b>ISR</b> (Interrupt Service Routine) of the <b>Communication Dedicated UART</b> in a separate c file\n
  For this to happen, FH user shall just include <b>FH_RFCommunication_GlobalVariables.h</b> there\n
  In other word, <b>FH_RFCommunication_ReceiveBuf</b> array shall receive every byte of the received data there\n
  It is configurable in <b>FH_RFCommunication_Configs.h</b>
*/
volatile uint8_t FH_RFCommunication_ReceiveBuf[FH_RFCommunication_ReceiveBufLength];

/*!
  <b>FH_RFCommunication_ReceiveBufIndex</b> is the index of <b>FH_RFCommunication_ReceiveBuf</b>
*/
volatile uint16_t FH_RFCommunication_ReceiveBufIndex;

/*!
  <b>FH_RFCommunication_SendBuf</b> is the data buffer for sending back the response to the received message through the <b>Communication Dedicated UART</b>\n
  In other word, it is the data buffer to send the response back to the <b>RobotFramework</b>
  It is configurable in <b>FH_RFCommunication_Configs.h</b>
*/
char FH_RFCommunication_SendBuf[FH_RFCommunication_SendBufLength];

/*!
  <b>FH_RFCommunication_ReceiveBufReadIndex</b> is the index of the data which is read from the <b>FH_RFCommunication_ReceiveBuf</b> to be processed\n
  It is used in <b>FH_RFCommunication_Receive</b> function to help process the received data through the <b>Communication Dedicated UART</b>
*/
volatile uint16_t FH_RFCommunication_ReceiveBufReadIndex  = 0;

/*!
  <b>FH_RFCommunication_Message_DataIndex</b> is the index of the data part of the message frame\n
  It is used in <b>FH_RFCommunication_Receive</b> function to help collect the received data part of the message frame through the <b>Communication Dedicated UART</b>
  For more information, refer to <b>FH_RFCommunication_Message</b>
*/
volatile uint16_t FH_RFCommunication_Message_DataIndex = 0;

/*!
   <b>FH_RFCommunication_Message</b> is the structure for receiving the message frame from <b>RobotFramework</b>\n
*/
FH_RFCommunication_Message* fh_RFCommunication_Message;

/*!
   <b>FH_RFCommunication_State</b> is the enumeration utilized as state machine to collect the different blocks of the message frame from <b>RobotFramework</b>\n
   It is initialized with <b>RFCommunication_STATE_IDLE</b> to be ready to collect a new message from <b>RobotFramework</b>
*/
volatile FH_RFCommunication_State fh_RFCommunication_State = RFCommunication_STATE_IDLE;

/**
 * @brief This function initializes the <b>Communication Dedicated UART</b>\n
 *        The <b>Communication Dedicated UART</b> could be any interested UART of the micro-controller on which <b>FH</b> source code is ported\n
 *        <b>FH</b> user should call the initialization function of the interested UART here
 *
 * @param  None
 *
 * @return FH_ErrorInfo is returned
 *
 * @note
 * To have a clean code, just include the related header file\n
 * Then just call the function here
 *
 * @warning
 * To be able to send or receive data through the <b>Communication Dedicated UART</b> of the micro-controller on which <b>FH</b> source code is ported, this function shall be invoked once in the <b>main.c</b> file firstly\n
 *

*/
FH_ErrorInfo FH_RFCommunication_Init ()
{
	FH_ErrorInfo fh_ErrorInfo;    // Error Information
	FH_ResetErrorInfo(&fh_ErrorInfo);    // Reset Error Information to default

	FH_RFCommunication_ReceiveBufIndex = 0;    // Reset FH_RFCommunication_ReceiveBufIndex

	// Attention 2: FH user defined code (call the initialization function of the Communication Dedicated UART here)

	// YourInitializationFunctionName ();

	//

	return fh_ErrorInfo;
}

/**
 * @brief This function sends data through the <b>Communication Dedicated UART</b>\n
 *        The <b>Communication Dedicated UART</b> could be any interested UART of the micro-controller on which <b>FH</b> source code is ported\n
 *        <b>FH</b> user should call the send function of the interested UART here
 *
 * @param  DataString
 *         a null terminated string of data to be sent
 *
 * @return FH_ErrorInfo is returned
 *
 * @note
 * To have a clean code, just include the related header file\n
 * Then just call the function here
 *
 * @warning
 * To be able to send data through the <b>Communication Dedicated UART</b> of the micro-controller on which <b>FH</b> source code is ported, the <b>FH_RFCommunication_Init</b> function shall be invoked once in the <b>main.c</b> file firstly\n
 *

*/
FH_ErrorInfo FH_RFCommunication_Send (char* DataString)
{
	FH_ErrorInfo fh_ErrorInfo;    // Error Information
	FH_ResetErrorInfo(&fh_ErrorInfo);    // Reset Error Information to default

	// Attention 3: FH user defined code (call the send process function of the Communication Dedicated UART here with DataString as argument)
	// Hint: The prototype of the send process function should be something like YourSendProcessFunctionName(uint8_t* Data);

	// YourSendProcessFunctionName (DataString);

	//

	return fh_ErrorInfo;
}

/**
  * @brief
  *       This function is the main source of receiving a complete message from <b>RobotFramework</b>\n
  *       The micro-controller on which <b>FH</b> source code is ported, could be simply utilized in a <b>RS485 network</b>\n
  *       In other word, multiple devices or multiple cards could be simply utilized where every device or every card has its own address\n
  *       Address of the device (or card) for every device (or card) is set by <b>FH</b> user in <b>FH_DeviceAddress.h</b>\n
  *       An interested UART (called <b>Communication Dedicated UART</b>) by the <b>FH</b> user for the communication between <b>RobotFramework</b> and the micro-controller on which <b>FH</b> source code is ported, shall be dedicated\n
  *
  * @param  None
  *
  * @return FH_ErrorInfo is returned
  *
  * @note <b>FH</b> user shall use <b>FH_RFCommunication_ReceiveBuf</b> and <b>FH_RFCommunication_ReceiveBufIndex</b> in the receive <b>ISR</b> (Interrupt Service Routine) of the <b>Communication Dedicated UART</b> in a separate c file\n
  *       For this to happen, <b>FH</b> user shall just include <b>FH_RFCommunication_GlobalVariables.h</b> there\n
  *       In other word, <b>FH_RFCommunication_ReceiveBuf</b> array shall receive every byte of the received data there with <b>FH_RFCommunication_ReceiveBufIndex</b> as index of the array
  *
  * @attention
  *       <b>FH_RFCommunication_Message</b> is the structure for receiving the message frame from <b>RobotFramework</b>\n
  *       The first data in this structure is the <b>DeviceAddress</b>\n
  *       If a message (from <b>RobotFramework</b>) with a different <b>DeviceAddress</b> than the one set in <b>FH_DeviceAddress.h</b> is received, it will be ignored and not processed
  *
  * @note
  *      If there is just one device (or card), there is no need for the <b>FH</b> user to change the default address which is already <b>0x01</b>\n
  *      In this case, the address of the message in the message frame (in <b>RobotFramework</b>) shall be set to <b>01</b>
  *
  * @verbatim
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
  *
  * @note If at least one byte of data is received through the <b>ISR</b> (Interrupt Service Routine) of the <b>Communication Dedicated UART</b> by the <b>FH</b> user, a complete message shall be received in a maximum defined timeout\n
  *       The received data in the <b>ISR</b> (Interrupt Service Routine) will be ignored if the complete message will not be received within the defined timeout\n
  *       For this to happen, <b>FH_GlobalTimeCounter</b> is utilized to calculate the maximum timeout\n
  *       <b>FH_RFCommunication_ReceiveBufMaxTimeout</b> is the defined maximum timeout for every byte\n
  *       In the <b>ISR</b> (Interrupt Service Routine) of the <b>Communication Dedicated UART</b> by the <b>FH</b> user, <b>FH_GlobalTimeCounter</b> shall be reset after receiving every byte of data
  *
  * @note If at least one byte of data is received through the <b>ISR</b> (Interrupt Service Routine) of the <b>Communication Dedicated UART</b> by the <b>FH</b> user, a complete message shall be received in a maximum defined timeout\n
  *       The received data in the <b>ISR</b> (Interrupt Service Routine) will be ignored if the complete message will not be received within the defined timeout\n
  *       For this to happen, <b>FH_GlobalTimeCounter</b> is utilized to calculate the maximum timeout\n
  *       <b>FH_RFCommunication_ReceiveBufMaxTimeout</b> is the defined maximum timeout for every byte\n
  *       In the <b>ISR</b> (Interrupt Service Routine) of the <b>Communication Dedicated UART</b> by the <b>FH</b> user, <b>FH_GlobalTimeCounter</b> shall be reset after receiving every byte of data
  *
  * @warning If <b>FH</b> user would not increment the <b>FH_GlobalTimeCounter</b> in a timer <b>ISR</b> (Interrupt Service Routine) every 1 mili-second, there will be a malfunction here
  *
  * @attention <b>FH</b> user could left this function intact
  *
  * @note
  *      <b>FH_RFCommunication_Message</b> is the structure for receiving the message frame from <b>RobotFramework</b>\n
  *      <b>FH_RFCommunication_State</b> is the enumeration utilized as state machine to collect the different blocks of the message frame from <b>RobotFramework</b>\n
  *      It is initialized with <b>RFCommunication_STATE_IDLE</b> to be ready to collect a new message from <b>RobotFramework</b>
  *
  * @note
  *      <b>FH_RFCommunication_ReceiveBufReadIndex</b> is the index of the data which is read from the <b>FH_RFCommunication_ReceiveBuf</b> to be processed\n
  *      It is used to help process the received data through the <b>Communication Dedicated UART</b>
  *
  * @note
  *      <b>FH_RFCommunication_Message_DataIndex</b> is the index of the data part of the message frame\n
  *      It is used in <b>FH_RFCommunication_Receive</b> function to help collect the received data part of the message frame through the <b>Communication Dedicated UART</b>
  *      For more information, refer to <b>FH_RFCommunication_Message</b>
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
FH_ErrorInfo FH_RFCommunication_Receive()
{
	FH_ErrorInfo fh_ErrorInfo;    // Error Information
	FH_ResetErrorInfo(&fh_ErrorInfo);    // Reset Error Information to default

	if (FH_RFCommunication_ReceiveBufIndex > 0)    // If there is at least one byte of data available in the ISR (Interrupt Service Routine)
	{
		FH_RFCommunication_ReceiveBufReadIndex = 0;    // The index of the data which is read from the FH_RFCommunication_ReceiveBuf
		fh_RFCommunication_State = RFCommunication_STATE_DeviceAddress;    // The state to verify the device (or card) address
		FH_RFCommunication_Message_DataIndex = 0;    // The index of the data part of the message frame

		while (fh_RFCommunication_State !=  RFCommunication_STATE_MessageReceived &&    // Loop till receiving a complete message
				FH_GlobalTimeCounter < FH_RFCommunication_ReceiveBufMaxTimeout)    // Loop timeout till receiving a complete message (Exit the loop if the timer counter exceeds the FH_RFCommunication_ReceiveBufMaxTimeout)
		{
			if (FH_RFCommunication_ReceiveBufReadIndex < FH_RFCommunication_ReceiveBufIndex)    // If there is yet at least one byte of data in FH_RFCommunication_ReceiveBuf which is not yet read
			{
				switch (fh_RFCommunication_State)    // Check different states
				{
					case RFCommunication_STATE_DeviceAddress:    // The state to receive the device (or card) address of the message
						if (FH_RFCommunication_ReceiveBufReadIndex == RFCommunication_DeviceAddress)    // If the read index is on the device address part of the message
						{
							if (FH_RFCommunication_ReceiveBuf[RFCommunication_DeviceAddress] == FH_RFCommunication_DeviceAddress)    // If the device (or card) address in the message is true
							{
								fh_RFCommunication_Message -> DeviceAddress = FH_RFCommunication_ReceiveBuf[RFCommunication_DeviceAddress];    // Set the device (or card) address part of the message
								fh_RFCommunication_State = RFCommunication_STATE_Function;    // Go to the next state which is the function part of the message
								FH_RFCommunication_ReceiveBufReadIndex = FH_RFCommunication_ReceiveBufReadIndex + 1;    // Increase the index of the data which is read from the FH_RFCommunication_ReceiveBuf
							}
							else    // If the device (or card) address in the message is not true
							{
								FH_RFCommunication_ReceiveBufIndex = 0;    // Reset the index of the receive buffer
								fh_RFCommunication_State = RFCommunication_STATE_IDLE;    // Go to the RFCommunication_STATE_IDLE state
								fh_ErrorInfo.error_code =  FH_ERROR_MessageFrame;    // There is FH_ERROR_MessageFrame error
								return fh_ErrorInfo;
							}
						}
						break;
					case RFCommunication_STATE_Function:    // The state to receive the function part of the message
					    if (FH_RFCommunication_ReceiveBufReadIndex == RFCommunication_Function)    // If the read index is on the function part of the message
						{
							fh_RFCommunication_Message  -> Function = FH_RFCommunication_ReceiveBuf[RFCommunication_Function];    // Set the function part of the message
							fh_RFCommunication_State = RFCommunication_STATE_Command;    // Go to the next state which is the command part of the message
							FH_RFCommunication_ReceiveBufReadIndex = FH_RFCommunication_ReceiveBufReadIndex + 1;    // Increase the index of the data which is read from the FH_RFCommunication_ReceiveBuf
						}
						break;
					case RFCommunication_STATE_Command:    // The state to receive the command part of the message
						if (FH_RFCommunication_ReceiveBufReadIndex == RFCommunication_Command)    // If the read index is on the command part of the message
						{
							fh_RFCommunication_Message -> Command = FH_RFCommunication_ReceiveBuf[RFCommunication_Command];    // Set the command part of the message
							fh_RFCommunication_State = RFCommunication_STATE_DataLength;    // Go to the next state which is the data length part of the message
							FH_RFCommunication_ReceiveBufReadIndex = FH_RFCommunication_ReceiveBufReadIndex + 1;    // Increase the index of the data which is read from the FH_RFCommunication_ReceiveBuf
						}
						break;
					case RFCommunication_STATE_DataLength:    // The state to receive the data length part of the message
						if (FH_RFCommunication_ReceiveBufReadIndex == RFCommunication_DataLength)    // If the read index is on the data length part of the message
						{
							fh_RFCommunication_Message -> DataLength = FH_RFCommunication_ReceiveBuf[RFCommunication_DataLength];    // Set the data length part of the message
							fh_RFCommunication_State = RFCommunication_STATE_Data;    // Go to the next state which is the data part of the message
							FH_RFCommunication_ReceiveBufReadIndex = FH_RFCommunication_ReceiveBufReadIndex + 1;    // Increase the index of the data which is read from the FH_RFCommunication_ReceiveBuf
						}
						break;
					case RFCommunication_STATE_Data:    // The state to receive the data part of the message (Which may be more than one bytes of data)
					    if (FH_RFCommunication_ReceiveBufReadIndex < (fh_RFCommunication_Message -> DataLength + FH_RFCommunication_MinCommandSize - 1))    // If the read index is yet on the data part of the message
						{
							fh_RFCommunication_Message -> Data[FH_RFCommunication_Message_DataIndex++] = FH_RFCommunication_ReceiveBuf[FH_RFCommunication_ReceiveBufReadIndex];    // Set the data part of the message one by one
							FH_RFCommunication_ReceiveBufReadIndex = FH_RFCommunication_ReceiveBufReadIndex + 1;    // Increase the index of the data which is read from the FH_RFCommunication_ReceiveBuf
						}
						else
						{
							fh_RFCommunication_State = RFCommunication_STATE_Checksum;    // Go to the next state which is the checksum part of the message
						}
						break;
					case RFCommunication_STATE_Checksum:    // The state to receive the checksum part of the message
						if (FH_RFCommunication_ReceiveBufReadIndex == (fh_RFCommunication_Message -> DataLength + FH_RFCommunication_MinCommandSize - 1))    // If the read index is on the checksum part of the message
						{
							fh_RFCommunication_Message -> Checksum = FH_RFCommunication_ReceiveBuf[FH_RFCommunication_ReceiveBufReadIndex];    // Set the checksum part of the message
							// For user-friendly design purposes, not implemented => always 0xAA
							//if ()    // If the checksum is true
							//{
								fh_RFCommunication_State = RFCommunication_STATE_MessageReceived;    // A complete message is received (Exit the loop)
							//}
							//else    // If the checksum is not true
							//{
								// FH_RFCommunication_ReceiveBufIndex = 0;    // Reset the index of the receive buffer
								// fh_RFCommunication_State = RFCommunication_STATE_IDLE;
								// fh_ErrorInfo.error_code =  FH_ERROR_MessageFrame;
								// return fh_ErrorInfo;
							//}
						}
						break;
					case RFCommunication_STATE_MessageReceived:    // A complete message is received and the loop ends up
						break;
					default:
						break;
				}
			}
		}
		
		FH_RFCommunication_ReceiveBufIndex = 0;    // Reset the index of the receive buffer
		if (fh_RFCommunication_State == RFCommunication_STATE_MessageReceived)    // If a  complete message is received
		{
		    fh_RFCommunication_State = RFCommunication_STATE_IDLE;    // Ready to collect a new message
			fh_ErrorInfo.error_code =  FH_ERROR_OK;    // There is no error and a complete message is received
			return fh_ErrorInfo;
		}
		else    // A complete message is not received within the specified timeout
		{
			fh_RFCommunication_State = RFCommunication_STATE_IDLE;    // Ready to collect a new message
			fh_ErrorInfo.error_code =  FH_ERROR_Timeout;    // There is timeout error
			return fh_ErrorInfo;
		}
	}
	else    // If there is not at least one byte of data available in the ISR (Interrupt Service Routine)
	{
		fh_ErrorInfo.error_code = FH_ERROR_NoInfo;    // There is no information yet
		return fh_ErrorInfo;
	}

}

/**
  * @brief
  *       This function verifies if a complete message from <b>RobotFramework</b> is received or not and if yes, calls the related function\n
  *       The micro-controller on which <b>FH</b> source code is ported, could be simply utilized in a <b>RS485 network</b>\n
  *       In other word, multiple devices or multiple cards could be simply utilized where every device or every card has its own address\n
  *       Address of the device (or card) for every device (or card) is set by <b>FH</b> user in <b>FH_DeviceAddress.h</b>\n
  *       An interested UART (called <b>Communication Dedicated UART</b>) by the <b>FH</b> user for the communication between <b>RobotFramework</b> and the micro-controller on which <b>FH</b> source code is ported, shall be dedicated\n
  *
  * @param  None
  *
  * @return FH_ErrorInfo is returned
  *
  * @note <b>FH</b> user shall use <b>FH_RFCommunication_ReceiveBuf</b> and <b>FH_RFCommunication_ReceiveBufIndex</b> in the receive <b>ISR</b> (Interrupt Service Routine) of the <b>Communication Dedicated UART</b> in a separate c file\n
  *       For this to happen, <b>FH</b> user shall just include <b>FH_RFCommunication_GlobalVariables.h</b> there\n
  *       In other word, <b>FH_RFCommunication_ReceiveBuf</b> array shall receive every byte of the received data there with <b>FH_RFCommunication_ReceiveBufIndex</b> as index of the array
  *
  * @attention
  *       <b>FH_RFCommunication_Message</b> is the structure for receiving the message frame from <b>RobotFramework</b>\n
  *       The first data in this structure is the <b>DeviceAddress</b>\n
  *       If a message (from <b>RobotFramework</b>) with a different <b>DeviceAddress</b> than the one set in <b>FH_DeviceAddress.h</b> is received, it will be ignored and not processed
  *
  * @note
  *      If there is just one device (or card), there is no need for the <b>FH</b> user to change the default address which is already <b>0x01</b>\n
  *      In this case, the address of the message in the message frame (in <b>RobotFramework</b>) shall be set to <b>01</b>
  *
  * @verbatim
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
  *
  * @note If at least one byte of data is received through the <b>ISR</b> (Interrupt Service Routine) of the <b>Communication Dedicated UART</b> by the <b>FH</b> user, a complete message shall be received in a maximum defined timeout\n
  *       The received data in the <b>ISR</b> (Interrupt Service Routine) will be ignored if the complete message will not be received within the defined timeout\n
  *       For this to happen, <b>FH_GlobalTimeCounter</b> is utilized to calculate the maximum timeout\n
  *       <b>FH_RFCommunication_ReceiveBufMaxTimeout</b> is the defined maximum timeout for every byte\n
  *       In the <b>ISR</b> (Interrupt Service Routine) of the <b>Communication Dedicated UART</b> by the <b>FH</b> user, <b>FH_GlobalTimeCounter</b> shall be reset after receiving every byte of data
  *
  * @note If at least one byte of data is received through the <b>ISR</b> (Interrupt Service Routine) of the <b>Communication Dedicated UART</b> by the <b>FH</b> user, a complete message shall be received in a maximum defined timeout\n
  *       The received data in the <b>ISR</b> (Interrupt Service Routine) will be ignored if the complete message will not be received within the defined timeout\n
  *       For this to happen, <b>FH_GlobalTimeCounter</b> is utilized to calculate the maximum timeout\n
  *       <b>FH_RFCommunication_ReceiveBufMaxTimeout</b> is the defined maximum timeout for every byte\n
  *       In the <b>ISR</b> (Interrupt Service Routine) of the <b>Communication Dedicated UART</b> by the <b>FH</b> user, <b>FH_GlobalTimeCounter</b> shall be reset after receiving every byte of data
  *
  * @warning If <b>FH</b> user would not increment the <b>FH_GlobalTimeCounter</b> in a timer <b>ISR</b> (Interrupt Service Routine) every 1 mili-second, there will be a malfunction here
  *
  * @attention <b>FH</b> user could left this function intact
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
FH_ErrorInfo FH_RFCommunication()
{
	FH_ErrorInfo fh_ErrorInfo;    // Error Information
	FH_ResetErrorInfo(&fh_ErrorInfo);    // Reset Error Information to default

	fh_ErrorInfo = FH_RFCommunication_Receive();    // Call the main source of receiving a complete message

	if (fh_ErrorInfo.error_code == FH_ERROR_OK)    // If there is no error and a complete message is received
	{
		switch (fh_RFCommunication_Message -> Function)    // Check different functions
		{
			case RFCommunication_Function_DO:    // If DO (Digital Output) function is received
				#if FH_DO_MaxPeripheralNumber > 0    // It is configurable in FH_DevicePeripherals.h
				fh_ErrorInfo = FH_DO_RFCommunication (fh_RFCommunication_Message);    // Process DO (Digital Output) function
				#endif
				break;
			case RFCommunication_Function_DI:    // If DI (Digital Input) function is received
				#if FH_DI_MaxPeripheralNumber > 0    // It is configurable in FH_DevicePeripherals.h
				fh_ErrorInfo = FH_DI_RFCommunication (fh_RFCommunication_Message);    // Process DI (Digital Input) function
				#endif
				break;
			case RFCommunication_Function_AO:    // If AO (Analog Output) function is received
				#if FH_AO_MaxPeripheralNumber > 0    // It is configurable in FH_DevicePeripherals.h
				fh_ErrorInfo = FH_AO_RFCommunication (fh_RFCommunication_Message);    // Process AO (Analog Output) function
				#endif
				break;
			case RFCommunication_Function_AI:    // If AI (Analog Input) function is received
				#if FH_AI_MaxPeripheralNumber > 0    // It is configurable in FH_DevicePeripherals.h
				fh_ErrorInfo = FH_AI_RFCommunication (fh_RFCommunication_Message);    // Process AI (Analog Input) function
				#endif
				break;
			case RFCommunication_Function_PWMO:    // If PWMO (PWM Output) function is received
				#if FH_PWMO_MaxPeripheralNumber > 0    // It is configurable in FH_DevicePeripherals.h
				fh_ErrorInfo = FH_PWMO_RFCommunication (fh_RFCommunication_Message);    // Process PWMO (PWM Output) function
				#endif
				break;
			case RFCommunication_Function_PWMI:    // If PWMI (PWM Input) function is received
				#if FH_PWMI_MaxPeripheralNumber > 0    // It is configurable in FH_DevicePeripherals.h
				fh_ErrorInfo = FH_PWMI_RFCommunication (fh_RFCommunication_Message);    // Process PWMI (PWM Input) function
				#endif
				break;
			case RFCommunication_Function_UART:    // If UART function is received
				#if FH_UART_MaxPeripheralNumber > 0    // It is configurable in FH_DevicePeripherals.h
				fh_ErrorInfo = FH_UART_RFCommunication (fh_RFCommunication_Message);    // Process UART function
				#endif
				break;
			case RFCommunication_Function_CAN:    // If CAN function is received
				#if FH_CAN_MaxPeripheralNumber > 0    // It is configurable in FH_DevicePeripherals.h
				fh_ErrorInfo = FH_CAN_RFCommunication (fh_RFCommunication_Message);    // Process CAN function
				#endif
				break;
			default:
				break;
		}
	}
	else
	{
	}

	return fh_ErrorInfo;
}
