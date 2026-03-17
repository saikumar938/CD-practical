%{
#include<stdio.h>

int vowels = 0;
int consonants = 0;
%}

%%

[aeiouAEIOU]      { vowels++; }

[a-zA-Z]          { consonants++; }

\n                { 
                    printf("\nNumber of vowels: %d\n", vowels);
                    printf("Number of consonants: %d\n", consonants);
                  }

.                 ;

%%

int yywrap() {
    return 1;
}

int main() {
    printf("Enter a string:\n");
    yylex();
    return 0;
}
