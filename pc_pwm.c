#include <xc.h>

#include "pc_pwm.h"

void PWM_init()
{
    PWMEN0 = 0;             // PWM0 and PWM1 enabled
    PWMEN1 = 1;
    PWMEN2 = 0;
    
    PMOD0 = 1;              // PWM0 & PWM1 in independent mode
    
    // PWM setup
    PTCKPS0 = 1;            // time base 1:64 prescale
    PTCKPS1 = 1;
    
    //PTPER = 155;          // PWM period of 10ms
    PTPERL = 0b10011010;
    PTPERH = 0b00000000;
    
    PDC0L = 0b01011111;     // neutral throttle +1.5 -8.5
    
    PTEN = 1;
}
