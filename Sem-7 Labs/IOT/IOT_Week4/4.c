#include <8051.h>

void main(void) {
    unsigned char in1, in2;

    P1 = 5; 
    P2 = 5; 

    while (1) {
        in1 = P1;
        in2 = P2;

        P0 = in1 & in2; 
        P3 = in1 | in2; 
        
        
        ACC = in1 ^ in2;
        P1 = ACC;
    }
}