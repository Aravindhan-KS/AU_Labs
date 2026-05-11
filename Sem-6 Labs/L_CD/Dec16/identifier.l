%{
#include <stdio.h>
%}
%option noyywrap
%%
[a-zA-Z_]+ {
printf("Saw an identifier: %s\n", yytext); }
.|\n { }
%%
int main(void)
{ yylex();
return 0;
}
