#ifndef __LM25145_PERIPH_H
#define __LM25145_PERIPH_H

#ifdef __cplusplus
extern "C" {
#endif 
	
#include "main.h"
#include "AD8402_Periph.h"

#define RES_UP    56 // 56K
#define RES_DOWN   0 // none resistor
#define FB_VOLTAGE 0.8f // LM25145 Feedback Voltage = 0.8V

#define AD8402_Pin_Link_Type AW
#define AW  0 // AD8402 Pin A and W
#define BW  1 // AD8402 Pin B and W

#define MINIMUM_VOLTAGE ((RES_UP/(AD8402_TYPE + RES_DOWN) + 1) * FB_VOLTAGE) // 0.8V * 56/(56+0) = 0.8V

extern float DCDC_Voltage[2]; // 23.5V, 12.0V

void DCDC_SetVoltage(float* value);
float Resistor_Count(float exp_val);

#ifdef __cplusplus
}
#endif 

#endif
