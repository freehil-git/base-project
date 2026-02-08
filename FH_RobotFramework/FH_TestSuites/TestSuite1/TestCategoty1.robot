#  *******************************************************************************
#  * SPDX-License-Identifier: Apache-2.0
# *
# * Copyright 2026 Vahid Hasirchi
# *
# * Licensed under the Apache License, Version 2.0 (the "License");
# * you may not use this file except in compliance with the License.
# * You may obtain a copy of the License at
# *
# * http://www.apache.org/licenses/LICENSE-2.0
# *
# * Unless required by applicable law or agreed to in writing, software
# * distributed under the License is distributed on an "AS IS" BASIS,
# * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# * See the License for the specific language governing permissions and
# * limitations under the License.
#  ********************************************************************************

*** Settings ***
Documentation     Example Test Cases of FH package are presented here
...               (For more information, refer to FreeHIL.com)
Suite Setup       SuiteSetup
Suite Teardown    SuiteTeardown
Library           SerialLibrary
Resource          ../../FH_Resources/FH_MessageSetting.robot
Resource          ../../FH_Resources/FH_Keywords.robot

*** Variables ***
${SerialPortName}    COM3

*** Test Cases ***
DO_Init
    [Documentation]    This Test Case initializes DO01 (Digital Output 01) by invoking FH_DO_Init_DO01 in FH embedded software source code
    ...    (For more information, refer to FH Documentation, DO (Digital Output) Messages, DO_Init)
    @{MessageData} =    Create List    ${DO01}
    &{Message} =    Create Dictionary    DeviceAddress=${DeviceAddress_01}    Function=${Function_DO}    Command=${DO_Commands_Init}    Data=@{MessageData}
    ${Result}    SendMessage    &{Message}
    Log Many    Result =    ${Result}
    @{ResultComponents}=    split string    ${Result}    |
    Log Many    DeviceAddress =    ${ResultComponents}[0]
    Log Many    Function =    ${ResultComponents}[1]
    Log Many    Command =    ${ResultComponents}[2]
    Log Many    ErrorInfomation =    ${ResultComponents}[3]
    Should Be Equal    ${ResultComponents}[0]    01
    Should Be Equal    ${ResultComponents}[1]    DO
    Should Be Equal    ${ResultComponents}[2]    Init
    Should Be Equal    ${ResultComponents}[3]    ${ERROR_NoInfo}

DO_SetStatus
    [Documentation]    This Test Case sets the status of DO01 (Digital Output 01) to 1 by invoking FH_DO_SetStatus_DO01 in FH embedded software source code
    ...    (For more information, refer to FH Documentation, DO (Digital Output) Messages, DO_SetStatus)
    @{MessageData} =    Create List    ${DO01}    ${DO_Set}
    &{Message} =    Create Dictionary    DeviceAddress=${DeviceAddress_01}    Function=${Function_DO}    Command=${DO_Commands_SetStatus}    Data=@{MessageData}
    ${Result}    SendMessage    &{Message}
    Log Many    Result =    ${Result}
    @{ResultComponents}=    split string    ${Result}    |
    Log Many    DeviceAddress =    ${ResultComponents}[0]
    Log Many    Function =    ${ResultComponents}[1]
    Log Many    Command =    ${ResultComponents}[2]
    Log Many    ErrorInfomation =    ${ResultComponents}[3]
    Should Be Equal    ${ResultComponents}[0]    01
    Should Be Equal    ${ResultComponents}[1]    DO
    Should Be Equal    ${ResultComponents}[2]    SetStatus
    Should Be Equal    ${ResultComponents}[3]    ${ERROR_NoInfo}

DO_InitMULTI
    [Documentation]    This Test Case initializes all 64 DO (Digital Output) by invoking FH_DO_Init_DO01 to FH_DO_Init_DO64 in FH embedded software source code
    ...    (For more information, refer to FH Documentation, DO (Digital Output) Messages, DO_InitMULTI)
    @{MessageData} =    Create List    FF    FF    FF    FF    FF    FF    FF    FF
    &{Message} =    Create Dictionary    DeviceAddress=${DeviceAddress_01}    Function=${Function_DO}    Command=${DO_Commands_InitMULTI}    Data=@{MessageData}
    ${Result}    SendMessage    &{Message}
    @{ResultComponents}=    split string    ${Result}    |
    Log Many    DeviceAddress =    ${ResultComponents}[0]
    Log Many    Function =    ${ResultComponents}[1]
    Log Many    Command =    ${ResultComponents}[2]
    Log Many    ErrorInfomation =    ${ResultComponents}[3]
    Should Be Equal    ${ResultComponents}[0]    01
    Should Be Equal    ${ResultComponents}[1]    DO
    Should Be Equal    ${ResultComponents}[2]    InitMULTI
    Should Be Equal    ${ResultComponents}[3]    ${ERROR_NoInfo}

DO_SetStatusMULTI
    [Documentation]    This Test Case sets the status of all 64 DO (Digital Output) according to the related arguments (01 02 03 04 05 06 07) by invoking FH_DO_SetStatus_DO01 to FH_DO_SetStatus_DO64 in FH embedded software source code
    ...    (For more information, refer to FH Documentation, DO (Digital Output) Messages, DO_SetStatusMULTI)
    @{MessageData} =    Create List    FF    FF    FF    FF    FF    FF    FF    FF    01    02    03    04    05    06    07
    ...    08
    &{Message} =    Create Dictionary    DeviceAddress=${DeviceAddress_01}    Function=${Function_DO}    Command=${DO_Commands_SetStatusMULTI}    Data=@{MessageData}
    ${Result}    SendMessage    &{Message}
    @{ResultComponents}=    split string    ${Result}    |
    Log Many    DeviceAddress =    ${ResultComponents}[0]
    Log Many    Function =    ${ResultComponents}[1]
    Log Many    Command =    ${ResultComponents}[2]
    Log Many    ErrorInfomation =    ${ResultComponents}[3]
    Should Be Equal As Strings    ${ResultComponents}[0]    01
    Should Be Equal    ${ResultComponents}[1]    DO
    Should Be Equal    ${ResultComponents}[2]    SetStatusMULTI
    Should Be Equal    ${ResultComponents}[3]    ${ERROR_NoInfo}

