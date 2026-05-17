# EdgeVoice-485

## 项目简介

EdgeVoice-485 是一个基于 STM32F103ZE 的工业数据采集与通信网关项目，面向现场设备的数据接入、总线通信和本地交互场景。

项目以 STM32F103ZE 开发板为硬件平台，采用 STM32 标准外设库进行底层开发。工程按项目入口、应用层、服务层、板级驱动、通用工具、第三方中间件和文档进行组织。当前工程已完成 Keil 工程搭建、系统时钟配置、板载 LED 验证、BSP 基础封装以及应用入口整理。

规划功能包括多通道数据采集、RS485/Modbus RTU 兼容通信、CAN 总线扩展以及离线语音模块接入。语音模块用于本地命令输入和设备交互验证。

## 技术方案

- 主控芯片：STM32F103ZE
- 开发环境：Keil MDK，ARMCC V5 编译器
- 底层库：STM32 标准外设库
- 系统架构：裸机工程基础上迁移到 FreeRTOS 多任务架构
- 主要外设：GPIO、USART、RS485、CAN、TIM、ADC、DMA、Flash
- 通信协议：Modbus RTU 兼容通信协议

## 当前工程状态

当前版本完成了最小可运行工程和基础工程框架，程序可在 STM32F103ZE 开发板上正常编译、下载和运行。工程入口已整理为系统初始化、应用初始化和应用运行三部分。

FreeRTOS 相关目录和配置文件已预留，内核源码尚未接入编译。当前默认配置为裸机运行模式，板载 LED 用于验证系统时钟、BSP 初始化和应用入口链路。

## 工程目录

```text
Documentation/                                      项目说明、构建记录和阶段性设计文档
Drivers/BSP/EdgeVoice485_Board/                    板级支持包
Drivers/CMSIS/                                      CMSIS 内核与芯片头文件
Drivers/STM32F10x_StdPeriph_Driver/                STM32 标准外设库
Middlewares/Third_Party/FreeRTOS/                  FreeRTOS 内核预留目录
Projects/STM32F103ZE_EdgeVoice485/Application/     应用层代码
Projects/STM32F103ZE_EdgeVoice485/Services/        服务层代码
Projects/STM32F103ZE_EdgeVoice485/Inc/             工程级配置头文件
Projects/STM32F103ZE_EdgeVoice485/Src/             主函数、中断文件和系统文件
Projects/STM32F103ZE_EdgeVoice485/MDK-ARM/         Keil 工程文件
Utilities/                                         通用工具模块
```
