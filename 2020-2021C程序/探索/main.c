#include <stdio.h>
#include <stdlib.h>
float stu_ave(int *p,int n) //接收列地址，和元素个数
{
  int i;
  float sum = 0;
  for(i = 0 ; i < n ; i++)
  sum += p[i];//p[i]  p是一个列地址 把二维看成一个一维数组所以就是P[i] 来进行遍历每个元素
  return sum/n;
  }
int *stu_find(int (*p)[4],int num) //传过来一个行地址，用指针数组接收（为啥用数组指针接收呢因为例：）
       // int  (*p)[4]; p++；指针移动会走[4]列相当于二维数组的首地址a+1也是跳转到下一行，所以呢就用数组指针接收行地址
{
   return *(p+num);//利用了*来进行降级操作将行指针降级成列地址return给指针函数
}
void stu_print(int *p)//显示选择的行的列元素的值
{
  int i;
  for(i = 0 ; i < 4; i++)//列长度到4
  printf("%d ",p[i]);
  printf("\n");
}
int main()
{
     int z;
    int s[3]= {1,2,3};
    int k;
    int a = 0;
    int b;
    printf("%p\n",&z);
    printf("%p\n",&s[2]);
    printf("%p\n",&s[1]);
    printf("%p\n",s);

    printf("%p\n",&k);
    printf("%p\n",&a);
    printf("%p\n",&b);

    int *p;
    int *pp;
    char c;
    long l;
    double d;
    printf("%p\n",&p);
    printf("%p\n",&pp);
    printf("%p\n",&c);
    printf("%p\n",&l);
    printf("%p\n",&d);
printf("\n%d\n",sizeof(*p));
printf("\n%d\n",sizeof(*pp));

    p++;
    printf("\n%p\n",p);
    p++;
    printf("%p\n",p);

    printf("%d\n",k);
    printf("%d",a);
    return 0;
  /*int num;
  int a[3][4] = {{89,98,34,21},{85,56,36,99},{34,86,59,73}};
  int *ret;
  printf("%f\n",stu_ave(*a,3*4));//实参的地址要和函数的形参类型匹配（如果要想遍历数组中的每个元素要传入数组的元素个数）
  printf("Please enter the NO([0,2]):");
  scanf("%d",&num);*/
  /*if error*/
 /* ret = stu_find(a,num); //传过去一个行指针(传过去后返回的时候会降级)，和你选择要显示的学生成绩，函数会返回一个指针并给了ret
  stu_print(ret);*/
  return 0;
}
