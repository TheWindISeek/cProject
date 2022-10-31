#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 505;

const int inf = 0x3f3f3f3f;

typedef struct
{
    int length;
    int cost;
} city;


int main ()
{
    int n,m,s,d;
    int i,j,x,y,q,w;
    city g[N][N];
    //读取数据
    cin >> n >> m >> s >> d;
    //初始化
    for(i = 0; i < n; ++i)
    {
        for(j = 0; j < n; ++j)
        {
            if(i != j)
            {
                g[i][j].length =g[j][i].length = inf;
                g[i][j].cost = g[j][i].cost = inf;
            }
            else
            {
                g[i][j].length = 0;
                g[i][j].cost = 0;
            }

        }
    }

    for(i = 0; i < m; ++i)
    {
        cin >> x >> y >> q >> w;
        g[y][x].length = g[x][y].length = q;
        g[x][y].cost = g[y][x].cost = w;
    }
    //运行算法
    int cost[N];//花费数组
    int weight[N];
    int visit[N];
    int min,index;
    for(i = 0; i < n; ++i)
    {
        visit[i] = 0;
        cost[i] = g[s][i].length;
        weight[i] = g[s][i].cost;
    }
    visit[s] = 1;
    for(int k = 0; k < n -1; ++k)
    {
        min = inf;
        index = -1;
        for(i = 0; i < n; ++i)
        {
            if(!visit[i] && min > cost[i])
            {
                min = cost[i];
                index = i;
            }
        }
        visit[index] = 1;
        for(i = 0; i < n; ++i)
        {
            if(g[index][i].length < N)
            {
                if(cost[index] + g[index][i].length < cost[i])
                {
                    cost[i] = cost[index] + g[index][i].length;
                    weight[i] = weight[index] + g[index][i].cost;
                }
                else if(cost[index] + g[index][i].length == cost[i])
                {
                    if(weight[index] + g[index][i].cost < weight[i])
                    {
                        weight[i] = weight[index] + g[index][i].cost;
                    }
                }
            }
        }
    }
    printf("%d %d",cost[d],weight[d]);
    return 0;
}
