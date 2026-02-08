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
Library           String
Library           Collections
Library           SerialLibrary

*** Keywords ***
SendMessage
    [Arguments]    &{Message}
    Write Data    ${Message}[DeviceAddress]
    Write Data    ${Message}[Function]
    Write Data    ${Message}[Command]
    ${Data_Len}=    Get length    ${Message}[Data]
    ${Data_Len_Hex}=    Convert To Hex    ${Data_Len}
    ${Data_Len_Hex_Len}=    Get length    ${Data_Len_Hex}
    IF    ${Data_Len_Hex_Len} < 2
        ${Data_Len_Hex_Formatted}=    Catenate    SEPARATOR=    0    ${Data_Len_Hex}
    ELSE
        ${Data_Len_Hex_Formatted}=    Set Variable    ${Data_Len_Hex}
    END
    @{Data_Len_Hex_Formatted_Chars} =    Split String To Characters    ${Data_Len_Hex_Formatted}
    ${Data_Len_Hex_Formatted_Chars} =    Catenate    SEPARATOR=    ${Data_Len_Hex_Formatted_Chars}[0]    ${Data_Len_Hex_Formatted_Chars}[1]
    ${Data_Len_Hex_Formatted_Chars_String}=    Convert To String    ${Data_Len_Hex_Formatted_Chars}
    Write Data    ${Data_Len_Hex_Formatted_Chars_String}
    FOR    ${element}    IN    @{Message}[Data]
        Write Data    ${element}
    END
    Write Data    AA
    ${read} =    Read Until    encoding=ascii
    Return From Keyword    ${read}
