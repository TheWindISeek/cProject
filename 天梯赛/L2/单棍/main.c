#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n;
    scanf("%d", &n);
    int a = 0, cnt = 0;
    while (a < n)
    {
        a = a * 10 + 1;
        cnt++;
    }
    while (1)
    {
        printf("%d", a / n);
        a = a % n;
        if (a == 0)
            break;
        a = a * 10 + 1;
        cnt++;
    }
    printf(" %d", cnt);
    return 0;
}
