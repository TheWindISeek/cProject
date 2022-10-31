#include <iostream>
#include <vector>
#include <iterator>
#include <string>
#include <cstring>
using namespace std;

int main()
{
  //  using int_array = int[4];
    typedef int int_array[4];
    int_array ia[3];
    for(int i=0;i!=3;i++)
    {
        for(int k=0;k!=4;k++)
        {
            ia[i][k]=i*3+k;
        }
    }
    cout<<"以下是用指针输出的，用类型别名解决的"<<endl;
    for(int_array *p=ia;p!=ia+3;++p)
    {
        for(int *q = *p;q!=*p+4;++q)
            cout<<*q<<' ';
        cout<<endl;
    }
    cout<<"以下是用范围for输出的"<<endl;
    for(const auto &i:ia)
    {
        for(auto &k:i)
        {
            cout<<k<<' ';
        }
        cout<<endl;
    }
    cout<<"以下是用下标运算符输出的"<<endl;
    for(int i=0;i!=3;i++)
    {
        for(int k=0;k!=4;k++)
        {
            cout<<ia[i][k]<<' ';
        }
        cout<<endl;
    }
cout<<"以下用auto关键字解决"<<endl;
for(auto p=ia;p!=ia+3;p++)
{
    for(auto q=*p;q!=*p+4;q++)
    {
        cout<<*q<<' ';
    }
    cout<<endl;
}

    return 0;
}
