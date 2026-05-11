%{
#include <stdio.h>
#include <stdlib.h>

void yyerror(const char *s);
int yylex();
%}

%token FOR ID NUM
%token LT GT LE GE EQ NE

%%

start:
        forstmt { printf("Valid For Loop\n"); }
        ;

forstmt:
        FOR '(' assign ';' condition ';' assign ')' block
        ;

assign:
        ID '=' expr
        ;

condition:
        expr LT expr
        | expr GT expr
        | expr LE expr
        | expr GE expr
        | expr EQ expr
        | expr NE expr
        ;

expr:
        expr '+' expr
        | expr '-' expr
        | expr '*' expr
        | expr '/' expr
        | ID
        | NUM
        ;

block:
        '{' '}'
        | '{' stmtlist '}'
        ;

stmtlist:
        stmtlist stmt
        |
        ;

stmt:
        assign ';'
        ;

%%

void yyerror(const char *s) {
    printf("Invalid For Loop\n");
}

int main() {
    yyparse();
    return 0;
}