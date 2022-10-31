#include <stdio.h>
#include <stdlib.h>
//最长子列判断思路
//首先记录变化点，一局变化点去判断长度，选出最长的长度，打印这个范围的数据
//但是我觉得使用左边界和右边界好点，因为会出现第一个被我漏掉的情况
int main ()
{
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i = 0; i< n; ++i)
    {
        scanf("%d",&a[i]);
    }
    int mark[n];
    int k = 1;
    mark[0] = -1;
    //记录
    for(int i = 0; i < n ; ++i)
    {
        if(i+1 == n)
        {
            //
           // printf("记录点%d 记录值%d 对应数值%d\n",k,i,a[i]);
            mark[k++] = i;
            break;
        }
        if(a[i]>=a[i+1])
        {
            //printf("记录点%d 记录值%d 对应数值%d\n",k,i,a[i]);
            mark[k++] = i;
        }
    }
  //  printf("\n");
    //观察记录结果
  /*  for(int i = 0; i< k; i++)
    {
        printf("%d 下标 %4d 值 %d",i,mark[i],a[mark[i]]);
        printf("\n");
    }*/
    int max = mark[1]-mark[0];
    int index = 0;
    //计算最长
    for(int i = 0; i<k-1 ; ++i)
    {
        if(mark[i+1]-mark[i]+1 > max)
        {
            max = mark[i+1]-mark[i]+1;
            index = i;
        }
    }
  //  printf("index:%d max:%d",index,max);
  //  printf("\n");
    //打印最长
        for(int i = mark[index]+1; i < mark[index] + max; ++i)
        {
            if(i == mark[index] + max-1)
            {
                printf("%d",a[i]);
            }
            else
                printf("%d ",a[i]);
        }

    return 0;
}
