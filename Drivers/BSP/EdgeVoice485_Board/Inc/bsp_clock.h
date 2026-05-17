#ifndef EDGEVOICE485_BSP_CLOCK_H
#define EDGEVOICE485_BSP_CLOCK_H

#include <stdint.h>

/**
  * @brief  初始化系统时钟相关配置。
  */
void BSP_Clock_Init(void);

/**
  * @brief  毫秒级阻塞延时。
  * @param  ms 延时时间。
  */
void BSP_DelayMs(uint32_t ms);

#endif
