/**
  ******************************************************************************
  * @file    ls2k03xx_hal_spi_flash.h
  * @author  Ilikara <3435193369@qq.com>
  * @brief   Header file of SPI-Flash HAL module.
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
#ifndef LS2K03XX_HAL_SPI_FLASH_H
#define LS2K03XX_HAL_SPI_FLASH_H

#include <stdint.h>
#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "ls2k03xx_hal_def.h"

/** @addtogroup LS2K03XX_HAL_Driver
  * @{
  */

/** @addtogroup SPI
  * @{
  */

/* Exported types ------------------------------------------------------------*/
/** @defgroup SPI_Exported_Types SPI Exported Types
  * @{
  */

/**
  * @brief  SPI Configuration Structure definition
  */
typedef struct
{
  uint8_t CLKPolarity;         /*!< Specifies the serial clock steady state.
                                     This parameter can be a value of @ref SPI_Clock_Polarity */

  uint8_t CLKPhase;            /*!< Specifies the clock active edge for the bit capture.
                                     This parameter can be a value of @ref SPI_Clock_Phase */

  uint8_t NSS;                 /*!< Specifies whether the NSS signal is managed by
                                     hardware (NSS pin) or by software using the SSI bit.
                                     This parameter can be a value of @ref SPI_Slave_Select_management */

  uint8_t BaudRatePrescaler;   /*!< Specifies the Baud Rate prescaler value which will be
                                     used to configure the transmit and receive SCK clock.
                                     This parameter can be a value of @ref SPI_BaudRate_Prescaler
                                     @note The communication clock is derived from the master
                                     clock. The slave clock does not need to be set. */
} SPI_FLASH_InitTypeDef;

/**
  * @brief  HAL SPI State structure definition
  */
typedef enum
{
  HAL_SPI_FLASH_STATE_RESET      = 0x00U,    /*!< Peripheral not Initialized                         */
  HAL_SPI_FLASH_STATE_READY      = 0x01U,    /*!< Peripheral Initialized and ready for use           */
  HAL_SPI_FLASH_STATE_BUSY       = 0x02U,    /*!< an internal process is ongoing                     */
  HAL_SPI_FLASH_STATE_BUSY_TX    = 0x03U,    /*!< Data Transmission process is ongoing               */
  HAL_SPI_FLASH_STATE_BUSY_RX    = 0x04U,    /*!< Data Reception process is ongoing                  */
  HAL_SPI_FLASH_STATE_BUSY_TX_RX = 0x05U,    /*!< Data Transmission and Reception process is ongoing */
  HAL_SPI_FLASH_STATE_ERROR      = 0x06U,    /*!< SPI error state                                    */
  HAL_SPI_FLASH_STATE_ABORT      = 0x07U     /*!< SPI abort is ongoing                               */
} HAL_SPI_FLASH_StateTypeDef;

/**
  * @brief  SPI handle Structure definition
  */
typedef struct __SPI_FLASH_HandleTypeDef
{
  SPI_FLASH_TypeDef           *Instance;      /*!< SPI registers base address               */

  SPI_FLASH_InitTypeDef       Init;           /*!< SPI communication parameters             */

  const uint8_t               *pTxBuffPtr;    /*!< Pointer to SPI Tx transfer Buffer        */

  uint16_t                    TxXferSize;     /*!< SPI Tx Transfer size                     */

  __IO uint16_t               TxXferCount;    /*!< SPI Tx Transfer Counter                  */

  uint8_t                     *pRxBuffPtr;    /*!< Pointer to SPI Rx transfer Buffer        */

  uint16_t                    RxXferSize;     /*!< SPI Rx Transfer size                     */

  __IO uint16_t               RxXferCount;    /*!< SPI Rx Transfer Counter                  */

  HAL_LockTypeDef            Lock;           /*!< Locking object                           */

  __IO HAL_SPI_FLASH_StateTypeDef  State;          /*!< SPI communication state                  */

  __IO uint32_t              ErrorCode;      /*!< SPI Error code                           */
} SPI_FLASH_HandleTypeDef;
/**
  * @}
  */

/* Exported constants --------------------------------------------------------*/
/** @defgroup SPI_Exported_Constants SPI Exported Constants
  * @{
  */

/** @defgroup SPI_Error_Code SPI Error Code
  * @{
  */
