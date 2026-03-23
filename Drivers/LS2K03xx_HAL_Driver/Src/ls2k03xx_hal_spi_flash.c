/**
  ******************************************************************************
  * @file    ls2k03xx_hal_spi_flash.c
  * @author  Ilikara <3435193369@qq.com>
  * @brief   SPI-Flash HAL module driver.
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

/** @addtogroup LS2K03xx_HAL_Driver
  * @{
  */

/** @defgroup SPI SPI
  * @brief SPI-FLASH HAL module driver
  * @{
  */
#ifdef HAL_SPI_FLASH_MODULE_ENABLED

/* Private typedef -----------------------------------------------------------*/
/* Private defines -----------------------------------------------------------*/
/* Private macros ------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
static HAL_StatusTypeDef SPI_FLASH_EndRxTxTransaction(SPI_FLASH_HandleTypeDef *hspi, uint32_t Timeout, uint32_t Tickstart);
/* Exported functions --------------------------------------------------------*/
/** @defgroup SPI_Exported_Functions SPI Exported Functions
  * @{
  */

/** @defgroup SPI_Exported_Functions_Group1 Initialization and de-initialization functions
  *  @brief    Initialization and Configuration functions
  *
@verbatim
 ===============================================================================
              ##### Initialization and de-initialization functions #####
 ===============================================================================
@endverbatim
  * @{
  */

/**
  * @brief  Initialize the SPI according to the specified parameters
  *         in the SPI_InitTypeDef and initialize the associated handle.
  * @param  hspi pointer to a SPI_FLASH_HandleTypeDef structure that contains
  *               the configuration information for SPI module.
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_SPI_FLASH_Init(SPI_FLASH_HandleTypeDef *hspi)
{
  /* Check the SPI handle allocation */
  if (hspi == NULL)
  {
    return HAL_ERROR;
  }

  /* Check the parameters */
  assert_param(IS_SPI_FLASH_INSTANCE(hspi->Instance));
  assert_param(IS_SPI_FLASH_NSS(hspi->Init.NSS));
  assert_param(IS_SPI_FLASH_BAUDRATE_PRESCALER(hspi->Init.BaudRatePrescaler));

  /* Init the low level hardware : GPIO... */
  HAL_SPI_FLASH_MspInit(hspi);

  hspi->State = HAL_SPI_FLASH_STATE_BUSY;

  CLEAR_BIT(hspi->Instance->SPCR, SPI_FLASH_SPCR_SPE);

  SET_BIT(hspi->Instance->SPSR, SPI_FLASH_SPSR_SPIF | SPI_FLASH_SPSR_WCOL);

  WRITE_REG(hspi->Instance->SFC_SOFTCS, hspi->Init.NSS);

  MODIFY_REG(hspi->Instance->SPCR, 
    SPI_FLASH_SPCR_CPOL | SPI_FLASH_SPCR_CPHA | SPI_FLASH_SPCR_SPR, 
    ((hspi->Init.CLKPolarity & SPI_FLASH_SPCR_CPOL) |
     (hspi->Init.CLKPhase & SPI_FLASH_SPCR_CPHA) |
     ((hspi->Init.BaudRatePrescaler >> 0) & SPI_FLASH_SPCR_SPR)));

  MODIFY_REG(hspi->Instance->SPER, 
    SPI_FLASH_SPER_SPRE, 
    ((hspi->Init.BaudRatePrescaler >> 2) & SPI_FLASH_SPER_SPRE));

  hspi->ErrorCode = HAL_SPI_FLASH_ERROR_NONE;
  hspi->State     = HAL_SPI_FLASH_STATE_READY;

  return HAL_OK;
}

/**
  * @brief  De-Initialize the SPI peripheral.
  * @param  hspi pointer to a SPI_FLASH_HandleTypeDef structure that contains
  *               the configuration information for SPI module.
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_SPI_FLASH_DeInit(SPI_FLASH_HandleTypeDef *hspi)
{
  /* Check the SPI handle allocation */
  if (hspi == NULL)
  {
    return HAL_ERROR;
  }

  /* Check SPI Instance parameter */
  assert_param(IS_SPI_FLASH_INSTANCE(hspi->Instance));

  hspi->State = HAL_SPI_FLASH_STATE_BUSY;

  /* Disable the SPI Peripheral Clock */
  __HAL_SPI_FLASH_DISABLE(hspi);

  /* DeInit the low level hardware: GPIO... */
  HAL_SPI_FLASH_MspDeInit(hspi);

  hspi->ErrorCode = HAL_SPI_FLASH_ERROR_NONE;
  hspi->State = HAL_SPI_FLASH_STATE_RESET;

  /* Release Lock */
  __HAL_UNLOCK(hspi);

  return HAL_OK;
}

