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
//��һ���� �ṹ��������׵�ַ �ڶ����Ǹ�����ĳ��� �������ǱȽϹ��� ���ĸ��ǽ������� ������ǻ���Ԫ�ص��±� ����ȡ���Ǻ���ָ��
DataType *divide( DataType *a,const int length,int (*pcmp)(const DataType&,const DataType&),void (*pswap)(DataType  &,DataType  &),const int index)
{
   if(length <1)
   return a;
    if(index <=-1 ||index >= length)//�Ϸ����ж�
        return a;
    (*pswap)(a[index],a[0]);//������ĳ�����Ҫ����
    int i,j;//�����α� ��ȡ�±귽ʽ
    for( i = 1,j = 1; i< length; ++i)//һ����ͷ��β����
        if((*pcmp)(a[i],a[0]))//���ոú����ı�׼ �ж�
            (*pswap)(a[j++],a[i]);//����������Ԫ��
    (*pswap)(a[0],a[j-1]);//�����1~n-1�źú� ���ڶ���ָ����ƣ���Ϊ�����һ��++�������ٽ���
    return a;//��󷵻������׵�ַ
}
/*5 6 2 4 3 9 1 8 0 7*/
int main()
{
    DataType a[10];
    for(int i = 0; i<10; ++i)
        scanf("%d",&a[i]);
    DataType *p = divide(a,int (sizeof(a)/sizeof(DataType)),cmp,swap,1);//����Ϊ�˾��Ǹı������С ���ܲ��ø��Ĳ���
    for(int i = 0; i< 10; ++i)
        cout<<p[i] <<" ";
    return 0;
}
