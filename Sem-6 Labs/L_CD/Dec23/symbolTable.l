%{
#include <stdio.h>
#include <string.h>

char symtab[100][50];
int count = 0;
//ctrl+d to eof
void add(char *id) {
    for(int i = 0; i < count; i++) {
        if(strcmp(symtab[i], id) == 0)
            return;   /* avoid duplicates */
    }
    strcpy(symtab[count++], id);
}

%}

%option noyywrap

%%
[a-zA-Z_][a-zA-Z0-9_]*   { 
                            add(yytext);
                            printf("Identifier found: %s\n", yytext);
                         }
[ \t\n]+                ;
.                      ;
%%

int main() {
    yylex();
    printf("\n----- SYMBOL TABLE -----\n");
    for(int i = 0; i < count; i++)
        printf("%d : %s\n", i + 1, symtab[i]);
    return 0;
}
