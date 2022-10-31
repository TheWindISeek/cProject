#include<stdio.h>
#include <string.h>
int main ()
{

    char name[3][10]= {"tom", "jack", "rose"};
    char s[10];
    int num[3]= {0};
    printf("请输入人数");
    int n;
    scanf("%d",&n);
    int i;
    for(i=0; i<n; i++)
    {
        printf("请输入票");
        scanf("%s",s);
        if(strcmp(s,name[0])==0)
            num[0]++;
        else if(strcmp(s,name[1])==0)
            num[1]++;
        else   if(strcmp(s,name[2])==0)
            num[2]++;
    }
    for(i=0;i<3;i++)
    {
        printf("%s:%d\n",name[i],num[i]);
    }
    int ret=0;
    for(i=0;i<3;i++)
    {
        if(num[ret]<num[i])
            ret=i;
    }
    printf("最终的获胜者是");
    printf("%s:%d",name[ret],num[ret]);

    return 0;

}
