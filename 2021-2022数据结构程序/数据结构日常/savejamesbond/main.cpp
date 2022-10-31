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
node g[N];//�洢��Щ����
int path[N];//�洢·�� ��Ӧ����һ����ı��
int cost[N];//�洢·������ Ѱ�����·��
int first[N];//��һ�����Ե���� ��һ���ǲ�һ���� ���ҵ���̵��Ǹ� ���Բ�ȡ����
int visit[N];//��Ƕ����Ƿ񱻷��ʹ�
int n,dis;//���������� ���� ÿ��������Զ

bool cmp (int,int);//��������ĺ���
int distant(int);//���ڼ��㶥����뵺�ľ���
int safe(int);//�����ж��Ƿ��ܹ����ﰶ��
int jump (int,int);//�����ж�����������֮���Ƿ��ܹ�����
int isAlive();//�ж��Ƿ��ܻ�ȥ�ĺ���

int main ()
{
    int i;
    //��ʼ������
    for(i = 0; i < N; ++i)
    {
        g[i].x = 0;
        g[i].y = 0;
        visit[i] = 0;
        first[i] = i;
        path[i] = -1;//���е�·����������
        cost[i] = -1;
    }
    //��ȡ��Ŀ����
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
    if(flag) //����ɹ�
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
    if(length >= d)//����ܹ�����
        return d;
    else//������ ����һ����־
        return -1;
}
bool cmp (int x, int y)
{
    return distant(x) < distant(y);
}
int safe(int v)
{
    //����ĸ�������һ�������ܹ��ﵽ ���ж����ѳɹ�
    if(g[v].y+dis >= 50 || g[v].x-dis <= -50||g[v].x+dis >= 50 || g[v].y-dis <= -50)
        return 1;
    return 0;
}
int jump(int v,int w)
{
    //��������֮��ľ���
    double distant = sqrt(((double)g[v].x-g[w].x)*((double)g[v].x-g[w].x)+((double)g[v].y-g[w].y)*((double)g[v].y-g[w].y));
    if(distant > dis)
        return 0;
    return 1;
}
int isAlive()
{
    //��ȡ���н��й�����ȱ���
    //���Ƚ���һ���ܴﵽ�ĵ���ӽ������� ����Ǳ��ѱ�����
    int i,v;
    queue<int> q;
    //�Ե�һ���Ķ����������
    sort(first+1,first+n+1,cmp);
    for(i = 1; i <= n; ++i)
    {
        v = first[i];
        //����һ���ľ����С�������������
        if(distant(v) != -1)
        {
            q.push(v);
            visit[v] = 1;//��Ǳ�����
            path[v] = 0;//��һ������Ϊ��һ��0
            cost[v] = 1;//·������Ϊ���ĳ���
        }
    }
    //�����в�Ϊ��ʱ ���й�����ȱ���
    while(!q.empty())
    {
        //����
        v = q.front();
        q.pop();
        if(safe(v)) //����Ѿ���ȫ �ͼ�����һ�����ж�
        {
            break;
        }
        //���������������û�б����ʵ��Ķ��� ���ҿ��Դﵽ�Ķ�����з���
        for(i = 1; i <=n; ++i)
        {
            if(!visit[i] && jump(i,v) && cost[i]== -1)
            {
                //���������� ������������
                visit[i] = 1;
                q.push(i);
                path[i] = v;
                cost[i] = cost[v]+1;
            }
        }
    }
    return v;
}
