%{
#include "y.tab.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
%}

%option noyywrap

DIGIT   [0-9]
LETTER  [a-zA-Z]

%%

{LETTER}({LETTER}|{DIGIT})*   { yylval.str = strdup(yytext); return ID; }
{DIGIT}+                     { yylval.str = strdup(yytext); return NUM; }

"+"     { return '+'; }
"-"     { return '-'; }
"*"     { return '*'; }
"/"     { return '/'; }
"("     { return '('; }
")"     { return ')'; }

[ \t\n] ;
.       { printf("Invalid character\n"); }

%%
