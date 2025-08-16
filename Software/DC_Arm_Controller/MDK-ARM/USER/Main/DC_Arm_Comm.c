#include "DC_Arm_Comm.h"

void FDCAN_IntFilterAndStart(FDCAN_HandleTypeDef *hfdcan) {
    //--------FDCAN1 Filter and Start--------//
	FDCAN_FilterTypeDef sFilterConfig;
	sFilterConfig.IdType = FDCAN_STANDARD_ID;
	sFilterConfig.FilterIndex = 0;
	sFilterConfig.FilterType = FDCAN_FILTER_MASK;
	sFilterConfig.FilterConfig = FDCAN_FILTER_TO_RXFIFO0;
	sFilterConfig.FilterID1 = 0x500;
	sFilterConfig.FilterID2 = 0x780;
	if (HAL_FDCAN_ConfigFilter(hfdcan, &sFilterConfig) != HAL_OK)
	{
		FDCAN_ErrorHandler();
	}
	if (HAL_FDCAN_ConfigGlobalFilter(hfdcan, FDCAN_REJECT, FDCAN_REJECT, FDCAN_FILTER_REMOTE, FDCAN_FILTER_REMOTE) != HAL_OK)
	{
		FDCAN_ErrorHandler();
	}
	if (HAL_FDCAN_Start(hfdcan) != HAL_OK)
	{
		FDCAN_ErrorHandler();
	}
	if (HAL_FDCAN_ActivateNotification(hfdcan, FDCAN_IT_RX_FIFO0_NEW_MESSAGE, 0) != HAL_OK)
	{
		FDCAN_ErrorHandler();
	}
	if (HAL_FDCAN_ActivateNotification(hfdcan, FDCAN_IT_BUS_OFF, 0) != HAL_OK) 
	{ 
		FDCAN_ErrorHandler(); 
	}
}


void DC_Arm_Comm_Handler(Motor_Struct *motor, uint32_t cmd, uint8_t *rxdata)
{
    // Decode the received data
	switch (cmd)
	{
	case CMD_THETA_CURRENT_FDB:
		motor->Theta_fed = *(float *)rxdata;
		motor->Current_fed = *(float *)(rxdata + 4);
		break;
	case CMD_ERROR_FDB:
		motor->Error_Status.SAFETY_STATE = rxdata[0] & 0x01;
		motor->Error_Status.OVER_VOLTAGE_STATE = (rxdata[0] >> 1) & 0x01;
		motor->Error_Status.UNDER_VOLTAGE_STATE = (rxdata[0] >> 2) & 0x01;
		motor->Error_Status.OVER_CURRENT_STATE = (rxdata[0] >> 3) & 0x01;
		motor->Error_Status.OVER_SPEED_STATE = (rxdata[0] >> 4) & 0x01;
		motor->Error_Status.OVER_TEMPERATURE_STATE = (rxdata[0] >> 5) & 0x01;
		motor->Error_Status.DRV8323_ERROR_STATE = (rxdata[0] >> 6) & 0x01;
		break;
	case CMD_IQ_PID_FDB:
		motor->Iq_PID.kp = *(float *)rxdata;
		motor->Iq_PID.ki = *(float *)(rxdata + 4);
		motor->Iq_PID.kd = *(float *)(rxdata + 8);
		motor->Iq_PID.output_max = *(float *)(rxdata + 12);
		break;
	case CMD_ID_PID_FDB:
		motor->Id_PID.kp = *(float *)rxdata;
		motor->Id_PID.ki = *(float *)(rxdata + 4);
		motor->Id_PID.kd = *(float *)(rxdata + 8);
		motor->Id_PID.output_max = *(float *)(rxdata + 12);
		break;
	case CMD_POSITION_PID_FDB:
		motor->Position_PID.kp = *(float *)rxdata;
		motor->Position_PID.ki = *(float *)(rxdata + 4);
		motor->Position_PID.kd = *(float *)(rxdata + 8);
		motor->Position_PID.output_max = *(float *)(rxdata + 12);
		break;
	default:
		// Handle other commands if necessary
		break;
	}
}

uint8_t RxData[64];
FDCAN_RxHeaderTypeDef RxHeader;
void HAL_FDCAN_RxFifo0Callback(FDCAN_HandleTypeDef *hfdcan, uint32_t RxFifo0ITs)
{
	if((RxFifo0ITs & FDCAN_IT_RX_FIFO0_NEW_MESSAGE)!=RESET)
	{
		if(hfdcan->Instance == FDCAN1) //Slave Arm
		{
			HAL_FDCAN_GetRxMessage(hfdcan, FDCAN_RX_FIFO0, &RxHeader, RxData);
			uint32_t cmd = RxHeader.Identifier & CMD_MASK;
			uint32_t device_id = RxHeader.Identifier & DEVICE_ID_MASK;
			Motor_Struct *pArm = NULL;
			switch(device_id)
			{
				case Slave0_Arm_ID | Read_Mark: pArm = &Slave0_Arm; break;
				case Slave1_Arm_ID | Read_Mark: pArm = &Slave1_Arm; break;
				case Slave2_Arm_ID | Read_Mark: pArm = &Slave2_Arm; break;
				default: break;
			}
			DC_Arm_Comm_Handler(pArm, cmd, RxData);
			if( HAL_FDCAN_ActivateNotification(hfdcan, FDCAN_IT_RX_FIFO0_NEW_MESSAGE, 0)!= HAL_OK) 
			{
				FDCAN_ErrorHandler();
			}
		}
		else if(hfdcan->Instance == FDCAN2) //Slave End
		{
			HAL_FDCAN_GetRxMessage(hfdcan, FDCAN_RX_FIFO0, &RxHeader, RxData);
			uint32_t cmd = RxHeader.Identifier & CMD_MASK;
			uint32_t device_id = RxHeader.Identifier & DEVICE_ID_MASK;
			Motor_Struct *pEnd = NULL;
			switch(device_id)
			{
				case Slave0_End_ID | Read_Mark: pEnd = &Slave0_End; break;
				case Slave1_End_ID | Read_Mark: pEnd = &Slave1_End; break;
				case Slave2_End_ID | Read_Mark: pEnd = &Slave2_End; break;
				default: break;
			}
			DC_Arm_Comm_Handler(pEnd, cmd, RxData);
			if( HAL_FDCAN_ActivateNotification(hfdcan, FDCAN_IT_RX_FIFO0_NEW_MESSAGE, 0)!= HAL_OK) 
			{
				FDCAN_ErrorHandler();
			}
		}
	}
}



