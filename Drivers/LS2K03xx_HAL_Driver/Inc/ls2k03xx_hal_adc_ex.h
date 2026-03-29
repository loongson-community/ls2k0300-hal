/**
  ******************************************************************************
  * @file    ls2k03xx_hal_adc_ex.h
  * @author  MCD Application Team (Original STM32 HAL)
  * @author  Ilikara <3435193369@qq.com> (Ported for LS2K03xx)
  * @brief   Header file of ADC HAL extension module.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2016 STMicroelectronics.
  * Copyright (c) 2026 Ilikara <3435193369@qq.com>
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
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
#ifndef __LS2K03xx_HAL_ADC_EX_H
#define __LS2K03xx_HAL_ADC_EX_H

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "ls2k03xx_hal_def.h"  

/** @addtogroup LS2K03xx_HAL_Driver
  * @{
  */

/** @addtogroup ADCEx
  * @{
  */ 

/* Exported types ------------------------------------------------------------*/ 
/** @defgroup ADCEx_Exported_Types ADCEx Exported Types
  * @{
  */

/** 
  * @brief  ADC Configuration injected Channel structure definition
  * @note   Parameters of this structure are shared within 2 scopes:
  *          - Scope channel: InjectedChannel, InjectedRank, InjectedSamplingTime, InjectedOffset
  *          - Scope injected group (affects all channels of injected group): InjectedNbrOfConversion, InjectedDiscontinuousConvMode,
  *            AutoInjectedConv, ExternalTrigInjecConvEdge, ExternalTrigInjecConv.
  * @note   The setting of these parameters with function HAL_ADCEx_InjectedConfigChannel() is conditioned to ADC state.
  *         ADC state can be either:
  *          - For all parameters: ADC disabled (this is the only possible ADC state to modify parameter 'ExternalTrigInjecConv')
  *          - For all except parameters 'ExternalTrigInjecConv': ADC enabled without conversion on going on injected group.
  */
typedef struct 
{
  uint32_t InjectedChannel;                       /*!< Selection of ADC channel to configure
                                                       This parameter can be a value of @ref ADC_channels
                                                       Note: Depending on devices, some channels may not be available on package pins. Refer to device datasheet for channels availability. */
  uint32_t InjectedRank;                          /*!< Rank in the injected group sequencer
                                                       This parameter must be a value of @ref ADCEx_injected_rank
                                                       Note: In case of need to disable a channel or change order of conversion sequencer, rank containing a previous channel setting can be overwritten by the new channel setting (or parameter number of conversions can be adjusted) */
  uint32_t InjectedSamplingTime;                  /*!< Sampling time value to be set for the selected channel.
                                                       Unit: ADC clock cycles
                                                       Conversion time is the addition of sampling time and processing time (13 ADC clock cycles at ADC resolution 12 bits).
                                                       This parameter can be a value of @ref ADC_sampling_times
                                                       Caution: This parameter updates the parameter property of the channel, that can be used into regular and/or injected groups.
                                                                If this same channel has been previously configured in the other group (regular/injected), it will be updated to last setting.
                                                       Note: In case of usage of internal measurement channels (VrefInt/TempSensor),
                                                             sampling time constraints must be respected (sampling time can be adjusted in function of ADC clock frequency and sampling time setting)
                                                             Refer to device datasheet for timings values, parameters TS_vrefint, TS_temp (values rough order: 5us to 17.1us min). */
  uint32_t InjectedOffset;                        /*!< Defines the offset to be subtracted from the raw converted data (for channels set on injected group only).
                                                       Offset value must be a positive number.
                                                       Depending of ADC resolution selected (12, 10, 8 or 6 bits),
                                                       this parameter must be a number between Min_Data = 0x000 and Max_Data = 0xFFF, 0x3FF, 0xFF or 0x3F respectively. */
  uint32_t InjectedNbrOfConversion;               /*!< Specifies the number of ranks that will be converted within the injected group sequencer.
                                                       To use the injected group sequencer and convert several ranks, parameter 'ScanConvMode' must be enabled.
                                                       This parameter must be a number between Min_Data = 1 and Max_Data = 4.
                                                       Caution: this setting impacts the entire injected group. Therefore, call of HAL_ADCEx_InjectedConfigChannel() to
                                                                configure a channel on injected group can impact the configuration of other channels previously set. */
  FunctionalState InjectedDiscontinuousConvMode;  /*!< Specifies whether the conversions sequence of injected group is performed in Complete-sequence/Discontinuous-sequence (main sequence subdivided in successive parts).
                                                       Discontinuous mode is used only if sequencer is enabled (parameter 'ScanConvMode'). If sequencer is disabled, this parameter is discarded.
                                                       Discontinuous mode can be enabled only if continuous mode is disabled. If continuous mode is enabled, this parameter setting is discarded.
                                                       This parameter can be set to ENABLE or DISABLE.
                                                       Note: For injected group, number of discontinuous ranks increment is fixed to one-by-one.
                                                       Caution: this setting impacts the entire injected group. Therefore, call of HAL_ADCEx_InjectedConfigChannel() to
                                                                configure a channel on injected group can impact the configuration of other channels previously set. */
  FunctionalState AutoInjectedConv;               /*!< Enables or disables the selected ADC automatic injected group conversion after regular one
                                                       This parameter can be set to ENABLE or DISABLE.
                                                       Note: To use Automatic injected conversion, discontinuous mode must be disabled ('DiscontinuousConvMode' and 'InjectedDiscontinuousConvMode' set to DISABLE)
                                                       Note: To use Automatic injected conversion, injected group external triggers must be disabled ('ExternalTrigInjecConv' set to ADC_SOFTWARE_START)
                                                       Note: In case of DMA used with regular group: if DMA configured in normal mode (single shot) JAUTO will be stopped upon DMA transfer complete.
                                                             To maintain JAUTO always enabled, DMA must be configured in circular mode.
                                                       Caution: this setting impacts the entire injected group. Therefore, call of HAL_ADCEx_InjectedConfigChannel() to
                                                                configure a channel on injected group can impact the configuration of other channels previously set. */
  uint32_t ExternalTrigInjecConv;                 /*!< Selects the external event used to trigger the conversion start of injected group.
                                                       If set to ADC_INJECTED_SOFTWARE_START, external triggers are disabled.
                                                       If set to external trigger source, triggering is on event rising edge.
                                                       This parameter can be a value of @ref ADCEx_External_trigger_source_Injected
                                                       Note: This parameter must be modified when ADC is disabled (before ADC start conversion or after ADC stop conversion).
                                                             If ADC is enabled, this parameter setting is bypassed without error reporting (as it can be the expected behaviour in case of another parameter update on the fly)
                                                       Caution: this setting impacts the entire injected group. Therefore, call of HAL_ADCEx_InjectedConfigChannel() to
                                                                configure a channel on injected group can impact the configuration of other channels previously set. */
}ADC_InjectionConfTypeDef;


