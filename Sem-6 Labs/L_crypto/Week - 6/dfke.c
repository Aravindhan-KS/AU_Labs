#include <stdio.h>

long long power(long long a, long long b, long long p) {
    long long r = 1;
    while (b) {
        if (b % 2) r = (r * a) % p;
        a = (a * a) % p;
        b /= 2;
    }
    return r;
}

int main() {
    long long p, g, a, b;
    scanf("%lld %lld %lld %lld", &p, &g, &a, &b);

    long long A = power(g, a, p);
    long long B = power(g, b, p);

    long long key1 = power(B, a, p);
    long long key2 = power(A, b, p);

    printf("Public Key A: %lld\n", A);
    printf("Public Key B: %lld\n", B);
    printf("Shared Key: %lld\n", key1);
}
