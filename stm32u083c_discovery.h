/**
  ******************************************************************************
  * @file    stm32u083c_discovery.h
  * @author  MCD Application Team
  * @brief   This file contains definitions for stm32u083c_discovery.c:
  *          LEDs
  *          USER push-button
  *          COM port
  *          Joystick
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef STM32U083C_DK_H
#define STM32U083C_DK_H

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/**
  * @brief  Define for STM32U083C_DISCOVERY board
  */
#if !defined (USE_STM32U083C_DISCO_REVC) && !defined (USE_STM32U083C_DISCO_REVB) && !defined (USE_STM32U083C_DISCO_REVA)
#define USE_STM32U083C_DISCO_REVC
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32u083c_discovery_conf.h"
#include "stm32u083c_discovery_errno.h"

#if (USE_BSP_COM_FEATURE > 0)
#if (USE_COM_LOG > 0)
#ifndef __GNUC__
#include "stdio.h"
#endif /* __GNUC__ */
#endif /* USE_COM_LOG */
#endif /* USE_BSP_COM_FEATURE */

/** @addtogroup BSP
  * @{
  */

/** @addtogroup STM32U083C_DK
  * @{
  */

/** @addtogroup STM32U083C_DK_LOW_LEVEL
  * @{
  */

/** @defgroup STM32U083C_DK_LOW_LEVEL_Exported_Types LOW LEVEL Exported Types
  * @{
  */
/**
  * @brief LED Types Definition
  */
typedef enum
{
  LED3 = 0U,
  LED_GREEN  = LED3,
  LD3  = LED3,
  LED4 = 1U,
  LED_BLUE   = LED4,
  LD4   = LED4,
  LED5 = 2U,
  LED_RED    = LED5,
  LD5   = LED5,
  LEDn
} Led_TypeDef;

/**
  * @brief BUTTON Types Definition
  */
typedef enum
{
  BUTTON_USER = 0U,
  BUTTONn
} Button_TypeDef;

typedef enum
{
  BUTTON_MODE_GPIO = 0U,
  BUTTON_MODE_EXTI = 1U
} ButtonMode_TypeDef;

/**
  * @brief JOYSTICK Types Definition
  */
#if (USE_BSP_JOY_FEATURE > 0)
typedef enum
{
  JOY_MODE_GPIO = 0U,
  JOY_MODE_EXTI = 1U
} JOYMode_TypeDef;

typedef enum
{
  JOY1 = 0U,
  JOYn
} JOY_TypeDef;

typedef enum
{
  JOY_NONE  = 0x00U,
  JOY_SEL   = 0x01U,
  JOY_DOWN  = 0x02U,
  JOY_LEFT  = 0x04U,
  JOY_RIGHT = 0x08U,
  JOY_UP    = 0x10U,
  JOY_ALL   = 0x1FU
} JOYPin_TypeDef;
#endif /* USE_BSP_JOY_FEATURE */

#if (USE_HAL_ADC_REGISTER_CALLBACKS == 1)
typedef struct
{
  void (* pMspInitCb)(ADC_HandleTypeDef *);
  void (* pMspDeInitCb)(ADC_HandleTypeDef *);
} BSP_JOY_Cb_t;
#endif /* (USE_HAL_ADC_REGISTER_CALLBACKS == 1) */

/**
  * @brief COM Types Definition
  */
#if (USE_BSP_COM_FEATURE > 0)
typedef enum
{
  COM1 = 0U,
  COMn
} COM_TypeDef;

typedef enum
{
  COM_STOPBITS_1     =   UART_STOPBITS_1,
} COM_StopBitsTypeDef;

typedef enum
{
  COM_PARITY_NONE     =  UART_PARITY_NONE,
  COM_PARITY_EVEN     =  UART_PARITY_EVEN,
  COM_PARITY_ODD      =  UART_PARITY_ODD,
} COM_ParityTypeDef;

typedef enum
{
  COM_HWCONTROL_NONE    =  UART_HWCONTROL_NONE,
  COM_HWCONTROL_RTS     =  UART_HWCONTROL_RTS,
  COM_HWCONTROL_CTS     =  UART_HWCONTROL_CTS,
  COM_HWCONTROL_RTS_CTS =  UART_HWCONTROL_RTS_CTS,
} COM_HwFlowCtlTypeDef;

typedef enum
{
  COM_WORDLENGTH_7B = UART_WORDLENGTH_7B,
  COM_WORDLENGTH_8B = UART_WORDLENGTH_8B,
  COM_WORDLENGTH_9B = UART_WORDLENGTH_9B,
} COM_WordLengthTypeDef;

