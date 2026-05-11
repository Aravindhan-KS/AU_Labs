%{
#include "y.tab.h"
%}

%%
"for"       { return FOR; }

"=="        { return EQ; }
"!="        { return NE; }
"<="        { return LE; }
">="        { return GE; }
"<"         { return LT; }
">"         { return GT; }

[0-9]+      { return NUM; }
[a-zA-Z_][a-zA-Z0-9_]*  { return ID; }

"="         { return '='; }
";"         { return ';'; }
"("         { return '('; }
")"         { return ')'; }
"{"         { return '{'; }
"}"         { return '}'; }
"+"         { return '+'; }
"-"         { return '-'; }
"*"         { return '*'; }
"/"         { return '/'; }

[ \t\n]     ;
.           { return yytext[0]; }

%%

int yywrap() { return 1; }