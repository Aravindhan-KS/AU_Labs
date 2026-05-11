#include <stdio.h>
unsigned char gfMultiply(unsigned char a, unsigned char b) {
    unsigned char result = 0;
    unsigned char mod = 0x1B;

    while (b) {
        if (b & 1)
            result ^= a;
        unsigned char msb = a & 0x80;
        a <<= 1;
        if (msb)
            a ^= mod;
        b >>= 1;
    }
    return result;
}
int main() {
    unsigned char A = 0x57;
    unsigned char B = 0x83;
    printf("Addition (A ^ B) = 0x%X\n", A ^ B);
    printf("Multiplication (A * B mod P(x)) = 0x%X\n", gfMultiply(A, B));
    return 0;
}
