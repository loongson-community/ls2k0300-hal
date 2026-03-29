/**
  ******************************************************************************
  * @file    ls2k0300.h
  * @author  MCD Application Team
  * @author  Ilikara <3435193369@qq.com> (Ported for LS2K03xx)
  * @brief   LSSIS LS2K03xx Device Peripheral Access Layer Header File. 
  *          This file contains all the peripheral register's definitions, bits 
  *          definitions and memory mapping for STM32F1xx devices.            
  *            
  *          This file contains:
  *           - Data structures and the address mapping for all peripherals
  *           - Peripheral's registers declarations and bits definition
  *           - Macros to access peripheral's registers hardware
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

/** @addtogroup ls2k0300
  * @{
  */

#ifndef __LS2K0300_H
#define __LS2K0300_H

#ifdef __cplusplus
extern "C" {
#endif

/** @addtogroup Peripheral_interrupt_number_definition
  * @{
  */

/**
 * @brief LS2K0300 Interrupt Number Definition, according to the selected device 
 *        in @ref Library_configuration_section 
 */

 /*!< Interrupt Number Definition */
typedef enum
{
  UART00_LIOINTC_IRQn = 0,
  UART01_LIOINTC_IRQn,
  UART02_05_LIOINTC_IRQn,
  UART06_09_LIOINTC_IRQn,
  I2C00_01_LIOINTC_IRQn,
  I2C02_03_LIOINTC_IRQn,
  SPI2_LIOINTC_IRQn,
  SPI3_LIOINTC_IRQn,
  CAN0_LIOINTC_IRQn,
  CAN1_LIOINTC_IRQn,
  CAN2_LIOINTC_IRQn,
  CAN3_LIOINTC_IRQn,
  I2S_LIOINTC_IRQn,
  ATIM_LIOINTC_IRQn,
  GTIM_LIOINTC_IRQn,
  BTIM_LIOINTC_IRQn,
  PWM0_1_LIOINTC_IRQn,
  PWM2_3_LIOINTC_IRQn,
  ADC_LIOINTC_IRQn,
  HPET0_LIOINTC_IRQn,
  HPET1_LIOINTC_IRQn,
  HPET2_LIOINTC_IRQn,
  HPET3_LIOINTC_IRQn,
  APB_DMA0_LIOINTC_IRQn,
  APB_DMA1_LIOINTC_IRQn,
  APB_DMA2_LIOINTC_IRQn,
  APB_DMA3_LIOINTC_IRQn,
  APB_DMA4_LIOINTC_IRQn,
  APB_DMA5_LIOINTC_IRQn,
  APB_DMA6_LIOINTC_IRQn,
  APB_DMA7_LIOINTC_IRQn,
  SDIO0_CTRL_LIOINTC_IRQn,
  SDIO1_CTRL_LIOINTC_IRQn,
  SDIO0_DMA_LIOINTC_IRQn,
  SDIO1_DMA_LIOINTC_IRQn,
  ENCRYPT_DMA_LIOINTC_IRQn,
  AES_LIOINTC_IRQn,
  DES_LIOINTC_IRQn,
  SM3_LIOINTC_IRQn,
  SM4_LIOINTC_IRQn,
  RTC_INT_LIOINTC_IRQn,
  TOY_INT_LIOINTC_IRQn,
  RTC_TICK_LIOINTC_IRQn,
  TOY_TICK_LIOINTC_IRQn,
  SPI0_LIOINTC_IRQn,
  SPI1_LIOINTC_IRQn,
  EHCI_LIOINTC_IRQn,
  OHCI_LIOINTC_IRQn,
  OTG_LIOINTC_IRQn,
  GMAC0_LIOINTC_IRQn,
  GMAC1_LIOINTC_IRQn,
  DC_LIOINTC_IRQn,
  THSENS_LIOINTC_IRQn,
  GPIO00_15_LIOINTC_IRQn,
  GPIO16_31_LIOINTC_IRQn,
  GPIO32_47_LIOINTC_IRQn,
  GPIO48_63_LIOINTC_IRQn,
  GPIO64_79_LIOINTC_IRQn,
  GPIO80_95_LIOINTC_IRQn,
  GPIO96_105_LIOINTC_IRQn,

  DDR_ECC0_LIOINTC_IRQn = 61,
  DDR_ECC1_LIOINTC_IRQn,

} LIOINTC_IRQn_Type;

/**
  * @}
  */

#include "core_la264.h"
#include "system_ls2k03xx.h"
#include <stdint.h>

/** @addtogroup Peripheral_registers_structures
  * @{
  */

/** 
  * @brief Analog to Digital Converter
  */

typedef struct
{
  __IO uint32_t SR;
  __IO uint32_t CR1;
  __IO uint32_t CR2;
  __IO uint32_t SMPR1;
  __IO uint32_t SMPR2;
  __IO uint32_t JOFR1;
  __IO uint32_t JOFR2;
  __IO uint32_t JOFR3;
  __IO uint32_t JOFR4;
  __IO uint32_t HTR;
  __IO uint32_t LTR;
  __IO uint32_t SQR1;
  __IO uint32_t SQR2;
  __IO uint32_t SQR3;
  __IO uint32_t JSQR;
  __IO uint32_t JDR1;
  __IO uint32_t JDR2;
  __IO uint32_t JDR3;
  __IO uint32_t JDR4;
  __IO uint32_t DR;
} ADC_TypeDef;

/** 
  * @brief DMA Controller
  */

typedef struct
{
  __IO uint32_t CCR;
  __IO uint32_t CNDTR;
  __IO uint32_t CPAR;
  __IO uint32_t CMAR;
} DMA_Channel_TypeDef;

/** 
  * @brief
  */

typedef struct
{
  __IO uint32_t ISR;
  __IO uint32_t IFCR;
} DMA_TypeDef;

/** 
  * @brief GPIO Registers in bit access mode
  */

typedef struct
{
  __IO uint32_t OEN[4];
  __IO uint32_t O[4];
  __IO uint32_t I[4];
  __IO uint32_t INT_EN[4];
  __IO uint32_t INT_POL[4];
  __IO uint32_t INT_EDGE[4];
  __IO uint32_t INT_CLR[4];
  __IO uint32_t INT_DUAL[4];
} GPIO_BIT_TypeDef;

/** 
  * @brief GPIO Registers in byte access mode
  */

typedef struct
{
  __IO uint8_t OEN[106];
  __IO uint8_t RESERVED0[150];
  __IO uint8_t O[106];
  __IO uint8_t RESERVED1[150];
  __IO uint8_t I[106];
  __IO uint8_t RESERVED2[150];
  __IO uint8_t INT_EN[106];
  __IO uint8_t RESERVED3[150];
  __IO uint8_t INT_POL[106];
  __IO uint8_t RESERVED4[150];
  __IO uint8_t INT_EDGE[106];
  __IO uint8_t RESERVED5[150];
  __IO uint8_t INT_CLR[106];
  __IO uint8_t RESERVED6[150];
  __IO uint8_t INT_DUAL[106];
} GPIO_BYTE_TypeDef;

/** 
  * @brief GPIO pin control Registers
  */

typedef struct
{
  __IO uint32_t MUX[7];
} GPIO_MUX_TypeDef;

/** 
  * @brief Inter Integrated Circuit Interface
  */

typedef struct
{
  __IO uint32_t CR1;
  __IO uint32_t CR2;
  __IO uint32_t OAR1;
  __IO uint32_t RESERVED;
  __IO uint32_t DR;
  __IO uint32_t SR1;
  __IO uint32_t SR2;
  __IO uint32_t CCR;
  __IO uint32_t TRISE;
} I2C_TypeDef;

/** 
  * @brief
  */
typedef struct
{
  __IO uint8_t ENTRY[32];
  __IO uint32_t ISR;
  __IO uint32_t EN;
  __IO uint32_t ENSET;
  __IO uint32_t ENCLR;
  __IO uint32_t POL;
  __IO uint32_t EDGE;
} LIOINTC_TypeDef;

/** 
  * @brief
  */
typedef struct
{
  __IO uint32_t CORE_INTISR;
  __IO uint32_t INTISR;
} LIOINTC_COREISR_TypeDef;

/** 
  * @brief
  */

typedef struct
{
  __IO uint32_t RESERVED;
  __IO uint32_t Low_buffer;
  __IO uint32_t Full_buffer;
  __IO uint32_t CTRL;
} PWM_TypeDef;

/** 
  * @brief
  */

typedef struct
{
  __IO uint32_t RESERVED[8];
  __IO uint32_t TOYTRIM;
  __IO uint32_t TOYWRITE0;
  __IO uint32_t TOYWRITE1;
  __IO uint32_t TOYREAD0;
  __IO uint32_t TOYREAD1;
  __IO uint32_t TOYMATCH0;
  __IO uint32_t TOYMATCH1;
  __IO uint32_t TOYMATCH2;
  __IO uint32_t RCCCTL;
  __IO uint32_t RCCTRIM;
  __IO uint32_t RCCWRITE0;
  __IO uint32_t RCCREAD0;
  __IO uint32_t RCCMATCH0;
  __IO uint32_t RCCMATCH1;
  __IO uint32_t RCCMATCH2;
} RTC_TypeDef;

/** 
  * @brief Serial Peripheral Interface
  */

typedef struct
{
  __IO uint8_t SPCR;
  __IO uint8_t SPSR;
  __IO uint8_t FIFO;
  __IO uint8_t SPER;
  __IO uint8_t SFC_PARAM;
  __IO uint8_t SFC_SOFTCS;
  __IO uint8_t SFC_TIMING;
} SPI_FLASH_TypeDef;

/** 
  * @brief Serial Peripheral Interface
  */

typedef struct
{
  __IO uint32_t CR1;
  __IO uint32_t CR2;
  __IO uint32_t CR3;
  __IO uint32_t CR4;
  __IO uint32_t IER;
  __IO uint32_t SR1;
  __IO uint32_t SR2;
  __IO uint32_t RESERVED0;
  __IO uint32_t CFG1;
  __IO uint32_t CFG2;
  __IO uint32_t CFG3;
  __IO uint32_t RESERVED1;
  __IO uint32_t CRC1;
  __IO uint32_t CRC2;
  __IO uint32_t RESERVED2[2];
  __IO uint32_t DR;
} SPI_IO_TypeDef;

/** 
  * @brief TIM Timers
  */

typedef struct
{
  __IO uint32_t CR1;             /*!< TIM control register 1,                      Address offset: 0x00 */
  __IO uint32_t CR2;             /*!< TIM control register 2,                      Address offset: 0x04 */
  __IO uint32_t SMCR;            /*!< TIM slave Mode Control register,             Address offset: 0x08 */
  __IO uint32_t DIER;            /*!< TIM DMA/interrupt enable register,           Address offset: 0x0C */
  __IO uint32_t SR;              /*!< TIM status register,                         Address offset: 0x10 */
  __IO uint32_t EGR;             /*!< TIM event generation register,               Address offset: 0x14 */
  __IO uint32_t CCMR1;           /*!< TIM  capture/compare mode register 1,        Address offset: 0x18 */
  __IO uint32_t CCMR2;           /*!< TIM  capture/compare mode register 2,        Address offset: 0x1C */
  __IO uint32_t CCER;            /*!< TIM capture/compare enable register,         Address offset: 0x20 */
  __IO uint32_t CNT;             /*!< TIM counter register,                        Address offset: 0x24 */
  __IO uint32_t PSC;             /*!< TIM prescaler register,                      Address offset: 0x28 */
  __IO uint32_t ARR;             /*!< TIM auto-reload register,                    Address offset: 0x2C */
  __IO uint32_t RCR;             /*!< TIM  repetition counter register,            Address offset: 0x30 */
  __IO uint32_t CCR1;            /*!< TIM capture/compare register 1,              Address offset: 0x34 */
  __IO uint32_t CCR2;            /*!< TIM capture/compare register 2,              Address offset: 0x38 */
  __IO uint32_t CCR3;            /*!< TIM capture/compare register 3,              Address offset: 0x3C */
  __IO uint32_t CCR4;            /*!< TIM capture/compare register 4,              Address offset: 0x40 */
  __IO uint32_t BDTR;            /*!< TIM break and dead-time register,            Address offset: 0x44 */
  __IO uint32_t RESERVED[2];
  __IO uint32_t INSTA;
} TIM_TypeDef;

/** 
  * @brief Universal Asynchronous Receiver Transmitter (16550A-like)
  */

typedef struct
{
  __IO uint8_t DAT;
  __IO uint8_t IER;
  __IO uint8_t FCR;
  __IO uint8_t LCR;
  __IO uint8_t MCR;
  __IO uint8_t LSR;
  __IO uint8_t MSR;
} UART_TypeDef;

/**
  * @}
  */

/** @addtogroup Peripheral_memory_map
  * @{
  */

#define PERIPH_BASE           0x8000000000000000

/*!< Peripheral memory map */
#define PWM_BASE              (PERIPH_BASE + 0x1611b000)
#define PWM0_BASE             (PWM_BASE + 0x00)
#define PWM1_BASE             (PWM_BASE + 0x10)
#define PWM2_BASE             (PWM_BASE + 0x20)
#define PWM3_BASE             (PWM_BASE + 0x30)

#define ADC_BASE              (PERIPH_BASE + 0x1611c000)

#define DMA_BASE              (PERIPH_BASE + 0x1612c000)
#define DMA_Channel0_BASE     (DMA_BASE + 0x08 + 0x14 * 0)
#define DMA_Channel1_BASE     (DMA_BASE + 0x08 + 0x14 * 1)
#define DMA_Channel2_BASE     (DMA_BASE + 0x08 + 0x14 * 2)
#define DMA_Channel3_BASE     (DMA_BASE + 0x08 + 0x14 * 3)
#define DMA_Channel4_BASE     (DMA_BASE + 0x08 + 0x14 * 4)
#define DMA_Channel5_BASE     (DMA_BASE + 0x08 + 0x14 * 5)
#define DMA_Channel6_BASE     (DMA_BASE + 0x08 + 0x14 * 6)
#define DMA_Channel7_BASE     (DMA_BASE + 0x08 + 0x14 * 7)

#define GPIO_BASE             (PERIPH_BASE + 0x16104000)
#define GPIO_BIT_BASE         (GPIO_BASE + 0x000)
#define GPIO_BYTE_BASE        (GPIO_BASE + 0x800)
#define GPIO_MUX_BASE         (PERIPH_BASE + 0x16000490)

#define I2C_BASE              (PERIPH_BASE + 0x16108000)
#define I2C0_BASE             (I2C_BASE + 0x0000)
#define I2C1_BASE             (I2C_BASE + 0x1000)
#define I2C2_BASE             (I2C_BASE + 0x2000)
#define I2C3_BASE             (I2C_BASE + 0x3000)

#define LIOINTC_BASE          (PERIPH_BASE + 0x16001400)
#define LIOINTC0_BASE         (LIOINTC_BASE + 0x00)
#define LIOINTC1_BASE         (LIOINTC_BASE + 0x40)
#define LIOINTC_COREISR_BASE  (PERIPH_BASE + 0x16001040)
#define LIOINTC0_COREISR_BASE (LIOINTC_COREISR_BASE + 0x00)
#define LIOINTC1_COREISR_BASE (LIOINTC_COREISR_BASE + 0x08)

#define RTC_BASE              (PERIPH_BASE + 0x16128000)

#define SPI_FLASE_BASE        (PERIPH_BASE + 0x16010000)
#define SPI0_BASE             (SPI_FLASE_BASE + 0x0000)
#define SPI1_BASE             (SPI_FLASE_BASE + 0x8000)

#define SPI_IO_BASE           (PERIPH_BASE + 0x1610c000)
#define SPI2_BASE             (SPI_IO_BASE + 0x0000)
#define SPI3_BASE             (SPI_IO_BASE + 0x2000)

#define ATIM_BASE             (PERIPH_BASE + 0x16118000)
#define GTIM_BASE             (SPI_IO_BASE + 0x16119000)
#define BTIM_BASE             (SPI_IO_BASE + 0x1611a000)

#define UART_BASE             (PERIPH_BASE + 0x16100000)
#define UART0_BASE            (UART_BASE + 0x400 * 0)
#define UART1_BASE            (UART_BASE + 0x400 * 1)
#define UART2_BASE            (UART_BASE + 0x400 * 2)
#define UART3_BASE            (UART_BASE + 0x400 * 3)
#define UART4_BASE            (UART_BASE + 0x400 * 4)
#define UART5_BASE            (UART_BASE + 0x400 * 5)
#define UART6_BASE            (UART_BASE + 0x400 * 6)
#define UART7_BASE            (UART_BASE + 0x400 * 7)
#define UART8_BASE            (UART_BASE + 0x400 * 8)
#define UART9_BASE            (UART_BASE + 0x400 * 9)

/**
  * @}
  */

/** @addtogroup Peripheral_declaration
  * @{
  */

#define PWM0                  ((PWM_TypeDef *)PWM0_BASE)
#define PWM1                  ((PWM_TypeDef *)PWM1_BASE)
#define PWM2                  ((PWM_TypeDef *)PWM2_BASE)
#define PWM3                  ((PWM_TypeDef *)PWM3_BASE)

#define ADC                   ((ADC_TypeDef *)ADC_BASE)

#define DMA                   ((DMA_TypeDef *)DMA_BASE)
#define DMA_Channel0          ((DMA_Channel_TypeDef *)DMA_Channel0_BASE)
#define DMA_Channel1          ((DMA_Channel_TypeDef *)DMA_Channel1_BASE)
#define DMA_Channel2          ((DMA_Channel_TypeDef *)DMA_Channel2_BASE)
#define DMA_Channel3          ((DMA_Channel_TypeDef *)DMA_Channel3_BASE)
#define DMA_Channel4          ((DMA_Channel_TypeDef *)DMA_Channel4_BASE)
#define DMA_Channel5          ((DMA_Channel_TypeDef *)DMA_Channel5_BASE)
#define DMA_Channel6          ((DMA_Channel_TypeDef *)DMA_Channel6_BASE)
#define DMA_Channel7          ((DMA_Channel_TypeDef *)DMA_Channel7_BASE)

#define GPIO_BIT              ((GPIO_BIT_TypeDef *)GPIO_BIT_BASE)
#define GPIO_BYTE             ((GPIO_BYTE_TypeDef *)GPIO_BYTE_BASE)
#define GPIO_MUX              ((GPIO_MUX_TypeDef *)GPIO_MUX_BASE)

#define I2C0                  ((I2C_TypeDef *)I2C0_BASE)
#define I2C1                  ((I2C_TypeDef *)I2C1_BASE)
#define I2C2                  ((I2C_TypeDef *)I2C2_BASE)
#define I2C3                  ((I2C_TypeDef *)I2C3_BASE)

#define LIOINTC0              ((LIOINTC_TypeDef *)LIOINTC0_BASE)
#define LIOINTC1              ((LIOINTC_TypeDef *)LIOINTC1_BASE)

#define LIOINTC0_COREISR      ((LIOINTC_COREISR_TypeDef *)LIOINTC0_COREISR_BASE)
#define LIOINTC1_COREISR      ((LIOINTC_COREISR_TypeDef *)LIOINTC1_COREISR_BASE)

#define LIOINTC               ((LIOINTC_TypeDef *[2]){ LIOINTC0, LIOINTC1 })
#define LIOINTC_COREISR       ((LIOINTC_COREISR_TypeDef *[2]){ LIOINTC0_COREISR, LIOINTC1_COREISR })

#define RTC                   ((RTC_TypeDef *)RTC_BASE)

#define SPI0                  ((SPI_FLASH_TypeDef *)SPI0_BASE)
#define SPI1                  ((SPI_FLASH_TypeDef *)SPI1_BASE)

#define SPI2                  ((SPI_IO_TypeDef *)SPI2_BASE)
#define SPI3                  ((SPI_IO_TypeDef *)SPI3_BASE)

#define ATIM                  ((TIM_TypeDef *)ATIM_BASE)
#define GTIM                  ((TIM_TypeDef *)GTIM_BASE)
#define BTIM                  ((TIM_TypeDef *)BTIM_BASE)

#define UART0                 ((UART_TypeDef *)UART0_BASE)
#define UART1                 ((UART_TypeDef *)UART1_BASE)
#define UART2                 ((UART_TypeDef *)UART2_BASE)
#define UART3                 ((UART_TypeDef *)UART3_BASE)
#define UART4                 ((UART_TypeDef *)UART4_BASE)
#define UART5                 ((UART_TypeDef *)UART5_BASE)
#define UART6                 ((UART_TypeDef *)UART6_BASE)
#define UART7                 ((UART_TypeDef *)UART7_BASE)
#define UART8                 ((UART_TypeDef *)UART8_BASE)
#define UART9                 ((UART_TypeDef *)UART9_BASE)

/**
  * @}
  */

/** @addtogroup Exported_constants
  * @{
  */

/** @addtogroup Peripheral_Registers_Bits_Definition
  * @{
  */

/******************************************************************************/
/*                                                                            */
/*                             DMA Controller                                 */
/*                                                                            */
/******************************************************************************/

/*******************  Bit definition for DMA_ISR register  ********************/
#define DMA_ISR_GIF0_Pos                    (0U)
#define DMA_ISR_GIF0_Msk                    (0x1UL << DMA_ISR_GIF0_Pos)         /*!< 0x00000001 */
#define DMA_ISR_GIF0                        DMA_ISR_GIF0_Msk                   /*!< Channel 0 Global interrupt flag */
#define DMA_ISR_TCIF0_Pos                   (1U)
#define DMA_ISR_TCIF0_Msk                   (0x1UL << DMA_ISR_TCIF0_Pos)        /*!< 0x00000002 */
#define DMA_ISR_TCIF0                       DMA_ISR_TCIF0_Msk                  /*!< Channel 0 Transfer Complete flag */
#define DMA_ISR_HTIF0_Pos                   (2U)
#define DMA_ISR_HTIF0_Msk                   (0x1UL << DMA_ISR_HTIF0_Pos)        /*!< 0x00000004 */
#define DMA_ISR_HTIF0                       DMA_ISR_HTIF0_Msk                  /*!< Channel 0 Half Transfer flag */
#define DMA_ISR_TEIF0_Pos                   (3U)
#define DMA_ISR_TEIF0_Msk                   (0x1UL << DMA_ISR_TEIF0_Pos)        /*!< 0x00000008 */
#define DMA_ISR_TEIF0                       DMA_ISR_TEIF0_Msk                  /*!< Channel 0 Transfer Error flag */
#define DMA_ISR_GIF1_Pos                    (4U)
#define DMA_ISR_GIF1_Msk                    (0x1UL << DMA_ISR_GIF1_Pos)         /*!< 0x00000010 */
#define DMA_ISR_GIF1                        DMA_ISR_GIF1_Msk                   /*!< Channel 1 Global interrupt flag */
#define DMA_ISR_TCIF1_Pos                   (5U)
#define DMA_ISR_TCIF1_Msk                   (0x1UL << DMA_ISR_TCIF1_Pos)        /*!< 0x00000020 */
#define DMA_ISR_TCIF1                       DMA_ISR_TCIF1_Msk                  /*!< Channel 1 Transfer Complete flag */
#define DMA_ISR_HTIF1_Pos                   (6U)
#define DMA_ISR_HTIF1_Msk                   (0x1UL << DMA_ISR_HTIF1_Pos)        /*!< 0x00000040 */
#define DMA_ISR_HTIF1                       DMA_ISR_HTIF1_Msk                  /*!< Channel 1 Half Transfer flag */
#define DMA_ISR_TEIF1_Pos                   (7U)
#define DMA_ISR_TEIF1_Msk                   (0x1UL << DMA_ISR_TEIF1_Pos)        /*!< 0x00000080 */
#define DMA_ISR_TEIF1                       DMA_ISR_TEIF1_Msk                  /*!< Channel 1 Transfer Error flag */
#define DMA_ISR_GIF2_Pos                    (8U)
#define DMA_ISR_GIF2_Msk                    (0x1UL << DMA_ISR_GIF2_Pos)         /*!< 0x00000100 */
#define DMA_ISR_GIF2                        DMA_ISR_GIF2_Msk                   /*!< Channel 2 Global interrupt flag */
#define DMA_ISR_TCIF2_Pos                   (9U)
#define DMA_ISR_TCIF2_Msk                   (0x1UL << DMA_ISR_TCIF2_Pos)        /*!< 0x00000200 */
#define DMA_ISR_TCIF2                       DMA_ISR_TCIF2_Msk                  /*!< Channel 2 Transfer Complete flag */
#define DMA_ISR_HTIF2_Pos                   (10U)
#define DMA_ISR_HTIF2_Msk                   (0x1UL << DMA_ISR_HTIF2_Pos)        /*!< 0x00000400 */
#define DMA_ISR_HTIF2                       DMA_ISR_HTIF2_Msk                  /*!< Channel 2 Half Transfer flag */
#define DMA_ISR_TEIF2_Pos                   (11U)
#define DMA_ISR_TEIF2_Msk                   (0x1UL << DMA_ISR_TEIF2_Pos)        /*!< 0x00000800 */
#define DMA_ISR_TEIF2                       DMA_ISR_TEIF2_Msk                  /*!< Channel 2 Transfer Error flag */
#define DMA_ISR_GIF3_Pos                    (12U)
#define DMA_ISR_GIF3_Msk                    (0x1UL << DMA_ISR_GIF3_Pos)         /*!< 0x00001000 */
#define DMA_ISR_GIF3                        DMA_ISR_GIF3_Msk                   /*!< Channel 3 Global interrupt flag */
#define DMA_ISR_TCIF3_Pos                   (13U)
#define DMA_ISR_TCIF3_Msk                   (0x1UL << DMA_ISR_TCIF3_Pos)        /*!< 0x00002000 */
#define DMA_ISR_TCIF3                       DMA_ISR_TCIF3_Msk                  /*!< Channel 3 Transfer Complete flag */
#define DMA_ISR_HTIF3_Pos                   (14U)
#define DMA_ISR_HTIF3_Msk                   (0x1UL << DMA_ISR_HTIF3_Pos)        /*!< 0x00004000 */
#define DMA_ISR_HTIF3                       DMA_ISR_HTIF3_Msk                  /*!< Channel 3 Half Transfer flag */
#define DMA_ISR_TEIF3_Pos                   (15U)
#define DMA_ISR_TEIF3_Msk                   (0x1UL << DMA_ISR_TEIF3_Pos)        /*!< 0x00008000 */
#define DMA_ISR_TEIF3                       DMA_ISR_TEIF3_Msk                  /*!< Channel 3 Transfer Error flag */
#define DMA_ISR_GIF4_Pos                    (16U)
#define DMA_ISR_GIF4_Msk                    (0x1UL << DMA_ISR_GIF4_Pos)         /*!< 0x00010000 */
#define DMA_ISR_GIF4                        DMA_ISR_GIF4_Msk                   /*!< Channel 4 Global interrupt flag */
#define DMA_ISR_TCIF4_Pos                   (17U)
#define DMA_ISR_TCIF4_Msk                   (0x1UL << DMA_ISR_TCIF4_Pos)        /*!< 0x00020000 */
#define DMA_ISR_TCIF4                       DMA_ISR_TCIF4_Msk                  /*!< Channel 4 Transfer Complete flag */
#define DMA_ISR_HTIF4_Pos                   (18U)
#define DMA_ISR_HTIF4_Msk                   (0x1UL << DMA_ISR_HTIF4_Pos)        /*!< 0x00040000 */
#define DMA_ISR_HTIF4                       DMA_ISR_HTIF4_Msk                  /*!< Channel 4 Half Transfer flag */
#define DMA_ISR_TEIF4_Pos                   (19U)
#define DMA_ISR_TEIF4_Msk                   (0x1UL << DMA_ISR_TEIF4_Pos)        /*!< 0x00080000 */
#define DMA_ISR_TEIF4                       DMA_ISR_TEIF4_Msk                  /*!< Channel 4 Transfer Error flag */
#define DMA_ISR_GIF5_Pos                    (20U)
#define DMA_ISR_GIF5_Msk                    (0x1UL << DMA_ISR_GIF5_Pos)         /*!< 0x00100000 */
#define DMA_ISR_GIF5                        DMA_ISR_GIF5_Msk                   /*!< Channel 5 Global interrupt flag */
#define DMA_ISR_TCIF5_Pos                   (21U)
#define DMA_ISR_TCIF5_Msk                   (0x1UL << DMA_ISR_TCIF5_Pos)        /*!< 0x00200000 */
#define DMA_ISR_TCIF5                       DMA_ISR_TCIF5_Msk                  /*!< Channel 5 Transfer Complete flag */
#define DMA_ISR_HTIF5_Pos                   (22U)
#define DMA_ISR_HTIF5_Msk                   (0x1UL << DMA_ISR_HTIF5_Pos)        /*!< 0x00400000 */
#define DMA_ISR_HTIF5                       DMA_ISR_HTIF5_Msk                  /*!< Channel 5 Half Transfer flag */
#define DMA_ISR_TEIF5_Pos                   (23U)
#define DMA_ISR_TEIF5_Msk                   (0x1UL << DMA_ISR_TEIF5_Pos)        /*!< 0x00800000 */
#define DMA_ISR_TEIF5                       DMA_ISR_TEIF5_Msk                  /*!< Channel 5 Transfer Error flag */
#define DMA_ISR_GIF6_Pos                    (24U)
#define DMA_ISR_GIF6_Msk                    (0x1UL << DMA_ISR_GIF6_Pos)         /*!< 0x01000000 */
#define DMA_ISR_GIF6                        DMA_ISR_GIF6_Msk                   /*!< Channel 6 Global interrupt flag */
#define DMA_ISR_TCIF6_Pos                   (25U)
#define DMA_ISR_TCIF6_Msk                   (0x1UL << DMA_ISR_TCIF6_Pos)        /*!< 0x02000000 */
#define DMA_ISR_TCIF6                       DMA_ISR_TCIF6_Msk                  /*!< Channel 6 Transfer Complete flag */
#define DMA_ISR_HTIF6_Pos                   (26U)
#define DMA_ISR_HTIF6_Msk                   (0x1UL << DMA_ISR_HTIF6_Pos)        /*!< 0x04000000 */
#define DMA_ISR_HTIF6                       DMA_ISR_HTIF6_Msk                  /*!< Channel 6 Half Transfer flag */
#define DMA_ISR_TEIF6_Pos                   (27U)
#define DMA_ISR_TEIF6_Msk                   (0x1UL << DMA_ISR_TEIF6_Pos)        /*!< 0x08000000 */
#define DMA_ISR_TEIF6                       DMA_ISR_TEIF6_Msk                  /*!< Channel 6 Transfer Error flag */
#define DMA_ISR_GIF7_Pos                    (28U)
#define DMA_ISR_GIF7_Msk                    (0x1UL << DMA_ISR_GIF7_Pos)         /*!< 0x10000000 */
#define DMA_ISR_GIF7                        DMA_ISR_GIF7_Msk                   /*!< Channel 7 Global interrupt flag */
#define DMA_ISR_TCIF7_Pos                   (29U)
#define DMA_ISR_TCIF7_Msk                   (0x1UL << DMA_ISR_TCIF7_Pos)        /*!< 0x20000000 */
#define DMA_ISR_TCIF7                       DMA_ISR_TCIF7_Msk                  /*!< Channel 7 Transfer Complete flag */
#define DMA_ISR_HTIF7_Pos                   (30U)
#define DMA_ISR_HTIF7_Msk                   (0x1UL << DMA_ISR_HTIF7_Pos)        /*!< 0x40000000 */
#define DMA_ISR_HTIF7                       DMA_ISR_HTIF7_Msk                  /*!< Channel 7 Half Transfer flag */
#define DMA_ISR_TEIF7_Pos                   (31U)
#define DMA_ISR_TEIF7_Msk                   (0x1UL << DMA_ISR_TEIF7_Pos)        /*!< 0x80000000 */
#define DMA_ISR_TEIF7                       DMA_ISR_TEIF7_Msk                  /*!< Channel 7 Transfer Error flag */

/*******************  Bit definition for DMA_IFCR register  *******************/
#define DMA_IFCR_CGIF0_Pos                  (0U)
#define DMA_IFCR_CGIF0_Msk                  (0x1UL << DMA_IFCR_CGIF0_Pos)       /*!< 0x00000001 */
#define DMA_IFCR_CGIF0                      DMA_IFCR_CGIF0_Msk                 /*!< Channel 0 Global interrupt clear */
#define DMA_IFCR_CTCIF0_Pos                 (1U)
#define DMA_IFCR_CTCIF0_Msk                 (0x1UL << DMA_IFCR_CTCIF0_Pos)      /*!< 0x00000002 */
#define DMA_IFCR_CTCIF0                     DMA_IFCR_CTCIF0_Msk                /*!< Channel 0 Transfer Complete clear */
#define DMA_IFCR_CHTIF0_Pos                 (2U)
#define DMA_IFCR_CHTIF0_Msk                 (0x1UL << DMA_IFCR_CHTIF0_Pos)      /*!< 0x00000004 */
#define DMA_IFCR_CHTIF0                     DMA_IFCR_CHTIF0_Msk                /*!< Channel 0 Half Transfer clear */
#define DMA_IFCR_CTEIF0_Pos                 (3U)
#define DMA_IFCR_CTEIF0_Msk                 (0x1UL << DMA_IFCR_CTEIF0_Pos)      /*!< 0x00000008 */
#define DMA_IFCR_CTEIF0                     DMA_IFCR_CTEIF0_Msk                /*!< Channel 0 Transfer Error clear */
#define DMA_IFCR_CGIF1_Pos                  (4U)
#define DMA_IFCR_CGIF1_Msk                  (0x1UL << DMA_IFCR_CGIF1_Pos)       /*!< 0x00000010 */
#define DMA_IFCR_CGIF1                      DMA_IFCR_CGIF1_Msk                 /*!< Channel 1 Global interrupt clear */
#define DMA_IFCR_CTCIF1_Pos                 (5U)
#define DMA_IFCR_CTCIF1_Msk                 (0x1UL << DMA_IFCR_CTCIF1_Pos)      /*!< 0x00000020 */
#define DMA_IFCR_CTCIF1                     DMA_IFCR_CTCIF1_Msk                /*!< Channel 1 Transfer Complete clear */
#define DMA_IFCR_CHTIF1_Pos                 (6U)
#define DMA_IFCR_CHTIF1_Msk                 (0x1UL << DMA_IFCR_CHTIF1_Pos)      /*!< 0x00000040 */
#define DMA_IFCR_CHTIF1                     DMA_IFCR_CHTIF1_Msk                /*!< Channel 1 Half Transfer clear */
#define DMA_IFCR_CTEIF1_Pos                 (7U)
#define DMA_IFCR_CTEIF1_Msk                 (0x1UL << DMA_IFCR_CTEIF1_Pos)      /*!< 0x00000080 */
#define DMA_IFCR_CTEIF1                     DMA_IFCR_CTEIF1_Msk                /*!< Channel 1 Transfer Error clear */
#define DMA_IFCR_CGIF2_Pos                  (8U)
#define DMA_IFCR_CGIF2_Msk                  (0x1UL << DMA_IFCR_CGIF2_Pos)       /*!< 0x00000100 */
#define DMA_IFCR_CGIF2                      DMA_IFCR_CGIF2_Msk                 /*!< Channel 2 Global interrupt clear */
#define DMA_IFCR_CTCIF2_Pos                 (9U)
#define DMA_IFCR_CTCIF2_Msk                 (0x1UL << DMA_IFCR_CTCIF2_Pos)      /*!< 0x00000200 */
#define DMA_IFCR_CTCIF2                     DMA_IFCR_CTCIF2_Msk                /*!< Channel 2 Transfer Complete clear */
#define DMA_IFCR_CHTIF2_Pos                 (10U)
#define DMA_IFCR_CHTIF2_Msk                 (0x1UL << DMA_IFCR_CHTIF2_Pos)      /*!< 0x00000400 */
#define DMA_IFCR_CHTIF2                     DMA_IFCR_CHTIF2_Msk                /*!< Channel 2 Half Transfer clear */
#define DMA_IFCR_CTEIF2_Pos                 (11U)
#define DMA_IFCR_CTEIF2_Msk                 (0x1UL << DMA_IFCR_CTEIF2_Pos)      /*!< 0x00000800 */
#define DMA_IFCR_CTEIF2                     DMA_IFCR_CTEIF2_Msk                /*!< Channel 2 Transfer Error clear */
#define DMA_IFCR_CGIF3_Pos                  (12U)
#define DMA_IFCR_CGIF3_Msk                  (0x1UL << DMA_IFCR_CGIF3_Pos)       /*!< 0x00001000 */
#define DMA_IFCR_CGIF3                      DMA_IFCR_CGIF3_Msk                 /*!< Channel 3 Global interrupt clear */
#define DMA_IFCR_CTCIF3_Pos                 (13U)
#define DMA_IFCR_CTCIF3_Msk                 (0x1UL << DMA_IFCR_CTCIF3_Pos)      /*!< 0x00002000 */
#define DMA_IFCR_CTCIF3                     DMA_IFCR_CTCIF3_Msk                /*!< Channel 3 Transfer Complete clear */
#define DMA_IFCR_CHTIF3_Pos                 (14U)
#define DMA_IFCR_CHTIF3_Msk                 (0x1UL << DMA_IFCR_CHTIF3_Pos)      /*!< 0x00004000 */
#define DMA_IFCR_CHTIF3                     DMA_IFCR_CHTIF3_Msk                /*!< Channel 3 Half Transfer clear */
#define DMA_IFCR_CTEIF3_Pos                 (15U)
#define DMA_IFCR_CTEIF3_Msk                 (0x1UL << DMA_IFCR_CTEIF3_Pos)      /*!< 0x00008000 */
#define DMA_IFCR_CTEIF3                     DMA_IFCR_CTEIF3_Msk                /*!< Channel 3 Transfer Error clear */
#define DMA_IFCR_CGIF4_Pos                  (16U)
#define DMA_IFCR_CGIF4_Msk                  (0x1UL << DMA_IFCR_CGIF4_Pos)       /*!< 0x00010000 */
#define DMA_IFCR_CGIF4                      DMA_IFCR_CGIF4_Msk                 /*!< Channel 4 Global interrupt clear */
#define DMA_IFCR_CTCIF4_Pos                 (17U)
#define DMA_IFCR_CTCIF4_Msk                 (0x1UL << DMA_IFCR_CTCIF4_Pos)      /*!< 0x00020000 */
#define DMA_IFCR_CTCIF4                     DMA_IFCR_CTCIF4_Msk                /*!< Channel 4 Transfer Complete clear */
#define DMA_IFCR_CHTIF4_Pos                 (18U)
#define DMA_IFCR_CHTIF4_Msk                 (0x1UL << DMA_IFCR_CHTIF4_Pos)      /*!< 0x00040000 */
#define DMA_IFCR_CHTIF4                     DMA_IFCR_CHTIF4_Msk                /*!< Channel 4 Half Transfer clear */
#define DMA_IFCR_CTEIF4_Pos                 (19U)
#define DMA_IFCR_CTEIF4_Msk                 (0x1UL << DMA_IFCR_CTEIF4_Pos)      /*!< 0x00080000 */
#define DMA_IFCR_CTEIF4                     DMA_IFCR_CTEIF4_Msk                /*!< Channel 4 Transfer Error clear */
#define DMA_IFCR_CGIF5_Pos                  (20U)
#define DMA_IFCR_CGIF5_Msk                  (0x1UL << DMA_IFCR_CGIF5_Pos)       /*!< 0x00100000 */
#define DMA_IFCR_CGIF5                      DMA_IFCR_CGIF5_Msk                 /*!< Channel 5 Global interrupt clear */
#define DMA_IFCR_CTCIF5_Pos                 (21U)
#define DMA_IFCR_CTCIF5_Msk                 (0x1UL << DMA_IFCR_CTCIF5_Pos)      /*!< 0x00200000 */
#define DMA_IFCR_CTCIF5                     DMA_IFCR_CTCIF5_Msk                /*!< Channel 5 Transfer Complete clear */
#define DMA_IFCR_CHTIF5_Pos                 (22U)
#define DMA_IFCR_CHTIF5_Msk                 (0x1UL << DMA_IFCR_CHTIF5_Pos)      /*!< 0x00400000 */
#define DMA_IFCR_CHTIF5                     DMA_IFCR_CHTIF5_Msk                /*!< Channel 5 Half Transfer clear */
#define DMA_IFCR_CTEIF5_Pos                 (23U)
#define DMA_IFCR_CTEIF5_Msk                 (0x1UL << DMA_IFCR_CTEIF5_Pos)      /*!< 0x00800000 */
#define DMA_IFCR_CTEIF5                     DMA_IFCR_CTEIF5_Msk                /*!< Channel 5 Transfer Error clear */
#define DMA_IFCR_CGIF6_Pos                  (24U)
#define DMA_IFCR_CGIF6_Msk                  (0x1UL << DMA_IFCR_CGIF6_Pos)       /*!< 0x01000000 */
#define DMA_IFCR_CGIF6                      DMA_IFCR_CGIF6_Msk                 /*!< Channel 6 Global interrupt clear */
#define DMA_IFCR_CTCIF6_Pos                 (25U)
#define DMA_IFCR_CTCIF6_Msk                 (0x1UL << DMA_IFCR_CTCIF6_Pos)      /*!< 0x02000000 */
#define DMA_IFCR_CTCIF6                     DMA_IFCR_CTCIF6_Msk                /*!< Channel 6 Transfer Complete clear */
#define DMA_IFCR_CHTIF6_Pos                 (26U)
#define DMA_IFCR_CHTIF6_Msk                 (0x1UL << DMA_IFCR_CHTIF6_Pos)      /*!< 0x04000000 */
#define DMA_IFCR_CHTIF6                     DMA_IFCR_CHTIF6_Msk                /*!< Channel 6 Half Transfer clear */
#define DMA_IFCR_CTEIF6_Pos                 (27U)
#define DMA_IFCR_CTEIF6_Msk                 (0x1UL << DMA_IFCR_CTEIF6_Pos)      /*!< 0x08000000 */
#define DMA_IFCR_CTEIF6                     DMA_IFCR_CTEIF6_Msk                /*!< Channel 6 Transfer Error clear */
#define DMA_IFCR_CGIF7_Pos                  (28U)
#define DMA_IFCR_CGIF7_Msk                  (0x1UL << DMA_IFCR_CGIF7_Pos)       /*!< 0x10000000 */
#define DMA_IFCR_CGIF7                      DMA_IFCR_CGIF7_Msk                 /*!< Channel 7 Global interrupt clear */
#define DMA_IFCR_CTCIF7_Pos                 (29U)
#define DMA_IFCR_CTCIF7_Msk                 (0x1UL << DMA_IFCR_CTCIF7_Pos)      /*!< 0x20000000 */
#define DMA_IFCR_CTCIF7                     DMA_IFCR_CTCIF7_Msk                /*!< Channel 7 Transfer Complete clear */
#define DMA_IFCR_CHTIF7_Pos                 (30U)
#define DMA_IFCR_CHTIF7_Msk                 (0x1UL << DMA_IFCR_CHTIF7_Pos)      /*!< 0x40000000 */
#define DMA_IFCR_CHTIF7                     DMA_IFCR_CHTIF7_Msk                /*!< Channel 7 Half Transfer clear */
#define DMA_IFCR_CTEIF7_Pos                 (31U)
#define DMA_IFCR_CTEIF7_Msk                 (0x1UL << DMA_IFCR_CTEIF7_Pos)      /*!< 0x80000000 */
#define DMA_IFCR_CTEIF7                     DMA_IFCR_CTEIF7_Msk                /*!< Channel 7 Transfer Error clear */

/*******************  Bit definition for DMA_CCR register   *******************/
#define DMA_CCR_EN_Pos                      (0U)                               
#define DMA_CCR_EN_Msk                      (0x1UL << DMA_CCR_EN_Pos)           /*!< 0x00000001 */
#define DMA_CCR_EN                          DMA_CCR_EN_Msk                     /*!< Channel enable */
#define DMA_CCR_TCIE_Pos                    (1U)                               
#define DMA_CCR_TCIE_Msk                    (0x1UL << DMA_CCR_TCIE_Pos)         /*!< 0x00000002 */
#define DMA_CCR_TCIE                        DMA_CCR_TCIE_Msk                   /*!< Transfer complete interrupt enable */
#define DMA_CCR_HTIE_Pos                    (2U)                               
#define DMA_CCR_HTIE_Msk                    (0x1UL << DMA_CCR_HTIE_Pos)         /*!< 0x00000004 */
#define DMA_CCR_HTIE                        DMA_CCR_HTIE_Msk                   /*!< Half Transfer interrupt enable */
#define DMA_CCR_TEIE_Pos                    (3U)                               
#define DMA_CCR_TEIE_Msk                    (0x1UL << DMA_CCR_TEIE_Pos)         /*!< 0x00000008 */
#define DMA_CCR_TEIE                        DMA_CCR_TEIE_Msk                   /*!< Transfer error interrupt enable */
#define DMA_CCR_DIR_Pos                     (4U)                               
#define DMA_CCR_DIR_Msk                     (0x1UL << DMA_CCR_DIR_Pos)          /*!< 0x00000010 */
#define DMA_CCR_DIR                         DMA_CCR_DIR_Msk                    /*!< Data transfer direction */
#define DMA_CCR_CIRC_Pos                    (5U)                               
#define DMA_CCR_CIRC_Msk                    (0x1UL << DMA_CCR_CIRC_Pos)         /*!< 0x00000020 */
#define DMA_CCR_CIRC                        DMA_CCR_CIRC_Msk                   /*!< Circular mode */
#define DMA_CCR_PINC_Pos                    (6U)                               
#define DMA_CCR_PINC_Msk                    (0x1UL << DMA_CCR_PINC_Pos)         /*!< 0x00000040 */
#define DMA_CCR_PINC                        DMA_CCR_PINC_Msk                   /*!< Peripheral increment mode */
#define DMA_CCR_MINC_Pos                    (7U)                               
#define DMA_CCR_MINC_Msk                    (0x1UL << DMA_CCR_MINC_Pos)         /*!< 0x00000080 */
#define DMA_CCR_MINC                        DMA_CCR_MINC_Msk                   /*!< Memory increment mode */

#define DMA_CCR_PSIZE_Pos                   (8U)                               
#define DMA_CCR_PSIZE_Msk                   (0x3UL << DMA_CCR_PSIZE_Pos)        /*!< 0x00000300 */
#define DMA_CCR_PSIZE                       DMA_CCR_PSIZE_Msk                  /*!< PSIZE[1:0] bits (Peripheral size) */
#define DMA_CCR_PSIZE_0                     (0x1UL << DMA_CCR_PSIZE_Pos)        /*!< 0x00000100 */
#define DMA_CCR_PSIZE_1                     (0x2UL << DMA_CCR_PSIZE_Pos)        /*!< 0x00000200 */

#define DMA_CCR_MSIZE_Pos                   (10U)                              
#define DMA_CCR_MSIZE_Msk                   (0x3UL << DMA_CCR_MSIZE_Pos)        /*!< 0x00000C00 */
#define DMA_CCR_MSIZE                       DMA_CCR_MSIZE_Msk                  /*!< MSIZE[1:0] bits (Memory size) */
#define DMA_CCR_MSIZE_0                     (0x1UL << DMA_CCR_MSIZE_Pos)        /*!< 0x00000400 */
#define DMA_CCR_MSIZE_1                     (0x2UL << DMA_CCR_MSIZE_Pos)        /*!< 0x00000800 */

#define DMA_CCR_PL_Pos                      (12U)                              
#define DMA_CCR_PL_Msk                      (0x3UL << DMA_CCR_PL_Pos)           /*!< 0x00003000 */
#define DMA_CCR_PL                          DMA_CCR_PL_Msk                     /*!< PL[1:0] bits(Channel Priority level) */
#define DMA_CCR_PL_0                        (0x1UL << DMA_CCR_PL_Pos)           /*!< 0x00001000 */
#define DMA_CCR_PL_1                        (0x2UL << DMA_CCR_PL_Pos)           /*!< 0x00002000 */

#define DMA_CCR_MEM2MEM_Pos                 (14U)                              
#define DMA_CCR_MEM2MEM_Msk                 (0x1UL << DMA_CCR_MEM2MEM_Pos)      /*!< 0x00004000 */
#define DMA_CCR_MEM2MEM                     DMA_CCR_MEM2MEM_Msk                /*!< Memory to memory mode */

/******************  Bit definition for DMA_CNDTR  register  ******************/
#define DMA_CNDTR_NDT_Pos                   (0U)                               
#define DMA_CNDTR_NDT_Msk                   (0xFFFFFFFFUL << DMA_CNDTR_NDT_Pos) /*!< 0xFFFFFFFF */
#define DMA_CNDTR_NDT                       DMA_CNDTR_NDT_Msk                  /*!< Number of data to Transfer */

/******************  Bit definition for DMA_CPAR  register  *******************/
#define DMA_CPAR_PA_Pos                     (0U)                               
#define DMA_CPAR_PA_Msk                     (0xFFFFFFFFUL << DMA_CPAR_PA_Pos)   /*!< 0xFFFFFFFF */
#define DMA_CPAR_PA                         DMA_CPAR_PA_Msk                    /*!< Peripheral Address */

/******************  Bit definition for DMA_CMAR  register  *******************/
#define DMA_CMAR_MA_Pos                     (0U)                               
#define DMA_CMAR_MA_Msk                     (0xFFFFFFFFUL << DMA_CMAR_MA_Pos)   /*!< 0xFFFFFFFF */
#define DMA_CMAR_MA                         DMA_CMAR_MA_Msk                    /*!< Memory Address */

/******************************************************************************/
/*                         Peripheral Registers_Bits_Definition               */
/******************************************************************************/

/******************************************************************************/
/*                                                                            */
/*                        Serial Peripheral Interface                         */
/*                                                                            */
/******************************************************************************/

/****************  Bit definition for SPI_FLASH_SPCR register  ****************/
#define SPI_FLASH_SPCR_SPR_POS              (0U)
#define SPI_FLASH_SPCR_SPR_Msk              (0x3UL << SPI_FLASH_SPCR_SPR_POS)   /*!< 0x00000003 */
#define SPI_FLASH_SPCR_SPR                  SPI_FLASH_SPCR_SPR_Msk
#define SPI_FLASH_SPCR_CPHA_POS             (2U)
#define SPI_FLASH_SPCR_CPHA_Msk             (0x1UL << SPI_FLASH_SPCR_CPHA_POS)  /*!< 0x00000004 */
#define SPI_FLASH_SPCR_CPHA                 SPI_FLASH_SPCR_CPHA_Msk            /*!< SPI Clock Phase */
#define SPI_FLASH_SPCR_CPOL_POS             (3U)
#define SPI_FLASH_SPCR_CPOL_Msk             (0x1UL << SPI_FLASH_SPCR_CPOL_POS)  /*!< 0x00000008 */
#define SPI_FLASH_SPCR_CPOL                 SPI_FLASH_SPCR_CPOL_Msk            /*!< SPI Clock Polarity */
#define SPI_FLASH_SPCR_MSTR_POS             (4U)
#define SPI_FLASH_SPCR_MSTR_Msk             (0x1UL << SPI_FLASH_SPCR_MSTR_POS)  /*!< 0x00000010 */
#define SPI_FLASH_SPCR_MSTR                 SPI_FLASH_SPCR_MSTR_Msk            /*!< SPI Master Selection */
#define SPI_FLASH_SPCR_SPE_POS              (6U)
#define SPI_FLASH_SPCR_SPE_Msk              (0x1UL << SPI_FLASH_SPCR_SPE_POS)   /*!< 0x00000040 */
#define SPI_FLASH_SPCR_SPE                  SPI_FLASH_SPCR_SPE_Msk             /*!< SPI Enable */
#define SPI_FLASH_SPCR_SPIE_POS             (7U)
#define SPI_FLASH_SPCR_SPIE_Msk             (0x1UL << SPI_FLASH_SPCR_SPIE_POS)  /*!< 0x00000080 */
#define SPI_FLASH_SPCR_SPIE                 SPI_FLASH_SPCR_SPIE_Msk            /*!< SPI Interrupt */

/****************  Bit definition for SPI_FLASH_SPSR register  ****************/
#define SPI_FLASH_SPSR_RFEMPTY_POS          (0U)
#define SPI_FLASH_SPSR_RFEMPTY_Msk          (0x1UL << SPI_FLASH_SPSR_RFEMPTY_POS)   /*!< 0x00000001 */
#define SPI_FLASH_SPSR_RFEMPTY              SPI_FLASH_SPSR_RFEMPTY_Msk             /*!< SPI Receive FIFO Empty */
#define SPI_FLASH_SPSR_RFFULL_POS           (1U)
#define SPI_FLASH_SPSR_RFFULL_Msk           (0x1UL << SPI_FLASH_SPSR_RFFULL_POS)   /*!< 0x00000002 */
#define SPI_FLASH_SPSR_RFFULL               SPI_FLASH_SPSR_RFFULL_Msk             /*!< SPI Receive FIFO Full */
#define SPI_FLASH_SPSR_WFEMPTY_POS          (2U)
#define SPI_FLASH_SPSR_WFEMPTY_Msk          (0x1UL << SPI_FLASH_SPSR_WFEMPTY_POS)   /*!< 0x00000004 */
#define SPI_FLASH_SPSR_WFEMPTY              SPI_FLASH_SPSR_WFEMPTY_Msk             /*!< SPI Transmit FIFO Empty */
#define SPI_FLASH_SPSR_WFFULL_POS           (3U)
#define SPI_FLASH_SPSR_WFFULL_Msk           (0x1UL << SPI_FLASH_SPSR_WFFULL_POS)   /*!< 0x00000008 */
#define SPI_FLASH_SPSR_WFFULL               SPI_FLASH_SPSR_WFFULL_Msk             /*!< SPI Transmit FIFO Full */
#define SPI_FLASH_SPSR_WCOL_POS             (6U)
#define SPI_FLASH_SPSR_WCOL_Msk             (0x1UL << SPI_FLASH_SPSR_WCOL_POS)  /*!< 0x00000040 */
#define SPI_FLASH_SPSR_WCOL                 SPI_FLASH_SPSR_WCOL_Msk            /*!< SPI Write Collision Interrupt */
#define SPI_FLASH_SPSR_SPIF_POS             (7U)
#define SPI_FLASH_SPSR_SPIF_Msk             (0x1UL << SPI_FLASH_SPSR_SPIF_POS)  /*!< 0x00000080 */
#define SPI_FLASH_SPSR_SPIF                 SPI_FLASH_SPSR_SPIF_Msk            /*!< SPI Transfer Complete Interrupt */

/****************  Bit definition for SPI_FLASH_SPER register  ****************/
#define SPI_FLASH_SPER_SPRE_POS             (0U)
#define SPI_FLASH_SPER_SPRE_Msk             (0x3UL << SPI_FLASH_SPER_SPRE_POS)  /*!< 0x00000003 */
#define SPI_FLASH_SPER_SPRE                 SPI_FLASH_SPER_SPRE_Msk            /*!< SPI Prescaler */
#define SPI_FLASH_SPER_MODE_POS             (2U)
#define SPI_FLASH_SPER_MODE_Msk             (0x1UL << SPI_FLASH_SPER_MODE_POS)  /*!< 0x00000004 */
#define SPI_FLASH_SPER_MODE                 SPI_FLASH_SPER_MODE_Msk            /*!< SPI Mode */
#define SPI_FLASH_SPER_ICNT_POS             (6U)
#define SPI_FLASH_SPER_ICNT_Msk             (0x3UL << SPI_FLASH_SPER_ICNT_POS)  /*!< 0x000000C0 */
#define SPI_FLASH_SPER_ICNT                 SPI_FLASH_SPER_ICNT_Msk            /*!< SPI Interrupt Count */

/*************  Bit definition for SPI_FLASH_SFC_PARAM register  **************/
#define SPI_FLASH_SFC_PARAM_MEMORY_EN_POS   (0U)
#define SPI_FLASH_SFC_PARAM_MEMORY_EN_Msk   (0x1UL << SPI_FLASH_SFC_PARAM_MEMORY_EN_POS)  /*!< 0x00000001 */
#define SPI_FLASH_SFC_PARAM_MEMORY_EN       SPI_FLASH_SFC_PARAM_MEMORY_EN_Msk            /*!< SPI Flash Memory Access Enable */
#define SPI_FLASH_SFC_PARAM_BURST_EN_POS    (1U)
#define SPI_FLASH_SFC_PARAM_BURST_EN_Msk    (0x1UL << SPI_FLASH_SFC_PARAM_BURST_EN_POS)   /*!< 0x00000002 */
#define SPI_FLASH_SFC_PARAM_BURST_EN        SPI_FLASH_SFC_PARAM_BURST_EN_Msk             /*!< SPI Flash Burst Access Enable */
#define SPI_FLASH_SFC_PARAM_FAST_READ_POS   (2U)
#define SPI_FLASH_SFC_PARAM_FAST_READ_Msk   (0x1UL << SPI_FLASH_SFC_PARAM_FAST_READ_POS)  /*!< 0x00000004 */
#define SPI_FLASH_SFC_PARAM_FAST_READ       SPI_FLASH_SFC_PARAM_FAST_READ_Msk            /*!< SPI Flash Fast Read Enable */
#define SPI_FLASH_SFC_PARAM_DUAL_MODE_POS   (3U)
#define SPI_FLASH_SFC_PARAM_DUAL_MODE_Msk   (0x1UL << SPI_FLASH_SFC_PARAM_DUAL_MODE_POS)  /*!< 0x00000008 */
#define SPI_FLASH_SFC_PARAM_DUAL_MODE       SPI_FLASH_SFC_PARAM_DUAL_MODE_Msk            /*!< SPI Flash Dual I/O Mode Enable */
#define SPI_FLASH_SFC_PARAM_CLK_DIV_POS     (4U)
#define SPI_FLASH_SFC_PARAM_CLK_DIV_Msk     (0xFUL << SPI_FLASH_SFC_PARAM_CLK_DIV_POS)    /*!< 0x000000F0 */
#define SPI_FLASH_SFC_PARAM_CLK_DIV         SPI_FLASH_SFC_PARAM_CLK_DIV_Msk

/*************  Bit definition for SPI_FLASH_SFC_SOFTCS register  *************/
#define SPI_FLASH_SFC_SOFTCS_CSEN_POS       (0U)
#define SPI_FLASH_SFC_SOFTCS_CSEN_Msk       (0xFUL << SPI_FLASH_SFC_SOFTCS_CSEN_POS)      /*!< 0x0000000F */
#define SPI_FLASH_SFC_SOFTCS_CSEN           SPI_FLASH_SFC_SOFTCS_CSEN_Msk                /*!< SPI Flash Software Chip Select Enable */
#define SPI_FLASH_SFC_SOFTCS_CSN_POS        (4U)
#define SPI_FLASH_SFC_SOFTCS_CSN_Msk        (0xFUL << SPI_FLASH_SFC_SOFTCS_CSN_POS)       /*!< 0x000000F0 */
#define SPI_FLASH_SFC_SOFTCS_CSN            SPI_FLASH_SFC_SOFTCS_CSN_Msk                 /*!< SPI Flash Software Chip Select Number */

/*************  Bit definition for SPI_FLASH_SFC_TIMING register  *************/
#define SPI_FLASH_SFC_TIMING_TCSH_POS       (0U)
#define SPI_FLASH_SFC_TIMING_TCSH_Msk       (0x3UL << SPI_FLASH_SFC_TIMING_TCSH_POS)      /*!< 0x00000003 */
#define SPI_FLASH_SFC_TIMING_TCSH           SPI_FLASH_SFC_TIMING_TCSH_Msk                /*!< SPI Flash Chip Select Hold Time */
#define SPI_FLASH_SFC_TIMING_TFAST_POS      (2U)
#define SPI_FLASH_SFC_TIMING_TFAST_Msk      (0x1UL << SPI_FLASH_SFC_TIMING_TFAST_POS)     /*!< 0x00000004 */
#define SPI_FLASH_SFC_TIMING_TFAST          SPI_FLASH_SFC_TIMING_TFAST_Msk               /*!< SPI Flash Fast Access Mode */

/******************  Bit definition for SPI_IO_CR1 register  ******************/
#define SPI_IO_CR1_SPE_POS                  (0U)
#define SPI_IO_CR1_SPE_Msk                  (0x1UL << SPI_IO_CR1_SPE_POS)         /*!< 0x00000001 */
#define SPI_IO_CR1_SPE                      SPI_IO_CR1_SPE_Msk
#define SPI_IO_CR1_CSTART_POS               (1U)
#define SPI_IO_CR1_CSTART_Msk               (0x1UL << SPI_IO_CR1_CSTART_POS)      /*!< 0x00000002 */
#define SPI_IO_CR1_CSTART                   SPI_IO_CR1_CSTART_Msk
#define SPI_IO_CR1_AUTOSUS_POS              (2U)
#define SPI_IO_CR1_AUTOSUS_Msk              (0x1UL << SPI_IO_CR1_AUTOSUS_POS)     /*!< 0x00000004 */
#define SPI_IO_CR1_AUTOSUS                  SPI_IO_CR1_AUTOSUS_Msk
#define SPI_IO_CR1_SSREV_POS                (8U)
#define SPI_IO_CR1_SSREV_Msk                (0x1UL << SPI_IO_CR1_SSREV_POS)       /*!< 0x00000100 */
#define SPI_IO_CR1_SSREV                    SPI_IO_CR1_SSREV_Msk

/******************  Bit definition for SPI_IO_CR2 register  ******************/
#define SPI_IO_CR2_RXFTHLV_POS              (0U)
#define SPI_IO_CR2_RXFTHLV_Msk              (0x3UL << SPI_IO_CR2_RXFTHLV_POS)     /*!< 0x00000003 */
#define SPI_IO_CR2_RXFTHLV                  SPI_IO_CR2_RXFTHLV_Msk
#define SPI_IO_CR2_RXDMAEN_POS              (7U)
#define SPI_IO_CR2_RXDMAEN_Msk              (0x1UL << SPI_IO_CR2_RXDMAEN_POS)     /*!< 0x00000080 */
#define SPI_IO_CR2_RXDMAEN                  SPI_IO_CR2_RXDMAEN_Msk
#define SPI_IO_CR2_TXFTHLV_POS              (8U)
#define SPI_IO_CR2_TXFTHLV_Msk              (0x3UL << SPI_IO_CR2_TXFTHLV_POS)     /*!< 0x00000300 */
#define SPI_IO_CR2_TXFTHLV                  SPI_IO_CR2_TXFTHLV_Msk
#define SPI_IO_CR2_TXDMAEN_POS              (15U)
#define SPI_IO_CR2_TXDMAEN_Msk              (0x1UL << SPI_IO_CR2_TXDMAEN_POS)     /*!< 0x00008000 */
#define SPI_IO_CR2_TXDMAEN                  SPI_IO_CR2_TXDMAEN_Msk

/******************  Bit definition for SPI_IO_CR3 register  ******************/
#define SPI_IO_CR3_TSIZE_POS                (0U)
#define SPI_IO_CR3_TSIZE_Msk                (0xFFFFUL << SPI_IO_CR3_TSIZE_POS)    /*!< 0x0000FFFF */
#define SPI_IO_CR3_TSIZE                    SPI_IO_CR3_TSIZE_Msk

/******************  Bit definition for SPI_IO_CR4 register  ******************/
#define SPI_IO_CR4_CTSIZE_POS               (0U)
#define SPI_IO_CR4_CTSIZE_Msk               (0xFFFFUL << SPI_IO_CR4_CTSIZE_POS)   /*!< 0x0000FFFF */
#define SPI_IO_CR4_CTSIZE                   SPI_IO_CR4_CTSIZE_Msk

/******************  Bit definition for SPI_IO_IER register  ******************/
#define SPI_IO_IER_RXAIE_POS                (0U)
#define SPI_IO_IER_RXAIE_Msk                (0x1UL << SPI_IO_IER_RXAIE_POS)       /*!< 0x00000001 */
#define SPI_IO_IER_RXAIE                    SPI_IO_IER_RXAIE_Msk
#define SPI_IO_IER_TXAIE_POS                (1U)
#define SPI_IO_IER_TXAIE_Msk                (0x1UL << SPI_IO_IER_TXAIE_POS)       /*!< 0x00000002 */
#define SPI_IO_IER_TXAIE                    SPI_IO_IER_TXAIE_Msk
#define SPI_IO_IER_DXAIE_POS                (2U)
#define SPI_IO_IER_DXAIE_Msk                (0x1UL << SPI_IO_IER_DXAIE_POS)       /*!< 0x00000004 */
#define SPI_IO_IER_DXAIE                    SPI_IO_IER_DXAIE_Msk
#define SPI_IO_IER_RXEIE_POS                (4U)
#define SPI_IO_IER_RXEIE_Msk                (0x1UL << SPI_IO_IER_RXEIE_POS)       /*!< 0x00000010 */
#define SPI_IO_IER_RXEIE                    SPI_IO_IER_RXEIE_Msk
#define SPI_IO_IER_TXEIE_POS                (5U)
#define SPI_IO_IER_TXEIE_Msk                (0x1UL << SPI_IO_IER_TXEIE_POS)       /*!< 0x00000020 */
#define SPI_IO_IER_TXEIE                    SPI_IO_IER_TXEIE_Msk
#define SPI_IO_IER_SUSPIE_POS               (7U)
#define SPI_IO_IER_SUSPIE_Msk               (0x1UL << SPI_IO_IER_SUSPIE_POS)      /*!< 0x00000080 */
#define SPI_IO_IER_SUSPIE                   SPI_IO_IER_SUSPIE_Msk
#define SPI_IO_IER_OVRIE_POS                (8U)
#define SPI_IO_IER_OVRIE_Msk                (0x1UL << SPI_IO_IER_OVRIE_POS)       /*!< 0x00000100 */
#define SPI_IO_IER_OVRIE                    SPI_IO_IER_OVRIE_Msk
#define SPI_IO_IER_UDRIE_POS                (9U)
#define SPI_IO_IER_UDRIE_Msk                (0x1UL << SPI_IO_IER_UDRIE_POS)       /*!< 0x00000200 */
#define SPI_IO_IER_UDRIE                    SPI_IO_IER_UDRIE_Msk
#define SPI_IO_IER_CRCEIE_POS               (10U)
#define SPI_IO_IER_CRCEIE_Msk               (0x1UL << SPI_IO_IER_CRCEIE_POS)      /*!< 0x00000400 */
#define SPI_IO_IER_CRCEIE                   SPI_IO_IER_CRCEIE_Msk
#define SPI_IO_IER_MODFIE_POS               (11U)
#define SPI_IO_IER_MODFIE_Msk               (0x1UL << SPI_IO_IER_MODFIE_POS)      /*!< 0x00000800 */
#define SPI_IO_IER_MODFIE                   SPI_IO_IER_MODFIE_Msk
#define SPI_IO_IER_EOTIE_POS                (15U)
#define SPI_IO_IER_EOTIE_Msk                (0x1UL << SPI_IO_IER_EOTIE_POS)       /*!< 0x00008000 */
#define SPI_IO_IER_EOTIE                    SPI_IO_IER_EOTIE_Msk

/******************  Bit definition for SPI_IO_SR1 register  ******************/
#define SPI_IO_SR1_RXA_POS                  (0U)
#define SPI_IO_SR1_RXA_Msk                  (0x1UL << SPI_IO_SR1_RXA_POS)         /*!< 0x00000001 */
#define SPI_IO_SR1_RXA                      SPI_IO_SR1_RXA_Msk
#define SPI_IO_SR1_TXA_POS                  (1U)
#define SPI_IO_SR1_TXA_Msk                  (0x1UL << SPI_IO_SR1_TXA_POS)         /*!< 0x00000002 */
#define SPI_IO_SR1_TXA                      SPI_IO_SR1_TXA_Msk
#define SPI_IO_SR1_DXA_POS                  (2U)
#define SPI_IO_SR1_DXA_Msk                  (0x1UL << SPI_IO_SR1_DXA_POS)         /*!< 0x00000004 */
#define SPI_IO_SR1_DXA                      SPI_IO_SR1_DXA_Msk
#define SPI_IO_SR1_RXE_POS                  (4U)
#define SPI_IO_SR1_RXE_Msk                  (0x1UL << SPI_IO_SR1_RXE_POS)         /*!< 0x00000010 */
#define SPI_IO_SR1_RXE                      SPI_IO_SR1_RXE_Msk
#define SPI_IO_SR1_TXE_POS                  (5U)
#define SPI_IO_SR1_TXE_Msk                  (0x1UL << SPI_IO_SR1_TXE_POS)         /*!< 0x00000020 */
#define SPI_IO_SR1_TXE                      SPI_IO_SR1_TXE_Msk
#define SPI_IO_SR1_SUSP_POS                 (7U)
#define SPI_IO_SR1_SUSP_Msk                 (0x1UL << SPI_IO_SR1_SUSP_POS)        /*!< 0x00000080 */
#define SPI_IO_SR1_SUSP                     SPI_IO_SR1_SUSP_Msk
#define SPI_IO_SR1_OVR_POS                  (8U)
#define SPI_IO_SR1_OVR_Msk                  (0x1UL << SPI_IO_SR1_OVR_POS)         /*!< 0x00000100 */
#define SPI_IO_SR1_OVR                      SPI_IO_SR1_OVR_Msk
#define SPI_IO_SR1_UDR_POS                  (9U)
#define SPI_IO_SR1_UDR_Msk                  (0x1UL << SPI_IO_SR1_UDR_POS)         /*!< 0x00000200 */
#define SPI_IO_SR1_UDR                      SPI_IO_SR1_UDR_Msk
#define SPI_IO_SR1_CRCE_POS                 (10U)
#define SPI_IO_SR1_CRCE_Msk                 (0x1UL << SPI_IO_SR1_CRCE_POS)        /*!< 0x00000400 */
#define SPI_IO_SR1_CRCE                     SPI_IO_SR1_CRCE_Msk
#define SPI_IO_SR1_MODF_POS                 (11U)
#define SPI_IO_SR1_MODF_Msk                 (0x1UL << SPI_IO_SR1_MODF_POS)        /*!< 0x00000800 */
#define SPI_IO_SR1_MODF                     SPI_IO_SR1_MODF_Msk
#define SPI_IO_SR1_EOT_POS                  (15U)
#define SPI_IO_SR1_EOT_Msk                  (0x1UL << SPI_IO_SR1_EOT_POS)         /*!< 0x00008000 */
#define SPI_IO_SR1_EOT                      SPI_IO_SR1_EOT_Msk

/******************  Bit definition for SPI_IO_SR2 register  ******************/
#define SPI_IO_SR2_RXFLV_POS                (0U)
#define SPI_IO_SR2_RXFLV_Msk                (0x7UL << SPI_IO_SR2_RXFLV_POS)       /*!< 0x00000007 */
#define SPI_IO_SR2_RXFLV                    SPI_IO_SR2_RXFLV_Msk
#define SPI_IO_SR2_TXFLV_POS                (8U)
#define SPI_IO_SR2_TXFLV_Msk                (0x7UL << SPI_IO_SR2_TXFLV_POS)       /*!< 0x00000700 */
#define SPI_IO_SR2_TXFLV                    SPI_IO_SR2_TXFLV_Msk

/******************  Bit definition for SPI_IO_CFG1 register  *****************/
#define SPI_IO_CFG1_CPOL_POS                (0U)
#define SPI_IO_CFG1_CPOL_Msk                (0x1UL << SPI_IO_CFG1_CPOL_POS)       /*!< 0x00000001 */
#define SPI_IO_CFG1_CPOL                    SPI_IO_CFG1_CPOL_Msk
#define SPI_IO_CFG1_CPHA_POS                (1U)
#define SPI_IO_CFG1_CPHA_Msk                (0x1UL << SPI_IO_CFG1_CPHA_POS)       /*!< 0x00000002 */
#define SPI_IO_CFG1_CPHA                    SPI_IO_CFG1_CPHA_Msk
#define SPI_IO_CFG1_LSBFRST_POS             (7U)
#define SPI_IO_CFG1_LSBFRST_Msk             (0x1UL << SPI_IO_CFG1_LSBFRST_POS)    /*!< 0x00000080 */
#define SPI_IO_CFG1_LSBFRST                 SPI_IO_CFG1_LSBFRST_Msk
#define SPI_IO_CFG1_DSIZE_POS               (8U)
#define SPI_IO_CFG1_DSIZE_Msk               (0x1FUL << SPI_IO_CFG1_DSIZE_POS)     /*!< 0x00001F00 */
#define SPI_IO_CFG1_DSIZE                   SPI_IO_CFG1_DSIZE_Msk

/******************  Bit definition for SPI_IO_CFG2 register  *****************/
#define SPI_IO_CFG2_BRDEC_POS               (2U)
#define SPI_IO_CFG2_BRDEC_Msk               (0x3FUL << SPI_IO_CFG2_BRDEC_POS)     /*!< 0x000000FC */
#define SPI_IO_CFG2_BRDEC                   SPI_IO_CFG2_BRDEC_Msk
#define SPI_IO_CFG2_BRINT_POS               (8U)
#define SPI_IO_CFG2_BRINT_Msk               (0xFFUL << SPI_IO_CFG2_BRINT_POS)     /*!< 0x0000FF00 */
#define SPI_IO_CFG2_BRINT                   SPI_IO_CFG2_BRINT_Msk

/******************  Bit definition for SPI_IO_CFG3 register  *****************/
#define SPI_IO_CFG3_MSTR_POS                (0U)
#define SPI_IO_CFG3_MSTR_Msk                (0x1UL << SPI_IO_CFG3_MSTR_POS)       /*!< 0x00000001 */
#define SPI_IO_CFG3_MSTR                    SPI_IO_CFG3_MSTR_Msk
#define SPI_IO_CFG3_DIOSWP_POS              (1U)
#define SPI_IO_CFG3_DIOSWP_Msk              (0x1UL << SPI_IO_CFG3_DIOSWP_POS)     /*!< 0x00000002 */
#define SPI_IO_CFG3_DIOSWP                  SPI_IO_CFG3_DIOSWP_Msk
#define SPI_IO_CFG3_DIE_POS                 (2U)
#define SPI_IO_CFG3_DIE_Msk                 (0x1UL << SPI_IO_CFG3_DIE_POS)        /*!< 0x00000004 */
#define SPI_IO_CFG3_DIE                     SPI_IO_CFG3_DIE_Msk
#define SPI_IO_CFG3_DOE_POS                 (3U)
#define SPI_IO_CFG3_DOE_Msk                 (0x1UL << SPI_IO_CFG3_DOE_POS)        /*!< 0x00000008 */
#define SPI_IO_CFG3_DOE                     SPI_IO_CFG3_DOE_Msk
#define SPI_IO_CFG3_SSMODE_POS              (8U)
#define SPI_IO_CFG3_SSMODE_Msk              (0x3UL << SPI_IO_CFG3_SSMODE_POS)     /*!< 0x00000300 */
#define SPI_IO_CFG3_SSMODE                  SPI_IO_CFG3_SSMODE_Msk

/******************  Bit definition for SPI_IO_CRC1 register  *****************/
#define SPI_IO_CRC1_CRCEN_POS               (0U)
#define SPI_IO_CRC1_CRCEN_Msk               (0x1UL << SPI_IO_CRC1_CRCEN_POS)      /*!< 0x00000001 */
#define SPI_IO_CRC1_CRCEN                   SPI_IO_CRC1_CRCEN_Msk
#define SPI_IO_CRC1_CRCPOLY_POS             (1U)
#define SPI_IO_CRC1_CRCPOLY_Msk             (0x7FFFFFFFUL << SPI_IO_CRC1_CRCPOLY_POS) /*!< 0xFFFFFFFE */
#define SPI_IO_CRC1_CRCPOLY                 SPI_IO_CRC1_CRCPOLY_Msk

/******************  Bit definition for SPI_IO_CRC2 register  *****************/
#define SPI_IO_CRC2_RCRCINI_POS             (0U)
#define SPI_IO_CRC2_RCRCINI_Msk             (0x1UL << SPI_IO_CRC2_RCRCINI_POS)    /*!< 0x00000001 */
#define SPI_IO_CRC2_RCRCINI                 SPI_IO_CRC2_RCRCINI_Msk
#define SPI_IO_CRC2_TCRCINI_POS             (1U)
#define SPI_IO_CRC2_TCRCINI_Msk             (0x1UL << SPI_IO_CRC2_TCRCINI_POS)    /*!< 0x00000002 */
#define SPI_IO_CRC2_TCRCINI                 SPI_IO_CRC2_TCRCINI_Msk
#define SPI_IO_CRC2_CRCSIZE_POS             (8U)
#define SPI_IO_CRC2_CRCSIZE_Msk             (0x1FUL << SPI_IO_CRC2_CRCSIZE_POS)   /*!< 0x00001F00 */
#define SPI_IO_CRC2_CRCSIZE                 SPI_IO_CRC2_CRCSIZE_Msk

/******************  Bit definition for SPI_IO_DR register  *******************/
#define SPI_IO_DR_DR_POS                    (0U)
#define SPI_IO_DR_DR_Msk                    (0xFFFFFFFFUL << SPI_IO_DR_DR_POS)    /*!< 0xFFFFFFFF */
#define SPI_IO_DR_DR                        SPI_IO_DR_DR_Msk

/******************************************************************************/
/*                                                                            */
/*                      Inter-integrated Circuit Interface                    */
/*                                                                            */
/******************************************************************************/

/*******************  Bit definition for I2C_CR1 register  ********************/
#define I2C_CR1_PE_Pos                      (0U)                               
#define I2C_CR1_PE_Msk                      (0x1UL << I2C_CR1_PE_Pos)           /*!< 0x00000001 */
#define I2C_CR1_PE                          I2C_CR1_PE_Msk                     /*!< Peripheral Enable */
#define I2C_CR1_ENGC_Pos                    (6U)                               
#define I2C_CR1_ENGC_Msk                    (0x1UL << I2C_CR1_ENGC_Pos)         /*!< 0x00000040 */
#define I2C_CR1_ENGC                        I2C_CR1_ENGC_Msk                   /*!< General Call Enable */
#define I2C_CR1_NOSTRETCH_Pos               (7U)                               
#define I2C_CR1_NOSTRETCH_Msk               (0x1UL << I2C_CR1_NOSTRETCH_Pos)    /*!< 0x00000080 */
#define I2C_CR1_NOSTRETCH                   I2C_CR1_NOSTRETCH_Msk              /*!< Clock Stretching Disable (Slave mode) */
#define I2C_CR1_START_Pos                   (8U)                               
#define I2C_CR1_START_Msk                   (0x1UL << I2C_CR1_START_Pos)        /*!< 0x00000100 */
#define I2C_CR1_START                       I2C_CR1_START_Msk                  /*!< Start Generation */
#define I2C_CR1_STOP_Pos                    (9U)                               
#define I2C_CR1_STOP_Msk                    (0x1UL << I2C_CR1_STOP_Pos)         /*!< 0x00000200 */
#define I2C_CR1_STOP                        I2C_CR1_STOP_Msk                   /*!< Stop Generation */
#define I2C_CR1_ACK_Pos                     (10U)                              
#define I2C_CR1_ACK_Msk                     (0x1UL << I2C_CR1_ACK_Pos)          /*!< 0x00000400 */
#define I2C_CR1_ACK                         I2C_CR1_ACK_Msk                    /*!< Acknowledge Enable */
#define I2C_CR1_POS_Pos                     (11U)                              
#define I2C_CR1_POS_Msk                     (0x1UL << I2C_CR1_POS_Pos)          /*!< 0x00000800 */
#define I2C_CR1_POS                         I2C_CR1_POS_Msk                    /*!< Acknowledge/PEC Position (for data reception) */
#define I2C_CR1_RECOVER_Pos                 (14U)
#define I2C_CR1_RECOVER_Msk                 (0x1UL << I2C_CR1_RECOVER_Pos)      /*!< 0x00004000 */
#define I2C_CR1_RECOVER                     I2C_CR1_RECOVER_Msk                /*!< I2C Bus Recovery */
#define I2C_CR1_SWRST_Pos                   (15U)                              
#define I2C_CR1_SWRST_Msk                   (0x1UL << I2C_CR1_SWRST_Pos)        /*!< 0x00008000 */
#define I2C_CR1_SWRST                       I2C_CR1_SWRST_Msk                  /*!< Software Reset */

/*******************  Bit definition for I2C_CR2 register  ********************/
#define I2C_CR2_FREQ_Pos                    (0U)                               
#define I2C_CR2_FREQ_Msk                    (0x3FUL << I2C_CR2_FREQ_Pos)        /*!< 0x0000003F */
#define I2C_CR2_FREQ                        I2C_CR2_FREQ_Msk                   /*!< FREQ[5:0] bits (Peripheral Clock Frequency) */
#define I2C_CR2_FREQ_0                      (0x01UL << I2C_CR2_FREQ_Pos)        /*!< 0x00000001 */
#define I2C_CR2_FREQ_1                      (0x02UL << I2C_CR2_FREQ_Pos)        /*!< 0x00000002 */
#define I2C_CR2_FREQ_2                      (0x04UL << I2C_CR2_FREQ_Pos)        /*!< 0x00000004 */
#define I2C_CR2_FREQ_3                      (0x08UL << I2C_CR2_FREQ_Pos)        /*!< 0x00000008 */
#define I2C_CR2_FREQ_4                      (0x10UL << I2C_CR2_FREQ_Pos)        /*!< 0x00000010 */
#define I2C_CR2_FREQ_5                      (0x20UL << I2C_CR2_FREQ_Pos)        /*!< 0x00000020 */

#define I2C_CR2_ITERREN_Pos                 (8U)                               
#define I2C_CR2_ITERREN_Msk                 (0x1UL << I2C_CR2_ITERREN_Pos)      /*!< 0x00000100 */
#define I2C_CR2_ITERREN                     I2C_CR2_ITERREN_Msk                /*!< Error Interrupt Enable */
#define I2C_CR2_ITEVTEN_Pos                 (9U)                               
#define I2C_CR2_ITEVTEN_Msk                 (0x1UL << I2C_CR2_ITEVTEN_Pos)      /*!< 0x00000200 */
#define I2C_CR2_ITEVTEN                     I2C_CR2_ITEVTEN_Msk                /*!< Event Interrupt Enable */
#define I2C_CR2_ITBUFEN_Pos                 (10U)                              
#define I2C_CR2_ITBUFEN_Msk                 (0x1UL << I2C_CR2_ITBUFEN_Pos)      /*!< 0x00000400 */
#define I2C_CR2_ITBUFEN                     I2C_CR2_ITBUFEN_Msk                /*!< Buffer Interrupt Enable */
#define I2C_CR2_DMAEN_Pos                   (11U)                              
#define I2C_CR2_DMAEN_Msk                   (0x1UL << I2C_CR2_DMAEN_Pos)        /*!< 0x00000800 */
#define I2C_CR2_DMAEN                       I2C_CR2_DMAEN_Msk                  /*!< DMA Requests Enable */

/*******************  Bit definition for I2C_OAR1 register  *******************/
#define I2C_OAR1_ADD1_7                     0x000000FEU             /*!< Interface Address */

#define I2C_OAR1_ADD0                       (0x1UL)                             /*!< 0x00000001 */

#define I2C_OAR1_ADD1_Pos                   (1U)                               
#define I2C_OAR1_ADD1_Msk                   (0x1UL << I2C_OAR1_ADD1_Pos)        /*!< 0x00000002 */
#define I2C_OAR1_ADD1                       I2C_OAR1_ADD1_Msk                  /*!< Bit 1 */
#define I2C_OAR1_ADD2_Pos                   (2U)                               
#define I2C_OAR1_ADD2_Msk                   (0x1UL << I2C_OAR1_ADD2_Pos)        /*!< 0x00000004 */
#define I2C_OAR1_ADD2                       I2C_OAR1_ADD2_Msk                  /*!< Bit 2 */
#define I2C_OAR1_ADD3_Pos                   (3U)                               
#define I2C_OAR1_ADD3_Msk                   (0x1UL << I2C_OAR1_ADD3_Pos)        /*!< 0x00000008 */
#define I2C_OAR1_ADD3                       I2C_OAR1_ADD3_Msk                  /*!< Bit 3 */
#define I2C_OAR1_ADD4_Pos                   (4U)                               
#define I2C_OAR1_ADD4_Msk                   (0x1UL << I2C_OAR1_ADD4_Pos)        /*!< 0x00000010 */
#define I2C_OAR1_ADD4                       I2C_OAR1_ADD4_Msk                  /*!< Bit 4 */
#define I2C_OAR1_ADD5_Pos                   (5U)                               
#define I2C_OAR1_ADD5_Msk                   (0x1UL << I2C_OAR1_ADD5_Pos)        /*!< 0x00000020 */
#define I2C_OAR1_ADD5                       I2C_OAR1_ADD5_Msk                  /*!< Bit 5 */
#define I2C_OAR1_ADD6_Pos                   (6U)                               
#define I2C_OAR1_ADD6_Msk                   (0x1UL << I2C_OAR1_ADD6_Pos)        /*!< 0x00000040 */
#define I2C_OAR1_ADD6                       I2C_OAR1_ADD6_Msk                  /*!< Bit 6 */
#define I2C_OAR1_ADD7_Pos                   (7U)                               
#define I2C_OAR1_ADD7_Msk                   (0x1UL << I2C_OAR1_ADD7_Pos)        /*!< 0x00000080 */
#define I2C_OAR1_ADD7                       I2C_OAR1_ADD7_Msk                  /*!< Bit 7 */

/********************  Bit definition for I2C_DR register  ********************/
#define I2C_DR_DR_Pos             (0U)                                         
#define I2C_DR_DR_Msk             (0xFFUL << I2C_DR_DR_Pos)                     /*!< 0x000000FF */
#define I2C_DR_DR                 I2C_DR_DR_Msk                                /*!< 8-bit Data Register         */

/*******************  Bit definition for I2C_SR1 register  ********************/
#define I2C_SR1_SB_Pos                      (0U)                               
#define I2C_SR1_SB_Msk                      (0x1UL << I2C_SR1_SB_Pos)           /*!< 0x00000001 */
#define I2C_SR1_SB                          I2C_SR1_SB_Msk                     /*!< Start Bit (Master mode) */
#define I2C_SR1_ADDR_Pos                    (1U)                               
#define I2C_SR1_ADDR_Msk                    (0x1UL << I2C_SR1_ADDR_Pos)         /*!< 0x00000002 */
#define I2C_SR1_ADDR                        I2C_SR1_ADDR_Msk                   /*!< Address sent (master mode)/matched (slave mode) */
#define I2C_SR1_BTF_Pos                     (2U)                               
#define I2C_SR1_BTF_Msk                     (0x1UL << I2C_SR1_BTF_Pos)          /*!< 0x00000004 */
#define I2C_SR1_BTF                         I2C_SR1_BTF_Msk                    /*!< Byte Transfer Finished */
#define I2C_SR1_STOPF_Pos                   (4U)                               
#define I2C_SR1_STOPF_Msk                   (0x1UL << I2C_SR1_STOPF_Pos)        /*!< 0x00000010 */
#define I2C_SR1_STOPF                       I2C_SR1_STOPF_Msk                  /*!< Stop detection (Slave mode) */
#define I2C_SR1_RXNE_Pos                    (6U)                               
#define I2C_SR1_RXNE_Msk                    (0x1UL << I2C_SR1_RXNE_Pos)         /*!< 0x00000040 */
#define I2C_SR1_RXNE                        I2C_SR1_RXNE_Msk                   /*!< Data Register not Empty (receivers) */
#define I2C_SR1_TXE_Pos                     (7U)                               
#define I2C_SR1_TXE_Msk                     (0x1UL << I2C_SR1_TXE_Pos)          /*!< 0x00000080 */
#define I2C_SR1_TXE                         I2C_SR1_TXE_Msk                    /*!< Data Register Empty (transmitters) */
#define I2C_SR1_BERR_Pos                    (8U)                               
#define I2C_SR1_BERR_Msk                    (0x1UL << I2C_SR1_BERR_Pos)         /*!< 0x00000100 */
#define I2C_SR1_BERR                        I2C_SR1_BERR_Msk                   /*!< Bus Error */
#define I2C_SR1_ARLO_Pos                    (9U)                               
#define I2C_SR1_ARLO_Msk                    (0x1UL << I2C_SR1_ARLO_Pos)         /*!< 0x00000200 */
#define I2C_SR1_ARLO                        I2C_SR1_ARLO_Msk                   /*!< Arbitration Lost (master mode) */
#define I2C_SR1_AF_Pos                      (10U)                              
#define I2C_SR1_AF_Msk                      (0x1UL << I2C_SR1_AF_Pos)           /*!< 0x00000400 */
#define I2C_SR1_AF                          I2C_SR1_AF_Msk                     /*!< Acknowledge Failure */
#define I2C_SR1_OVR_Pos                     (11U)                              
#define I2C_SR1_OVR_Msk                     (0x1UL << I2C_SR1_OVR_Pos)          /*!< 0x00000800 */
#define I2C_SR1_OVR                         I2C_SR1_OVR_Msk                    /*!< Overrun/Underrun */

/*******************  Bit definition for I2C_SR2 register  ********************/
#define I2C_SR2_MSL_Pos                     (0U)                               
#define I2C_SR2_MSL_Msk                     (0x1UL << I2C_SR2_MSL_Pos)          /*!< 0x00000001 */
#define I2C_SR2_MSL                         I2C_SR2_MSL_Msk                    /*!< Master/Slave */
#define I2C_SR2_BUSY_Pos                    (1U)                               
#define I2C_SR2_BUSY_Msk                    (0x1UL << I2C_SR2_BUSY_Pos)         /*!< 0x00000002 */
#define I2C_SR2_BUSY                        I2C_SR2_BUSY_Msk                   /*!< Bus Busy */
#define I2C_SR2_TRA_Pos                     (2U)                               
#define I2C_SR2_TRA_Msk                     (0x1UL << I2C_SR2_TRA_Pos)          /*!< 0x00000004 */
#define I2C_SR2_TRA                         I2C_SR2_TRA_Msk                    /*!< Transmitter/Receiver */
#define I2C_SR2_GENCALL_Pos                 (4U)                               
#define I2C_SR2_GENCALL_Msk                 (0x1UL << I2C_SR2_GENCALL_Pos)      /*!< 0x00000010 */
#define I2C_SR2_GENCALL                     I2C_SR2_GENCALL_Msk                /*!< General Call Address (Slave mode) */

/*******************  Bit definition for I2C_CCR register  ********************/
#define I2C_CCR_CCR_Pos                     (0U)                               
#define I2C_CCR_CCR_Msk                     (0xFFFUL << I2C_CCR_CCR_Pos)        /*!< 0x00000FFF */
#define I2C_CCR_CCR                         I2C_CCR_CCR_Msk                    /*!< Clock Control Register in Fast/Standard mode (Master mode) */
#define I2C_CCR_DUTY_Pos                    (14U)                              
#define I2C_CCR_DUTY_Msk                    (0x1UL << I2C_CCR_DUTY_Pos)         /*!< 0x00004000 */
#define I2C_CCR_DUTY                        I2C_CCR_DUTY_Msk                   /*!< Fast Mode Duty Cycle */
#define I2C_CCR_FS_Pos                      (15U)                              
#define I2C_CCR_FS_Msk                      (0x1UL << I2C_CCR_FS_Pos)           /*!< 0x00008000 */
#define I2C_CCR_FS                          I2C_CCR_FS_Msk                     /*!< I2C Master Mode Selection */

/******************  Bit definition for I2C_TRISE register  *******************/
#define I2C_TRISE_TRISE_Pos                 (0U)                               
#define I2C_TRISE_TRISE_Msk                 (0x3FUL << I2C_TRISE_TRISE_Pos)     /*!< 0x0000003F */
#define I2C_TRISE_TRISE                     I2C_TRISE_TRISE_Msk                /*!< Maximum Rise Time in Fast/Standard mode (Master mode) */

/*****************************************************************************/
/*                                                                           */
/*                                   UART                                    */
/*                                                                           */
/*****************************************************************************/

/*******************  Bit definition for UART_IER register  ******************/
#define UART_IER_MSI                        0x08	/* Enable Modem status interrupt */
#define UART_IER_RLSI                       0x04	/* Enable receiver line status interrupt */
#define UART_IER_THRI                       0x02	/* Enable Transmitter holding register int. */
#define UART_IER_RDI                        0x01	/* Enable receiver data interrupt */

/*******************  Bit definition for UART_IIR register  ******************/
#define UART_IIR_NO_INT                     0x01  /* No interrupts pending */
#define UART_IIR_ID                         0x0e  /* Mask for the interrupt ID */
#define UART_IIR_MSI                        0x00  /* Modem status interrupt */
#define UART_IIR_THRI                       0x02  /* Transmitter holding register empty */
#define UART_IIR_RDI                        0x04  /* Receiver data interrupt */
#define UART_IIR_RLSI                       0x06  /* Receiver line status interrupt */
#define UART_IIR_RX_TIMEOUT                 0x0c  /* OMAP RX Timeout interrupt */

/*******************  Bit definition for UART_FCR register  ******************/
#define UART_FCR_ENABLE_FIFO                0x01  /* Enable the FIFO */
#define UART_FCR_CLEAR_RCVR                 0x02  /* Clear the RCVR FIFO */
#define UART_FCR_CLEAR_XMIT                 0x04  /* Clear the XMIT FIFO */
#define UART_FCR_DMA_SELECT                 0x08  /* For DMA applications */
#define UART_FCR_TRIGGER_MASK               0xC0 /* Mask for the FIFO trigger range */
#define UART_FCR_R_TRIG_00                  0x00
#define UART_FCR_R_TRIG_01                  0x40
#define UART_FCR_R_TRIG_10                  0x80
#define UART_FCR_R_TRIG_11                  0xc0

/*******************  Bit definition for UART_LCR register  ******************/
#define UART_LCR_WLEN_MSK                   0x03  /* character length select mask */
#define UART_LCR_WLEN5                      0x00  /* Wordlength: 5 bits */
#define UART_LCR_WLEN6                      0x01  /* Wordlength: 6 bits */
#define UART_LCR_WLEN7                      0x02  /* Wordlength: 7 bits */
#define UART_LCR_WLEN8                      0x03  /* Wordlength: 8 bits */
#define UART_LCR_STOP                       0x04  /* Stop bits: 0=1 bit, 1=2 bits */
#define UART_LCR_PARITY                     0x08  /* Parity eneble */
#define UART_LCR_EPAR                       0x10  /* Even Parity Select */
#define UART_LCR_SPAR                       0x20  /* Stick Parity */
#define UART_LCR_SBRK                       0x40  /* Set Break */
#define UART_LCR_SBC                        0x80  /* Set break control */
#define UART_LCR_DLAB                       0x80  /* Divisor latch access bit */

/*******************  Bit definition for UART_MCR register  ******************/
#define UART_MCR_LOOP                       0x10 /* Enable loopback test mode */
#define UART_MCR_OUT2                       0x08 /* Out2 complement */
#define UART_MCR_OUT1                       0x04 /* Out1 complement */
#define UART_MCR_RTS                        0x02 /* RTS complement */
#define UART_MCR_DTR                        0x01 /* DTR complement */

/*******************  Bit definition for UART_LSR register  ******************/
#define UART_LSR_DR                         0x01  /* Receiver Data ready */
#define UART_LSR_OE                         0x02  /* Overrun error indicator */
#define UART_LSR_PE                         0x04  /* Parity error indicator */
#define UART_LSR_FE                         0x08  /* Framing error indicator */
#define UART_LSR_BI                         0x10  /* Break interrupt indicator */
#define UART_LSR_THRE                       0x20  /* Transmit-hold-register empty */
#define UART_LSR_TEMT                       0x40  /* Transmitter empty */
#define UART_LSR_ERR                        0x80  /* Error */
#define UART_LSR_BRK_ERROR_BITS             (UART_LSR_BI|UART_LSR_FE|UART_LSR_PE|UART_LSR_OE)

/*******************  Bit definition for UART_MSR register  ******************/
#define UART_MSR_DCD                        0x80		/* Data Carrier Detect */
#define UART_MSR_RI                         0x40		/* Ring Indicator */
#define UART_MSR_DSR                        0x20		/* Data Set Ready */
#define UART_MSR_CTS                        0x10		/* Clear to Send */
#define UART_MSR_DDCD                       0x08		/* Delta DCD */
#define UART_MSR_TERI                       0x04		/* Trailing edge ring indicator */
#define UART_MSR_DDSR                       0x02		/* Delta DSR */
#define UART_MSR_DCTS                       0x01		/* Delta CTS */
#define UART_MSR_ANY_DELTA                  (UART_MSR_DDCD|UART_MSR_TERI|UART_MSR_DDSR|UART_MSR_DCTS)

/*****************************************************************************/
/*                                                                           */
/*                               Timers (TIM)                                */
/*                                                                           */
/*****************************************************************************/
/*******************  Bit definition for TIM_CR1 register  *******************/
#define TIM_CR1_CEN_Pos                     (0U)                               
#define TIM_CR1_CEN_Msk                     (0x1UL << TIM_CR1_CEN_Pos)          /*!< 0x00000001 */
#define TIM_CR1_CEN                         TIM_CR1_CEN_Msk                    /*!<Counter enable */
#define TIM_CR1_UDIS_Pos                    (1U)                               
#define TIM_CR1_UDIS_Msk                    (0x1UL << TIM_CR1_UDIS_Pos)         /*!< 0x00000002 */
#define TIM_CR1_UDIS                        TIM_CR1_UDIS_Msk                   /*!<Update disable */
#define TIM_CR1_URS_Pos                     (2U)                               
#define TIM_CR1_URS_Msk                     (0x1UL << TIM_CR1_URS_Pos)          /*!< 0x00000004 */
#define TIM_CR1_URS                         TIM_CR1_URS_Msk                    /*!<Update request source */
#define TIM_CR1_OPM_Pos                     (3U)                               
#define TIM_CR1_OPM_Msk                     (0x1UL << TIM_CR1_OPM_Pos)          /*!< 0x00000008 */
#define TIM_CR1_OPM                         TIM_CR1_OPM_Msk                    /*!<One pulse mode */
#define TIM_CR1_DIR_Pos                     (4U)                               
#define TIM_CR1_DIR_Msk                     (0x1UL << TIM_CR1_DIR_Pos)          /*!< 0x00000010 */
#define TIM_CR1_DIR                         TIM_CR1_DIR_Msk                    /*!<Direction */

#define TIM_CR1_CMS_Pos                     (5U)                               
#define TIM_CR1_CMS_Msk                     (0x3UL << TIM_CR1_CMS_Pos)          /*!< 0x00000060 */
#define TIM_CR1_CMS                         TIM_CR1_CMS_Msk                    /*!<CMS[1:0] bits (Center-aligned mode selection) */
#define TIM_CR1_CMS_0                       (0x1UL << TIM_CR1_CMS_Pos)          /*!< 0x00000020 */
#define TIM_CR1_CMS_1                       (0x2UL << TIM_CR1_CMS_Pos)          /*!< 0x00000040 */

#define TIM_CR1_ARPE_Pos                    (7U)                               
#define TIM_CR1_ARPE_Msk                    (0x1UL << TIM_CR1_ARPE_Pos)         /*!< 0x00000080 */
#define TIM_CR1_ARPE                        TIM_CR1_ARPE_Msk                   /*!<Auto-reload preload enable */

#define TIM_CR1_CKD_Pos                     (8U)                               
#define TIM_CR1_CKD_Msk                     (0x3UL << TIM_CR1_CKD_Pos)          /*!< 0x00000300 */
#define TIM_CR1_CKD                         TIM_CR1_CKD_Msk                    /*!<CKD[1:0] bits (clock division) */
#define TIM_CR1_CKD_0                       (0x1UL << TIM_CR1_CKD_Pos)          /*!< 0x00000100 */
#define TIM_CR1_CKD_1                       (0x2UL << TIM_CR1_CKD_Pos)          /*!< 0x00000200 */

/*******************  Bit definition for TIM_CR2 register  *******************/
#define TIM_CR2_CCPC_Pos                    (0U)                               
#define TIM_CR2_CCPC_Msk                    (0x1UL << TIM_CR2_CCPC_Pos)         /*!< 0x00000001 */
#define TIM_CR2_CCPC                        TIM_CR2_CCPC_Msk                   /*!<Capture/Compare Preloaded Control */
#define TIM_CR2_CCUS_Pos                    (2U)                               
#define TIM_CR2_CCUS_Msk                    (0x1UL << TIM_CR2_CCUS_Pos)         /*!< 0x00000004 */
#define TIM_CR2_CCUS                        TIM_CR2_CCUS_Msk                   /*!<Capture/Compare Control Update Selection */
#define TIM_CR2_CCDS_Pos                    (3U)                               
#define TIM_CR2_CCDS_Msk                    (0x1UL << TIM_CR2_CCDS_Pos)         /*!< 0x00000008 */
#define TIM_CR2_CCDS                        TIM_CR2_CCDS_Msk                   /*!<Capture/Compare DMA Selection */

#define TIM_CR2_MMS_Pos                     (4U)                               
#define TIM_CR2_MMS_Msk                     (0x7UL << TIM_CR2_MMS_Pos)          /*!< 0x00000070 */
#define TIM_CR2_MMS                         TIM_CR2_MMS_Msk                    /*!<MMS[2:0] bits (Master Mode Selection) */
#define TIM_CR2_MMS_0                       (0x1UL << TIM_CR2_MMS_Pos)          /*!< 0x00000010 */
#define TIM_CR2_MMS_1                       (0x2UL << TIM_CR2_MMS_Pos)          /*!< 0x00000020 */
#define TIM_CR2_MMS_2                       (0x4UL << TIM_CR2_MMS_Pos)          /*!< 0x00000040 */

#define TIM_CR2_TI1S_Pos                    (7U)                               
#define TIM_CR2_TI1S_Msk                    (0x1UL << TIM_CR2_TI1S_Pos)         /*!< 0x00000080 */
#define TIM_CR2_TI1S                        TIM_CR2_TI1S_Msk                   /*!<TI1 Selection */
#define TIM_CR2_OIS1_Pos                    (8U)                               
#define TIM_CR2_OIS1_Msk                    (0x1UL << TIM_CR2_OIS1_Pos)         /*!< 0x00000100 */
#define TIM_CR2_OIS1                        TIM_CR2_OIS1_Msk                   /*!<Output Idle state 1 (OC1 output) */
#define TIM_CR2_OIS1N_Pos                   (9U)                               
#define TIM_CR2_OIS1N_Msk                   (0x1UL << TIM_CR2_OIS1N_Pos)        /*!< 0x00000200 */
#define TIM_CR2_OIS1N                       TIM_CR2_OIS1N_Msk                  /*!<Output Idle state 1 (OC1N output) */
#define TIM_CR2_OIS2_Pos                    (10U)                              
#define TIM_CR2_OIS2_Msk                    (0x1UL << TIM_CR2_OIS2_Pos)         /*!< 0x00000400 */
#define TIM_CR2_OIS2                        TIM_CR2_OIS2_Msk                   /*!<Output Idle state 2 (OC2 output) */
#define TIM_CR2_OIS2N_Pos                   (11U)                              
#define TIM_CR2_OIS2N_Msk                   (0x1UL << TIM_CR2_OIS2N_Pos)        /*!< 0x00000800 */
#define TIM_CR2_OIS2N                       TIM_CR2_OIS2N_Msk                  /*!<Output Idle state 2 (OC2N output) */
#define TIM_CR2_OIS3_Pos                    (12U)                              
#define TIM_CR2_OIS3_Msk                    (0x1UL << TIM_CR2_OIS3_Pos)         /*!< 0x00001000 */
#define TIM_CR2_OIS3                        TIM_CR2_OIS3_Msk                   /*!<Output Idle state 3 (OC3 output) */
#define TIM_CR2_OIS3N_Pos                   (13U)                              
#define TIM_CR2_OIS3N_Msk                   (0x1UL << TIM_CR2_OIS3N_Pos)        /*!< 0x00002000 */
#define TIM_CR2_OIS3N                       TIM_CR2_OIS3N_Msk                  /*!<Output Idle state 3 (OC3N output) */
#define TIM_CR2_OIS4_Pos                    (14U)                              
#define TIM_CR2_OIS4_Msk                    (0x1UL << TIM_CR2_OIS4_Pos)         /*!< 0x00004000 */
#define TIM_CR2_OIS4                        TIM_CR2_OIS4_Msk                   /*!<Output Idle state 4 (OC4 output) */

/*******************  Bit definition for TIM_SMCR register  ******************/
#define TIM_SMCR_SMS_Pos                    (0U)                               
#define TIM_SMCR_SMS_Msk                    (0x7UL << TIM_SMCR_SMS_Pos)         /*!< 0x00000007 */
#define TIM_SMCR_SMS                        TIM_SMCR_SMS_Msk                   /*!<SMS[2:0] bits (Slave mode selection) */
#define TIM_SMCR_SMS_0                      (0x1UL << TIM_SMCR_SMS_Pos)         /*!< 0x00000001 */
#define TIM_SMCR_SMS_1                      (0x2UL << TIM_SMCR_SMS_Pos)         /*!< 0x00000002 */
#define TIM_SMCR_SMS_2                      (0x4UL << TIM_SMCR_SMS_Pos)         /*!< 0x00000004 */

#define TIM_SMCR_TS_Pos                     (4U)                               
#define TIM_SMCR_TS_Msk                     (0x7UL << TIM_SMCR_TS_Pos)          /*!< 0x00000070 */
#define TIM_SMCR_TS                         TIM_SMCR_TS_Msk                    /*!<TS[2:0] bits (Trigger selection) */
#define TIM_SMCR_TS_0                       (0x1UL << TIM_SMCR_TS_Pos)          /*!< 0x00000010 */
#define TIM_SMCR_TS_1                       (0x2UL << TIM_SMCR_TS_Pos)          /*!< 0x00000020 */
#define TIM_SMCR_TS_2                       (0x4UL << TIM_SMCR_TS_Pos)          /*!< 0x00000040 */

#define TIM_SMCR_MSM_Pos                    (7U)                               
#define TIM_SMCR_MSM_Msk                    (0x1UL << TIM_SMCR_MSM_Pos)         /*!< 0x00000080 */
#define TIM_SMCR_MSM                        TIM_SMCR_MSM_Msk                   /*!<Master/slave mode */

#define TIM_SMCR_ETF_Pos                    (8U)                               
#define TIM_SMCR_ETF_Msk                    (0xFUL << TIM_SMCR_ETF_Pos)         /*!< 0x00000F00 */
#define TIM_SMCR_ETF                        TIM_SMCR_ETF_Msk                   /*!<ETF[3:0] bits (External trigger filter) */
#define TIM_SMCR_ETF_0                      (0x1UL << TIM_SMCR_ETF_Pos)         /*!< 0x00000100 */
#define TIM_SMCR_ETF_1                      (0x2UL << TIM_SMCR_ETF_Pos)         /*!< 0x00000200 */
#define TIM_SMCR_ETF_2                      (0x4UL << TIM_SMCR_ETF_Pos)         /*!< 0x00000400 */
#define TIM_SMCR_ETF_3                      (0x8UL << TIM_SMCR_ETF_Pos)         /*!< 0x00000800 */

#define TIM_SMCR_ETPS_Pos                   (12U)                              
#define TIM_SMCR_ETPS_Msk                   (0x3UL << TIM_SMCR_ETPS_Pos)        /*!< 0x00003000 */
#define TIM_SMCR_ETPS                       TIM_SMCR_ETPS_Msk                  /*!<ETPS[1:0] bits (External trigger prescaler) */
#define TIM_SMCR_ETPS_0                     (0x1UL << TIM_SMCR_ETPS_Pos)        /*!< 0x00001000 */
#define TIM_SMCR_ETPS_1                     (0x2UL << TIM_SMCR_ETPS_Pos)        /*!< 0x00002000 */

#define TIM_SMCR_ECE_Pos                    (14U)                              
#define TIM_SMCR_ECE_Msk                    (0x1UL << TIM_SMCR_ECE_Pos)         /*!< 0x00004000 */
#define TIM_SMCR_ECE                        TIM_SMCR_ECE_Msk                   /*!<External clock enable */
#define TIM_SMCR_ETP_Pos                    (15U)                              
#define TIM_SMCR_ETP_Msk                    (0x1UL << TIM_SMCR_ETP_Pos)         /*!< 0x00008000 */
#define TIM_SMCR_ETP                        TIM_SMCR_ETP_Msk                   /*!<External trigger polarity */

/*******************  Bit definition for TIM_DIER register  ******************/
#define TIM_DIER_UIE_Pos                    (0U)                               
#define TIM_DIER_UIE_Msk                    (0x1UL << TIM_DIER_UIE_Pos)         /*!< 0x00000001 */
#define TIM_DIER_UIE                        TIM_DIER_UIE_Msk                   /*!<Update interrupt enable */
#define TIM_DIER_CC1IE_Pos                  (1U)                               
#define TIM_DIER_CC1IE_Msk                  (0x1UL << TIM_DIER_CC1IE_Pos)       /*!< 0x00000002 */
#define TIM_DIER_CC1IE                      TIM_DIER_CC1IE_Msk                 /*!<Capture/Compare 1 interrupt enable */
#define TIM_DIER_CC2IE_Pos                  (2U)                               
#define TIM_DIER_CC2IE_Msk                  (0x1UL << TIM_DIER_CC2IE_Pos)       /*!< 0x00000004 */
#define TIM_DIER_CC2IE                      TIM_DIER_CC2IE_Msk                 /*!<Capture/Compare 2 interrupt enable */
#define TIM_DIER_CC3IE_Pos                  (3U)                               
#define TIM_DIER_CC3IE_Msk                  (0x1UL << TIM_DIER_CC3IE_Pos)       /*!< 0x00000008 */
#define TIM_DIER_CC3IE                      TIM_DIER_CC3IE_Msk                 /*!<Capture/Compare 3 interrupt enable */
#define TIM_DIER_CC4IE_Pos                  (4U)                               
#define TIM_DIER_CC4IE_Msk                  (0x1UL << TIM_DIER_CC4IE_Pos)       /*!< 0x00000010 */
#define TIM_DIER_CC4IE                      TIM_DIER_CC4IE_Msk                 /*!<Capture/Compare 4 interrupt enable */
#define TIM_DIER_COMIE_Pos                  (5U)                               
#define TIM_DIER_COMIE_Msk                  (0x1UL << TIM_DIER_COMIE_Pos)       /*!< 0x00000020 */
#define TIM_DIER_COMIE                      TIM_DIER_COMIE_Msk                 /*!<COM interrupt enable */
#define TIM_DIER_TIE_Pos                    (6U)                               
#define TIM_DIER_TIE_Msk                    (0x1UL << TIM_DIER_TIE_Pos)         /*!< 0x00000040 */
#define TIM_DIER_TIE                        TIM_DIER_TIE_Msk                   /*!<Trigger interrupt enable */
#define TIM_DIER_BIE_Pos                    (7U)                               
#define TIM_DIER_BIE_Msk                    (0x1UL << TIM_DIER_BIE_Pos)         /*!< 0x00000080 */
#define TIM_DIER_BIE                        TIM_DIER_BIE_Msk                   /*!<Break interrupt enable */
#define TIM_DIER_UDE_Pos                    (8U)                               
#define TIM_DIER_UDE_Msk                    (0x1UL << TIM_DIER_UDE_Pos)         /*!< 0x00000100 */
#define TIM_DIER_UDE                        TIM_DIER_UDE_Msk                   /*!<Update DMA request enable */
#define TIM_DIER_CC1DE_Pos                  (9U)                               
#define TIM_DIER_CC1DE_Msk                  (0x1UL << TIM_DIER_CC1DE_Pos)       /*!< 0x00000200 */
#define TIM_DIER_CC1DE                      TIM_DIER_CC1DE_Msk                 /*!<Capture/Compare 1 DMA request enable */
#define TIM_DIER_CC2DE_Pos                  (10U)                              
#define TIM_DIER_CC2DE_Msk                  (0x1UL << TIM_DIER_CC2DE_Pos)       /*!< 0x00000400 */
#define TIM_DIER_CC2DE                      TIM_DIER_CC2DE_Msk                 /*!<Capture/Compare 2 DMA request enable */
#define TIM_DIER_CC3DE_Pos                  (11U)                              
#define TIM_DIER_CC3DE_Msk                  (0x1UL << TIM_DIER_CC3DE_Pos)       /*!< 0x00000800 */
#define TIM_DIER_CC3DE                      TIM_DIER_CC3DE_Msk                 /*!<Capture/Compare 3 DMA request enable */
#define TIM_DIER_CC4DE_Pos                  (12U)                              
#define TIM_DIER_CC4DE_Msk                  (0x1UL << TIM_DIER_CC4DE_Pos)       /*!< 0x00001000 */
#define TIM_DIER_CC4DE                      TIM_DIER_CC4DE_Msk                 /*!<Capture/Compare 4 DMA request enable */
#define TIM_DIER_COMDE_Pos                  (13U)                              
#define TIM_DIER_COMDE_Msk                  (0x1UL << TIM_DIER_COMDE_Pos)       /*!< 0x00002000 */
#define TIM_DIER_COMDE                      TIM_DIER_COMDE_Msk                 /*!<COM DMA request enable */
#define TIM_DIER_TDE_Pos                    (14U)                              
#define TIM_DIER_TDE_Msk                    (0x1UL << TIM_DIER_TDE_Pos)         /*!< 0x00004000 */
#define TIM_DIER_TDE                        TIM_DIER_TDE_Msk                   /*!<Trigger DMA request enable */

/********************  Bit definition for TIM_SR register  *******************/
#define TIM_SR_UIF_Pos                      (0U)                               
#define TIM_SR_UIF_Msk                      (0x1UL << TIM_SR_UIF_Pos)           /*!< 0x00000001 */
#define TIM_SR_UIF                          TIM_SR_UIF_Msk                     /*!<Update interrupt Flag */
#define TIM_SR_CC1IF_Pos                    (1U)                               
#define TIM_SR_CC1IF_Msk                    (0x1UL << TIM_SR_CC1IF_Pos)         /*!< 0x00000002 */
#define TIM_SR_CC1IF                        TIM_SR_CC1IF_Msk                   /*!<Capture/Compare 1 interrupt Flag */
#define TIM_SR_CC2IF_Pos                    (2U)                               
#define TIM_SR_CC2IF_Msk                    (0x1UL << TIM_SR_CC2IF_Pos)         /*!< 0x00000004 */
#define TIM_SR_CC2IF                        TIM_SR_CC2IF_Msk                   /*!<Capture/Compare 2 interrupt Flag */
#define TIM_SR_CC3IF_Pos                    (3U)                               
#define TIM_SR_CC3IF_Msk                    (0x1UL << TIM_SR_CC3IF_Pos)         /*!< 0x00000008 */
#define TIM_SR_CC3IF                        TIM_SR_CC3IF_Msk                   /*!<Capture/Compare 3 interrupt Flag */
#define TIM_SR_CC4IF_Pos                    (4U)                               
#define TIM_SR_CC4IF_Msk                    (0x1UL << TIM_SR_CC4IF_Pos)         /*!< 0x00000010 */
#define TIM_SR_CC4IF                        TIM_SR_CC4IF_Msk                   /*!<Capture/Compare 4 interrupt Flag */
#define TIM_SR_COMIF_Pos                    (5U)                               
#define TIM_SR_COMIF_Msk                    (0x1UL << TIM_SR_COMIF_Pos)         /*!< 0x00000020 */
#define TIM_SR_COMIF                        TIM_SR_COMIF_Msk                   /*!<COM interrupt Flag */
#define TIM_SR_TIF_Pos                      (6U)                               
#define TIM_SR_TIF_Msk                      (0x1UL << TIM_SR_TIF_Pos)           /*!< 0x00000040 */
#define TIM_SR_TIF                          TIM_SR_TIF_Msk                     /*!<Trigger interrupt Flag */
#define TIM_SR_BIF_Pos                      (7U)                               
#define TIM_SR_BIF_Msk                      (0x1UL << TIM_SR_BIF_Pos)           /*!< 0x00000080 */
#define TIM_SR_BIF                          TIM_SR_BIF_Msk                     /*!<Break interrupt Flag */
#define TIM_SR_CC1OF_Pos                    (9U)                               
#define TIM_SR_CC1OF_Msk                    (0x1UL << TIM_SR_CC1OF_Pos)         /*!< 0x00000200 */
#define TIM_SR_CC1OF                        TIM_SR_CC1OF_Msk                   /*!<Capture/Compare 1 Overcapture Flag */
#define TIM_SR_CC2OF_Pos                    (10U)                              
#define TIM_SR_CC2OF_Msk                    (0x1UL << TIM_SR_CC2OF_Pos)         /*!< 0x00000400 */
#define TIM_SR_CC2OF                        TIM_SR_CC2OF_Msk                   /*!<Capture/Compare 2 Overcapture Flag */
#define TIM_SR_CC3OF_Pos                    (11U)                              
#define TIM_SR_CC3OF_Msk                    (0x1UL << TIM_SR_CC3OF_Pos)         /*!< 0x00000800 */
#define TIM_SR_CC3OF                        TIM_SR_CC3OF_Msk                   /*!<Capture/Compare 3 Overcapture Flag */
#define TIM_SR_CC4OF_Pos                    (12U)                              
#define TIM_SR_CC4OF_Msk                    (0x1UL << TIM_SR_CC4OF_Pos)         /*!< 0x00001000 */
#define TIM_SR_CC4OF                        TIM_SR_CC4OF_Msk                   /*!<Capture/Compare 4 Overcapture Flag */

/*******************  Bit definition for TIM_EGR register  *******************/
#define TIM_EGR_UG_Pos                      (0U)                               
#define TIM_EGR_UG_Msk                      (0x1UL << TIM_EGR_UG_Pos)           /*!< 0x00000001 */
#define TIM_EGR_UG                          TIM_EGR_UG_Msk                     /*!<Update Generation */
#define TIM_EGR_CC1G_Pos                    (1U)                               
#define TIM_EGR_CC1G_Msk                    (0x1UL << TIM_EGR_CC1G_Pos)         /*!< 0x00000002 */
#define TIM_EGR_CC1G                        TIM_EGR_CC1G_Msk                   /*!<Capture/Compare 1 Generation */
#define TIM_EGR_CC2G_Pos                    (2U)                               
#define TIM_EGR_CC2G_Msk                    (0x1UL << TIM_EGR_CC2G_Pos)         /*!< 0x00000004 */
#define TIM_EGR_CC2G                        TIM_EGR_CC2G_Msk                   /*!<Capture/Compare 2 Generation */
#define TIM_EGR_CC3G_Pos                    (3U)                               
#define TIM_EGR_CC3G_Msk                    (0x1UL << TIM_EGR_CC3G_Pos)         /*!< 0x00000008 */
#define TIM_EGR_CC3G                        TIM_EGR_CC3G_Msk                   /*!<Capture/Compare 3 Generation */
#define TIM_EGR_CC4G_Pos                    (4U)                               
#define TIM_EGR_CC4G_Msk                    (0x1UL << TIM_EGR_CC4G_Pos)         /*!< 0x00000010 */
#define TIM_EGR_CC4G                        TIM_EGR_CC4G_Msk                   /*!<Capture/Compare 4 Generation */
#define TIM_EGR_COMG_Pos                    (5U)                               
#define TIM_EGR_COMG_Msk                    (0x1UL << TIM_EGR_COMG_Pos)         /*!< 0x00000020 */
#define TIM_EGR_COMG                        TIM_EGR_COMG_Msk                   /*!<Capture/Compare Control Update Generation */
#define TIM_EGR_TG_Pos                      (6U)                               
#define TIM_EGR_TG_Msk                      (0x1UL << TIM_EGR_TG_Pos)           /*!< 0x00000040 */
#define TIM_EGR_TG                          TIM_EGR_TG_Msk                     /*!<Trigger Generation */
#define TIM_EGR_BG_Pos                      (7U)                               
#define TIM_EGR_BG_Msk                      (0x1UL << TIM_EGR_BG_Pos)           /*!< 0x00000080 */
#define TIM_EGR_BG                          TIM_EGR_BG_Msk                     /*!<Break Generation */

/******************  Bit definition for TIM_CCMR1 register  ******************/
#define TIM_CCMR1_CC1S_Pos                  (0U)                               
#define TIM_CCMR1_CC1S_Msk                  (0x3UL << TIM_CCMR1_CC1S_Pos)       /*!< 0x00000003 */
#define TIM_CCMR1_CC1S                      TIM_CCMR1_CC1S_Msk                 /*!<CC1S[1:0] bits (Capture/Compare 1 Selection) */
#define TIM_CCMR1_CC1S_0                    (0x1UL << TIM_CCMR1_CC1S_Pos)       /*!< 0x00000001 */
#define TIM_CCMR1_CC1S_1                    (0x2UL << TIM_CCMR1_CC1S_Pos)       /*!< 0x00000002 */

#define TIM_CCMR1_OC1FE_Pos                 (2U)                               
#define TIM_CCMR1_OC1FE_Msk                 (0x1UL << TIM_CCMR1_OC1FE_Pos)      /*!< 0x00000004 */
#define TIM_CCMR1_OC1FE                     TIM_CCMR1_OC1FE_Msk                /*!<Output Compare 1 Fast enable */
#define TIM_CCMR1_OC1PE_Pos                 (3U)                               
#define TIM_CCMR1_OC1PE_Msk                 (0x1UL << TIM_CCMR1_OC1PE_Pos)      /*!< 0x00000008 */
#define TIM_CCMR1_OC1PE                     TIM_CCMR1_OC1PE_Msk                /*!<Output Compare 1 Preload enable */

#define TIM_CCMR1_OC1M_Pos                  (4U)                               
#define TIM_CCMR1_OC1M_Msk                  (0x7UL << TIM_CCMR1_OC1M_Pos)       /*!< 0x00000070 */
#define TIM_CCMR1_OC1M                      TIM_CCMR1_OC1M_Msk                 /*!<OC1M[2:0] bits (Output Compare 1 Mode) */
#define TIM_CCMR1_OC1M_0                    (0x1UL << TIM_CCMR1_OC1M_Pos)       /*!< 0x00000010 */
#define TIM_CCMR1_OC1M_1                    (0x2UL << TIM_CCMR1_OC1M_Pos)       /*!< 0x00000020 */
#define TIM_CCMR1_OC1M_2                    (0x4UL << TIM_CCMR1_OC1M_Pos)       /*!< 0x00000040 */

#define TIM_CCMR1_OC1CE_Pos                 (7U)                               
#define TIM_CCMR1_OC1CE_Msk                 (0x1UL << TIM_CCMR1_OC1CE_Pos)      /*!< 0x00000080 */
#define TIM_CCMR1_OC1CE                     TIM_CCMR1_OC1CE_Msk                /*!<Output Compare 1Clear Enable */

#define TIM_CCMR1_CC2S_Pos                  (8U)                               
#define TIM_CCMR1_CC2S_Msk                  (0x3UL << TIM_CCMR1_CC2S_Pos)       /*!< 0x00000300 */
#define TIM_CCMR1_CC2S                      TIM_CCMR1_CC2S_Msk                 /*!<CC2S[1:0] bits (Capture/Compare 2 Selection) */
#define TIM_CCMR1_CC2S_0                    (0x1UL << TIM_CCMR1_CC2S_Pos)       /*!< 0x00000100 */
#define TIM_CCMR1_CC2S_1                    (0x2UL << TIM_CCMR1_CC2S_Pos)       /*!< 0x00000200 */

#define TIM_CCMR1_OC2FE_Pos                 (10U)                              
#define TIM_CCMR1_OC2FE_Msk                 (0x1UL << TIM_CCMR1_OC2FE_Pos)      /*!< 0x00000400 */
#define TIM_CCMR1_OC2FE                     TIM_CCMR1_OC2FE_Msk                /*!<Output Compare 2 Fast enable */
#define TIM_CCMR1_OC2PE_Pos                 (11U)                              
#define TIM_CCMR1_OC2PE_Msk                 (0x1UL << TIM_CCMR1_OC2PE_Pos)      /*!< 0x00000800 */
#define TIM_CCMR1_OC2PE                     TIM_CCMR1_OC2PE_Msk                /*!<Output Compare 2 Preload enable */

#define TIM_CCMR1_OC2M_Pos                  (12U)                              
#define TIM_CCMR1_OC2M_Msk                  (0x7UL << TIM_CCMR1_OC2M_Pos)       /*!< 0x00007000 */
#define TIM_CCMR1_OC2M                      TIM_CCMR1_OC2M_Msk                 /*!<OC2M[2:0] bits (Output Compare 2 Mode) */
#define TIM_CCMR1_OC2M_0                    (0x1UL << TIM_CCMR1_OC2M_Pos)       /*!< 0x00001000 */
#define TIM_CCMR1_OC2M_1                    (0x2UL << TIM_CCMR1_OC2M_Pos)       /*!< 0x00002000 */
#define TIM_CCMR1_OC2M_2                    (0x4UL << TIM_CCMR1_OC2M_Pos)       /*!< 0x00004000 */

#define TIM_CCMR1_OC2CE_Pos                 (15U)                              
#define TIM_CCMR1_OC2CE_Msk                 (0x1UL << TIM_CCMR1_OC2CE_Pos)      /*!< 0x00008000 */
#define TIM_CCMR1_OC2CE                     TIM_CCMR1_OC2CE_Msk                /*!<Output Compare 2 Clear Enable */

/*---------------------------------------------------------------------------*/

#define TIM_CCMR1_IC1PSC_Pos                (2U)                               
#define TIM_CCMR1_IC1PSC_Msk                (0x3UL << TIM_CCMR1_IC1PSC_Pos)     /*!< 0x0000000C */
#define TIM_CCMR1_IC1PSC                    TIM_CCMR1_IC1PSC_Msk               /*!<IC1PSC[1:0] bits (Input Capture 1 Prescaler) */
#define TIM_CCMR1_IC1PSC_0                  (0x1UL << TIM_CCMR1_IC1PSC_Pos)     /*!< 0x00000004 */
#define TIM_CCMR1_IC1PSC_1                  (0x2UL << TIM_CCMR1_IC1PSC_Pos)     /*!< 0x00000008 */

#define TIM_CCMR1_IC1F_Pos                  (4U)                               
#define TIM_CCMR1_IC1F_Msk                  (0xFUL << TIM_CCMR1_IC1F_Pos)       /*!< 0x000000F0 */
#define TIM_CCMR1_IC1F                      TIM_CCMR1_IC1F_Msk                 /*!<IC1F[3:0] bits (Input Capture 1 Filter) */
#define TIM_CCMR1_IC1F_0                    (0x1UL << TIM_CCMR1_IC1F_Pos)       /*!< 0x00000010 */
#define TIM_CCMR1_IC1F_1                    (0x2UL << TIM_CCMR1_IC1F_Pos)       /*!< 0x00000020 */
#define TIM_CCMR1_IC1F_2                    (0x4UL << TIM_CCMR1_IC1F_Pos)       /*!< 0x00000040 */
#define TIM_CCMR1_IC1F_3                    (0x8UL << TIM_CCMR1_IC1F_Pos)       /*!< 0x00000080 */

#define TIM_CCMR1_IC2PSC_Pos                (10U)                              
#define TIM_CCMR1_IC2PSC_Msk                (0x3UL << TIM_CCMR1_IC2PSC_Pos)     /*!< 0x00000C00 */
#define TIM_CCMR1_IC2PSC                    TIM_CCMR1_IC2PSC_Msk               /*!<IC2PSC[1:0] bits (Input Capture 2 Prescaler) */
#define TIM_CCMR1_IC2PSC_0                  (0x1UL << TIM_CCMR1_IC2PSC_Pos)     /*!< 0x00000400 */
#define TIM_CCMR1_IC2PSC_1                  (0x2UL << TIM_CCMR1_IC2PSC_Pos)     /*!< 0x00000800 */

#define TIM_CCMR1_IC2F_Pos                  (12U)                              
#define TIM_CCMR1_IC2F_Msk                  (0xFUL << TIM_CCMR1_IC2F_Pos)       /*!< 0x0000F000 */
#define TIM_CCMR1_IC2F                      TIM_CCMR1_IC2F_Msk                 /*!<IC2F[3:0] bits (Input Capture 2 Filter) */
#define TIM_CCMR1_IC2F_0                    (0x1UL << TIM_CCMR1_IC2F_Pos)       /*!< 0x00001000 */
#define TIM_CCMR1_IC2F_1                    (0x2UL << TIM_CCMR1_IC2F_Pos)       /*!< 0x00002000 */
#define TIM_CCMR1_IC2F_2                    (0x4UL << TIM_CCMR1_IC2F_Pos)       /*!< 0x00004000 */
#define TIM_CCMR1_IC2F_3                    (0x8UL << TIM_CCMR1_IC2F_Pos)       /*!< 0x00008000 */

/******************  Bit definition for TIM_CCMR2 register  ******************/
#define TIM_CCMR2_CC3S_Pos                  (0U)                               
#define TIM_CCMR2_CC3S_Msk                  (0x3UL << TIM_CCMR2_CC3S_Pos)       /*!< 0x00000003 */
#define TIM_CCMR2_CC3S                      TIM_CCMR2_CC3S_Msk                 /*!<CC3S[1:0] bits (Capture/Compare 3 Selection) */
#define TIM_CCMR2_CC3S_0                    (0x1UL << TIM_CCMR2_CC3S_Pos)       /*!< 0x00000001 */
#define TIM_CCMR2_CC3S_1                    (0x2UL << TIM_CCMR2_CC3S_Pos)       /*!< 0x00000002 */

#define TIM_CCMR2_OC3FE_Pos                 (2U)                               
#define TIM_CCMR2_OC3FE_Msk                 (0x1UL << TIM_CCMR2_OC3FE_Pos)      /*!< 0x00000004 */
#define TIM_CCMR2_OC3FE                     TIM_CCMR2_OC3FE_Msk                /*!<Output Compare 3 Fast enable */
#define TIM_CCMR2_OC3PE_Pos                 (3U)                               
#define TIM_CCMR2_OC3PE_Msk                 (0x1UL << TIM_CCMR2_OC3PE_Pos)      /*!< 0x00000008 */
#define TIM_CCMR2_OC3PE                     TIM_CCMR2_OC3PE_Msk                /*!<Output Compare 3 Preload enable */

#define TIM_CCMR2_OC3M_Pos                  (4U)                               
#define TIM_CCMR2_OC3M_Msk                  (0x7UL << TIM_CCMR2_OC3M_Pos)       /*!< 0x00000070 */
#define TIM_CCMR2_OC3M                      TIM_CCMR2_OC3M_Msk                 /*!<OC3M[2:0] bits (Output Compare 3 Mode) */
#define TIM_CCMR2_OC3M_0                    (0x1UL << TIM_CCMR2_OC3M_Pos)       /*!< 0x00000010 */
#define TIM_CCMR2_OC3M_1                    (0x2UL << TIM_CCMR2_OC3M_Pos)       /*!< 0x00000020 */
#define TIM_CCMR2_OC3M_2                    (0x4UL << TIM_CCMR2_OC3M_Pos)       /*!< 0x00000040 */

#define TIM_CCMR2_OC3CE_Pos                 (7U)                               
#define TIM_CCMR2_OC3CE_Msk                 (0x1UL << TIM_CCMR2_OC3CE_Pos)      /*!< 0x00000080 */
#define TIM_CCMR2_OC3CE                     TIM_CCMR2_OC3CE_Msk                /*!<Output Compare 3 Clear Enable */

#define TIM_CCMR2_CC4S_Pos                  (8U)                               
#define TIM_CCMR2_CC4S_Msk                  (0x3UL << TIM_CCMR2_CC4S_Pos)       /*!< 0x00000300 */
#define TIM_CCMR2_CC4S                      TIM_CCMR2_CC4S_Msk                 /*!<CC4S[1:0] bits (Capture/Compare 4 Selection) */
#define TIM_CCMR2_CC4S_0                    (0x1UL << TIM_CCMR2_CC4S_Pos)       /*!< 0x00000100 */
#define TIM_CCMR2_CC4S_1                    (0x2UL << TIM_CCMR2_CC4S_Pos)       /*!< 0x00000200 */

#define TIM_CCMR2_OC4FE_Pos                 (10U)                              
#define TIM_CCMR2_OC4FE_Msk                 (0x1UL << TIM_CCMR2_OC4FE_Pos)      /*!< 0x00000400 */
#define TIM_CCMR2_OC4FE                     TIM_CCMR2_OC4FE_Msk                /*!<Output Compare 4 Fast enable */
#define TIM_CCMR2_OC4PE_Pos                 (11U)                              
#define TIM_CCMR2_OC4PE_Msk                 (0x1UL << TIM_CCMR2_OC4PE_Pos)      /*!< 0x00000800 */
#define TIM_CCMR2_OC4PE                     TIM_CCMR2_OC4PE_Msk                /*!<Output Compare 4 Preload enable */

#define TIM_CCMR2_OC4M_Pos                  (12U)                              
#define TIM_CCMR2_OC4M_Msk                  (0x7UL << TIM_CCMR2_OC4M_Pos)       /*!< 0x00007000 */
#define TIM_CCMR2_OC4M                      TIM_CCMR2_OC4M_Msk                 /*!<OC4M[2:0] bits (Output Compare 4 Mode) */
#define TIM_CCMR2_OC4M_0                    (0x1UL << TIM_CCMR2_OC4M_Pos)       /*!< 0x00001000 */
#define TIM_CCMR2_OC4M_1                    (0x2UL << TIM_CCMR2_OC4M_Pos)       /*!< 0x00002000 */
#define TIM_CCMR2_OC4M_2                    (0x4UL << TIM_CCMR2_OC4M_Pos)       /*!< 0x00004000 */

#define TIM_CCMR2_OC4CE_Pos                 (15U)                              
#define TIM_CCMR2_OC4CE_Msk                 (0x1UL << TIM_CCMR2_OC4CE_Pos)      /*!< 0x00008000 */
#define TIM_CCMR2_OC4CE                     TIM_CCMR2_OC4CE_Msk                /*!<Output Compare 4 Clear Enable */

/*---------------------------------------------------------------------------*/

#define TIM_CCMR2_IC3PSC_Pos                (2U)                               
#define TIM_CCMR2_IC3PSC_Msk                (0x3UL << TIM_CCMR2_IC3PSC_Pos)     /*!< 0x0000000C */
#define TIM_CCMR2_IC3PSC                    TIM_CCMR2_IC3PSC_Msk               /*!<IC3PSC[1:0] bits (Input Capture 3 Prescaler) */
#define TIM_CCMR2_IC3PSC_0                  (0x1UL << TIM_CCMR2_IC3PSC_Pos)     /*!< 0x00000004 */
#define TIM_CCMR2_IC3PSC_1                  (0x2UL << TIM_CCMR2_IC3PSC_Pos)     /*!< 0x00000008 */

#define TIM_CCMR2_IC3F_Pos                  (4U)                               
#define TIM_CCMR2_IC3F_Msk                  (0xFUL << TIM_CCMR2_IC3F_Pos)       /*!< 0x000000F0 */
#define TIM_CCMR2_IC3F                      TIM_CCMR2_IC3F_Msk                 /*!<IC3F[3:0] bits (Input Capture 3 Filter) */
#define TIM_CCMR2_IC3F_0                    (0x1UL << TIM_CCMR2_IC3F_Pos)       /*!< 0x00000010 */
#define TIM_CCMR2_IC3F_1                    (0x2UL << TIM_CCMR2_IC3F_Pos)       /*!< 0x00000020 */
#define TIM_CCMR2_IC3F_2                    (0x4UL << TIM_CCMR2_IC3F_Pos)       /*!< 0x00000040 */
#define TIM_CCMR2_IC3F_3                    (0x8UL << TIM_CCMR2_IC3F_Pos)       /*!< 0x00000080 */

#define TIM_CCMR2_IC4PSC_Pos                (10U)                              
#define TIM_CCMR2_IC4PSC_Msk                (0x3UL << TIM_CCMR2_IC4PSC_Pos)     /*!< 0x00000C00 */
#define TIM_CCMR2_IC4PSC                    TIM_CCMR2_IC4PSC_Msk               /*!<IC4PSC[1:0] bits (Input Capture 4 Prescaler) */
#define TIM_CCMR2_IC4PSC_0                  (0x1UL << TIM_CCMR2_IC4PSC_Pos)     /*!< 0x00000400 */
#define TIM_CCMR2_IC4PSC_1                  (0x2UL << TIM_CCMR2_IC4PSC_Pos)     /*!< 0x00000800 */

#define TIM_CCMR2_IC4F_Pos                  (12U)                              
#define TIM_CCMR2_IC4F_Msk                  (0xFUL << TIM_CCMR2_IC4F_Pos)       /*!< 0x0000F000 */
#define TIM_CCMR2_IC4F                      TIM_CCMR2_IC4F_Msk                 /*!<IC4F[3:0] bits (Input Capture 4 Filter) */
#define TIM_CCMR2_IC4F_0                    (0x1UL << TIM_CCMR2_IC4F_Pos)       /*!< 0x00001000 */
#define TIM_CCMR2_IC4F_1                    (0x2UL << TIM_CCMR2_IC4F_Pos)       /*!< 0x00002000 */
#define TIM_CCMR2_IC4F_2                    (0x4UL << TIM_CCMR2_IC4F_Pos)       /*!< 0x00004000 */
#define TIM_CCMR2_IC4F_3                    (0x8UL << TIM_CCMR2_IC4F_Pos)       /*!< 0x00008000 */

/*******************  Bit definition for TIM_CCER register  ******************/
#define TIM_CCER_CC1E_Pos                   (0U)                               
#define TIM_CCER_CC1E_Msk                   (0x1UL << TIM_CCER_CC1E_Pos)        /*!< 0x00000001 */
#define TIM_CCER_CC1E                       TIM_CCER_CC1E_Msk                  /*!<Capture/Compare 1 output enable */
#define TIM_CCER_CC1P_Pos                   (1U)                               
#define TIM_CCER_CC1P_Msk                   (0x1UL << TIM_CCER_CC1P_Pos)        /*!< 0x00000002 */
#define TIM_CCER_CC1P                       TIM_CCER_CC1P_Msk                  /*!<Capture/Compare 1 output Polarity */
#define TIM_CCER_CC1NE_Pos                  (2U)                               
#define TIM_CCER_CC1NE_Msk                  (0x1UL << TIM_CCER_CC1NE_Pos)       /*!< 0x00000004 */
#define TIM_CCER_CC1NE                      TIM_CCER_CC1NE_Msk                 /*!<Capture/Compare 1 Complementary output enable */
#define TIM_CCER_CC1NP_Pos                  (3U)                               
#define TIM_CCER_CC1NP_Msk                  (0x1UL << TIM_CCER_CC1NP_Pos)       /*!< 0x00000008 */
#define TIM_CCER_CC1NP                      TIM_CCER_CC1NP_Msk                 /*!<Capture/Compare 1 Complementary output Polarity */
#define TIM_CCER_CC2E_Pos                   (4U)                               
#define TIM_CCER_CC2E_Msk                   (0x1UL << TIM_CCER_CC2E_Pos)        /*!< 0x00000010 */
#define TIM_CCER_CC2E                       TIM_CCER_CC2E_Msk                  /*!<Capture/Compare 2 output enable */
#define TIM_CCER_CC2P_Pos                   (5U)                               
#define TIM_CCER_CC2P_Msk                   (0x1UL << TIM_CCER_CC2P_Pos)        /*!< 0x00000020 */
#define TIM_CCER_CC2P                       TIM_CCER_CC2P_Msk                  /*!<Capture/Compare 2 output Polarity */
#define TIM_CCER_CC2NE_Pos                  (6U)                               
#define TIM_CCER_CC2NE_Msk                  (0x1UL << TIM_CCER_CC2NE_Pos)       /*!< 0x00000040 */
#define TIM_CCER_CC2NE                      TIM_CCER_CC2NE_Msk                 /*!<Capture/Compare 2 Complementary output enable */
#define TIM_CCER_CC2NP_Pos                  (7U)                               
#define TIM_CCER_CC2NP_Msk                  (0x1UL << TIM_CCER_CC2NP_Pos)       /*!< 0x00000080 */
#define TIM_CCER_CC2NP                      TIM_CCER_CC2NP_Msk                 /*!<Capture/Compare 2 Complementary output Polarity */
#define TIM_CCER_CC3E_Pos                   (8U)                               
#define TIM_CCER_CC3E_Msk                   (0x1UL << TIM_CCER_CC3E_Pos)        /*!< 0x00000100 */
#define TIM_CCER_CC3E                       TIM_CCER_CC3E_Msk                  /*!<Capture/Compare 3 output enable */
#define TIM_CCER_CC3P_Pos                   (9U)                               
#define TIM_CCER_CC3P_Msk                   (0x1UL << TIM_CCER_CC3P_Pos)        /*!< 0x00000200 */
#define TIM_CCER_CC3P                       TIM_CCER_CC3P_Msk                  /*!<Capture/Compare 3 output Polarity */
#define TIM_CCER_CC3NE_Pos                  (10U)                              
#define TIM_CCER_CC3NE_Msk                  (0x1UL << TIM_CCER_CC3NE_Pos)       /*!< 0x00000400 */
#define TIM_CCER_CC3NE                      TIM_CCER_CC3NE_Msk                 /*!<Capture/Compare 3 Complementary output enable */
#define TIM_CCER_CC3NP_Pos                  (11U)                              
#define TIM_CCER_CC3NP_Msk                  (0x1UL << TIM_CCER_CC3NP_Pos)       /*!< 0x00000800 */
#define TIM_CCER_CC3NP                      TIM_CCER_CC3NP_Msk                 /*!<Capture/Compare 3 Complementary output Polarity */
#define TIM_CCER_CC4E_Pos                   (12U)                              
#define TIM_CCER_CC4E_Msk                   (0x1UL << TIM_CCER_CC4E_Pos)        /*!< 0x00001000 */
#define TIM_CCER_CC4E                       TIM_CCER_CC4E_Msk                  /*!<Capture/Compare 4 output enable */
#define TIM_CCER_CC4P_Pos                   (13U)                              
#define TIM_CCER_CC4P_Msk                   (0x1UL << TIM_CCER_CC4P_Pos)        /*!< 0x00002000 */
#define TIM_CCER_CC4P                       TIM_CCER_CC4P_Msk                  /*!<Capture/Compare 4 output Polarity */

/*******************  Bit definition for TIM_CNT register  *******************/
#define TIM_CNT_CNT_Pos                     (0U)                               
#define TIM_CNT_CNT_Msk                     (0xFFFFFFFFUL << TIM_CNT_CNT_Pos)   /*!< 0xFFFFFFFF */
#define TIM_CNT_CNT                         TIM_CNT_CNT_Msk                    /*!<Counter Value */

/*******************  Bit definition for TIM_PSC register  *******************/
#define TIM_PSC_PSC_Pos                     (0U)                               
#define TIM_PSC_PSC_Msk                     (0xFFFFUL << TIM_PSC_PSC_Pos)       /*!< 0x0000FFFF */
#define TIM_PSC_PSC                         TIM_PSC_PSC_Msk                    /*!<Prescaler Value */

/*******************  Bit definition for TIM_ARR register  *******************/
#define TIM_ARR_ARR_Pos                     (0U)                               
#define TIM_ARR_ARR_Msk                     (0xFFFFFFFFUL << TIM_ARR_ARR_Pos)   /*!< 0xFFFFFFFF */
#define TIM_ARR_ARR                         TIM_ARR_ARR_Msk                    /*!<actual auto-reload Value */

/*******************  Bit definition for TIM_RCR register  *******************/
#define TIM_RCR_REP_Pos                     (0U)                               
#define TIM_RCR_REP_Msk                     (0xFFUL << TIM_RCR_REP_Pos)         /*!< 0x000000FF */
#define TIM_RCR_REP                         TIM_RCR_REP_Msk                    /*!<Repetition Counter Value */

/*******************  Bit definition for TIM_CCR1 register  ******************/
#define TIM_CCR1_CCR1_Pos                   (0U)                               
#define TIM_CCR1_CCR1_Msk                   (0xFFFFUL << TIM_CCR1_CCR1_Pos)     /*!< 0x0000FFFF */
#define TIM_CCR1_CCR1                       TIM_CCR1_CCR1_Msk                  /*!<Capture/Compare 1 Value */

/*******************  Bit definition for TIM_CCR2 register  ******************/
#define TIM_CCR2_CCR2_Pos                   (0U)                               
#define TIM_CCR2_CCR2_Msk                   (0xFFFFUL << TIM_CCR2_CCR2_Pos)     /*!< 0x0000FFFF */
#define TIM_CCR2_CCR2                       TIM_CCR2_CCR2_Msk                  /*!<Capture/Compare 2 Value */

/*******************  Bit definition for TIM_CCR3 register  ******************/
#define TIM_CCR3_CCR3_Pos                   (0U)                               
#define TIM_CCR3_CCR3_Msk                   (0xFFFFUL << TIM_CCR3_CCR3_Pos)     /*!< 0x0000FFFF */
#define TIM_CCR3_CCR3                       TIM_CCR3_CCR3_Msk                  /*!<Capture/Compare 3 Value */

/*******************  Bit definition for TIM_CCR4 register  ******************/
#define TIM_CCR4_CCR4_Pos                   (0U)                               
#define TIM_CCR4_CCR4_Msk                   (0xFFFFUL << TIM_CCR4_CCR4_Pos)     /*!< 0x0000FFFF */
#define TIM_CCR4_CCR4                       TIM_CCR4_CCR4_Msk                  /*!<Capture/Compare 4 Value */

/*******************  Bit definition for TIM_BDTR register  ******************/
#define TIM_BDTR_DTG_Pos                    (0U)                               
#define TIM_BDTR_DTG_Msk                    (0xFFUL << TIM_BDTR_DTG_Pos)        /*!< 0x000000FF */
#define TIM_BDTR_DTG                        TIM_BDTR_DTG_Msk                   /*!<DTG[0:7] bits (Dead-Time Generator set-up) */
#define TIM_BDTR_DTG_0                      (0x01UL << TIM_BDTR_DTG_Pos)        /*!< 0x00000001 */
#define TIM_BDTR_DTG_1                      (0x02UL << TIM_BDTR_DTG_Pos)        /*!< 0x00000002 */
#define TIM_BDTR_DTG_2                      (0x04UL << TIM_BDTR_DTG_Pos)        /*!< 0x00000004 */
#define TIM_BDTR_DTG_3                      (0x08UL << TIM_BDTR_DTG_Pos)        /*!< 0x00000008 */
#define TIM_BDTR_DTG_4                      (0x10UL << TIM_BDTR_DTG_Pos)        /*!< 0x00000010 */
#define TIM_BDTR_DTG_5                      (0x20UL << TIM_BDTR_DTG_Pos)        /*!< 0x00000020 */
#define TIM_BDTR_DTG_6                      (0x40UL << TIM_BDTR_DTG_Pos)        /*!< 0x00000040 */
#define TIM_BDTR_DTG_7                      (0x80UL << TIM_BDTR_DTG_Pos)        /*!< 0x00000080 */

#define TIM_BDTR_LOCK_Pos                   (8U)                               
#define TIM_BDTR_LOCK_Msk                   (0x3UL << TIM_BDTR_LOCK_Pos)        /*!< 0x00000300 */
#define TIM_BDTR_LOCK                       TIM_BDTR_LOCK_Msk                  /*!<LOCK[1:0] bits (Lock Configuration) */
#define TIM_BDTR_LOCK_0                     (0x1UL << TIM_BDTR_LOCK_Pos)        /*!< 0x00000100 */
#define TIM_BDTR_LOCK_1                     (0x2UL << TIM_BDTR_LOCK_Pos)        /*!< 0x00000200 */

#define TIM_BDTR_OSSI_Pos                   (10U)                              
#define TIM_BDTR_OSSI_Msk                   (0x1UL << TIM_BDTR_OSSI_Pos)        /*!< 0x00000400 */
#define TIM_BDTR_OSSI                       TIM_BDTR_OSSI_Msk                  /*!<Off-State Selection for Idle mode */
#define TIM_BDTR_OSSR_Pos                   (11U)                              
#define TIM_BDTR_OSSR_Msk                   (0x1UL << TIM_BDTR_OSSR_Pos)        /*!< 0x00000800 */
#define TIM_BDTR_OSSR                       TIM_BDTR_OSSR_Msk                  /*!<Off-State Selection for Run mode */
#define TIM_BDTR_BKE_Pos                    (12U)                              
#define TIM_BDTR_BKE_Msk                    (0x1UL << TIM_BDTR_BKE_Pos)         /*!< 0x00001000 */
#define TIM_BDTR_BKE                        TIM_BDTR_BKE_Msk                   /*!<Break enable */
#define TIM_BDTR_BKP_Pos                    (13U)                              
#define TIM_BDTR_BKP_Msk                    (0x1UL << TIM_BDTR_BKP_Pos)         /*!< 0x00002000 */
#define TIM_BDTR_BKP                        TIM_BDTR_BKP_Msk                   /*!<Break Polarity */
#define TIM_BDTR_AOE_Pos                    (14U)                              
#define TIM_BDTR_AOE_Msk                    (0x1UL << TIM_BDTR_AOE_Pos)         /*!< 0x00004000 */
#define TIM_BDTR_AOE                        TIM_BDTR_AOE_Msk                   /*!<Automatic Output enable */
#define TIM_BDTR_MOE_Pos                    (15U)                              
#define TIM_BDTR_MOE_Msk                    (0x1UL << TIM_BDTR_MOE_Pos)         /*!< 0x00008000 */
#define TIM_BDTR_MOE                        TIM_BDTR_MOE_Msk                   /*!<Main Output enable */

/**
  * @}
*/

/**
  * @}
*/

/** @addtogroup Exported_macro
  * @{
  */

/****************************** DMA Instances *********************************/
#define IS_DMA_ALL_INSTANCE(INSTANCE) (((INSTANCE) == DMA_Channel0) || \
                                       ((INSTANCE) == DMA_Channel1) || \
                                       ((INSTANCE) == DMA_Channel2) || \
                                       ((INSTANCE) == DMA_Channel3) || \
                                       ((INSTANCE) == DMA_Channel4) || \
                                       ((INSTANCE) == DMA_Channel5) || \
                                       ((INSTANCE) == DMA_Channel6) || \
                                       ((INSTANCE) == DMA_Channel7))

