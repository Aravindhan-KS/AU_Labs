%{
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int yylex();
void yyerror(char *s);

int t = 1;
char temp[10];

char* newtemp(){
sprintf(temp,"t%d",t++);
return strdup(temp);
}
%}

%union{
char *str;
}

%token <str> ID

%%

stmt :
ID '[' ID ']' '=' ID '[' ID ']'
{
char *t1 = newtemp();
char *t2 = newtemp();

printf("\nAnswer:\n");
printf("%s = %s * 4\n",t1,$3);
printf("%s = %s * 4\n",t2,$8);
printf("t3 = %s[%s]\n",$6,t2);
printf("%s[%s] = t3\n",$1,t1);
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
