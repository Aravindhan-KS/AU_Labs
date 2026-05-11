%{
#include <stdio.h>
%}
%option noyywrap
%%
"if"|"else"|"elseif"|"for"|"while" {
printf("Saw an keyword: %s\n", yytext); }
.|\n { }
%%
int main(void)
{ yylex();
return 0;
}
