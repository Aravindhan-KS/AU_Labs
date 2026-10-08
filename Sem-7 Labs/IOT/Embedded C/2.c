/*
Q: Read a byte from one port, write to another

   P1 as input
   P2 as output

*/
#include <8051.h>
void main(void) {
    P1 = 0xDC;            
    while (1) {
        P2 = P1;          
    }
}