# Keil 构建说明

## 开发环境

```text
IDE：Keil uVision5
编译器：ARMCC V5.06
芯片：STM32F103ZE
外设库：STM32F10x Standard Peripheral Library
烧录器：DAPLink
```

## 工程文件

```text
Projects/STM32F103ZE_EdgeVoice485/MDK-ARM/EdgeVoice485.uvprojx
```

## 构建状态

```text
0 Error(s), 0 Warning(s)
Program Size: Code=1568 RO-data=336 RW-data=20 ZI-data=1636
```

程序已完成下载和运行验证，板载 LED 可周期闪烁。

## 构建输出

`Objects/` 和 `Listings/` 为 Keil 生成目录，包含 `.o`、`.crf`、`.d`、`.map`、`.lst`、`.hex`、`.axf` 等文件。仓库通过 `.gitignore` 排除编译产物，目录结构通过 `.gitkeep` 保留。

## FreeRTOS 状态

当前工程未将 FreeRTOS 内核源码加入编译。`Middlewares/Third_Party/FreeRTOS/` 保留内核目录结构，`PROJECT_USE_FREERTOS` 当前配置为 0。
