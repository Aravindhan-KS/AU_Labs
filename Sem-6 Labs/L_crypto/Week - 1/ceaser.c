#include <stdio.h>
#include <ctype.h>

void caesarCipher(char text[], int shift) 
{
	char ch;
	for (int i = 0; text[i] != '\0'; i++) 
	{
		ch = text[i];
		if (isupper(ch) && !isspace)
			text[i] = (ch - 'A' + shift) % 26 + 'A';
		else if (islower(ch))
			text[i] = (ch - 'a' + shift) % 26 + 'a';
	}

}

int main() {
	char text[100];
	int shift;
	printf("Enter text: ");
	scanf(" %[^\n]",text);
	printf("Enter shift: ");
	scanf("%d", &shift);
	caesarCipher(text, shift);
	printf("Encrypted text: %s\n", text);
	return 0;
}