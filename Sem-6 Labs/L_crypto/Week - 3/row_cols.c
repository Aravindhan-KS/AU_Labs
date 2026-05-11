#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char ch;
    int original_index;
} KeyChar;

int compare(const void *a, const void *b) {
    return ((KeyChar *)a)->ch - ((KeyChar *)b)->ch;
}

int main() {
    char plaintext[100], keyword[50];
    
    printf("Enter plaintext: ");
    scanf(" %[^\n]s", plaintext);
    printf("Enter keyword: ");
    scanf("%s", keyword);
    
    int len = strlen(plaintext);
    int keyLen = strlen(keyword);

    int rows = len / keyLen;
    if (len % keyLen != 0) {
        rows++;
        int pad = (rows * keyLen) - len;
        for (int i = 0; i < pad; i++) {
            plaintext[len + i] = 'X';
        }
        plaintext[len + pad] = '\0';
        len += pad;
    }

    char matrix[rows][keyLen];
    int k = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < keyLen; j++) {
            matrix[i][j] = plaintext[k++];
        }
    }

    KeyChar keys[keyLen];
    for (int i = 0; i < keyLen; i++) {
        keys[i].ch = keyword[i];
        keys[i].original_index = i;
    }
    
    qsort(keys, keyLen, sizeof(KeyChar), compare);

    char ciphertext[len + 1];
    k = 0;
    for (int i = 0; i < keyLen; i++) {
        int col = keys[i].original_index;
        for (int j = 0; j < rows; j++) {
            ciphertext[k++] = matrix[j][col];
        }
    }
    ciphertext[len] = '\0';
    printf("Ciphertext: %s\n", ciphertext);

    char decryptMatrix[rows][keyLen];
    k = 0;
    for (int i = 0; i < keyLen; i++) {
        int col = keys[i].original_index;
        for (int j = 0; j < rows; j++) {
            decryptMatrix[j][col] = ciphertext[k++];
        }
    }
    
    printf("Decrypted Text: ");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < keyLen; j++) {
            printf("%c", decryptMatrix[i][j]);
        }
    }
    printf("\n");
    
    return 0;
}