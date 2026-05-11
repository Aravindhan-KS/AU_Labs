%{
#include "y.tab.h"
%}

%%
[a-z]      { yylval = yytext[0]; return ID; }
[ \t]      ;
\n         return '\n';
.          return yytext[0];
%%

int yywrap()
{
    return 1;
}
