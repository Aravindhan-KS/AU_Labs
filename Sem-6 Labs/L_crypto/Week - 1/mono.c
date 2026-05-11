#include <stdio.h>
#include <ctype.h>

int main() {
	char plaintext[100];
	char key[26];// = "QWERTYUIOPASDFGHJKLZXCVBNM"; // substitution key
	char ch;

	printf("Enter plaintext: ");
	scanf(" %[^\n]",plaintext);

	printf("Enter key: ");
	scanf(" %[^\n]",key);

	for (int i = 0; plaintext[i] != '\0'; i++) {
		ch = plaintext[i];
		if (isupper(ch))
			plaintext[i] = key[ch - 'A'];
		else if (islower(ch))
			plaintext[i] = tolower(key[ch - 'a']);
	}
	printf("Ciphertext: %s\n", plaintext);
	return 0;
}