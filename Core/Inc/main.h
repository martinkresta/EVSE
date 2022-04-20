/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32l4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

extern ADC_HandleTypeDef hadc1;
extern DMA_HandleTypeDef hdma_adc1;

extern CAN_HandleTypeDef hcan1;

extern TIM_HandleTypeDef htim1;
extern IWDG_HandleTypeDef hiwdg;

extern RTC_HandleTypeDef hrtc;

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

void HAL_TIM_MspPostInit(TIM_HandleTypeDef *htim);

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define BTN_ENTER_Pin GPIO_PIN_13
#define BTN_ENTER_GPIO_Port GPIOC
#define BTN_UP_Pin GPIO_PIN_14
#define BTN_UP_GPIO_Port GPIOC
#define BTN_DOWN_Pin GPIO_PIN_15
#define BTN_DOWN_GPIO_Port GPIOC
#define D0_Pin GPIO_PIN_0
#define D0_GPIO_Port GPIOA
#define D1_Pin GPIO_PIN_1
#define D1_GPIO_Port GPIOA
#define D2_Pin GPIO_PIN_2
#define D2_GPIO_Port GPIOA
#define D3_Pin GPIO_PIN_3
#define D3_GPIO_Port GPIOA
#define D4_Pin GPIO_PIN_4
#define D4_GPIO_Port GPIOA
#define D5_Pin GPIO_PIN_5
#define D5_GPIO_Port GPIOA
#define D6_Pin GPIO_PIN_6
#define D6_GPIO_Port GPIOA
#define D7_Pin GPIO_PIN_7
#define D7_GPIO_Port GPIOA
#define PILOT_ADC_IN_Pin GPIO_PIN_0
#define PILOT_ADC_IN_GPIO_Port GPIOB
#define R_W_Pin GPIO_PIN_1
#define R_W_GPIO_Port GPIOB
#define E_Pin GPIO_PIN_2
#define E_GPIO_Port GPIOB
#define LED_Life_Pin GPIO_PIN_12
#define LED_Life_GPIO_Port GPIOB
#define LED_Error_Pin GPIO_PIN_13
#define LED_Error_GPIO_Port GPIOB
#define RS_Pin GPIO_PIN_14
#define RS_GPIO_Port GPIOB
#define LED_Status_Pin GPIO_PIN_15
#define LED_Status_GPIO_Port GPIOB
#define ELM1_Pin GPIO_PIN_8
#define ELM1_GPIO_Port GPIOA
#define ELM1_EXTI_IRQn EXTI9_5_IRQn
#define AC_RELAY_Pin GPIO_PIN_10
#define AC_RELAY_GPIO_Port GPIOA
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
