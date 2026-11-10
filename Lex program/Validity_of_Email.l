%{
#include<stdio.h>
#include<string.h>
%}

%%
[a-zA-Z0-9_]+@[a-zA-Z0-9]+\.[a-zA-Z][a-zA-z]+ {printf("valid");}
.* {printf("Invalid");}
%%

int yywrap()
{
    return 1;
}

int main()
{
    printf("Enter the string:");
    yylex();
    return 0;
}