#include <stdio.h>
int main() {
    int a, b, p;
    int mul;
    printf("Enter a, b and p: ");
    scanf("%d %d %d", &a, &b, &p);
    mul = (a * b) % p;
    printf("Multiplication = (%d * %d) mod %d = %d\n", a, b, p, mul);
    return 0;
}
