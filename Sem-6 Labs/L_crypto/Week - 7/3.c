#include <stdio.h>
int extendedGCD(int a, int b, int *x, int *y) {
    if (a == 0) {
        *x = 0;
        *y = 1;
        return b;
    }
    int x1, y1;
    int gcd = extendedGCD(b % a, a, &x1, &y1);
    *x = y1 - (b / a) * x1;
    *y = x1;
    return gcd;
}
int main() {
    int a, p, x, y;
    printf("Enter a and p: ");
    scanf("%d %d", &a, &p);
    extendedGCD(a, p, &x, &y);
    x = (x % p + p) % p;
    printf("Multiplicative Inverse of %d mod %d = %d\n", a, p, x);
    return 0;
}
