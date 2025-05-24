#include "DC_Arm_Control.h"


Motor_Struct Slave0_Arm = {0, 0, 0, 0, {0, 0, 0, 0, 0, 0, 0, 0}, &hfdcan1, Slave0_Arm_ID};
Motor_Struct Slave1_Arm = {0, 0, 0, 0, {0, 0, 0, 0, 0, 0, 0, 0}, &hfdcan1, Slave1_Arm_ID};
Motor_Struct Slave2_Arm = {0, 0, 0, 0, {0, 0, 0, 0, 0, 0, 0, 0}, &hfdcan1, Slave2_Arm_ID};
Motor_Struct Slave0_End = {0, 0, 0, 0, {0, 0, 0, 0, 0, 0, 0, 0}, &hfdcan2, Slave0_End_ID};
Motor_Struct Slave1_End = {0, 0, 0, 0, {0, 0, 0, 0, 0, 0, 0, 0}, &hfdcan2, Slave1_End_ID};
Motor_Struct Slave2_End = {0, 0, 0, 0, {0, 0, 0, 0, 0, 0, 0, 0}, &hfdcan2, Slave2_End_ID};

void Main_Control_Init(void)
{
    HAL_TIM_Base_Start_IT(&htim1);

    FDCAN_IntFilterAndStart(&hfdcan1);
    FDCAN_IntFilterAndStart(&hfdcan2);
}

void DC_Arm_Comm_AngleSet(Motor_Struct *motor)
{
	uint8_t txdata[4];

	txdata[0] = *(uint8_t *) &(motor->Theta_ref);
	txdata[1] = *(uint8_t *)(&(motor->Theta_ref) + 1);
	txdata[2] = *(uint8_t *)(&(motor->Theta_ref) + 2);
	txdata[3] = *(uint8_t *)(&(motor->Theta_ref) + 3);

	FDCAN_SendMessageWithBaudSwitch(motor->hfdcan, txdata, FDCAN_DLC_BYTES_5, motor->Device_ID | White_Mark | 0x01);
}

void Main_Control_Loop(void)
{
    Slave2_Arm.Theta_ref = -PI/2;
    DC_Arm_Comm_AngleSet(&Slave2_Arm);
}
