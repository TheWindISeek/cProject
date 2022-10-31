#include <stdio.h>
int main ()
{
    int a = 1,b=2;
    printf("%d,%d\n",a,b);
    swap(&a,&b);
    printf("%d,%d",a,b);
    return 0;
}
void swap (int *n,int *m)
{
    int i;
    i = *n;
    *n = *m;
    *m = i;
}
