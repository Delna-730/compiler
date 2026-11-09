#include<stdio.h>
#include<string.h>
#include<ctype.h>

char keyword[][10]={"int","return"};
char token[50];

int isKeyword(char str[])
{
    for(int i=0;i<10;i++)
    {
        if(strcmp(keyword[i],str)==0)
        {
            return 1;
        }
    }
    return 0;
}

void main()
{
    int i=0;
    FILE *fp=fopen("input.txt","r");
    char c=fgetc(fp);
    while(c!=EOF)
    {
        if(c=='/')
        {
            c=fgetc(fp);
            if(c=='/')
            {
                while(c!='\n'&&c!=EOF)
                {
                    c=fgetc(fp);
                }
            }
            else if (c == '*')
            {
                c = fgetc(fp);

                while (c != EOF)
                {
                    if (c == '*')
                    {
                        c = fgetc(fp);

                        if (c == '/')
                            break;
                        
                    }
                    else
                    {
                        c = fgetc(fp);
                    }
                }
            }
            
        }
        else if(isalpha(c)&&c!=' '&&c!='\n')
        {
            i=0;
            while(isalpha(c)&&c!=' '&&c!='\n')
            {
                token[i++]=c;
                c=fgetc(fp);
            }
            token[i]='\0';
            if(isKeyword(token))
            {
                printf("%s Keyword\n",token);
            }
            else{
                printf("%s Identifier\n",token);
            }
        }
        else if(isdigit(c)&&c!=' '&&c!='\n')
        {
            i=0;
            while(isdigit(c)&&c!=' '&&c!='\n')
            {
                token[i++]=c;
                c=fgetc(fp);
            }
            token[i]='\0';
            printf("%s Number\n",token);
        }
        else if(c=='+'||c=='-'||c=='*'||c=='%'||c=='='||c=='/')
        {
            printf("%c Operator\n",c);
            c=fgetc(fp);
        }
        else if(c=='('||c==')'||c=='{'||c=='}'||c==','||c==';')
        {
            printf("%c Special symbol\n",c);
            c=fgetc(fp);
        }
        else{
            c=fgetc(fp);
        }
    }
}