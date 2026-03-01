/**
  ******************************************************************************
  * @file    system_ls2k03xx.h
  * @author  MCD Application Team
  * @author  Ilikara <3435193369@qq.com> (Ported for LS2K03xx)
  * @brief   LSSIS LS2K03xx Device Peripheral Access Layer System Header File.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2017-2021 STMicroelectronics.
  * Copyright (c) 2026 Ilikara <3435193369@qq.com>
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */

/** @addtogroup LSSIS
  * @{
  */

/** @addtogroup ls2k030x_system
  * @{
  */  

/**
  * @brief Define to prevent recursive inclusion
  */
#ifndef __SYSTEM_LS2K030X_H
#define __SYSTEM_LS2K030X_H

#include <stdint.h>
#ifdef __cplusplus
extern "C" {
#endif 

/** @addtogroup LS2K030x_System_Includes
  * @{
  */

/**
  * @}
  */


/** @addtogroup LS2K030x_System_Exported_types
  * @{
  */

extern uint32_t SystemCoreClock;          /*!< System Clock Frequency (Core Clock) */

/**
  * @}
  */

/** @addtogroup LS2K030x_System_Exported_Constants
  * @{
  */

/**
  * @}
  */

/** @addtogroup LS2K030x_System_Exported_Macros
  * @{
  */

/**
  * @}
  */

/** @addtogroup LS2K030x_System_Exported_Functions
  * @{
  */

extern void SystemInit(void);
extern void SystemCoreClockUpdate(void);
/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /*__SYSTEM_LS2K030X_H */

/**
  * @}
  */

/**
  * @}
  */