typedef struct
{
  uint32_t              BaudRate;
  COM_WordLengthTypeDef WordLength;
  COM_StopBitsTypeDef   StopBits;
  COM_ParityTypeDef     Parity;
  COM_HwFlowCtlTypeDef  HwFlowCtl;
} COM_InitTypeDef;

#define MX_UART_InitTypeDef COM_InitTypeDef

#endif /* (USE_BSP_COM_FEATURE > 0) */
#if (USE_HAL_UART_REGISTER_CALLBACKS == 1)
typedef struct
{
  void (* pMspInitCb)(UART_HandleTypeDef *);
  void (* pMspDeInitCb)(UART_HandleTypeDef *);
} BSP_COM_Cb_t;
#endif /* (USE_HAL_UART_REGISTER_CALLBACKS == 1) */

/**
  * @}
  */

/** @defgroup STM32U083C_DK_LOW_LEVEL_Exported_Constants LOW LEVEL Exported Constants
  * @{
  */
/**
  * @brief  Define for STM32U083C_DK board
  */
#if !defined (USE_STM32U083C_DK)
#define USE_STM32U083C_DK
#endif /* USE_STM32U083C_DK */

/**
  * @brief STM32U083C_DK BSP Driver version number V1.0.0
   */
#define STM32U083C_DK_BSP_VERSION_MAIN   (0x01) /*!< [31:24] main version */
#define STM32U083C_DK_BSP_VERSION_SUB1   (0x00) /*!< [23:16] sub1 version */
#define STM32U083C_DK_BSP_VERSION_SUB2   (0x00) /*!< [15:8]  sub2 version */
#define STM32U083C_DK_BSP_VERSION_RC     (0x00) /*!< [7:0]  release candidate */
#define STM32U083C_DK_BSP_VERSION        ((STM32U083C_DK_BSP_VERSION_MAIN << 24)\
                                          |(STM32U083C_DK_BSP_VERSION_SUB1 << 16)\
                                          |(STM32U083C_DK_BSP_VERSION_SUB2 << 8 )\
                                          |(STM32U083C_DK_BSP_VERSION_RC))

#define STM32U083C_DK_BSP_BOARD_NAME  "STM32U083C-DK";
#define STM32U083C_DK_BSP_BOARD_ID    "MB1933C";

/** @defgroup STM32U083C_DK_LOW_LEVEL_LED LOW LEVEL LED
  * @{
  */
#define LED3_PIN                          GPIO_PIN_13
#define LED3_GPIO_PORT                    GPIOC
#define LED3_GPIO_CLK_ENABLE()            __HAL_RCC_GPIOC_CLK_ENABLE()
#define LED3_GPIO_CLK_DISABLE()           __HAL_RCC_GPIOC_CLK_DISABLE()

#define LED4_PIN                          GPIO_PIN_5
#define LED4_GPIO_PORT                    GPIOA
#define LED4_GPIO_CLK_ENABLE()            __HAL_RCC_GPIOA_CLK_ENABLE()
#define LED4_GPIO_CLK_DISABLE()           __HAL_RCC_GPIOA_CLK_DISABLE()

#define LED5_PIN                          GPIO_PIN_2
#define LED5_GPIO_PORT                    GPIOB
#define LED5_GPIO_CLK_ENABLE()            __HAL_RCC_GPIOB_CLK_ENABLE()
#define LED5_GPIO_CLK_DISABLE()           __HAL_RCC_GPIOB_CLK_DISABLE()
/**
  * @}
  */

/** @defgroup STM32U083C_DK_LOW_LEVEL_BUTTON LOW LEVEL BUTTON
  * @{
  */
/* Button state */
#define BUTTON_RELEASED                    0U
#define BUTTON_PRESSED                     1U

/**
  * @brief User push-button
  */
#define BUTTON_USER_PIN                       GPIO_PIN_2
#define BUTTON_USER_GPIO_PORT                 GPIOC
#define BUTTON_USER_GPIO_CLK_ENABLE()         __HAL_RCC_GPIOC_CLK_ENABLE()
#define BUTTON_USER_GPIO_CLK_DISABLE()        __HAL_RCC_GPIOC_CLK_DISABLE()
#define BUTTON_USER_EXTI_IRQn                 EXTI2_3_IRQn
#define BUTTON_USER_EXTI_LINE                 EXTI_LINE_2
/**
  * @}
  */

/** @defgroup STM32U083C_DK_LOW_LEVEL_JOYSTICK LOW LEVEL JOYSTICK
  * @{
  */
#define JOY_KEY_NUMBER                     5U

