//需要对移动次数进行处理，如果大于数组长度，则取模
#include <stdio.h>
#include <stdlib.h>

void swap (int *a,int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;

}
typedef int DataType;
void Move_m(DataType *a,int n,int m){
    if(m == 0 || m%n == 0 )//属实是懒了
        return;
    m = m%n;
    int move = n/m;
    for(int i = m; i<n; i++)
        swap(&a[i-m],&a[i]);
    if(n%m != 0)
        for(int i = 0; i < m; i++)
            if(i+m*move < n)
                swap(&a[i-m+n],&a[i+m*move]);
            else
                swap (&a[i-m+n],&a[n-1]);
}
int main()
{
    int n,m;
    scanf("%d %d",&n, &m);
    int a[n];
    for(int i = 0; i <n ; ++i)
    {
        scanf("%d",&a[i]);
    }
Move_m(a,n,m);
    for(int i = 0; i< n ; i++)
    {
        if(i <n-1)
            printf("%d ",a[i]);
        else
            printf("%d",a[i]);
    }
    return 0;
}
