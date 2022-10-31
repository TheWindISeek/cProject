#include<stdio.h>
int a[14];
int main()
{
    int i,n,j=1; /*j:数组(盒子)下标，初始时为1号元素*/
    printf("The original order of cards is:");
    for(i=1; i<=13; i++) /*i:要放入盒子中的牌的序号*/
    {
        n=1;
        do
        {
            if(j>13) j=1; /*由于盒子构成一个圈，j超过最后一个元素则指向1号元素*/
            if(a[j]) j++; /*跳过非空的盒子，不进行计数*/
            else
            {
                if(n==i) a[j]=i; /*若数到第i个空盒子，则将牌放入空盒中*/
                j++;
                n++; /*对空盒计数，数组下标指向下一个盒子*/
            }
        }
        while(n<=i);  /*控制空盒计数为i*/
    }
    for(i=1; i<=13; i++) /*输出牌的排列顺序*/
        printf("%d ",a[i]);
    printf("\n");
}
