%{
#include <stdio.h>
#include <string.h>

/* list of valid keywords */
char *keywords[] = {
    "int", "float", "char", "double",
    "for", "while", "return", "if", "else"
};

int keyword_count = 9;

/* check if s is a subsequence of k */
int isSubsequence(char *s, char *k) {
    int i = 0, j = 0;

    while (s[i] && k[j]) {
        if (s[i] == k[j])
            i++;
        j++;
    }
    return s[i] == '\0';
}

void correct(char *word) {
    int found = 0;

    for (int i = 0; i < keyword_count; i++) {
        if (strlen(word) <= strlen(keywords[i]) &&
            isSubsequence(word, keywords[i])) {

            printf("Corrected keyword: %s\n", keywords[i]);
            found = 1;
        }
    }

    if (!found)
        printf("No correction possible for: %s\n", word);
}
%}

%%
[a-zA-Z]+   { correct(yytext); }
%%

int yywrap() {
    return 1;
}

int main() {
    printf("Enter keyword: ");
    yylex();
    return 0;
}
