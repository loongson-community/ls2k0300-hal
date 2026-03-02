/**
  ******************************************************************************
  * @file    GPIO/Core/Src/main.c
  * @author  MCD Application Team
  * @author  Ilikara <3435193369@qq.com>
  * @brief   This sample code shows how to use LS2K03xx GPIO HAL API to control
  *          a LED.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2016 STMicroelectronics.
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

/** @addtogroup LS2K03xx_HAL_Examples
  * @{
  */

/** @addtogroup GPIO_LED
  * @{
  */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
static GPIO_InitTypeDef GPIO_InitStruct;

/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/**
  * @brief  Main program.
  * @param  None
  * @retval None
  */
int main(void)
{
  GPIO_InitStruct.Dir = GPIO_DIR_OUTPUT;
  GPIO_InitStruct.Mode = GPIO_MODE_GPIO;
  GPIO_InitStruct.Pin = 83;
  HAL_GPIO_Init(&GPIO_InitStruct);
  while (1)
  {
    HAL_Delay(500);
    HAL_GPIO_TogglePin(83);
  }
}

/**
  * @}
  */

/**
  * @}
  */
