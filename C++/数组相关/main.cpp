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
    cout<<"��������ָ������ģ������ͱ��������"<<endl;
    for(int_array *p=ia;p!=ia+3;++p)
    {
        for(int *q = *p;q!=*p+4;++q)
            cout<<*q<<' ';
        cout<<endl;
    }
    cout<<"�������÷�Χfor�����"<<endl;
    for(const auto &i:ia)
    {
        for(auto &k:i)
        {
            cout<<k<<' ';
        }
        cout<<endl;
    }
    cout<<"���������±�����������"<<endl;
    for(int i=0;i!=3;i++)
    {
        for(int k=0;k!=4;k++)
        {
            cout<<ia[i][k]<<' ';
        }
        cout<<endl;
    }
cout<<"������auto�ؼ��ֽ��"<<endl;
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
