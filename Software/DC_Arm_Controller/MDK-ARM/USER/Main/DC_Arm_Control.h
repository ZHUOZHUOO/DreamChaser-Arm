#ifndef __DC_ARM_CONTROL_H
#define __DC_ARM_CONTROL_H

#include "stm32g4xx.h"
#include "util_fdcan.h"
#include "configure.h"
#include "arm_math.h"
#include "tim.h"
#include "DC_Arm_Comm.h"

typedef struct 
{
    uint8_t SAFETY_STATE;           //0:Safety expired  1:Normal
    uint8_t OVER_VOLTAGE_STATE;     //0:OverVoltage     1:Normal
    uint8_t UNDER_VOLTAGE_STATE;    //0:UnderVoltage    1:Normal
    uint8_t OVER_CURRENT_STATE;     //0:OverCurrent     1:Normal
    uint8_t OVER_SPEED_STATE;       //0:OverSpeed       1:Normal
    uint8_t OVER_TEMPERATURE_STATE; //0:OverTemperature 1:Normal
    uint8_t OVER_LOAD_STATE;        //0:OverLoad        1:Normal
    uint8_t DRV8323_ERROR_STATE;    //0:DRV8323 Error   1:Normal
}Motor_Error_Status;

typedef struct
{
    float Theta_ref;
    float Theta_fed;
    float Speed_ref;
    float Speed_fed;
    Motor_Error_Status Error_Status;
    FDCAN_HandleTypeDef *hfdcan;
    uint32_t Device_ID;
}Motor_Struct;


extern Motor_Struct Slave0_Arm;
extern Motor_Struct Slave1_Arm;
extern Motor_Struct Slave2_Arm;
extern Motor_Struct Slave0_End;
extern Motor_Struct Slave1_End;
extern Motor_Struct Slave2_End;

void Main_Control_Init(void);
void Main_Control_Loop(void);
void DC_Arm_Comm_AngleSet(Motor_Struct *motor);

#endif /* __DC_ARM_CONTROL_H */
