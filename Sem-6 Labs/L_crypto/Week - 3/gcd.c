#include <stdio.h>
long long gcd(long long a, long long b) 
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main() 
{
    long long num1, num2;
    
    printf("Enter number: ");
    scanf("%lld", &num1);
    printf("Enter number: ");
    scanf("%lld", &num2);

    printf("GCD of %lld and %lld is: %lld\n", num1, num2, gcd(num1, num2));
    return 0;
}