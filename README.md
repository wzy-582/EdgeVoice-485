# EdgeVoice-485

## 项目简介

EdgeVoice-485 是一个基于 STM32F103ZE 的工业数据采集与通信网关项目，面向现场设备的数据接入、总线通信和本地交互场景。

项目以 STM32F103ZE 开发板为硬件平台，采用 STM32 标准外设库进行底层开发。工程按项目入口、应用层、服务层、板级驱动、通用工具、第三方中间件和文档进行组织。当前工程已完成 Keil 工程搭建、系统时钟配置、板载 LED 验证、BSP 基础封装、应用入口整理以及 FreeRTOS 最小任务接入。

工程后续围绕多通道数据采集、RS485/Modbus RTU 兼容通信、CAN 总线扩展以及离线语音模块接入展开。语音模块用于本地命令输入和设备交互验证。

## 技术方案

- 主控芯片：STM32F103ZE
- 开发环境：Keil MDK，ARMCC V5 编译器
- 底层库：STM32 标准外设库
- 系统架构：FreeRTOS 多任务架构
- 主要外设：GPIO、USART、RS485、CAN、TIM、ADC、DMA、Flash
- 通信协议：Modbus RTU 兼容通信协议

## 当前工程状态

当前版本已接入 FreeRTOS 最小运行框架，`PROJECT_USE_FREERTOS` 配置为 1。程序入口整理为 BSP 初始化、应用初始化、任务创建和调度器启动四部分。

系统任务 `system task` 已加入应用层任务管理，由 `APP_Tasks_Create()` 创建。调度器启动后，系统任务按 500 ms 周期翻转 LED0，用于验证任务调度和系统运行状态。`APP_Run()` 保留裸机路径和异常停留时的 LED 指示逻辑。

FreeRTOS 已加入最小内核文件，包括 `list.c`、`queue.c`、`tasks.c`、`port.c` 和 `heap_4.c`。工程已实现内存申请失败 Hook 和任务栈溢出 Hook。

## 工程目录

```text
Documentation/                                      项目说明、构建记录和阶段性设计文档
Drivers/BSP/EdgeVoice485_Board/                    板级支持包
Drivers/CMSIS/                                      CMSIS 内核与芯片头文件
Drivers/STM32F10x_StdPeriph_Driver/                STM32 标准外设库
Middlewares/Third_Party/FreeRTOS/                  FreeRTOS 内核源码
Projects/STM32F103ZE_EdgeVoice485/Application/     应用层代码
Projects/STM32F103ZE_EdgeVoice485/Services/        服务层代码
Projects/STM32F103ZE_EdgeVoice485/Inc/             工程级配置头文件
Projects/STM32F103ZE_EdgeVoice485/Src/             主函数、中断文件和系统文件
Projects/STM32F103ZE_EdgeVoice485/MDK-ARM/         Keil 工程文件
Utilities/                                         通用工具模块
```

## 已完成内容

```text
Keil MDK 工程创建
STM32F103ZE 启动文件接入
系统时钟更新和 NVIC 分组配置
BSP_Init / APP_Init / APP_Start / APP_Run 入口整理
LED BSP 驱动封装
FreeRTOSConfig.h 配置
FreeRTOS 最小内核文件加入编译
system task 创建和任务入口实现
MallocFailedHook 和 StackOverflowHook 实现
Keil 编译通过
Git 和 GitHub 工程管理建立
```

## 构建记录

```text
编译器：ARMCC V5.06 update 6 (build 750)
构建结果：0 Error(s), 0 Warning(s)
Program Size: Code=6428 RO-data=336 RW-data=128 ZI-data=22312
```

## Git 提交说明

Keil 编译会生成 `Objects/` 和 `Listings/` 目录内容，仓库通过 `.gitignore` 排除 `.o`、`.d`、`.crf`、`.axf`、`.hex`、`.map`、`.lst` 等编译输出文件。
