/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __T55X_MODULE_H
#define __T55X_MODULE_H

#ifdef __cplusplus
extern "C" {
#endif

typedef enum
{
    BRIGHTNESS_25_PERCENT = 0,
    BRIGHTNESS_50_PERCENT,
    BRIGHTNESS_75_PERCENT,
    BRIGHTNESS_100_PERCENT,
    BRIGHTNESS_0_PERCENT,
} Brightness_t; 

//
  
  
#include "stdint.h"  
  
#include "board_init.h" 
#include "stm32l4xx_hal.h"
#include "stm32l4xx_nucleo.h"
#include "stm32l4xx_hal_gpio.h"
#include "stm32l4xx_hal_uart.h"
#include "stm32l4xx_hal_tim.h"
  
  
#include "lcddriver_ist3088.h"
#include "ButtonTask.h"
#include "Display_task.h"
#include "System_ctrl.h"





typedef struct
{
  Brightness_t value;        /*!< Specifies the GPIO pins to be configured.
                           This parameter can be any value of @ref GPIO_pins */
  uint8_t iflag;       /*!< Specifies the operating mode for the selected pins.*/

} Brightness_s;

extern Brightness_s bright_status;  



#ifdef __cplusplus
}
#endif

#endif /* __STM32L4XX_NUCLEO_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/