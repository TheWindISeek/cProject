#include <set>
#include <map>
#include <cstdio>
#include <cstring>
using namespace std;
#define N 1001
int father[N];
//����һ��һ���ĸо� �о�д�������� ���� ��Ļ�����ڵ�
/*�����һαװ�Ĳ��鼯����Ŀ ��Ҫͳ�������Ļ���Ҫ��-1 ���鼯֮���й�ϵ���˾��������Ȥֱ������ͬ�����*/
int find(int key)
{
    if(father[key] < 0)
        return key;
    return father[key] = find(father[key]);
}
void Union(int x,int y)
{
    int rootx = find(x),rooty = find(y);
    if(rootx != rooty)
    {
        father[rootx] += father[rooty];
        father[rooty] = rootx;
    }
}
int main()
{
    int n,k,h,f=1;
    set<int> s[N];
    memset(father,-1,sizeof(int)*N);
    scanf("%d",&n);
    for(int i = 1; i <= n; i++)
    {
        scanf("%d:",&k);
        while(k--)
        {
            scanf("%d",&h);
            s[i].insert(h);
        }
    }
    for(int i = 1; i <= n; i++)
    {
        for(int interest:s[i])
            for(int j = 1; j <= n; j++)
                if(j != i&&s[j].count(interest))
                    Union(i,j);
    }
    multiset<int> result;
    for(int i = 1; i <= n; i++)
        if(father[i] < 0)
            result.insert(-father[i]);
    printf("%d\n",(int)result.size());
    for(auto i = result.rbegin(); i != result.rend(); i++)
    {
        if(f)
            f = 0;
        else
            printf(" ");
        printf("%d",*i);
    }

    return 0;
}
