%{
#include <stdio.h>
#include <ctype.h>
char stack[100];
int top = -1;
void push(char);
char pop();
int precedence(char);
%}

%%

[a-zA-Z0-9]  { printf("%s ", yytext); }

[+\-*/]      {
                while (top != -1 && precedence(stack[top]) >= precedence(yytext[0]))
                    printf("%c ", pop());
                push(yytext[0]);
             }
"("          { push('('); }
")"          {
                while (stack[top] != '(')
                    printf("%c ", pop());
                pop();   /* remove '(' */
             }
\n           {
                while (top != -1)
                    printf("%c ", pop());
                printf("\n");
                return 0;
             }
[ \t]        ;

%%
int precedence(char op)
{
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

void push(char c)
{
    stack[++top] = c;
}

char pop()
{
    return stack[top--];
}

int yywrap() { return 1; }

int main()
{
    printf("Enter infix expression: ");
    yylex();
    return 0;
}
