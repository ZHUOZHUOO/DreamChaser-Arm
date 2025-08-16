#include "DC_Arm_Control.h"

volatile uint8_t switch_to_gpio_ready = 0;

Motor_Struct Slave0_Arm = {0, 0, 0, 0, 0, 0, {0, 0, 0, 0, 0, 0, 0}, &hfdcan1, Slave0_Arm_ID};
Motor_Struct Slave1_Arm = {0, 0, 0, 0, 0, 0, {0, 0, 0, 0, 0, 0, 0}, &hfdcan1, Slave1_Arm_ID};
Motor_Struct Slave2_Arm = {0, 0, 0, 0, 0, 0, {0, 0, 0, 0, 0, 0, 0}, &hfdcan1, Slave2_Arm_ID};
Motor_Struct Slave0_End = {0, 0, 0, 0, 0, 0, {0, 0, 0, 0, 0, 0, 0}, &hfdcan2, Slave0_End_ID};
Motor_Struct Slave1_End = {0, 0, 0, 0, 0, 0, {0, 0, 0, 0, 0, 0, 0}, &hfdcan2, Slave1_End_ID};
Motor_Struct Slave2_End = {0, 0, 0, 0, 0, 0, {0, 0, 0, 0, 0, 0, 0}, &hfdcan2, Slave2_End_ID};

void DC_Arm_Comm_AngleSet(Motor_Struct *motor);
void DC_Arm_Comm_CurrentSet(Motor_Struct *motor);

void Task_Main_Control(void)
{
	HAL_TIM_Base_Start_IT(&htim1);

    FDCAN_IntFilterAndStart(&hfdcan1);
    FDCAN_IntFilterAndStart(&hfdcan2);

	AD8402_RESET();
	DCDC_SetVoltage(DCDC_Voltage);
	
	while(1)
	{
		Slave2_Arm.Theta_ref = -PI/2;
    DC_Arm_Comm_AngleSet(&Slave2_Arm);
		osDelay(10);
	}
}

void DC_Arm_Comm_AngleSet(Motor_Struct *motor)
{
	uint8_t txdata[4];
	txdata[0] = *(uint8_t *) &(motor->Theta_ref);
	txdata[1] = *(uint8_t *)(&(motor->Theta_ref) + 1);
	txdata[2] = *(uint8_t *)(&(motor->Theta_ref) + 2);
	txdata[3] = *(uint8_t *)(&(motor->Theta_ref) + 3);

	uint32_t id_temp = motor->Device_ID | White_Mark | CMD_THETA_SET;
	FDCAN_SendMessageWithBaudSwitch(motor->hfdcan, txdata, FDCAN_DLC_BYTES_5, id_temp);
}

void DC_Arm_Comm_CurrentSet(Motor_Struct *motor)
{
	uint8_t txdata[4];
	txdata[0] = *(uint8_t *) &(motor->Current_ref);
	txdata[1] = *(uint8_t *)(&(motor->Current_ref) + 1);
	txdata[2] = *(uint8_t *)(&(motor->Current_ref) + 2);
	txdata[3] = *(uint8_t *)(&(motor->Current_ref) + 3);

	uint32_t id_temp = motor->Device_ID | White_Mark | CMD_CURRENT_SET;
	FDCAN_SendMessageWithBaudSwitch(motor->hfdcan, txdata, FDCAN_DLC_BYTES_5, id_temp);
}

void DC_Arm_Comm_IqPIDSet(Motor_Struct *motor, float id_ref, float iq_ref)
{
	uint8_t txdata[20];
	txdata[0] = *(uint8_t *) &(motor->Iq_PID.kp);
	txdata[1] = *(uint8_t *)(&(motor->Iq_PID.kp) + 1);
	txdata[2] = *(uint8_t *)(&(motor->Iq_PID.kp) + 2);
	txdata[3] = *(uint8_t *)(&(motor->Iq_PID.kp) + 3);
	txdata[4] = *(uint8_t *) &(motor->Iq_PID.ki);
	txdata[5] = *(uint8_t *)(&(motor->Iq_PID.ki) + 1);
	txdata[6] = *(uint8_t *)(&(motor->Iq_PID.ki) + 2);
	txdata[7] = *(uint8_t *)(&(motor->Iq_PID.ki) + 3);
	txdata[8] = *(uint8_t *) &(motor->Iq_PID.kd);
	txdata[9] = *(uint8_t *)(&(motor->Iq_PID.kd) + 1);
	txdata[10] = *(uint8_t *)(&(motor->Iq_PID.kd) + 2);
	txdata[11] = *(uint8_t *)(&(motor->Iq_PID.kd) + 3);
	txdata[12] = *(uint8_t *) &(motor->Iq_PID.sum_max);
	txdata[13] = *(uint8_t *)(&(motor->Iq_PID.sum_max) + 1);
	txdata[14] = *(uint8_t *)(&(motor->Iq_PID.sum_max) + 2);
	txdata[15] = *(uint8_t *)(&(motor->Iq_PID.sum_max) + 3);
	txdata[16] = *(uint8_t *) &(motor->Iq_PID.output_max);
	txdata[17] = *(uint8_t *)(&(motor->Iq_PID.output_max) + 1);
	txdata[18] = *(uint8_t *)(&(motor->Iq_PID.output_max) + 2);
	txdata[19] = *(uint8_t *)(&(motor->Iq_PID.output_max) + 3);

	uint32_t id_temp = motor->Device_ID | White_Mark | CMD_IQ_PID_SET;
	FDCAN_SendMessageWithBaudSwitch(motor->hfdcan, txdata, FDCAN_DLC_BYTES_20, id_temp);
}

