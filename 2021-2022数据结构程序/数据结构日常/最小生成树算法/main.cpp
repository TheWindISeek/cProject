#include<bits/stdc++.h>
using  namespace std;
#define INF 0x3f3f3f3f
const int maxn = 117;
int m[maxn][maxn];
int vis[maxn], low[maxn];
/*
���������Ŀ������m�����ٽӾ���vis�Ƿ��ʱ�����飬low����̾�������
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
    �Ȱѵ�һ����ŵ����Ȼ���ҵ�ʣ�µĵ㵽�����ľ���
    */
    for(int i = 1; i < n; i++)//ѭ������ n-1 �������ѵ�ȫ�����룡
    {
        minn = INF;
        for(int j = 1; j <= n; j++)
        {
            if(!vis[j] && minn > low[j]) //û�н����Ľڵ㣬��������ڵ㵽������ ����������������
            {
                minn = low[j];
                pos = j;
            }
        }
        sum += minn;
        vis[pos] = 1;
        for(int j = 1; j <= n; j++)
        {
            if(!vis[j] && low[j] > m[pos][j])//���¼���ĵ㣬����lowֵ
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
    printf("�����ڽӾ���ף�\n");
    scanf("%d",&n);
    printf("�����ڽӾ��������� -1����\n");
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
