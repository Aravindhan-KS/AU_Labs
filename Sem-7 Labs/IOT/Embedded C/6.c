/*
Q: Timer and external interrupts
P2 and R6 shows the no of ms passed after execution [Error around -1]
Set up Pin 3  bit 2 in simple keypad to interrupt
When interrupted it should show P1 being all 0's other times it should have all 1's
*/

#include <8051.h>

volatile unsigned int ticks = 0;
__data __at (0x06) volatile unsigned char ms_count;

void timer0_isr(void) __interrupt(1) {
    TH0 = 0xFC; TL0 = 0x18;
    ms_count++;
    P2 = ms_count;
}

void ex0_isr(void) __interrupt(0) {
    P1 = ~P1;
}

void main(void) {
    TMOD = 0x01;
    TH0 = 0xFC; TL0 = 0x18;
    IT0 = 1;
    EX0 = 1; ET0 = 1; EA = 1;
    TR0 = 1;
    while (1);
}