/**
  * @}
  */


/* Exported constants --------------------------------------------------------*/
   
/** @defgroup ADCEx_Exported_Constants ADCEx Exported Constants
  * @{
  */

/** @defgroup ADCEx_injected_rank ADCEx rank into injected group
  * @{
  */
#define ADC_INJECTED_RANK_1                           0x00000001U
#define ADC_INJECTED_RANK_2                           0x00000002U
#define ADC_INJECTED_RANK_3                           0x00000003U
#define ADC_INJECTED_RANK_4                           0x00000004U
/**
  * @}
  */

/** @defgroup ADCEx_External_trigger_edge_Injected ADCEx external trigger enable for injected group
  * @{
  */
#define ADC_EXTERNALTRIGINJECCONV_EDGE_NONE           0x00000000U
#define ADC_EXTERNALTRIGINJECCONV_EDGE_RISING         ((uint32_t)ADC_CR2_JEXTTRIG)
/**
  * @}
  */
    
/** @defgroup ADC_External_trigger_source_Regular ADC External trigger selection for regular group
  * @{
  */
/*!< List of external triggers with generic trigger name, independently of    */
/* ADC target, sorted by trigger name:                                        */

/*!< External triggers of regular group */
#define ADC_EXTERNALTRIGCONV_AT_CC1         ADC_EXTERNALTRIG_AT_CC1
#define ADC_EXTERNALTRIGCONV_AT_CC2         ADC_EXTERNALTRIG_AT_CC2
#define ADC_EXTERNALTRIGCONV_AT_CC3         ADC_EXTERNALTRIG_AT_CC3
#define ADC_EXTERNALTRIGCONV_GT_CC2         ADC_EXTERNALTRIG_GT_CC2
#define ADC_EXTERNALTRIGCONV_EXT_IT11       ADC_EXTERNALTRIG_EXT_IT11
#define ADC_SOFTWARE_START                  ADC_SWSTART
/**
  * @}
  */

/** @defgroup ADCEx_External_trigger_source_Injected ADCEx External trigger selection for injected group
  * @{
  */
/*!< List of external triggers with generic trigger name, independently of    */
/* ADC target, sorted by trigger name:                                        */

