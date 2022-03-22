

#ifndef __BUTTONTASK_H__
#define __BUTTONTASK_H__


#include <stdint.h>

typedef enum
{
    BUTTON_NOT_PRESSED = 0,
    BUTTON_PRESS_SHORT = 1,
    BUTTON_PRESS_LONG = 2,
    BUTTON_PRESS_ABIT_LONG = 3,
} ButtonState;

typedef enum
{
    NOT_BUTTON = 0,
    BUTTON_MENU = 0x1,
    BUTTON_UP = 0x2,
    BUTTON_DOWN = 0x4,
    BUTTON_POWER = 0x8,
    BUTTON_USB = 0x10,
} ButtonType;











extern  ButtonType KeyValue;

void Keyboard_Init(void);

























#endif /* __BUTTONTASK_H__ */