/**
  ******************************************************************************
  * @file    FreeRTOS/FreeRTOS_ThreadCreation/Src/board_init.c
  * @author  MCD Application Team
  * @brief   Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2017 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under Ultimate Liberty license SLA0044,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        http://www.st.com/SLA0044
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include <string.h>

#include "T55x_module.h"
#include "stm32l4xx_hal_tim.h"
    
//#include "stm32l4xx_hal_uart.h"

/* Private variables ---------------------------------------------------------*/
/* UART handler declaration */

UART_HandleTypeDef UartHandleDebug;

uint8_t TxBuff[10]={0,1,2,3,4,5,6,7,8,9};


#define  BRIGHTNESS_PERIOD        (uint32_t)(100)             /* Period Value  */
#define  BRIGHTNESS_DUTY_25       (uint32_t)(BRIGHTNESS_PERIOD/4)        /* 25%  */
#define  BRIGHTNESS_DUTY_50       (uint32_t)(BRIGHTNESS_PERIOD/2)        /* 50%  */
#define  BRIGHTNESS_DUTY_75       (uint32_t)(BRIGHTNESS_PERIOD*3/4)   /* 75%  */
#define  BRIGHTNESS_DUTY_100      BRIGHTNESS_PERIOD                      /* 100%  */
/****************************************************************************
 *  TYPE DECLARATIONS
 *****************************************************************************/
TIM_HandleTypeDef     TimHandle1;
TIM_OC_InitTypeDef    TimOCConfig;

/* Private functions ---------------------------------------------------------*/

/**
  * @brief  Main program
  * @param  None
  * @retval None
  */
void Board_GpioInit(void);
void Debug_printInit(void);
void Board_BrightnessInit(void);

void Board_Init(void)
{
  
  Board_GpioInit();
  Keyboard_Init();
  
  Debug_printInit();
  DPrint_Out("Debug print Inito sucessful!\r\n");

  Board_BrightnessInit();
  
}

void DPrint_Out(const char* szText,...)
{
  HAL_UART_Transmit(&UartHandleDebug,(unsigned char*)szText,strlen(szText),1000);
}


void Board_GpioInit(void)
{
  GPIO_InitTypeDef GPIO_InitStruct;
    
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOD_CLK_ENABLE(); 
    
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_MEDIUM;
  GPIO_InitStruct.Pull = GPIO_NOPULL; 
  GPIO_InitStruct.Pin = (GPIO_PIN_10|GPIO_PIN_11|GPIO_PIN_12);
  
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);   //PB12 for sub-1g power control    
  
  GPIOC->BSRR = (uint32_t)(GPIO_PIN_10|GPIO_PIN_11); // 
  GPIOC->BRR = (uint32_t)GPIO_PIN_12;                //low
  
  GPIO_InitStruct.Pin = (GPIO_PIN_0|GPIO_PIN_14);
  HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);   //PB12 for sub-1g power control  
  
  GPIOC->BRR = (uint32_t)(GPIO_PIN_0|GPIO_PIN_14); // 
  
}

/**
  * @brief  data print out with uart program
  * @param  None
  * @retval None
  */ 


void Debug_printInit(void)
{
  GPIO_InitTypeDef  GPIO_InitStruct;
  GPIO_TypeDef*  pPort;
  uint32_t u32PinTx, u32PinRx, u32AlternateFunction;  
  
  __HAL_RCC_USART2_CLK_ENABLE(); /* Enable USARTx clock */

      /* TUC1_TX = PA9 */
      /* TUC1_RX = PA10 */
   __HAL_RCC_GPIOD_CLK_ENABLE(); /* Enable GPIO TX/RX clock */    
   
  pPort = GPIOD;
  u32PinTx = GPIO_PIN_5;
  u32PinRx = GPIO_PIN_6;
  u32AlternateFunction = GPIO_AF7_USART2;
  /* UART TX GPIO pin configuration  */
  GPIO_InitStruct.Pin       = u32PinTx;
  GPIO_InitStruct.Mode      = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Pull      = GPIO_PULLUP;
  GPIO_InitStruct.Speed     = GPIO_SPEED_FREQ_HIGH;
  GPIO_InitStruct.Alternate = u32AlternateFunction;
  HAL_GPIO_Init(pPort, &GPIO_InitStruct);

  /* UART RX GPIO pin configuration  */
  GPIO_InitStruct.Pin = u32PinRx;
  GPIO_InitStruct.Alternate = u32AlternateFunction;
  HAL_GPIO_Init(pPort, &GPIO_InitStruct);    
  
  
  UartHandleDebug.Instance        = USART2;
  UartHandleDebug.Init.BaudRate     = 115200; //512000;//115200;
  UartHandleDebug.Init.WordLength   = UART_WORDLENGTH_8B;
  UartHandleDebug.Init.StopBits     = UART_STOPBITS_1;
  UartHandleDebug.Init.Parity       = UART_PARITY_NONE;
  UartHandleDebug.Init.HwFlowCtl    = UART_HWCONTROL_NONE;
  UartHandleDebug.Init.Mode         = UART_MODE_TX_RX;

  if(HAL_UART_DeInit(&UartHandleDebug) != HAL_OK)
  {
    //Error_Handler();
  }
  if(HAL_UART_Init(&UartHandleDebug) != HAL_OK)
  {
    //Error_Handler();
  }  

}

