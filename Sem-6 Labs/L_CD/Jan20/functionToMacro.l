%{
#include <stdio.h>
#include <string.h>
%}

TYPE    (int|float|double|char|void)
ID      [a-zA-Z_][a-zA-Z0-9_]*
WS      [ \t]*

%%

{TYPE}{WS}+{ID}{WS}*\(([^)]*)\){WS}*\{{WS}*return{WS}+([^;]+);{WS}*\} {
    char rettype[50], fname[50], args[200], body[200];
    sscanf(yytext, "%s %[^ (](%[^)]) { return %[^;]; }",rettype, fname, args, body);
    printf("#define %s(%s) (%s)\n", fname, args, body);
}

.|\n    { printf("%s", yytext); }

%%

int main(void) {
    yylex();
    return 0;
}

int yywrap(void) {
    return 1;
}
