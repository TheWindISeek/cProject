/*
构建无向图
删除相关边 存储这些边
判断连通性
重新补充这些边
*/
#include <iostream>
#include <cstdio>
#include <map>
#include <vector>
using namespace std;
const int N = 10005;

typedef struct
{
    int x;
    int y;
} edge;
edge e[N];
int main ()
{
    int n,m,k,num,city,j;
    map<int,int> mp;
    scanf("%d %d",&n,&m);
    for(int i = 1; i <= m; i++)
    {
        scanf("%d %d",&e[i].x,&e[i].y);
    }
    scanf("%d",&k);
    while(k--)
    {
        mp.clear();
        scanf("%d",&num);
        while(num--)
        {
            scanf("%d",&city);
            mp[city] = 1;
        }
        for( j = 1; j <= m; j++)
            if(mp[e[j].x] != 1 && mp[e[j].y] != 1)
            {
                printf("No\n");
                break;
            }
        if(j >= m)
            printf("Yes\n");
    }
    return 0;
}
