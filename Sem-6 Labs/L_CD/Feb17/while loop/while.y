%{
#include <stdio.h>
#include <stdlib.h>

int yylex();
void yyerror(const char *s);
%}

%token WHILE ID NUM
%token LT GT EQ
%token ASSIGN SEMI
%token LP RP LB RB

%%

program : while_stmt
          { printf("Valid while loop\n"); }
        ;

while_stmt : WHILE LP condition RP block
           ;

condition : ID relop ID
          | ID relop NUM
          | NUM relop ID
          | NUM relop NUM
          ;

relop : LT
      | GT
      | EQ
      ;

block : LB stmt_list RB
      ;

stmt_list : stmt stmt_list
          | /* empty */
          ;

stmt : ID ASSIGN expr SEMI
     ;

expr : ID
     | NUM
     ;

%%

void yyerror(const char *s)
{
    printf("Invalid while loop\n");
}

int main()
{
    printf("Enter while loop:\n");
    yyparse();
    return 0;
}