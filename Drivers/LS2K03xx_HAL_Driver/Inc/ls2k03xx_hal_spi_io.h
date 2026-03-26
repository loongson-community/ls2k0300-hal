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
#ifndef LS2K03XX_HAL_SPI_IO_H
#define LS2K03XX_HAL_SPI_IO_H

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
  uint32_t Mode;                /*!< Specifies the SPI operating mode.
                                     This parameter can be a value of @ref SPI_Mode */

  uint32_t DataSize;            /*!< Specifies the SPI data size.
                                     This parameter can be a value between 4 and 32 */

  uint32_t CLKPolarity;         /*!< Specifies the serial clock steady state.
                                     This parameter can be a value of @ref SPI_Clock_Polarity */

  uint32_t CLKPhase;            /*!< Specifies the clock active edge for the bit capture.
                                     This parameter can be a value of @ref SPI_Clock_Phase */

  uint32_t NSS;                 /*!< Specifies whether the NSS signal is managed by
                                     hardware (NSS pin) or by software using the SSI bit.
                                     This parameter can be a value of @ref SPI_Slave_Select_management */

  uint32_t BaudRate;            /*!< This member configures the UART communication baud rate. */

  uint32_t FirstBit;            /*!< Specifies whether data transfers start from MSB or LSB bit.
                                     This parameter can be a value of @ref SPI_MSB_LSB_transmission */

  uint32_t CRCCalculation;      /*!< Specifies if the CRC calculation is enabled or not.
                                     This parameter can be a value of @ref SPI_CRC_Calculation */

  uint32_t CRCPolynomial;       /*!< Specifies the polynomial used for the CRC calculation.
                                     This parameter must be an odd number between Min_Data = 1 and Max_Data = 4294967295 */
} SPI_IO_InitTypeDef;

/**
  * @brief  HAL SPI State structure definition
  */
typedef enum
{
  HAL_SPI_IO_STATE_RESET      = 0x00U,    /*!< Peripheral not Initialized                         */
  HAL_SPI_IO_STATE_READY      = 0x01U,    /*!< Peripheral Initialized and ready for use           */
  HAL_SPI_IO_STATE_BUSY       = 0x02U,    /*!< an internal process is ongoing                     */
  HAL_SPI_IO_STATE_BUSY_TX    = 0x03U,    /*!< Data Transmission process is ongoing               */
  HAL_SPI_IO_STATE_BUSY_RX    = 0x04U,    /*!< Data Reception process is ongoing                  */
  HAL_SPI_IO_STATE_BUSY_TX_RX = 0x05U,    /*!< Data Transmission and Reception process is ongoing */
  HAL_SPI_IO_STATE_ERROR      = 0x06U,    /*!< SPI error state                                    */
  HAL_SPI_IO_STATE_ABORT      = 0x07U     /*!< SPI abort is ongoing                               */
} HAL_SPI_IO_StateTypeDef;

/**
  * @brief  SPI handle Structure definition
  */
typedef struct __SPI_IO_HandleTypeDef
{
  SPI_IO_TypeDef              *Instance;      /*!< SPI registers base address               */

  SPI_IO_InitTypeDef          Init;           /*!< SPI communication parameters             */

  const uint8_t               *pTxBuffPtr;    /*!< Pointer to SPI Tx transfer Buffer        */

  uint16_t                    TxXferSize;     /*!< SPI Tx Transfer size                     */

  __IO uint16_t               TxXferCount;    /*!< SPI Tx Transfer Counter                  */

  uint8_t                     *pRxBuffPtr;    /*!< Pointer to SPI Rx transfer Buffer        */

  uint16_t                    RxXferSize;     /*!< SPI Rx Transfer size                     */

  __IO uint16_t               RxXferCount;    /*!< SPI Rx Transfer Counter                  */

  HAL_LockTypeDef             Lock;           /*!< Locking object                           */

  __IO HAL_SPI_IO_StateTypeDef  State;          /*!< SPI communication state                  */

  __IO uint32_t               ErrorCode;      /*!< SPI Error code                           */
} SPI_IO_HandleTypeDef;
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
#define HAL_SPI_IO_ERROR_NONE               (0x00000000U)   /*!< No error                               */
#define HAL_SPI_IO_ERROR_DMA                (0x00000010U)   /*!< DMA transfer error                     */
#define HAL_SPI_IO_ERROR_FLAG               (0x00000020U)   /*!< Error on RXNE/TXE/BSY Flag             */
#define HAL_SPI_IO_ERROR_ABORT              (0x00000040U)   /*!< Error during SPI Abort procedure       */
#if (USE_HAL_SPI_IO_REGISTER_CALLBACKS == 1U)
#define HAL_SPI_IO_ERROR_INVALID_CALLBACK   (0x00000080U)   /*!< Invalid Callback error                 */
#endif /* USE_HAL_SPI_IO_REGISTER_CALLBACKS */
/**
  * @}
  */