#define HAL_SPI_FLASH_ERROR_NONE              (0x00000000U)   /*!< No error                               */
#define HAL_SPI_FLASH_ERROR_DMA               (0x00000010U)   /*!< DMA transfer error                     */
#define HAL_SPI_FLASH_ERROR_FLAG              (0x00000020U)   /*!< Error on RXNE/TXE/BSY Flag             */
#define HAL_SPI_FLASH_ERROR_ABORT             (0x00000040U)   /*!< Error during SPI Abort procedure       */
#if (USE_HAL_SPI_FLASH_REGISTER_CALLBACKS == 1U)
#define HAL_SPI_FLASH_ERROR_INVALID_CALLBACK  (0x00000080U)   /*!< Invalid Callback error                 */
#endif /* USE_HAL_SPI_FLASH_REGISTER_CALLBACKS */
/**
  * @}
  */

/** @defgroup SPI_Clock_Polarity SPI Clock Polarity
  * @{
  */
#define SPI_FLASH_POLARITY_LOW                (0x00)
#define SPI_FLASH_POLARITY_HIGH               SPI_FLASH_SPCR_CPOL
/**
  * @}
  */

/** @defgroup SPI_Clock_Phase SPI Clock Phase
  * @{
  */
#define SPI_FLASH_PHASE_1EDGE                 (0x00)
#define SPI_FLASH_PHASE_2EDGE                 SPI_FLASH_SPCR_CPHA
/**
  * @}
  */

/** @defgroup SPI_Slave_Select_management SPI Slave Select Management
  * @{
  */
#define SPI_FLASH_NSS_SOFT                SPI_FLASH_SFC_SOFTCS_CSEN
#define SPI_FLASH_NSS_HARD                (0x00)
/**
  * @}
  */

/** @defgroup SPI_BaudRate_Prescaler SPI BaudRate Prescaler
  * @{
  */
#define SPI_FLASH_BAUDRATEPRESCALER_2     (0x0)
#define SPI_FLASH_BAUDRATEPRESCALER_4     (0x1)
#define SPI_FLASH_BAUDRATEPRESCALER_16    (0x2)
#define SPI_FLASH_BAUDRATEPRESCALER_32    (0x3)
#define SPI_FLASH_BAUDRATEPRESCALER_8     (0x4)
#define SPI_FLASH_BAUDRATEPRESCALER_64    (0x5)
#define SPI_FLASH_BAUDRATEPRESCALER_128   (0x6)
#define SPI_FLASH_BAUDRATEPRESCALER_256   (0x7)
#define SPI_FLASH_BAUDRATEPRESCALER_512   (0x8)
#define SPI_FLASH_BAUDRATEPRESCALER_1024  (0x9)
#define SPI_FLASH_BAUDRATEPRESCALER_2048  (0xA)
#define SPI_FLASH_BAUDRATEPRESCALER_4096  (0xB)
/**
  * @}
  */

/** @defgroup SPI_Interrupt_definition SPI Interrupt Definition
  * @{
  */
#define SPI_FLASH_IT_SPIE                 SPI_FLASH_SPCR_SPIE
/**
  * @}
  */

/** @defgroup SPI_Flags_definition SPI Flags Definition
  * @{
  */
#define SPI_FLASH_FLAG_SPIF                   SPI_FLASH_SPSR_SPIF
#define SPI_FLASH_FLAG_WCOL                   SPI_FLASH_SPSR_WCOL
#define SPI_FLASH_FLAG_WFFULL                 SPI_FLASH_SPSR_WFFULL
#define SPI_FLASH_FLAG_WFEMPTY                SPI_FLASH_SPSR_WFEMPTY
#define SPI_FLASH_FLAG_RFFULL                 SPI_FLASH_SPSR_RFFULL
#define SPI_FLASH_FLAG_RFEMPTY                SPI_FLASH_SPSR_RFEMPTY
#define SPI_FLASH_FLAG_MASK                   (SPI_FLASH_SPSR_SPIF | SPI_FLASH_SPSR_WCOL | SPI_FLASH_SPSR_WFFULL\
                                               | SPI_FLASH_SPSR_WFEMPTY | SPI_FLASH_SPSR_RFFULL | SPI_FLASH_SPSR_RFEMPTY)
/**
  * @}
  */

/**
  * @}
  */

/* Exported macros -----------------------------------------------------------*/
/** @defgroup SPI_Exported_Macros SPI Exported Macros
  * @{
  */

/** @brief  Enable the specified SPI interrupts.
  * @param  __HANDLE__ specifies the SPI Handle.
  *         This parameter can be SPI where x: 0 or 1 to select the SPI peripheral.
  * @param  None
  * @retval None
  */
#define __HAL_SPI_FLASH_ENABLE_IT(__HANDLE__)   SET_BIT((__HANDLE__)->Instance->SPCR, (SPI_FLASH_SPCR_SPIE))

