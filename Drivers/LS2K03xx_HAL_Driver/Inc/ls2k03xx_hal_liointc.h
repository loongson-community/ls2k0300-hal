/**
  ******************************************************************************
  * @file    ls2k03xx_hal_liointc.h
  * @author  Ilikara <3435193369@qq.com>
  * @brief   Header file of LIOINTC HAL module.
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef LS2K03xx_HAL_LIOINTC_H
#define LS2K03xx_HAL_LIOINTC_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "ls2k03xx_hal_def.h"

/** @addtogroup LS2K03xx_HAL_Driver
  * @{
  */

/** @addtogroup LIOINTC
  * @{
  */

/* Exported types ------------------------------------------------------------*/
typedef	void (*LIOINTC_HandleTypeDef)(void);
/* Exported constants --------------------------------------------------------*/
typedef enum
{
  LIOINTC_IRQ_TYPE_HIGH,
  LIOINTC_IRQ_TYPE_LOW,
  LIOINTC_IRQ_TYPE_RISING,
  LIOINTC_IRQ_TYPE_FALLING,
} LIOINTC_IRQ_Type;
/* Exported macro ------------------------------------------------------------*/
/* Exported functions --------------------------------------------------------*/
void HAL_LIOINTC_IRQHandler(uint32_t liointc_group);
HAL_StatusTypeDef HAL_LIOINTC_RegisterCallback(LIOINTC_IRQn_Type irqn, LIOINTC_HandleTypeDef callback);
HAL_StatusTypeDef HAL_LIOINTC_Enable(LIOINTC_IRQn_Type irqn);
HAL_StatusTypeDef HAL_LIOINTC_Disable(LIOINTC_IRQn_Type irqn);
HAL_StatusTypeDef HAL_LIOINTC_Config(LIOINTC_IRQn_Type irqn, LIOINTC_IRQ_Type type);
HAL_StatusTypeDef HAL_LIOINTC_Init(uint32_t liointc_group);
/* Private types -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private constants ---------------------------------------------------------*/
/* Private macros ------------------------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/**
  * @}
  */

/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* LS2K03xx_HAL_LIOINTC_H */