/**
  * @brief  Initialize the SPI MSP.
  * @param  hspi pointer to a SPI_FLASH_HandleTypeDef structure that contains
  *               the configuration information for SPI module.
  * @retval None
  */
__weak void HAL_SPI_FLASH_MspInit(SPI_FLASH_HandleTypeDef *hspi)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(hspi);

  /* NOTE : This function should not be modified, when the callback is needed,
            the HAL_SPI_FLASH_MspInit should be implemented in the user file
   */
}

/**
  * @brief  De-Initialize the SPI MSP.
  * @param  hspi pointer to a SPI_FLASH_HandleTypeDef structure that contains
  *               the configuration information for SPI module.
  * @retval None
  */
__weak void HAL_SPI_FLASH_MspDeInit(SPI_FLASH_HandleTypeDef *hspi)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(hspi);

  /* NOTE : This function should not be modified, when the callback is needed,
            the HAL_SPI_FLASH_MspDeInit should be implemented in the user file
   */
}
/**
  * @}
  */

/** @defgroup SPI_Exported_Functions_Group2 IO operation functions
  *  @brief   Data transfers functions
  *
@verbatim
  ==============================================================================
                      ##### IO operation functions #####
 ===============================================================================
 [..]
    This subsection provides a set of functions allowing to manage the SPI
    data transfers.

    [..] The SPI supports master mode :

    (#) There is one mode of transfer:
       (++) Blocking mode: The communication is performed in polling mode.
            The HAL status of all data processing is returned by the same function
            after finishing transfer.

@endverbatim
  * @{
  */

