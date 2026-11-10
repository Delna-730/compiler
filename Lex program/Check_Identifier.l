%{
    #include<stdio.h>
%}

%%
[a-zA-Z][a-zA-Z0-9_]* {printf("Identifier %s\n",yytext);}
.* {printf("Not Identifier: %s\n",yytext);}
%%

int main()
{
    printf("Enter the string: ");
    yylex();
    return 0;
}

int yywrap()
{
    return 1;
}