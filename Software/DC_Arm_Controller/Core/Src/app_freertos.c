/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * File Name          : app_freertos.c
  * Description        : Code for freertos applications
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "FreeRTOS.h"
#include "task.h"
#include "main.h"
#include "cmsis_os.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN Variables */

/* USER CODE END Variables */
/* Definitions for defaultTask */
osThreadId_t defaultTaskHandle;
const osThreadAttr_t defaultTask_attributes = {
  .name = "defaultTask",
  .priority = (osPriority_t) osPriorityNormal,
  .stack_size = 256 * 4
};
/* Definitions for RGB */
osThreadId_t RGBHandle;
const osThreadAttr_t RGB_attributes = {
  .name = "RGB",
  .priority = (osPriority_t) osPriorityLow1,
  .stack_size = 512 * 4
};
/* Definitions for Communite */
osThreadId_t CommuniteHandle;
const osThreadAttr_t Communite_attributes = {
  .name = "Communite",
  .priority = (osPriority_t) osPriorityRealtime1,
  .stack_size = 1024 * 4
};
/* Definitions for Main_Control */
osThreadId_t Main_ControlHandle;
const osThreadAttr_t Main_Control_attributes = {
  .name = "Main_Control",
  .priority = (osPriority_t) osPriorityHigh1,
  .stack_size = 4096 * 4
};
/* Definitions for Error_Detect */
osThreadId_t Error_DetectHandle;
const osThreadAttr_t Error_Detect_attributes = {
  .name = "Error_Detect",
  .priority = (osPriority_t) osPriorityBelowNormal,
  .stack_size = 256 * 4
};

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN FunctionPrototypes */

/* USER CODE END FunctionPrototypes */

void StartDefaultTask(void *argument);
void Task_RGB(void *argument);
void Task_Communite(void *argument);
void Task_Main_Control(void *argument);
void Task_Error_Detect(void *argument);

void MX_FREERTOS_Init(void); /* (MISRA C 2004 rule 8.1) */

/**
  * @brief  FreeRTOS initialization
  * @param  None
  * @retval None
  */
void MX_FREERTOS_Init(void) {
  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* USER CODE BEGIN RTOS_MUTEX */
  /* add mutexes, ... */
  /* USER CODE END RTOS_MUTEX */

  /* USER CODE BEGIN RTOS_SEMAPHORES */
  /* add semaphores, ... */
  /* USER CODE END RTOS_SEMAPHORES */

  /* USER CODE BEGIN RTOS_TIMERS */
  /* start timers, add new ones, ... */
  /* USER CODE END RTOS_TIMERS */

  /* USER CODE BEGIN RTOS_QUEUES */
  /* add queues, ... */
  /* USER CODE END RTOS_QUEUES */

  /* Create the thread(s) */
  /* creation of defaultTask */
  defaultTaskHandle = osThreadNew(StartDefaultTask, NULL, &defaultTask_attributes);

  /* creation of RGB */
  RGBHandle = osThreadNew(Task_RGB, NULL, &RGB_attributes);

  /* creation of Communite */
  CommuniteHandle = osThreadNew(Task_Communite, NULL, &Communite_attributes);

  /* creation of Main_Control */
  Main_ControlHandle = osThreadNew(Task_Main_Control, NULL, &Main_Control_attributes);

  /* creation of Error_Detect */
  Error_DetectHandle = osThreadNew(Task_Error_Detect, NULL, &Error_Detect_attributes);

  /* USER CODE BEGIN RTOS_THREADS */
  /* add threads, ... */
  /* USER CODE END RTOS_THREADS */

  /* USER CODE BEGIN RTOS_EVENTS */
  /* add events, ... */
  /* USER CODE END RTOS_EVENTS */

}

/* USER CODE BEGIN Header_StartDefaultTask */
/**
  * @brief  Function implementing the defaultTask thread.
  * @param  argument: Not used
  * @retval None
  */
/* USER CODE END Header_StartDefaultTask */
void StartDefaultTask(void *argument)
{
  /* USER CODE BEGIN StartDefaultTask */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END StartDefaultTask */
}

/* USER CODE BEGIN Header_Task_RGB */
/**
* @brief Function implementing the RGB thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_Task_RGB */
__weak void Task_RGB(void *argument)
{
  /* USER CODE BEGIN Task_RGB */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END Task_RGB */
}

/* USER CODE BEGIN Header_Task_Communite */
/**
* @brief Function implementing the Communite thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_Task_Communite */
__weak void Task_Communite(void *argument)
{
  /* USER CODE BEGIN Task_Communite */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END Task_Communite */
}

/* USER CODE BEGIN Header_Task_Main_Control */
/**
* @brief Function implementing the Main_Control thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_Task_Main_Control */
__weak void Task_Main_Control(void *argument)
{
  /* USER CODE BEGIN Task_Main_Control */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END Task_Main_Control */
}

/* USER CODE BEGIN Header_Task_Error_Detect */
/**
* @brief Function implementing the Error_Detect thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_Task_Error_Detect */
__weak void Task_Error_Detect(void *argument)
{
  /* USER CODE BEGIN Task_Error_Detect */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END Task_Error_Detect */
}

/* Private application code --------------------------------------------------*/
/* USER CODE BEGIN Application */

/* USER CODE END Application */

