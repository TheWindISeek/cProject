#include <cstdio>
#include <iostream>
#include <queue>
#include <cstdlib>
#define N 100001

using namespace std;
int main ()
{
    int n;
    int k,to;
    int i,j;
    int visit[N] = {0};
    scanf("%d",&n);
    int g[n+1][n+1];
    for(i = 0; i <=n ; i++)
        for(j = 0; j <= n; j++)
            g[i][j] = 0;
    for(i = 1; i <= n; i++)
    {
        scanf("%d",&k);
        while(k--)
        {
            scanf("%d",&to);
            g[i][to] = 1;//可到达
            visit[to] = 1;
        }
    }
    //哪个点是入口
    for(i = 1; i <= n; i++)
        if(!visit[i])
            break;
    queue<int> q;
    int x;
    int path[N]= {1};
    q.push(i);
    while(!q.empty())
    {
        x = q.front();
        q.pop();
        for(i = 1; i <= n; i++)
        {
            if(g[x][i])
            {
                path[i] = path[x] + 1;
                q.push(i);
            }
        }
    }
    int max = 0,index = 0;
    for(i = 1; i <= n; i++)
        if(max < path[i])
        {
            max = path[i];
            index = i;
        }
    printf("%d",index);
    return 0;
}
