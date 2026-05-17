# FreeRTOS 接入说明

## 接入目标

本文记录 EdgeVoice-485 工程中 FreeRTOS 的接入方式。当前工程通过 `PROJECT_USE_FREERTOS` 控制应用启动路径，配置为 1 时进入 FreeRTOS 任务调度流程。

## 目录位置

```text
Middlewares/Third_Party/FreeRTOS/Source
```

FreeRTOS 工程配置文件位于：

```text
Projects/STM32F103ZE_EdgeVoice485/Inc/FreeRTOSConfig.h
```

Hook 函数文件位于：

```text
Projects/STM32F103ZE_EdgeVoice485/Src/freertos_hooks.c
```

## 当前编译文件

```text
list.c
queue.c
tasks.c
portable/RVDS/ARM_CM3/port.c
portable/MemMang/heap_4.c
```

## 启动配置

```text
PROJECT_USE_FREERTOS    1
```

启动链路如下：

```text
main()
  -> BSP_Init()
  -> APP_Init()
  -> APP_Start()
      -> APP_Tasks_Create()
          -> Task_System_Create()
      -> vTaskStartScheduler()
```

调度器启动后进入 `Task_System_Entry()`，系统任务按 `APP_SYSTEM_TASK_PERIOD_MS` 周期运行。

## 系统任务配置

```text
任务名称：system
任务栈大小：128 words
任务优先级：1
运行周期：500 ms
运行指示：LED0 周期翻转
```

任务创建文件：

```text
Projects/STM32F103ZE_EdgeVoice485/Application/Src/task_system.c
```

## Hook 配置

`FreeRTOSConfig.h` 中已启用：

```text
configUSE_MALLOC_FAILED_HOOK      1
configCHECK_FOR_STACK_OVERFLOW    2
```

Hook 行为：

```text
vApplicationMallocFailedHook
内存申请失败时关闭调度相关中断并进入 LED 指示循环。

vApplicationStackOverflowHook
任务栈溢出时关闭调度相关中断并进入 LED 指示循环。
```

## 中断入口映射

`FreeRTOSConfig.h` 中完成 Cortex-M3 异常入口映射：

```text
vPortSVCHandler       SVC_Handler
xPortPendSVHandler    PendSV_Handler
xPortSysTickHandler   SysTick_Handler
```

## 中断优先级配置

```text
configPRIO_BITS                         4
configLIBRARY_LOWEST_INTERRUPT_PRIORITY 15
configLIBRARY_MAX_SYSCALL_INTERRUPT_PRIORITY 5
```

后续使用 `FromISR` 类 FreeRTOS API 时，外设中断优先级按该配置统一检查。

## 内存配置

```text
configSUPPORT_DYNAMIC_ALLOCATION    1
configSUPPORT_STATIC_ALLOCATION     0
configTOTAL_HEAP_SIZE               20 KB
```

当前使用 `heap_4.c` 作为动态内存管理方案。

## 构建记录

```text
编译器：ARMCC V5.06 update 6 (build 750)
结果：0 Error(s), 0 Warning(s)
Program Size: Code=6428 RO-data=336 RW-data=128 ZI-data=22312
```
