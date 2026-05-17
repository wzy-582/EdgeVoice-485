#include "bsp.h"

/**
  * @brief  初始化板级资源。
  * @param  无
  * @retval 无
  */
void BSP_Init(void)
{
    BSP_Clock_Init();
    BSP_LED_Init();
}
