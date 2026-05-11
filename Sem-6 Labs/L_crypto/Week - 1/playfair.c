#include <stdio.h>
#include <string.h>
#include <ctype.h>

char keyTable[5][5];

void generateKeyTable(char key[]) {
	int used[26] = {0};
	int i, k = 0;
	for (i = 0; key[i]; i++) {
		if (key[i] == 'J') key[i] = 'I';
		if (!used[key[i] - 'A']) {
			keyTable[k / 5][k % 5] = key[i];
			used[key[i] - 'A'] = 1;
			k++;
		}
	}

	for (i = 0; i < 26; i++) {
		if (i + 'A' == 'J') continue;
		if (!used[i]) {
			keyTable[k / 5][k % 5] = i + 'A';
			k++;
		}
	}
}

void findPosition(char ch, int *row, int *col) {
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			if (keyTable[i][j] == ch) {
				*row = i;
				*col = j;
			}
}

void playfairEncrypt(char text[]) {
	int r1, c1, r2, c2;
	if(strlen(text) % 2 != 0)
	{
		strcat(text,"X");
	}
	for (int i = 0; i < strlen(text); i += 2) {
		findPosition(text[i], &r1, &c1);
		findPosition(text[i + 1], &r2, &c2);
		if (r1 == r2) {
			text[i] = keyTable[r1][(c1 + 1) % 5];
			text[i + 1] = keyTable[r2][(c2 + 1) % 5];
		} else if (c1 == c2) {
			text[i] = keyTable[(r1 + 1) % 5][c1];
			text[i + 1] = keyTable[(r2 + 1) % 5][c2];
		} else {
			text[i] = keyTable[r1][c2];
			text[i + 1] = keyTable[r2][c1];
		}
	}
}

int main() {
	char key[20], text[100];
	printf("Enter key: ");
	scanf("%s", key);
	printf("Enter plaintext: ");
	scanf("%s", text);
	generateKeyTable(key);
	playfairEncrypt(text);
	printf("Ciphertext: %s\n", text);
	return 0;
}