#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <stack>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;
const int N = 105;
typedef struct
{
    int x;
    int y;
} node;
node g[N];//存储那些顶点
int path[N];//存储路径 对应的上一顶点的标号
int cost[N];//存储路径长度 寻找最短路径
int first[N];//第一跳可以到达的 第一跳是不一样的 并找到最短的那个 所以采取升序
int visit[N];//标记顶点是否被访问过
int n,dis;//多少条鳄鱼 顶点 每次能跳多远

bool cmp (int,int);//用于排序的函数
int distant(int);//用于计算顶点距离岛的距离
int safe(int);//用于判断是否能够到达岸上
int jump (int,int);//用于判断这两个顶点之间是否能够到达
int isAlive();//判断是否能回去的函数

int main ()
{
    int i;
    //初始化数据
    for(i = 0; i < N; ++i)
    {
        g[i].x = 0;
        g[i].y = 0;
        visit[i] = 0;
        first[i] = i;
        path[i] = -1;//所有的路径都不存在
        cost[i] = -1;
    }
    //读取题目数据
    cin >> n >> dis;
    for(i = 1; i <= n; ++i)
    {
        cin >> g[i].x >> g[i].y;
    }
    if(dis  >= 35)
    {
        printf("1\n");
        return 0;
    }
    int flag = isAlive();
    if(flag) //如果成功
    {
        printf("%d\n",cost[flag]+1);
        stack<int> s;
        int v = flag;
        while(v != 0)
        {
            s.push(v);
            v = path[v];
        }
        while(!s.empty())
        {
            v = s.top();
            s.pop();
            printf("%d %d\n",g[v].x,g[v].y);
        }
    }
    else
    {
        printf("0\n");
    }
    return 0;
}

int distant (int v)
{
    double d = (g[v].x*g[v].x)+(g[v].y*g[v].y);
    double length = (7.5+dis)*(7.5+dis);
    if(length >= d)//如果能够跳到
        return d;
    else//跳不到 返回一个标志
        return -1;
}
bool cmp (int x, int y)
{
    return distant(x) < distant(y);
}
int safe(int v)
{
    //如果四个方向有一个方向能够达到 就判定逃脱成功
    if(g[v].y+dis >= 50 || g[v].x-dis <= -50||g[v].x+dis >= 50 || g[v].y-dis <= -50)
        return 1;
    return 0;
}
int jump(int v,int w)
{
    //计算两点之间的距离
    double distant = sqrt(((double)g[v].x-g[w].x)*((double)g[v].x-g[w].x)+((double)g[v].y-g[w].y)*((double)g[v].y-g[w].y));
    if(distant > dis)
        return 0;
    return 1;
}
int isAlive()
{
    //采取队列进行广度优先遍历
    //首先将第一跳能达到的点添加进队列中 并标记被已被访问
    int i,v;
    queue<int> q;
    //对第一跳的顶点进行排序
    sort(first+1,first+n+1,cmp);
    for(i = 1; i <= n; ++i)
    {
        v = first[i];
        //按第一跳的距离从小达大添加入队列中
        if(distant(v) != -1)
        {
            q.push(v);
            visit[v] = 1;//标记被访问
            path[v] = 0;//上一个顶点为第一个0
            cost[v] = 1;//路径长度为跳的长度
        }
    }
    //当队列不为空时 进行广度优先遍历
    while(!q.empty())
    {
        //出队
        v = q.front();
        q.pop();
        if(safe(v)) //如果已经安全 就继续下一个的判断
        {
            break;
        }
        //对于这个结点的所有没有被访问到的顶点 并且可以达到的顶点进行访问
        for(i = 1; i <=n; ++i)
        {
            if(!visit[i] && jump(i,v) && cost[i]== -1)
            {
                //访问这个结点 并将这个点入队
                visit[i] = 1;
                q.push(i);
                path[i] = v;
                cost[i] = cost[v]+1;
            }
        }
    }
    return v;
}
