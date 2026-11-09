#include<stdio.h>
#include<string.h>
char input[50],stack[50];
int top=-1;
void main()
{
    printf("Enter the string:");
    scanf("%s",input);
    strcat(input,"$");
    printf("\n Stack\t input\t Action\n");
    int i=0;
    int change=1;
    while(change)
    {
        change=0;
        int reduced=0;
        if(top>=1&&stack[top]=='d'&&stack[top-1]=='i')
        {
            stack[top-1]='E';
            top--;
            stack[top+1]='\0';
            printf("%s\t%s\tReduce E->id\n",stack,input+i);
            change=1;
            reduced=1;
        }
        else if(top>=2 && stack[top]=='E' && stack[top-1]=='+'&&stack[top-2]=='E')
        {
            stack[top-2]='E';
            top-=2;
            stack[top+1]='\0';
            printf("%s\t%s\tReduce E->E+E\n",stack,input+i);
            change=1;
            reduced=1;
        }
        else if(top>=2 && stack[top]=='E' && stack[top-1]=='*'&&stack[top-2]=='E')
        {
            stack[top-2]='E';
            top-=2;
            stack[top+1]='\0';
            printf("%s\t%s\tReduce E->E*E\n",stack,input+i);
            change=1;
            reduced=1;
        }
        else if(top>=2 && stack[top]==')' && stack[top-1]=='E'&&stack[top-2]=='(')
        {
            stack[top-2]='E';
            top-=2;
            stack[top+1]='\0';
            printf("%s\t%s\tReduce E->(E)\n",stack,input+i);
            change=1;
            reduced=1;
        }



        if(!reduced && input[i]!='$')
        {
            if(input[i]=='i' && input[i+1]=='d')
            {
                stack[++top]=input[i];
                stack[++top]=input[i+1];
                stack[top+1]='\0';
                printf("%s\t%s\tShift\n",stack,input+i+2) ;
                i+=2;  
                change=1;
            }
            else
            {
                stack[++top]=input[i];
                stack[top+1]='\0';
                printf("%s\t%s\tShift\n",stack,input+i) ;
                i++;
                change=1;
            }
        }
    }


    if(stack[0]=='E'&&top==0)
    {
        printf("\nString Accepted");
    }
    else{
        printf("\nString Rejected");
    }
}