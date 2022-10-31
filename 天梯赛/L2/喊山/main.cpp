#include <cstring>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
#define N 10001
vector<int> g[N];
/*坏了 判断错了 这是广搜 不是深搜*/
int bfs(int i)
{
    queue<int> q;
    q.push(i);
    int deep[N]= {0},v,minNode = i,maxLength = 1;
    deep[i] = 1;
    while(!q.empty())
    {
        v = q.front();
        q.pop();
        if(maxLength == deep[v]&&v < minNode)
            minNode = v;
        if(maxLength < deep[v])
        {
            minNode = v;
            maxLength = deep[v];
        }
        for(int node:g[v])
            if(!deep[node])
            {
                deep[node] = deep[v]+1;
                q.push(node);
            }
    }
    if(minNode == i)
        return 0;
    return minNode;
}
int main()
{
    int n,m,k,in,out;
    scanf("%d%d%d",&n,&m,&k);
    for(int i = 0; i < m; i++)
    {
        scanf("%d%d",&in,&out);
        g[in].push_back(out);
        g[out].push_back(in);
    }
    while(k--)
    {
        scanf("%d",&in);
        printf("%d\n",bfs(in));
    }
    return 0;
}
