
%{
#include <stdio.h>
#include <stdlib.h>

int yylex();
void yyerror(char *s);

%}

%token NUM

%%
stmt : expr '\n' { printf("\n"); exit(0); }
;

expr : expr '+' term { printf("+ "); }
| expr '-' term { printf("- "); }
| term
;

term : term '*' factor { printf("* "); }
| term '/' factor { printf("/ "); }
| factor
;

factor : '(' expr ')'
| NUM                { printf("%c ", $1); }
;

%%

int main() 
{
                printf("Enter infix expression: ");
                yyparse();
                return 0;
}

void yyerror(char *s) 
{
                printf("Invalid Expression\n");
}