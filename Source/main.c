/***************************************************************************//**
* \file main.c
* \version 1.0
*
* \brief
* Minimal new application template for 150MHz PSoC 6 devices. Debug is enabled 
* and platform clocks are set for high performance (144MHz CLK_FAST for CM4 
* core and 72MHz CLK_SLOW for CM0+) but with a peripheral-friendly CLK_PERI 
* frequency (72MHz).
*
********************************************************************************
* \copyright
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
*******************************************************************************/

#include "cy_device_headers.h"
#include "cycfg.h"
#include "stdio.h"
#include "cy_sd_host.h"
#include "cy_sysint.h"
#include "string.h"

#define SD_Host_INTR_NUM        sdhc_1_interrupt_general_IRQn
#define SD_Host_INTR_PRIORITY   (3UL)
#define DATA       (5u)  /* Data to write. */


cy_stc_scb_uart_context_t uart_context;
cy_stc_sd_host_context_t sdHostContext;
cy_en_sd_host_card_type_t cardType;
cy_en_sd_host_card_capacity_t cardCapacity;
cy_stc_sd_host_write_read_config_t data;
cy_en_sd_host_status_t ret;

uint32_t rca;

const cy_stc_sysint_t sdHostIntrConfig =
{
            #if (CY_CPU_CORTEX_M0P)
			  	  .intrSrc = NvicMux4_IRQn,
				  .cm0pSrc = SD_Host_INTR_NUM,
            #else
				 .intrSrc = SD_Host_INTR_NUM, /* SD Host interrupt number (non M0 core)*/
            #endif
				 .intrPriority = SD_Host_INTR_PRIORITY
};

const cy_stc_sd_host_init_config_t sdHostConfig =
{
    .dmaType = CY_SD_HOST_DMA_ADMA2,
    .enableLedControl = false,
    .emmc = false,
};

cy_stc_sd_host_sd_card_config_t sdCardConfig =
{
    .lowVoltageSignaling = false,
    .busWidth = CY_SD_HOST_BUS_WIDTH_4_BIT,
    .cardType = &cardType,
    .rca = &rca,
    .cardCapacity = &cardCapacity,
};

__WEAK bool Cy_SD_Host_IsCardConnected(SDHC_Type const *base)
{
	// pseudo
	//return (bool)Cy_GPIO_Read(13_5);
	return true;
}

void SD_Host_User_Isr(void)
{
    uint32_t normalStatus;
    uint32_t errorStatus;

    normalStatus = Cy_SD_Host_GetNormalInterruptStatus(SDHC_HW);
    /* Check the Error event */
    if (0u < normalStatus)
    {
        /* Clear the normalStatus event */
        Cy_SD_Host_ClearNormalInterruptStatus(SDHC_HW, normalStatus);
    }

    errorStatus = Cy_SD_Host_GetErrorInterruptStatus(SDHC_HW);
    /* Check the Error event */
    if (0u < errorStatus)
    {
        /* Clear the Error event */
        Cy_SD_Host_ClearErrorInterruptStatus(SDHC_HW, errorStatus);
    }

    /* Add the use code here. */
}

int main(void)
{
    /* Set up the device based on configurator selections */
    init_cycfg_all();

    __enable_irq();
 
    Cy_SCB_UART_Init(Bridge_UART_HW, &Bridge_UART_config, &uart_context);
    Cy_SCB_UART_Enable(Bridge_UART_HW);

    printf("\x1b[2J\x1b[;H");

    //Cy_SysClk_ClkHfSetSource(2u, CY_SYSCLK_CLKHF_IN_CLKPATH0);
    //Cy_SysClk_ClkHfSetDivider(2u, CY_SYSCLK_CLKHF_NO_DIVIDE);
    //Cy_SysClk_ClkHfEnable(2u);

    Cy_SysInt_Init(&sdHostIntrConfig, &SD_Host_User_Isr);
	NVIC_EnableIRQ(SD_Host_INTR_NUM);
	Cy_SD_Host_Enable(SDHC_HW);
	ret = Cy_SD_Host_Init(SDHC_HW, &sdHostConfig, &sdHostContext);

	if (CY_SD_HOST_SUCCESS == ret)
		ret = Cy_SD_Host_InitCard(SDHC1, &sdCardConfig, &sdHostContext);

	uint8_t rxBuff[CY_SD_HOST_BLOCK_SIZE];   /* Data to read. */
	uint8_t txBuff[CY_SD_HOST_BLOCK_SIZE];   /* Data to write. */

	memset(txBuff, DATA, sizeof(txBuff));  /* Fill the array with data to write. */

	printf("rxBuff before:\n\r");
//	for (int var = 0; var < CY_SD_HOST_BLOCK_SIZE; ++var) {
//		printf("%u ", rxBuff[var]);
//	}

	data.address = 0UL;         /* The address to write/read data on the card or eMMC. */
	data.numberOfBlocks = 1UL;  /* The number of blocks to write/read (Single block write/read). */
	data.autoCommand = CY_SD_HOST_AUTO_CMD_NONE;  /* Selects which auto commands are used if any. */
	data.dataTimeout = 12UL;     /* The timeout value for the transfer. */
	data.enReliableWrite = false; /* For EMMC cards enable reliable write. */
	data.enableDma = true;  /* Enable DMA mode. */

	data.data = (uint32_t*)txBuff;  /* The pointer to data to write. */
	ret = Cy_SD_Host_Write(SDHC1, &data, &sdHostContext);  /* Write data to the card. */

	if (CY_SD_HOST_SUCCESS == ret)
	{
	    while (CY_SD_HOST_XFER_COMPLETE != (Cy_SD_Host_GetNormalInterruptStatus(SDHC1) & CY_SD_HOST_XFER_COMPLETE))
	    {
	        /* Wait for the data-transaction complete event. */
	    }
	    Cy_SD_Host_ClearNormalInterruptStatus(SDHC1, CY_SD_HOST_XFER_COMPLETE);
	}

	data.data = (uint32_t*)rxBuff;  /* The pointer to data to read. */
	ret = Cy_SD_Host_Read(SDHC1, &data, &sdHostContext);   /* Read data from the card. */

	if (CY_SD_HOST_SUCCESS == ret)
	{
	    while (CY_SD_HOST_XFER_COMPLETE != (Cy_SD_Host_GetNormalInterruptStatus(SDHC1) & CY_SD_HOST_XFER_COMPLETE))
	    {
	        /* Wait for the data-transaction complete event. */
	    }

	    /* Clear the data-transaction complete event. */
	    Cy_SD_Host_ClearNormalInterruptStatus(SDHC1, CY_SD_HOST_XFER_COMPLETE);
	}

	printf("\r\n\nrxBuff after:\n\r");
	for (int var = 0; var < CY_SD_HOST_BLOCK_SIZE; ++var) {
		printf("%u ", rxBuff[var]);
	}

    for(;;)
    {

    }
}