/** @defgroup SPI_Mode SPI Mode
  * @{
  */
#define SPI_IO_MODE_SLAVE                  (0x00000000U)
#define SPI_IO_MODE_MASTER                 (SPI_IO_CFG3_MSTR)
/**
  * @}
  */

/** @defgroup SPI_Clock_Polarity SPI Clock Polarity
  * @{
  */
#define SPI_IO_POLARITY_LOW                 (0x00000000U)
#define SPI_IO_POLARITY_HIGH                SPI_IO_CFG1_CPOL
/**
  * @}
  */

/** @defgroup SPI_Clock_Phase SPI Clock Phase
  * @{
  */
#define SPI_IO_PHASE_1EDGE                  (0x00000000U)
#define SPI_IO_PHASE_2EDGE                  SPI_IO_CFG1_CPHA
/**
  * @}
  */

/** @defgroup SPI_Slave_Select_management SPI Slave Select Management
  * @{
  */
#define SPI_IO_NSS_SOFT                     (0x1UL << SPI_IO_CFG3_SSMODE_POS)
#define SPI_IO_NSS_HARD                     (0x00000000U)
/**
  * @}
  */

/** @defgroup SPI_MSB_LSB_transmission SPI MSB LSB Transmission
  * @{
  */
#define SPI_IO_FIRSTBIT_MSB                 (0x00000000U)
#define SPI_IO_FIRSTBIT_LSB                 SPI_IO_CFG1_LSBFRST
/**
  * @}
  */

/** @defgroup SPI_CRC_Calculation SPI CRC Calculation
  * @{
  */
#define SPI_IO_CRCCALCULATION_DISABLE       (0x00000000U)
#define SPI_IO_CRCCALCULATION_ENABLE        SPI_IO_CRC1_CRCEN
/**
  * @}
  */

/** @defgroup SPI_Interrupt_definition SPI Interrupt Definition
  * @{
  */
#define SPI_IO_IT_EOT                       SPI_IO_IER_EOTIE
#define SPI_IO_IT_MODF                      SPI_IO_IER_MODFIE
#define SPI_IO_IT_CRCE                      SPI_IO_IER_CRCEIE
#define SPI_IO_IT_UDR                       SPI_IO_IER_UDRIE
#define SPI_IO_IT_OVR                       SPI_IO_IER_OVRIE
#define SPI_IO_IT_SUSP                      SPI_IO_IER_SUSPIE
#define SPI_IO_IT_TXE                       SPI_IO_IER_TXEIE
#define SPI_IO_IT_RXE                       SPI_IO_IER_RXEIE
#define SPI_IO_IT_DXA                       SPI_IO_IER_DXAIE
#define SPI_IO_IT_TXA                       SPI_IO_IER_TXAIE
#define SPI_IO_IT_RXA                       SPI_IO_IER_RXAIE
#define SPI_IO_IT_MASK                      (SPI_IO_IT_RXA | SPI_IO_IT_TXA | SPI_IO_IT_DXA\
                                             | SPI_IO_IT_RXE | SPI_IO_IT_TXE | SPI_IO_IT_SUSP\
                                             | SPI_IO_IT_OVR | SPI_IO_IT_UDR | SPI_IO_IT_CRCE\
                                             | SPI_IO_IT_MODF | SPI_IO_IT_EOT)
