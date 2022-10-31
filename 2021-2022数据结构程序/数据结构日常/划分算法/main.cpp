#include <iostream>

using namespace std;
using DataType = int;

void swap(DataType  &a,DataType  &b)
{
    DataType temp = a;
    a = b;
    b = temp;
}
int cmp(const DataType &a,const DataType &b)
{
    if(a > b)
        return 1;
    else
        return 0;
}
//第一个是 结构体数组的首地址 第二个是该数组的长度 第三个是比较规则 第四个是交换规则 第五个是划分元素的下标 都采取的是函数指针
DataType *divide( DataType *a,const int length,int (*pcmp)(const DataType&,const DataType&),void (*pswap)(DataType  &,DataType  &),const int index)
{
   if(length <1)
   return a;
    if(index <=-1 ||index >= length)//合法性判断
        return a;
    (*pswap)(a[index],a[0]);//让下面的程序不需要更改
    int i,j;//两个游标 采取下标方式
    for( i = 1,j = 1; i< length; ++i)//一个从头至尾遍历
        if((*pcmp)(a[i],a[0]))//按照该函数的标准 判断
            (*pswap)(a[j++],a[i]);//交换这两个元素
    (*pswap)(a[0],a[j-1]);//当最后1~n-1排好后 将第二个指针后移（因为最后有一步++操作）再交换
    return a;//最后返回数组首地址
}
/*5 6 2 4 3 9 1 8 0 7*/
int main()
{
    DataType a[10];
    for(int i = 0; i<10; ++i)
        scanf("%d",&a[i]);
    DataType *p = divide(a,int (sizeof(a)/sizeof(DataType)),cmp,swap,1);//这是为了就是改变数组大小 还能不用更改参数
    for(int i = 0; i< 10; ++i)
        cout<<p[i] <<" ";
    return 0;
}
