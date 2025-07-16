#include "WS2812_Periph.h"

uint16_t pwm_buffer[BIT_COUNT] = {0};

void rgb_to_pwm(uint8_t r, uint8_t g, uint8_t b, uint16_t *buffer, int start_index);

void Task_RGB(void)
{
//		HAL_TIM_Base_Start(&WS2812_TIM);
    HAL_TIM_PWM_Start_DMA(&WS2812_TIM, WS2812_TIM_CHANNEL, (uint32_t *)pwm_buffer, sizeof(pwm_buffer)/sizeof(uint16_t));

    while (1)
    {
        for (int i = 0; i < LED_COUNT; i++) {
        uint8_t r = 0;
        uint8_t g = 0;
        uint8_t b = 60;
        rgb_to_pwm(r, g, b, pwm_buffer, (LED_RST_NUM + i) * 24);
				}

    HAL_TIM_PWM_Stop_DMA(&WS2812_TIM, WS2812_TIM_CHANNEL);

    HAL_TIM_PWM_Start_DMA(&WS2812_TIM, WS2812_TIM_CHANNEL, (uint32_t *)pwm_buffer, sizeof(pwm_buffer)/sizeof(uint16_t));

    osDelay(1000);  // ÑÓÊ±1Ãë
    }
}


// Change RGB data to PWM data
void rgb_to_pwm(uint8_t r, uint8_t g, uint8_t b, uint16_t *buffer, int start_index)
{
    // WS2812's data order GRB
		for (uint8_t i = 0;i < 8;i++)
		{
			buffer[start_index + i]      = (g << i) & (0x80)?PWM_HIGH:PWM_LOW;
			buffer[start_index + i + 8]  = (r << i) & (0x80)?PWM_HIGH:PWM_LOW;
			buffer[start_index + i + 16] = (b << i) & (0x80)?PWM_HIGH:PWM_LOW;
		}
}

void ws2823_reset(void)
{
	
}

