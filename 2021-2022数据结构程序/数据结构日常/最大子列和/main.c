#include <stdio.h>
//全是负数 输出第一个元素和最后一个元素 最大和为 0
//如果有多个最大和相同 输出最小的那个
int main ()
{
    int n;
    scanf("%d", &n);//我现在需要的是now对应的那个begin 那个数值而不是那些其他的玩意
    int max = 0,now = 0,begin,end,temp = 0;
    int data[n],mark = 0;
    for(int i = 0; i < n ; ++i)
    {
        scanf("%d", &data[i]);
        if(data[i] >= 0)
            mark++;
    }
    if(mark)
    {
        for(int i = 0; i < n ; ++i)
        {
            now += data[i];
            if(now < 0)
            {
                now = 0;
                if( i+1 < n )
                    temp = i+1;
            }
            if(max < now)
            {
                begin = temp;
                max = now;
                end = i;
            }
        }
        if(max == 0)
            printf("0 0 0");
        else
            printf("%d %d %d",max,data[begin],data[end]);
    }
    else
        printf("%d %d %d",max,data[0],data[n-1]);
    return 0;
}
