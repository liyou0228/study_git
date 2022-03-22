


/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __SYSTEM_CTRL_H
#define __SYSTEM_CTRL_H



#ifdef __cplusplus
extern "C" {
#endif

  
  
#include "cmsis_os.h"
  
  
  
  

  
  
  





extern osThreadId Sysctrl_Handle;

void Sysctrl_Thread(void const *argument);
  
  
  
  
  
  
  
  
  
  
  




#ifdef __cplusplus
}
#endif

#endif /* __STM32L4XX_NUCLEO_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/