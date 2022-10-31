#include <stdlib.h>
#include<stdio.h>
#include <math.h>
/*突然想到直接对那个数求余不就得了，算了，都写完了*/
int y (int x,int i)
{
    int y;
    y = x/(int)(pow(10,i-1)+0.5)%10;
    return y;
}
int JS (int n)
{
    int m;
    for(m=1;; m++)
    {
        if(n<pow(10,m))
            return m;
    }
}
int pr (int num[])
{
    int i;
    for(i=0; i<10; i++)
    {
        if(num[i]>=2)
            return 1;
    }
    return 0;
}
int main()
{

    int n;
    printf("Input n:\n");
    scanf("%d",&n);
    int num[10]= {0};
    int k;
    int m;
    m=JS(n);
    for(k=1; k<=m; k++)
    {
        switch(y(n,k))
        {
        case 0:
            num[0]++;
            break;
        case 1:
            num[1]++;
            break;
        case 2:
            num[2]++;
            break;
        case 3:
            num[3]++;
            break;
        case 4:
            num[4]++;
            break;
        case 5:
            num[5]++;
            break;
        case 6:
            num[6]++;
            break;
        case 7:
            num[7]++;
            break;
        case 8:
            num[8]++;
            break;
        case 9:
            num[9]++;
            break;
        }

    }
    if(pr(num))
        printf("Repeated digit!\n");
    else
        printf("No repeated digit!\n");
    return 0;
}
