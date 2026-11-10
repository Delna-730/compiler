%{
    #include<stdio.h>
    #include<stdlib.h>
    void yyerror(char *s);
    int yylex();
%}

%token ID key

%%
start: ID {printf("valid");}
;
%%

void yyerror(char *s)
{
    printf("Invalid");
}
int main()
{
    printf("Enter the word:");
    yyparse();
    return 0;
}