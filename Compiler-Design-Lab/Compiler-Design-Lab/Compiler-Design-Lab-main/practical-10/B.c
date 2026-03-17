%{
#include<stdio.h>
%}

%%

\<[^>]*\>      { printf("HTML Tag: %s\n", yytext); }

.|\n           ;

%%

int yywrap()
{
    return 1;
}

int main()
{
    printf("HTML tags found:\n");
    yylex();
    return 0;
}
