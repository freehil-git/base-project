/**
  * @file
  * @brief
  *       <b>File Map:</b>\n
  *       <b>FH_Functions</b>, Section <b>FH_UART</b>, Peripheral <b>FH_UART02</b> (UART 02)\n
  *       (The <b>UART02 (UART 02)</b> could be any interested UART of the micro-controller on which <b>FH</b> source code is ported)\n
  *
  * @note To have a clean code, <b>FH</b> user should have the implementation of the initialization and send functions of the <b>UART 02</b> in a separate c file\n
  *       Then <b>FH</b> user should include the header file <b>(.h)</b> of the related source file <b>(.c)</b> here\n
  *       This header file shall include the following items:\n
  *       The declaration of the initialization function of the <b>UART 02</b>\n
  *       The declaration of the send function of the <b>UART 02</b>\n\n
  *
  *       <b>FH</b> user shall use <b>FH_UART02_ReceiveBuf</b> and <b>FH_UART02_ReceiveBufIndex</b> in the receive <b>ISR</b> (Interrupt Service Routine) of the <b>UART 02</b> in a separate c file\n
  *       For this to happen, <b>FH</b> user shall just include <b>FH_UART02_GlobalVariables.h</b> there\n
  *       In other word, <b>FH_UART02_ReceiveBuf</b> array shall receive every byte of the received data there with <b>FH_UART02_ReceiveBufIndex</b> as index of the array
  *
  *       <b>FH_UART02_SharedDataBuf_8Bits</b>, <b>FH_UART02_SharedDataBuf_16Bits</b> and <b>FH_UART02_SharedDataBuf_32Bits</b> are optional and could be left intact\n
  *       They could be used by <b>FH</b> user to set some special data like receive filters on <b>ISR</b> (Interrupt Service Routine) of the <b>UART 02</b> , ...\n
  *       They are controllable with some commands (described in this file) through <b>RobotFramework</b>\n
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
/* Primary Includes ------------------------------------------------------------------*/
// Attention 1: FH user defined code (include the mentioned header file here)

//
#include "../../../../FH_Embedded/FH_Functions/FH_UART/FH_UART02/FH_UART02.h"

#ifdef FH_UART02    // It is configurable in FH_UART_Configs.h

#if FH_UART_MaxPeripheralNumber > 0    // It is configurable in FH_DevicePeripherals.h

/* Secondary Includes ------------------------------------------------------------------*/
#include "../../../../FH_Embedded/FH_Root/FH_Perif/FH_UART/FH_UART.h"
#include "../../../../FH_Embedded/FH_Root/FH_General/FH_GlobalTimerCount/FH_GlobalTimerCount.h"
#include "../../../../FH_Embedded/FH_Root/FH_General/FH_GeneralFunctions/FH_GeneralFunctions.h"
#include "../../../../FH_Embedded/FH_Functions/FH_UART/FH_UART02/FH_UART02_Configs.h"
#include "../../../../FH_Embedded/FH_Functions/FH_UART/FH_UART02/FH_UART02_GlobalVariables.h"

/*!
  <b>FH</b> user shall use <b>FH_UART02_ReceiveBuf</b> in the receive <b>ISR</b> (Interrupt Service Routine) of the <b>UART 02</b> in a separate c file\n
  For this to happen, FH user shall just include FH_UART02_GlobalVariables.h there\n
  In other word, <b>FH_UART02_ReceiveBuf</b> array shall receive every byte of the received data there\n
  It is configurable in FH_UART02_Configs.h
*/
volatile uint8_t  FH_UART02_ReceiveBuf[FH_UART02_ReceiveBufLength];

/*!
  <b>FH_UART02_ReceiveBufIndex</b> is the index of <b>FH_UART02_ReceiveBuf</b>
*/
volatile uint16_t FH_UART02_ReceiveBufIndex = 0;

/*!
  <b>FH_UART02_SharedDataBuf_8Bits</b> is optional and could be left intact\n
  It could be used by <b>FH</b> user to set some special data like receive filters on <b>ISR</b> (Interrupt Service Routine) of the <b>UART 02</b> , ...
  It are controllable with some commands (described in this file) through <b>RobotFramework</b>\n
  It is configurable in FH_UART02_Configs.h
*/
volatile uint8_t  FH_UART02_SharedDataBuf_8Bits [FH_UART02_SharedDataBufLength_8Bits];

/*!
  <b>FH_UART02_SharedDataBuf_16Bits</b> is optional and could be left intact\n
  It could be used by <b>FH</b> user to set some special data like receive filters on <b>ISR</b> (Interrupt Service Routine) of the <b>UART 02</b> , ...
  It are controllable with some commands (described in this file) through <b>RobotFramework</b>\n
  It is configurable in FH_UART02_Configs.h
*/
volatile uint16_t FH_UART02_SharedDataBuf_16Bits[FH_UART02_SharedDataBufLength_16Bits];
/*!
  <b>FH_UART02_SharedDataBuf_32Bits</b> is optional and could be left intact\n
  It could be used by <b>FH</b> user to set some special data like receive filters on <b>ISR</b> (Interrupt Service Routine) of the <b>UART 02</b> , ...
  It are controllable with some commands (described in this file) through <b>RobotFramework</b>\n
  It is configurable in FH_UART02_Configs.h
*/
volatile uint32_t FH_UART02_SharedDataBuf_32Bits[FH_UART02_SharedDataBufLength_32Bits];

