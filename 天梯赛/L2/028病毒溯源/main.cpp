#include <vector>
#include <cstdio>
#include <queue>
#include <stack>
using namespace std;
#define N 10001
vector<int> g[N];
int n;
vector<int> output,tmp;
int _max;
void dfs(int v,int deep)
{
    tmp.push_back(v);
    if(_max < deep)
    {
        _max = deep;
        if(g[v].empty())
        {
            output.clear();
            for(int x:tmp)
                output.push_back(x);
        }
    }
    for(int x:g[v])
        dfs(x,deep+1);
    tmp.pop_back();
}
int main ()
{
    int m,data;
    int root;
    int visit[N]={0};
    scanf("%d",&n);
    for(int i = 0; i < n;i++)
    {
        scanf("%d",&m);
        while(m--)
        {
            scanf("%d",&data);
            visit[data] = 1;
            vector<int>::iterator it = lower_bound(g[i].begin(),g[i].end(),data);
            g[i].insert(it,data);
            //g[i].push_back(data);
        }
    }
    for(root = 0; root < n; root++)
        if(!visit[root])
            break;
    _max = 0;
    dfs(root,1);
    int i = 0;
    printf("%d\n",_max);
    for(int x:output)
    {
        if(i++)
            printf(" ");
        printf("%d",x);
    }
    return 0;
}
