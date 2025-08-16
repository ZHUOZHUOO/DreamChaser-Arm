#include "OLED_Periph.h"



void Task_OLED_Display(){
		
		OLED_Init();
	
	  while(1){ 
		//编辑显存数据
		//坐标-内容-大小-正/反色
//		GUI_ShowChar(0,10,'i',16,0);//显示字符
//		GUI_ShowString(0,10,"channel1:",16,1);//显示字符串
//		GUI_ShowNum(0,30,DCDC_Voltage[0],3,16,1);//显示数字
//		GUI_DrawBMP(50,50,20,20,BMP1,0);//显示图片，图片编码在bmp.h里面
	
		//将显存中的数据更新到OLED
		OLED_Clear();
	
	  //更新频率10Hz
		osDelay(100);
		}
}

//void Switch_SPI_to_GPIO(SPI_HandleTypeDef* hspi) {
//    // 1. 反初始化SPI（释放引脚）
//    HAL_SPI_DeInit(hspi);

//    // 2. 配置为GPIO输出
//    GPIO_InitTypeDef GPIO_InitStruct = {0};
//    GPIO_InitStruct.Pin = GPIO_PIN_5 | GPIO_PIN_7;
//    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
//    GPIO_InitStruct.Pull = GPIO_PULLUP;
//    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
//    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
//}