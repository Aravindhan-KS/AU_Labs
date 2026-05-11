%{
//without operator precedence
#include <stdio.h>
#include <stdlib.h>
int result = 0;
int current = 0;
char last_op = '+';
void apply_op(int num);
%}

%%
[0-9]+   {
            int val = atoi(yytext);
            apply_op(val);
         }
[+\-*/]  { last_op = yytext[0]; }
\n       { printf("Result = %d\n", result); return 0; }
[ \t]    ;
.        ;
%%

void apply_op(int num)
{
    if (last_op == '+')
        result += num;
    else if (last_op == '-')
        result -= num;
    else if (last_op == '*')
        result *= num;
    else if (last_op == '/')
        result /= num;
}

int yywrap() { return 1; }

int main()
{
    printf("Enter expression: ");
    yylex();
    return 0;
}
