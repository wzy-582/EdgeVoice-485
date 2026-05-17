#include "bsp_clock.h"
#include "stm32f10x.h"
#include "misc.h"

/**
  * @brief  初始化系统时钟相关配置。
  * @param  无
  * @retval 无
  */
void BSP_Clock_Init(void)
{
    SystemCoreClockUpdate();
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_4);
}

/**
  * @brief  毫秒级阻塞延时。
  * @param  ms 延时时间。
  * @retval 无
  */
void BSP_DelayMs(uint32_t ms)
{
    volatile uint32_t i;
    volatile uint32_t count;

    count = (SystemCoreClock / 8000U) * ms;

    for (i = 0; i < count; i++)
    {
        __NOP();
    }
}