/**
  * @brief  backlight program
  * @param  None
  * @retval None
  */ 

void Board_BrightnessInit(void)
{
    //#ifdef STM32L452XX
    GPIO_InitTypeDef GPIO_InitStruct ={0};
    
    __HAL_RCC_GPIOB_CLK_ENABLE();
    
    GPIO_InitStruct.Pin = GPIO_PIN_15;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_PULLUP;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF1_TIM1;
    HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);
    
    __HAL_RCC_TIM1_CLK_ENABLE();
    
    /* Prescaler declaration */
    uint32_t uwPrescalerValue = 0;
    uwPrescalerValue = (uint32_t) (80000 * 1000 / 1000000) - 1;
    TimHandle1.Instance = TIM1;
    TimHandle1.Init.Prescaler = uwPrescalerValue;
    TimHandle1.Init.Period = BRIGHTNESS_PERIOD;
    TimHandle1.Init.ClockDivision = 0;
    TimHandle1.Init.CounterMode = TIM_COUNTERMODE_UP;
    TimHandle1.Init.RepetitionCounter = 0;
    HAL_TIM_PWM_Init(&TimHandle1);
    
    TimOCConfig.OCMode = TIM_OCMODE_PWM1;
    TimOCConfig.OCPolarity = TIM_OCPOLARITY_HIGH;
    TimOCConfig.OCFastMode = TIM_OCFAST_DISABLE;
    TimOCConfig.OCNPolarity = TIM_OCNPOLARITY_HIGH;
    TimOCConfig.OCNIdleState = TIM_OCNIDLESTATE_RESET;
    TimOCConfig.OCIdleState = TIM_OCIDLESTATE_RESET;
    TimOCConfig.Pulse = BRIGHTNESS_DUTY_25;
    
    HAL_TIM_PWM_ConfigChannel(&TimHandle1, &TimOCConfig, TIM_CHANNEL_3);
    
    HAL_TIMEx_PWMN_Start(&TimHandle1, TIM_CHANNEL_3);
    
//    uint8_t i;
//    for(i = 0;i<4;i++)
//    {
//        Board_setBrightness(i);
//    }
    
}

void Board_setBrightness(Brightness_t brightness)
{
    uint32_t BrightnessDuty;
    
     uint32_t uwPrescalerValue = 0;
    uwPrescalerValue = (uint32_t) (80000 * 1000 / 1000000) - 1;
    TimHandle1.Instance = TIM1;
    TimHandle1.Init.Prescaler = uwPrescalerValue;
    TimHandle1.Init.Period = BRIGHTNESS_PERIOD;
    TimHandle1.Init.ClockDivision = 0;
    TimHandle1.Init.CounterMode = TIM_COUNTERMODE_UP;
    TimHandle1.Init.RepetitionCounter = 0;
    HAL_TIM_PWM_Init(&TimHandle1);   
    
    
    if (brightness == BRIGHTNESS_25_PERCENT)
      {
        BrightnessDuty = BRIGHTNESS_DUTY_25;
      }
    else if (brightness == BRIGHTNESS_50_PERCENT)
      {
        BrightnessDuty = BRIGHTNESS_DUTY_50;
      }
    else if (brightness == BRIGHTNESS_75_PERCENT)
      {
        BrightnessDuty = BRIGHTNESS_DUTY_75;
      }
    else
      {
        BrightnessDuty = BRIGHTNESS_DUTY_100;
      }

    TimOCConfig.OCMode = TIM_OCMODE_PWM1;
    TimOCConfig.OCPolarity = TIM_OCPOLARITY_HIGH;
    TimOCConfig.OCFastMode = TIM_OCFAST_DISABLE;
    TimOCConfig.OCNPolarity = TIM_OCNPOLARITY_HIGH;
    TimOCConfig.OCNIdleState = TIM_OCNIDLESTATE_RESET;
    TimOCConfig.OCIdleState = TIM_OCIDLESTATE_RESET;
    TimOCConfig.Pulse = BrightnessDuty;
    HAL_TIM_PWM_ConfigChannel(&TimHandle1, &TimOCConfig, TIM_CHANNEL_3);
    HAL_TIMEx_PWMN_Start(&TimHandle1, TIM_CHANNEL_3);
}

/**
  * @brief  USB program
  * @param  None
  * @retval None
  */ 

void Board_initUSB(void)
{
  GPIO_InitTypeDef GPIO_InitStruct;
  /**USB GPIO Configuration
  PA11     ------> USB_DM
  PA12     ------> USB_DP
  */
  GPIO_InitStruct.Pin = GPIO_PIN_11|GPIO_PIN_12;
  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
  GPIO_InitStruct.Alternate = GPIO_AF10_USB_FS;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /* Peripheral clock enable */
  __HAL_RCC_USB_CLK_ENABLE();

  /* Peripheral interrupt init */
  HAL_NVIC_SetPriority(USB_IRQn, 5, 0);
  HAL_NVIC_EnableIRQ(USB_IRQn);
}






