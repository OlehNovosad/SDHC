/*******************************************************************************
* File Name: cycfg_routing.h
*
* Description:
* Establishes all necessary connections between hardware elements.
* This file was automatically generated and should not be modified.
* 
********************************************************************************
* Copyright 2017-2019 Cypress Semiconductor Corporation
* SPDX-License-Identifier: Apache-2.0
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*     http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
********************************************************************************/

#if !defined(CYCFG_ROUTING_H)
#define CYCFG_ROUTING_H

#if defined(__cplusplus)
extern "C" {
#endif

#include "cycfg_notices.h"
void init_cycfg_routing(void);
#define init_cycfg_connectivity() init_cycfg_routing()
#define ioss_0_port_12_pin_1_HSIOM P12_1_SDHC1_CARD_DETECT_N
#define ioss_0_port_12_pin_2_HSIOM P12_2_SDHC1_CARD_MECH_WRITE_PROT
#define ioss_0_port_12_pin_4_HSIOM P12_4_SDHC1_CARD_CMD
#define ioss_0_port_12_pin_5_HSIOM P12_5_SDHC1_CLK_CARD
#define ioss_0_port_12_pin_6_HSIOM P12_6_SDHC1_CARD_IF_PWR_EN
#define ioss_0_port_12_pin_7_HSIOM P12_7_SDHC1_IO_VOLT_SEL
#define ioss_0_port_13_pin_0_HSIOM P13_0_SDHC1_CARD_DAT_3TO00
#define ioss_0_port_13_pin_1_HSIOM P13_1_SDHC1_CARD_DAT_3TO01
#define ioss_0_port_13_pin_2_HSIOM P13_2_SDHC1_CARD_DAT_3TO02
#define ioss_0_port_13_pin_3_HSIOM P13_3_SDHC1_CARD_DAT_3TO03
#define ioss_0_port_5_pin_0_HSIOM P5_0_SCB5_UART_RX
#define ioss_0_port_5_pin_1_HSIOM P5_1_SCB5_UART_TX
#define ioss_0_port_6_pin_4_HSIOM P6_4_CPUSS_SWJ_SWO_TDO
#define ioss_0_port_6_pin_6_HSIOM P6_6_CPUSS_SWJ_SWDIO_TMS
#define ioss_0_port_6_pin_7_HSIOM P6_7_CPUSS_SWJ_SWCLK_TCLK

#if defined(__cplusplus)
}
#endif


#endif /* CYCFG_ROUTING_H */