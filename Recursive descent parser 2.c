#include<stdio.h>
char input[50];
int i=0;
int E(),E1(),T(),T1(),F();
int E()
{
    if(T())
    {
        if(E1())
        {
            return 1;
        }
        else {
            return 0;
        }
    }
    else
    {
        return 0;
    }
}

int E1()
{
    if(input[i]=='+')
    {
        i++;
        if(T())
        {
            if(E1())
            {
                return 1;
            }
            else{
                return 0;}
        }
        else{
                return 0;}

    }else{
        return 1;
    }
}

int T()
{
    if(F())
    {
        if(T1())
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
}

int T1()
{
    if(input[i]=='*')
    {
        i++;
        if(F())
        {
            if(T1())
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        else
        {
            return 0;
        }
    }
    else
    {
        return 1;
    }
}

int F()
{
    if(input[i]=='(')
    {
        i++;
        if(E())
        {
            if(input[i]==')')
            {
                i++;
                return 1;
            }
            else 
            {
                return 0;
            }
        }
        else
        {
            return 0;
        }
    }
    else if(input[i]=='i' && input[i+1]=='d')
    {
        i+=2;
        return 1;
    }
    else {
        return 0;
    }
}

int main()
{   
    printf("Enter the input:");
    scanf("%s",input);
    if(E()&&input[i]=='\0')
    {
        printf("success");
    }
    else{
        printf("failure");
    }
}