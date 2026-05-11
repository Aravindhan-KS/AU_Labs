%{
#include "y.tab.h"
%}
%%
[0-9]           { yylval = yytext[0]; return NUM; }
[+\-*/()]       { return yytext[0]; }
[\t ]+          ;
\n              { return '\n'; }
%%
int yywrap() { return 1; }