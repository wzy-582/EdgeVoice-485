#include "bsp_led.h"
#include "board_config.h"
#include "stm32f10x_gpio.h"
#include "stm32f10x_rcc.h"

/**
  * @brief  获取 LED 对应的 GPIO 端口和引脚。
  * @param  led LED 编号。
  * @param  port GPIO 端口指针。
  * @param  pin GPIO 引脚指针。
  * @retval 无
  */
static void BSP_LED_GetPortPin(bsp_led_id_t led, GPIO_TypeDef **port, uint16_t *pin)
{
    if (led == BSP_LED_0)
    {
        *port = BOARD_LED0_GPIO_PORT;
        *pin  = BOARD_LED0_GPIO_PIN;
    }
    else
    {
        *port = BOARD_LED1_GPIO_PORT;
        *pin  = BOARD_LED1_GPIO_PIN;
    }
}

/**
  * @brief  设置 LED 输出状态。
  * @param  led LED 编号。
  * @param  on 点亮状态。
  * @retval 无
  */
static void BSP_LED_Write(bsp_led_id_t led, uint8_t on)
{
    GPIO_TypeDef *port;
    uint16_t pin;

    BSP_LED_GetPortPin(led, &port, &pin);

#if BOARD_LED_ACTIVE_LOW
    if (on)
    {
        GPIO_ResetBits(port, pin);
    }
    else
    {
        GPIO_SetBits(port, pin);
    }
#else
    if (on)
    {
        GPIO_SetBits(port, pin);
    }
    else
    {
        GPIO_ResetBits(port, pin);
    }
#endif
}

/**
  * @brief  初始化 LED GPIO。
  * @param  无
  * @retval 无
  */
void BSP_LED_Init(void)
{
    GPIO_InitTypeDef gpio;

    RCC_APB2PeriphClockCmd(BOARD_LED0_GPIO_CLK | BOARD_LED1_GPIO_CLK, ENABLE);

    gpio.GPIO_Speed = GPIO_Speed_50MHz;
    gpio.GPIO_Mode  = GPIO_Mode_Out_PP;

    gpio.GPIO_Pin = BOARD_LED0_GPIO_PIN;
    GPIO_Init(BOARD_LED0_GPIO_PORT, &gpio);

    gpio.GPIO_Pin = BOARD_LED1_GPIO_PIN;
    GPIO_Init(BOARD_LED1_GPIO_PORT, &gpio);

    BSP_LED_AllOff();
}

/**
  * @brief  点亮 LED。
  * @param  led LED 编号。
  * @retval 无
  */
void BSP_LED_On(bsp_led_id_t led)
{
    BSP_LED_Write(led, 1U);
}

/**
  * @brief  熄灭 LED。
  * @param  led LED 编号。
  * @retval 无
  */
void BSP_LED_Off(bsp_led_id_t led)
{
    BSP_LED_Write(led, 0U);
}

/**
  * @brief  翻转 LED。
  * @param  led LED 编号。
  * @retval 无
  */
void BSP_LED_Toggle(bsp_led_id_t led)
{
    GPIO_TypeDef *port;
    uint16_t pin;

    BSP_LED_GetPortPin(led, &port, &pin);

    if (GPIO_ReadOutputDataBit(port, pin) == Bit_SET)
    {
        GPIO_ResetBits(port, pin);
    }
    else
    {
        GPIO_SetBits(port, pin);
    }
}

/**
  * @brief  熄灭全部 LED。
  * @param  无
  * @retval 无
  */
void BSP_LED_AllOff(void)
{
    BSP_LED_Off(BSP_LED_0);
    BSP_LED_Off(BSP_LED_1);
}
