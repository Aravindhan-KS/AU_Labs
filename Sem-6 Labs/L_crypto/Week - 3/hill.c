#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int mod(int a, int m) {
    return (a % m + m) % m;
}

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int modInverse(int a, int m) {
    for (int x = 1; x < m; x++)
        if (((a % m) * (x % m)) % m == 1)
            return x;
    return -1;
}

void getCofactor(int n, int mat[n][n], int temp[n][n], int p, int q) {
    int i = 0, j = 0;
    for (int row = 0; row < n; row++) {
        for (int col = 0; col < n; col++) {
            if (row != p && col != q) {
                temp[i][j++] = mat[row][col];
                if (j == n - 1) {
                    j = 0;
                    i++;
                }
            }
        }
    }
}

int determinant(int n, int mat[n][n]) {
    int D = 0;
    if (n == 1) return mat[0][0];

    int temp[n][n];
    int sign = 1;

    for (int f = 0; f < n; f++) {
        getCofactor(n, mat, temp, 0, f);
        D += sign * mat[0][f] * determinant(n - 1, temp);
        sign = -sign;
    }
    return D;
}

void adjoint(int n, int mat[n][n], int adj[n][n]) {
    if (n == 1) {
        adj[0][0] = 1;
        return;
    }
    int sign = 1, temp[n][n];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            getCofactor(n, mat, temp, i, j);
            sign = ((i + j) % 2 == 0) ? 1 : -1;
            adj[j][i] = sign * determinant(n - 1, temp);
        }
    }
}

int inverseMatrix(int n, int mat[n][n], int inv[n][n]) {
    int det = determinant(n, mat);
    int detMod = mod(det, 26);

    if (detMod == 0 || gcd(detMod, 26) != 1) {
        printf("Key matrix is invalid (Determinant is 0 or not coprime to 26).\n");
        return 0;
    }

    int detInv = modInverse(detMod, 26);
    int adj[n][n];
    adjoint(n, mat, adj);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            inv[i][j] = mod(adj[i][j] * detInv, 26);

    return 1;
}

int main() {
    int n;
    printf("Enter order of key matrix (n): ");
    scanf("%d", &n);

    int key[n][n], keyInv[n][n];
    printf("Enter key matrix elements:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &key[i][j]);

    if (!inverseMatrix(n, key, keyInv)) return 0;

    printf("\nInverse Key Matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) printf("%d ", keyInv[i][j]);
        printf("\n");
    }

    char plaintext[100];
    printf("\nEnter plaintext: ");
    scanf("%s", plaintext);

    int len = strlen(plaintext);
    int pad = (n - len % n) % n;
    for (int i = 0; i < pad; i++) plaintext[len + i] = 'X';
    plaintext[len + pad] = '\0';
    len += pad;

    char ciphertext[len + 1];
    for (int i = 0; i < len; i += n) {
        for (int j = 0; j < n; j++) {
            int sum = 0;
            for (int k = 0; k < n; k++)
                sum += (plaintext[i + k] - 'A') * key[k][j];
            ciphertext[i + j] = (sum % 26) + 'A';
        }
    }
    ciphertext[len] = '\0';
    printf("Ciphertext: %s\n", ciphertext);

    char decrypted[len + 1];
    for (int i = 0; i < len; i += n) {
        for (int j = 0; j < n; j++) {
            int sum = 0;
            for (int k = 0; k < n; k++)
                sum += (ciphertext[i + k] - 'A') * keyInv[k][j];
            decrypted[i + j] = (sum % 26) + 'A';
        }
    }
    decrypted[len] = '\0';
    printf("Decrypted Text: %s\n", decrypted);

    return 0;
}