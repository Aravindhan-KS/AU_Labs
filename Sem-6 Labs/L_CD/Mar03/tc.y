%{
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int yylex();
void yyerror(const char *s);

char declared_type[20];
%}

%union {
    char* str;
}

%token <str> ID NUM_INT NUM_FLOAT CHAR_LITERAL
%token INT FLOAT DOUBLE CHAR

%type <str> value

%%

program:
        program stmt
      | stmt
      ;

stmt:
      datatype ID '=' value ';'
      {
          if(strcmp(declared_type, $4) == 0)
              printf("Valid Assignment\n");
          else
              printf("Invalid Assignment\n");
      }
      ;

datatype:
      INT     { strcpy(declared_type, "int"); }
    | FLOAT   { strcpy(declared_type, "float"); }
    | DOUBLE  { strcpy(declared_type, "float"); }
    | CHAR    { strcpy(declared_type, "char"); }
    ;

value:
      NUM_INT       { $$ = $1; }
    | NUM_FLOAT     { $$ = $1; }
    | CHAR_LITERAL  { $$ = $1; }
    ;

%%

void yyerror(const char *s) {
    printf("Invalid Statement\n");
}

int main() {
    printf("Enter declarations:\n");
    yyparse();
    return 0;
}
