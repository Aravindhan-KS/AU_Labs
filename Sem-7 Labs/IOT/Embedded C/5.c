/* Q: Count the 1s in a byte
   P2 displays the number of one from the input(P1)
*/
#include <8051.h>

void main(void) {
    unsigned char val, count = 0, i;
    P1 = 0xFF;
    val = P1;
    for (i = 0; i < 8; i++) {
        if (val & 0x01)
            count++;
        val >>= 1;
    }
    P2 = count;
    while (1);
}

/*
Q: Count the 1s in a byte using Timer0 as a counter (C/T = 1)

#include <8051.h>
void main(void) {
    unsigned char val, i;
    P1 = 0xFF;
    val = P1;
    TMOD = 0x05;            // Timer0, mode 1, C/T = 1 (counter)
    TH0 = 0; TL0 = 0;
    TR0 = 1;
    P3_4 = 1;               // T0 pin idle high
    for (i = 0; i < 8; i++) {
        if (val & 0x01) {   // for each '1' bit, make a falling edge on T0
            P3_4 = 1;
            __asm nop __endasm;
            P3_4 = 0;       // falling edge, so the counter increments
            __asm nop __endasm;
        }
        val >>= 1;
    }
    TR0 = 0;
    P2 = TL0;               // number of 1s
    while (1);
}
*/