/**
  * @}
  */

/** @defgroup SPI_Flags_definition SPI Flags Definition
  * @{
  */
#define SPI_IO_FLAG_RXA                     SPI_IO_SR1_RXA
#define SPI_IO_FLAG_TXA                     SPI_IO_SR1_TXA
#define SPI_IO_FLAG_DXA                     SPI_IO_SR1_DXA
#define SPI_IO_FLAG_RXE                     SPI_IO_SR1_RXE
#define SPI_IO_FLAG_TXE                     SPI_IO_SR1_TXE
#define SPI_IO_FLAG_SUSP                    SPI_IO_SR1_SUSP
#define SPI_IO_FLAG_OVR                     SPI_IO_SR1_OVR
#define SPI_IO_FLAG_UDR                     SPI_IO_SR1_UDR
#define SPI_IO_FLAG_CRCE                    SPI_IO_SR1_CRCE
#define SPI_IO_FLAG_MODF                    SPI_IO_SR1_MODF
#define SPI_IO_FLAG_EOT                     SPI_IO_SR1_EOT
#define SPI_IO_FLAG_MASK                    (SPI_IO_FLAG_RXA | SPI_IO_FLAG_TXA | SPI_IO_FLAG_DXA\
                                             | SPI_IO_FLAG_RXE | SPI_IO_FLAG_TXE | SPI_IO_FLAG_SUSP\
                                             | SPI_IO_FLAG_OVR | SPI_IO_FLAG_UDR | SPI_IO_FLAG_CRCE\
                                             | SPI_IO_FLAG_MODF | SPI_IO_FLAG_EOT)
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
  *         This parameter can be SPI where x: 2 or 3 to select the SPI peripheral.
  * @param  __INTERRUPT__ specifies the interrupt source to enable.
  *         This parameter can be one of the following values:
  *            @arg SPI_IO_IT_EOT
  *            @arg SPI_IO_IT_MODF
  *            @arg SPI_IO_IT_CRCE
  *            @arg SPI_IO_IT_UDR
  *            @arg SPI_IO_IT_OVR
  *            @arg SPI_IO_IT_SUSP
  *            @arg SPI_IO_IT_TXE
  *            @arg SPI_IO_IT_RXE
  *            @arg SPI_IO_IT_DXA
  *            @arg SPI_IO_IT_TXA
  *            @arg SPI_IO_IT_RXA
  * @param  None
  * @retval None
  */
#define __HAL_SPI_IO_ENABLE_IT(__HANDLE__, __INTERRUPT__)   SET_BIT((__HANDLE__)->Instance->IER, (__INTERRUPT__))

/** @brief  Disable the specified SPI interrupts.
  * @param  __HANDLE__ specifies the SPI handle.
  *         This parameter can be SPIx where x: 2 or 3 to select the SPI peripheral.
  * @param  __INTERRUPT__ specifies the interrupt source to enable.
  *         This parameter can be one of the following values:
  *            @arg SPI_IO_IT_EOT
  *            @arg SPI_IO_IT_MODF
  *            @arg SPI_IO_IT_CRCE
  *            @arg SPI_IO_IT_UDR
  *            @arg SPI_IO_IT_OVR
  *            @arg SPI_IO_IT_SUSP
  *            @arg SPI_IO_IT_TXE
  *            @arg SPI_IO_IT_RXE
  *            @arg SPI_IO_IT_DXA
  *            @arg SPI_IO_IT_TXA
  *            @arg SPI_IO_IT_RXA
  * @param  None
  * @retval None
  */
#define __HAL_SPI_IO_DISABLE_IT(__HANDLE__, __INTERRUPT__)  CLEAR_BIT((__HANDLE__)->Instance->IER, (__INTERRUPT__))

