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
     //�����������ǺϷ��ģ�c������Ӧ����const char,Ҳ���ǲ���������޸�
     for(auto &c:s)
     cout<<s[0]<<endl;*/


    /* string ss;cin>>ss;
     for(auto &c:ss)
      if(isalpha(c))
      cout<<c;*/


    /*
    //�������ַ�������ֵ����vec�����ԭ�������û����Ӧ�ĺ���
    vector<string> a;
    cout<<a[0]<<endl;*/


    /*
    vector<vector<int> > ivec;
    vector<string> svec=ivec;
    vector<string> sa(10,"null");*/

    /*
    string word;
    vector<string> svec;
    //����ctrl+z�ټ���enter������ֹѭ������Ӧ��ע����ǣ�cin��һ��һ�ж�ȡ��������������д��ctrl+z���ᱻ�����ַ����룬Ϊ��ʵ����ֹ��������Ҫ���н���
    while(cin>>word)
        svec.push_back(word);
    cout<<svec[3]<<endl;*/

    /*
    //�ó����Ŀ�����ж�a��A�Ĵ�С���⣬Ӧ���ǰ�ASCLL��������
    vector<string> s1(1,"A");
    vector<string> s2(1,"a");
    if(s1>s2)
        cout<<s1[0]<<endl;
    else
        cout<<s2[0]<<endl;*/

/*
    //������������Ԫ�ظ������������Ԫ��Ҳ�������Ҫע���һ����size���������������ţ�����������⣬���⻹�о��ǲ�Ҫ�ּ���decltype��ʱ�����˸����ţ���Ȼ�ᱨ��
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
