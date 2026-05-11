#include <stdio.h>
int main() {
    int a, b, p;
    int add, sub;
    printf("Enter a, b and p: ");
    scanf("%d %d %d", &a, &b, &p);
    add = (a + b) % p;
    sub = (a - b + p) % p;
    printf("Addition = (%d + %d) mod %d = %d\n", a, b, p, add);
    printf("Subtraction = (%d - %d) mod %d = %d\n", a, b, p, sub);
    return 0;
}