/**
 * @brief This function initializes the <b>UART 02</b>\n
 *        The <b>UART 02</b> could be any interested UART of the micro-controller on which <b>FH</b> source code is ported\n
 *        <b>FH</b> user should call the initialization function of the interested UART here
 *
 * @param  fh_RFCommunication_Message
 *         The message frame set by <b>RobotFramework</b>
 *
 * @return FH_ErrorInfo is returned
 *
 * @note
 * To have a clean code, just include the related header file\n
 * Then just call the function here
 *
 * @verbatim
    ==============================================================================
                          ##### RobotFramework Example #####
    ==============================================================================
    @{MessageData} =    Create List    ${UART02}
    &{Message}     =    Create Dictionary    DeviceAddress=${DeviceAddress_01}    Function=${Function_UART}    Command=${UART_Commands_Init}    Data=@{MessageData}
    ${Result}    SendMessage    &{Message}

    Comments:

    UART02 => It indicates the UART 02
    DeviceAddress_01 => It shall be equal to the address of the device: FH_RFCommunication_DeviceAddress
    Function_UART => It is the function in the message frame
    UART_Commands_Init => It is the command of the function in the message frame
  @endverbatim
 *
 *
 * @warning
 * To be able to send or receive data through the <b>UART 02</b> of the micro-controller on which <b>FH</b> source code is ported, this function shall be invoked once by <b>RobotFramework</b> firstly\n
 * In other words, before invoking for example <b>FH_UART_Send_UART02</b> or <b>FH_UART_Receive_UART02</b> functions or ... from <b>RobotFramework</b>, this function shall be invoked in order to initialize the UART
 *

*/
FH_ErrorInfo FH_UART_Init_UART02(FH_RFCommunication_Message* fh_RFCommunication_Message)
{
	FH_ErrorInfo fh_ErrorInfo;    // Error Information
	FH_ResetErrorInfo(&fh_ErrorInfo);    // Reset Error Information to default

	// Attention 2: FH user defined code (call the initialization function of the UART 02 here)

	// YourInitializationFunctionName ();

	//

	return fh_ErrorInfo;
}

/**
 * @brief This function sends data through the <b>UART 02</b>\n
 *        The <b>UART 02</b> could be any interested UART of the micro-controller on which <b>FH</b> source code is ported\n
 *        <b>FH</b> user should call the send function of the interested UART here
 *
 * @param  fh_RFCommunication_Message
 *         The message frame set by <b>RobotFramework</b>
 *
 * @return FH_ErrorInfo is returned
 *
 * @note
 * To have a clean code, just include the related header file\n
 * Then just call the function here
 *
 * @verbatim
    ==============================================================================
                          ##### RobotFramework Example #####
    ==============================================================================
    @{MessageData} =    Create List    ${UART02}    02    B1     FF
    &{Message}     =    Create Dictionary    DeviceAddress=${DeviceAddress_01}    Function=${Function_UART}    Command=${UART_Commands_Send}    Data=@{MessageData}
    ${Result}    SendMessage    &{Message}

    Comments:

    UART02 => It indicates the UART 02
    02 => Example length of the data to be sent
    B1     FF => Example data (0xB1, 0xFF) to be sent (or apart from the data to be sent, it may include some other data like ID, Filter, ... to be processed too, if need be) through the <b>UART 02</b>\n
    DeviceAddress_01 => It shall be equal to the address of the device: FH_RFCommunication_DeviceAddress
    Function_UART => It is the function in the message frame
    UART_Commands_Send => It is the command of the function in the message frame
  @endverbatim
 *
 *
 * @warning
 * To be able to send data through the <b>UART 02</b> of the micro-controller on which <b>FH</b> source code is ported, the <b>FH_UART_Init_UART02</b> function shall be invoked once by <b>RobotFramework</b> firstly\n
 * In other words, before invoking <b>FH_UART_Send_UART02</b> function from <b>RobotFramework</b>, <b>FH_UART_Init_UART02</b> function shall be invoked in order to initialize the UART
 *

*/
FH_ErrorInfo FH_UART_Send_UART02(FH_RFCommunication_Message* fh_RFCommunication_Message)
{
	FH_ErrorInfo fh_ErrorInfo;    // Error Information
	FH_ResetErrorInfo(&fh_ErrorInfo);    // Reset Error Information to default

	// **** Option 1 (just one of the 2 options here shall be selected) ****
	// If the data is supposed to be directly sent (without the need to be processed), the following code could be simply utilized:

	for (uint8_t i = UART_Send_Data; i < (fh_RFCommunication_Message -> Data[UART_Send_DataLength] + UART_Send_Data); i++)
	{
		// Attention 3: FH user defined code (call the send function of the UART 02 here with fh_RFCommunication_Message -> Data[i] as argument)

		// YourSendFunctionName (fh_RFCommunication_Message -> Data[i]);

		//
	}

	// **** Option 2  (just one of the 2 options here shall be selected) ****
	// If the data is supposed to be processed, an extra process function shall be developed by FH user and the following code could be utilized:

	// Attention 3: FH user defined code (call the send process function of the UART 02 here with &fh_RFCommunication_Message -> Data[UART_Send_Data] and fh_RFCommunication_Message -> Data[UART_Send_DataLength] as argument)
	// Hint: The prototype of the send process function should be something like YourSendProcessFunctionName(uint8_t* Data, uint8_t DataLength);

	// YourSendProcessFunctionName (&fh_RFCommunication_Message -> Data[UART_Send_Data], fh_RFCommunication_Message -> Data[UART_Send_DataLength]);

	//

	return fh_ErrorInfo;
}

