#include <8051.h>

volatile unsigned char time_elapsed_register = 0;

/* Timer 0 Interrupt Service Routine (Interrupt Vector 1 for Timer 0) */
void timer0_ISR(void) __interrupt(1) {
    /* Reload 16-bit timer values for desired delay */
    TH0 = 0xFC; 
    TL0 = 0x18; 
    
    time_elapsed_register++;    /* Increment register tracking elapsed time unit */
    P2 = time_elapsed_register; /* Display count on Port 2 */
}

void main(void) {
    TMOD = 0x01;  /* Timer 0, Mode 1 (16-bit Timer) */
    TH0 = 0xFC;   /* Load Initial values */
    TL0 = 0x18;
    
    ET0 = 1;      /* Enable Timer 0 Interrupt */
    EA = 1;       /* Enable Global Interrupts */
    TR0 = 1;      /* Start Timer 0 */

    while (1) {
        /* Main task loop */
    }
}