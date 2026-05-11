%{
#include <stdio.h>
#include <stdlib.h>

int yylex();
void yyerror(char *s);

int reg = 0;
%}

%token ID

%%

S : E '\n'
;

E : E '+' T
    {
        printf("ADD R0, R1\n");
    }
  | E '-' T
    {
        printf("SUB R0, R1\n");
    }
  | T
;

T : T '*' F
    {
        printf("MUL R0, R1\n");
    }
  | T '/' F
    {
        printf("DIV R0, R1\n");
    }
  | F
;

F : '(' E ')'
  | ID
    {
        if(reg == 0)
        {
            printf("MOV R0, %c\n",$1);
            reg = 1;
        }
        else
        {
            printf("MOV R1, %c\n",$1);
        }
    }
;

%%

void yyerror(char *s)
{
    printf("Error\n");
}

int main()
{
    printf("Enter expression : ");
    yyparse();
}
