%{
#include<stdio.h>

int line = 1;
%}

%%

^        { printf("%d ", line); }

\n       { line++; printf("\n"); }

.        { printf("%s", yytext); }

%%

int yywrap()
{
    return 1;
}

int main()
{
    yylex();
    return 0;
}
