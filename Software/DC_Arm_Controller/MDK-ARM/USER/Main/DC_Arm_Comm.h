#ifndef __DC_ARM_COMM_H
#define __DC_ARM_COMM_H

#include "DC_Arm_Control.h"
#include "util_fdcan.h"
#include "configure.h"

void FDCAN_IntFilterAndStart(FDCAN_HandleTypeDef *hfdcan);


#endif /* __DC_ARM_COMM_H */
