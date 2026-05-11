%{

#include "y.tab.h"

#include <string.h>

#include <stdlib.h>

%}



%%

"int"           { return INT; }

"float"         { return FLOAT; }

"for"           { return FOR; }



"=="            { return EQ; }

"!="            { return NE; }

"<="            { return LE; }

">="            { return GE; }

"<"             { return LT; }

">"             { return GT; }



[0-9]+"."[0-9]+ { yylval.fval = atof(yytext); return FNUM; }

[0-9]+          { yylval.ival = atoi(yytext); return NUM; }



[a-zA-Z_][a-zA-Z0-9_]* { yylval.str = strdup(yytext); return ID; }



"="             { return '='; }

";"             { return ';'; }

","             { return ','; }

"("             { return '('; }

")"             { return ')'; }

"{"             { return '{'; }

"}"             { return '}'; }

"+"             { return '+'; }

"-"             { return '-'; }

"*"             { return '*'; }

"/"             { return '/'; }



[ \t\n]         ;

.               { return yytext[0]; }



%%



int yywrap() { return 1; }