void DC_Arm_Comm_IdPIDSet(Motor_Struct *motor, float id_ref)
{
	uint8_t txdata[20];
	txdata[0] = *(uint8_t *) &(motor->Id_PID.kp);
	txdata[1] = *(uint8_t *)(&(motor->Id_PID.kp) + 1);
	txdata[2] = *(uint8_t *)(&(motor->Id_PID.kp) + 2);
	txdata[3] = *(uint8_t *)(&(motor->Id_PID.kp) + 3);
	txdata[4] = *(uint8_t *) &(motor->Id_PID.ki);
	txdata[5] = *(uint8_t *)(&(motor->Id_PID.ki) + 1);
	txdata[6] = *(uint8_t *)(&(motor->Id_PID.ki) + 2);
	txdata[7] = *(uint8_t *)(&(motor->Id_PID.ki) + 3);
	txdata[8] = *(uint8_t *) &(motor->Id_PID.kd);
	txdata[9] = *(uint8_t *)(&(motor->Id_PID.kd) + 1);
	txdata[10] = *(uint8_t *)(&(motor->Id_PID.kd) + 2);
	txdata[11] = *(uint8_t *)(&(motor->Id_PID.kd) + 3);
	txdata[12] = *(uint8_t *) &(motor->Id_PID.sum_max);
	txdata[13] = *(uint8_t *)(&(motor->Id_PID.sum_max) + 1);
	txdata[14] = *(uint8_t *)(&(motor->Id_PID.sum_max) + 2);
	txdata[15] = *(uint8_t *)(&(motor->Id_PID.sum_max) + 3);
	txdata[16] = *(uint8_t *) &(motor->Id_PID.output_max);
	txdata[17] = *(uint8_t *)(&(motor->Id_PID.output_max) + 1);
	txdata[18] = *(uint8_t *)(&(motor->Id_PID.output_max) + 2);
	txdata[19] = *(uint8_t *)(&(motor->Id_PID.output_max) + 3);

	uint32_t id_temp = motor->Device_ID | White_Mark | CMD_ID_PID_SET;
	FDCAN_SendMessageWithBaudSwitch(motor->hfdcan, txdata, FDCAN_DLC_BYTES_20, id_temp);
}

void DC_Arm_Comm_PositionPIDSet(Motor_Struct *motor, float position_ref)
{
	uint8_t txdata[20];
	txdata[0] = *(uint8_t *) &(motor->Position_PID.kp);
	txdata[1] = *(uint8_t *)(&(motor->Position_PID.kp) + 1);
	txdata[2] = *(uint8_t *)(&(motor->Position_PID.kp) + 2);
	txdata[3] = *(uint8_t *)(&(motor->Position_PID.kp) + 3);
	txdata[4] = *(uint8_t *) &(motor->Position_PID.ki);
	txdata[5] = *(uint8_t *)(&(motor->Position_PID.ki) + 1);
	txdata[6] = *(uint8_t *)(&(motor->Position_PID.ki) + 2);
	txdata[7] = *(uint8_t *)(&(motor->Position_PID.ki) + 3);
	txdata[8] = *(uint8_t *) &(motor->Position_PID.kd);
	txdata[9] = *(uint8_t *)(&(motor->Position_PID.kd) + 1);
	txdata[10] = *(uint8_t *)(&(motor->Position_PID.kd) + 2);
	txdata[11] = *(uint8_t *)(&(motor->Position_PID.kd) + 3);
	txdata[12] = *(uint8_t *) &(motor->Position_PID.sum_max);
	txdata[13] = *(uint8_t *)(&(motor->Position_PID.sum_max) + 1);
	txdata[14] = *(uint8_t *)(&(motor->Position_PID.sum_max) + 2);
	txdata[15] = *(uint8_t *)(&(motor->Position_PID.sum_max) + 3);
	txdata[16] = *(uint8_t *) &(motor->Position_PID.output_max);
	txdata[17] = *(uint8_t *)(&(motor->Position_PID.output_max) + 1);
	txdata[18] = *(uint8_t *)(&(motor->Position_PID.output_max) + 2);
	txdata[19] = *(uint8_t *)(&(motor->Position_PID.output_max) + 3);

	uint32_t id_temp = motor->Device_ID | White_Mark | CMD_POSITION_PID_SET;
	FDCAN_SendMessageWithBaudSwitch(motor->hfdcan, txdata, FDCAN_DLC_BYTES_20, id_temp);
}

