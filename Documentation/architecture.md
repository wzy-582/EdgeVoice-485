# 软件架构说明

## 架构目标

EdgeVoice-485 面向多通道采集、RS485/Modbus RTU 兼容通信、CAN 总线扩展和本地命令输入。软件按工程入口、应用层、服务层、板级驱动、通用工具和第三方中间件划分。

## 目录分层

```text
Projects/STM32F103ZE_EdgeVoice485/Src
主函数、中断入口、系统文件和重定向代码。

Projects/STM32F103ZE_EdgeVoice485/Inc
工程级配置头文件。

Projects/STM32F103ZE_EdgeVoice485/Application
应用入口、任务创建、任务运行和业务流程组织。

Projects/STM32F103ZE_EdgeVoice485/Services
数据模型、采样管理、协议处理、命令分发、诊断和日志。

Drivers/BSP/EdgeVoice485_Board
时钟、GPIO、LED、USART、RS485、CAN、ADC、Timer 等板级资源封装。

Drivers/CMSIS
CMSIS 内核文件和 STM32F10x 设备头文件。

Drivers/STM32F10x_StdPeriph_Driver
STM32 标准外设库。

Utilities
CRC、环形缓冲区、字节序处理和滤波等通用软件模块。

Middlewares/Third_Party/FreeRTOS
FreeRTOS 内核目录。
```

## 当前运行链路

```text
Reset_Handler
  -> SystemInit()
  -> main()
      -> BSP_Init()
      -> APP_Init()
      -> APP_Start()
      -> while (1)
          -> APP_Run()
```

`PROJECT_USE_FREERTOS` 当前配置为 0，程序运行在裸机循环中。应用层通过 `APP_Run()` 周期翻转板载 LED，验证工程入口、时钟配置和 BSP 基础封装。

## 分层约定

应用层负责业务流程和任务组织，不直接操作寄存器。

服务层负责协议、数据模型、诊断和命令分发，不直接占用底层外设资源。

BSP 层负责板级硬件资源初始化和基础读写接口，不承载业务状态机。

通用工具模块保持无硬件依赖。