DI_Init
    [Documentation]    This Test Case initializes DI01 (Digital Input 01) by invoking FH_DI_Init_DO01 in FH embedded software source code
    ...    (For more information, refer to FH Documentation, DI (Digital Input) Messages, DI_Init)
    @{MessageData} =    Create List    ${DI01}
    &{Message} =    Create Dictionary    DeviceAddress=${DeviceAddress_01}    Function=${Function_DI}    Command=${DI_Commands_Init}    Data=@{MessageData}
    ${Result}    SendMessage    &{Message}
    Log Many    Result =    ${Result}
    @{ResultComponents}=    split string    ${Result}    |
    Log Many    DeviceAddress =    ${ResultComponents}[0]
    Log Many    Function =    ${ResultComponents}[1]
    Log Many    Command =    ${ResultComponents}[2]
    Log Many    ErrorInfomation =    ${ResultComponents}[3]
    Should Be Equal    ${ResultComponents}[0]    01
    Should Be Equal    ${ResultComponents}[1]    DI
    Should Be Equal    ${ResultComponents}[2]    Init
    Should Be Equal    ${ResultComponents}[3]    ${ERROR_NoInfo}

DI_GetStatus
    [Documentation]    This Test Case gets the status of DI01 (Digital Input 01) by invoking FH_DI_GetStatus_DO01 in FH embedded software source code
    ...    (For more information, refer to FH Documentation, DI (Digital Output) Messages, DI_GetStatus)
    @{MessageData} =    Create List    ${DI01}
    &{Message} =    Create Dictionary    DeviceAddress=${DeviceAddress_01}    Function=${Function_DI}    Command=${DI_Commands_GetStatus}    Data=@{MessageData}
    ${Result}    SendMessage    &{Message}
    Log Many    Result =    ${Result}
    @{ResultComponents}=    split string    ${Result}    |
    Log Many    DeviceAddress =    ${ResultComponents}[0]
    Log Many    Function =    ${ResultComponents}[1]
    Log Many    Command =    ${ResultComponents}[2]
    Log Many    ErrorInfomation =    ${ResultComponents}[3]
    Log Many    Status =    ${ResultComponents}[4]
    Should Be Equal    ${ResultComponents}[0]    01
    Should Be Equal    ${ResultComponents}[1]    DI
    Should Be Equal    ${ResultComponents}[2]    GetStatus
    Should Be Equal    ${ResultComponents}[3]    ${ERROR_NoInfo}
    Should Be Equal    ${ResultComponents}[4]    0

DI_InitMULTI
    [Documentation]    This Test Case initializes all 64 DI (Digital Input) by invoking FH_DI_Init_DO01 to FH_DI_Init_DO64 in FH embedded software source code
    ...    (For more information, refer to FH Documentation, DI (Digital Input) Messages, DI_InitMULTI)
    @{MessageData} =    Create List    FF    FF    FF    FF    FF    FF    FF    FF
    &{Message} =    Create Dictionary    DeviceAddress=${DeviceAddress_01}    Function=${Function_DI}    Command=${DI_Commands_InitMULTI}    Data=@{MessageData}
    ${Result}    SendMessage    &{Message}
    Log Many    Result =    ${Result}
    @{ResultComponents}=    split string    ${Result}    |
    Log Many    DeviceAddress =    ${ResultComponents}[0]
    Log Many    Function =    ${ResultComponents}[1]
    Log Many    Command =    ${ResultComponents}[2]
    Log Many    ErrorInfomation =    ${ResultComponents}[3]
    Should Be Equal    ${ResultComponents}[0]    01
    Should Be Equal    ${ResultComponents}[1]    DI
    Should Be Equal    ${ResultComponents}[2]    InitMULTI
    Should Be Equal    ${ResultComponents}[3]    ${ERROR_NoInfo}

DI_GetStatusMULTI
    [Documentation]    This Test Case gets the status of all 64 DI (Digital Input) by invoking FH_DI_SetStatus_DO01 to FH_DI_SetStatus_DO64 in FH embedded software source code
    ...    (For more information, refer to FH Documentation, DI (Digital Input) Messages, DI_GetStatusMULTI)
    @{MessageData} =    Create List    FF    FF    FF    FF    FF    FF    FF    FF
    &{Message} =    Create Dictionary    DeviceAddress=${DeviceAddress_01}    Function=${Function_DI}    Command=${DI_Commands_GetStatusMULTI}    Data=@{MessageData}
    ${Result}    SendMessage    &{Message}
    Log Many    Result =    ${Result}
    @{ResultComponents}=    split string    ${Result}    |
    Log Many    DeviceAddress =    ${ResultComponents}[0]
    Log Many    Function =    ${ResultComponents}[1]
    Log Many    Command =    ${ResultComponents}[2]
    Log Many    ErrorInfomation =    ${ResultComponents}[3]
    Log Many    Status =    ${ResultComponents}[4]
    Should Be Equal    ${ResultComponents}[0]    01
    Should Be Equal    ${ResultComponents}[1]    DI
    Should Be Equal    ${ResultComponents}[2]    GetStatusMULTI
    Should Be Equal    ${ResultComponents}[3]    ${ERROR_NoInfo}
    Should Be Equal    ${ResultComponents}[4]    0011001100220022

AO_Init
    [Documentation]    This Test Case initializes AO01 (Analog Output 01) by invoking FH_AO_Init_DO01 in FH embedded software source code
    ...    (For more information, refer to FH Documentation, AO (Analog Output) Messages, AO_Init)
    @{MessageData} =    Create List    ${AO01}
    &{Message} =    Create Dictionary    DeviceAddress=${DeviceAddress_01}    Function=${Function_AO}    Command=${AO_Commands_Init}    Data=@{MessageData}
    ${Result}    SendMessage    &{Message}
    Log Many    Result =    ${Result}
    @{ResultComponents}=    split string    ${Result}    |
    Log Many    DeviceAddress =    ${ResultComponents}[0]
    Log Many    Function =    ${ResultComponents}[1]
    Log Many    Command =    ${ResultComponents}[2]
    Log Many    ErrorInfomation =    ${ResultComponents}[3]
    Should Be Equal    ${ResultComponents}[0]    01
    Should Be Equal    ${ResultComponents}[1]    AO
    Should Be Equal    ${ResultComponents}[2]    Init
    Should Be Equal    ${ResultComponents}[3]    ${ERROR_NoInfo}