/**
 * @brief This function retrieves the <b>ISR</b> (Interrupt Service Routine) receive buffer (<b>FH_UART02_ReceiveBuf</b>) of the <b>UART 02</b>\n
 *        The <b>UART 02</b> could be any interested UART of the micro-controller on which <b>FH</b> source code is ported\n
 *        <b>FH</b> user could left the present source code here intact
 *
 * @param  fh_RFCommunication_Message
 *         The message frame set by <b>RobotFramework</b>
 * @param  DataSize
 *         *DataSize will be set to the <b>ISR</b> (Interrupt Service Routine) receive buffer index (<b>FH_UART02_ReceiveBufIndex</b>) of the <b>UART 02</b>
 * @param  Data
 *         *Data will be set to the <b>ISR</b> (Interrupt Service Routine) receive buffer (<b>FH_UART02_ReceiveBuf</b>) of the <b>UART 02</b>
 *
 * @return FH_ErrorInfo is returned
 *
 * @note
 *       <b>FH</b> user shall use <b>FH_UART02_ReceiveBuf</b> and <b>FH_UART02_ReceiveBufIndex</b> in the receive <b>ISR</b> (Interrupt Service Routine) of the <b>UART 02</b> in a separate c file\n
 *       For this to happen, <b>FH</b> user shall just include <b>FH_UART02_GlobalVariables.h</b> there\n
 *       In other word, <b>FH_UART02_ReceiveBuf</b> array shall receive every byte of the received data there with <b>FH_UART02_ReceiveBufIndex</b> as index of the array
 *
 * @verbatim
    ==============================================================================
                          ##### RobotFramework Example #####
    ==============================================================================
    @{MessageData} =    Create List    ${UART02}
    &{Message}     =    Create Dictionary    DeviceAddress=${DeviceAddress_01}    Function=${Function_UART}    Command=${UART_Commands_Receive}    Data=@{MessageData}
    ${Result}    SendMessage    &{Message}

    Comments:

    UART02 => It indicates the UART 02
    DeviceAddress_01 => It shall be equal to the address of the device: FH_RFCommunication_DeviceAddress
    Function_UART => It is the function in the message frame
    UART_Commands_Receive => It is the command of the function in the message frame
  @endverbatim
 *
 *
 * @warning
 * To be able to receive data through the <b>UART 02</b> of the micro-controller on which <b>FH</b> source code is ported, the <b>FH_UART_Init_UART02</b> function shall be invoked once by <b>RobotFramework</b> firstly\n
 * In other words, before invoking <b>FH_UART_Receive_UART02</b> function from <b>RobotFramework</b>, <b>FH_UART_Init_UART02</b> function shall be invoked in order to initialize the UART
 *
 * @note
 * The only solution for resetting the receive buffer index (<b>FH_UART02_ReceiveBufIndex</b>) is using <b>FH_UART_ResetRB_UART02</b> function\n
 * In other words, <b>FH_UART02_ReceiveBufIndex</b> may have been already increased if any data has been already received\n
 * So it is normally required to invoke <b>FH_UART_ResetRB_UART02</b> through <b>RobotFramework</b> to reset the receive buffer index (<b>FH_UART02_ReceiveBufIndex</b>) before invoking <b>FH_UART_Receive_UART02</b>
 *

*/
FH_ErrorInfo FH_UART_Receive_UART02(FH_RFCommunication_Message* fh_RFCommunication_Message, uint8_t* DataSize, uint8_t* Data)
{
	FH_ErrorInfo fh_ErrorInfo;    // Error Information
	FH_ResetErrorInfo(&fh_ErrorInfo);    // Reset Error Information to default

	if (FH_UART02_ReceiveBufIndex > 0)    // If there is at least one byte of data received in the ISR (Interrupt Service Routine) of the UART 02
	{
		*DataSize = FH_UART02_ReceiveBufIndex;    // The number of the received bytes in the ISR (Interrupt Service Routine) of the UART 02
		for (uint8_t i = 0; i < FH_UART02_ReceiveBufIndex; i++)
		{
			*(Data + i) = FH_UART02_ReceiveBuf[i];    // The data received in the ISR (Interrupt Service Routine) of the UART 02
		}
	}
	*DataSize = FH_UART02_ReceiveBufIndex;    // The number of the received bytes in the ISR (Interrupt Service Routine) of the UART 02

	return fh_ErrorInfo;
}

