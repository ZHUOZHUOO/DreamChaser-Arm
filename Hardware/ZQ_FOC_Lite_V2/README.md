# 硬件改动

- 为了方便在HT4315电机上安装PCB，在PCB上加了3个M2的孔，在装配时参照DreamChaser-Arm\SW files\HT4315_V2路径下提供的HT4315_V2的装配体文件

- 为了方便管理电机的CAN ID，添加了拨码开关。但需要注意BOOT0引脚复用为GPIO Input，建议使用STM32 ST-LINK Utility对芯片进行配置，使系统从nBOOT0启动。

- Utility配置截图在(DreamChaser-Arm\Hardware\ZQ_FOC_Lite_V2\STM32 ST-LINK Utility配置.png)。设计者因受条件限制无法完成测试，若按照Utility配置截图进行配置后代码仍无法正常启动，请自行搜索STM32G431KBU6的BOOT0引脚复用解决方案。

# 机械改动

- 为了适应新的PCB元器件布局，需要对电机后盖进行重新设计