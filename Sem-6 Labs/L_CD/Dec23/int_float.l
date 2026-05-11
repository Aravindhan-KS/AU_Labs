%{
#include <stdio.h>
%}

%%
[0-9]+              printf("Integer : %s\n", yytext);
[0-9]+\.[0-9]+      printf("Float   : %s\n", yytext);
[+\-*/%]            printf("Operator: %s\n", yytext);
[\(\)]              printf("Bracket : %s\n", yytext);
[ \t\n]+            ;      
.                   printf("Others  : %s\n", yytext);
%%

int yywrap() {                                                               
    return 1;                                                                 
}

int main() {
    yylex();
    return 0;
}
