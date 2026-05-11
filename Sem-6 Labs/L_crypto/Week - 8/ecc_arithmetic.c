#include <stdio.h>

int p = 31;   // Prime number
int a = 1;    // Curve parameter

/* Modular Inverse */
int modInverse(int n)
{
    n = (n % p + p) % p;
    for(int i = 1; i < p; i++)
        if((n * i) % p == 1)
            return i;
    return 1;
}

/* Point Addition / Doubling */
void pointOperation(int x1,int y1,int x2,int y2,int *x3,int *y3)
{
    int lambda;

    if(x1 == x2 && y1 == y2)
        lambda = ((3*x1*x1 + a) * modInverse(2*y1)) % p;
    else
        lambda = ((y2 - y1) * modInverse(x2 - x1)) % p;

    lambda = (lambda + p) % p;

    *x3 = (lambda*lambda - x1 - x2) % p;
    *x3 = (*x3 + p) % p;

    *y3 = (lambda*(x1 - *x3) - y1) % p;
    *y3 = (*y3 + p) % p;
}

/* Scalar Multiplication */
void scalarMultiply(int k,int x,int y,int *rx,int *ry)
{
    *rx = x;
    *ry = y;

    for(int i = 1; i < k; i++)
        pointOperation(*rx,*ry,x,y,rx,ry);
}

int main()
{
    int x1 = 3, y1 = 10;
    int x2 = 9, y2 = 7;

    int x3,y3;

    printf("Point Addition:\n");
    pointOperation(x1,y1,x2,y2,&x3,&y3);
    printf("Result = (%d , %d)\n",x3,y3);

    printf("\nPoint Doubling:\n");
    pointOperation(x1,y1,x1,y1,&x3,&y3);
    printf("Result = (%d , %d)\n",x3,y3);

    printf("\nScalar Multiplication (k=3):\n");
    scalarMultiply(3,x1,y1,&x3,&y3);
    printf("Result = (%d , %d)\n",x3,y3);

    return 0;
}