/**
  ******************************************************************************
  * @file    ls2k03xx_it.c
  * @brief   Interrupt Service Routines.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2026 Ilikara <3435193369@qq.com>
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "ls2k03xx_it.h"

#include <stdio.h>
#include <string.h>
/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
extern DMA_HandleTypeDef hdma_adc;
extern UART_HandleTypeDef huart0;
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

uint8_t uartBuffer[128] = {0};
extern uint32_t adcValue[8];

void APB_DMA0_LIOINTC_IRQHandler(void)
{
  HAL_UART_Transmit(&huart0, (uint8_t *)"Hello, IRQ!\n", 12, -1);
  snprintf((char *)uartBuffer,
           sizeof(uartBuffer),
           "ADC Values: %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu\n",
           (unsigned long)adcValue[0],
           (unsigned long)adcValue[1],
           (unsigned long)adcValue[2],
           (unsigned long)adcValue[3],
           (unsigned long)adcValue[4],
           (unsigned long)adcValue[5],
           (unsigned long)adcValue[6],
           (unsigned long)adcValue[7]);
  HAL_UART_Transmit(&huart0, uartBuffer, strlen((char *)uartBuffer), -1);
  HAL_GPIO_TogglePin(83);
	HAL_DMA_IRQHandler(&hdma_adc);
}