/**
 * @brief This function waits to receive the specified number of bytes of data through the <b>ISR</b> (Interrupt Service Routine) receive buffer (<b>FH_UART02_ReceiveBuf</b>) of the <b>UART 02</b>\n
 *        A maximum timeout is specified too\n
 *        The <b>UART 02</b> could be any interested UART of the micro-controller on which <b>FH</b> source code is ported\n
 *        <b>FH</b> user could left the present source code here intact
 *
 * @param  fh_RFCommunication_Message
 *         The message frame set by <b>RobotFramework</b>
 * @param  DataSize
 *         *DataSize will be set to the <b>ISR</b> (Interrupt Service Routine) receive buffer index (<b>FH_UART02_ReceiveBufIndex</b>) of the <b>UART 02</b>
 * @param  Data
 *         *Data will be set to the <b>ISR</b> (Interrupt Service Routine) receive buffer (<b>FH_UART02_ReceiveBuf</b>) of the <b>UART 02</b>
 *
 * @return FH_ErrorInfo is returned
 *
 * @note
 *       <b>FH</b> user shall use <b>FH_UART02_ReceiveBuf</b> and <b>FH_UART02_ReceiveBufIndex</b> in the receive <b>ISR</b> (Interrupt Service Routine) of the <b>UART 02</b> in a separate c file\n
 *       For this to happen, <b>FH</b> user shall just include <b>FH_UART02_GlobalVariables.h</b> there\n
 *       In other word, <b>FH_UART02_ReceiveBuf</b> array shall receive every byte of the received data there with <b>FH_UART02_ReceiveBufIndex</b> as index of the array
 *
 * @verbatim
    ==============================================================================
                          ##### RobotFramework Example #####
    ==============================================================================
    @{MessageData} =    Create List    ${UART02}    05    00    00    0B    B8
    &{Message}     =    Create Dictionary    DeviceAddress=${DeviceAddress_01}    Function=${Function_UART}    Command=${UART_Commands_ReceiveW}    Data=@{MessageData}
    ${Result}    SendMessage    &{Message}

    Comments:

    UART02 => It indicates the UART 02
    05 => The expected number of bytes of data to be received through the <b>ISR</b> (Interrupt Service Routine) receive buffer (FH_UART02_ReceiveBuf) of the <b>UART 02</b>
    00    00    0B    B8 => Example data (0x00000BB8 mili-seconds) as timeout of receiving the expected number of bytes
                            FH_GlobalTimeCounter which is a global variable is utilized to calculate the timeout
                            FH_GlobalTimeCounter shall be incremented every <b>1 mili-second</b> in an interested timer <b>ISR</b> (Interrupt Service Routine) by <b>FH</b> user
                            For this to happen, <b>FH_GlobalTimerCount.h</b> shall be included in the interested timer <b>ISR</b> (Interrupt Service Routine) file
                            If the expected number of bytes are received, the function does not wait anymore for the remaining time of the timeout
    DeviceAddress_01 => It shall be equal to the address of the device: FH_RFCommunication_DeviceAddress
    Function_UART => It is the function in the message frame
    UART_Commands_ReceiveW => It is the command of the function in the message frame
  @endverbatim
 *
 * @warning
 * To be able to receive data through the <b>UART 02</b> of the micro-controller on which <b>FH</b> source code is ported, the <b>FH_UART_Init_UART02</b> function shall be invoked once by <b>RobotFramework</b> firstly\n
 * In other words, before invoking <b>FH_UART_ReceiveW_UART02</b> function from <b>RobotFramework</b>, <b>FH_UART_Init_UART02</b> function shall be invoked in order to initialize the UART
 *
 * @note
 * The only solution for resetting the receive buffer index (<b>FH_UART02_ReceiveBufIndex</b>) is using <b>FH_UART_ResetRB_UART02</b> function\n
 * In other words, <b>FH_UART02_ReceiveBufIndex</b> may have been already increased if any data has been already received\n
 * So it is normally required to invoke <b>FH_UART_ResetRB_UART02</b> through <b>RobotFramework</b> to reset the receive buffer index (<b>FH_UART02_ReceiveBufIndex</b>) before invoking <b>FH_UART_ReceiveW_UART02</b>
 *

*/
FH_ErrorInfo FH_UART_ReceiveW_UART02(FH_RFCommunication_Message* fh_RFCommunication_Message, uint8_t* DataSize, uint8_t* Data)
{
	FH_ErrorInfo fh_ErrorInfo;    // Error Information
	FH_ResetErrorInfo(&fh_ErrorInfo);    // Reset Error Information to default

	uint8_t ExpectedDataLength;
	ExpectedDataLength = fh_RFCommunication_Message -> Data[UART_ReceiveW_ExpectedDataLength];    // The expected number of bytes to be received through the ISR (Interrupt Service Routine) receive buffer (FH_UART02_ReceiveBuf) of the UART 02

	uint32_t MaxTimerCount = FH_ConvertUint8ToUint32(&fh_RFCommunication_Message -> Data[UART_ReceiveW_MaxTimerCount]);    // The timeout of receiving the expected number of bytes

	FH_GlobalTimeCounter = 0;    // The global variable is utilized to calculate the timeout
	// Wait till the expected number of bytes are received or timeout happens
	while (FH_UART02_ReceiveBufIndex < ExpectedDataLength && FH_GlobalTimeCounter < MaxTimerCount)
	{
	}
	
	if (FH_UART02_ReceiveBufIndex > 0)    // If there is at least one byte of data received in the ISR (Interrupt Service Routine) of the UART 02
	{
		*DataSize = FH_UART02_ReceiveBufIndex;
		for (uint8_t i = 0; i < FH_UART02_ReceiveBufIndex; i++)
		{
			*(Data + i) = FH_UART02_ReceiveBuf[i];
		}
	}
	*DataSize = FH_UART02_ReceiveBufIndex;    // The number of the received bytes in the ISR (Interrupt Service Routine) of the UART 02

	return fh_ErrorInfo;
}

