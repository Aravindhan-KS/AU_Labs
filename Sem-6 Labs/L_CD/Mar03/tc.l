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

"int"           { return INT; }
"float"         { return FLOAT; }
"double"        { return DOUBLE; }
"char"          { return CHAR; }

{LETTER}({LETTER}|{DIGIT})*  { yylval.str = strdup(yytext); return ID; }

{DIGIT}+        { yylval.str = strdup("int"); return NUM_INT; }

{DIGIT}+"."{DIGIT}+  { yylval.str = strdup("float"); return NUM_FLOAT; }

\'[a-zA-Z]\'    { yylval.str = strdup("char"); return CHAR_LITERAL; }

"="             { return '='; }
";"             { return ';'; }

[ \t\n]         ;
.               { printf("Invalid Character\n"); }

%%
