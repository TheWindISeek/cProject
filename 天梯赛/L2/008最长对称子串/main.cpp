#include <stdio.h>
#include <iostream>
#include <map>
/*
此题的测试数据在第一次提交之后就察觉到了
然后自己也按那个想法更改了
但是因为一些问题
还是没有ALL PASS
后来看了一下网上的
发现其实思路一致
但是就是不知道为什么老不对
就按他的改了下
发现还是不对
当时就很纠结 觉得明明一样
后来心很烦 没发现自己的程序中的移动方向错误
而后提交了别人的代码后 认真比对之下才发现这个问题
还是心急了 想快点写完 去玩会
同时还看到了一个证明这种解法正确性的文章 看完和之前看循环不变式一样的感觉-这也要证？
唉证明啊
*/
using namespace std;
int Symmetric(string &s,int n,int f,int b,int length)
{
    int l = length;
    while(f >= 0 && b < n)
    {
        if(s[f] == s[b])
            l+=2;
        else
            break;
        f--;
        b++;
    }
    return l;
}
int main ()
{
    string s;
    getline(cin,s);
    int max = 1,l;
    int n = s.length();
    for(int i = 0; i < n; i++)
    {
        l = Symmetric(s,n,i-1,i+1,1);
        if(l  > max)
            max = l;
        l = Symmetric(s,n,i,i+1,0);
        if(l  > max)
            max = l;
    }
    cout << max;
    return 0;
}
