#include <iostream>

using namespace std;

int main()
{
    int sum =0,value = 0;
    //cin 不同于scanf的使用
    while(std::cin>> value )
    {
        sum+=value;
        cout<<"sum is :"<<sum<<endl;
    }
    //关于无符号和有符号包含的类型转换,以及可能会出现的问题
    unsigned u=10;
    int i=-42;
    cout<<i+i<<endl;
    cout<<u+i<<endl;
    //错误，会出现死循环，这是因为符号与无符号的区别
    for(u=10;u>=0;u--)
    {
        cout<<u<<endl;
    }
    return 0;
}
