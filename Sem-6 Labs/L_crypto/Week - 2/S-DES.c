#include <stdio.h>
#include <string.h>

int P10[] = {3,5,2,7,4,10,1,9,8,6};
int P8[]  = {6,3,7,4,8,5,10,9};
int IP[]  = {2,6,3,1,4,8,5,7};
int IP1[] = {4,1,3,5,7,2,8,6};
int EP[]  = {4,1,2,3,2,3,4,1};
int P4[]  = {2,4,3,1};
int S0[4][4] = {
	{1,0,3,2},
	{3,2,1,0},
	{0,2,1,3},
	{3,1,3,2}
};
int S1[4][4] = {
	{0,1,2,3},
	{2,0,1,3},
	{3,0,1,0},
	{2,1,0,3}
};

void permute(int *in, int *out, int *p, int n) 
{
	for(int i=0;i<n;i++)
	{
		out[i] = in[p[i]-1];
	}
}

void leftShift(int *k, int s) 
{
	while(s--) 
	{
		int t = k[0];
		for(int i=0;i<4;i++) k[i]=k[i+1];
		k[4]=t;
		t = k[5];
		for(int i=5;i<9;i++) k[i]=k[i+1];
		k[9]=t;
	}
}

void keyGen(int *key, int *k1, int *k2) 
{
	int t[10];
	permute(key,t,P10,10);
	leftShift(t,1);
	permute(t,k1,P8,8);
	leftShift(t,2);
	permute(t,k2,P8,8);
}

void fk(int *b, int *k) 
{
	int L[4], R[4], ep[8], x[8];
	for(int i=0;i<4;i++) 
	{
		L[i]=b[i];
		R[i]=b[i+4];
	}
	permute(R,ep,EP,8);
	for(int i=0;i<8;i++)
	{
		x[i]=ep[i]^k[i];
	}
	int r=(x[0]<<1)|x[3];
	int c=(x[1]<<1)|x[2];
	int s0=S0[r][c];

	r=(x[4]<<1)|x[7];
	c=(x[5]<<1)|x[6];
	int s1=S1[r][c];

	int sb[4] = 
	{
		(s0>>1)&1, s0&1,
		(s1>>1)&1, s1&1
	};
	int p4[4];
	permute(sb,p4,P4,4);
	for(int i=0;i<4;i++)
	{
		b[i]=L[i]^p4[i];
	}	
}

void sdes(int *pt, int *k1, int *k2, int mode) 
{
	int t[8];
	permute(pt,t,IP,8);
	if(mode==0) 
	{
		fk(t,k1);
	} 
	else 
	{
		fk(t,k2);
	}
	for(int i=0;i<4;i++) 
	{
		int x=t[i];
		t[i]=t[i+4];
		t[i+4]=x;
	}
	if(mode==0) 
	{
		fk(t,k2);
	}
	else 
	{
		fk(t,k1);
	}
	permute(t,pt,IP1,8);
}

void charToBits(char c, int *b) 
{
	for(int i=7;i>=0;i--) 
	{
		b[i]=c&1;
		c>>=1;
	}
}

void bitsToChar(int *b, char *c) 
{
	*c=0;
	for(int i=0;i<8;i++)
	{
		*c=(*c<<1)|b[i];
	}
}

int main() 
{
	int choice;
	printf("1. Binary\n2. Text\nChoose: ");
	scanf("%d",&choice);
	if(choice==1) 
	{
		int key[10], pt[8], k1[8], k2[8];
		char ks[11], ps[9];

		printf("Enter 10-bit key: ");
		scanf("%s",ks);
		printf("Enter 8-bit plaintext: ");
		scanf("%s",ps);

		for(int i=0;i<10;i++) 
		{
			key[i]=(ks[i]=='1');
		}
		for(int i=0;i<8;i++)
		{
			pt[i]=(ps[i]=='1');
		}

		keyGen(key,k1,k2);
		printf("K1: ");
		for(int i=0;i<8;i++)
		{
			printf("%d",k1[i]);
		}

		printf("\nK2: ");
		for(int i=0;i<8;i++)
		{ 
			printf("%d",k2[i]);
		}

		sdes(pt,k1,k2,0);
		printf("\nCiphertext: ");

		for(int i=0;i<8;i++)
		{
			printf("%d",pt[i]);
		}

		sdes(pt,k1,k2,1);
		printf("\nDecrypted Plaintext: ");
		for(int i=0;i<8;i++)
		{ 
			printf("%d",pt[i]);
		}
	}
	else 
	{
		int key[10], k1[8], k2[8];
		char text[50], ks[11];

		printf("Enter 10-bit key: ");
		scanf("%s",ks);
		printf("Enter text: ");
		scanf(" %[^\n]",text);

		for(int i=0;i<10;i++)
		{
			 key[i]=(ks[i]=='1');
		}

		keyGen(key,k1,k2);
		printf("K1: ");
		for(int i=0;i<8;i++)
		{
			printf("%d",k1[i]);
		}

		printf("\nK2: ");
		for(int i=0;i<8;i++)
		{
			 printf("%d",k2[i]);
		}
		
		printf("\nCiphertext (binary): ");
		for(int i=0;i<strlen(text);i++) 
		{	
			int b[8];
			charToBits(text[i],b);
			sdes(b,k1,k2,0);
			for(int j=0;j<8;j++) printf("%d",b[j]);
			printf(" ");
		}

		printf("\nDecrypted Text: ");
		for(int i=0;i<strlen(text);i++) 
		{
			int b[8];
			charToBits(text[i],b);
			sdes(b,k1,k2,0);
			sdes(b,k1,k2,1);
			char c;
			bitsToChar(b,&c);
			printf("%c",c);
		}
	}
	return 0;
}