/*!< External triggers of injected group */
#define ADC_EXTERNALTRIGINJECCONV_AT_TRGO        ADC_EXTERNALTRIGINJEC_AT_TRGO
#define ADC_EXTERNALTRIGINJECCONV_AT_CC4         ADC_EXTERNALTRIGINJEC_AT_CC4
#define ADC_EXTERNALTRIGINJECCONV_GT_TRGO        ADC_EXTERNALTRIGINJEC_GT_TRGO
#define ADC_EXTERNALTRIGINJECCONV_GT_CC1         ADC_EXTERNALTRIGINJEC_GT_CC1
#define ADC_EXTERNALTRIGINJECCONV_EXT_IT15       ADC_EXTERNALTRIGINJEC_EXT_IT15
#define ADC_INJECTED_SOFTWARE_START              ADC_JSWSTART
/**
  * @}
  */

/**
  * @}
  */


/* Private constants ---------------------------------------------------------*/

/** @addtogroup ADCEx_Private_Constants ADCEx Private Constants
  * @{
  */

/** @defgroup ADCEx_Internal_HAL_driver_Ext_trig_src_Regular ADC Extended Internal HAL driver trigger selection for regular group
  * @{
  */
/* List of external triggers of regular group for ADC */
/* (used internally by HAL driver. To not use into HAL structure parameters)  */

/* External triggers of regular group for ADC */
#define ADC_EXTERNALTRIG_AT_CC1                       0x00000000U
#define ADC_EXTERNALTRIG_AT_CC2              ((uint32_t)(                                      ADC_CR2_EXTSEL_0))
#define ADC_EXTERNALTRIG_AT_CC3              ((uint32_t)(                   ADC_CR2_EXTSEL_1                   ))
#define ADC_EXTERNALTRIG_GT_CC2              ((uint32_t)(                   ADC_CR2_EXTSEL_1 | ADC_CR2_EXTSEL_0))
#define ADC_EXTERNALTRIG_EXT_IT11            ((uint32_t)(ADC_CR2_EXTSEL_2 | ADC_CR2_EXTSEL_1                   ))
#define ADC_SWSTART                          ((uint32_t)(ADC_CR2_EXTSEL_2 | ADC_CR2_EXTSEL_1 | ADC_CR2_EXTSEL_0))
/**
  * @}
  */

/** @defgroup ADCEx_Internal_HAL_driver_Ext_trig_src_Injected ADC Extended Internal HAL driver trigger selection for injected group
  * @{
  */
/* List of external triggers of injected group for ADC */
/* (used internally by HAL driver. To not use into HAL structure parameters)  */

/* External triggers of injected group for ADC */
#define ADC_EXTERNALTRIGINJEC_AT_TRGO                    0x00000000U
#define ADC_EXTERNALTRIGINJEC_AT_CC4         ((uint32_t)(                                        ADC_CR2_JEXTSEL_0))
#define ADC_EXTERNALTRIGINJEC_GT_TRGO        ((uint32_t)(                    ADC_CR2_JEXTSEL_1                    ))
#define ADC_EXTERNALTRIGINJEC_GT_CC1         ((uint32_t)(                    ADC_CR2_JEXTSEL_1 | ADC_CR2_JEXTSEL_0))
#define ADC_EXTERNALTRIGINJEC_EXT_IT15       ((uint32_t)(ADC_CR2_JEXTSEL_2 | ADC_CR2_JEXTSEL_1                    ))
#define ADC_JSWSTART                         ((uint32_t)(ADC_CR2_JEXTSEL_2 | ADC_CR2_JEXTSEL_1 | ADC_CR2_JEXTSEL_0))
/**
  * @}
  */

/**
  * @}
  */


/* Exported macro ------------------------------------------------------------*/

/* Private macro -------------------------------------------------------------*/

/** @defgroup ADCEx_Private_Macro ADCEx Private Macro
  * @{
  */
/* Macro reserved for internal HAL driver usage, not intended to be used in   */
/* code of final user.                                                        */

    
/**
  * @brief This macro makes no change.
  * @param __HANDLE__: ADC handle
  * @param __EXT_TRIG_CONV__: External trigger selected for regular group.
  * @retval External trigger to be programmed into EXTSEL bits of CR2 register
  */
#define ADC_CFGR_EXTSEL(__HANDLE__, __EXT_TRIG_CONV__)                         \
  (__EXT_TRIG_CONV__)

/**
  * @brief This macro makes no change.
  * @param __HANDLE__: ADC handle
  * @param __EXT_TRIG_INJECTCONV__: External trigger selected for injected group.
  * @retval External trigger to be programmed into JEXTSEL bits of CR2 register
  */
