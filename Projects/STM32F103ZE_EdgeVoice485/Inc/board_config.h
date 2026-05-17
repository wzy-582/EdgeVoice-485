#ifndef EDGEVOICE485_BOARD_CONFIG_H
#define EDGEVOICE485_BOARD_CONFIG_H

#include "stm32f10x.h"

#define BOARD_LED0_GPIO_PORT                 GPIOB
#define BOARD_LED0_GPIO_CLK                  RCC_APB2Periph_GPIOB
#define BOARD_LED0_GPIO_PIN                  GPIO_Pin_5

#define BOARD_LED1_GPIO_PORT                 GPIOE
#define BOARD_LED1_GPIO_CLK                  RCC_APB2Periph_GPIOE
#define BOARD_LED1_GPIO_PIN                  GPIO_Pin_5

#define BOARD_LED_ACTIVE_LOW                 1

#endif
