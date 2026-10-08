/*
Q: Timer-based delay (LED toggle)

Set Pin 1 Bit 0 in LED Panel

It may takes some set up code (around 800µs) then every 1ms led is toggled
*/
#include <8051.h>
void delay_ms(unsigned int ms) {
    while (ms--) {
        TMOD = 0x01;
        TH0 = 0xFC; TL0 = 0x18;
        TR0 = 1;
        while (!TF0);
        TR0 = 0; TF0 = 0;
    }
}
void main(void) {
    P1_0 = 0;
    while (1) {
        P1_0 = 0;
        delay_ms(1);
        P1_0 = 1;
        delay_ms(1);
    }
}