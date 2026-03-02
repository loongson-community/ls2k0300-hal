/**
  ******************************************************************************
  * @file    TIM/Core/Src/main.c
  * @author  MCD Application Team
  * @author  Ilikara <3435193369@qq.com>
  * @brief   This sample code shows how to use LS2K03xx TIM HAL API to generate
  *          1 signal in PWM to control a LED.
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

/** @addtogroup TIM_PWMOutput
  * @{
  */

/* Private typedef -----------------------------------------------------------*/
#define  PERIOD_VALUE       (uint32_t)(500000 - 1)  /* Period Value  */
#define  PULSE3_VALUE       (uint32_t)(PERIOD_VALUE/2)        /* Capture Compare 3 Value  */

/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Timer handler declaration */
TIM_HandleTypeDef    TimHandle;

/* Timer Output Compare Configuration Structure declaration */
TIM_OC_InitTypeDef sConfig;

GPIO_InitTypeDef   GPIO_InitStruct;

/* Counter Prescaler value */
uint32_t uhPrescalerValue = 0;

/* Private function prototypes -----------------------------------------------*/
static void Error_Handler(void);

/* Private functions ---------------------------------------------------------*/

/**
  * @brief  Main program.
  * @param  None
  * @retval None
  */
int main(void)
{
  GPIO_InitStruct.Mode = GPIO_MODE_AF_M;
  GPIO_InitStruct.Pin = 83;
  HAL_GPIO_Init(&GPIO_InitStruct);

  /* Compute the prescaler value to have TIM2 counter clock equal to 2000000 Hz */
  uhPrescalerValue = (uint32_t)(APB_FREQ / 2000000) - 1;

  TimHandle.Instance = ATIM;

  TimHandle.Init.Prescaler         = uhPrescalerValue;
  TimHandle.Init.Period            = PERIOD_VALUE;
  TimHandle.Init.ClockDivision     = 0;
  TimHandle.Init.CounterMode       = TIM_COUNTERMODE_UP;
  TimHandle.Init.RepetitionCounter = 0;
  TimHandle.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_PWM_Init(&TimHandle) != HAL_OK)
  {
    /* Initialization Error */
    Error_Handler();
  }

  /*##-2- Configure the PWM channels #########################################*/
  /* Common configuration for all channels */
  sConfig.OCMode       = TIM_OCMODE_PWM1;
  sConfig.OCPolarity   = TIM_OCPOLARITY_HIGH;
  sConfig.OCFastMode   = TIM_OCFAST_DISABLE;
  sConfig.OCNPolarity  = TIM_OCNPOLARITY_HIGH;
  sConfig.OCNIdleState = TIM_OCNIDLESTATE_RESET;

  sConfig.OCIdleState  = TIM_OCIDLESTATE_RESET;

  /* Set the pulse value for channel 3 */
  sConfig.Pulse = PULSE3_VALUE;
  if (HAL_TIM_PWM_ConfigChannel(&TimHandle, &sConfig, TIM_CHANNEL_3) != HAL_OK)
  {
    /* Configuration Error */
    Error_Handler();
  }

  /*##-3- Start PWM signals generation #######################################*/
  /* Start channel 3 */
  if (HAL_TIM_PWM_Start(&TimHandle, TIM_CHANNEL_3) != HAL_OK)
  {
    /* PWM generation Error */
    Error_Handler();
  }

  while (1)
  {
  }

}

/**
  * @brief  This function is executed in case of error occurrence.
  * @param  None
  * @retval None
  */
static void Error_Handler(void)
{
  while (1)
  {
  }
}

/**
  * @}
  */

/**
  * @}
  */
