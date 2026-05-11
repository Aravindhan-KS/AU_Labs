%{
#include "y.tab.h"
#include <string.h>
%}

%%
int|float      { yylval.str=strdup(yytext); return TYPE; }
[a-zA-Z][a-zA-Z0-9]*      { return VAR; }
","            { return COMMA; }
";"            { return SEMI; }
[0-9]+[a-zA-Z][a-zA-Z0-9]*  ;

[ \t\n]        ;
.              ;
%%

int yywrap()
{
    return 1;
}