/**
 * @brief This function resets the <b>ISR</b> (Interrupt Service Routine) receive buffer index (<b>FH_UART02_ReceiveBufIndex</b>) of the <b>UART 02</b>\n
 *        The <b>UART 02</b> could be any interested UART of the micro-controller on which <b>FH</b> source code is ported\n
 *        <b>FH</b> user could left the present source code here intact
 *
 * @param  fh_RFCommunication_Message
 *         The message frame set by <b>RobotFramework</b>
 *
 * @return FH_ErrorInfo is returned
 *
 * @note
 *       <b>FH</b> user shall use <b>FH_UART02_ReceiveBuf</b> and <b>FH_UART02_ReceiveBufIndex</b> in the receive <b>ISR</b> (Interrupt Service Routine) of the <b>UART 02</b> in a separate c file\n
 *       For this to happen, <b>FH</b> user shall just include <b>FH_UART02_GlobalVariables.h</b> there\n
 *       In other word, <b>FH_UART02_ReceiveBuf</b> array shall receive every byte of the received data there with <b>FH_UART02_ReceiveBufIndex</b> as index of the array
 *
 * @verbatim
    ==============================================================================
                          ##### RobotFramework Example #####
    ==============================================================================
    @{MessageData} =    Create List    ${UART02}
    &{Message}     =    Create Dictionary    DeviceAddress=${DeviceAddress_01}    Function=${Function_UART}    Command=${UART_Commands_ResetRB}    Data=@{MessageData}
    ${Result}    SendMessage    &{Message}

    Comments:

    UART02 => It indicates the UART 02
    DeviceAddress_01 => It shall be equal to the address of the device: FH_RFCommunication_DeviceAddress
    Function_UART => It is the function in the message frame
    UART_Commands_ResetRB => It is the command of the function in the message frame
  @endverbatim
 *
 * @warning
 * The only solution for resetting the receive buffer index (<b>FH_UART02_ReceiveBufIndex</b>) is using <b>FH_UART_ResetRB_UART02</b> function\n
 * In other words, <b>FH_UART02_ReceiveBufIndex</b> may have been already increased if any data has been already received\n
 * So it is normally required to invoke <b>FH_UART_ResetRB_UART02</b> through <b>RobotFramework</b> to reset the receive buffer index (<b>FH_UART02_ReceiveBufIndex</b>) before invoking <b>FH_UART_Receive_UART02</b> or <b>FH_UART_ReceiveW_UART02</b> or ...
 *

*/
FH_ErrorInfo FH_UART_ResetRB_UART02(FH_RFCommunication_Message* fh_RFCommunication_Message)
{
	FH_ErrorInfo fh_ErrorInfo;    // Error Information
	FH_ResetErrorInfo(&fh_ErrorInfo);    // Reset Error Information to default

	FH_UART02_ReceiveBufIndex = 0;    // The receive buffer index of the ISR (Interrupt Service Routine) of the UART 02

	return fh_ErrorInfo;
}

/**
 * @brief This function sets the shared data buffer (<b>FH_UART02_SharedDataBuf_8Bits</b>) of the <b>UART 02</b>\n
 *        The <b>UART 02</b> could be any interested UART of the micro-controller on which <b>FH</b> source code is ported\n
 *        <b>FH_UART02_SharedDataBuf_8Bits</b> is a shared global 8 bit array which is a data bridge between <b>RobotFramework</b> and <b>FH</b> user code\n
 *        <b>FH_UART02_SharedDataBuf_8Bits</b> is optional\n
 *        It could be used by <b>FH</b> user to set some special data like receive filters on <b>ISR</b> (Interrupt Service Routine) of the <b>UART 02</b> or ...
 *
 *        <b>FH</b> user could left the present source code here intact
 *
 * @param  fh_RFCommunication_Message
 *         The message frame set by <b>RobotFramework</b>
 *
 * @return FH_ErrorInfo is returned
 *
 * @note
 *       <b>FH</b> user could use <b>FH_UART02_SharedDataBuf_8Bits</b> in the receive <b>ISR</b> (Interrupt Service Routine) of the <b>UART 02</b> in a separate c file or anywhere else interested\n
 *       For this to happen, <b>FH</b> user shall just include <b>FH_UART02_GlobalVariables.h</b> there
 *
 * @verbatim
    ==============================================================================
                          ##### RobotFramework Example #####
    ==============================================================================
    @{MessageData} =    Create List    ${UART02}    04    AA    BB    CC    DD
    &{Message}     =    Create Dictionary    DeviceAddress=${DeviceAddress_01}    Function=${Function_UART}    Command=${UART_Commands_SSD8}    Data=@{MessageData}
    ${Result}    SendMessage    &{Message}

    Comments:

    UART02 => It indicates the UART 02
    04 => Example interested length of the 8 bit data to be set
    AA    BB    CC    DD => Example data (0xAA, 0xBB, 0xCC, 0xDD) to be set in <b>FH_UART02_SharedDataBuf_8Bits</b>
    DeviceAddress_01 => It shall be equal to the address of the device: FH_RFCommunication_DeviceAddress
    Function_UART => It is the function in the message frame
    UART_Commands_SSD8 => It is the command of the function in the message frame
  @endverbatim
 *

*/
FH_ErrorInfo FH_UART_SSD8_UART02(FH_RFCommunication_Message* fh_RFCommunication_Message)
{
	FH_ErrorInfo fh_ErrorInfo;    // Error Information
	FH_ResetErrorInfo(&fh_ErrorInfo);    // Reset Error Information to default

	if (fh_RFCommunication_Message -> Data[UART_SSD8_SharedDataLength] > FH_UART02_SharedDataBufLength_8Bits)     // The length of the 8 bit data to be set
	{
		fh_ErrorInfo.error_code = FH_ERROR_Functions;    // FH User Defined Function Error
		return fh_ErrorInfo;
	}

	for (uint8_t i = 0; i < fh_RFCommunication_Message -> Data[UART_SSD8_SharedDataLength] ; i++)
	{
		FH_UART02_SharedDataBuf_8Bits[i] = fh_RFCommunication_Message -> Data[UART_SSD8_SharedData+i];    // Set data to FH_UART02_SharedDataBuf_8Bits
	}
	fh_ErrorInfo.error_code = FH_ERROR_OK;    // There is no Error

	return fh_ErrorInfo;
}

