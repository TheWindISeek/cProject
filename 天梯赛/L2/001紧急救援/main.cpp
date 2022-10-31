#include <iostream>
#include <cstdio>
#include <stack>
#include <algorithm>
#include <cmath>
using namespace std;
#define N 501
#define inf 0x7fffff
int g[N][N];
int aid[N];
int s,d,c,min_cost,n;
void dijkstra(int n)
{
    int visit[N]= {0};
    int cost[N];
    int dis[N];
    int path[N];
    int roadCount[N];
    int pay = 0,min,v;
    for(int i = 0; i < n; i++)
    {
        if(g[s][i] != inf)
            path[i] = s;
        else
            path[i] = -1;
        dis[i] = g[s][i];
        if(g[s][i] != inf)
            cost[i] = aid[i]+aid[s];
        roadCount[i] = 1;
    }
    visit[s] = 1;
    for(int i = 0; i < n-1; i++)
    {
        min = inf;
        for(int j = 0; j < n; j++)
            if(!visit[j]&&min >dis[j])
            {
                min = dis[j];
                v = j;
            }
        visit[v] = 1;
        for(int j = 0; j < n; j++)
        {
            if(g[v][j] != inf)
                if(!visit[j] && g[v][j] + dis[v] < dis[j])
                {
                    dis[j] = g[v][j] + dis[v];
                    path[j] = v;
                    roadCount[j] = roadCount[v];
                    cost[j] = aid[j]+cost[v];
                }
                else if(!visit[j] && g[v][j] + dis[v] == dis[j])
                {
                    roadCount[j] += roadCount[v];
                    if(cost[v] + aid[j] > cost[j])
                    {
                        cost[j] = cost[v] + aid[j];
                        path[j] = v;
                    }
                }
        }
    }
    cout << roadCount[d]<<" "<<cost[d]<<endl;
    stack<int> st;
    v = d;
    while(v!=s)
    {
        st.push(v);
        v = path[v];
    }
    cout << s;
    while(!st.empty())
    {
        v = st.top();
        st.pop();
        cout <<" "<<v;
    }
}
int main ()
{
    int m;
    int source,destination,howmuch;
    scanf("%d%d%d%d",&n,&m,&s,&d);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            g[i][j] = inf;
    for(int i = 0; i < n; i++)
        scanf("%d",&aid[i]);
    for(int i = 0; i < m; i++)
    {
        scanf("%d%d%d",&source,&destination,&howmuch);
        g[source][destination]=g[destination][source] = howmuch;
    }
    dijkstra(n);
    return 0;
}
