%option noyywrap

%{

#include<stdio.h>
char dt[10],ini[20],con[20],inc[20],stmt[100];

%}

op "++"|"--"|"+="|"-="|"*="|"/="
rop ">"|"<"|">="|"<="|"=="|"!="|"&&"|"||"
id [a-zA-Z][a-zA-Z0-9]*
no [0-9]*
pp [\n\t" "]

%%

for\(({id}{pp}{id}=({no}|{id}));({id}{rop}({id}|{no})|{id});({id}{op}{no}?)\)\{(.|\n)*\} {
 int i=0,j,k;
 while(yytext[i] != '(') i++;
 j = ++i; k=0;
 while(yytext[j] != ' '){
 dt[k++] = yytext[j++];
 }
 while(yytext[j] == ' '){
 j++;
 }
 k=0;
 while(yytext[j] != ';'){
 ini[k++] = yytext[j++];
 }
 j++;
 k=0;
 while(yytext[j] != ';'){
 con[k++] = yytext[j++];
 }
 j++;
 k=0;
 while(yytext[j] != ')'){
 inc[k++] = yytext[j++];
 }
 while(yytext[j] != '{'){
 j++;
 }
 j++;
 k=0;
 while(yytext[j] != '}'){
 stmt[k++] = yytext[j++];

 }

 printf("%s %s;\n",dt,ini);
 printf("L1 : if(%s) {",con);
 printf("%s",stmt);
 printf("%s;\ngoto L1\n}",inc);

}

%%

int main(){
yyin = fopen("codefor.txt","r");
yylex();
return 0;
}