/**
 * @brief This function sets the shared data buffer (<b>FH_UART02_SharedDataBuf_16Bits</b>) of the <b>UART 02</b>\n
 *        The <b>UART 02</b> could be any interested UART of the micro-controller on which <b>FH</b> source code is ported\n
 *        <b>FH_UART02_SharedDataBuf_16Bits</b> is a shared global 8 bit array which is a data bridge between <b>RobotFramework</b> and <b>FH</b> user code\n
 *        <b>FH_UART02_SharedDataBuf_16Bits</b> is optional\n
 *        It could be used by <b>FH</b> user to set some special data like receive filters on <b>ISR</b> (Interrupt Service Routine) of the <b>UART 02</b> or ...
 *
 *        <b>FH</b> user could left the present source code here intact
 *
 * @param  fh_RFCommunication_Message
 *         The message frame set by <b>RobotFramework</b>
 *
 * @return FH_ErrorInfo is returned
 *
 * @note
 *       <b>FH</b> user could use <b>FH_UART02_SharedDataBuf_16Bits</b> in the receive <b>ISR</b> (Interrupt Service Routine) of the <b>UART 02</b> in a separate c file or anywhere else interested\n
 *       For this to happen, <b>FH</b> user shall just include <b>FH_UART02_GlobalVariables.h</b> there
 *
 * @verbatim
    ==============================================================================
                          ##### RobotFramework Example #####
    ==============================================================================
    @{MessageData} =    Create List    ${UART02}    02    AA    BB    CC    DD
    &{Message}     =    Create Dictionary    DeviceAddress=${DeviceAddress_01}    Function=${Function_UART}    Command=${UART_Commands_SSD16}    Data=@{MessageData}
    ${Result}    SendMessage    &{Message}

    Comments:

    UART02 => It indicates the UART 02
    02 => Example interested length of the 16 bit data to be set
    AA    BB    CC    DD => Example data (0xAABB and 0xCCDD) to be set in <b>FH_UART02_SharedDataBuf_16Bits</b>
    DeviceAddress_01 => It shall be equal to the address of the device: FH_RFCommunication_DeviceAddress
    Function_UART => It is the function in the message frame
    UART_Commands_SSD16 => It is the command of the function in the message frame
  @endverbatim
 *

*/
FH_ErrorInfo FH_UART_SSD16_UART02(FH_RFCommunication_Message* fh_RFCommunication_Message)
{
	FH_ErrorInfo fh_ErrorInfo;    // Error Information
	FH_ResetErrorInfo(&fh_ErrorInfo);    // Reset Error Information to default

	if (fh_RFCommunication_Message -> Data[UART_SSD16_SharedDataLength] > (FH_UART02_SharedDataBufLength_16Bits * 2))      // The length of the 16 bit data to be set
	{
		fh_ErrorInfo.error_code = FH_ERROR_Functions;    // FH User Defined Function Error
		return fh_ErrorInfo;
	}

	uint8_t i = 0;
	uint8_t SharedDataIndex = UART_SSD16_SharedData;    // Shared Data Index in FH_UART_Commandelements_SSD16
	do
	{
		FH_UART02_SharedDataBuf_16Bits[i] = FH_ConvertUint8ToUint16(&fh_RFCommunication_Message -> Data[SharedDataIndex]);    // Set data to FH_UART02_SharedDataBuf_16Bits
		SharedDataIndex = SharedDataIndex + 2;
		i = i + 1;
	}while (i < fh_RFCommunication_Message -> Data[UART_SSD16_SharedDataLength]);    // The length of the 16 bit data to be set
	fh_ErrorInfo.error_code = FH_ERROR_OK;    // There is no Error

	return fh_ErrorInfo;
}

/**
 * @brief This function sets the shared data buffer (<b>FH_UART02_SharedDataBuf_32Bits</b>) of the <b>UART 02</b>\n
 *        The <b>UART 02</b> could be any interested UART of the micro-controller on which <b>FH</b> source code is ported\n
 *        <b>FH_UART02_SharedDataBuf_32Bits</b> is a shared global 8 bit array which is a data bridge between <b>RobotFramework</b> and <b>FH</b> user code\n
 *        <b>FH_UART02_SharedDataBuf_32Bits</b> is optional\n
 *        It could be used by <b>FH</b> user to set some special data like receive filters on <b>ISR</b> (Interrupt Service Routine) of the <b>UART 02</b> or ...
 *
 *        <b>FH</b> user could left the present source code here intact
 *
 * @param  fh_RFCommunication_Message
 *         The message frame set by <b>RobotFramework</b>
 *
 * @return FH_ErrorInfo is returned
 *
 * @note
 *       <b>FH</b> user could use <b>FH_UART02_SharedDataBuf_32Bits</b> in the receive <b>ISR</b> (Interrupt Service Routine) of the <b>UART 02</b> in a separate c file or anywhere else interested\n
 *       For this to happen, <b>FH</b> user shall just include <b>FH_UART02_GlobalVariables.h</b> there
 *
 * @verbatim
    ==============================================================================
                          ##### RobotFramework Example #####
    ==============================================================================
    @{MessageData} =    Create List    ${UART02}    02    AA    BB    CC    DD    01    02    03    04
    &{Message}     =    Create Dictionary    DeviceAddress=${DeviceAddress_01}    Function=${Function_UART}    Command=${UART_Commands_SSD32}    Data=@{MessageData}
    ${Result}    SendMessage    &{Message}

    Comments:

    UART02 => It indicates the UART 02
    02 => Example interested length of the 32 bit data to be set
    AA    BB    CC    DD    01    02    03    04 => Example data (0xAABBCCDD and 0x01020304) to be set in <b>FH_UART02_SharedDataBuf_32Bits</b>
    DeviceAddress_01 => It shall be equal to the address of the device: FH_RFCommunication_DeviceAddress
    Function_UART => It is the function in the message frame
    UART_Commands_SSD32 => It is the command of the function in the message frame
  @endverbatim
 *

*/
FH_ErrorInfo FH_UART_SSD32_UART02(FH_RFCommunication_Message* fh_RFCommunication_Message)
{
	FH_ErrorInfo fh_ErrorInfo;    // Error Information
	FH_ResetErrorInfo(&fh_ErrorInfo);    // Reset Error Information to default

	if (fh_RFCommunication_Message -> Data[UART_SSD32_SharedDataLength] > (FH_UART02_SharedDataBufLength_32Bits * 4))     // The length of the 32 bit data to be set
	{
		fh_ErrorInfo.error_code = FH_ERROR_Functions;    // FH User Defined Function Error
		return fh_ErrorInfo;
	}

	uint8_t i = 0;
	uint8_t SharedDataIndex = UART_SSD32_SharedData;    // Shared Data Index in FH_UART_Commandelements_SSD32
	do
	{
		FH_UART02_SharedDataBuf_32Bits[i] = FH_ConvertUint8ToUint32(&fh_RFCommunication_Message -> Data[SharedDataIndex]);    // Set data to FH_UART02_SharedDataBuf_32Bits
		SharedDataIndex = SharedDataIndex + 4;
		i = i + 1;
	}while (i < fh_RFCommunication_Message -> Data[UART_SSD32_SharedDataLength]);    // The length of the 32 bit data to be set

	fh_ErrorInfo.error_code = FH_ERROR_OK;    // There is no Error

	return fh_ErrorInfo;
}

