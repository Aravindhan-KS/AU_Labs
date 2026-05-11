%{

#include <stdio.h>

#include <stdlib.h>

#include <string.h>



void yyerror(char *s);

int yylex();



int valid = 1;

int offset = 0;



/* Symbol Table */

struct symtab {

    char name[20];

    char type[10];

    int offset;

} table[100];



int count = 0;



int lookup(char *name) {

    for(int i=0;i<count;i++)

        if(strcmp(table[i].name,name)==0)

            return i;

    return -1;

}



void insert(char *name,char *type) {

    if(lookup(name)!=-1) {

        printf("Error: Redeclaration of %s\n",name);

        valid = 0;

        return;

    }

    strcpy(table[count].name,name);

    strcpy(table[count].type,type);

    table[count].offset = offset;



    if(strcmp(type,"int")==0)

        offset += 4;

    else

        offset += 8;



    count++;

}



char* gettype(char *name) {

    int i = lookup(name);

    if(i==-1) {

        printf("Error: Variable %s not declared\n",name);

        valid = 0;

        return "error";

    }

    return table[i].type;

}

%}



%union {

    int ival;

    float fval;

    char *str;

}



%token INT FLOAT FOR

%token <ival> NUM

%token <fval> FNUM

%token <str> ID

%token LT GT LE GE EQ NE



%type <str> type expr decl



%%



program:

        program stmt

        |

        ;



stmt:

        decl ';'

        | assign ';'

        | forstmt

        ;



decl:

        type ID

        {

            insert($2,$1);

            $$ = $1;

        }

        | decl ',' ID

        {

            insert($3,$1);

            $$ = $1;

        }

        ;



type:

        INT   { $$="int"; }

        | FLOAT { $$="float"; }

        ;



assign:

        ID '=' expr

        {

            char *t = gettype($1);

            if(strcmp(t,$3)!=0 && strcmp($3,"error")!=0) {

                printf("Type Mismatch in assignment to %s\n",$1);

                valid = 0;

            }

        }

        ;



expr:

        expr '+' expr   { $$=$1; }

        | expr '-' expr { $$=$1; }

        | expr '*' expr { $$=$1; }

        | expr '/' expr { $$=$1; }

        | expr LT expr  { $$="int"; }

        | expr GT expr  { $$="int"; }

        | expr LE expr  { $$="int"; }

        | expr GE expr  { $$="int"; }

        | expr EQ expr  { $$="int"; }

        | expr NE expr  { $$="int"; }

        | ID            { $$ = gettype($1); }

        | NUM           { $$="int"; }

        | FNUM          { $$="float"; }

        ;



forstmt:

        FOR '(' assign ';' expr ';' assign ')' '{' program '}'

        ;



%%



void yyerror(char *s) {

    valid = 0;

}



int main() {

    printf("Enter Program:\n");

    yyparse();



    if(valid)

        printf("\nValid Program\n");

    else

        printf("\nInvalid Program\n");



    printf("\nSymbol Table:\n");

    printf("Identifier\tType\tOffset\n");

    for(int i=0;i<count;i++)

        printf("%s\t\t%s\t%d\n",

               table[i].name,

               table[i].type,

               table[i].offset);



    return 0;

}
