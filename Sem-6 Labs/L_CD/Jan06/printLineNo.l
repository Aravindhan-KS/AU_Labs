%{
#include <stdio.h>
int line_no = 1;
%}

%%

\n 	{ printf("\tLine: %d",line_no); line_no++; printf("\n"); }
[ \t]+     ;

[0-9]+[a-zA-Z][a-zA-Z0-9]* { printf("%s", yytext); }

[a-zA-Z][a-zA-Z0-9]* {  printf("%s", yytext); }

[0-9]+ { printf("%s", yytext); }

[+\-*/=] { printf("%s", yytext); }

[@#$] ; 

%%

int main() { yylex(); return 0; }
int yywrap() { return 1; }

