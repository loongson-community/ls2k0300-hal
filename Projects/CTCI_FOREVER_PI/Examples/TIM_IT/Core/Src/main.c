/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
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

/* Private includes ----------------------------------------------------------*/
/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
#define  PSC_VALUE          (uint32_t)((APB_FREQ / 2000000) - 1)
#define  PERIOD_VALUE       (uint32_t)(500000 - 1)
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
UART_HandleTypeDef huart0;
TIM_HandleTypeDef  htim;
GPIO_InitTypeDef GPIO_InitStruct = {0};
/* Private function prototypes -----------------------------------------------*/
static void TIM_Init(void);
static void UART_Init(void);
/* Private user code ---------------------------------------------------------*/

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  HAL_Init();

  /* Initialize all configured peripherals */
  UART_Init();
  TIM_Init();

  GPIO_InitStruct.Dir = GPIO_DIR_OUTPUT;
  GPIO_InitStruct.Mode = GPIO_MODE_GPIO;
  GPIO_InitStruct.Pin = 83;
  HAL_GPIO_Init(&GPIO_InitStruct);

  if (HAL_TIM_Base_Start_IT(&htim) != HAL_OK)
  {
    Error_Handler();
  }

  while (1)
  {
    HAL_UART_Transmit(&huart0, (uint8_t *)"Hello, World!\n", 14, -1);
    HAL_Delay(500);
  }
}

/**
  * @brief UART0 Initialization Function
  * @param None
  * @retval None
  */
static void UART_Init(void)
{
  huart0.Instance = UART0;
  huart0.Init.BaudRate = 115200;
  huart0.Init.WordLength = UART_WORDLENGTH_8B;
  huart0.Init.StopBits = UART_STOPBITS_1;
  huart0.Init.Parity = UART_PARITY_NONE;
  if (HAL_UART_Init(&huart0) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief TIM Initialization Function
  * @param None
  * @retval None
  */
static void TIM_Init(void)
{
  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};
  htim.Instance = ATIM;
  htim.Init.Prescaler = PSC_VALUE;
  htim.Init.Period = PERIOD_VALUE;
  htim.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim.Init.RepetitionCounter = 0;
  htim.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_TIM_PWM_Init(&htim) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }

  HAL_LIOINTC_Init(ATIM_LIOINTC_IRQn / 32);
  HAL_LIOINTC_Config(ATIM_LIOINTC_IRQn, LIOINTC_IRQ_TYPE_RISING);
  HAL_LIOINTC_RegisterCallback(ATIM_LIOINTC_IRQn, ATIM_LIOINTC_IRQHandler);
  HAL_LIOINTC_Enable(ATIM_LIOINTC_IRQn);
}

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  __disable_irq();
  while (1)
  {
  }
}
#ifdef USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
}
#endif /* USE_FULL_ASSERT */
