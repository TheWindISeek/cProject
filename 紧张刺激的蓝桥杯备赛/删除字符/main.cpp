#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    // 请在此输入您的代码
    string s;
    getline(cin,s);
    int t;
    cin >> t;
    //怎么删除才能让字典序最小 就是如果当前的比后面的
    /*
    让小的尽可能往前面排 这样就行了 每次把后面最小的那个放这里
    */
    int l = s.length();
    bool is[l];
    int c = 0;
    memset(is,false,sizeof(is));
    for(int i = 0; i < l&&c<t; i++)
    {
        int next = i+1;
        for(; next<l; next++)
        {
            while(is[next])
                next++;
            if(s[next] < s[i])
            {
                c++;
                is[i] = true;
                break;
            }
        }
    }
    for(int i = 0; i < l; i++)
    {
        if(!is[i])
            printf("%c",s[i]);
    }

    return 0;
}
