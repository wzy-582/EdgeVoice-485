#ifndef EDGEVOICE485_STM32F10X_IT_H
#define EDGEVOICE485_STM32F10X_IT_H

#include "project_config.h"

#if (PROJECT_USE_FREERTOS != 0)

void SVC_Handler(void);
void PendSV_Handler(void);
void SysTick_Handler(void);

#endif

#endif
