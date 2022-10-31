#include <stdio.h>
#include <stdlib.h>
void hanio (int ,char ,char ,char );
int main()
{int n;
scanf("%d",&n);

    hanio(n,'a','b','c');
    return 0;
}
void hanio (int n,char a,char b,char c)
{
    if(n==1)
    {
        printf("%c-->%c\n",a,c);

    }
    else
    {
     hanio(n-1,a,c,b);
    printf("%c-->%c\n",a,c);
    hanio(n-1,b,a,c);
    }
}