/**
 * @brief This function gets the shared data buffer (<b>FH_UART02_SharedDataBuf_8Bits</b>) of the <b>UART 02</b>\n
 *        The <b>UART 02</b> could be any interested UART of the micro-controller on which <b>FH</b> source code is ported\n
 *        <b>FH_UART02_SharedDataBuf_8Bits</b> is a shared global 8 bit array which is a data bridge between <b>RobotFramework</b> and <b>FH</b> user code\n
 *        <b>FH_UART02_SharedDataBuf_8Bits</b> is optional\n
 *        It could be used by <b>FH</b> user to set some special data like receive filters on <b>ISR</b> (Interrupt Service Routine) of the <b>UART 02</b> or ...
 *
 *        <b>FH</b> user could left the present source code here intact
 *
 * @param  fh_RFCommunication_Message
 *         The message frame set by <b>RobotFramework</b>
 * @param  SharedDataLength
 *         *SharedDataLength will be set to <b>FH_UART02_SharedDataBufLength_8Bits</b>
 * @param  SharedData
 *         *SharedData will be set to <b>FH_UART02_SharedDataBuf_8Bits</b>
 *
 * @return FH_ErrorInfo is returned
 *
 * @note
 *       <b>FH</b> user could use <b>FH_UART02_SharedDataBuf_8Bits</b> in the receive <b>ISR</b> (Interrupt Service Routine) of the <b>UART 02</b> in a separate c file or anywhere else interested\n
 *       For this to happen, <b>FH</b> user shall just include <b>FH_UART02_GlobalVariables.h</b> there
 *
 * @verbatim
    ==============================================================================
                          ##### RobotFramework Example #####
    ==============================================================================
    @{MessageData} =    Create List    ${UART02}
    &{Message}     =    Create Dictionary    DeviceAddress=${DeviceAddress_01}    Function=${Function_UART}    Command=${UART_Commands_GSD8}    Data=@{MessageData}
    ${Result}    SendMessage    &{Message}

    Comments:

    UART02 => It indicates the UART 02
    DeviceAddress_01 => It shall be equal to the address of the device: FH_RFCommunication_DeviceAddress
    Function_UART => It is the function in the message frame
    UART_Commands_GSD8 => It is the command of the function in the message frame
  @endverbatim
 *

*/
FH_ErrorInfo FH_UART_GSD8_UART02(FH_RFCommunication_Message* fh_RFCommunication_Message, uint8_t* SharedDataLength, uint8_t* SharedData)
{
	FH_ErrorInfo fh_ErrorInfo;    // Error Information
	FH_ResetErrorInfo(&fh_ErrorInfo);    // Reset Error Information to default

	for (uint8_t i = 0; i < FH_UART02_SharedDataBufLength_8Bits; i++)
	{
		*(SharedData + i) = FH_UART02_SharedDataBuf_8Bits[i];
	}
	*SharedDataLength = FH_UART02_SharedDataBufLength_8Bits;     // The length of the 8 bit data to be set
	fh_ErrorInfo.error_code = FH_ERROR_OK;    // There is no Error

	return fh_ErrorInfo;
}

