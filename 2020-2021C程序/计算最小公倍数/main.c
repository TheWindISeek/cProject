#include <stdio.h>
#include <stdlib.h>

int MinCommonMultiple(int a, int b)
{
    int n,min = a>b?b:a;
    for(n=min;n>=1;n--)
    {
        if(a%n==0&&b%n==0)
        return a*b/n;
    }
}

