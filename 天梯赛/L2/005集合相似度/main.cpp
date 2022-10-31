#include <iostream>
#include <cstdio>
#include <map>
#include <set>
const int N = 51;
using namespace std;
int main ()
{
    int n,m,k,data,first,second,nc,nt;
    set<int> s[N];
    scanf("%d",&n);
    for(int i = 1; i <= n;i++)
    {
        scanf("%d",&m);
        while(m--)
        {
            scanf("%d",&data);
            s[i].insert(data);
        }
    }
    scanf("%d",&k);
    while(k--)
    {
        nc = nt = 0;
        scanf("%d%d",&first,&second);
        //���еĲ����Ԫ�صĸ���/���еĲ���ȵ�Ԫ��
        for(auto i = s[first].begin(); i != s[first].end();++i)
            if(s[second].count(*i))
                nc++;
        nt = (int)s[first].size()+(int)s[second].size()-nc;
        printf("%.2f%%\n",nc*100.0/nt);
    }
    return 0;
}
