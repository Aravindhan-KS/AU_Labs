%{
#include "y.tab.h"
%}

%%
while          return WHILE;
[a-zA-Z_][a-zA-Z0-9_]*   return ID;
[0-9]+         return NUM;

"<"            return LT;
">"            return GT;
"=="           return EQ;

"="            return ASSIGN;
";"            return SEMI;

"("            return LP;
")"            return RP;
"{"            return LB;
"}"            return RB;

[ \t\n]        ;
.              return yytext[0];
%%