AO_SetStatus
    [Documentation]    This Test Case sets the status of AO01 (Analog Output 01) according to the related arguments (F1 C2 01 08) by invoking FH_AO_SetStatus_AO01 in FH embedded software source code
    ...    (For more information, refer to FH Documentation, AO (Analog Output) Messages, AO_SetStatus)
    @{MessageData} =    Create List    ${AO01}    F1    C2    01    08
    &{Message} =    Create Dictionary    DeviceAddress=${DeviceAddress_01}    Function=${Function_AO}    Command=${AO_Commands_SetStatus}    Data=@{MessageData}
    ${Result}    SendMessage    &{Message}
    Log Many    Result =    ${Result}
    @{ResultComponents}=    split string    ${Result}    |
    Log Many    DeviceAddress =    ${ResultComponents}[0]
    Log Many    Function =    ${ResultComponents}[1]
    Log Many    Command =    ${ResultComponents}[2]
    Log Many    ErrorInfomation =    ${ResultComponents}[3]
    Should Be Equal    ${ResultComponents}[0]    01
    Should Be Equal    ${ResultComponents}[1]    AO
    Should Be Equal    ${ResultComponents}[2]    SetStatus
    Should Be Equal    ${ResultComponents}[3]    ${ERROR_NoInfo}

AI_Init
    [Documentation]    This Test Case initializes AI01 (Analog Input 01) by invoking FH_AI_Init_AI01 in FH embedded software source code
    ...    (For more information, refer to FH Documentation, AI (Analog Input) Messages, AI_Init)
    @{MessageData} =    Create List    ${AI01}
    &{Message} =    Create Dictionary    DeviceAddress=${DeviceAddress_01}    Function=${Function_AI}    Command=${AI_Commands_Init}    Data=@{MessageData}
    ${Result}    SendMessage    &{Message}
    Log Many    Result =    ${Result}
    @{ResultComponents}=    split string    ${Result}    |
    Log Many    DeviceAddress =    ${ResultComponents}[0]
    Log Many    Function =    ${ResultComponents}[1]
    Log Many    Command =    ${ResultComponents}[2]
    Log Many    ErrorInfomation =    ${ResultComponents}[3]
    Should Be Equal    ${ResultComponents}[0]    01
    Should Be Equal    ${ResultComponents}[1]    AI
    Should Be Equal    ${ResultComponents}[2]    Init
    Should Be Equal    ${ResultComponents}[3]    ${ERROR_NoInfo}

AI_GetStatus
    [Documentation]    This Test Case gets the status of AI01 (Analog Input 01) by invoking FH_AI_GetStatus_AI01 in FH embedded software source code
    ...    (For more information, refer to FH Documentation, AI (Analog Input) Messages, AI_GetStatus)
    @{MessageData} =    Create List    ${AI01}
    &{Message} =    Create Dictionary    DeviceAddress=${DeviceAddress_01}    Function=${Function_AI}    Command=${AI_Commands_GetStatus}    Data=@{MessageData}
    ${Result}    SendMessage    &{Message}
    Log Many    Result =    ${Result}
    @{ResultComponents}=    split string    ${Result}    |
    Log Many    DeviceAddress =    ${ResultComponents}[0]
    Log Many    Function =    ${ResultComponents}[1]
    Log Many    Command =    ${ResultComponents}[2]
    Log Many    ErrorInfomation =    ${ResultComponents}[3]
    Log Many    Status =    ${ResultComponents}[4]
    Should Be Equal    ${ResultComponents}[0]    01
    Should Be Equal    ${ResultComponents}[1]    AI
    Should Be Equal    ${ResultComponents}[2]    GetStatus
    Should Be Equal    ${ResultComponents}[3]    ${ERROR_NoInfo}
    Should Be Equal    ${ResultComponents}[4]    00110011

PWMO_Init
    [Documentation]    This Test Case initializes PWMO01 (PWM Output 01) by invoking FH_PWMO_Init_PWMO01 in FH embedded software source code
    ...    (For more information, refer to FH Documentation, PWMO (PWM Output) Messages, PWMO_Init)
    @{MessageData} =    Create List    ${PWMO01}
    &{Message} =    Create Dictionary    DeviceAddress=${DeviceAddress_01}    Function=${Function_PWMO}    Command=${PWMO_Commands_Init}    Data=@{MessageData}
    ${Result}    SendMessage    &{Message}
    Log Many    Result =    ${Result}
    @{ResultComponents}=    split string    ${Result}    |
    Log Many    DeviceAddress =    ${ResultComponents}[0]
    Log Many    Function =    ${ResultComponents}[1]
    Log Many    Command =    ${ResultComponents}[2]
    Log Many    ErrorInfomation =    ${ResultComponents}[3]
    Should Be Equal    ${ResultComponents}[0]    01
    Should Be Equal    ${ResultComponents}[1]    PWMO
    Should Be Equal    ${ResultComponents}[2]    Init
    Should Be Equal    ${ResultComponents}[3]    ${ERROR_NoInfo}

PWMO_SetStatus
    [Documentation]    This Test Case sets the status of PWMO01 (PWM Output 01) according to the related arguments (00 00 00 F0 32) by invoking FH_PWMO_Init_PWMO01 in FH embedded software source code
    ...    (For more information, refer to FH Documentation, PWMO (PWM Output) Messages, PWMO_SetStatus)
    @{MessageData} =    Create List    ${PWMO01}    00    00    00    F0    32
    &{Message} =    Create Dictionary    DeviceAddress=${DeviceAddress_01}    Function=${Function_PWMO}    Command=${PWMO_Commands_SetStatus}    Data=@{MessageData}
    ${Result}    SendMessage    &{Message}
    Log Many    Result =    ${Result}
    @{ResultComponents}=    split string    ${Result}    |
    Log Many    DeviceAddress =    ${ResultComponents}[0]
    Log Many    Function =    ${ResultComponents}[1]
    Log Many    Command =    ${ResultComponents}[2]
    Log Many    ErrorInfomation =    ${ResultComponents}[3]
    Should Be Equal    ${ResultComponents}[0]    01
    Should Be Equal    ${ResultComponents}[1]    PWMO
    Should Be Equal    ${ResultComponents}[2]    SetStatus
    Should Be Equal    ${ResultComponents}[3]    ${ERROR_NoInfo}