#define JOY1_SEL_PIN                       GPIO_PIN_2
#define JOY1_SEL_GPIO_PORT                 GPIOC
#define JOY1_SEL_GPIO_CLK_ENABLE()         __HAL_RCC_GPIOC_CLK_ENABLE()
#define JOY1_SEL_GPIO_CLK_DISABLE()        __HAL_RCC_GPIOC_CLK_DISABLE()
#define JOY1_SEL_EXTI_IRQn                 EXTI2_3_IRQn
#define JOY1_SEL_EXTI_LINE                 GPIO_PIN_2

#define JOY1_DOWN_PIN                      GPIO_PIN_2
#define JOY1_DOWN_GPIO_PORT                GPIOC
#define JOY1_DOWN_GPIO_CLK_ENABLE()        __HAL_RCC_GPIOC_CLK_ENABLE()
#define JOY1_DOWN_GPIO_CLK_DISABLE()       __HAL_RCC_GPIOC_CLK_DISABLE()
#define JOY1_DOWN_EXTI_IRQn                EXTI2_3_IRQn
#define JOY1_DOWN_EXTI_LINE                GPIO_PIN_2

#define JOY1_LEFT_PIN                      GPIO_PIN_2
#define JOY1_LEFT_GPIO_PORT                GPIOC
#define JOY1_LEFT_GPIO_CLK_ENABLE()        __HAL_RCC_GPIOC_CLK_ENABLE()
#define JOY1_LEFT_GPIO_CLK_DISABLE()       __HAL_RCC_GPIOC_CLK_DISABLE()
#define JOY1_LEFT_EXTI_IRQn                EXTI2_3_IRQn
#define JOY1_LEFT_EXTI_LINE                GPIO_PIN_2

#define JOY1_RIGHT_PIN                     GPIO_PIN_2
#define JOY1_RIGHT_GPIO_PORT               GPIOC
#define JOY1_RIGHT_GPIO_CLK_ENABLE()       __HAL_RCC_GPIOC_CLK_ENABLE()
#define JOY1_RIGHT_GPIO_CLK_DISABLE()      __HAL_RCC_GPIOC_CLK_DISABLE()
#define JOY1_RIGHT_EXTI_IRQn               EXTI2_3_IRQn
#define JOY1_RIGHT_EXTI_LINE               GPIO_PIN_2

#define JOY1_UP_PIN                        GPIO_PIN_2
#define JOY1_UP_GPIO_PORT                  GPIOC
#define JOY1_UP_GPIO_CLK_ENABLE()          __HAL_RCC_GPIOC_CLK_ENABLE()
#define JOY1_UP_GPIO_CLK_DISABLE()         __HAL_RCC_GPIOC_CLK_DISABLE()
#define JOY1_UP_EXTI_IRQn                  EXTI2_3_IRQn
#define JOY1_UP_EXTI_LINE                  GPIO_PIN_2

/**
  * @brief Definition for Joystick, connected to ADC1
  */
#define JOY1_ADC                        ADC1
#define JOY1_CLK_ENABLE()               __HAL_RCC_ADC_CLK_ENABLE()
#define JOY1_CLK_DISABLE()              __HAL_RCC_ADC_CLK_DISABLE()
#define JOY1_CHANNEL_GPIO_CLK_ENABLE()  __HAL_RCC_GPIOC_CLK_ENABLE()
#define JOY1_FORCE_RESET()              __HAL_RCC_ADC_FORCE_RESET()
#define JOY1_RELEASE_RESET()            __HAL_RCC_ADC_RELEASE_RESET()

/* Definition for ADCx Channel Pin */
#define JOY1_CHANNEL_GPIO_PIN           GPIO_PIN_2
#define JOY1_CHANNEL_GPIO_PORT          GPIOC

/* Definition for ADCx's Channel */
#define JOY1_ADC_CHANNEL                ADC_CHANNEL_2
#define JOY1_SAMPLING_TIME              ADC_SAMPLINGTIME_COMMON_1
#define JOY1_PRESCALER                  ADC_CLOCK_SYNC_PCLK_DIV4
#define JOY_ADC_POLL_TIMEOUT            10U
/**
  * @}
  */

/** @defgroup STM32U083C_DK_LOW_LEVEL_COM LOW LEVEL COM
  * @{
  */
#ifndef USE_BSP_COM_FEATURE
#define USE_BSP_COM_FEATURE    0U
#endif /* USE_BSP_COM_FEATURE */
#if (USE_BSP_COM_FEATURE > 0)
/**
  * @brief Definition for COM port1, connected to USART2 (ST-Link USB Virtual Com Port)
  */
