# 引脚分配表

## 已验证引脚

| 功能 | MCU 引脚/端口 | 有效电平 | 当前用途 | 说明 |
|---|---:|---:|---|---|
| LED0 | PB5 | 低电平点亮 | 系统任务心跳 | `BOARD_LED0_GPIO_PORT` / `BOARD_LED0_GPIO_PIN` |
| LED1 | PE5 | 低电平点亮 | 启动和异常指示 | `BOARD_LED1_GPIO_PORT` / `BOARD_LED1_GPIO_PIN` |

## LED 配置

LED 引脚宏定义位于：

```text
Projects/STM32F103ZE_EdgeVoice485/Inc/board_config.h
```

当前配置如下：

```text
BOARD_LED0_GPIO_PORT    GPIOB
BOARD_LED0_GPIO_PIN     GPIO_Pin_5

BOARD_LED1_GPIO_PORT    GPIOE
BOARD_LED1_GPIO_PIN     GPIO_Pin_5

BOARD_LED_ACTIVE_LOW    1
```

LED 驱动文件位于：

```text
Drivers/BSP/EdgeVoice485_Board/Src/bsp_led.c
Drivers/BSP/EdgeVoice485_Board/Inc/bsp_led.h
```

## 后续外设引脚规划

| 模块 | 外设资源 | 用途 |
|---|---|---|
| RS485 | USART + DE/RE GPIO | 半双工总线通信 |
| CAN | CAN1 | CAN 总线通信 |
| Voice UART | USART | 离线语音模块接入 |
| ADC Channels | ADC + DMA | 多通道数据采集 |
| Timer | TIM | 周期采样和时间基准 |

