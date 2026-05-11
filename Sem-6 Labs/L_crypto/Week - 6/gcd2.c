#include <stdio.h>

int egcd(int a, int b, int *x, int *y) {
    if (b == 0) {
        *x = 1;
        *y = 0;
        return a;
    }
    int x1, y1;
    int g = egcd(b, a % b, &x1, &y1);
    *x = y1;
    *y = x1 - (a / b) * y1;
    return g;
}

int main() {
    int a, b, x, y;
    scanf("%d %d", &a, &b);
    int g = egcd(a, b, &x, &y);

    printf("GCD = %d\n", g);
    printf("x = %d, y = %d\n", x, y);

    if (g == 1)
        printf("Modular Inverse = %d\n", (x % b + b) % b);
}
