#include "lib/Main.h"
#include "lib/Port.h"
// #include "lib/Common.h"

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

    while (1)
    {
        /* code */
    }
}