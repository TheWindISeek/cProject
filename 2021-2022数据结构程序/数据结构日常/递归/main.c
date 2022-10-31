#include <stdio.h>
#include <stdlib.h>

void print(long long  n)
{

    if(n == 1)
        printf("1");
    else
    {
        printf("%ld\n",n);
        print(n-1);
    }
}

int main()
{
    print(100000);

    return 0;
}
