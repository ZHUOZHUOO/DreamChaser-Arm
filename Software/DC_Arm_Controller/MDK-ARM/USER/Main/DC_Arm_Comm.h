#ifndef __DC_ARM_COMM_H
#define __DC_ARM_COMM_H

#ifdef __cplusplus
extern "C" {
#endif 

#include "DC_Arm_Control.h"
#include "util_fdcan.h"
#include "configure.h"

//-----------FDCAN ID Setting------------//

#define Slave0_Arm_ID 	0x420
#define Slave1_Arm_ID 	0x430
#define Slave2_Arm_ID 	0x440
#define Slave0_End_ID 	0x450
#define Slave1_End_ID 	0x460
#define Slave2_End_ID 	0x470

#define White_Mark 		0x000
#define Read_Mark 		0x100

#define FILTER_ID_1     0x500
#define FILTER_ID_2     0x780
#define DEVICE_ID_MASK  0x7F0
#define CMD_MASK        0x00F

//-----------FDCAN Command Setting------------//

#define CMD_THETA_SET           0x001
#define CMD_CURRENT_SET         0x002
#define CMD_THETA_CURRENT_FDB   0x003
#define CMD_ERROR_FDB           0x004
#define CMD_IQ_PID_SET          0x005
#define CMD_IQ_PID_FDB          0x006
#define CMD_ID_PID_SET          0x007
#define CMD_ID_PID_FDB          0x008
#define CMD_POSITION_PID_SET    0x009
#define CMD_POSITION_PID_FDB    0x00A

void FDCAN_IntFilterAndStart(FDCAN_HandleTypeDef *hfdcan);

#ifdef __cplusplus
}
#endif 
	
#endif /* __DC_ARM_COMM_H */
