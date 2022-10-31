#include <bits/stdc++.h>
using namespace std;
int g[22][22];
bool visit[22];
int c;
void dfs(int v)
{
   // cout << v <<endl;
    if(visit[v])
    {
        if(v == 1)
            c++;
        return;
    }
    visit[v] = true;
    for(int i = 1; i <= 21; i++)
    {
        if(g[v][i])
            dfs(i);
    }
    visit[v] = false;
}
int main()
{
    memset(visit,false,sizeof(visit));
    memset(g,0,sizeof(g));
    for(int i = 2; i <= 21; i++)
        g[1][i] = g[i][1] = 1;
    for(int i = 2; i <= 21; i++)
    {
        for(int j = i+1; j <= 21; j++)
        {
            if(j%i)
            {
                g[i][j] = g[j][i] = 1;
            }
        }
    }
    dfs(1);
    cout << c;
    return 0;
}
