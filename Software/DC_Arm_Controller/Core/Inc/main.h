/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
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
#include "stm32g4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define SWITCH1_Pin GPIO_PIN_13
#define SWITCH1_GPIO_Port GPIOC
#define SWITCH2_Pin GPIO_PIN_14
#define SWITCH2_GPIO_Port GPIOC
#define ADC1_VCC_Pin GPIO_PIN_0
#define ADC1_VCC_GPIO_Port GPIOA
#define ADC1_CH1_Pin GPIO_PIN_1
#define ADC1_CH1_GPIO_Port GPIOA
#define ADC1_CH2_Pin GPIO_PIN_2
#define ADC1_CH2_GPIO_Port GPIOA
#define SWITCH3_Pin GPIO_PIN_3
#define SWITCH3_GPIO_Port GPIOA
#define SWITCH4_Pin GPIO_PIN_4
#define SWITCH4_GPIO_Port GPIOA
#define OLED_RESET_Pin GPIO_PIN_0
#define OLED_RESET_GPIO_Port GPIOB
#define OLED_DC_Pin GPIO_PIN_1
#define OLED_DC_GPIO_Port GPIOB
#define OLED_CS_Pin GPIO_PIN_2
#define OLED_CS_GPIO_Port GPIOB
#define AD8402_CS_Pin GPIO_PIN_4
#define AD8402_CS_GPIO_Port GPIOB
#define AD8402_RESET_Pin GPIO_PIN_5
#define AD8402_RESET_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
