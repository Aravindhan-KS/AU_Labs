%option noyywrap

%{
#include<stdio.h>
#include<stdlib.h>
#include "y.tab.h"
extern int yylval;
%}

%%
[-]*[0-9]+ {yylval=atoi(yytext); return INTEGER;}
[-+*/] {return *yytext;}
[\n] {return *yytext;}
[\t] ;
%%
