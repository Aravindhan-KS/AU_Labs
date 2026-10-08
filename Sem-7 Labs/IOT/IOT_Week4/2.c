#include <8051.h>

void main(void) {
    unsigned char port_data;
    
    P1 = 0xFF;

    while (1) {
        port_data = P1;  /* Read 8-bit data byte from Port 1 */
        P2 = port_data;  /* Output the read byte to Port 2 */
    }
}