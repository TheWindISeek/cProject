#include <set>
#include <map>
#include <cstdio>
#include <cstring>
using namespace std;
#define N 1001
int father[N];
//和上一题一样的感觉 感觉写完两个字 就这 玩的花里胡哨的
/*这题就一伪装的并查集的题目 需要统计人数的话就要用-1 并查集之间有关系的人就是这个兴趣直接有相同点的人*/
int find(int key)
{
    if(father[key] < 0)
        return key;
    return father[key] = find(father[key]);
}
void Union(int x,int y)
{
    int rootx = find(x),rooty = find(y);
    if(rootx != rooty)
    {
        father[rootx] += father[rooty];
        father[rooty] = rootx;
    }
}
int main()
{
    int n,k,h,f=1;
    set<int> s[N];
    memset(father,-1,sizeof(int)*N);
    scanf("%d",&n);
    for(int i = 1; i <= n; i++)
    {
        scanf("%d:",&k);
        while(k--)
        {
            scanf("%d",&h);
            s[i].insert(h);
        }
    }
    for(int i = 1; i <= n; i++)
    {
        for(int interest:s[i])
            for(int j = 1; j <= n; j++)
                if(j != i&&s[j].count(interest))
                    Union(i,j);
    }
    multiset<int> result;
    for(int i = 1; i <= n; i++)
        if(father[i] < 0)
            result.insert(-father[i]);
    printf("%d\n",(int)result.size());
    for(auto i = result.rbegin(); i != result.rend(); i++)
    {
        if(f)
            f = 0;
        else
            printf(" ");
        printf("%d",*i);
    }

    return 0;
}
