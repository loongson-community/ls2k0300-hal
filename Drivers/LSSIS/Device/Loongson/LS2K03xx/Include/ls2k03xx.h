/**
  ******************************************************************************
  * @file    ls2k03xx.h
  * @author  MCD Application Team
  * @author  Ilikara <3435193369@qq.com> (Ported for LS2K03xx)
  * @brief   LSSIS LS2K03xx Device Peripheral Access Layer Header File. 
  *
  *          The file is the unique include file that the application programmer
  *          is using in the C source code, usually in main.c. This file contains:
  *            - Configuration section that allows to select:
  *              - The LS2K03xx device used in the target application
  *              - To use or not the peripheral's drivers in application code(i.e. 
  *                code will be based on direct access to peripheral's registers 
  *                rather than drivers API), this option is controlled by 
  *                "#define USE_HAL_DRIVER"
  *  
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

/** @addtogroup ls2k03xx
  * @{
  */

#ifndef __LS2K03XX_H
#define __LS2K03XX_H

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/** @addtogroup Library_configuration_section
  * @{
  */

/**
  * @brief LS2K Family
  */
#if !defined (LS2K03)
#define LS2K03
#endif /* LS2K03 */

/* Uncomment the line below according to the target LS2K03 device used in your 
   application 
  */

#if !defined (LS2K0300) && !defined (LS2K0301)
  /* #define LS2K0300 */
  /* #define LS2K0301 */
#endif

/*  Tip: To avoid modifying this file each time you need to switch between these
        devices, you can define the device in your toolchain compiler preprocessor.
  */
  
#if !defined  (USE_HAL_DRIVER)
/**
 * @brief Comment the line below if you will not use the peripherals drivers.
   In this case, these drivers will not be included and the application code will 
   be based on direct access to peripherals registers 
   */
  /*#define USE_HAL_DRIVER */
#endif /* USE_HAL_DRIVER */

/**
  * @brief LSSIS Device version number
  */
#define __LS2K03_LSSIS_VERSION_MAIN     (0x04) /*!< [31:24] main version */
#define __LS2K03_LSSIS_VERSION_SUB1     (0x03) /*!< [23:16] sub1 version */
#define __LS2K03_LSSIS_VERSION_SUB2     (0x05) /*!< [15:8]  sub2 version */
#define __LS2K03_LSSIS_VERSION_RC       (0x00) /*!< [7:0]  release candidate */ 
#define __LS2K03_LSSIS_VERSION          ((__LS2K03_LSSIS_VERSION_MAIN << 24)\
                                        |(__LS2K03_LSSIS_VERSION_SUB1 << 16)\
                                        |(__LS2K03_LSSIS_VERSION_SUB2 << 8 )\
                                        |(__LS2K03_LSSIS_VERSION_RC))

/**
  * @}
  */

/** @addtogroup Device_Included
  * @{
  */

#if defined(LS2K0300)
  #include "ls2k0300.h"
#else
 #error "Please select first the target LS2K03xx device used in your application (in ls2k03xx.h file)"
#endif

/**
  * @}
  */

/** @addtogroup Exported_types
  * @{
  */
typedef enum 
{
  RESET = 0, 
  SET = !RESET
} FlagStatus, ITStatus;

typedef enum 
{
  DISABLE = 0, 
  ENABLE = !DISABLE
} FunctionalState;
#define IS_FUNCTIONAL_STATE(STATE) (((STATE) == DISABLE) || ((STATE) == ENABLE))

typedef enum
{
  SUCCESS = 0U,
  ERROR = !SUCCESS
} ErrorStatus;

/**
  * @}
  */

/** @addtogroup Exported_macros
  * @{
  */
#define SET_BIT(REG, BIT)     ((REG) |= (BIT))

#define CLEAR_BIT(REG, BIT)   ((REG) &= ~(BIT))

#define READ_BIT(REG, BIT)    ((REG) & (BIT))

#define CLEAR_REG(REG)        ((REG) = (0x0))

#define WRITE_REG(REG, VAL)   ((REG) = (VAL))

#define READ_REG(REG)         ((REG))

#define MODIFY_REG(REG, CLEARMASK, SETMASK)  WRITE_REG((REG), (((READ_REG(REG)) & (~(CLEARMASK))) | (SETMASK)))

/**
  * @}
  */

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __LS2K03XX_H */
/**
  * @}
  */

/**
  * @}
  */