/**
 * @brief This function gets the shared data buffer (<b>FH_UART02_SharedDataBuf_16Bits</b>) of the <b>UART 02</b>\n
 *        The <b>UART 02</b> could be any interested UART of the micro-controller on which <b>FH</b> source code is ported\n
 *        <b>FH_UART02_SharedDataBuf_16Bits</b> is a shared global 16 bit array which is a data bridge between <b>RobotFramework</b> and <b>FH</b> user code\n
 *        <b>FH_UART02_SharedDataBuf_16Bits</b> is optional\n
 *        It could be used by <b>FH</b> user to set some special data like receive filters on <b>ISR</b> (Interrupt Service Routine) of the <b>UART 02</b> or ...
 *
 *        <b>FH</b> user could left the present source code here intact
 *
 * @param  fh_RFCommunication_Message
 *         The message frame set by <b>RobotFramework</b>
 * @param  SharedDataLength
 *         *SharedDataLength will be set to <b>FH_UART02_SharedDataBufLength_16Bits</b>
 * @param  SharedData
 *         *SharedData will be set to <b>FH_UART02_SharedDataBuf_16Bits</b>
 *
 * @return FH_ErrorInfo is returned
 *
 * @note
 *       <b>FH</b> user could use <b>FH_UART02_SharedDataBuf_16Bits</b> in the receive <b>ISR</b> (Interrupt Service Routine) of the <b>UART 02</b> in a separate c file or anywhere else interested\n
 *       For this to happen, <b>FH</b> user shall just include <b>FH_UART02_GlobalVariables.h</b> there
 *
 * @verbatim
    ==============================================================================
                          ##### RobotFramework Example #####
    ==============================================================================
    @{MessageData} =    Create List    ${UART02}
    &{Message}     =    Create Dictionary    DeviceAddress=${DeviceAddress_01}    Function=${Function_UART}    Command=${UART_Commands_GSD16}    Data=@{MessageData}
    ${Result}    SendMessage    &{Message}

    Comments:

    UART02 => It indicates the UART 02
    DeviceAddress_01 => It shall be equal to the address of the device: FH_RFCommunication_DeviceAddress
    Function_UART => It is the function in the message frame
    UART_Commands_GSD16 => It is the command of the function in the message frame
  @endverbatim
 *

*/
FH_ErrorInfo FH_UART_GSD16_UART02(FH_RFCommunication_Message* fh_RFCommunication_Message, uint8_t* SharedDataLength, uint8_t* SharedData)
{
	FH_ErrorInfo fh_ErrorInfo;    // Error Information
	FH_ResetErrorInfo(&fh_ErrorInfo);    // Reset Error Information to default

	FH_Uint8Uint16 fh_Uint8Uint16;    // Union to access 4 uint8_t out of 1 uint16_t
	uint8_t SharedDataIndex = 0;
	for (uint8_t i = 0; i < FH_UART02_SharedDataBufLength_16Bits; i++)
	{
		fh_Uint8Uint16.value = FH_UART02_SharedDataBuf_16Bits[i];
		*(SharedData + SharedDataIndex++) = fh_Uint8Uint16.bytes[1];
		*(SharedData + SharedDataIndex++) = fh_Uint8Uint16.bytes[0];
	}
	*SharedDataLength = FH_UART02_SharedDataBufLength_16Bits;     // The length of the 16 bit data to be set
	fh_ErrorInfo.error_code = FH_ERROR_OK;    // There is no Error

	return fh_ErrorInfo;
}

/**
 * @brief This function gets the shared data buffer (<b>FH_UART02_SharedDataBuf_32Bits</b>) of the <b>UART 02</b>\n
 *        The <b>UART 02</b> could be any interested UART of the micro-controller on which <b>FH</b> source code is ported\n
 *        <b>FH_UART02_SharedDataBuf_32Bits</b> is a shared global 32 bit array which is a data bridge between <b>RobotFramework</b> and <b>FH</b> user code\n
 *        <b>FH_UART02_SharedDataBuf_32Bits</b> is optional\n
 *        It could be used by <b>FH</b> user to set some special data like receive filters on <b>ISR</b> (Interrupt Service Routine) of the <b>UART 02</b> or ...
 *
 *        <b>FH</b> user could left the present source code here intact
 *
 * @param  fh_RFCommunication_Message
 *         The message frame set by <b>RobotFramework</b>
 * @param  SharedDataLength
 *         *SharedDataLength will be set to <b>FH_UART02_SharedDataBufLength_32Bits</b>
 * @param  SharedData
 *         *SharedData will be set to <b>FH_UART02_SharedDataBuf_32Bits</b>
 *
 * @return FH_ErrorInfo is returned
 *
 * @note
 *       <b>FH</b> user could use <b>FH_UART02_SharedDataBuf_32Bits</b> in the receive <b>ISR</b> (Interrupt Service Routine) of the <b>UART 02</b> in a separate c file or anywhere else interested\n
 *       For this to happen, <b>FH</b> user shall just include <b>FH_UART02_GlobalVariables.h</b> there
 *
 * @verbatim
    ==============================================================================
                          ##### RobotFramework Example #####
    ==============================================================================
    @{MessageData} =    Create List    ${UART02}
    &{Message}     =    Create Dictionary    DeviceAddress=${DeviceAddress_01}    Function=${Function_UART}    Command=${UART_Commands_GSD32}    Data=@{MessageData}
    ${Result}    SendMessage    &{Message}

    Comments:

    UART02 => It indicates the UART 02
    DeviceAddress_01 => It shall be equal to the address of the device: FH_RFCommunication_DeviceAddress
    Function_UART => It is the function in the message frame
    UART_Commands_GSD32 => It is the command of the function in the message frame
  @endverbatim
 *

*/
FH_ErrorInfo FH_UART_GSD32_UART02(FH_RFCommunication_Message* fh_RFCommunication_Message, uint8_t* SharedDataLength, uint8_t* SharedData)
{
	FH_ErrorInfo fh_ErrorInfo;    // Error Information
	FH_ResetErrorInfo(&fh_ErrorInfo);    // Reset Error Information to default

	FH_Uint8Uint32 fh_Uint8Uint32;    // Union to access 4 uint8_t out of 1 uint32_t
	uint8_t SharedDataIndex = 0;
	for (uint8_t i = 0; i < FH_UART02_SharedDataBufLength_32Bits; i++)
	{
		fh_Uint8Uint32.value = FH_UART02_SharedDataBuf_32Bits[i];
		*(SharedData + SharedDataIndex++) = fh_Uint8Uint32.bytes[3];
		*(SharedData + SharedDataIndex++) = fh_Uint8Uint32.bytes[2];
		*(SharedData + SharedDataIndex++) = fh_Uint8Uint32.bytes[1];
		*(SharedData + SharedDataIndex++) = fh_Uint8Uint32.bytes[0];
	}
	*SharedDataLength = FH_UART02_SharedDataBufLength_32Bits;     // The length of the 32 bit data to be set

	fh_ErrorInfo.error_code = FH_ERROR_OK;    // There is no Error
	return fh_ErrorInfo;
}

#endif

#endif
