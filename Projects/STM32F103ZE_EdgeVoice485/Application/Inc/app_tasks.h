#ifndef EDGEVOICE485_APP_TASKS_H
#define EDGEVOICE485_APP_TASKS_H

typedef enum
{
    APP_TASKS_OK    = 0,
    APP_TASKS_ERROR = -1
} app_tasks_status_t;

/**
  * @brief  初始化任务模块。
  */
void APP_Tasks_Init(void);

/**
  * @brief  创建系统任务。
  */
app_tasks_status_t APP_Tasks_Create(void);

#endif
