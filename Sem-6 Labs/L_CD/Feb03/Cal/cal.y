%{
#include<stdio.h>
#include<stdlib.h>
int result;
int yylex(void);
void yyerror(char* s);
%}

%token INTEGER

%%

A: A E '\n' {printf("%d\n",$2);}
 | {}
;

E: E '-' F {$$=$1-$3;}
 | E '+' F {$$=$1+$3;}
 | F {$$=$1;}
;

F: F '*' G {$$=$1*$3;}
 | G {$$=$1;}
;

G: G '/' H {$$=$1/$3;}
 | H {$$=$1;}
;

H: INTEGER {$$=$1;}
;

%%

int main(){
printf("Enter the expression:");
yyparse();
return 0;
}

void yyerror(char* msg){
fprintf(stderr,"Error:%s\n",msg);
exit(1);
}
