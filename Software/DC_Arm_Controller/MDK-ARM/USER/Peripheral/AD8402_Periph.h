#ifndef AD8402_PERIPH_H
#define AD8402_PERIPH_H

#ifdef __cplusplus
extern "C" {
#endif 
	
#include "main.h"
#include "spi.h"
#include "cmsis_os.h"

#define AD8402_TYPE AD8402ARZ10 // 10k
#define AD8402ARZ1   1
#define AD8402ARZ8 8
#define AD8402ARZ10 10
#define AD8402ARZ50 50
#define AD8402ARZ100 100

#define AD8402_RESET_PORT GPIOB
#define AD8402_RESET_PIN  GPIO_PIN_5

#define AD8402_CS_PORT    GPIOB
#define AD8402_CS_PIN     GPIO_PIN_4

#define SPI_MOSI_PORT    GPIOA
#define SPI_MOSI_PIN     GPIO_PIN_7
//#define SPI_MOSI_LOW     (SPI_MOSI_PORT->BSRR = (uint32_t)SPI_MOSI_PIN << 16U)
//#define SPI_MOSI_HIGH    (SPI_MOSI_PORT->BSRR|=SPI_MOSI_PIN)

#define SPI_SCK_PORT    GPIOA
#define SPI_SCK_PIN     GPIO_PIN_5
//#define SPI_SCK_LOW     (SPI_SCK_PORT->BSRR = (uint32_t)SPI_SCK_PIN << 16U)
//#define SPI_SCK_HIGH    (SPI_SCK_PORT->BSRR|=SPI_SCK_PIN)

#define SPI_MOSI_LOW     HAL_GPIO_WritePin(SPI_MOSI_PORT,SPI_MOSI_PIN,GPIO_PIN_RESET)
#define SPI_MOSI_HIGH    HAL_GPIO_WritePin(SPI_MOSI_PORT,SPI_MOSI_PIN,GPIO_PIN_SET)

#define SPI_SCK_LOW      HAL_GPIO_WritePin(SPI_SCK_PORT,SPI_SCK_PIN,GPIO_PIN_RESET)
#define SPI_SCK_HIGH     HAL_GPIO_WritePin(SPI_SCK_PORT,SPI_SCK_PIN,GPIO_PIN_SET)

typedef enum{
	AW = 0,
	BW = 1
}AD8402_Pin_Link_Type;

extern uint16_t AD8402_Periph_DATA[2];

extern float  AD8402_Periph_Ohm[2];

void AD8402_SetValue(AD8402_Pin_Link_Type link_type, float* ohm);
uint8_t AD8402_DecoderValue(float ohm);
void AD8402_RESET(void);

#ifdef __cplusplus
}
#endif 

#endif

