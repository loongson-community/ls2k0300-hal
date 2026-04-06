/**
  ******************************************************************************
  * @file    ls2k03xx_hal_conf.h
  * @author  MCD Application Team (Original STM32 HAL)
  * @author  Ilikara <3435193369@qq.com> (Ported for LS2K03xx)
  * @brief   HAL configuration file.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2017 STMicroelectronics.
  * Copyright (c) 2026 Ilikara <3435193369@qq.com>
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  * @note
  * This file is based on STM32 HAL library, ported and modified for 
  * Loongson LS2K03xx series processors.
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __LS2K03xx_HAL_CONF_H
#define __LS2K03xx_HAL_CONF_H

#ifdef __cplusplus
extern "C" {
#endif

#ifndef __ASSEMBLY__
/* Exported types ------------------------------------------------------------*/
#endif /* __ASSEMBLY__ */
/* Exported constants --------------------------------------------------------*/

/* ########################## Module Selection ############################## */
/**
  * @brief This is the list of modules to be used in the HAL driver
  */
#define HAL_MODULE_ENABLED
// #define HAL_ADC_MODULE_ENABLED
#define HAL_DMA_MODULE_ENABLED
// #define HAL_I2C_MODULE_ENABLED
#define HAL_LIOINTC_MODULE_ENABLED
#define HAL_GPIO_MODULE_ENABLED
// #define HAL_SPI_FLASH_MODULE_ENABLED
// #define HAL_SPI_IO_MODULE_ENABLED
#define HAL_TIM_MODULE_ENABLED
#define HAL_UART_MODULE_ENABLED

/**
  * @brief APB value.
  */
#if !defined  (APB_FREQ)
#define APB_FREQ              200000000ULL  /*!< Value in Hz */
#endif /* APB_FREQ */

/* ########################### System Configuration ######################### */
/**
  * @brief This is the HAL system configuration section
  */
#define  USE_RTOS                     0U

#define  USE_HAL_ADC_REGISTER_CALLBACKS         0U /* ADC register callback disabled       */
#define  USE_HAL_I2C_REGISTER_CALLBACKS         0U /* I2C register callback disabled       */
#define  USE_HAL_SPI_FLASH_REGISTER_CALLBACKS   0U /* SPI-Flash register callback disabled */
#define  USE_HAL_SPI_IO_REGISTER_CALLBACKS      0U /* SPI-IO register callback disabled    */
#define  USE_HAL_TIM_REGISTER_CALLBACKS         0U /* TIM register callback disabled       */
#define  USE_HAL_UART_REGISTER_CALLBACKS        0U /* UART register callback disabled      */

/* ########################## Assert Selection ############################## */
/**
  * @brief Uncomment the line below to expanse the "assert_param" macro in the
  *        HAL drivers code
  */
/* #define USE_FULL_ASSERT    1U */

#ifndef __ASSEMBLY__
/* Includes ------------------------------------------------------------------*/
/**
  * @brief Include module's header file
  */

#ifdef HAL_DMA_MODULE_ENABLED
#include "ls2k03xx_hal_dma.h"
#endif /* HAL_DMA_MODULE_ENABLED */

#ifdef HAL_ADC_MODULE_ENABLED
#include "ls2k03xx_hal_adc.h"
#endif /* HAL_ADC_MODULE_ENABLED */

#ifdef HAL_I2C_MODULE_ENABLED
#include "ls2k03xx_hal_i2c.h"
#endif /* HAL_I2C_MODULE_ENABLED */

#ifdef HAL_LIOINTC_MODULE_ENABLED
#include "ls2k03xx_hal_liointc.h"
#endif /* HAL_LIOINTC_MODULE_ENABLED */

#ifdef HAL_GPIO_MODULE_ENABLED
#include "ls2k03xx_hal_gpio.h"
#endif /* HAL_GPIO_MODULE_ENABLED */

#ifdef HAL_SPI_FLASH_MODULE_ENABLED
#include "ls2k03xx_hal_spi_flash.h"
#endif /* HAL_SPI_FLASH_MODULE_ENABLED */

#ifdef HAL_SPI_IO_MODULE_ENABLED
#include "ls2k03xx_hal_spi_io.h"
#endif /* HAL_SPI_IO_MODULE_ENABLED */

#ifdef HAL_TIM_MODULE_ENABLED
#include "ls2k03xx_hal_tim.h"
#endif /* HAL_TIM_MODULE_ENABLED */

#ifdef HAL_UART_MODULE_ENABLED
#include "ls2k03xx_hal_uart.h"
#endif /* HAL_UART_MODULE_ENABLED */

/* Exported macro ------------------------------------------------------------*/
#ifdef  USE_FULL_ASSERT
/**
  * @brief  The assert_param macro is used for function's parameters check.
  * @param  expr If expr is false, it calls assert_failed function
  *         which reports the name of the source file and the source
  *         line number of the call that failed.
  *         If expr is true, it returns no value.
  * @retval None
  */
#define assert_param(expr) ((expr) ? (void)0U : assert_failed((uint8_t *)__FILE__, __LINE__))
/* Exported functions ------------------------------------------------------- */
void assert_failed(uint8_t* file, uint32_t line);
#else
#define assert_param(expr) ((void)0U)
#endif /* USE_FULL_ASSERT */

#endif /* __ASSEMBLY__ */

#ifdef __cplusplus
}
#endif

#endif /* __LS2K03xx_HAL_CONF_H */
