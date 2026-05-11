%{
#include <stdio.h>
#include <string.h>
%}

%option noyywrap

%%
[a-zA-Z]*		 printf("%s", yytext);       
["!"|"&"|"."|","]+    ;              
[\t\n]+                     ;
%%

int main() {
    yylex();
}
