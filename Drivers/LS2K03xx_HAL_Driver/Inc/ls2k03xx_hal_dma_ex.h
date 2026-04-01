/**
  ******************************************************************************
  * @file    ls2k03xx_hal_dma_ex.h
  * @author  MCD Application Team (Original STM32 HAL)
  * @author  Ilikara <3435193369@qq.com> (Ported for LS2K03xx)
  * @brief   Header file of DMA HAL extension module.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2016 STMicroelectronics.
  * Copyright (c) 2026 Ilikara <3435193369@qq.com>
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file in
  * the root directory of this software component.
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
#ifndef __LS2K03xx_HAL_DMA_EX_H
#define __LS2K03xx_HAL_DMA_EX_H

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "ls2k03xx_hal_def.h"

/** @addtogroup LS2K03xx_HAL_Driver
  * @{
  */

/** @defgroup DMAEx DMAEx
  * @{
  */

/* Exported types ------------------------------------------------------------*/ 
/* Exported constants --------------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/
/** @defgroup DMAEx_Exported_Macros DMA Extended Exported Macros
  * @{
  */
/* Interrupt & Flag management */

/**
  * @brief  Returns the current DMA Channel transfer complete flag.
  * @param  __HANDLE__: DMA handle
  * @retval The specified transfer complete flag index.
  */
#define __HAL_DMA_GET_TC_FLAG_INDEX(__HANDLE__) \
(((uint64_t)((__HANDLE__)->Instance) == ((uint64_t)DMA_Channel0))? DMA_FLAG_TC0 :\
 ((uint64_t)((__HANDLE__)->Instance) == ((uint64_t)DMA_Channel1))? DMA_FLAG_TC1 :\
 ((uint64_t)((__HANDLE__)->Instance) == ((uint64_t)DMA_Channel2))? DMA_FLAG_TC2 :\
 ((uint64_t)((__HANDLE__)->Instance) == ((uint64_t)DMA_Channel3))? DMA_FLAG_TC3 :\
 ((uint64_t)((__HANDLE__)->Instance) == ((uint64_t)DMA_Channel4))? DMA_FLAG_TC4 :\
 ((uint64_t)((__HANDLE__)->Instance) == ((uint64_t)DMA_Channel5))? DMA_FLAG_TC5 :\
 ((uint64_t)((__HANDLE__)->Instance) == ((uint64_t)DMA_Channel6))? DMA_FLAG_TC6 :\
   DMA_FLAG_TC7)

/**
  * @brief  Return the current DMA Channel half transfer complete flag.
  * @param  __HANDLE__: DMA handle
  * @retval The specified half transfer complete flag index.
  */
#define __HAL_DMA_GET_HT_FLAG_INDEX(__HANDLE__)\
(((uint64_t)((__HANDLE__)->Instance) == ((uint64_t)DMA_Channel0))? DMA_FLAG_HT0 :\
 ((uint64_t)((__HANDLE__)->Instance) == ((uint64_t)DMA_Channel1))? DMA_FLAG_HT1 :\
 ((uint64_t)((__HANDLE__)->Instance) == ((uint64_t)DMA_Channel2))? DMA_FLAG_HT2 :\
 ((uint64_t)((__HANDLE__)->Instance) == ((uint64_t)DMA_Channel3))? DMA_FLAG_HT3 :\
 ((uint64_t)((__HANDLE__)->Instance) == ((uint64_t)DMA_Channel4))? DMA_FLAG_HT4 :\
 ((uint64_t)((__HANDLE__)->Instance) == ((uint64_t)DMA_Channel5))? DMA_FLAG_HT5 :\
 ((uint64_t)((__HANDLE__)->Instance) == ((uint64_t)DMA_Channel6))? DMA_FLAG_HT6 :\
   DMA_FLAG_HT7)

/**
  * @brief  Return the current DMA Channel transfer error flag.
  * @param  __HANDLE__: DMA handle
  * @retval The specified transfer error flag index.
  */