PWMI_Init
    [Documentation]    This Test Case initializes PWMI01 (PWM Input 01) by invoking FH_PWMI_Init_PWMI01 in FH embedded software source code
    ...    (For more information, refer to FH Documentation, PWMI (PWM Input) Messages, PWMI_Init)
    @{MessageData} =    Create List    ${PWMI01}
    &{Message} =    Create Dictionary    DeviceAddress=${DeviceAddress_01}    Function=${Function_PWMI}    Command=${PWMI_Commands_Init}    Data=@{MessageData}
    ${Result}    SendMessage    &{Message}
    Log Many    Result =    ${Result}
    @{ResultComponents}=    split string    ${Result}    |
    Log Many    DeviceAddress =    ${ResultComponents}[0]
    Log Many    Function =    ${ResultComponents}[1]
    Log Many    Command =    ${ResultComponents}[2]
    Log Many    ErrorInfomation =    ${ResultComponents}[3]
    Should Be Equal    ${ResultComponents}[0]    01
    Should Be Equal    ${ResultComponents}[1]    PWMI
    Should Be Equal    ${ResultComponents}[2]    Init
    Should Be Equal    ${ResultComponents}[3]    ${ERROR_NoInfo}

PWMI_GetStatus
    [Documentation]    This Test Case gets the status of PWMI01 (PWM Input 01) by invoking FH_PWMI_Init_PWMO01 in FH embedded software source code
    ...    (For more information, refer to FH Documentation, PWMI (PWM Input) Messages, PWMI_GetStatus)
    @{MessageData} =    Create List    ${PWMI01}
    &{Message} =    Create Dictionary    DeviceAddress=${DeviceAddress_01}    Function=${Function_PWMI}    Command=${PWMI_Commands_GetStatus}    Data=@{MessageData}
    ${Result}    SendMessage    &{Message}
    Log Many    Result =    ${Result}
    @{ResultComponents}=    split string    ${Result}    |
    Log Many    DeviceAddress =    ${ResultComponents}[0]
    Log Many    Function =    ${ResultComponents}[1]
    Log Many    Command =    ${ResultComponents}[2]
    Log Many    ErrorInfomation =    ${ResultComponents}[3]
    Log Many    Frequency =    ${ResultComponents}[4]
    Log Many    Duty Cycle =    ${ResultComponents}[5]
    Should Be Equal    ${ResultComponents}[0]    01
    Should Be Equal    ${ResultComponents}[1]    PWMI
    Should Be Equal    ${ResultComponents}[2]    GetStatus
    Should Be Equal    ${ResultComponents}[3]    ${ERROR_NoInfo}
    Should Be Equal    ${ResultComponents}[4]    00110011
    Should Be Equal    ${ResultComponents}[5]    32

UART_Init
    [Documentation]    This Test Case initializes UART01 (UART 01) by invoking FH_UART_Init_UART01 in FH embedded software source code
    ...    (For more information, refer to FH Documentation, UART Messages, UART_Init)
    @{MessageData} =    Create List    ${UART01}
    &{Message} =    Create Dictionary    DeviceAddress=${DeviceAddress_01}    Function=${Function_UART}    Command=${UART_Commands_Init}    Data=@{MessageData}
    ${Result}    SendMessage    &{Message}
    Log Many    Result =    ${Result}
    @{ResultComponents}=    split string    ${Result}    |
    Log Many    DeviceAddress =    ${ResultComponents}[0]
    Log Many    Function =    ${ResultComponents}[1]
    Log Many    Command =    ${ResultComponents}[2]
    Log Many    ErrorInfomation =    ${ResultComponents}[3]
    Should Be Equal    ${ResultComponents}[0]    01
    Should Be Equal    ${ResultComponents}[1]    UART
    Should Be Equal    ${ResultComponents}[2]    Init
    Should Be Equal    ${ResultComponents}[3]    ${ERROR_NoInfo}

UART_Send
    [Documentation]    This Test Case sends data through UART01 (UART 01) according to the related arguments (02 B1 FF) by invoking FH_UART_Send_UART01 in FH embedded software source code
    ...    (For more information, refer to FH Documentation, UART Messages, UART_Send)
    @{MessageData} =    Create List    ${UART01}    02    B1    FF
    &{Message} =    Create Dictionary    DeviceAddress=${DeviceAddress_01}    Function=${Function_UART}    Command=${UART_Commands_Send}    Data=@{MessageData}
    ${Result}    SendMessage    &{Message}
    Log Many    Result =    ${Result}
    @{ResultComponents}=    split string    ${Result}    |
    Log Many    DeviceAddress =    ${ResultComponents}[0]
    Log Many    Function =    ${ResultComponents}[1]
    Log Many    Command =    ${ResultComponents}[2]
    Log Many    ErrorInfomation =    ${ResultComponents}[3]
    Should Be Equal    ${ResultComponents}[0]    01
    Should Be Equal    ${ResultComponents}[1]    UART
    Should Be Equal    ${ResultComponents}[2]    Send
    Should Be Equal    ${ResultComponents}[3]    ${ERROR_NoInfo}

UART_Receive
    [Documentation]    This Test Case retrieves the ISR (Interrupt Service Routine) receive buffer of the UART01 (UART 01) by invoking FH_UART_Receive_UART01 in FH embedded software source code
    ...    (For more information, refer to FH Documentation, UART Messages, UART_Receive)
    @{MessageData} =    Create List    ${UART01}
    &{Message} =    Create Dictionary    DeviceAddress=${DeviceAddress_01}    Function=${Function_UART}    Command=${UART_Commands_Receive}    Data=@{MessageData}
    ${Result}    SendMessage    &{Message}
    Log Many    Result =    ${Result}
    @{ResultComponents}=    split string    ${Result}    |
    Log Many    DeviceAddress =    ${ResultComponents}[0]
    Log Many    Function =    ${ResultComponents}[1]
    Log Many    Command =    ${ResultComponents}[2]
    Log Many    ErrorInfomation =    ${ResultComponents}[3]
    Log Many    DataLength =    ${ResultComponents}[4]
    Log Many    Data =    ${ResultComponents}[5]
    Should Be Equal    ${ResultComponents}[0]    01
    Should Be Equal    ${ResultComponents}[1]    UART
    Should Be Equal    ${ResultComponents}[2]    Receive
    Should Be Equal    ${ResultComponents}[3]    ${ERROR_NoInfo}
    Should Be Equal    ${ResultComponents}[4]    04
    Should Be Equal    ${ResultComponents}[5]    ABCDabcd