/******************************** SPI Instances *******************************/
#define IS_SPI_FLASH_INSTANCE(INSTANCE) (((INSTANCE) == SPI0) || \
                                         ((INSTANCE) == SPI1))

#define IS_SPI_IO_INSTANCE(INSTANCE) (((INSTANCE) == SPI2) || \
                                      ((INSTANCE) == SPI3))

/****************************** START TIM Instances ***************************/
/****************************** TIM Instances *********************************/
#define IS_TIM_INSTANCE(INSTANCE)\
  (((INSTANCE) == ATIM)    || \
   ((INSTANCE) == GTIM)    || \
   ((INSTANCE) == BTIM))

#define IS_TIM_CC1_INSTANCE(INSTANCE)\
  (((INSTANCE) == ATIM)    || \
   ((INSTANCE) == GTIM))

#define IS_TIM_CC2_INSTANCE(INSTANCE)\
  (((INSTANCE) == ATIM)    || \
   ((INSTANCE) == GTIM))

#define IS_TIM_CC3_INSTANCE(INSTANCE)\
  (((INSTANCE) == ATIM)    || \
   ((INSTANCE) == GTIM))

#define IS_TIM_CC4_INSTANCE(INSTANCE)\
  (((INSTANCE) == ATIM)    || \
   ((INSTANCE) == GTIM))

