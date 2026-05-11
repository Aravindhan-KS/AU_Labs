%{
#include <stdio.h>
#include <string.h>
%}

%option noyywrap

%%
[a-zA-Z]*		 printf("First name: %s\n", yytext);       
[" "]+    ;
[a-zA-Z]*[^ ]		printf("Middle name : %s\n",yytext); 
[a-zA-Z0-9]*			printf("Last Name :%s\n",yytext);               
[\t\n]+                     ;
%%

int main() {
    yylex();
}