/**
  * @brief  Transmit an amount of data in blocking mode.
  * @param  hspi pointer to a SPI_FLASH_HandleTypeDef structure that contains
  *               the configuration information for SPI module.
  * @param  pData pointer to data buffer
  * @param  Size amount of data to be sent
  * @param  Timeout Timeout duration
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_SPI_FLASH_Transmit(SPI_FLASH_HandleTypeDef *hspi, const uint8_t *pData, uint16_t Size, uint32_t Timeout)
{
  return HAL_SPI_FLASH_TransmitReceive(hspi, pData, NULL, Size, Timeout);
}

/**
  * @brief  Receive an amount of data in blocking mode.
  * @param  hspi pointer to a SPI_FLASH_HandleTypeDef structure that contains
  *               the configuration information for SPI module.
  * @param  pData pointer to data buffer
  * @param  Size amount of data to be received
  * @param  Timeout Timeout duration
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_SPI_FLASH_Receive(SPI_FLASH_HandleTypeDef *hspi, uint8_t *pData, uint16_t Size, uint32_t Timeout)
{
  return HAL_SPI_FLASH_TransmitReceive(hspi, NULL, pData, Size, Timeout);
}

/**
  * @brief  Transmit and Receive an amount of data in blocking mode.
  * @param  hspi pointer to a SPI_FLASH_HandleTypeDef structure that contains
  *               the configuration information for SPI module.
  * @param  pTxData pointer to transmission data buffer
  * @param  pRxData pointer to reception data buffer
  * @param  Size amount of data to be sent and received
  * @param  Timeout Timeout duration
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_SPI_FLASH_TransmitReceive(SPI_FLASH_HandleTypeDef *hspi, const uint8_t *pTxData, uint8_t *pRxData,
                                          uint16_t Size, uint32_t Timeout)
{
  uint16_t                    initial_TxXferCount;
  HAL_SPI_FLASH_StateTypeDef  tmp_state;
  uint32_t                    tickstart;

  /* Variable used to alternate Rx and Tx during transfer */
  uint32_t                    txallowed = 1U;

  uint8_t dummy_read;

  /* Init tickstart for timeout management*/
  tickstart = HAL_GetTick();

  /* Init temporary variables */
  tmp_state           = hspi->State;
  initial_TxXferCount = Size;

  if (!((tmp_state == HAL_SPI_FLASH_STATE_READY) || \
        (tmp_state == HAL_SPI_FLASH_STATE_BUSY_RX)))
  {
    return HAL_BUSY;
  }

  if (((pTxData == NULL) && (pRxData == NULL)) || (Size == 0U))
  {
    return HAL_ERROR;
  }

  /* Process Locked */
  __HAL_LOCK(hspi);

  /* Don't overwrite in case of HAL_SPI_FLASH_STATE_BUSY_RX */
  if (hspi->State != HAL_SPI_FLASH_STATE_BUSY_RX)
  {
    hspi->State = HAL_SPI_FLASH_STATE_BUSY_TX_RX;
  }

  /* Set the transaction information */
  hspi->ErrorCode   = HAL_SPI_FLASH_ERROR_NONE;
  hspi->pRxBuffPtr  = (uint8_t *)pRxData;
  hspi->RxXferCount = Size;
  hspi->RxXferSize  = Size;
  hspi->pTxBuffPtr  = (const uint8_t *)pTxData;
  hspi->TxXferCount = Size;
  hspi->TxXferSize  = Size;

  /* Check if the SPI is already enabled */
  if ((hspi->Instance->SPCR & SPI_FLASH_SPCR_SPE) != SPI_FLASH_SPCR_SPE)
  {
    /* Enable SPI peripheral */
    __HAL_SPI_FLASH_ENABLE(hspi);
  }

  if (initial_TxXferCount == 0x01U)
  {
    *((__IO uint8_t *)&hspi->Instance->FIFO) = *((const uint8_t *)hspi->pTxBuffPtr);
    hspi->pTxBuffPtr += sizeof(uint8_t);
    hspi->TxXferCount--;
  }
  while ((hspi->TxXferCount > 0U) || (hspi->RxXferCount > 0U))
  {
    /* Wait until WFEMPTY flag is set */
    if ((__HAL_SPI_FLASH_GET_FLAG(hspi, SPI_FLASH_SPSR_WFEMPTY)) && (hspi->TxXferCount > 0U) && (txallowed == 1U))
    {
      if(hspi->pTxBuffPtr)
      {
        *(__IO uint8_t *)&hspi->Instance->FIFO = *((const uint8_t *)hspi->pTxBuffPtr);
        hspi->pTxBuffPtr++;
      }
      else
      {
        *(__IO uint8_t *)&hspi->Instance->FIFO = 0;
      }
      hspi->TxXferCount--;
      /* Next Data is a reception (Rx). Tx not allowed */
      txallowed = 0U;
    }

    /* Wait until RFEMPTY flag is reset */
    if ((__HAL_SPI_FLASH_GET_FLAG(hspi, SPI_FLASH_SPSR_RFEMPTY) == 0) && (hspi->RxXferCount > 0U))
    {
      if(hspi->pRxBuffPtr)
      {
        (*(uint8_t *)hspi->pRxBuffPtr) = hspi->Instance->FIFO;
        hspi->pRxBuffPtr++;
      }
      else
      {
        dummy_read = hspi->Instance->FIFO;
        UNUSED(dummy_read);
      }
      hspi->RxXferCount--;
      /* Next Data is a Transmission (Tx). Tx is allowed */
      txallowed = 1U;
    }
    if ((((HAL_GetTick() - tickstart) >=  Timeout) && ((Timeout != HAL_MAX_DELAY))) || (Timeout == 0U))
    {
      hspi->State = HAL_SPI_FLASH_STATE_READY;
      __HAL_UNLOCK(hspi);
      return HAL_TIMEOUT;
    }
  }

  /* Check the end of the transaction */
  if (SPI_FLASH_EndRxTxTransaction(hspi, Timeout, tickstart) != HAL_OK)
  {
    hspi->ErrorCode = HAL_SPI_FLASH_ERROR_FLAG;
    __HAL_UNLOCK(hspi);
    return HAL_ERROR;
  }

  hspi->State = HAL_SPI_FLASH_STATE_READY;
  /* Unlock the process */
  __HAL_UNLOCK(hspi);

  if (hspi->ErrorCode != HAL_SPI_FLASH_ERROR_NONE)
  {
    return HAL_ERROR;
  }
  else
  {
    return HAL_OK;
  }
}

/**
  * @brief  Abort ongoing transfer (blocking mode).
  * @param  hspi SPI handle.
  * @note   This procedure could be used for aborting any ongoing transfer (Tx and Rx),
  *         started in Interrupt or DMA mode.
  *         This procedure performs following operations :
  *           - Disable SPI Interrupts (depending of transfer direction)
  *           - Set handle State to READY
  * @note   This procedure is executed in blocking mode : when exiting function, Abort is considered as completed.
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_SPI_FLASH_Abort(SPI_FLASH_HandleTypeDef *hspi)
{
  HAL_StatusTypeDef errorcode;

  /* Initialized local variable  */
  errorcode = HAL_OK;

  /* Restore hspi->state to ready */
  hspi->State = HAL_SPI_FLASH_STATE_READY;

  return errorcode;
}

