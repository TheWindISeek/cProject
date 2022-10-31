#include <bits/stdc++.h>
using namespace std;
#define N 201
#define inf 0x3f3f3f3f
int g[N][N];//用于存储距离
int visit[N];//用于dfs记录
int des[N];//用于标记端点
vector<int> gg[N];//用于dfs遍历
int n,m,k;
set<int> s;//用于从小到大输出
void dfs(int x)
{
    visit[x] = 1;
    s.insert(x);
    for(int v:gg[x])
        if(!visit[v])
            dfs(v);
}
int main()
{
    int v,w,c;
    scanf("%d%d%d\n",&n,&m,&k);
    memset(g,inf,sizeof(g));
    memset(des,0,sizeof(des));
    for(int i = 0; i < m;i++)
    {
        cin >> v;
        des[v] = 1;
        while(1)
        {
            cin >> w >> c;
            g[v][c] = g[c][v] = min(w,g[v][c]);//两个端点有多种输入 选择最短的那个
            v = c;
            if(getchar() == '\n')
                break;
        }
        des[v] = 1;
    }
    for(int k = 1; k<= n;k++)//Floyd求最短路
        for(int i = 1; i <= n;i++)
            for(int j = 1; j<= n;j++)
                if(i!=j)
                    g[i][j] = min(g[i][j],g[i][k]+g[k][j]);
    for(int i = 1; i <= n;i++)
    {
        map<int,int> m;
        for(int j = 1; j <= n;j++)
        {
            if(g[i][j]!= inf&& g[i][j] > m[g[i][j]/k])//首先可达 其次在当前价格区间里能到更远
                m[g[i][j]/k] = g[i][j];
        }
        for(int j = 1; j <= n;j++)
        {
            if(g[i][j] == m[g[i][j]/k] ||(i!=j&&g[i][j]!=inf&&des[j]))//因为出站有两种可能 所以要算上 能到的 端点 必须是能到的
                gg[i].push_back(j);
        }
    }
    int q,node,flag;
    scanf("%d",&q);
    for(int i = 0; i < q;i++)
    {
        s.clear();
        memset(visit,0,sizeof(visit));
        flag = 1;
        scanf("%d",&node);
        dfs(node);
        for(int x:s)
        {
            if(flag)
                flag = 0;
            else
                printf(" ");
            printf("%d",x);
        }
        printf("\n");
    }
    return 0;
}
