/**
  ******************************************************************************
  * @file    ls2k03xx_hal_liointc.c
  * @author  Ilikara <3435193369@qq.com>
  * @brief   LIOINTC HAL module driver.
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
  * @note
  * API naming and module structure inspired by STM32 HAL for ecosystem 
  * compatibility. Register definitions, bit mappings, and implementation 
  * are original work derived from Loongson LS2K0300 Reference Manual.
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "ls2k03xx_hal.h"
#include "ls2k03xx_hal_def.h"
#include <string.h>

/** @addtogroup LS2K03xx_HAL_Driver
  * @{
  */

/** @defgroup LIOINTC LIOINTC
  * @brief LIOINTC HAL module driver
  * @{
  */

#ifdef HAL_LIOINTC_MODULE_ENABLED

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
LIOINTC_HandleTypeDef LIOINTC_Handle[2][32] =
{
  [0 ... 1][0 ... 31] = NULL
};
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/
/* Exported functions --------------------------------------------------------*/

__attribute((used)) void HAL_LIOINTC_IRQHandler(uint32_t liointc_group)
{
  uint32_t pending = LIOINTC_COREISR[liointc_group]->CORE_INTISR;
  int bit;

  while (pending) {
    bit = __builtin_ctzl(pending);

    if(LIOINTC_Handle[liointc_group][bit])
    {
      LIOINTC_Handle[liointc_group][bit]();
    }
    pending &= ~(1UL << bit);
  }
}

HAL_StatusTypeDef HAL_LIOINTC_RegisterCallback(LIOINTC_IRQn_Type irqn, LIOINTC_HandleTypeDef callback)
{
  if (irqn < 64 && irqn >= 0)
  {
    LIOINTC_Handle[irqn / 32][irqn % 32] = callback;
    return HAL_OK;
  }
  return HAL_ERROR;
}

HAL_StatusTypeDef HAL_LIOINTC_Enable(LIOINTC_IRQn_Type irqn)
{
  LIOINTC[irqn / 32]->ENSET = (1UL << (irqn % 32));
  return HAL_OK;
}

HAL_StatusTypeDef HAL_LIOINTC_Disable(LIOINTC_IRQn_Type irqn)
{
  LIOINTC[irqn / 32]->ENCLR = (1UL << (irqn % 32));
  return HAL_OK;
}

HAL_StatusTypeDef HAL_LIOINTC_Config(LIOINTC_IRQn_Type irqn, LIOINTC_IRQ_Type type)
{
  switch (type) {
  case LIOINTC_IRQ_TYPE_HIGH:
    LIOINTC[irqn / 32]->EDGE = (LIOINTC[irqn / 32]->EDGE & ~(1UL << (irqn % 32)));
    LIOINTC[irqn / 32]->POL = (LIOINTC[irqn / 32]->POL & ~(1UL << (irqn % 32)));
    break;
  case LIOINTC_IRQ_TYPE_LOW:
    LIOINTC[irqn / 32]->EDGE = (LIOINTC[irqn / 32]->EDGE & ~(1UL << (irqn % 32)));
    LIOINTC[irqn / 32]->POL = (LIOINTC[irqn / 32]->POL | (1UL << (irqn % 32)));
    break;
  case LIOINTC_IRQ_TYPE_RISING:
    LIOINTC[irqn / 32]->EDGE = (LIOINTC[irqn / 32]->EDGE | (1UL << (irqn % 32)));
    LIOINTC[irqn / 32]->POL = (LIOINTC[irqn / 32]->POL & ~(1UL << (irqn % 32)));
    break;
  case LIOINTC_IRQ_TYPE_FALLING:
    LIOINTC[irqn / 32]->EDGE = (LIOINTC[irqn / 32]->EDGE | (1UL << (irqn % 32)));
    LIOINTC[irqn / 32]->POL = (LIOINTC[irqn / 32]->POL | (1UL << (irqn % 32)));
    break;
  default:
    return HAL_ERROR;
  }
  return HAL_OK;
}

HAL_StatusTypeDef HAL_LIOINTC_Init(uint32_t liointc_group)
{
  if (liointc_group > 1)
  {
    return HAL_ERROR;
  }
  LIOINTC[liointc_group]->ENCLR = 0xFFFFFFFF; // Disable all interrupts
  LIOINTC[liointc_group]->POL = 0; // Default to same polarity for all interrupts
  LIOINTC[liointc_group]->EDGE = 0; // Default to level-triggered
  // Default route liointc0->HWI0 liointc1->HWI1
  memset((void *)LIOINTC[liointc_group]->ENTRY, (1 << (liointc_group + 4)), 32);
  return HAL_OK;
}

#endif /* HAL_LIOINTC_MODULE_ENABLED */
/**
  * @}
  */

/**
  * @}
  */
