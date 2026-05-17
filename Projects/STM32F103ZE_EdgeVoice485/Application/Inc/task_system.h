#ifndef EDGEVOICE485_TASK_SYSTEM_H
#define EDGEVOICE485_TASK_SYSTEM_H

typedef enum
{
    TASK_SYSTEM_OK    = 0,
    TASK_SYSTEM_ERROR = -1
} task_system_status_t;

/**
  * @brief  初始化系统任务模块。
  */
void Task_System_Init(void);

/**
  * @brief  创建系统任务。
  */
task_system_status_t Task_System_Create(void);

#endif
