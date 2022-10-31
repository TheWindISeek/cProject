#include <iostream>
#include <algorithm>
#include <cstdio>
#include <set>
#include <map>
using namespace std;
#define N 5001
#define L 5
/*
10 GAO3 Magi Zha1 Sen1 Quan FaMK LSum Eins FatM LLao
8
Magi 50
Pota 30
LLao 3
Ammy 48
Dave 15
GAO3 31
Zoro 1
Cath 60
*/
bool cmp(string &a,string &b)
{
   return a > b;
}
int main ()
{//读取完后 将所有的人先按字母升序排序 后计算平均数 然后对于 点赞数高于平均数&不在关注列表 输出该人姓名 给个标志变量 标志变量没修改完 就输出并没有
    string a;
    int c,flag = 1,f=1;
    float ave = 0;
    set<string> s;
    map<string,int> mp;
    int n,m;
    scanf("%d",&n);
    for(int i = 0; i < n; ++i)
    {
        cin >> a;
        s.insert(a);
    }
    scanf("%d",&m);
    for(int i = 0; i < m; ++i)
    {

        cin >> a;
        scanf("%d",&c);
        mp[a] = c;
        ave+=c;
    }
    ave = ave/m;
    for(auto i = mp.begin(); i!= mp.end();++i)
    {
     if((*i).second > ave&&!s.count((*i).first))
     {
         if(flag)
            flag = 0;
         else
            printf("\n");
         cout << (*i).first;
         f = 0;
     }
    }
    if(f)
        printf("Bing Mei You");
    return 0;
}
