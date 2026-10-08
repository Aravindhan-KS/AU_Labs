#include <8051.h>

unsigned char count_ones(unsigned char byte) {
    unsigned char ones_count = 0;
    unsigned char i;
    for (i = 0; i < 8; i++) {
        if (byte & (1 << i)) {
            ones_count++;
        }
    }
    return ones_count;
}

void main(void) {
    unsigned char input_byte, total_ones;

    P1 = 0xFF;      /* Configure Port 1 as Input */
    TMOD = 0x05;    /* Timer 0 configured as 16-bit Counter (C/T = 1, Mode 1) */
    TH0 = 0;
    TL0 = 0;
    TR0 = 1;        /* Start Counter 0 */

    while (1) {
        input_byte = P1;
        total_ones = count_ones(input_byte);

        /* Load calculated 1s count into Timer 0 SFR registers */
        TL0 = total_ones; 
        
        /* Display count result stored in SFR register B/P2 */
        B = TL0;      
        P2 = B;       
    }
}