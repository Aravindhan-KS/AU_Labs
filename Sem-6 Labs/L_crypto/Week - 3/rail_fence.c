#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void encryptRailFence(char *text, int depth) {
    int len = strlen(text);
    char rail[depth][len];

    for (int i = 0; i < depth; i++)
        for (int j = 0; j < len; j++)
            rail[i][j] = '\n';
            
    int dir_down = 0;
    int row = 0, col = 0;
    
    for (int i = 0; i < len; i++) {
        if (row == 0 || row == depth - 1)
            dir_down = !dir_down;
            
        rail[row][col++] = text[i];
        
        if (dir_down) row++;
        else row--;
    }
    
    printf("Ciphertext: ");
    for (int i = 0; i < depth; i++)
        for (int j = 0; j < len; j++)
            if (rail[i][j] != '\n')
                printf("%c", rail[i][j]);
    printf("\n");
}

void decryptRailFence(char *cipher, int depth) {
    int len = strlen(cipher);
    char rail[depth][len];
    
    for (int i = 0; i < depth; i++)
        for (int j = 0; j < len; j++)
            rail[i][j] = '\n';
            
    int dir_down = 0;
    int row = 0, col = 0;

    for (int i = 0; i < len; i++) {
        if (row == 0) dir_down = 1;
        if (row == depth - 1) dir_down = 0;
            
        rail[row][col++] = '*';
        
        if (dir_down) row++;
        else row--;
    }

    int index = 0;
    for (int i = 0; i < depth; i++)
        for (int j = 0; j < len; j++)
            if (rail[i][j] == '*' && index < len)
                rail[i][j] = cipher[index++];

    printf("Decrypted Text: ");
    row = 0; col = 0;
    dir_down = 0;
    for (int i = 0; i < len; i++) {
        if (row == 0) dir_down = 1;
        if (row == depth - 1) dir_down = 0;
            
        if (rail[row][col] != '\n')
            printf("%c", rail[row][col++]);
            
        if (dir_down) row++;
        else row--;
    }
    printf("\n");
}

int main() {
    char text[100];
    int depth;
    
    printf("Enter plaintext: ");
    scanf(" %[^\n]s", text); 
    printf("Enter depth: ");
    scanf("%d", &depth);
    
    if (depth < 2) {
        printf("Depth must be at least 2.\n");
        return 0;
    }

    encryptRailFence(text, depth);
    
    char cipher[100];
    printf("Enter ciphertext to decrypt: ");
    scanf(" %[^\n]s", cipher);
    decryptRailFence(cipher, depth);
    
    return 0;
}
