
%{
#include <stdio.h>

int v = 0, c = 0;
%}

%%
[AEIOUaeiou]    { v++; }
[A-Za-z]        { c++; }
%%

int yywrap()
{
    return 1;
}

int main()
{
    printf("Enter the string:");
    yylex();

    printf("Vowels = %d\n", v);
    printf("Consonants = %d\n", c);

    return 0;
}
