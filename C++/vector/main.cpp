#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
using std::string;
using std::vector;
int main()
{
    /* string str("ASDDF");
     for(char &c:str)
         c='X';
     cout<<str<<endl;*/



    /* const string s;
     //下面这个语句是合法的，c的类型应该是const char,也就是不允许进行修改
     for(auto &c:s)
     cout<<s[0]<<endl;*/


    /* string ss;cin>>ss;
     for(auto &c:ss)
      if(isalpha(c))
      cout<<c;*/


    /*
    //不能用字符串字面值构建vec对象的原因可能是没有相应的函数
    vector<string> a;
    cout<<a[0]<<endl;*/


    /*
    vector<vector<int> > ivec;
    vector<string> svec=ivec;
    vector<string> sa(10,"null");*/

    /*
    string word;
    vector<string> svec;
    //利用ctrl+z再加上enter键来终止循环，但应该注意的是，cin是一行一行读取，如果你在这行中打出ctrl+z，会被当做字符读入，为了实现终止操作，需要换行进行
    while(cin>>word)
        svec.push_back(word);
    cout<<svec[3]<<endl;*/

    /*
    //该程序的目的是判断a和A的大小问题，应该是按ASCLL码来做的
    vector<string> s1(1,"A");
    vector<string> s2(1,"a");
    if(s1>s2)
        cout<<s1[0]<<endl;
    else
        cout<<s2[0]<<endl;*/

/*
    //将下面向量的元素个数输出，并将元素也输出。需要注意的一点是size函数不能忘记括号，诸如此类问题，另外还有就是不要手贱，decltype的时候多打了个括号，不然会报错
        vector<int> v1;
        vector<int> v2(10);
        vector<int> v3(10,42);
        vector<int> v4{10};
        vector<int> v5{10,42};
        vector<string> v6{10};
        vector<string> v7{10,"hi"};
for(decltype(v7.size()) ix=0  ;ix != v7.size(); ix++)
{
    if(!v7.empty())
    {
        cout<<v7.size()<<endl;
    }
    else
    {
        cout<<0<<endl;
        break;
    }
      cout<<v7[ix]<<endl;
}*/


    cout<<endl;
    cout << "the end" << endl;
    return 0;
}
