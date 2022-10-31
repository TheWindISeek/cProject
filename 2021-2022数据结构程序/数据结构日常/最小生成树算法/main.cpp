#include<bits/stdc++.h>
using  namespace std;
#define INF 0x3f3f3f3f
const int maxn = 117;
int m[maxn][maxn];
int vis[maxn], low[maxn];
/*
对于这道题目来将，m就是临接矩阵，vis是访问标记数组，low是最短距离数组
*/
int n;
int prim()
{
    vis[1] = 1;
    int sum = 0;
    int pos, minn;
    pos = 1;
    for(int i = 1; i <= n; i++)
    {
        low[i] = m[pos][i];
    }
    /*
    先把第一个点放到树里，然后找到剩下的点到这个点的距离
    */
    for(int i = 1; i < n; i++)//循环遍历 n-1 次数，把点全部加入！
    {
        minn = INF;
        for(int j = 1; j <= n; j++)
        {
            if(!vis[j] && minn > low[j]) //没有进树的节点，并且这个节点到树里面 点距离最近，拉进来
            {
                minn = low[j];
                pos = j;
            }
        }
        sum += minn;
        vis[pos] = 1;
        for(int j = 1; j <= n; j++)
        {
            if(!vis[j] && low[j] > m[pos][j])//用新加入的点，更新low值
            {
                low[j] = m[pos][j];
            }
        }
    }
    return sum;
}
void init()
{
    memset(vis,0,sizeof(vis));
    memset(low,0,sizeof(low));
    for(int i = 1; i <= n ;i++ )
    for(int j = 1; j <= n; j++)
        m[i][j] = INF;
}
void in_map()
{
    printf("输入邻接矩阵阶：\n");
    scanf("%d",&n);
    printf("输入邻接矩阵，无穷用 -1代表！\n");
    int t;
    for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)
    {
        scanf("%d",&t);
        m[i][j] = (t==-1?INF:t);
    }
}
int main()
{
    init();
    in_map();
    printf("%d",prim());
}
