#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

char buffer[50];
char stack[50];
int top=-1;
char operand[100][100];
int optop=-1,count=0;
char op1[90],op2[50],t[80];
int j=0;
void push(char c)
{
    stack[++top]=c;
}
char pop()
{
    return stack[top--];
}

int precedence(char c)
{
    if(c=='+'||c=='-')
    {
        return 1;
    }
    else if(c=='*'||c=='/')
    {
        return 2;
    }
    else if(c=='^')
    {
        return 3;
    }
    return 0;
}
int main()
{
    char stmt[50];
    printf("Enter the statement:");
    scanf("%s",stmt);

    for(int i=0;stmt[i]!='\0';i++)
    {
        char c=stmt[i];
        if(isalnum(c))
        {
            buffer[j++]=c;
        }
        else if(c=='(')
        {
            push(c);
        }
        else if(c==')')
        {
            while(top!=-1 && stack[top]!='(')
            {
                buffer[j++]=pop();
            }
            if(top!=-1 &&stack[top]=='(')
            {
                pop();
            }
        }
        else
        {
            while(top!=-1&&stack[top]!='('&&precedence(stack[top])>precedence(c))
            {
                buffer[j++]=pop();
            }
            push(c);
        }
    }

    while(top!=-1)
    {
        buffer[j++]=pop();
    }

    buffer[j]='\0';

    printf("\nPostfix=%s",buffer);
    printf("\nIntermediate code:\n");

    for(int i=0;buffer[i]!='\0';i++)
    {
        char c=buffer[i];
        if(isalnum(c))
        {
            operand[++optop][0]=c;
            operand[optop][1]='\0';
        }
        else
        {
            strcpy(op2,operand[optop--]);
            strcpy(op1,operand[optop--]);
            sprintf(t,"t%d",count++);
            printf("%s=%s %c %s\n",t,op1,c,op2);
            strcpy(operand[++optop], t);
        }
    }
}