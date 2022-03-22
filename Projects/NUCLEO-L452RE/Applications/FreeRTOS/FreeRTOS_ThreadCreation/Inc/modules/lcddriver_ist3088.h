/****************************************************************************
* Copyright: Testo AG, 79849 Lenzkirch, Postfach 1140
*****************************************************************************/
/**@file
@author someone
@brief <b>Description: </b> This module provides an interface to show measurement value
and system message

further information see display.c

set the module group for doxygen generation
\ingroup module_embedded_templates
*****************************************************************************/

#ifndef __lcddriver_ist3088__
# define __lcddriver_ist3088__

/****************************************************************************
*  INCLUDES
*****************************************************************************/
#include <stdbool.h>

/* module generated config file must be incuded first!
   This include will define all cmake options and include
   <stdbool.h> to define the type bool (values true/false)
   <stdint.h> to define int types like uint8_t, uint32_t
   <stddef.h> to define size_t (sizeof(size_t) depends on the architecture)
   it will also define the decl. used for shared builds
   */

/* for use in C++ code C-file header must use extern C define! */
#if defined (__cplusplus)
extern "C"
{
#endif

  /****************************************************************************
  * DEFINES
  *****************************************************************************/


/* Definition for GPIO control LCD*/


#define LCD_CS_EN       GPIOB->BRR = (uint32_t)GPIO_PIN_10
#define LCD_CS_DIS      GPIOB->BSRR = (uint32_t)GPIO_PIN_10
#define LCD_RST_LOW     GPIOB->BRR = (uint32_t)GPIO_PIN_12
#define LCD_RST_HIGH    GPIOB->BSRR = (uint32_t)GPIO_PIN_12
#define LCD_A0_LOW      GPIOB->BRR = (uint32_t)GPIO_PIN_13
#define LCD_A0_HIGH     GPIOB->BSRR = (uint32_t)GPIO_PIN_13
#define LCD_RD_LOW      GPIOB->BRR = (uint32_t)GPIO_PIN_14
#define LCD_RD_HIGH     GPIOB->BSRR = (uint32_t)GPIO_PIN_14
#define LCD_WR_LOW      GPIOB->BRR = (uint32_t)GPIO_PIN_11
#define LCD_WR_HIGH     GPIOB->BSRR = (uint32_t)GPIO_PIN_11



/***************************************************************************
 * DRIVER FUNCTION DECLARATIONS
 ***************************************************************************/
/* Maybe IST3048's driver function declaration should be here? */





//void IST3048_Init(bool bClearScreenOnInit);
//void IST3048_ShowAllSegment(bool bShowAll);

//void test_LCD(char pattern);
//void LCD_Update2(void);
//void LCD_GetSnapshot(void);
//void LCD_DisplaySnapshot(void);

void LCD_DisplayInit(void);
void LCD_PowerOff(void);
void LCD_Check(uint8_t iData1,uint8_t iData2);
void LCD_WriteScreen(uint8_t *DisplayData);
void DELAY_MS(uint32_t u32Ms);
void delay_init(uint32_t SYSCLK);
uint16_t LCD_RdData(uint8_t u8Reg);
void LCD_Restart(void);




void display_picture(uint8_t index);



#if defined (__cplusplus)
}
#endif

#endif /* HEADER_GUARD */
