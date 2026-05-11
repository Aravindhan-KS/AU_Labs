%{
#include <stdio.h>
int line_no = 1;
%}

%%
\n	   { line_no++; }
[ \t]+     ;

[0-9]+[a-zA-Z][a-zA-Z0-9]* { printf("Lexical Error at line %d: Invalid identifier '%s'\n",line_no, yytext); }

[a-zA-Z][a-zA-Z0-9]* { printf("IDENTIFIER: %s\n", yytext); }

[0-9]+ { printf("NUMBER: %s\n", yytext); }

[+\-*/=] { printf("OPERATOR: %s\n", yytext); }

[@#$] {	printf("Lexical Error at line %d: Invalid character '%s'\n",line_no, yytext); }

. { printf("Lexical Error at line %d: Unknown symbol '%s'\n",line_no, yytext); }

%%

int main() { yylex(); return 0; }
int yywrap() { return 1; }
