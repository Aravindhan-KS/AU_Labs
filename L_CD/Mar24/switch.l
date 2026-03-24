%{
#include "y.tab.h"
#include <string.h>
%}

%%
"switch"      return SWITCH;
"case"        return CASE;
"default"     return DEFAULT;
"break"       return BREAK;

[0-9]+        { yylval.num = atoi(yytext); return NUM; }

[a-zA-Z][a-zA-Z0-9]* {
                    yylval.str = strdup(yytext);
                    return ID;
                   }

":"           return ':';
";"           return ';';
"{"           return '{';
"}"           return '}';
"("           return '(';
")"           return ')';

[ \t\n]       ;
.             return yytext[0];
%%

int yywrap(){
return 1;
}
