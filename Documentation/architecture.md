# 软件架构说明

## 架构目标

EdgeVoice-485 面向多通道采集、RS485/Modbus RTU 兼容通信、CAN 总线扩展和本地命令输入。软件按工程入口、应用层、服务层、板级驱动、通用工具和第三方中间件划分。

当前工程已完成 FreeRTOS 最小任务接入，应用入口由 `main()` 进入 BSP 初始化、应用初始化、任务创建和调度器启动流程。

## 目录分层

```text
Projects/STM32F103ZE_EdgeVoice485/Src
主函数、中断入口、系统文件、FreeRTOS Hook 和工程级源文件。

Projects/STM32F103ZE_EdgeVoice485/Inc
工程级配置头文件，包括 project_config.h、board_config.h、FreeRTOSConfig.h。

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
FreeRTOS 内核源码和移植文件。
```

## 当前运行链路

```text
Reset_Handler
  -> SystemInit()
  -> main()
      -> BSP_Init()
          -> BSP_Clock_Init()
          -> BSP_LED_Init()
      -> APP_Init()
          -> APP_Tasks_Init()
              -> Task_System_Init()
      -> APP_Start()
          -> APP_Tasks_Create()
              -> Task_System_Create()
          -> vTaskStartScheduler()
              -> Task_System_Entry()
```

`PROJECT_USE_FREERTOS` 当前配置为 1，程序进入 FreeRTOS 启动路径。系统任务创建成功后启动调度器，`Task_System_Entry()` 周期翻转 LED0。

## 应用层结构

```text
app.c
应用初始化、应用启动和应用运行入口。

app_tasks.c
集中管理任务模块初始化和任务创建。

task_system.c
系统任务创建和系统任务入口。
```

## BSP 结构

```text
bsp.c
板级初始化总入口。

bsp_clock.c
系统时钟更新、NVIC 分组配置和阻塞延时。

bsp_led.c
LED GPIO 初始化、点亮、熄灭和翻转接口。
```

## FreeRTOS 接入结构

```text
FreeRTOSConfig.h
FreeRTOS 裁剪、堆大小、任务配置、Hook、中断优先级和 Cortex-M3 异常入口映射。

freertos_hooks.c
内存申请失败 Hook 和任务栈溢出 Hook。

Middlewares/Third_Party/FreeRTOS/Source
FreeRTOS 内核源码。
```

## 分层约定

应用层负责业务流程和任务组织，不直接操作寄存器。

服务层负责协议、数据模型、诊断和命令分发，不直接占用底层外设资源。

BSP 层负责板级硬件资源初始化和基础读写接口，不承载业务状态机。

通用工具模块保持无硬件依赖。
