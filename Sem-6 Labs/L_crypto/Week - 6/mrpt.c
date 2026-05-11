#include <stdio.h>
#include <stdlib.h>

long long power(long long a, long long d, long long n) {
    long long res = 1;
    a = a % n;
    while (d > 0) {
        if (d & 1)
            res = (res * a) % n;
        a = (a * a) % n;
        d >>= 1;
    }
    return res;
}

int millerRabin(long long n, int k) {
    if (n <= 1 || n == 4) return 0;
    if (n <= 3) return 1;

    long long d = n - 1;
    while (d % 2 == 0)
        d /= 2;

    for (int i = 0; i < k; i++) {
        long long a = 2 + rand() % (n - 4);
        long long x = power(a, d, n);

        if (x == 1 || x == n - 1)
            continue;

        long long temp = d;
        int flag = 0;

        while (temp != n - 1) {
            x = (x * x) % n;
            temp *= 2;

            if (x == n - 1) {
                flag = 1;
                break;
            }
        }

        if (!flag)
            return 0;
    }
    return 1;
}

int main() {
    long long n;
    scanf("%lld", &n);

    if (millerRabin(n, 5))
        printf("Prime\n");
    else
        printf("Composite\n");

    return 0;
}