/** @brief  Check whether the specified SPI interrupt source is enabled or not.
  * @param  __HANDLE__ specifies the SPI Handle.
  *         This parameter can be SPIx where x: 2 or 3 to select the SPI peripheral.
  * @param  __INTERRUPT__ specifies the SPI interrupt source to check.
  *          This parameter can be one of the following values:
  *            @arg SPI_IO_IT_EOT
  *            @arg SPI_IO_IT_MODF
  *            @arg SPI_IO_IT_CRCE
  *            @arg SPI_IO_IT_UDR
  *            @arg SPI_IO_IT_OVR
  *            @arg SPI_IO_IT_SUSP
  *            @arg SPI_IO_IT_TXE
  *            @arg SPI_IO_IT_RXE
  *            @arg SPI_IO_IT_DXA
  *            @arg SPI_IO_IT_TXA
  *            @arg SPI_IO_IT_RXA
  * @retval The new state of __IT__ (TRUE or FALSE).
  */
#define __HAL_SPI_GET_IT_SOURCE(__HANDLE__, __INTERRUPT__) ((((__HANDLE__)->Instance->IER\
                                                              & (__INTERRUPT__)) == (__INTERRUPT__)) ? SET : RESET)

/** @brief  Check whether the specified SPI flag is set or not.
  * @param  __HANDLE__ specifies the SPI Handle.
  *         This parameter can be SPI where x: 2 or 3 to select the SPI peripheral.
  * @param  __FLAG__ specifies the flag to check.
  *         This parameter can be one of the following values:
  *            @arg SPI_IO_FLAG_EOT
  *            @arg SPI_IO_FLAG_MODF
  *            @arg SPI_IO_FLAG_CRCE
  *            @arg SPI_IO_FLAG_UDR
  *            @arg SPI_IO_FLAG_OVR
  *            @arg SPI_IO_FLAG_SUSP
  *            @arg SPI_IO_FLAG_TXE
  *            @arg SPI_IO_FLAG_RXE
  *            @arg SPI_IO_FLAG_DXA
  *            @arg SPI_IO_FLAG_TXA
  *            @arg SPI_IO_FLAG_RXA
  * @retval The new state of __FLAG__ (TRUE or FALSE).
  */
#define __HAL_SPI_IO_GET_FLAG(__HANDLE__, __FLAG__) ((((__HANDLE__)->Instance->SR1) & (__FLAG__)) == (__FLAG__))

/** @brief  Enable the SPI peripheral.
  * @param  __HANDLE__ specifies the SPI Handle.
  *         This parameter can be SPI where x: 2 or 3 to select the SPI peripheral.
  * @retval None
  */
#define __HAL_SPI_IO_ENABLE(__HANDLE__)  SET_BIT((__HANDLE__)->Instance->CR1, SPI_IO_CR1_SPE)

/** @brief  Disable the SPI peripheral.
  * @param  __HANDLE__ specifies the SPI Handle.
  *         This parameter can be SPI where x: 2 or 3 to select the SPI peripheral.
  * @retval None
  */
#define __HAL_SPI_IO_DISABLE(__HANDLE__) CLEAR_BIT((__HANDLE__)->Instance->CR1, SPI_IO_CR1_SPE)

/**
  * @}
  */

/* Private constants ---------------------------------------------------------*/
/* Private macros ------------------------------------------------------------*/
/** @defgroup SPI_Private_Macros SPI Private Macros
  * @{
  */
/** @brief  Check whether the specified SPI flag is set or not.
  * @param  __SR1__  copy of SPI SR1 register.
  * @param  __FLAG__ specifies the flag to check.
  *         This parameter can be one of the following values:
  *            @arg SPI_IO_FLAG_EOT
  *            @arg SPI_IO_FLAG_MODF
  *            @arg SPI_IO_FLAG_CRCE
  *            @arg SPI_IO_FLAG_UDR
  *            @arg SPI_IO_FLAG_OVR
  *            @arg SPI_IO_FLAG_SUSP
  *            @arg SPI_IO_FLAG_TXE
  *            @arg SPI_IO_FLAG_RXE
  *            @arg SPI_IO_FLAG_DXA
  *            @arg SPI_IO_FLAG_TXA
  *            @arg SPI_IO_FLAG_RXA
  * @retval SET or RESET.
  */
