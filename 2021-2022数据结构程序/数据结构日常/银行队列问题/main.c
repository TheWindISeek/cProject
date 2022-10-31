#include <stdio.h>
#include <stdlib.h>

int main()
{
    //这是一个双重数组遍历的问题，解决的关键在于看待问题的角度
    //如果我从A出发 那么输出很简单 但是判断稍微有点儿复杂
    //从B出发是满足不了A先输出的要求 这样反而更复杂
    /*我的决定 从A出发 利用变量之间的关系去解决这个问题 关键在于双重遍历
    输出应该与程序的逻辑处理分开
    这是很重要的一点，应该意识到这点
    */
    int maxsize;
    scanf("%d",&maxsize);

    int number[maxsize];
        for(int i = 0;i < maxsize;i++)
        scanf("%d",&number[i]);
        for(int i = 0;i< maxsize;i++){
            printf("%d\n",number[i]);
        }
    int a[maxsize];
    int b[maxsize];
    int m,n;
int print[maxsize];
    m = 0,n = 0;
    for(int i = 0;i < maxsize;i++){
        if(number[i]%2!=0)
             a[m++]=number[i];
             else
                b[n++]=number[i];

    }
    int i,j,k;

    i = 0,j =0,k=0;
    for(;i<m&& j< n;i++){
        print[k++]=a[i];
        if(i %2 !=0)
        print[k++]=b[j++];
    }
if(i == m){
    for(;j<n;)
        print[k++]=b[j++];

}else{
while ( i < m)
    print[k++]=a[i++];

}
for(int i = 0; i< maxsize-1;i++){
    printf("%d ",print[i]);
}
printf("%d",print[maxsize-1]);
    return 0;
}
