%{
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int yylex();
void yyerror(char *s);
%}

%union{
    int num;
    char *str;
}

%token SWITCH CASE DEFAULT BREAK
%token <num> NUM
%token <str> ID

%%

stmt :
SWITCH '(' ID ')' '{'
CASE NUM ':' ID ';' BREAK ';'
DEFAULT ':' ID ';'
'}'
{
printf("if %s == %d goto L1\n",$3,$7);
printf("goto L2\n");

printf("L1: %s\n",$9);
printf("goto L3\n");

printf("L2: %s\n",$15);
printf("L3: end\n");
}
;

%%

void yyerror(char *s){
printf("Error\n");
}

int main(){
yyparse();
return 0;
}
