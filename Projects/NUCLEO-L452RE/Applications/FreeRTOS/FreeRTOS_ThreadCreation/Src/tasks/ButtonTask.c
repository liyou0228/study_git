


/****************************************************************************
 *  INCLUDES
 *****************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <stdbool.h>

#include "ButtonTask.h"
#include "T55x_module.h"

ButtonType KeyValue = NOT_BUTTON;


void Keyboard_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOE_CLK_ENABLE();
  
  GPIO_InitStruct.Pin    = GPIO_PIN_8;
  GPIO_InitStruct.Mode   = GPIO_MODE_IT_FALLING;
  GPIO_InitStruct.Pull   = GPIO_NOPULL;
  GPIO_InitStruct.Speed  = GPIO_SPEED_FREQ_HIGH;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
  
  GPIO_InitStruct.Pin    = GPIO_PIN_9; 
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);  
  
  GPIO_InitStruct.Pin    = (GPIO_PIN_5|GPIO_PIN_6); 
  HAL_GPIO_Init(GPIOE, &GPIO_InitStruct);
  
  GPIO_InitStruct.Pin    = GPIO_PIN_2;
  GPIO_InitStruct.Mode   = GPIO_MODE_IT_RISING_FALLING;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);  
  
  HAL_NVIC_SetPriority(EXTI9_5_IRQn, 5, 0); // will not masked by RTOS
  HAL_NVIC_EnableIRQ(EXTI9_5_IRQn);

  HAL_NVIC_SetPriority(EXTI2_IRQn, 5, 0); // will not masked by RTOS
  HAL_NVIC_EnableIRQ(EXTI2_IRQn);  
    
}




void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
  if((GPIO_Pin == GPIO_PIN_6))
  {
     KeyValue = BUTTON_POWER;
  //    setButtonIdEvent(BUTTON_POWER);
  //    HAL_TIM_Base_Start_IT(&TimHandle3);
  }
  else if((GPIO_Pin == GPIO_PIN_9))
  {
    KeyValue = BUTTON_MENU;
  //    setButtonIdEvent(BUTTON_MENU);
  //    HAL_TIM_Base_Start_IT(&TimHandle3);
  }
  else if((GPIO_Pin == GPIO_PIN_5))
  {
    KeyValue = BUTTON_UP;
  //    setButtonIdEvent(BUTTON_UP);
  //    HAL_TIM_Base_Start_IT(&TimHandle3);
  }
  else if((GPIO_Pin == GPIO_PIN_8))
  {
    KeyValue = BUTTON_DOWN;
  //    setButtonIdEvent(BUTTON_DOWN);
  //    HAL_TIM_Base_Start_IT(&TimHandle3);
  }
  else if((GPIO_Pin == GPIO_PIN_2))
  {
    KeyValue = BUTTON_USB;
  //    setButtonIdEvent(BUTTON_USB);
  //    HAL_TIM_Base_Start_IT(&TimHandle3);
  }

}