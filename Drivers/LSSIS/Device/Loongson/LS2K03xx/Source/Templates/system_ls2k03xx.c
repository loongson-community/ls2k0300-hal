/**
  ******************************************************************************
  * @file    system_ls2k03xx.c
  * @author  MCD Application Team
  * @author  Ilikara <3435193369@qq.com> (Ported for LS2K03xx)
  * @brief   LSSIS LS2K03xx Device Peripheral Access Layer System Source File.
  * 
  * 1.  This file provides two functions and one global variable to be called from 
  *     user application:
  *      - SystemInit(): This function is called at startup just after reset and 
  *                      before branch to main program. This call is made inside
  *                      the "startup_ls2k03xx_xx.s" file.
  *
  *      - SystemCoreClock variable: Contains the core clock, it can be used by
  *                                  the user application to configure other parameters.
  *                                     
  *      - SystemCoreClockUpdate(): Updates the variable SystemCoreClock and must
  *                                 be called whenever the core clock is changed
  *                                 during program execution.
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

/** @addtogroup ls2k03xx_system
  * @{
  */

/** @addtogroup LS2K03xx_System_Private_Includes
  * @{
  */

#include "ls2k03xx.h"

/**
  * @}
  */

/** @addtogroup LS2K03xx_System_Private_TypesDefinitions
  * @{
  */

/**
  * @}
  */

/** @addtogroup LS2K03xx_System_Private_Defines
  * @{
  */

#if !defined  (APB_FREQ)
#define APB_FREQ              200000000U  /*!< Value in Hz */
#endif /* APB_FREQ */

/******************************************************************************/

/**
  * @}
  */

/** @addtogroup LS2K03xx_System_Private_Macros
  * @{
  */

/**
  * @}
  */

/** @addtogroup LS2K03xx_System_Private_Variables
  * @{
  */

  /* This variable is updated in three ways:
      1) by calling LSSIS function SystemCoreClockUpdate()
         Note: If you use this function to configure the system clock; then there
               is no need to call the functions listed above, since SystemCoreClock
               variable is updated automatically.
  */
uint32_t SystemCoreClock = 1000000000;

/**
  * @}
  */

/** @addtogroup LS2K03xx_System_Private_FunctionPrototypes
  * @{
  */
/**
  * @}
  */

/** @addtogroup LS2K03xx_System_Private_Functions
  * @{
  */

/**
  * @brief  Setup the microcontroller system
  * @note   This function should be used only after reset.
  * @param  None
  * @retval None
  */
void SystemInit (void)
{
}

/**
  * @brief  Update SystemCoreClock variable according to Clock Register Values.
  *         The SystemCoreClock variable contains the core clock, it can be used
  *         by the user application to setup the SysTick timer or configure other
  *         parameters.
  *           
  * @note   Each time the core clock changes, this function must be called to
  *         update SystemCoreClock variable value. Otherwise, any configuration
  *         based on this variable will be incorrect.         
  *     
  * @note   - The system frequency computed by this function is not the real 
  *           frequency in the chip. It is calculated based on the predefined 
  *           constant.
  * @param  None
  * @retval None
  */
void SystemCoreClockUpdate (void)
{
  SystemCoreClock = 1000000000;
}

/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */
