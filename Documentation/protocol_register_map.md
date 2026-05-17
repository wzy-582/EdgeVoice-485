# 协议与寄存器映射

## 协议范围

RS485 通信采用 Modbus RTU 兼容帧格式。协议层负责地址检查、功能码处理、长度检查、CRC16 校验、寄存器访问和异常响应。

串口收发、DMA 缓冲、RS485 方向控制由 BSP 或通信链路模块负责。协议层不直接操作 USART、DMA 和 GPIO。

## 帧格式

```text
从机地址 | 功能码 | 数据区 | CRC_L | CRC_H
```

CRC16 采用 Modbus RTU 常用 CRC16，低字节在前，高字节在后。

## 功能码规划

| 功能码 | 名称 | 说明 |
|---:|---|---|
| 0x03 | Read Holding Registers | 读取保持寄存器 |
| 0x06 | Write Single Register | 写单个保持寄存器 |
| 0x10 | Write Multiple Registers | 写多个保持寄存器 |

## 寄存器地址规划

| 地址 | 名称 | 属性 | 说明 |
|---:|---|---|---|
| 0x0000 | DEVICE_STATUS | R | 设备状态字 |
| 0x0001 | ERROR_FLAGS | R | 错误标志 |
| 0x0002 | CONTROL_CMD | W | 控制命令 |
| 0x0003 | SYSTEM_TICK_L | R | 系统运行计数低 16 位 |
| 0x0004 | SYSTEM_TICK_H | R | 系统运行计数高 16 位 |
| 0x0010 | SAMPLE_CH0 | R | 采集通道 0 |
| 0x0011 | SAMPLE_CH1 | R | 采集通道 1 |
| 0x0012 | SAMPLE_CH2 | R | 采集通道 2 |
| 0x0013 | SAMPLE_CH3 | R | 采集通道 3 |
| 0x0020 | RS485_RX_COUNT | R | RS485 接收计数 |
| 0x0021 | RS485_TX_COUNT | R | RS485 发送计数 |
| 0x0022 | CAN_RX_COUNT | R | CAN 接收计数 |
| 0x0023 | CAN_TX_COUNT | R | CAN 发送计数 |
| 0x0030 | VOICE_CMD | R | 最近一次语音命令 |
| 0x0031 | VOICE_STATUS | R | 语音模块状态 |

## 设备状态字

| Bit | 名称 | 说明 |
|---:|---|---|
| 0 | SYS_RUNNING | 系统运行 |
| 1 | ACQ_ACTIVE | 采集运行 |
| 2 | RS485_ACTIVE | RS485 通信活动 |
| 3 | CAN_ACTIVE | CAN 通信活动 |
| 4 | VOICE_ACTIVE | 语音模块活动 |

## 错误标志

| Bit | 名称 | 说明 |
|---:|---|---|
| 0 | ERR_PARAM | 参数错误 |
| 1 | ERR_CRC | CRC 校验错误 |
| 2 | ERR_FRAME | 帧格式错误 |
| 3 | ERR_TIMEOUT | 通信超时 |
| 4 | ERR_ACQ | 采集错误 |
| 5 | ERR_CAN | CAN 通信错误 |
| 6 | ERR_VOICE | 语音模块错误 |

## 控制命令

| 值 | 名称 | 说明 |
|---:|---|---|
| 0x0000 | CMD_NONE | 空命令 |
| 0x0001 | CMD_START_ACQ | 启动采集 |
| 0x0002 | CMD_STOP_ACQ | 停止采集 |
| 0x0003 | CMD_CLEAR_ERROR | 清除错误 |
| 0x0004 | CMD_SAVE_PARAM | 保存参数 |

## 数据格式

寄存器宽度为 16 bit。多寄存器数据按高地址保存高 16 位、低地址保存低 16 位的方式组织。协议帧内多字节字段按 Modbus RTU 常用高字节在前的方式组织。
