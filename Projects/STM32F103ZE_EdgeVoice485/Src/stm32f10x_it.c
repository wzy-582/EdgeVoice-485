#include "project_config.h"

#if (PROJECT_USE_FREERTOS != 0)

#include "FreeRTOS.h"
#include "task.h"

extern void vPortSVCHandler(void);
extern void xPortPendSVHandler(void);
extern void xPortSysTickHandler(void);

/**
  * @brief  SVC 异常处理函数。
  * @param  无
  * @retval 无
  */
void SVC_Handler(void)
{
    vPortSVCHandler();
}

/**
  * @brief  PendSV 异常处理函数。
  * @param  无
  * @retval 无
  */
void PendSV_Handler(void)
{
    xPortPendSVHandler();
}

/**
  * @brief  SysTick 中断处理函数。
  * @param  无
  * @retval 无
  */
void SysTick_Handler(void)
{
    xPortSysTickHandler();
}

#endif
