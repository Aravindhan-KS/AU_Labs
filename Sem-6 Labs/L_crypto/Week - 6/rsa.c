#include <stdio.h>

long long modexp(long long a, long long b, long long m) {
    long long r = 1;
    while (b) {
        if (b % 2) r = (r * a) % m;
        a = (a * a) % m;
        b /= 2;
    }
    return r;
}

long long gcd(long long a, long long b) {
    return b == 0 ? a : gcd(b, a % b);
}

long long modinv(long long e, long long phi) {
    for (long long d = 1; d < phi; d++)
        if ((e * d) % phi == 1) return d;
    return -1;
}

int main() {
    long long p, q, m, n, phi, e, d;
    scanf("%lld %lld %lld", &p, &q, &m);

    n = p * q;
    phi = (p - 1) * (q - 1);

    for (e = 2; e < phi; e++)
        if (gcd(e, phi) == 1) break;

    d = modinv(e, phi);

    long long c = modexp(m, e, n);
    long long dec = modexp(c, d, n);

    printf("Public Key: (%lld,%lld)\n", e, n);
    printf("Private Key: (%lld,%lld)\n", d, n);
    printf("Encrypted: %lld\n", c);
    printf("Decrypted: %lld\n", dec);
}
