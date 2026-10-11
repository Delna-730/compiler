%{
    #include<stdio.h>
%}

%%
[a-z][a-zA-Z0-9]*@gmail.com {printf("Valid Email: %s\n",yytext);}
.* {printf("Invalid Email: %s\n",yytext);}
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