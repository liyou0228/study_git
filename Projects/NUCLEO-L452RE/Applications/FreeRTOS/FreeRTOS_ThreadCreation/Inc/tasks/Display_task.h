/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __DISPLAY_TASK_H
#define __DISPLAY_TASK_H

#ifdef __cplusplus
extern "C" {
#endif

#include "cmsis_os.h"

 
  
extern uint8_t displayIndex;  
extern osThreadId UIctrl_Handle;  


void UIctrl_Thread(void const *argument);





#ifdef __cplusplus
}
#endif

#endif /* __STM32L4XX_NUCLEO_H */