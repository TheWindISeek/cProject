#include <bits/stdc++.h>
using namespace std;
struct node
{
    int x,y;
};
int n,m;
bool g[101][101];
void push(int x,int y,queue<node> &q)
{
    if(x<=n&&x>0&&y>0&&y<=m&&!g[x][y])
    {
        struct node tmp;
        tmp.x = x;
        tmp.y = y;
        q.push(tmp);
        g[x][y] = true;
    }
}
int main()
{
    int t;
    int k;
    scanf("%d%d",&n,&m);
    memset(g,false,sizeof(g));
    scanf("%d",&t);
    int x,y;
    queue<struct node> q;
    for(int i = 0; i < t; i++)
    {
        scanf("%d%d",&x,&y);
        g[x][y] = true;
        struct node no;
        no.x = x;
        no.y = y;
        q.push(no);
    }
    scanf("%d",&k);
    queue<node> qq;
    while(k--)
    {
        while(!q.empty())
        {
            node no = q.front();
            q.pop();
            push(no.x+1,no.y,qq);
            push(no.x-1,no.y,qq);
            push(no.x,no.y+1,qq);
            push(no.x,no.y-1,qq);
        }
        while(!qq.empty())
        {
            q.push(qq.front());
            qq.pop();
        }
    }
    int c = 0;
    for(int i = 1; i <= n; i++)
    {
       // cout <<endl;
        for(int j = 1; j <= m; j++)
        {
            //cout <<g[i][j]<<' ';
            if(g[i][j])
                c++;
        }
    }
    printf("%d",c);
    return 0;
}
