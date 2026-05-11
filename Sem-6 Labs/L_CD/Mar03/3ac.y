%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int yylex();
void yyerror(const char *s);

int temp_count = 1;

char* new_temp() {
    char *temp = (char*)malloc(10);
    sprintf(temp, "t%d", temp_count++);
    return temp;
}
%}

%union {
    char* str;
}

%token <str> ID NUM
%type <str> expr term factor

%%

input:
      expr { printf("Result stored in %s\n", $1); }
      ;

expr:
      expr '+' term
      {
          char* temp = new_temp();
          printf("%s = %s + %s\n", temp, $1, $3);
          $$ = temp;
      }
    | expr '-' term
      {
          char* temp = new_temp();
          printf("%s = %s - %s\n", temp, $1, $3);
          $$ = temp;
      }
    | term { $$ = $1; }
    ;

term:
      term '*' factor
      {
          char* temp = new_temp();
          printf("%s = %s * %s\n", temp, $1, $3);
          $$ = temp;
      }
    | term '/' factor
      {
          char* temp = new_temp();
          printf("%s = %s / %s\n", temp, $1, $3);
          $$ = temp;
      }
    | factor { $$ = $1; }
    ;

factor:
      '(' expr ')' { $$ = $2; }
    | ID           { $$ = $1; }
    | NUM          { $$ = $1; }
    ;

%%

void yyerror(const char *s) {
    printf("Invalid Expression\n");
}

int main() {
    printf("Enter expression:\n");
    yyparse();
    return 0;
}
