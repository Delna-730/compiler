%{
    #include "y.tab.h"
%}

%%
int|float|main|return {return key;}
[a-zA-Z_][a-zA-Z0-9_]* {return ID;}
[ \t] ;
[\n] {return 0;}
. {return yytext[0];}
%%

int yywrap()
{
    return 1;
}