#define IS_TIM_CLOCKSOURCE_ETRMODE1_INSTANCE(INSTANCE)\
  (((INSTANCE) == ATIM)    || \
   ((INSTANCE) == GTIM))

#define IS_TIM_CLOCKSOURCE_ETRMODE2_INSTANCE(INSTANCE)\
  (((INSTANCE) == ATIM)    || \
   ((INSTANCE) == GTIM))

#define IS_TIM_CLOCKSOURCE_TIX_INSTANCE(INSTANCE)\
  (((INSTANCE) == ATIM)    || \
   ((INSTANCE) == GTIM))

#define IS_TIM_CLOCKSOURCE_ITRX_INSTANCE(INSTANCE)\
  (((INSTANCE) == ATIM)    || \
   ((INSTANCE) == GTIM))

#define IS_TIM_OCXREF_CLEAR_INSTANCE(INSTANCE)\
  (((INSTANCE) == ATIM)    || \
   ((INSTANCE) == GTIM))

#define IS_TIM_ENCODER_INTERFACE_INSTANCE(INSTANCE)\
  (((INSTANCE) == ATIM)    || \
   ((INSTANCE) == GTIM))

#define IS_TIM_XOR_INSTANCE(INSTANCE)\
  (((INSTANCE) == ATIM)    || \
   ((INSTANCE) == GTIM))

