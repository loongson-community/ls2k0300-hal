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

/* Private includes ----------------------------------------------------------*/
/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
UART_HandleTypeDef huart0;
uint8_t uartBuffer[4];
/* Private function prototypes -----------------------------------------------*/
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

  while (1)
  {
    HAL_UART_Receive(&huart0, uartBuffer, 1, -1);
    HAL_UART_Transmit(&huart0, uartBuffer, 1, -1);
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
