#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

char stack[100];
int top=-1;

void push(char c)
{
    stack[++top]=c;
}

int pop()
{
    return stack[top--];
}

int precedence(char c)
{
    if(c=='+' || c=='-')
    {
        return 1;
    }
    if(c=='*' || c=='/' )
    {
        return 2;    
    }
    if(c=='^')
    {
        return 3;
    }
}

int main()
{
    char stmt[30],buffer[30],operand[30][30];
    int count=0,j=0;
    int optop=-1;
    char op1[30],op2[30],t[30];
    char c;

    printf("Enter the statement:");
    scanf("%s",stmt);

    for(int i=0;stmt[i]!='\0';i++)
    {
        c=stmt[i];

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
            if(top!=-1 && stack[top]=='(')
            {
                pop();
            }
        }
        else{
            while(top!=-1 && stack[top]!='(' && precedence(stack[top])>=precedence(c))
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

    printf("Postfix Notation : %s\n",buffer);

    printf("Intermediate Code\n");

    for(int i=0;buffer[i]!='\0';i++)
    {
        c=buffer[i];
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
            printf("%s = %s %c %s\n",t,op1,c,op2);
            strcpy(operand[++optop], t);
        }
    }

    return 0;
}