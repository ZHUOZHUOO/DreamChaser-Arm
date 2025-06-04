#ifndef __DC_ARM_COMM_H
#define __DC_ARM_COMM_H

#include "DC_Arm_Control.h"
#include "util_fdcan.h"
#include "configure.h"

#define CMD_THETA_SET 0x01
#define CMD_CURRENT_SET 0x02
#define CMD_THETA_CURRENT_FEEDBACK 0x03
#define CMD_ERROR_FEEDBACK 0x04

void FDCAN_IntFilterAndStart(FDCAN_HandleTypeDef *hfdcan);


#endif /* __DC_ARM_COMM_H */
