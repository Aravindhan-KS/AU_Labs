%{
#include <stdio.h>
%}

%%
[0-9]+\.[0-9]+\.[0-9]+    printf("ERROR: Invalid number format: %s\n", yytext);
"/*"([^*]|\*+[^*/])*      printf("ERROR: Unterminated comment\n");
[@#$]                     printf("ERROR: Invalid symbol: %s\n", yytext);
[0-9]+\.[0-9]+            printf("FLOAT: %s\n", yytext);
[0-9]+                    printf("INTEGER: %s\n", yytext);
[ \t\n]+                  ;
.                          ;
%%

int yywrap()
{
	return 1;
}

int main() 
{
    yylex();
    return 0;
}
