
#include "cmsis_os.h"
#include "T55x_module.h"


osThreadId Sysctrl_Handle = NULL;

Brightness_s bright_status =
             {BRIGHTNESS_25_PERCENT,0};


void Sysctrl_Thread(void const *argument)
{
 uint32_t count;
  (void) argument;

  for (;;)
  {
//   count = osKernelSysTick() + 200;

    /* Turn on LED2 */
//    BSP_LED_On(LED2);

//   while (count > osKernelSysTick())
    {
      /* Toggle LED2 every 500ms*/
     osDelay(10);
      if(bright_status.iflag)
      {     
        Board_setBrightness(bright_status.value);
        bright_status.iflag = 0;
        
      }
//      BSP_LED_Toggle(LED2);
//      display_picture(0);
    }

    /* Turn off LED2 */
 //   BSP_LED_Off(LED2);

    /* Resume Thread 1 */
//    osThreadResume(UIctrl_Handle);
    /* Suspend Thread2 : current thread */
//    osThreadSuspend(Sysctrl_Handle); 
  }
}