UART_ReceiveW
    [Documentation]    This Test Case waits to receive the specified number of bytes of data through the ISR (Interrupt Service Routine) receive buffer of the UART01 (UART 01) according to the rerlated arguments (05 00 00 0B B8) by invoking FH_UART_ReceiveW_UART01 in FH embedded software source code
    ...    (For more information, refer to FH Documentation, UART Messages, UART_ReceiveW)
    @{MessageData} =    Create List    ${UART01}    05    00    00    0B    B8
    &{Message} =    Create Dictionary    DeviceAddress=${DeviceAddress_01}    Function=${Function_UART}    Command=${UART_Commands_ReceiveW}    Data=@{MessageData}
    ${Result}    SendMessage    &{Message}
    Log Many    Result =    ${Result}
    @{ResultComponents}=    split string    ${Result}    |
    Log Many    DeviceAddress =    ${ResultComponents}[0]
    Log Many    Function =    ${ResultComponents}[1]
    Log Many    Command =    ${ResultComponents}[2]
    Log Many    ErrorInfomation =    ${ResultComponents}[3]
    Log Many    DataLength =    ${ResultComponents}[4]
    Log Many    Data =    ${ResultComponents}[5]
    Should Be Equal    ${ResultComponents}[0]    01
    Should Be Equal    ${ResultComponents}[1]    UART
    Should Be Equal    ${ResultComponents}[2]    ReceiveW
    Should Be Equal    ${ResultComponents}[3]    ${ERROR_NoInfo}
    Should Be Equal    ${ResultComponents}[4]    05
    Should Be Equal    ${ResultComponents}[5]    ABCDabcd

UART_ResetRB
    [Documentation]    This Test Case resets the ISR (Interrupt Service Routine) receive buffer index of the UART01 (UART 01) by invoking FH_UART_ResetRB_UART01 in FH embedded software source code
    ...    (For more information, refer to FH Documentation, UART Messages, UART_ResetRB)
    @{MessageData} =    Create List    ${UART01}
    &{Message} =    Create Dictionary    DeviceAddress=${DeviceAddress_01}    Function=${Function_UART}    Command=${UART_Commands_ResetRB}    Data=@{MessageData}
    ${Result}    SendMessage    &{Message}
    Log Many    Result =    ${Result}
    @{ResultComponents}=    split string    ${Result}    |
    Log Many    DeviceAddress =    ${ResultComponents}[0]
    Log Many    Function =    ${ResultComponents}[1]
    Log Many    Command =    ${ResultComponents}[2]
    Log Many    ErrorInfomation =    ${ResultComponents}[3]
    Should Be Equal    ${ResultComponents}[0]    01
    Should Be Equal    ${ResultComponents}[1]    UART
    Should Be Equal    ${ResultComponents}[2]    ResetRB
    Should Be Equal    ${ResultComponents}[3]    ${ERROR_NoInfo}

UART_SSD8
    [Documentation]    This Test Case sets the shared data buffer (8 bit buffer) of the UART01 (UART 01) according to the related arguments (04 AA BB CC DD) by invoking FH_UART_SSD8_UART01 in FH embedded software source code
    ...    (For more information, refer to FH Documentation, UART Messages, UART_SSD8)
    @{MessageData} =    Create List    ${UART01}    04    AA    BB    CC    DD
    &{Message} =    Create Dictionary    DeviceAddress=${DeviceAddress_01}    Function=${Function_UART}    Command=${UART_Commands_SSD8}    Data=@{MessageData}
    ${Result}    SendMessage    &{Message}
    Log Many    Result =    ${Result}
    @{ResultComponents}=    split string    ${Result}    |
    Log Many    DeviceAddress =    ${ResultComponents}[0]
    Log Many    Function =    ${ResultComponents}[1]
    Log Many    Command =    ${ResultComponents}[2]
    Log Many    ErrorInfomation =    ${ResultComponents}[3]
    Should Be Equal    ${ResultComponents}[0]    01
    Should Be Equal    ${ResultComponents}[1]    UART
    Should Be Equal    ${ResultComponents}[2]    SSD8
    Should Be Equal    ${ResultComponents}[3]    ${ERROR_Ok}

UART_SSD16
    [Documentation]    This Test Case sets the shared data buffer (16 bit buffer) of the UART01 (UART 01) according to the related arguments (02 AA BB CC DD) by invoking FH_UART_SSD16_UART01 in FH embedded software source code
    ...    (For more information, refer to FH Documentation, UART Messages, UART_SSD16)
    @{MessageData} =    Create List    ${UART01}    02    AA    BB    CC    DD
    &{Message} =    Create Dictionary    DeviceAddress=${DeviceAddress_01}    Function=${Function_UART}    Command=${UART_Commands_SSD16}    Data=@{MessageData}
    ${Result}    SendMessage    &{Message}
    Log Many    Result =    ${Result}
    @{ResultComponents}=    split string    ${Result}    |
    Log Many    DeviceAddress =    ${ResultComponents}[0]
    Log Many    Function =    ${ResultComponents}[1]
    Log Many    Command =    ${ResultComponents}[2]
    Log Many    ErrorInfomation =    ${ResultComponents}[3]
    Should Be Equal    ${ResultComponents}[0]    01
    Should Be Equal    ${ResultComponents}[1]    UART
    Should Be Equal    ${ResultComponents}[2]    SSD16
    Should Be Equal    ${ResultComponents}[3]    ${ERROR_Ok}

UART_SSD32
    [Documentation]    This Test Case sets the shared data buffer (32 bit buffer) of the UART01 (UART 01) according to the related arguments (02 AA BB CC DD 01 02 03 04) by invoking FH_UART_SSD32_UART01 in FH embedded software source code
    ...    (For more information, refer to FH Documentation, UART Messages, UART_SSD32)
    @{MessageData} =    Create List    ${UART01}    02    AA    BB    CC    DD    01    02    03    04
    &{Message} =    Create Dictionary    DeviceAddress=${DeviceAddress_01}    Function=${Function_UART}    Command=${UART_Commands_SSD32}    Data=@{MessageData}
    ${Result}    SendMessage    &{Message}
    Log Many    Result =    ${Result}
    @{ResultComponents}=    split string    ${Result}    |
    Log Many    DeviceAddress =    ${ResultComponents}[0]
    Log Many    Function =    ${ResultComponents}[1]
    Log Many    Command =    ${ResultComponents}[2]
    Log Many    ErrorInfomation =    ${ResultComponents}[3]
    Should Be Equal    ${ResultComponents}[0]    01
    Should Be Equal    ${ResultComponents}[1]    UART
    Should Be Equal    ${ResultComponents}[2]    SSD32
    Should Be Equal    ${ResultComponents}[3]    ${ERROR_Ok}