#define IS_TIM_MASTER_INSTANCE(INSTANCE)\
  (((INSTANCE) == ATIM)    || \
   ((INSTANCE) == GTIM))

#define IS_TIM_SLAVE_INSTANCE(INSTANCE)\
  (((INSTANCE) == ATIM)    || \
   ((INSTANCE) == GTIM))

#define IS_TIM_BREAK_INSTANCE(INSTANCE)\
  (((INSTANCE) == ATIM))

#define IS_TIM_CCX_INSTANCE(INSTANCE, CHANNEL) \
   ((((INSTANCE) == ATIM) &&                   \
     (((CHANNEL) == TIM_CHANNEL_1) ||          \
      ((CHANNEL) == TIM_CHANNEL_2) ||          \
      ((CHANNEL) == TIM_CHANNEL_3) ||          \
      ((CHANNEL) == TIM_CHANNEL_4)))           \
    ||                                         \
    (((INSTANCE) == GTIM) &&                   \
     (((CHANNEL) == TIM_CHANNEL_1) ||          \
      ((CHANNEL) == TIM_CHANNEL_2) ||          \
      ((CHANNEL) == TIM_CHANNEL_3) ||          \
      ((CHANNEL) == TIM_CHANNEL_4))))

#define IS_TIM_CCXN_INSTANCE(INSTANCE, CHANNEL) \
   ((((INSTANCE) == ATIM) &&                   \
     (((CHANNEL) == TIM_CHANNEL_1) ||          \
      ((CHANNEL) == TIM_CHANNEL_2) ||          \
      ((CHANNEL) == TIM_CHANNEL_3))))

