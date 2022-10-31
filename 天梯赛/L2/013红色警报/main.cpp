#include <vector>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
#define N 501
#define M 5001
//n m
/*��Ȼȫ���� ������ô�о���һ���е�ˮ�� ��*/
//����һ��������ǲ�uȥʲô�������ݽṹȥ�洢ͼ
//Ȼ������Ҫһ���ܼ��ͼ��ͨ�Եĺ��� ���ص�Ӧ����ͼ����ͨ��֧����
//�������ܴ����������Ϣ ���������ݽṹ��Ӧ������һ�����Լ����м���� ����ÿ�ζ�������
//ͬʱ����Ҫȥ�ж�ʧȥ���еĸ���һ�����еĳ��ж�ʧȥ�� ��ôҪ�����Ϸ����
//��������Ͳ���ͨ ʧȥһ�����в��ı�����������ͨ�Բ���������
//���뱣֤���б�����ظ� ����ͨ·�����ظ�
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
    //printf("ԭ������ͨ��֧����:%d\n",old);
    for(int i = 0; i < k; i++)
    {
        scanf("%d",&data);
        visit[data] = 1;
        alter = readConnect();
        //printf("ɾ��%d�����ͨ��֧����%d\n",data,alter);
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
