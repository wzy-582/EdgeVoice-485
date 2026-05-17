#include "app_tasks.h"
#include "project_config.h"
#include "task_system.h"

/**
  * @brief  初始化任务模块。
  * @param  无
  * @retval 无
  */
void APP_Tasks_Init(void)
{
    Task_System_Init();
}

/**
  * @brief  创建系统任务。
  * @param  无
  * @retval 任务创建状态。
  */
app_tasks_status_t APP_Tasks_Create(void)
{
#if (PROJECT_USE_FREERTOS != 0)

    if (Task_System_Create() != TASK_SYSTEM_OK)
    {
        return APP_TASKS_ERROR;
    }

#endif

    return APP_TASKS_OK;
}