#define SPI_IO_CHECK_FLAG(__SR1__, __FLAG__)  ((((__SR1__) & ((__FLAG__) & SPI_IO_FLAG_MASK)) == \
                                                ((__FLAG__) & SPI_IO_FLAG_MASK)) ? SET : RESET)

/** @brief  Check whether the specified SPI Interrupt is set or not.
  * @param  __IER__  copy of SPI IER register.
  * @param  __INTERRUPT__ specifies the SPI interrupt source to check.
  *         This parameter can be one of the following values:
  *            @arg SPI_IO_IT_EOT
  *            @arg SPI_IO_IT_MODF
  *            @arg SPI_IO_IT_CRCE
  *            @arg SPI_IO_IT_UDR
  *            @arg SPI_IO_IT_OVR
  *            @arg SPI_IO_IT_SUSP
  *            @arg SPI_IO_IT_TXE
  *            @arg SPI_IO_IT_RXE
  *            @arg SPI_IO_IT_DXA
  *            @arg SPI_IO_IT_TXA
  *            @arg SPI_IO_IT_RXA
  * @retval SET or RESET.
  */
#define SPI_IO_CHECK_IT_SOURCE(__IER__, __INTERRUPT__)  ((((__IER__) & (__INTERRUPT__)) == \
                                                          (__INTERRUPT__)) ? SET : RESET)

/** @brief  Checks if SPI Mode parameter is in allowed range.
  * @param  __MODE__ specifies the SPI Mode.
  *         This parameter can be a value of @ref SPI_Mode
  * @retval None
  */
#define IS_SPI_IO_MODE(__MODE__)      (((__MODE__) == SPI_IO_MODE_SLAVE)   || \
                                       ((__MODE__) == SPI_IO_MODE_MASTER))

/** @brief  Checks if SPI Data Size parameter is in allowed range.
  * @param  __DATASIZE__ specifies the SPI Data Size.
  *         This parameter can be a value between 4 and 32
  * @retval None
  */
#define IS_SPI_IO_DATASIZE(__DATASIZE__) (((__DATASIZE__) >= 4) && \
                                          ((__DATASIZE__) <= 32))

/** @brief  Checks if SPI Serial clock steady state parameter is in allowed range.
  * @param  __CPOL__ specifies the SPI serial clock steady state.
  *         This parameter can be a value of @ref SPI_Clock_Polarity
  * @retval None
  */
#define IS_SPI_IO_CPOL(__CPOL__)         (((__CPOL__) == SPI_IO_POLARITY_LOW) || \
                                          ((__CPOL__) == SPI_IO_POLARITY_HIGH))

/** @brief  Checks if SPI Clock Phase parameter is in allowed range.
  * @param  __CPHA__ specifies the SPI Clock Phase.
  *         This parameter can be a value of @ref SPI_Clock_Phase
  * @retval None
  */
#define IS_SPI_IO_CPHA(__CPHA__)         (((__CPHA__) == SPI_IO_PHASE_1EDGE) || \
                                          ((__CPHA__) == SPI_IO_PHASE_2EDGE))

/** @brief  Checks if SPI Slave Select parameter is in allowed range.
  * @param  __NSS__ specifies the SPI Slave Select management parameter.
  *         This parameter can be a value of @ref SPI_Slave_Select_management
  * @retval None
  */
#define IS_SPI_IO_NSS(__NSS__)           (((__NSS__) == SPI_IO_NSS_SOFT)       || \
                                          ((__NSS__) == SPI_IO_NSS_HARD))

