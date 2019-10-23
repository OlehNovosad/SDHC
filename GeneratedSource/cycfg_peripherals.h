/*******************************************************************************
* File Name: cycfg_peripherals.h
*
* Description:
* Peripheral Hardware Block configuration
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

#if !defined(CYCFG_PERIPHERALS_H)
#define CYCFG_PERIPHERALS_H

#include "cycfg_notices.h"
#include "cy_scb_uart.h"
#include "cy_sysclk.h"
#include "cy_sd_host.h"

#if defined(__cplusplus)
extern "C" {
#endif

#define Bridge_UART_HW SCB5
#define Bridge_UART_IRQ scb_5_interrupt_IRQn
#define SDHC_HW SDHC1
#define SDHC_IRQ sdhc_1_interrupt_general_IRQn

extern const cy_stc_scb_uart_config_t Bridge_UART_config;
extern cy_en_sd_host_card_capacity_t SDHC_cardCapacity;
extern cy_en_sd_host_card_type_t SDHC_cardType;
extern uint32_t SDHC_rca;
extern const cy_stc_sd_host_init_config_t SDHC_config;
extern cy_stc_sd_host_sd_card_config_t SDHC_card_cfg;

void init_cycfg_peripherals(void);

#if defined(__cplusplus)
}
#endif


#endif /* CYCFG_PERIPHERALS_H */
