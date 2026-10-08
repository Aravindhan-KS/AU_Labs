/*
Blink a LED - Virtual HW set LED pin 1 port 0
*/

#include <8051.h>
void delay(unsigned int ms) {
    unsigned int i, j;
    for (i = 0; i < ms; i++){
        for (j = 0; j < 120; j++){
        ;
        }
    }
}
void main(void) {
    while (1) {
        P1_0 = 0; 
        delay(100);
        P1_0 = 1; 
        delay(100);
    }
}