#include <stdio.h>
main()
{
    int num;
    printf("Enter number:");
    scanf("%d",&num);
    printn(num);
    printf("\n");
}
printn(int n)
{
    if(0<=n&&n<=9)
        printf("%d",n);
    else
    {
        printf("%d",n%10);
        printn(n/10);
    }
}
