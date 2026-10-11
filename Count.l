
%{
#include <stdio.h>

int l = 0, w = 0, c = 0;
%}

%%
\n              { l++; c++; }
\t              { c++; }
[a-zA-Z0-9]+    { w++; c += yyleng; }
.               { c++; }
%%

int yywrap()
{
    return 1;
}

int main()
{
    printf("Enter the string:\n");
    yylex();

    printf("\nlines = %d", l + 1);
    printf("\nwords = %d", w);
    printf("\ncharacters = %d\n", c);

    return 0;
}
