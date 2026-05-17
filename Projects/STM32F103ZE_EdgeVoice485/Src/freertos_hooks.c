#include "project_config.h"

#if (PROJECT_USE_FREERTOS != 0)

#include "FreeRTOS.h"
#include "task.h"
#include "bsp_led.h"

static void Hook_Delay(void);

/**
  * @brief  内存申请失败回调
  * @param  None
  * @retval None
  */
void vApplicationMallocFailedHook(void)
{
    taskDISABLE_INTERRUPTS();

    while (1)
    {
        BSP_LED_Toggle(BSP_LED_0);
        BSP_LED_Off(BSP_LED_1);
        Hook_Delay();
    }
}

/**
  * @brief  任务栈溢出回调
  * @param  xTask      任务句柄
  * @param  pcTaskName 任务名称
  * @retval None
  */
void vApplicationStackOverflowHook(TaskHandle_t xTask, char *pcTaskName)
{
    (void)xTask;
    (void)pcTaskName;

    taskDISABLE_INTERRUPTS();

    while (1)
    {
        BSP_LED_Off(BSP_LED_0);
        BSP_LED_Toggle(BSP_LED_1);
        Hook_Delay();
    }
}

/**
  * @brief  Hook 延时
  * @param  None
  * @retval None
  */
static void Hook_Delay(void)
{
    volatile unsigned long i;

    for (i = 0; i < 800000UL; i++)
    {
    }
}

#endif
