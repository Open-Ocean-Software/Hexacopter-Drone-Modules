
#include "Controller.h"
#include <avr/interrupt.h>

int main (void)
{
    while (1) {
        InitializeStopwatch();
        Activity();
        Standby();
        ResetStopwatch();
    }
    return 0;
}

ISR(TIMER0_OVF_vect)
{
    StopwatchHandler();
}
