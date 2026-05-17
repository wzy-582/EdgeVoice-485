#include "main.h"
#include "bsp.h"
#include "app.h"

/**
  * @brief  主函数。
  * @param  无
  * @retval int
  */
int main(void)
{
    BSP_Init();
    APP_Init();
    APP_Start();

    while (1)
    {
        APP_Run();
    }
}
