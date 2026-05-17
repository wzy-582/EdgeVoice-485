# 引脚分配表

| 功能 | MCU 引脚/端口 | 有效电平 | 当前状态 | 说明 |
|---|---:|---:|---|---|
| LED0 | PB5 | 低电平点亮 | 已启用 | `BOARD_LED0_GPIO_PORT` / `BOARD_LED0_GPIO_PIN` |
| LED1 | PE5 | 低电平点亮 | 已启用 | `BOARD_LED1_GPIO_PORT` / `BOARD_LED1_GPIO_PIN` |
| RS485 UART | 待确认 | 待确认 | 未启用 | 串口收发 |
| RS485 DE/RE | 待确认 | 待确认 | 未启用 | 收发方向控制 |
| CAN | 待确认 | 待确认 | 未启用 | CAN 总线 |
| Voice UART | 待确认 | 待确认 | 未启用 | 语音模块串口 |
| ADC Channels | 待确认 | 待确认 | 未启用 | 多通道采集 |

引脚宏定义位于 `board_config.h` 或对应 BSP 配置文件。
