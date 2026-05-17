#include "task_system.h"
#include "project_config.h"
#include "bsp_led.h"

#if (PROJECT_USE_FREERTOS != 0)
#include "FreeRTOS.h"
#include "task.h"

#define TASK_SYSTEM_STACK_WORDS        128U
#define TASK_SYSTEM_PRIORITY           1U

static TaskHandle_t s_systemTaskHandle = 0;

static void Task_System_Entry(void *argument);
#endif

/**
  * @brief  初始化系统任务模块。
  * @param  无
  * @retval 无
  */
void Task_System_Init(void)
{
}

/**
  * @brief  创建系统任务。
  * @param  无
  * @retval 任务创建状态。
  */
task_system_status_t Task_System_Create(void)
{
#if (PROJECT_USE_FREERTOS != 0)

    BaseType_t ret;

    ret = xTaskCreate(Task_System_Entry,
                      "system",
                      TASK_SYSTEM_STACK_WORDS,
                      0,
                      TASK_SYSTEM_PRIORITY,
                      &s_systemTaskHandle);

    if (ret != pdPASS)
    {
        return TASK_SYSTEM_ERROR;
    }

#endif

    return TASK_SYSTEM_OK;
}

#if (PROJECT_USE_FREERTOS != 0)

/**
  * @brief  系统任务入口。
  * @param  argument 任务参数。
  * @retval 无
  */
static void Task_System_Entry(void *argument)
{
    (void)argument;

    BSP_LED_Off(BSP_LED_1);

    while (1)
    {
        BSP_LED_Toggle(BSP_LED_0);
        vTaskDelay(pdMS_TO_TICKS(APP_SYSTEM_TASK_PERIOD_MS));
    }
}

#endif