/**
  * @}
  */

/** @defgroup SPI_Exported_Functions_Group3 Peripheral State and Errors functions
  * @brief   SPI control functions
  *
@verbatim
 ===============================================================================
                      ##### Peripheral State and Errors functions #####
 ===============================================================================
    [..]
    This subsection provides a set of functions allowing to control the SPI.
     (+) HAL_SPI_FLASH_GetState() API can be helpful to check in run-time the state of the SPI peripheral
     (+) HAL_SPI_FLASH_GetError() check in run-time Errors occurring during communication
@endverbatim
  * @{
  */

/**
  * @brief  Return the SPI handle state.
  * @param  hspi pointer to a SPI_FLASH_HandleTypeDef structure that contains
  *               the configuration information for SPI module.
  * @retval SPI state
  */
HAL_SPI_FLASH_StateTypeDef HAL_SPI_FLASH_GetState(const SPI_FLASH_HandleTypeDef *hspi)
{
  /* Return SPI handle state */
  return hspi->State;
}

/**
  * @brief  Return the SPI error code.
  * @param  hspi pointer to a SPI_FLASH_HandleTypeDef structure that contains
  *               the configuration information for SPI module.
  * @retval SPI error code in bitmap format
  */
uint32_t HAL_SPI_FLASH_GetError(const SPI_FLASH_HandleTypeDef *hspi)
{
  /* Return SPI ErrorCode */
  return hspi->ErrorCode;
}

/**
  * @}
  */

/**
  * @}
  */

/** @addtogroup SPI_Private_Functions
  * @brief   Private functions
  * @{
  */

/**
  * @brief  Handle SPI Communication Timeout.
  * @param  hspi pointer to a SPI_FLASH_HandleTypeDef structure that contains
  *              the configuration information for SPI module.
  * @param  Flag SPI flag to check
  * @param  State flag state to check
  * @param  Timeout Timeout duration
  * @param  Tickstart tick start value
  * @retval HAL status
  */
static HAL_StatusTypeDef SPI_FLASH_WaitFlagStateUntilTimeout(SPI_FLASH_HandleTypeDef *hspi, uint32_t Flag, FlagStatus State,
                                                       uint32_t Timeout, uint32_t Tickstart)
{
  while (__HAL_SPI_FLASH_GET_FLAG(hspi, Flag) == State)
  {
    if (Timeout != HAL_MAX_DELAY)
    {
      if (((HAL_GetTick() - Tickstart) >= Timeout) || (Timeout == 0U))
      {
        /* Disable interrupts for the interrupt process */
        __HAL_SPI_FLASH_DISABLE_IT(hspi);

        /* Disable SPI peripheral */
        __HAL_SPI_FLASH_DISABLE(hspi);

        hspi->State = HAL_SPI_FLASH_STATE_READY;

        /* Process Unlocked */
        __HAL_UNLOCK(hspi);

        return HAL_TIMEOUT;
      }
    }
  }

  return HAL_OK;
}

/**
  * @brief  Handle the check of the RXTX or TX transaction complete.
  * @param  hspi SPI handle
  * @param  Timeout Timeout duration
  * @param  Tickstart tick start value
  * @retval HAL status
  */
static HAL_StatusTypeDef SPI_FLASH_EndRxTxTransaction(SPI_FLASH_HandleTypeDef *hspi, uint32_t Timeout, uint32_t Tickstart)
{
  if (SPI_FLASH_WaitFlagStateUntilTimeout(hspi, SPI_FLASH_FLAG_WFEMPTY, RESET, Timeout, Tickstart) != HAL_OK)
  {
    SET_BIT(hspi->ErrorCode, HAL_SPI_FLASH_ERROR_FLAG);
    return HAL_TIMEOUT;
  }

  if (SPI_FLASH_WaitFlagStateUntilTimeout(hspi, SPI_FLASH_FLAG_RFEMPTY, RESET, Timeout, Tickstart) != HAL_OK)
  {
    SET_BIT(hspi->ErrorCode, HAL_SPI_FLASH_ERROR_FLAG);
    return HAL_TIMEOUT;
  }
  return HAL_OK;
}
/**
  * @}
  */

#endif /* HAL_SPI_FLASH_MODULE_ENABLED */

/**
  * @}
  */

/**
  * @}
  */
