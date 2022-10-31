#include <bits/stdc++.h>
using namespace std;
#define N 201
#define inf 0x3f3f3f3f
int g[N][N];//���ڴ洢����
int visit[N];//����dfs��¼
int des[N];//���ڱ�Ƕ˵�
vector<int> gg[N];//����dfs����
int n,m,k;
set<int> s;//���ڴ�С�������
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
            g[v][c] = g[c][v] = min(w,g[v][c]);//�����˵��ж������� ѡ����̵��Ǹ�
            v = c;
            if(getchar() == '\n')
                break;
        }
        des[v] = 1;
    }
    for(int k = 1; k<= n;k++)//Floyd�����·
        for(int i = 1; i <= n;i++)
            for(int j = 1; j<= n;j++)
                if(i!=j)
                    g[i][j] = min(g[i][j],g[i][k]+g[k][j]);
    for(int i = 1; i <= n;i++)
    {
        map<int,int> m;
        for(int j = 1; j <= n;j++)
        {
            if(g[i][j]!= inf&& g[i][j] > m[g[i][j]/k])//���ȿɴ� ����ڵ�ǰ�۸��������ܵ���Զ
                m[g[i][j]/k] = g[i][j];
        }
        for(int j = 1; j <= n;j++)
        {
            if(g[i][j] == m[g[i][j]/k] ||(i!=j&&g[i][j]!=inf&&des[j]))//��Ϊ��վ�����ֿ��� ����Ҫ���� �ܵ��� �˵� �������ܵ���
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
