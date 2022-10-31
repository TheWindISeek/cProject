#include <iostream>
#include <string>
#include <cstring>
#include <stack>
using namespace std;
void print(int n,int flag)
{
    switch(n)
    {
    case 0:
        if(flag)
            printf("[-?");
        else
            printf("?-]");
        break;
    case 1:
        if(flag)
            printf("{-?");
        else
            printf("?-}");
        break;
    case 2:
        if(flag)
            printf("/*-?");
        else
            printf("?-*/");
        break;
    case 3:
        if(flag)
            printf("(-?");
        else
            printf("?-)");
        break;
    }
}
int main()
{
    //不考虑符号分段的情况 按行读取
    //[ 0 { 1 /* 2 ( 3
    string a;
    stack<int> s;
    //现在的想法是利用hash表去记录值 等等 好了 这种想法不行 因为还有退栈操作 我觉得稍微牺牲一下复杂度比较好
    //主要的问题在于 判断是哪个缺少 已经最早缺少的是哪个问题
    //其他的都很简单 由于我采取的是右边匹配左边 这样就会出现一些问题 比如 如果我在左边没有找到 那么它就是那个 第一个出问题的
    //如果我在左边找到了和它相匹配的 那么这个匹配的下一个就是我需要的 我之前的想法是利用hash表 但现在感觉不好 直接去找到它就好了
    while(1)
    {
        getline(cin,a);
        if(a == ".")
            break;
        for(int i = 0; i < (int)a.size(); ++i)
        {
            if(a[i] == '[')
                s.push(0);
            else if (a[i] == ']')
                if(!s.empty() && s.top() == 0)
                    s.pop();
                else//栈为空 也就是右边多了 记录这第一个
                {
                    printf("NO\n");
                    if(s.empty())
                        print(0,1);
                    else
                        print(s.top(),0);
                    return 0;
                }
            else if(a[i] == '{')
                s.push(1);
            else if (a[i] == '}')
                if(!s.empty() && s.top() == 1)
                    s.pop();
                else//栈为空 也就是右边多了 记录这第一个
                {
                    printf("NO\n");
                    if(s.empty())
                        print(1,1);
                    else
                        print(s.top(),0);
                    return 0;
                }
            else if(i+1<(int)a.size() && a[i]=='/' &&a[i+1]=='*')
                s.push(2);
            else if(i+1<(int)a.size() && a[i]=='*' &&a[i+1]=='/')
                if(!s.empty() && s.top() == 2)
                    s.pop();
                else//栈为空 也就是右边多了 记录这第一个
                {
                    printf("NO\n");
                    if(s.empty())
                        print(2,1);
                    else
                        print(s.top(),0);
                    return 0;
                }
            else if(a[i] == '(')
                s.push(3);
            else if(a[i] == ')')
                if(!s.empty() && s.top() == 3)
                    s.pop();
                else//栈为空 也就是右边多了 记录这第一个
                {
                    printf("NO\n");
                    if(s.empty())
                        print(3,1);
                    else
                        print(s.top(),0);
                    return 0;
                }
        }
    }
    cout << "YES";
    return 0;
}
