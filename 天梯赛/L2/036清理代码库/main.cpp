#include <cstdio>
#include <map>
#include <vector>
#include <algorithm>
//������ԭ�Ȳ��õ���string����vector �������������Ե����ȥ
//�������Ǳ��˽������Ż��Ĵ��� �ڴ������Ч�ʶ�����
//���˵�STL�õ�����˳���� �Ҷ���֪��vector���ԱȽϴ�С ���� ���˰����˰�
using namespace std;
int main ()
{
    int n,mm,data;
    scanf("%d%d",&n,&mm);
    vector<int> ve;
    map<vector<int>,int> m;
    vector<pair<int,vector<int> > > v;
    for(int i = 0; i < n; i++)
    {
        ve.clear();
        for(int j = 0; j < mm; ++j)
        {
            scanf("%d",&data);
            ve.push_back(data);
        }
        m[ve]++;
    }
    for(auto &i:m)
    v.push_back({-i.second,i.first});
    sort(v.begin(),v.end());
    printf("%d",(int)v.size());
    for(auto &i:v)
    {
        printf("\n%d",-i.first);
        for(auto j:i.second)
            printf(" %d",j);
    }
    return 0;
}
