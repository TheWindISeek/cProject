#include <iostream>
#include <queue>
using namespace std;
const int N = 1002;
int a[N];
int indegree[N];
int g[N][N];
//���������Ϊ���ȶ��е��������� ����Ҫ��������i��������a[i]�����Ծ���Ҫ�Լ���дһ���Զ���ıȽϷ�ʽ������������ ��Ҫʹ�õ�����������
struct cmp
{
    bool operator()(int x,int y)
    {
        return a[x] > a[y];
    }
};

void top_sort(int n)
{
    //������ҪС������� ��ĺ���� ���⻹��Ҫ���� ���Բ�ȡ���ȶ��� Ҳ���Ƕ�ȥ������������
    int i,x,flag = 1;//���������ʽ��ȷ
    priority_queue<int, vector<int>, cmp > q;
    for(i = 0; i < n; ++i)
    {
        if(indegree[i] == 0 && a[i] >=0)//���Ϊ0���������Ԫ��
            q.push(i);
    }
    while(!q.empty())
    {
        //��һС�鴦���ʽ���
        if(flag) flag = 0;
        else printf(" ");
        //���� ����
        x  = q.top();
        q.pop();
        printf("%d",a[x]);
        //���������е��ڽӵ���з���
        for(i = 0; i < n; i++)
        {
            if(g[x][i] !=-1)//�������֮���бߴ���
            {
                if(--indegree[i] == 0)//��ȼ�С���ж��Ƿ�Ϊ0
                    q.push(i);
            }
        }
    }
}
int main ()
{
    int n;
    int i,x,j;
    cin >> n;
    for(i = 0; i < n; ++i)
        cin >> a[i];
    for(i =0; i< n; ++i)
    {
        indegree[i] = 0;
        for(j =0; j<n; j++)
            g[i][j]=-1;
    }
    for(i = 0; i < n; ++i)
    {
        if((a[i]%n) == i || a[i] < 0)
            continue;
        else //�����ж�������ָ����
        {
            x = a[i]%n;
            while(x != i)
            {
                //���ò�˵ ����е���
                //Ҫ�ﵽ��Ŀ���� �������Ǿ�������̽��֮��ŷŵ���ǰλ�õ� �����ǰλ��Ҳ����i x��������Ӧ�÷ŵĵط�
                /*����x������i��ʱ�� Ҳ���Ǵ����￪ʼ����̽�� ÿ��̽��������ǲ����� ��ô����̽��������ڵ�Ԫ�ض�Ӧ������ǰ�����
                �����������Ⱦ�Ҫ����1
                ���������i �ǵ�i�� ��Ϊ֮���������ӳ��ȥ���в����� ֮��Ϊ�ڽӾ�������� ����� �ӵ�ǰ�㵽i�ı� ��Ҫ�ŵ�Ԫ����i����ȥ�����ڽӱ�*/
                indegree[i]++;
                g[x][i] = i;
                x = (x+1)%n;
            }
        }
    }
    top_sort(n);
    return 0;
}
