#include "project_config.h"
#include "freertos_hooks.h"

#if (PROJECT_USE_FREERTOS != 0)

#include "FreeRTOS.h"
#include "task.h"
#include "bsp_led.h"
#include "bsp_clock.h"

/**
  * @brief  FreeRTOS 内存分配失败回调。
  * @param  无
  * @retval 无
  */
void vApplicationMallocFailedHook(void)
{
    taskDISABLE_INTERRUPTS();

    while (1)
    {
        BSP_LED_On(BSP_LED_0);
        BSP_LED_On(BSP_LED_1);
        BSP_DelayMs(100U);

        BSP_LED_Off(BSP_LED_0);
        BSP_LED_Off(BSP_LED_1);
        BSP_DelayMs(100U);
    }
}

/**
  * @brief  FreeRTOS 任务栈溢出回调。
  * @param  taskHandle 任务句柄。
  * @param  taskName 任务名称。
  * @retval 无
  */
void vApplicationStackOverflowHook(TaskHandle_t taskHandle, char *taskName)
{
    (void)taskHandle;
    (void)taskName;

    taskDISABLE_INTERRUPTS();

    while (1)
    {
        BSP_LED_On(BSP_LED_0);
        BSP_LED_Off(BSP_LED_1);
        BSP_DelayMs(100U);

        BSP_LED_Off(BSP_LED_0);
        BSP_LED_On(BSP_LED_1);
        BSP_DelayMs(100U);
    }
}

#endif