#define IS_TIM_COUNTER_MODE_SELECT_INSTANCE(INSTANCE)\
  (((INSTANCE) == ATIM)    || \
   ((INSTANCE) == GTIM))

#define IS_TIM_REPETITION_COUNTER_INSTANCE(INSTANCE)\
  (((INSTANCE) == ATIM))

#define IS_TIM_CLOCK_DIVISION_INSTANCE(INSTANCE)\
  (((INSTANCE) == ATIM)    || \
   ((INSTANCE) == GTIM)    || \
   ((INSTANCE) == BTIM))

#define IS_TIM_COMMUTATION_EVENT_INSTANCE(INSTANCE)\
  (((INSTANCE) == ATIM)    || \
   ((INSTANCE) == GTIM))

#define IS_TIM_ETR_INSTANCE(INSTANCE)\
  (((INSTANCE) == ATIM)    || \
   ((INSTANCE) == GTIM))

#define IS_TIM_HALL_SENSOR_INTERFACE_INSTANCE(INSTANCE)\
  (((INSTANCE) == ATIM)    || \
   ((INSTANCE) == GTIM))

/****************************** END TIM Instances *****************************/

/******************** UART Instances : Asynchronous mode **********************/
#define IS_UART_INSTANCE(INSTANCE) (((INSTANCE) == UART0) || \
                                    ((INSTANCE) == UART1) || \
                                    ((INSTANCE) == UART2) || \
                                    ((INSTANCE) == UART3) || \
                                    ((INSTANCE) == UART4) || \
                                    ((INSTANCE) == UART5) || \
                                    ((INSTANCE) == UART6) || \
                                    ((INSTANCE) == UART7) || \
                                    ((INSTANCE) == UART8) || \
                                    ((INSTANCE) == UART9))
/**
  * @}
  */

#ifdef __cplusplus
}
#endif /* __cplusplus */
  
#endif /* __LS2K0300_H */
