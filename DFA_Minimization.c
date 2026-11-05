#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int transition[100][100];
int nstates,nsymbols,nfinal;
int finalstates[100];
int table[100][100];

int isfinal(int state)
{
    for(int i=0;i<nfinal;i++)
    {
        if(finalstates[i]==state)
        {
            return 1;
        }
    }
    return 0;
}

void initializetable()
{
    for(int i=0;i<nstates;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(isfinal(i)&&!isfinal(j)||isfinal(j)&&!isfinal(i))
            {
                table[i][j]=1;
            }
            else
            {
                table[i][j]=0;
            }
        }
    }
}



void filltable()
{
    int changed=1;
    while(changed)
    {
        changed=0;
        for(int i=0;i<nstates;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(table[i][j]==0)
                {
                    for(int k=0;k<nsymbols;k++)
                    {
                        int p=transition[i][k];
                        int q=transition[j][k];

                        if(p==-1 || q==-1)
                        {
                            continue;
                        }
                        if(p>q)
                        {
                            int temp=p;
                            p=q;
                            q=temp;
                        }
                        if(table[q][p]==1)
                        {
                            table[i][j]=1;
                            changed=1;
                            break;
                        }
                    }
                }
            }
        }
    }
}

void printDFA()
{
    int mergerd[100]={0};
    printf("Equivalent dfa:\n");
    for(int i=0;i<nstates;i++)
    {
        if(!mergerd[i])
        {
            printf("{ %d",i);
            for(int j=i+1;j<nstates;j++)
            {
                if(table[j][i]==0)
                {
                    printf(",%d",j);
                    mergerd[j]=1;
                }
            }
            printf("}\n");
        }
    }

}

int main()
{

    printf("Enter the no.of states: ");
    scanf("%d",&nstates);
    printf("Enter the no.of symbols: ");
    scanf("%d",&nsymbols);
    printf("Enter the transition table (-1 if no transition): ");
    for(int i=0;i<nstates;i++)
    {
        for(int j=0;j<nsymbols;j++)
        {
            scanf("%d",&transition[i][j]);
        }
    }
    printf("Enter the no.of final states:");
    scanf("%d",&nfinal);

    printf("Enter the final states: ");
    for(int i=0;i<nfinal;i++)
    {
        scanf("%d",&finalstates[i]);
    }

    initializetable();
    filltable();
    printDFA();

    return 0;
}