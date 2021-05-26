#include "lib/Main.h"
#include "lib/Port.h"
#include "lib/Timer0.h"
#include "lib/Led.h"
// #include "lib/Common.h"

void TIMER0_Update() interrupt 1
{
    static unsigned char count = 0;

    TIMER0_CLEAR_FLAG();
    
    count++;
    if (count % 20 == 0)
    {
        LED_Toggle(ALARM_LED_PIN);
        count = 0;
    }
    
}

void main()
{
    // diable the watch dog
    WDTCN = 0x0DE;
    WDTCN = 0x0AD;

    OSCICN = 0x014; // 2MH clock

    // config cross bar
    XBR0 = 0x00;
    XBR1 = 0x00;
    XBR2 = 0x040; // Cross bar enabled , weak Pull-up enabled

    LED_Init(TOO_MANY_PEOPLE, LED_ON);
    TIMER0_Init();
    TIMER0_Start();

    while (1)
    {
        /* code */
    }
}