UART_GSD8
    [Documentation]    This Test Case gets the shared data buffer (8 bit buffer) of the UART01 (UART 01) by invoking FH_UART_GSD8_UART01 in FH embedded software source code
    ...    (For more information, refer to FH Documentation, UART Messages, UART_GSD8)
    @{MessageData} =    Create List    ${UART01}
    &{Message} =    Create Dictionary    DeviceAddress=${DeviceAddress_01}    Function=${Function_UART}    Command=${UART_Commands_GSD8}    Data=@{MessageData}
    ${Result}    SendMessage    &{Message}
    Log Many    Result =    ${Result}
    @{ResultComponents}=    split string    ${Result}    |
    Log Many    DeviceAddress =    ${ResultComponents}[0]
    Log Many    Function =    ${ResultComponents}[1]
    Log Many    Command =    ${ResultComponents}[2]
    Log Many    ErrorInfomation =    ${ResultComponents}[3]
    Log Many    DataLength =    ${ResultComponents}[4]
    Log Many    Data =    ${ResultComponents}[5]
    Should Be Equal    ${ResultComponents}[0]    01
    Should Be Equal    ${ResultComponents}[1]    UART
    Should Be Equal    ${ResultComponents}[2]    GSD8
    Should Be Equal    ${ResultComponents}[3]    ${ERROR_Ok}
    Should Be Equal    ${ResultComponents}[4]    10
    Should Be Equal    ${ResultComponents}[5]    aabbccdd000000000000000000000000

UART_GSD16
    [Documentation]    This Test Case gets the shared data buffer (16 bit buffer) of the UART01 (UART 01) by invoking FH_UART_GSD16_UART01 in FH embedded software source code
    ...    (For more information, refer to FH Documentation, UART Messages, UART_GSD16)
    @{MessageData} =    Create List    ${UART01}
    &{Message} =    Create Dictionary    DeviceAddress=${DeviceAddress_01}    Function=${Function_UART}    Command=${UART_Commands_GSD16}    Data=@{MessageData}
    ${Result}    SendMessage    &{Message}
    Log Many    Result =    ${Result}
    @{ResultComponents}=    split string    ${Result}    |
    Log Many    DeviceAddress =    ${ResultComponents}[0]
    Log Many    Function =    ${ResultComponents}[1]
    Log Many    Command =    ${ResultComponents}[2]
    Log Many    ErrorInfomation =    ${ResultComponents}[3]
    Log Many    DataLength =    ${ResultComponents}[4]
    Log Many    Data =    ${ResultComponents}[5]
    Should Be Equal    ${ResultComponents}[0]    01
    Should Be Equal    ${ResultComponents}[1]    UART
    Should Be Equal    ${ResultComponents}[2]    GSD16
    Should Be Equal    ${ResultComponents}[3]    ${ERROR_Ok}
    Should Be Equal    ${ResultComponents}[4]    10
    Should Be Equal    ${ResultComponents}[5]    aabbccdd000000000000000000000000

UART_GSD32
    [Documentation]    This Test Case gets the shared data buffer (32 bit buffer) of the UART01 (UART 01) by invoking FH_UART_GSD32_UART01 in FH embedded software source code
    ...    (For more information, refer to FH Documentation, UART Messages, UART_GSD32)
    @{MessageData} =    Create List    ${UART01}
    &{Message} =    Create Dictionary    DeviceAddress=${DeviceAddress_01}    Function=${Function_UART}    Command=${UART_Commands_GSD32}    Data=@{MessageData}
    ${Result}    SendMessage    &{Message}
    Log Many    Result =    ${Result}
    @{ResultComponents}=    split string    ${Result}    |
    Log Many    DeviceAddress =    ${ResultComponents}[0]
    Log Many    Function =    ${ResultComponents}[1]
    Log Many    Command =    ${ResultComponents}[2]
    Log Many    ErrorInfomation =    ${ResultComponents}[3]
    Log Many    DataLength =    ${ResultComponents}[4]
    Log Many    Data =    ${ResultComponents}[5]
    Should Be Equal    ${ResultComponents}[0]    01
    Should Be Equal    ${ResultComponents}[1]    UART
    Should Be Equal    ${ResultComponents}[2]    GSD32
    Should Be Equal    ${ResultComponents}[3]    ${ERROR_Ok}
    Should Be Equal    ${ResultComponents}[4]    10
    Should Be Equal    ${ResultComponents}[5]    aabbccdd010203040000000000000000

CAN_Init
    @{MessageData} =    Create List    ${CAN01}
    &{Message} =    Create Dictionary    DeviceAddress=${DeviceAddress_01}    Function=${Function_CAN}    Command=${CAN_Commands_Init}    Data=@{MessageData}
    ${Result}    SendMessage    &{Message}
    Log Many    Result =    ${Result}
    @{ResultComponents}=    split string    ${Result}    |
    Log Many    DeviceAddress =    ${ResultComponents}[0]
    Log Many    Function =    ${ResultComponents}[1]
    Log Many    Command =    ${ResultComponents}[2]
    Log Many    ErrorInfomation =    ${ResultComponents}[3]
    Should Be Equal    ${ResultComponents}[0]    01
    Should Be Equal    ${ResultComponents}[1]    CAN
    Should Be Equal    ${ResultComponents}[2]    Init
    Should Be Equal    ${ResultComponents}[3]    ${ERROR_NoInfo}

CAN_Send
    [Documentation]    This Test Case sends data through CAN01 (CAN 01) according to the related arguments (02 B1 FF) by invoking FH_CAN_Send_CAN01 in FH embedded software source code
    ...    (For more information, refer to FH Documentation, CAN Messages, CAN_Send)
    @{MessageData} =    Create List    ${CAN01}    02    B1    FF
    &{Message} =    Create Dictionary    DeviceAddress=${DeviceAddress_01}    Function=${Function_CAN}    Command=${CAN_Commands_Send}    Data=@{MessageData}
    ${Result}    SendMessage    &{Message}
    Log Many    Result =    ${Result}
    @{ResultComponents}=    split string    ${Result}    |
    Log Many    DeviceAddress =    ${ResultComponents}[0]
    Log Many    Function =    ${ResultComponents}[1]
    Log Many    Command =    ${ResultComponents}[2]
    Log Many    ErrorInfomation =    ${ResultComponents}[3]
    Should Be Equal    ${ResultComponents}[0]    01
    Should Be Equal    ${ResultComponents}[1]    CAN
    Should Be Equal    ${ResultComponents}[2]    Send
    Should Be Equal    ${ResultComponents}[3]    ${ERROR_NoInfo}

