#include <8051.h>

void main(void) {
    unsigned char val1, val2, sum;

    P1 = 2; /* Set Port 1 as Input */
    P2 = 3; /* Set Port 2 as Input */

    while (1) {
        val1 = P1; /* Read first byte */
        val2 = P2; /* Read second byte */

        /* Add the numbers and store in register/variable */
        ACC = val1 + val2; 
        sum = ACC;

        P0 = sum;         /* Display sum output on Port 0 */
        P3_0 = CY;        /* Display Carry Flag (from PSW register) on P3.0 */
    }
}