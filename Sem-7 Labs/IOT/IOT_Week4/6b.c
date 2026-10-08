#include <8051.h>

volatile unsigned char key_data = 0;

/* External Interrupt 0 Service Routine (Interrupt Vector 0 for INT0) */
void external0_ISR(void) __interrupt(0) {
    key_data = P1;   /* Read keyboard input byte from Port 1 upon interrupt trigger */
    P2 = key_data;   /* Display key value on Port 2 */
}

void main(void) {
    P1 = 0xFF;  /* Set Port 1 as Input (Keyboard interface) */
    
    EX0 = 1;    /* Enable External Interrupt 0 (INT0) */
    IT0 = 1;    /* Set INT0 trigger mode to Falling-Edge Triggered */
    EA = 1;     /* Enable Global Interrupts */

    while (1) {
        /* Main loop */
    }
}