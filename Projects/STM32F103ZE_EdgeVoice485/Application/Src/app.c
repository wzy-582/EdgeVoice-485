#include "app.h"
#include "project_config.h"
#include "app_tasks.h"
#include "bsp_led.h"
#include "bsp_clock.h"

#if (PROJECT_USE_FREERTOS != 0)
#include "FreeRTOS.h"
#include "task.h"
#endif

/**
  * @brief  初始化应用层。
  * @param  无
  * @retval 无
  */
void APP_Init(void)
{
    BSP_LED_AllOff();
    APP_Tasks_Init();
}

/**
  * @brief  运行应用层循环。
  * @param  无
  * @retval 无
  */
void APP_Run(void)
{
#if (PROJECT_USE_FREERTOS == 0)

    BSP_LED_Toggle(BSP_LED_0);
    BSP_LED_Toggle(BSP_LED_1);
    BSP_DelayMs(APP_BARE_METAL_HEARTBEAT_MS);

#else

    BSP_LED_On(BSP_LED_0);
    BSP_LED_On(BSP_LED_1);
    BSP_DelayMs(100U);

    BSP_LED_Off(BSP_LED_0);
    BSP_LED_Off(BSP_LED_1);
    BSP_DelayMs(100U);

#endif
}

/**
  * @brief  启动应用层。
  * @param  无
  * @retval 无
  */
void APP_Start(void)
{
#if (PROJECT_USE_FREERTOS != 0)

    if (APP_Tasks_Create() != APP_TASKS_OK)
    {
        while (1)
        {
            APP_Run();
        }
    }

    vTaskStartScheduler();

    while (1)
    {
        APP_Run();
    }

#else

    (void)APP_Tasks_Create();

#endif
}
