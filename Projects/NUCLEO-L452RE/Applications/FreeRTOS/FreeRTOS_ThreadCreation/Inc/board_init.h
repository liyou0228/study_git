

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __BOARD_INIT_H
#define __BOARD_INIT_H




#ifdef __cplusplus
extern "C" {
#endif

#include "T55x_module.h"
  
  
  
  

  
  
  
#define LCD_PO_ON()    GPIOC->BRR = (uint32_t)GPIO_PIN_10
#define LCD_PO_OFF()   GPIOC->BSRR = (uint32_t)GPIO_PIN_10  
  
#define BT_PO_ON()    GPIOC->BRR = (uint32_t)GPIO_PIN_11
#define BT_PO_OFF()   GPIOC->BSRR = (uint32_t)GPIO_PIN_11  
 
#define Meas_Dis()  GPIOC->BRR = (uint32_t)GPIO_PIN_12
#define Meas_EN()   GPIOC->BSRR = (uint32_t)GPIO_PIN_12  
  
#define FLASH_PO_OFF()  GPIOD->BRR = (uint32_t)GPIO_PIN_0
#define FLASH_PO_ON()   GPIOD->BSRR = (uint32_t)GPIO_PIN_0  
  
#define BAT_Mea_Dis()  GPIOD->BRR = (uint32_t)GPIO_PIN_14
#define BAT_Mea_EN()   GPIOD->BSRR = (uint32_t)GPIO_PIN_14






//void Board_GpioInit(void);
//void Debug_printInit(void);
void Board_initUSB(void);
void Board_Init(void);
void DPrint_Out(const char* szText,...);







  
  
  
  
  
  
  
  
  
  
  




#ifdef __cplusplus
}
#endif

#endif /* __STM32L4XX_NUCLEO_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/