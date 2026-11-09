#include<stdio.h>
#include<string.h>
char stack[50];
int top=-1;
int i=0;
void main()
{
    int change=1;
    printf("Enter the string:");
    char input[40];
    scanf("%s",input);
    strcat(input,"$");
    printf("Stack\tinput\taction\n");

    while(change)
    {
        change=0;
        int reduce=0;
        
        if(top>=2 && stack[top]=='T' && stack[top-1]=='+' && stack[top-2]=='E')
        {
            stack[top-2]='E';
            top-=2;
            stack[top+1]='\0';
            printf("%s\t%s\tReduce E->E+T\n",stack,input+i);
            change=1;
            reduce=1;
        }
        
        else if(top>=2 && stack[top]=='F' && stack[top-1]=='*' && stack[top-2]=='T')
        {
            stack[top-2]='T';
            top-=2;
            stack[top+1]='\0';
            printf("%s\t%s\tReduce T->T*F\n",stack,input+i);
            change=1;
            reduce=1;
        }
        
        else if(top>=2 && stack[top]==')' && stack[top-1]=='E' && stack[top-2]=='(')
        {
            stack[top-2]='F';
            top-=2;
            stack[top+1]='\0';
            printf("%s\t%s\tReduce F->(E)\n",stack,input+i);
            change=1;
            reduce=1;
        }
        else if(top>=1 && stack[top]=='d' && stack[top-1]=='i')
        {
            stack[top-1]='F';
            top--;
            stack[top+1]='\0';
            printf("%s\t%s\tReduce F->id\n",stack,input+i);
            change=1;
            reduce=1;
        }
        else if(top>=0 && stack[top]=='F')
        {
            stack[top]='T';
            stack[top+1]='\0';
            printf("%s\t%s\tReduce T->F\n",stack,input+i);
            change=1;
            reduce=1;
        }
        else if(top>=0 && stack[top]=='E')
        {
            if(input[i] == '$')
            {
                stack[top]='S';
                stack[top+1]='\0';
                printf("%s\t%s\tReduce S->E\n",stack,input+i);
                change=1;
                reduce=1;
            }
            
        }
        else if(top>=0 && stack[top]=='T')
        {
            if(input[i] != '*')
            {
                stack[top]='E';
                stack[top+1]='\0';
                printf("%s\t%s\tReduce E->T\n",stack,input+i);
                change=1;
                reduce=1;
            }
            
        }
        if(!reduce && input[i]!='$')
        {
            if(input[i]=='i' && input[i+1]=='d')
            {
                stack[++top]=input[i];
                stack[++top]=input[i+1];
                printf("%s\t%s\t Shift\n",stack,input+i+2);
                i+=2;
                change=1;
            }
            else{
                stack[++top]=input[i];
                printf("%s\t%s\t Shift\n",stack,input+i);
                i++;
                change=1;
            }
        }
    }
    stack[++top]='$';
    stack[top+1]='\n';

    if(stack[0]=='S'&&top==1)
    {
        printf("String accepted\n");
    }
    else{
        printf("String Rejected");
    }
}