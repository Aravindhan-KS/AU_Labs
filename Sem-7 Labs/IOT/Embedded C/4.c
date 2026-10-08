/* Q : AND(&), OR(|), XOR(^) */


#include <8051.h>
void main(void) {
    unsigned char a, b;
    P1 = 0x00; P2 = 0x01;
    while (1) {
        a = P1; b = P2;
        P0 = a & b;
        P3 = a | b;
        B  = a ^ b;
    }
}