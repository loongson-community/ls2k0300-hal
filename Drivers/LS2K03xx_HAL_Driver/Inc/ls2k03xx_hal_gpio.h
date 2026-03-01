/**
  ******************************************************************************
  * @file    ls2k03xx_hal_gpio.h
  * @author  Ilikara <3435193369@qq.com>
  * @brief   Header file of GPIO HAL module.
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
#ifndef LS2K03xx_HAL_GPIO_H
#define LS2K03xx_HAL_GPIO_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "ls2k03xx_hal_def.h"

/** @addtogroup LS2K03xx_HAL_Driver
  * @{
  */

/** @addtogroup GPIO
  * @{
  */

/* Exported types ------------------------------------------------------------*/
/** @defgroup GPIO_Exported_Types GPIO Exported Types
  * @{
  */

/**
  * @brief GPIO Init structure definition
  */
typedef struct
{
  uint32_t Pin;       /*!< Specifies the GPIO pins to be configured.
                           This parameter can be any value from 0 to 106 */

  uint32_t Mode;      /*!< Specifies the operating mode for the selected pins.
                           This parameter can be a value of @ref GPIO_mode_define */
  uint32_t Dir;
} GPIO_InitTypeDef;

/**
  * @brief  GPIO Bit SET and Bit RESET enumeration
  */
typedef enum
{
  GPIO_PIN_RESET = 0u,
  GPIO_PIN_SET
} GPIO_PinState;
/**
  * @}
  */

/* Exported constants --------------------------------------------------------*/

/** @defgroup GPIO_Exported_Constants GPIO Exported Constants
  * @{
  */
/**
  * @}
  */

/** @defgroup GPIO_mode_define GPIO mode define
  * @brief GPIO Configuration Mode
  * @{
  */
typedef enum {
  GPIO_DIR_OUTPUT = 0,
  GPIO_DIR_INPUT = 1,
} GPIO_Dir;

typedef enum {
  GPIO_MODE_GPIO = 0b00,  /*!< GPIO Mode                        */
  GPIO_MODE_AF_1 = 0b01,  /*!< Alternate Function Mode 1        */
  GPIO_MODE_AF_2 = 0b10,  /*!< Alternate Function Mode 2        */
  GPIO_MODE_AF_M = 0b11,  /*!< Alternate Function Mode Master   */
} GPIO_AF;
/**
  * @}
  */

/**
  * @}
  */

/* Exported macro ------------------------------------------------------------*/
/** @defgroup GPIO_Exported_Macros GPIO Exported Macros
  * @{
  */

/* Exported functions --------------------------------------------------------*/
/** @addtogroup GPIO_Exported_Functions
  * @{
  */

/** @addtogroup GPIO_Exported_Functions_Group1
  * @{
  */
/* Initialization and de-initialization functions *****************************/
void HAL_GPIO_Init(GPIO_InitTypeDef *GPIO_Init);
void HAL_GPIO_DeInit(uint32_t GPIO_Pin);
/**
  * @}
  */

/** @addtogroup GPIO_Exported_Functions_Group2
  * @{
  */
/* IO operation functions *****************************************************/
GPIO_PinState HAL_GPIO_ReadPin(uint32_t GPIO_Pin);
void HAL_GPIO_WritePin(uint32_t GPIO_Pin, GPIO_PinState PinState);
void HAL_GPIO_TogglePin(uint32_t GPIO_Pin);
/**
  * @}
  */

/**
  * @}
  */
/* Private types -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private constants ---------------------------------------------------------*/
/** @defgroup GPIO_Private_Constants GPIO Private Constants
  * @{
  */
/**
  * @}
  */

/* Private macros ------------------------------------------------------------*/
/** @defgroup GPIO_Private_Macros GPIO Private Macros
  * @{
  */
#define IS_GPIO_PIN_ACTION(ACTION)  (((ACTION) == GPIO_PIN_RESET) || ((ACTION) == GPIO_PIN_SET))
#define IS_GPIO_PIN(PIN)            (PIN >=0 && PIN <= 106)
#define IS_GPIO_MODE(MODE)          (MODE >= 0b00 && MODE <= 0b11)
/**
  * @}
  */

/* Private functions ---------------------------------------------------------*/
/** @defgroup GPIO_Private_Functions GPIO Private Functions
  * @{
  */
/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* LS2K03xx_HAL_GPIO_H */