/** @brief  Checks if SPI MSB LSB transmission parameter is in allowed range.
  * @param  __BIT__ specifies the SPI MSB LSB transmission (whether data transfer starts from MSB or LSB bit).
  *         This parameter can be a value of @ref SPI_MSB_LSB_transmission
  * @retval None
  */
#define IS_SPI_IO_FIRST_BIT(__BIT__)  (((__BIT__) == SPI_IO_FIRSTBIT_MSB) || \
                                       ((__BIT__) == SPI_IO_FIRSTBIT_LSB))

/** @brief  Checks if SPI CRC calculation enabled state is in allowed range.
  * @param  __CALCULATION__ specifies the SPI CRC calculation enable state.
  *         This parameter can be a value of @ref SPI_CRC_Calculation
  * @retval None
  */
#define IS_SPI_IO_CRC_CALCULATION(__CALCULATION__)  (((__CALCULATION__) == SPI_IO_CRCCALCULATION_DISABLE) || \
                                                     ((__CALCULATION__) == SPI_IO_CRCCALCULATION_ENABLE))

/** @brief  Checks if SPI polynomial value to be used for the CRC calculation, is in allowed range.
  * @param  __POLYNOMIAL__ specifies the SPI polynomial value to be used for the CRC calculation.
  *         This parameter must be a number between Min_Data = 0 and Max_Data = 4294967295
  * @retval None
  */
#define IS_SPI_IO_CRC_POLYNOMIAL(__POLYNOMIAL__)  (((__POLYNOMIAL__) >= 0x1U)    && \
                                                   ((__POLYNOMIAL__) <= 0xFFFFFFFFU) && \
                                                   (((__POLYNOMIAL__)&0x1U) != 0U))

#define IS_SPI_IO_BAUDRATE(BAUDRATE) ((BAUDRATE) <= ((SPI_IO_REF_CLK) / 2))

#define SPI_IO_REF_CLK (APB_FREQ)

/* SPI IO Divisor Calculation
 * Result: 14-bit divisor split into Integer(8bit) + Decimal(6bit) + Unused(2bit)
 */
#define SPI_IO_DIV_VALUE(_BAUD_)  ((((SPI_IO_REF_CLK) << 8) + ((_BAUD_) / 2)) / (_BAUD_))

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
HAL_StatusTypeDef HAL_SPI_IO_Init(SPI_IO_HandleTypeDef *hspi);
HAL_StatusTypeDef HAL_SPI_IO_DeInit(SPI_IO_HandleTypeDef *hspi);
void HAL_SPI_IO_MspInit(SPI_IO_HandleTypeDef *hspi);
void HAL_SPI_IO_MspDeInit(SPI_IO_HandleTypeDef *hspi);
/**
  * @}
  */

/** @addtogroup SPI_Exported_Functions_Group2
  * @{
  */
/* I/O operation functions  ***************************************************/
HAL_StatusTypeDef HAL_SPI_IO_Transmit(SPI_IO_HandleTypeDef *hspi, const uint8_t *pData, uint16_t Size, uint32_t Timeout);
HAL_StatusTypeDef HAL_SPI_IO_Receive(SPI_IO_HandleTypeDef *hspi, uint8_t *pData, uint16_t Size, uint32_t Timeout);
HAL_StatusTypeDef HAL_SPI_IO_TransmitReceive(SPI_IO_HandleTypeDef *hspi, const uint8_t *pTxData, uint8_t *pRxData,
                                          uint16_t Size, uint32_t Timeout);
/* Transfer Abort functions */
HAL_StatusTypeDef HAL_SPI_IO_Abort(SPI_IO_HandleTypeDef *hspi);
/**
  * @}
  */

/** @addtogroup SPI_Exported_Functions_Group3
  * @{
  */
/* Peripheral State and Error functions ***************************************/
HAL_SPI_IO_StateTypeDef HAL_SPI_IO_GetState(const SPI_IO_HandleTypeDef *hspi);
uint32_t                   HAL_SPI_IO_GetError(const SPI_IO_HandleTypeDef *hspi);
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

#endif /* LS2K03XX_HAL_SPI_IO_H */