CAN_Receive
    [Documentation]    This Test Case retrieves the ISR (Interrupt Service Routine) receive buffer of the CAN01 (CAN 01) by invoking FH_CAN_Receive_CAN01 in FH embedded software source code
    ...    (For more information, refer to FH Documentation, CAN Messages, CAN_Receive)
    @{MessageData} =    Create List    ${CAN01}
    &{Message} =    Create Dictionary    DeviceAddress=${DeviceAddress_01}    Function=${Function_CAN}    Command=${CAN_Commands_Receive}    Data=@{MessageData}
    ${Result}    SendMessage    &{Message}
    Log Many    Result =    ${Result}
    @{ResultComponents}=    split string    ${Result}    |
    Log Many    DeviceAddress =    ${ResultComponents}[0]
    Log Many    Function =    ${ResultComponents}[1]
    Log Many    Command =    ${ResultComponents}[2]
    Log Many    ErrorInfomation =    ${ResultComponents}[3]
    Log Many    DataLength =    ${ResultComponents}[4]
    Log Many    Data =    ${ResultComponents}[5]
    Should Be Equal    ${ResultComponents}[0]    01
    Should Be Equal    ${ResultComponents}[1]    CAN
    Should Be Equal    ${ResultComponents}[2]    Receive
    Should Be Equal    ${ResultComponents}[3]    ${ERROR_NoInfo}
    Should Be Equal    ${ResultComponents}[4]    04
    Should Be Equal    ${ResultComponents}[5]    ABCDabcd

CAN_ReceiveW
    [Documentation]    This Test Case waits to receive the specified number of bytes of data through the ISR (Interrupt Service Routine) receive buffer of the CAN01 (CAN 01) according to the rerlated arguments (05 00 00 0B B8) by invoking FH_CAN_ReceiveW_CAN01 in FH embedded software source code
    ...    (For more information, refer to FH Documentation, CAN Messages, CAN_ReceiveW)
    @{MessageData} =    Create List    ${CAN01}    05    00    00    0B    B8
    &{Message} =    Create Dictionary    DeviceAddress=${DeviceAddress_01}    Function=${Function_CAN}    Command=${CAN_Commands_ReceiveW}    Data=@{MessageData}
    ${Result}    SendMessage    &{Message}
    Log Many    Result =    ${Result}
    @{ResultComponents}=    split string    ${Result}    |
    Log Many    DeviceAddress =    ${ResultComponents}[0]
    Log Many    Function =    ${ResultComponents}[1]
    Log Many    Command =    ${ResultComponents}[2]
    Log Many    ErrorInfomation =    ${ResultComponents}[3]
    Log Many    DataLength =    ${ResultComponents}[4]
    Log Many    Data =    ${ResultComponents}[5]
    Should Be Equal    ${ResultComponents}[0]    01
    Should Be Equal    ${ResultComponents}[1]    CAN
    Should Be Equal    ${ResultComponents}[2]    ReceiveW
    Should Be Equal    ${ResultComponents}[3]    ${ERROR_NoInfo}
    Should Be Equal    ${ResultComponents}[4]    04
    Should Be Equal    ${ResultComponents}[5]    ABCDabcd

CAN_ResetRB
    [Documentation]    This Test Case resets the ISR (Interrupt Service Routine) receive buffer index of the CAN01 (CAN 01) by invoking FH_CAN_ResetRB_CAN01 in FH embedded software source code
    ...    (For more information, refer to FH Documentation, CAN Messages, CAN_ResetRB)
    @{MessageData} =    Create List    ${CAN01}
    &{Message} =    Create Dictionary    DeviceAddress=${DeviceAddress_01}    Function=${Function_CAN}    Command=${CAN_Commands_ResetRB}    Data=@{MessageData}
    ${Result}    SendMessage    &{Message}
    Log Many    Result =    ${Result}
    @{ResultComponents}=    split string    ${Result}    |
    Log Many    DeviceAddress =    ${ResultComponents}[0]
    Log Many    Function =    ${ResultComponents}[1]
    Log Many    Command =    ${ResultComponents}[2]
    Log Many    ErrorInfomation =    ${ResultComponents}[3]
    Should Be Equal    ${ResultComponents}[0]    01
    Should Be Equal    ${ResultComponents}[1]    CAN
    Should Be Equal    ${ResultComponents}[2]    ResetRB
    Should Be Equal    ${ResultComponents}[3]    ${ERROR_NoInfo}

CAN_SSD8
    [Documentation]    This Test Case sets the shared data buffer (8 bit buffer) of the CAN01 (CAN 01) according to the related arguments (04 AA BB CC DD) by invoking FH_CAN_SSD8_CAN01 in FH embedded software source code
    ...    (For more information, refer to FH Documentation, CAN Messages, CAN_SSD8)
    @{MessageData} =    Create List    ${CAN01}    04    AA    BB    CC    DD
    &{Message} =    Create Dictionary    DeviceAddress=${DeviceAddress_01}    Function=${Function_CAN}    Command=${CAN_Commands_SSD8}    Data=@{MessageData}
    ${Result}    SendMessage    &{Message}
    Log Many    Result =    ${Result}
    @{ResultComponents}=    split string    ${Result}    |
    Log Many    DeviceAddress =    ${ResultComponents}[0]
    Log Many    Function =    ${ResultComponents}[1]
    Log Many    Command =    ${ResultComponents}[2]
    Log Many    ErrorInfomation =    ${ResultComponents}[3]
    Should Be Equal    ${ResultComponents}[0]    01
    Should Be Equal    ${ResultComponents}[1]    CAN
    Should Be Equal    ${ResultComponents}[2]    SSD8
    Should Be Equal    ${ResultComponents}[3]    ${ERROR_Ok}

CAN_SSD16
    [Documentation]    This Test Case sets the shared data buffer (16 bit buffer) of the CAN01 (CAN 01) according to the related arguments (04 AA BB CC DD) by invoking FH_CAN_SSD16_CAN01 in FH embedded software source code
    ...    (For more information, refer to FH Documentation, CAN Messages, CAN_SSD16)
    @{MessageData} =    Create List    ${CAN01}    02    AA    BB    CC    DD
    &{Message} =    Create Dictionary    DeviceAddress=${DeviceAddress_01}    Function=${Function_CAN}    Command=${CAN_Commands_SSD16}    Data=@{MessageData}
    ${Result}    SendMessage    &{Message}
    Log Many    Result =    ${Result}
    @{ResultComponents}=    split string    ${Result}    |
    Log Many    DeviceAddress =    ${ResultComponents}[0]
    Log Many    Function =    ${ResultComponents}[1]
    Log Many    Command =    ${ResultComponents}[2]
    Log Many    ErrorInfomation =    ${ResultComponents}[3]
    Should Be Equal    ${ResultComponents}[0]    01
    Should Be Equal    ${ResultComponents}[1]    CAN
    Should Be Equal    ${ResultComponents}[2]    SSD16
    Should Be Equal    ${ResultComponents}[3]    ${ERROR_Ok}

