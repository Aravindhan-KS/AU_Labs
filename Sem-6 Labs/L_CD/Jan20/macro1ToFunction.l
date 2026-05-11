%{

#include <stdio.h>

#include <string.h>

%}



id      [a-zA-Z_][a-zA-Z0-9_]*

params  [a-zA-Z_, ]+



%%



#define[ \t]+{id}\({params}\)[ \t]+(.+) {

    char name[50], args[100], body[200];

    sscanf(yytext, "#define %[^ (](%[^)]) %[^ \n]", name, args, body);



    printf("int %s(", name);



    char *token = strtok(args, ",");

    while(token) {

        printf("int %s", token);

        token = strtok(NULL, ",");

        if(token) printf(", ");

    }



    printf(") {\n");

    printf("    return %s;\n", body);

    printf("}\n\n");

}



.|\n    ;



%%



int main() {

    yylex();

    return 0;

}



int yywrap() {

    return 1;

}
