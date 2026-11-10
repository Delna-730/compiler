%{
    #include<stdio.h>
    void yyerror(char *s);
    #include<stdlib.h> 
    int yylex();  
%}

%token NUMBER
%left '+' '-'
%left '*' '/'

%%
start:E {printf("Valid Expression");}
E:E'+'E
  |E'-'E
  |E'*'E
  |E'/'E
  |E'%'E
  |NUMBER
  |'('E')'
  ;
%%

void yyerror(char *s)
{
    printf("invalid expression");
}

int main()
{
    printf("Enter the expression:");
    yyparse();
    return 0;
}