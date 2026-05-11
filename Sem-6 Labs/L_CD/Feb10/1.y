%{
#include <stdio.h>
#include <stdlib.h>

int yylex();
void yyerror(const char *s);

%}

%token NUM
%%
stmt : expr '\n' { printf("Valid Expression\n"); exit(0); }
;
expr : expr '+' term
| expr '-' term
| term
;
term : term '*' factor
| term '/' factor
| factor
;
factor : NUM
| '(' expr ')'
;
%%
void yyerror(const char *s) {
printf("Invalid Expression\n");
exit(0);
}
int main() {printf("Enter expression: ");
yyparse();
return 0;
}