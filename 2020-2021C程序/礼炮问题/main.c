
#include<stdio.h>
int main()
{
   int i=0,a=5,b=6,c=7,n=21,count=0;
    for(i=0;i<=100;i++)       //计算5s的大炮范围内的听到响声
    {
         if(i%a==0||i%b==0||i%c==0)
         count++;
    }
    for(i=100;i<=120;i++)     // 计算6s的大炮范围内的听到响声
    {
         if(i%b==0||i%c==0)
         count++;
    }
    for(i=120;i<=140;i++)     // 计算7s的大炮范围内的听到响声
    {
         if(i%c==0)
         count++;
    }
    printf("n=%d",count);
    return 0;
}
