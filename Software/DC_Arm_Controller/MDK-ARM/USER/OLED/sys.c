#include "sys.h"

void NVIC_Configuration(void)
{

    HAL_NVIC_SetPriorityGrouping(NVIC_PRIORITYGROUP_2);	//设置NVIC中断分组2:2位抢占优先级，2位响应优先级

}
