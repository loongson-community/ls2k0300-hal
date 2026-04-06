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
/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
extern TIM_HandleTypeDef  htim;
extern UART_HandleTypeDef huart0;
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

void ATIM_LIOINTC_IRQHandler(void)
{
  HAL_UART_Transmit(&huart0, (uint8_t *)"Hello, IRQ!\n", 12, -1);
  HAL_GPIO_TogglePin(83);
	HAL_TIM_IRQHandler(&htim);
}