CAN_SSD32
    [Documentation]    This Test Case sets the shared data buffer (32 bit buffer) of the CAN01 (CAN 01) according to the related arguments (02 AA BB CC DD 01 02 03 04) by invoking FH_CAN_SSD32_CAN01 in FH embedded software source code
    ...    (For more information, refer to FH Documentation, CAN Messages, CAN_SSD32)
    @{MessageData} =    Create List    ${CAN01}    02    AA    BB    CC    DD    01    02    03    04
    &{Message} =    Create Dictionary    DeviceAddress=${DeviceAddress_01}    Function=${Function_CAN}    Command=${CAN_Commands_SSD32}    Data=@{MessageData}
    ${Result}    SendMessage    &{Message}
    Log Many    Result =    ${Result}
    @{ResultComponents}=    split string    ${Result}    |
    Log Many    DeviceAddress =    ${ResultComponents}[0]
    Log Many    Function =    ${ResultComponents}[1]
    Log Many    Command =    ${ResultComponents}[2]
    Log Many    ErrorInfomation =    ${ResultComponents}[3]
    Should Be Equal    ${ResultComponents}[0]    01
    Should Be Equal    ${ResultComponents}[1]    CAN
    Should Be Equal    ${ResultComponents}[2]    SSD32
    Should Be Equal    ${ResultComponents}[3]    ${ERROR_Ok}

CAN_GSD8
    [Documentation]    This Test Case gets the shared data buffer (8 bit buffer) of the CAN01 (CAN 01) by invoking FH_CAN_GSD8_CAN01 in FH embedded software source code
    ...    (For more information, refer to FH Documentation, CAN Messages, CAN_GSD8)
    @{MessageData} =    Create List    ${CAN01}
    &{Message} =    Create Dictionary    DeviceAddress=${DeviceAddress_01}    Function=${Function_CAN}    Command=${CAN_Commands_GSD8}    Data=@{MessageData}
    ${Result}    SendMessage    &{Message}
    Log Many    Result =    ${Result}
    @{ResultComponents}=    split string    ${Result}    |
    Log Many    DeviceAddress =    ${ResultComponents}[0]
    Log Many    Function =    ${ResultComponents}[1]
    Log Many    Command =    ${ResultComponents}[2]
    Log Many    ErrorInfomation =    ${ResultComponents}[3]
    Log Many    DataLength =    ${ResultComponents}[4]
    Log Many    Data =    ${ResultComponents}[5]
    Should Be Equal    ${ResultComponents}[0]    01
    Should Be Equal    ${ResultComponents}[1]    CAN
    Should Be Equal    ${ResultComponents}[2]    GSD8
    Should Be Equal    ${ResultComponents}[3]    ${ERROR_Ok}
    Should Be Equal    ${ResultComponents}[4]    10
    Should Be Equal    ${ResultComponents}[5]    aabbccdd000000000000000000000000

CAN_GSD16
    [Documentation]    This Test Case gets the shared data buffer (16 bit buffer) of the CAN01 (CAN 01) by invoking FH_CAN_GSD16_CAN01 in FH embedded software source code
    ...    (For more information, refer to FH Documentation, CAN Messages, CAN_GSD16)
    @{MessageData} =    Create List    ${CAN01}
    &{Message} =    Create Dictionary    DeviceAddress=${DeviceAddress_01}    Function=${Function_CAN}    Command=${CAN_Commands_GSD16}    Data=@{MessageData}
    ${Result}    SendMessage    &{Message}
    Log Many    Result =    ${Result}
    @{ResultComponents}=    split string    ${Result}    |
    Log Many    DeviceAddress =    ${ResultComponents}[0]
    Log Many    Function =    ${ResultComponents}[1]
    Log Many    Command =    ${ResultComponents}[2]
    Log Many    ErrorInfomation =    ${ResultComponents}[3]
    Log Many    DataLength =    ${ResultComponents}[4]
    Log Many    Data =    ${ResultComponents}[5]
    Should Be Equal    ${ResultComponents}[0]    01
    Should Be Equal    ${ResultComponents}[1]    CAN
    Should Be Equal    ${ResultComponents}[2]    GSD16
    Should Be Equal    ${ResultComponents}[3]    ${ERROR_Ok}
    Should Be Equal    ${ResultComponents}[4]    10
    Should Be Equal    ${ResultComponents}[5]    aabbccdd000000000000000000000000

CAN_GSD32
    [Documentation]    This Test Case gets the shared data buffer (32 bit buffer) of the CAN01 (CAN 01) by invoking FH_CAN_GSD32_CAN01 in FH embedded software source code
    ...    (For more information, refer to FH Documentation, CAN Messages, CAN_GSD32)
    @{MessageData} =    Create List    ${CAN01}
    &{Message} =    Create Dictionary    DeviceAddress=${DeviceAddress_01}    Function=${Function_CAN}    Command=${CAN_Commands_GSD32}    Data=@{MessageData}
    ${Result}    SendMessage    &{Message}
    Log Many    Result =    ${Result}
    @{ResultComponents}=    split string    ${Result}    |
    Log Many    DeviceAddress =    ${ResultComponents}[0]
    Log Many    Function =    ${ResultComponents}[1]
    Log Many    Command =    ${ResultComponents}[2]
    Log Many    ErrorInfomation =    ${ResultComponents}[3]
    Log Many    DataLength =    ${ResultComponents}[4]
    Log Many    Data =    ${ResultComponents}[5]
    Should Be Equal    ${ResultComponents}[0]    01
    Should Be Equal    ${ResultComponents}[1]    CAN
    Should Be Equal    ${ResultComponents}[2]    GSD32
    Should Be Equal    ${ResultComponents}[3]    ${ERROR_Ok}
    Should Be Equal    ${ResultComponents}[4]    10
    Should Be Equal    ${ResultComponents}[5]    aabbccdd010203040000000000000000

*** Keywords ***
SuiteSetup
    Add Port    ${SerialPortName}    baudrate=115200    bytesize=8    encoding=ascci    timeout=5
    Open Port    ${SerialPortName}

SuiteTeardown
    Close Port    ${SerialPortName}
