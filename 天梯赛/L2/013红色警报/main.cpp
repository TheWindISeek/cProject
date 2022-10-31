#include <vector>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
#define N 501
#define M 5001
//n m
/*虽然全对了 但是怎么感觉这一题有点水呢 汗*/
//此题一大问题就是才u去什么样的数据结构去存储图
//然后是需要一个能检测图连通性的函数 返回的应该是图的连通分支个数
//这样才能处理多样的信息 这样的数据结构还应该满足一个特性即是有记忆的 不能每次都重新来
//同时还需要去判断失去城市的个数一旦所有的城市都失去了 那么要输出游戏结束
//如果本来就不连通 失去一个城市不改变其他城市连通性不发出警报
//输入保证城市编号无重复 但是通路可能重复
vector<int> g[N];
int visit[N];
int n,m;
int readConnect()
{
    int v[N] = {0},i,node,c = 0;
    queue<int> q;
    for(i = 0; i < n; i++)
    {
        if(!v[i]&&!visit[i])
        {
            q.push(i);
            c++;
            v[i] = 1;
            while(!q.empty())
            {
                node = q.front();
                q.pop();
                for(int a:g[node])
                    if(!visit[a]&&!v[a])
                    {
                        v[a] = 1;
                        q.push(a);
                    }

            }
        }
    }
    return c;
}
int main()
{
    int in,out,data,k,old,alter;
    scanf("%d%d",&n,&m);
    memset(visit,0,sizeof(int)*N);
    for(int i = 0; i < m; i++)
    {
        scanf("%d%d",&in,&out);
        g[in].push_back(out);
        g[out].push_back(in);
    }
    scanf("%d",&k);
    old = readConnect();
    //printf("原来的连通分支个数:%d\n",old);
    for(int i = 0; i < k; i++)
    {
        scanf("%d",&data);
        visit[data] = 1;
        alter = readConnect();
        //printf("删除%d后的连通分支个数%d\n",data,alter);
        if(alter > old)
        {
            printf("Red Alert: City %d is lost!\n",data);
        }
        else
            printf("City %d is lost.\n",data);
        old = alter;
        if(i == n-1)
            printf("Game Over.");
    }
    return 0;
}
