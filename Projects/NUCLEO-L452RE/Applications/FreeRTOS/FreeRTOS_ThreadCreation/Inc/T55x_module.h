/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __T55X_MODULE_H
#define __T55X_MODULE_H

#ifdef __cplusplus
extern "C" {
#endif



  
  
#include "stdint.h"  
  
#include "board_init.h" 
#include "stm32l4xx_hal.h"
#include "stm32l4xx_nucleo.h"
#include "stm32l4xx_hal_gpio.h"
#include "stm32l4xx_hal_uart.h"

  
  
#include "lcddriver_ist3088.h"
#include "ButtonTask.h"
#include "Display_task.h"
#include "System_ctrl.h"





#ifdef __cplusplus
}
#endif

#endif /* __STM32L4XX_NUCLEO_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/