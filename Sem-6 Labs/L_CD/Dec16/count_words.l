%{
#include <stdio.h>
int count = 1;
%}
%option noyywrap
%%
" " {
count++;
printf("No of words : %d\n", count);
}
.|\n { }
%%
int main(void)
{yylex();
return 0;
}

