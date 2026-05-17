# Keil 构建说明

## 开发环境

```text
IDE：Keil uVision5
编译器：ARMCC V5.06 update 6 (build 750)
芯片：STM32F103ZE
外设库：STM32F10x Standard Peripheral Library
烧录器：DAPLink
```

## 工程文件

```text
Projects/STM32F103ZE_EdgeVoice485/MDK-ARM/EdgeVoice485.uvprojx
```

## 当前构建状态

```text
0 Error(s), 0 Warning(s)
Program Size: Code=6428 RO-data=336 RW-data=128 ZI-data=22312
```

当前工程已将 FreeRTOS 最小内核文件加入 Keil 编译列表，`PROJECT_USE_FREERTOS` 配置为 1。

## 已参与编译的 FreeRTOS 文件

```text
Middlewares/Third_Party/FreeRTOS/Source/list.c
Middlewares/Third_Party/FreeRTOS/Source/queue.c
Middlewares/Third_Party/FreeRTOS/Source/tasks.c
Middlewares/Third_Party/FreeRTOS/Source/portable/RVDS/ARM_CM3/port.c
Middlewares/Third_Party/FreeRTOS/Source/portable/MemMang/heap_4.c
```

## 当前应用文件

```text
Projects/STM32F103ZE_EdgeVoice485/Application/Src/app.c
Projects/STM32F103ZE_EdgeVoice485/Application/Src/app_tasks.c
Projects/STM32F103ZE_EdgeVoice485/Application/Src/task_system.c
Projects/STM32F103ZE_EdgeVoice485/Src/freertos_hooks.c
```

## 构建输出

`Objects/` 和 `Listings/` 为 Keil 生成目录，包含 `.o`、`.crf`、`.d`、`.map`、`.lst`、`.hex`、`.axf` 等文件。仓库通过 `.gitignore` 排除编译产物，目录结构通过 `.gitkeep` 保留。

## 构建步骤

```text
1. 打开 Projects/STM32F103ZE_EdgeVoice485/MDK-ARM/EdgeVoice485.uvprojx
2. 选择 STM32F103ZE 目标
3. 使用 ARMCC V5 编译器
4. 执行 Rebuild
5. 检查 Build Output 中的错误和警告数量
6. 生成 HEX 后通过 DAPLink 下载
```


