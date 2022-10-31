#include <iostream>

using namespace std;
//C++风格类型转化
//static_cast<类型> (变量或者表达式)   适用于绝大多数类型转化
//const_cast<> () 适用于对常量转变为非常量的类型转化
//reinterpret_cast <> () 最危险的一种，随便玩
//C风格类型转化
//(类型) 变量 类型 (变量)




//打印字符串
void error_msg (initializer_list<string> il)
{
    for(auto beg= il.begin();beg!=il.end();++beg)
    {
        cout<<*beg<<endl;
    }
}
//计算整数和
int sum_int (initializer_list<int > ok)
{
    long sum=0;
    for(auto beg=ok.begin();beg!=ok.end();++beg)
    {
        sum+=*beg;
    }
    return static_cast<int> (sum);
}
int main()
{
    error_msg({"hello","my","friend"});

    cout<<  sum_int({1,2,3,4})<<endl;
    return 0;
}
