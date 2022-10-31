#include <stdio.h>
int *p;
int SC (void);//输入长度
int SR (int a,int b[]);//输入数据和所要求的范围
int SWAP (int,int,int b[],int num[]);  //选择法排序
void SK(int a,int b[]);
void main ()
{
    int a=SC();
    int b[a];
    if(SR(a,b))
      SK(a,b);
}
int SC(void)
{
    int a;
    do
    {
        printf("请输入长度\n");
        scanf("%d",&a);
    }
    while (a<=0);
    return a;
}
int SR(int a,int b[])
{
    int i=0;
    printf("请输入数据(以空格为分界)\n");
   do{
     scanf(" %d",&b[i]);
     i++;
   }while (i<a);
}
void SK (int a,int b[])
{
    int q,w;
    printf("请输入您想要数据的范围(两个数字 比如1/2)\n");
AS:
    fflush(stdin);
    scanf("%d/%d",&q,&w);
    if(q<=0||w<=0||q>a||w>a)
    {
        printf("请重新输入\n");
        goto AS;
    }
    int min = q<w?q:w;
    int max = q>w?q:w;
    int num[a];
    int k = SWAP(min-1,max,b,num);
    for(int k=0;k<*p;k++)
    {printf("第%d位上的最大\n",num[k]+1);
    printf("值为%d\n",b[num[k]]);}
    printf("以下为排好的数据\n");
    if(SWAP(0,a,b,num))
        for(int k=0; k<a; k++)
            printf("第%d个%2d\n",k+1,b[k]);
}
int SWAP (int min,int max,int b[],int num[])
{
    int i,j,k,temp;
   static int c=0;
   int a=0;
   p=&a;
    for(i=min; i<max-1; i++)
    {
        k=i;
        for(j=i+1; j<max; j++)
        {
            if(b[j]>b[k])
                k=j;
        }
        for(j=i+1; j<max; j++)
            if(b[k]==b[j])
        {
            num[0]=j;
            num++;
            a++;
        }
        if(c<1)
        {
            c++;
            return k;
        }
        if(k!=i)
        {
            temp = b[k];
            b[k]=b[i];
            b[i]=temp;
        }
    }
    return 1;
}