#define ADC_CFGR_JEXTSEL(__HANDLE__, __EXT_TRIG_INJECTCONV__)                  \
   (__EXT_TRIG_INJECTCONV__)



#define IS_ADC_INJECTED_RANK(CHANNEL) (((CHANNEL) == ADC_INJECTED_RANK_1) || \
                                       ((CHANNEL) == ADC_INJECTED_RANK_2) || \
                                       ((CHANNEL) == ADC_INJECTED_RANK_3) || \
                                       ((CHANNEL) == ADC_INJECTED_RANK_4))

#define IS_ADC_EXTTRIGINJEC_EDGE(EDGE) (((EDGE) == ADC_EXTERNALTRIGINJECCONV_EDGE_NONE)  || \
                                        ((EDGE) == ADC_EXTERNALTRIGINJECCONV_EDGE_RISING))

/** @defgroup ADCEx_injected_nb_conv_verification ADCEx injected nb conv verification
  * @{
  */
#define IS_ADC_INJECTED_NB_CONV(LENGTH)  (((LENGTH) >= 1U) && ((LENGTH) <= 4U))
/**
  * @}
  */

#if defined (LS2K0300)
#define IS_ADC_EXTTRIG(REGTRIG) (((REGTRIG) == ADC_EXTERNALTRIGCONV_AT_CC1)        || \
                                 ((REGTRIG) == ADC_EXTERNALTRIGCONV_AT_CC2)        || \
                                 ((REGTRIG) == ADC_EXTERNALTRIGCONV_AT_CC3)        || \
                                 ((REGTRIG) == ADC_EXTERNALTRIGCONV_GT_CC2)        || \
                                 ((REGTRIG) == ADC_EXTERNALTRIGCONV_EXT_IT11)  || \
                                 ((REGTRIG) == ADC_SOFTWARE_START))
#endif

#if defined (LS2K0300)
#define IS_ADC_EXTTRIGINJEC(REGTRIG) (((REGTRIG) == ADC_EXTERNALTRIGINJECCONV_AT_TRGO)  || \
                                      ((REGTRIG) == ADC_EXTERNALTRIGINJECCONV_AT_CC4)   || \
                                      ((REGTRIG) == ADC_EXTERNALTRIGINJECCONV_GT_TRGO)  || \
                                      ((REGTRIG) == ADC_EXTERNALTRIGINJECCONV_GT_CC1)   || \
                                      ((REGTRIG) == ADC_EXTERNALTRIGINJECCONV_EXT_IT15) || \
                                      ((REGTRIG) == ADC_INJECTED_SOFTWARE_START))
#endif


/**
  * @}
  */      
   
    

    
    
   
/* Exported functions --------------------------------------------------------*/
/** @addtogroup ADCEx_Exported_Functions
  * @{
  */

/* IO operation functions  *****************************************************/
/** @addtogroup ADCEx_Exported_Functions_Group1
  * @{
  */

/* ADC calibration */
HAL_StatusTypeDef       HAL_ADCEx_Calibration_Start(ADC_HandleTypeDef* hadc);

/* Blocking mode: Polling */
HAL_StatusTypeDef       HAL_ADCEx_InjectedStart(ADC_HandleTypeDef* hadc);
HAL_StatusTypeDef       HAL_ADCEx_InjectedStop(ADC_HandleTypeDef* hadc);
HAL_StatusTypeDef       HAL_ADCEx_InjectedPollForConversion(ADC_HandleTypeDef* hadc, uint32_t Timeout);

/* Non-blocking mode: Interruption */
HAL_StatusTypeDef       HAL_ADCEx_InjectedStart_IT(ADC_HandleTypeDef* hadc);
HAL_StatusTypeDef       HAL_ADCEx_InjectedStop_IT(ADC_HandleTypeDef* hadc);

/* ADC retrieve conversion value intended to be used with polling or interruption */
uint32_t                HAL_ADCEx_InjectedGetValue(ADC_HandleTypeDef* hadc, uint32_t InjectedRank);

/* ADC IRQHandler and Callbacks used in non-blocking modes (Interruption) */
void                    HAL_ADCEx_InjectedConvCpltCallback(ADC_HandleTypeDef* hadc);
/**
  * @}
  */


/* Peripheral Control functions ***********************************************/
/** @addtogroup ADCEx_Exported_Functions_Group2
  * @{
  */
HAL_StatusTypeDef       HAL_ADCEx_InjectedConfigChannel(ADC_HandleTypeDef* hadc,ADC_InjectionConfTypeDef* sConfigInjected);
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

#endif /* __LS2K03xx_HAL_ADC_EX_H */
