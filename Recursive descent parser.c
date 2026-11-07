#include<stdio.h>
char input[50];
int i=0;
int S(),L1(),L();

int S()
{
    if(input[i]=='(')
    {
        i++;
        if(L())
        {
            if(input[i]==')')
            {
                i++;
                return 1;
            }
            else{
                return 0;
            }
        }
        else
        {
            return 0;
        }
    }
    else if(input[i]=='a')
    
        
        {
            i++;
            return 1;
        }

    
    else{
        return 0;
    }
}



int L()
{
    if(S())
    {
        if(L1())
        {
            return 1;
        }else{
            return 0;
        }
    }
    else{
         return 0;}
}

int L1()
{
    if(input[i]==',')
    {
        i++;
        if(S())
        {
            if(L1())
            {
                return 1;
            }
            else{
                return 0;
            }
        }
        else
        {
            return 0;
        }
    }
    return 1;
}

int main()
{   
    printf("Enter the input:");
    scanf("%s",input);
    if(S()&&input[i]=='\0')
    {
        printf("success");
    }
    else{
        printf("failure");
    }
}