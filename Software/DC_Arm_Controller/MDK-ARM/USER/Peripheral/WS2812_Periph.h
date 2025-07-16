#ifndef __WS2812_PERIPH_H
#define __WS2812_PERIPH_H

#ifdef __cplusplus
extern "C" {
#endif 

#include "main.h"
#include "tim.h"
#include "cmsis_os.h"
#include "gpio.h"

#define WS2812_TIM  htim2
#define WS2812_TIM_CHANNEL  TIM_CHANNEL_4

#define LED_COUNT 10  // number of WS2812
#define LED_RST_NUM 12
#define BIT_COUNT ((LED_RST_NUM + LED_COUNT) * 24)  // 24bits per WS2812

#define PWM_LOW 70  // Duty Cycle of logic ¡°0¡±
#define PWM_HIGH 140 // Duty Cycle of logic ¡°1¡±

void WS2812_TIM_Init(void);

#ifdef __cplusplus
}
#endif 

#endif
