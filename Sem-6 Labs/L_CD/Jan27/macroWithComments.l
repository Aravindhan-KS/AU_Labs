%option noyywrap
%{

#include <stdio.h>
#include <string.h>
char buffer[1000];

%}

%x FUNC

TYPE    int|float|double|char
ID      [a-zA-Z_][a-zA-Z0-9_]*
WS      [ \t\n]*

%%

"//".*                             ;
"/*"([^*]|\*+[^*/])*\*+"/"         ;

{TYPE}{WS}+{ID}{WS}*\( {
    buffer[0] = '\0';
    strcat(buffer, yytext);
    BEGIN(FUNC);
}

<FUNC>.|\n {
    strcat(buffer, yytext);
    if (yytext[0] == '}') 
    {
        char type[20], fname[50], ptype[20], param[50], expr[100];
        sscanf(buffer, "%s %s", type, fname);
        sscanf(buffer, "%*[^'(](%s %[^)])", ptype, param);
        sscanf(buffer, "%*[^r]return %[^;];", expr);
        printf("#define %s(%s) (%s)\n", fname, param, expr);
        BEGIN(INITIAL);
    }
}

.|\n ;

%%

int main() {
    yylex();
    return 0;
}
