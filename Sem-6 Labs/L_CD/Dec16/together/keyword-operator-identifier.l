%{
	#include <stdio.h>
%}
%option noyywrap

%%
"if"|"else" {
	printf("Saw a keyword: %s\n", yytext); 
}
[a-zA-Z_]+[a-zA-Z0-9]*[a-zA-Z]* {

	printf("Saw an identifier: %s\n", yytext);
}
"+"|"-"|"/"|"*"|"%" {
	printf("Saw an operator: %s\n", yytext);
}
.|\n { }
%%

int main(void)
{
	yylex();
	return 0;
}
