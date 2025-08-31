#include "AD8402_Periph.h"

uint16_t AD8402_Periph_DATA[2] = {0, 0};
float  AD8402_Periph_Ohm[2];


void AD8402_SetValue(AD8402_Pin_Link_Type link_type, float* ohm) 
{	
	uint8_t value[2];	
	if(link_type == BW)					// Set AD8402 Pin B and W
	{
		value[0] = AD8402_DecoderValue(ohm[0]);
		value[1] = AD8402_DecoderValue(ohm[1]);
	}
	else if(link_type == AW)		// Set AD8402 Pin A and W
	{
		value[0] = 255 - AD8402_DecoderValue(ohm[0]);
		value[1] = 255 - AD8402_DecoderValue(ohm[1]);
	}

	AD8402_Periph_DATA[0] = 0x00;
	AD8402_Periph_DATA[1] = 0x00 << 8 | value[0];
	
	HAL_GPIO_WritePin(AD8402_CS_PORT, AD8402_CS_PIN, GPIO_PIN_RESET);
	HAL_SPI_Transmit(&hspi1, (uint8_t *)AD8402_Periph_DATA, 2, 100);
	HAL_GPIO_WritePin(AD8402_CS_PORT, AD8402_CS_PIN, GPIO_PIN_SET);
	
	AD8402_Periph_DATA[0] = 0x00;
	AD8402_Periph_DATA[1] = 0x01 << 8 | value[1];
	
	HAL_GPIO_WritePin(AD8402_CS_PORT, AD8402_CS_PIN, GPIO_PIN_RESET);
	HAL_SPI_Transmit(&hspi1, (uint8_t *)AD8402_Periph_DATA, 2, 100);
	HAL_GPIO_WritePin(AD8402_CS_PORT, AD8402_CS_PIN, GPIO_PIN_SET);
}// Hint: This function sets the AD8402 resistance values in ohms between Pin "B" and "W".

uint8_t AD8402_DecoderValue(float ohm) 
{	
	uint32_t value;
	value = (uint32_t) (ohm * 255.0f / (float)AD8402_TYPE);
	if(value >= 255) value = 255;
	return (uint8_t)value;
}

void AD8402_RESET(void) 
{
	HAL_GPIO_WritePin(AD8402_RESET_PORT , AD8402_RESET_PIN , GPIO_PIN_RESET);
	osDelay(1);
	HAL_GPIO_WritePin(AD8402_RESET_PORT , AD8402_RESET_PIN , GPIO_PIN_SET) ;
	osDelay(1);
}
