%{
	#include <stdio.h>
	int line_no = 1;
	int panic = 0;
%}

%%

\n   { line_no++; }

[ \t]+              ;

[;}] { if (panic) { panic = 0; } }

[0-9]+[a-zA-Z][a-zA-Z0-9]* { printf("Lexical Error at line %d: Invalid identifier '%s'\n",line_no, yytext); panic = 1; }

[a-zA-Z][a-zA-Z0-9]* { if (!panic) {  printf("IDENTIFIER: %s\n", yytext); } }

[0-9]+ { if (!panic) { printf("NUMBER: %s\n", yytext); } }

[+\-*/=] { if (!panic) { printf("OPERATOR: %s\n", yytext); } }

[@#$] { printf("Lexical Error at line %d: Invalid character '%s'\n",line_no, yytext); panic = 1; }

. { if (!panic) { printf("Lexical Error at line %d: Unknown symbol '%s'\n",line_no, yytext); panic = 1; } }

%%

int main() { yylex(); return 0; }

int yywrap() { return 1; }
