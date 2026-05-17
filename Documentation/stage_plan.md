# 阶段计划

## 阶段 0：Keil 最小工程与 BSP LED 验证

目标：建立可编译、可烧录、可运行的最小工程。

状态：已完成。

已完成内容：

```text
Keil MDK 工程创建
STM32F103ZE 启动文件接入
CMSIS 和 STM32 标准外设库接入
系统时钟更新
NVIC 分组配置
BSP_Init 入口建立
LED GPIO 驱动封装
APP_Init / APP_Start / APP_Run 入口整理
裸机 LED 周期闪烁验证
Git 和 GitHub 工程管理建立
```

验收记录：

```text
Keil 编译通过
DAPLink 下载通过
板载 LED 可周期闪烁
```

## 阶段 1：FreeRTOS 内核接入与系统任务

目标：建立 FreeRTOS 最小运行框架。

状态：已完成工程接入和编译验证。

已完成内容：

```text
FreeRTOSConfig.h 配置
FreeRTOS 最小内核文件加入 Keil 编译
heap_4.c 动态内存管理接入
Cortex-M3 port.c 接入
PROJECT_USE_FREERTOS 配置为 1
APP_Tasks_Init 任务模块初始化入口建立
APP_Tasks_Create 任务创建入口建立
Task_System_Create 系统任务创建接口实现
Task_System_Entry 系统任务入口实现
vApplicationMallocFailedHook 实现
vApplicationStackOverflowHook 实现
```

验收记录：

```text
Keil ARMCC V5.06 编译通过
0 Error(s), 0 Warning(s)
Program Size: Code=6428 RO-data=336 RW-data=128 ZI-data=22312
```

## 阶段 2：基础串口日志和运行诊断

目标：建立调试串口输出和基础运行诊断接口。

主要内容：

```text
USART BSP 初始化
printf 重定向
日志接口封装
系统启动日志
任务运行计数
错误码定义
诊断信息输出
```

验收标准：

```text
串口可输出启动信息
系统任务可输出运行计数
错误码可统一打印
日志接口不直接散落在业务模块中
```

## 阶段 3：基础采集与数据模型

目标：建立 ADC 采集入口和内部数据模型。

主要内容：

```text
ADC 通道配置
采样触发入口
采样缓存
基础滤波接口
数据模型读写接口
采集任务
```

验收标准：

```text
采样数据可周期更新
数据模型可被通信层读取
采样接口和业务数据分离
任务间数据访问方式清晰
```

## 阶段 4：RS485 接收链路与协议前置框架

目标：建立 USART/RS485 接收链路、帧缓存和协议解析入口。

主要内容：

```text
USART 初始化
RS485 收发方向控制
接收缓冲区
帧边界识别
协议解析入口
RS485 接收任务
协议处理任务
```

验收标准：

```text
串口接收稳定
半双工方向控制正常
协议层可获得完整帧
异常帧处理后可继续接收后续帧
```

## 阶段 5：Modbus RTU 兼容从机与统一发送链路

目标：实现基础寄存器访问、CRC 校验、异常响应和统一发送链路。

主要内容：

```text
设备地址配置
功能码处理
CRC16 校验
寄存器映射
异常响应
通信发送任务
```

验收标准：

```text
读寄存器功能正常
写寄存器功能正常
CRC 错误帧可被识别
异常响应格式正确
业务模块通过统一接口提交发送数据
```

## 阶段 6：CAN 网关与语音命令接入

目标：建立 CAN 收发链路，并将语音命令接入命令分发层。

主要内容：

```text
CAN 初始化
CAN 收发队列
路由服务
语音 UART 接收
命令码解析
命令分发
```

验收标准：

```text
CAN 帧可收发
RS485 与 CAN 数据路由可验证
语音命令可触发内部命令
通信错误可统计
```
