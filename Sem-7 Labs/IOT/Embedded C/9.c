/*
Switch (P3.0) toggles LED (P1.0) on each press
*/
#include <8051.h>

void main(void) {
    P3 = 0xFF;
    while (1) {
        P1 = P3;
    }
}