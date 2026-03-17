%{
#include<stdio.h>
%}

%%

[0-9]+      { printf("Number: %s\n", yytext); }

.|\n        ;

%%

int yywrap()
{
    return 1;
}

int main()
{
    printf("Numbers in the file are:\n");
    yylex();
    return 0;
}
