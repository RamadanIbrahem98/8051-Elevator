#include "lib/Timer0.h"
#include "lib/Main.h"
#include "lib/Led.h"
#include "lib/Port.h"
 
void TIMER0_Init()
{
    UC_SET_ALL_Int_STATE(1);

    TIMER0_SET_INT_STATE(1);
    TIMER0_SET_MODE(0);
    TIMER0_SELECT_CLOCK_SOURCE(0);
    TIMER0_SELECT_Event_Type(EVENT_FALLING_EDGE);
}

// void TIMER0_Update() interrupt 1
// {
//     static unsigned char count = 0;

//     TIMER0_CLEAR_FLAG();

//     // LED_Toggle(LED_0);
    
//     count++;
//     if (count % 100 == 0)
//     {
//         LED_Toggle(UP_BTN_PIN);
//         count = 0;
//     }
    
// }

void TIMER0_Start()
{
    TIMER0_SET_STATE(1);
}
