#include<stdio.h>
int main()
{
    int n,i;
    int j,k;
    int arr[100];
    printf("输入数组的长度");//提示信息
    scanf("%d",&n);
    for(i=0; i<n; i++) //为数组赋值
    {
        scanf("%d",&arr[i]);
    }
    int temp, i, j;
    for (i = 0; i < n-1; i++)  //进行9次比较
    {
        for (j = 0; j < n - i - 1; j++)//在每次中进行10-i-1次比较
        {
            if (a[j] > a[j + 1])      //按升序排序，降序用<
            {
                temp = a[j + 1];      //交换相邻的两个元素
                a[j + 1] = a[j];
                a[j] = temp;
            }
        }
    }

    printf("排序后结果为:\n");  //输出排序后的结果
    for(i=0; i<n; i++) //打印数组
    {
        printf("%d\t",arr[i]);
    }
    return 0;
}

