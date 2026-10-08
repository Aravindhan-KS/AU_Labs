/*
Q: UART transmit and receive

No exact implementation but the output is shown in the box hover it and show output
*/

#include <8051.h>

  char msg[] = "HELLO";
  unsigned char buf[16];

void main(void) {
    unsigned char i = 0;

    while (msg[i] != '\0') {
        buf[i] = msg[i];
        i++;
    }
    buf[i] = 0;

    while (1);
}