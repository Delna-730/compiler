#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

char f[50], a[50][50];
int n,m=0,z;
void firstT(char c,int x,int y);
void first(char c);
char c;

void first(char c)
{
    if(!isupper(c))
    {
        f[m++]=c;
    }
    for(int k=0;k<n;k++)
    {
        if(a[k][0]==c)
        {
            if(a[k][2]=='#')
            {
                f[m++]='#';
            }
            else if(islower(a[k][2]))
            {
                f[m++]=a[k][2];
            }
            else{
                firstT(a[k][2],k,3);
            }
        }
    }
}

void firstT(char c,int x,int y)
{
    if(!isupper(c))
    {
        f[m++]=c;
    }
    for(int k=0;k<n;k++)
    {
        if(a[k][0]==c)
        {
            if(a[k][2]=='#')
            {
                if(a[x][y]=='\0')
                {
                    f[m++]='#';
                }
                else{
                    firstT(a[x][y],x,y+1);
                }
            }
            else if(islower(a[k][2]))
            {
                f[m++]=a[k][2];
            }
            else{
                firstT(a[k][2],k,3);
            }
        }

    }
}

int main()
{
    printf("enter the no.of productions:");
    scanf("%d",&n);

    printf("Enter the productions:");
    for(int i=0;i<n;i++)
    {
        scanf("%s",a[i]);
    }

    do{
        printf("Enter the element:");
        scanf(" %c",&c);
        m=0;
        strcpy(f,"");

        first(c);

        printf("First(%c):",c);
        for(int i=0;i<m;i++)
        {
            printf("%c ",f[i]);
        }

        printf("Continue(0/1):");
        scanf("%d",&z);
    }while(z==1);

}