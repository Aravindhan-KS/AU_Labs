/*
Q : Add two bytes, store the sum in a register, view SFRs

P1 and P2 are input
P0 is output addition value
P3 bit 0 shows carry if present 
To view SFR, C and AC in PSW are green color (showing it is being accessed)
*/

#include <8051.h>

void main(void) {
    unsigned int s;
    unsigned char lo, carry;

    P1 = 0xFF;
    P2 = 0x03;

    while (1) {
        s = (unsigned int)P1 + P2;
        lo = (unsigned char)(s & 0xFF);
        carry = (s > 0xFF) ? 1 : 0;

        P0 = lo;
        P3 = carry;
    }
}