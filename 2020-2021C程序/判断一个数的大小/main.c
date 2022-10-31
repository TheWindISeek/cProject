#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int JS (int n)
{
    int m;
    for(m=1;;m++)
    {
        if(n<pow(10,m))
            return m;
    }
}
