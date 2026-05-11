%{
#include <stdio.h>
#include <stdlib.h>

int count=0;
char *dtype;

void yyerror(const char *s);
int yylex();
%}

%union{
    char *str;
}

%token <str> TYPE
%token VAR COMMA SEMI

%%

stmt:
     TYPE { dtype=$1; count=0; }
     vars SEMI
     {
        printf("Type : %s\n", dtype);
        printf("Variable Count : %d\n", count);
     }
     ;

vars:
     VAR { count=1; }
     | vars COMMA VAR { count++; }
     ;

%%

void yyerror(const char *s)
{
    printf("Invalid declaration!\n");
}

int main()
{
    printf("Enter declaration:\n");
    yyparse();
    return 0;
}