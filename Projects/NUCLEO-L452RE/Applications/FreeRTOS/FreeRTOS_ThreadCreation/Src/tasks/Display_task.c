

#include "T55x_module.h"
#include "cmsis_os.h"


osThreadId UIctrl_Handle = NULL;




void UIctrl_Thread(void const *argument)
{
  uint32_t count = 0;
  (void) argument;
  
  LCD_DisplayInit();
  
  if(LCD_RdData(0x03) != 0x70)    // add read register for ESD test
  {    //restart LCD display
    LCD_PowerOff();
    DELAY_MS(500);
    LCD_DisplayInit();
//    sprintf(string,"LCD_Display inito falied!\r\n");
    DPrint_Out("LCD_Display inito falied!\r\n");
  }
  
  for (;;)
  {
    count = osKernelSysTick() + 10000;

    /* Turn on LED2 */
    BSP_LED_On(LED2);

    while (count > osKernelSysTick())
    {
      /* Toggle LED2 every 250ms*/
      osDelay(50);
//      BSP_LED_Toggle(LED2);
       display_picture(KeyValue);
    }

    /* Turn off LED2 */
//    BSP_LED_Off(LED2);
    DPrint_Out("KeyValue = %d!\r\n",&KeyValue);
    /* Resume Thread 2 */
    osThreadResume(Sysctrl_Handle);
    /* Suspend Thread 1 : current thread */
    osThreadSuspend(UIctrl_Handle);
    
  }

}