#define COM1_UART                     USART2
#define COM1_CLK_ENABLE()             __HAL_RCC_USART2_CLK_ENABLE()
#define COM1_CLK_DISABLE()            __HAL_RCC_USART2_CLK_DISABLE()

#define COM1_TX_PIN                   GPIO_PIN_2
#define COM1_TX_GPIO_PORT             GPIOA
#define COM1_TX_GPIO_CLK_ENABLE()     __HAL_RCC_GPIOA_CLK_ENABLE()
#define COM1_TX_GPIO_CLK_DISABLE()    __HAL_RCC_GPIOA_CLK_DISABLE()
#define COM1_TX_AF                    GPIO_AF7_USART2

#define COM1_RX_PIN                   GPIO_PIN_3
#define COM1_RX_GPIO_PORT             GPIOA
#define COM1_RX_GPIO_CLK_ENABLE()     __HAL_RCC_GPIOA_CLK_ENABLE()
#define COM1_RX_GPIO_CLK_DISABLE()    __HAL_RCC_GPIOA_CLK_DISABLE()
#define COM1_RX_AF                    GPIO_AF7_USART2

#define COM_POLL_TIMEOUT              1000U
#endif /* (USE_BSP_COM_FEATURE > 0) */
/**
  * @}
  */

/**
  * @}
  */

/** @addtogroup STM32U083C_DK_LOW_LEVEL_Exported_Variables
  * @{
  */
extern EXTI_HandleTypeDef hpb_exti[];
#if (USE_BSP_COM_FEATURE > 0)
extern UART_HandleTypeDef hcom_uart[];
extern USART_TypeDef *COM_UART[];
#endif /* USE_BSP_COM_FEATURE */
/**
  * @}
  */

/** @defgroup STM32U083C_DK_LOW_LEVEL_Exported_Functions
  * @{
  */
int32_t                  BSP_GetVersion(void);
const uint8_t           *BSP_GetBoardName(void);
const uint8_t           *BSP_GetBoardID(void);

int32_t                 BSP_LED_Init(Led_TypeDef Led);
int32_t                 BSP_LED_DeInit(Led_TypeDef Led);
int32_t                 BSP_LED_On(Led_TypeDef Led);
int32_t                 BSP_LED_Off(Led_TypeDef Led);
int32_t                 BSP_LED_Toggle(Led_TypeDef Led);
int32_t                 BSP_LED_GetState(Led_TypeDef Led);

int32_t                 BSP_PB_Init(Button_TypeDef Button, ButtonMode_TypeDef ButtonMode);
int32_t                 BSP_PB_DeInit(Button_TypeDef Button);
int32_t                 BSP_PB_GetState(Button_TypeDef Button);
void                    BSP_PB_Callback(Button_TypeDef Button);
void                    BSP_PB_IRQHandler(Button_TypeDef Button);

#if (USE_BSP_JOY_FEATURE > 0)
int32_t  BSP_JOY_Init(JOY_TypeDef JOY, JOYMode_TypeDef JoyMode,  JOYPin_TypeDef JoyPins);
int32_t  BSP_JOY_DeInit(JOY_TypeDef JOY,  JOYPin_TypeDef JoyPins);
int32_t  BSP_JOY_GetState(JOY_TypeDef JOY);
#endif /* USE_BSP_JOY_FEATURE */

#if (USE_BSP_COM_FEATURE > 0)
int32_t  BSP_COM_Init(COM_TypeDef COM, COM_InitTypeDef *COM_Init);
int32_t  BSP_COM_DeInit(COM_TypeDef COM);
#if (USE_COM_LOG > 0)
int32_t  BSP_COM_SelectLogPort(COM_TypeDef COM);
#endif /* USE_COM_LOG */

#if (USE_HAL_UART_REGISTER_CALLBACKS > 0)
int32_t BSP_COM_RegisterDefaultMspCallbacks(COM_TypeDef COM);
int32_t BSP_COM_RegisterMspCallbacks(COM_TypeDef COM, BSP_COM_Cb_t *Callback);
#endif /* USE_HAL_UART_REGISTER_CALLBACKS */
HAL_StatusTypeDef MX_USART2_Init(UART_HandleTypeDef *huart, MX_UART_InitTypeDef *COM_Init);
#endif /* USE_BSP_COM_FEATURE */

/* These __weak functions can be surcharged by application code for specific application needs */
void                    BSP_ErrorHandler(void);

#if defined(HAL_I2C_MODULE_ENABLED)
void I2C2_Init(void);
void I2C2_DeInit(void);
#endif /* HAL_I2C_MODULE_ENABLED */

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
#endif /* STM32U083C_DK_H */
