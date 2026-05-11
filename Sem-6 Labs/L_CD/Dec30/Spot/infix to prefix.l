%option noyywrap

%{
//infix to prefix
#include <stdio.h>
char stack[50];
int top=-1;

int prec(char c){
 if(c=='+'||c=='-') return 1;
 if(c=='*'||c=='/') return 2;
 return 0;
}
void push(char c)
{   stack[++top]=c; }
char pop()
{   return stack[top--]; }

%}
%%
[\+\-\*/]    { printf("%s",yytext); }
[a-zA-Z0-9]     {  
                //while(top!=-1 && prec(stack[top])>=prec(yytext[0]))
                while(top!=-1)
                    printf("%c",pop());
                push(yytext[0]);
            }
"("         { push('('); }
")"         {
              while(stack[top]!='(')
                printf("%c",pop());
              pop();
            }
\n          {
              while(top!=-1)
                printf("%c",pop());
              printf("\n"); 
              return 0;
            }
[ \t]       ;
.           ;
%%

int main(){
 printf("Enter infix: ");
 yylex();
 return 0;
}

