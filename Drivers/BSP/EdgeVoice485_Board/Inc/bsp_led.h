#ifndef EDGEVOICE485_BSP_LED_H
#define EDGEVOICE485_BSP_LED_H

#include <stdint.h>

typedef enum
{
    BSP_LED_0 = 0,
    BSP_LED_1 = 1
} bsp_led_id_t;

/**
  * @brief  初始化 LED GPIO。
  */
void BSP_LED_Init(void);

/**
  * @brief  点亮 LED。
  */
void BSP_LED_On(bsp_led_id_t led);

/**
  * @brief  熄灭 LED。
  */
void BSP_LED_Off(bsp_led_id_t led);

/**
  * @brief  翻转 LED。
  */
void BSP_LED_Toggle(bsp_led_id_t led);

/**
  * @brief  熄灭全部 LED。
  */
void BSP_LED_AllOff(void);

#endif
