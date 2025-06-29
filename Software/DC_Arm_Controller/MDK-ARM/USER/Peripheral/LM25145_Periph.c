#include "LM25145_Periph.h"

float DCDC_Voltage[2] = {23.5f, 23.0f}; // 23.5V, 12.0V

void DCDC_SetVoltage(float* value)
{
	if(AD8402_Pin_Link_Type == AW)
	{
		// Set AD8402 Pin A and W
		AD8402_Periph_Ohm[0] = AD8402_TYPE - Resistor_Count(value[0]);
		AD8402_Periph_Ohm[1] = AD8402_TYPE - Resistor_Count(value[1]);
	}
	else if(AD8402_Pin_Link_Type == BW)
	{
		// Set AD8402 Pin B and W
		AD8402_Periph_Ohm[0] = Resistor_Count(value[0]);
		AD8402_Periph_Ohm[1] = Resistor_Count(value[1]);
	}
	AD8402_SetValue(AD8402_Periph_Ohm);
}

float Resistor_Count(float exp_val)
{
	if(exp_val < MINIMUM_VOLTAGE) exp_val = MINIMUM_VOLTAGE;
  	float AD8402_Value = 0;
  	AD8402_Value = (FB_VOLTAGE * (RES_DOWN + RES_UP) - exp_val * RES_DOWN) / (exp_val - FB_VOLTAGE) ;
  	return AD8402_Value;
}
