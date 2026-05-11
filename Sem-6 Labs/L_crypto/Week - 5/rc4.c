#include <stdio.h>
#include <string.h>

void swap(int *a, int *b)
{
        int temp = *a;
        *a = *b;
        *b = temp;
}
int main()
{
        char plaintext[100], key[100];
        int S[256], K[256];
        int i, j = 0, t;
        int ptlen, keylen;
        int keystream[100];
        unsigned char ciphertext[100], decrypted[100];

        printf("Enter plaintext: ");
        scanf(" %[^\n]",plaintext);
        printf("Enter key: ");
        scanf(" %[^\n]",key);

        ptlen = strlen(plaintext);
        keylen = strlen(key);

        for (i = 0; i < 256; i++) 
        {
                S[i] = i;
                K[i] = key[i % keylen];
        }
        for (i = 0; i < 256; i++) 
        {
                j = (j + S[i] + K[i]) % 256;
                swap(&S[i], &S[j]);
        }

        i = j = 0;
        for (int n = 0; n < ptlen; n++) 
        {
                i = (i + 1) % 256;
                j = (j + S[i]) % 256;
                swap(&S[i], &S[j]);
                t = (S[i] + S[j]) % 256;
                keystream[n] = S[t];
                ciphertext[n] = plaintext[n] ^ keystream[n];
                decrypted[n] = ciphertext[n] ^ keystream[n];
        }

        printf("Generated Keystream : ");
        for (i = 0; i < ptlen; i++)
        {
                printf("%d ", keystream[i]);
        }
        
        printf("\nCiphertext : ");
        for (i = 0; i < ptlen; i++)
        {
                printf("%02X ", ciphertext[i]);
        }
        
        printf("\nDecrypted Text : ");
        for (i = 0; i < ptlen; i++)
        {
                printf("%c", decrypted[i]);
        }
        printf("\n");
        
        return 0;
}