/** @brief  Disable the specified SPI interrupts.
  * @param  __HANDLE__ specifies the SPI handle.
  *         This parameter can be SPIx where x: 1, 2, or 3 to select the SPI peripheral.
  * @param  None
  * @retval None
  */
#define __HAL_SPI_FLASH_DISABLE_IT(__HANDLE__)  CLEAR_BIT((__HANDLE__)->Instance->SPCR, (SPI_FLASH_SPCR_SPIE))

/** @brief  Check whether the specified SPI flag is set or not.
  * @param  __HANDLE__ specifies the SPI Handle.
  *         This parameter can be SPI where x: 0 or 1 to select the SPI peripheral.
  * @param  __FLAG__ specifies the flag to check.
  *         This parameter can be one of the following values:
  *            @arg SPI_FLASH_FLAG_SPIF
  *            @arg SPI_FLASH_FLAG_WCOL
  *            @arg SPI_FLASH_FLAG_WFFULL
  *            @arg SPI_FLASH_FLAG_WFEMPTY
  *            @arg SPI_FLASH_FLAG_RFFULL
  *            @arg SPI_FLASH_FLAG_RFEMPTY
  * @retval The new state of __FLAG__ (TRUE or FALSE).
  */
#define __HAL_SPI_FLASH_GET_FLAG(__HANDLE__, __FLAG__) ((((__HANDLE__)->Instance->SPSR) & (__FLAG__)) == (__FLAG__))

/** @brief  Enable the SPI peripheral.
  * @param  __HANDLE__ specifies the SPI Handle.
  *         This parameter can be SPI where x: 0 or 1 to select the SPI peripheral.
  * @retval None
  */
#define __HAL_SPI_FLASH_ENABLE(__HANDLE__)  SET_BIT((__HANDLE__)->Instance->SPCR, SPI_FLASH_SPCR_SPE)

/** @brief  Disable the SPI peripheral.
  * @param  __HANDLE__ specifies the SPI Handle.
  *         This parameter can be SPI where x: 0 or 1 to select the SPI peripheral.
  * @retval None
  */
#define __HAL_SPI_FLASH_DISABLE(__HANDLE__) CLEAR_BIT((__HANDLE__)->Instance->SPCR, SPI_FLASH_SPCR_SPE)

/**
  * @}
  */

/* Private constants ---------------------------------------------------------*/
/* Private macros ------------------------------------------------------------*/
/** @defgroup SPI_Private_Macros SPI Private Macros
  * @{
  */
/** @brief  Check whether the specified SPI flag is set or not.
  * @param  __SPSR__  copy of SPI SPSR register.
  * @param  __FLAG__ specifies the flag to check.
  *         This parameter can be one of the following values:
  *            @arg SPI_FLASH_FLAG_SPIF
  *            @arg SPI_FLASH_FLAG_WCOL
  *            @arg SPI_FLASH_FLAG_WFFULL
  *            @arg SPI_FLASH_FLAG_WFEMPTY
  *            @arg SPI_FLASH_FLAG_RFFULL
  *            @arg SPI_FLASH_FLAG_RFEMPTY
  * @retval SET or RESET.
  */
#define SPI_FLASH_CHECK_FLAG(__SPSR__, __FLAG__) ((((__SPSR__) & ((__FLAG__) & SPI_FLASH_FLAG_MASK)) == \
                                             ((__FLAG__) & SPI_FLASH_FLAG_MASK)) ? SET : RESET)

/** @brief  Check whether the specified SPI Interrupt is set or not.
  * @param  __SPCR__  copy of SPI SPCR register.
  * @retval SET or RESET.
  */
#define SPI_FLASH_CHECK_IT_SOURCE(__SPCR__) ((((__SPCR__) & (SPI_FLASH_SPCR_SPIE)) == \
                                              (SPI_FLASH_SPCR_SPIE)) ? SET : RESET)

/** @brief  Checks if SPI Serial clock steady state parameter is in allowed range.
  * @param  __CPOL__ specifies the SPI serial clock steady state.
  *         This parameter can be a value of @ref SPI_Clock_Polarity
  * @retval None
  */
#define IS_SPI_FLASH_CPOL(__CPOL__)      (((__CPOL__) == SPI_FLASH_POLARITY_LOW) || \
                                          ((__CPOL__) == SPI_FLASH_POLARITY_HIGH))

/** @brief  Checks if SPI Clock Phase parameter is in allowed range.
  * @param  __CPHA__ specifies the SPI Clock Phase.
  *         This parameter can be a value of @ref SPI_Clock_Phase
  * @retval None
  */
