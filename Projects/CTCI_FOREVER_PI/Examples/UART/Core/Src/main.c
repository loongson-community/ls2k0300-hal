/**
  ******************************************************************************
  * @file    GPIO/Core/Src/main.c
  * @author  MCD Application Team
  * @brief   This sample code shows how to use LS2K03xx TIM HAL API to generate
  *          4 signals in PWM.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2016 STMicroelectronics.
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
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
static GPIO_InitTypeDef GPIO_InitStruct;
/* UART handler declaration */
static UART_HandleTypeDef UartHandle;
char uartBuffer[4];

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
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
  GPIO_InitStruct.Pin = 40;
  HAL_GPIO_Init(&GPIO_InitStruct);

  GPIO_InitStruct.Mode = GPIO_MODE_AF_M;
  GPIO_InitStruct.Pin = 41;
  HAL_GPIO_Init(&GPIO_InitStruct);

  UartHandle.Instance = UART0;

  UartHandle.Init.BaudRate   = 115200;
  UartHandle.Init.WordLength = UART_WORDLENGTH_8B;
  UartHandle.Init.StopBits   = UART_STOPBITS_1;
  UartHandle.Init.Parity     = UART_PARITY_NONE;

  GPIO_InitStruct.Dir = GPIO_DIR_OUTPUT;
  GPIO_InitStruct.Mode = GPIO_MODE_GPIO;
  GPIO_InitStruct.Pin = 83;
  HAL_GPIO_Init(&GPIO_InitStruct);

  if (HAL_UART_Init(&UartHandle) != HAL_OK)
  {
    /* Initialization Error */
    Error_Handler();
  }

  while (1)
  {
    HAL_UART_Receive(&UartHandle, uartBuffer, 4, -1);
    HAL_UART_Transmit(&UartHandle, uartBuffer, 4, -1);
  }

}

/**
  * @brief  This function is executed in case of error occurrence.
  * @param  None
  * @retval None
  */
static void Error_Handler(void)
{
  HAL_UART_Transmit(&UartHandle, "QAQ!\n", 5, -1);
  while (1)
  {
  }
}

/**
  * @brief  System Clock Configuration
  *         The system Clock is configured as follow : 
  *            System Clock source            = PLL (HSE)
  *            SYSCLK(Hz)                     = 72000000
  *            HCLK(Hz)                       = 72000000
  *            AHB Prescaler                  = 1
  *            APB1 Prescaler                 = 2
  *            APB2 Prescaler                 = 1
  *            HSE Frequency(Hz)              = 8000000
  *            HSE PREDIV1                    = 1
  *            PLLMUL                         = 9
  *            Flash Latency(WS)              = 2
  * @param  None
  * @retval None
  */
void SystemClock_Config(void)
{
}


#ifdef  USE_FULL_ASSERT

/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

  /* Infinite loop */
  while (1)
  {
  }
}

#endif

/**
  * @}
  */

/**
  * @}
  */
