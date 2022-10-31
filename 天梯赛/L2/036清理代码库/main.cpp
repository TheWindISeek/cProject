#include <cstdio>
#include <map>
#include <vector>
#include <algorithm>
//此题我原先采用的是string而非vector 但是有两个测试点过不去
//现在这是别人进行了优化的代码 内存和运行效率都不错
//别人的STL用的真是顺畅啊 我都不知道vector可以比较大小 汗颜 算了吧算了吧
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