#define IS_SPI_FLASH_CPHA(__CPHA__)      (((__CPHA__) == SPI_FLASH_PHASE_1EDGE) || \
                                          ((__CPHA__) == SPI_FLASH_PHASE_2EDGE))

/** @brief  Checks if SPI Slave Select parameter is in allowed range.
  * @param  __NSS__ specifies the SPI Slave Select management parameter.
  *         This parameter can be a value of @ref SPI_Slave_Select_management
  * @retval None
  */
#define IS_SPI_FLASH_NSS(__NSS__)        (((__NSS__) == SPI_FLASH_NSS_SOFT)       || \
                                          ((__NSS__) == SPI_FLASH_NSS_HARD))

/** @brief  Checks if SPI Baudrate prescaler parameter is in allowed range.
  * @param  __PRESCALER__ specifies the SPI Baudrate prescaler.
  *         This parameter can be a value of @ref SPI_BaudRate_Prescaler
  * @retval None
  */
#define IS_SPI_FLASH_BAUDRATE_PRESCALER(__PRESCALER__) (((__PRESCALER__) == SPI_FLASH_BAUDRATEPRESCALER_2)    || \
                                                        ((__PRESCALER__) == SPI_FLASH_BAUDRATEPRESCALER_4)    || \
                                                        ((__PRESCALER__) == SPI_FLASH_BAUDRATEPRESCALER_8)    || \
                                                        ((__PRESCALER__) == SPI_FLASH_BAUDRATEPRESCALER_16)   || \
                                                        ((__PRESCALER__) == SPI_FLASH_BAUDRATEPRESCALER_32)   || \
                                                        ((__PRESCALER__) == SPI_FLASH_BAUDRATEPRESCALER_64)   || \
                                                        ((__PRESCALER__) == SPI_FLASH_BAUDRATEPRESCALER_128)  || \
                                                        ((__PRESCALER__) == SPI_FLASH_BAUDRATEPRESCALER_256)  || \
                                                        ((__PRESCALER__) == SPI_FLASH_BAUDRATEPRESCALER_512)  || \
                                                        ((__PRESCALER__) == SPI_FLASH_BAUDRATEPRESCALER_1024) || \
                                                        ((__PRESCALER__) == SPI_FLASH_BAUDRATEPRESCALER_2048) || \
                                                        ((__PRESCALER__) == SPI_FLASH_BAUDRATEPRESCALER_4096))

/**
  * @}
  */

/* Private functions ---------------------------------------------------------*/
/* Exported functions --------------------------------------------------------*/
/** @addtogroup SPI_Exported_Functions
  * @{
  */

/** @addtogroup SPI_Exported_Functions_Group1
  * @{
  */
/* Initialization/de-initialization functions  ********************************/
HAL_StatusTypeDef HAL_SPI_FLASH_Init(SPI_FLASH_HandleTypeDef *hspi);
HAL_StatusTypeDef HAL_SPI_FLASH_DeInit(SPI_FLASH_HandleTypeDef *hspi);
void HAL_SPI_FLASH_MspInit(SPI_FLASH_HandleTypeDef *hspi);
void HAL_SPI_FLASH_MspDeInit(SPI_FLASH_HandleTypeDef *hspi);
/**
  * @}
  */

/** @addtogroup SPI_Exported_Functions_Group2
  * @{
  */
/* I/O operation functions  ***************************************************/
HAL_StatusTypeDef HAL_SPI_FLASH_Transmit(SPI_FLASH_HandleTypeDef *hspi, const uint8_t *pData, uint16_t Size, uint32_t Timeout);
HAL_StatusTypeDef HAL_SPI_FLASH_Receive(SPI_FLASH_HandleTypeDef *hspi, uint8_t *pData, uint16_t Size, uint32_t Timeout);
HAL_StatusTypeDef HAL_SPI_FLASH_TransmitReceive(SPI_FLASH_HandleTypeDef *hspi, const uint8_t *pTxData, uint8_t *pRxData,
                                          uint16_t Size, uint32_t Timeout);
/* Transfer Abort functions */
HAL_StatusTypeDef HAL_SPI_FLASH_Abort(SPI_FLASH_HandleTypeDef *hspi);
/**
  * @}
  */

/** @addtogroup SPI_Exported_Functions_Group3
  * @{
  */
/* Peripheral State and Error functions ***************************************/
HAL_SPI_FLASH_StateTypeDef HAL_SPI_FLASH_GetState(const SPI_FLASH_HandleTypeDef *hspi);
uint32_t                   HAL_SPI_FLASH_GetError(const SPI_FLASH_HandleTypeDef *hspi);
/**
  * @}
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

#endif /* LS2K03XX_HAL_SPI_FLASH_H */
