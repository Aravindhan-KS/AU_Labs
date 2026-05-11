%option noyywrap

%{

#include<stdio.h>

#include<string.h>

char *init,*cond;

char stmts[100]="",incr[100]="";

int incrLength=0;

%}

%x whileLoop

%x stmt

%%

[^;]*;"while(" {

 yytext[yyleng-7]='\0';

 init=strdup(yytext);

 BEGIN whileLoop;

 }

<whileLoop>[^){]*")" {

 yytext[yyleng-1]='\0';

 cond=strdup(yytext);

 }

<whileLoop>"{" { BEGIN stmt; }

<stmt>[^;]*";" {

 incr[0]=' ';

 strcat(stmts,incr);

 strcpy(incr,yytext);

 incrLength=yyleng;

 }

<stmt>"}" {

 incr[0]=' ';

 incr[incrLength-1]='\0';

 printf("for(%s%s;%s){\n%s\n}",init,cond,incr,stmts);

 BEGIN INITIAL;

 }

%%

int main(){

yyin=fopen("codewhile.txt","r");

yylex();

return 0;

}
