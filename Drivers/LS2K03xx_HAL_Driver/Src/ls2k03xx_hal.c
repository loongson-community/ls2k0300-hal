/**
  ******************************************************************************
  * @file    ls2k03xx_hal.c
  * @author  MCD Application Team (Original STM32 HAL)
  * @author  Ilikara <3435193369@qq.com> (Ported for LS2K03xx)
  * @brief   HAL module driver.
  *          This is the common part of the HAL initialization
  *
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
  * @note
  * This file is based on STM32 HAL library, ported and modified for 
  * Loongson LS2K03xx series processors.
  *
  ******************************************************************************
  @verbatim
  ==============================================================================
                     ##### How to use this driver #####
  ==============================================================================
    [..]
    The common HAL driver contains a set of generic and common APIs that can be
    used by the PPP peripheral drivers and the user to start using the HAL.
    [..]
    The HAL contains two APIs' categories:
         (+) Common HAL APIs
         (+) Services HAL APIs

  @endverbatim
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "ls2k03xx_hal.h"

/** @addtogroup LS2K03xx_HAL_Driver
  * @{
  */

/** @defgroup HAL HAL
  * @brief HAL module driver.
  * @{
  */

#ifdef HAL_MODULE_ENABLED

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/

/** @defgroup HAL_Private_Constants HAL Private Constants
  * @{
  */
/**
 * @brief LS2K03xx HAL Driver version number
   */
#define __LS2K03xx_HAL_VERSION_MAIN   (0x00U) /*!< [31:24] main version */
#define __LS2K03xx_HAL_VERSION_SUB1   (0x00U) /*!< [23:16] sub1 version */
#define __LS2K03xx_HAL_VERSION_SUB2   (0x00U) /*!< [15:8]  sub2 version */
#define __LS2K03xx_HAL_VERSION_RC     (0x00U) /*!< [7:0]  release candidate */
#define __LS2K03xx_HAL_VERSION         ((__LS2K03xx_HAL_VERSION_MAIN << 24)\
                                        |(__LS2K03xx_HAL_VERSION_SUB1 << 16)\
                                        |(__LS2K03xx_HAL_VERSION_SUB2 << 8 )\
                                        |(__LS2K03xx_HAL_VERSION_RC))

/**
  * @}
  */

/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/

/** @defgroup HAL_Private_Variables HAL Private Variables
  * @{
  */
#define uwTickFreq 120000000ull
/**
  * @}
  */
/* Private function prototypes -----------------------------------------------*/
/* Exported functions ---------------------------------------------------------*/

/** @defgroup HAL_Exported_Functions HAL Exported Functions
  * @{
  */

/** @defgroup HAL_Exported_Functions_Group1 Initialization and de-initialization Functions
 *  @brief    Initialization and de-initialization functions
 *
@verbatim
 ===============================================================================
              ##### Initialization and de-initialization functions #####
 ===============================================================================
   [..]  This section provides functions allowing to:
      (+) Initializes the Flash interface, the NVIC allocation and initial clock
          configuration. It initializes the systick also when timeout is needed
          and the backup domain when enabled.
      (+) de-Initializes common part of the HAL.
@endverbatim
  * @{
  */

/**
  * @brief  This function is used to initialize the HAL Library; it must be the first
  *         instruction to be executed in the main program (before to call any other
  *         HAL function), it performs the following:
  *           Calls the HAL_MspInit() callback function defined in user file
  *           "ls2k03xx_hal_msp.c" to do the global low level hardware initialization
  *
  * @note   
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_Init(void)
{
  /* Init the low level hardware */
  HAL_MspInit();

  /* Return function status */
  return HAL_OK;
}

/**
  * @brief This function de-Initializes common part of the HAL.
  * @note This function is optional.
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_DeInit(void)
{
  /* De-Init the low level hardware */
  HAL_MspDeInit();

  /* Return function status */
  return HAL_OK;
}

/**
  * @brief  Initialize the MSP.
  * @retval None
  */
__weak void HAL_MspInit(void)
{
  /* NOTE : This function should not be modified, when the callback is needed,
            the HAL_MspInit could be implemented in the user file
   */
}

/**
  * @brief  DeInitializes the MSP.
  * @retval None
  */
__weak void HAL_MspDeInit(void)
{
  /* NOTE : This function should not be modified, when the callback is needed,
            the HAL_MspDeInit could be implemented in the user file
   */
}

/**
  * @}
  */

/** @defgroup HAL_Exported_Functions_Group2 HAL Control functions
  *  @brief    HAL Control functions
  *
@verbatim
 ===============================================================================
                      ##### HAL Control functions #####
 ===============================================================================
    [..]  This section provides functions allowing to:
      (+) Provide a tick value
      (+) Provide a blocking delay in millisecond
      (+) Get the HAL API driver version

@endverbatim
  * @{
  */


static inline uint64_t drdtime(void)
{
	uint64_t val = 0;

	__asm__ __volatile__(
		"rdtime.d %0, $zero\n\t"
		: "=r"(val)
		:
		);
	return val;
}

/**
  * @brief Provides a tick value.
  * @note  This function is declared as __weak to be overwritten in case of other
  *       implementations in user file.
  * @retval tick value
  */
__weak uint32_t HAL_GetTick(void)
{
  return drdtime() / (uwTickFreq / 1000);
}

void __delay(uint64_t cycles)
{
	uint64_t t0 = drdtime();

	while ((uint64_t)(drdtime() - t0) < cycles)
  {
	}
}

void __mdelay(uint64_t ms)
{
	__delay((ms * 0x00418937ull * uwTickFreq) >> 32);
}

void __udelay(uint64_t us)
{
	__delay((us * 0x000010c7ull * uwTickFreq) >> 32);
}

void __ndelay(uint64_t ns)
{
	__delay((ns * 0x00000005ull * uwTickFreq) >> 32);
}

/**
  * @brief This function provides minimum delay (in milliseconds) based
  *        on variable incremented.
  * @note In the default implementation , SysTick timer is the source of time base.
  *       It is used to generate interrupts at regular time intervals where uwTick
  *       is incremented.
  * @note This function is declared as __weak to be overwritten in case of other
  *       implementations in user file.
  * @param Delay specifies the delay time length, in milliseconds.
  * @retval None
  */
__weak void HAL_Delay(uint32_t Delay)
{
  __mdelay(Delay);
}

/**
  * @brief  Returns the HAL revision
  * @retval version 0xXYZR (8bits for each decimal, R for RC)
  */
uint32_t HAL_GetHalVersion(void)
{
  return __LS2K03xx_HAL_VERSION;
}

/**
  * @}
  */

/**
  * @}
  */

#endif /* HAL_MODULE_ENABLED */
/**
  * @}
  */

/**
  * @}
  */
