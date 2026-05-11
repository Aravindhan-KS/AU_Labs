#include <stdio.h>

int p = 31;
int a = 1;

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
    int Gx = 3, Gy = 10;     // Base point
    int d = 7;               // Private key

    int Qx,Qy;
    scalarMultiply(d,Gx,Gy,&Qx,&Qy);

    printf("Public Key Q = (%d , %d)\n",Qx,Qy);

    int Mx = 9, My = 7;      // Message point
    int k = 3;               // Random number

    int C1x,C1y;
    scalarMultiply(k,Gx,Gy,&C1x,&C1y);

    int kQx,kQy;
    scalarMultiply(k,Qx,Qy,&kQx,&kQy);

    int C2x,C2y;
    pointOperation(Mx,My,kQx,kQy,&C2x,&C2y);

    printf("\nCipher Text:\n");
    printf("C1 = (%d , %d)\n",C1x,C1y);
    printf("C2 = (%d , %d)\n",C2x,C2y);

    int dC1x,dC1y;
    scalarMultiply(d,C1x,C1y,&dC1x,&dC1y);

    dC1y = (p - dC1y) % p;

    int Dx,Dy;
    pointOperation(C2x,C2y,dC1x,dC1y,&Dx,&Dy);

    printf("\nDecrypted Message = (%d , %d)\n",Dx,Dy);

    return 0;
}