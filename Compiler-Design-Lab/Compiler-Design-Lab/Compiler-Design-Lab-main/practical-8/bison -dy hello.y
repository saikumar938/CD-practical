%{ 
 
#include <stdio.h> 
#include 
<stdlib.h> int 
yylex(void); 
int yyerror(const char *s); 
 
%} 
 
%token HI BYE 
 
%%
program: 
hi bye 
; 
 
hi: 
 
 
bye: 
 
HI { printf("Hello World\n"); } 
; 
 
BYE { printf("Bye World\n"); exit(0); } 
; 