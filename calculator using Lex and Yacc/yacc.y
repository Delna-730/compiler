%{
#include<stdio.h>
#include<string.h>
void yyerror(char *s);
int yylex();    
%}

%token NUMBER
%left '+' '-'
%left '*' '/'


%%
start:E {printf("Result=%d",$$);};
E:E'+'E {$$=$1+$3;}
  |E'*'E {$$=$1*$3;}
  |E'/'E {$$=$1/$3;}
  |E'-'E {$$=$1-$3;}
  |'('E')' {$$=$2;}
  |NUMBER {$$=$1;}
  ;
%%

void yyerror(char *s)
{
    printf("Invalid");
}

int main()
{
    printf("Enter the expression");
    yyparse();
    return 0;
}