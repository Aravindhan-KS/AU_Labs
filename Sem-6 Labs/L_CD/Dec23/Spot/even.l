%{
#include <stdio.h>
#include <string.h>

char symtab[100][50];
int count = 0;

void evenorodd(char *id)
{
	int number = atoi(id);
	if(number % 2 == 0)
	{
		printf("Number is even\n");
	}
	else
	{
		printf("Number is odd\n");
	}
}


%}

%option noyywrap

%%
[0-9]*   {
                            evenorodd(yytext);
                            
                         }
[ \t\n]+                ;
.                      ;
%%

int main() {
    yylex();
    return 0;
}