#define __HAL_DMA_GET_TE_FLAG_INDEX(__HANDLE__)\
(((uint64_t)((__HANDLE__)->Instance) == ((uint64_t)DMA_Channel0))? DMA_FLAG_TE0 :\
 ((uint64_t)((__HANDLE__)->Instance) == ((uint64_t)DMA_Channel1))? DMA_FLAG_TE1 :\
 ((uint64_t)((__HANDLE__)->Instance) == ((uint64_t)DMA_Channel2))? DMA_FLAG_TE2 :\
 ((uint64_t)((__HANDLE__)->Instance) == ((uint64_t)DMA_Channel3))? DMA_FLAG_TE3 :\
 ((uint64_t)((__HANDLE__)->Instance) == ((uint64_t)DMA_Channel4))? DMA_FLAG_TE4 :\
 ((uint64_t)((__HANDLE__)->Instance) == ((uint64_t)DMA_Channel5))? DMA_FLAG_TE5 :\
 ((uint64_t)((__HANDLE__)->Instance) == ((uint64_t)DMA_Channel6))? DMA_FLAG_TE6 :\
   DMA_FLAG_TE7)

/**
  * @brief  Return the current DMA Channel Global interrupt flag.
  * @param  __HANDLE__: DMA handle
  * @retval The specified transfer error flag index.
  */
#define __HAL_DMA_GET_GI_FLAG_INDEX(__HANDLE__)\
(((uint64_t)((__HANDLE__)->Instance) == ((uint64_t)DMA_Channel0))? DMA_FLAG_GL0 :\
 ((uint64_t)((__HANDLE__)->Instance) == ((uint64_t)DMA_Channel1))? DMA_FLAG_GL1 :\
 ((uint64_t)((__HANDLE__)->Instance) == ((uint64_t)DMA_Channel2))? DMA_FLAG_GL2 :\
 ((uint64_t)((__HANDLE__)->Instance) == ((uint64_t)DMA_Channel3))? DMA_FLAG_GL3 :\
 ((uint64_t)((__HANDLE__)->Instance) == ((uint64_t)DMA_Channel4))? DMA_FLAG_GL4 :\
 ((uint64_t)((__HANDLE__)->Instance) == ((uint64_t)DMA_Channel5))? DMA_FLAG_GL5 :\
 ((uint64_t)((__HANDLE__)->Instance) == ((uint64_t)DMA_Channel6))? DMA_FLAG_GL6 :\
   DMA_FLAG_GL7)

/**
  * @brief  Get the DMA Channel pending flags.
  * @param  __HANDLE__: DMA handle
  * @param  __FLAG__: Get the specified flag.
  *          This parameter can be any combination of the following values:
  *            @arg DMA_FLAG_TCx:  Transfer complete flag
  *            @arg DMA_FLAG_HTx:  Half transfer complete flag
  *            @arg DMA_FLAG_TEx:  Transfer error flag
  *            @arg DMA_FLAG_GLx:  Global interrupt flag
  *         Where x can be 0_7 to select the DMA Channel flag.   
  * @retval The state of FLAG (SET or RESET).
  */

#define __HAL_DMA_GET_FLAG(__HANDLE__, __FLAG__)   (DMA->ISR & (__FLAG__))

/**
  * @brief  Clear the DMA Channel pending flags.
  * @param  __HANDLE__: DMA handle
  * @param  __FLAG__: specifies the flag to clear.
  *          This parameter can be any combination of the following values:
  *            @arg DMA_FLAG_TCx:  Transfer complete flag
  *            @arg DMA_FLAG_HTx:  Half transfer complete flag
  *            @arg DMA_FLAG_TEx:  Transfer error flag
  *            @arg DMA_FLAG_GLx:  Global interrupt flag
  *         Where x can be 0_7 to select the DMA Channel flag.   
  * @retval None
  */
#define __HAL_DMA_CLEAR_FLAG(__HANDLE__, __FLAG__) (DMA->IFCR = (__FLAG__))
  
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

#endif /* __LS2K03xx_HAL_DMA_H */
