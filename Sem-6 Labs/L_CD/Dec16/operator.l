%{
#include <stdio.h>
%}
%option noyywrap
%%
"+"|"-"|"*"|"/"|"%" {
printf("Saw an operator: %s\n", yytext); }
.|\n { }
%%
int main(void)
{ yylex();
return 0;
}

