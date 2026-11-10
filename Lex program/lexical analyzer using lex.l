%{
#include<stdio.h>
%}

%x COMMENT

%%
"//".*                  ;
"/*"                    BEGIN(COMMENT);
<COMMENT>"*/"           BEGIN(INITIAL);
<COMMENT>\n             ;
<COMMENT>.              ;

int|float|char|return    {printf("%s Keyword\n",yytext);}
[(){};,]                {printf("%s Special symbol\n",yytext);}
[+\-/*=]                {printf("%s Operator\n",yytext);}
[a-zA-Z_][a-zA-Z0-9_]*  {printf("%s Identifier\n",yytext);}
[0-9]+                  {printf("%s Number\n",yytext);}
[ \t\n]                 ;
.                       ;
%%

int yywrap()
{
    return 1;
}

int main()
{
    FILE *fp;
    fp=fopen("input.txt","r");
    yyin=fp;
    yylex();
    fclose(fp);
    return 0;
}