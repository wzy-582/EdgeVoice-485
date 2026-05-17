#include "stm32f10x_it.h"
#include "bsp_led.h"

static void Fault_Delay(void);

/**
  * @brief  HardFault 中断处理
  * @param  None
  * @retval None
  */
void HardFault_Handler(void)
{
    while (1)
    {
        BSP_LED_On(BSP_LED_0);
        BSP_LED_On(BSP_LED_1);
        Fault_Delay();

        BSP_LED_Off(BSP_LED_0);
        BSP_LED_Off(BSP_LED_1);
        Fault_Delay();
    }
}

/**
  * @brief  故障指示延时
  * @param  None
  * @retval None
  */
static void Fault_Delay(void)
{
    volatile unsigned long i;

    for (i = 0; i < 800000UL; i++)
    {
    }
}
