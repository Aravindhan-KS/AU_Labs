%option noyywrap

%{
#include <stdio.h>
#include <ctype.h>

int val[50], vtop=-1;
char op[50]; int otop=-1;

int prec(char c){
    if(c=='+'||c=='-') return 1;
    if(c=='*'||c=='/') return 2;
    return 0;
}

int apply(int a,int b,char c){
    if(c=='+') return a+b;
    if(c=='-') return a-b;
    if(c=='*') return a*b;
    if(c=='/') return a/b;
    return 0;
}

void process(){
    int b=val[vtop--];
    int a=val[vtop--];
    char c=op[otop--];
    val[++vtop]=apply(a,b,c);
}
%}

%%
[0-9]+        { val[++vtop]=atoi(yytext); }

"("           { op[++otop]='('; }

")"           {
                while(op[otop]!='(') process();
                otop--;
              }

[+\-*/]       {
                while(otop!=-1 && prec(op[otop])>=prec(yytext[0]))
                    process();
                op[++otop]=yytext[0];
              }

[ \t]         ;   /* ignore spaces */

\n            {
                while(otop!=-1) process();
                printf("Result = %d\n",val[vtop]);
                return 0;
              }
.             ;
%%

int main(){
    printf("Enter expression: ");
    yylex();
    return 0;
}
