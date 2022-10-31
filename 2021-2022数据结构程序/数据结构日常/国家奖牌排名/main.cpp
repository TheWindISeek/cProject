#include <iostream>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;
const int N = 225;
/*
0到n-1编号
4 4
51 100 1000
36 110 300
6 14 32
5 18 40
0 1 2 3
m个前来咨询的国家
输出
先给出排名 再加上冒号:  给出是按什么的排名
1代表着金牌榜
2代表着奖牌榜
3代表着人均金牌榜
4代表着人均奖牌榜
*/
/*对于这题我现在的想法是 先按各种方式进行排序 从4到1 然后去更新最优排名 同时注明是哪个排序方式*/
typedef struct country
{
    int gold;//金牌个数
    int all;//所有的奖牌的个数
    int num;//所有人的数量
    int choose;//是什么排序
    int rank;//在这排序下的排名
} Country;
Country c[N];
//感觉应该是使用表排序的处理方式

//对于当前的国家 输出最有利的排序方式
inline bool
gold_cmp (int x,int y)
{
    return c[x].gold > c[y].gold;
}
inline bool
gold_equal (int x,int y)
{
    return c[x].gold == c[y].gold;
}
inline bool
ave_num_cmp(int x,int y)
{
    return c[x].all * c[y].num > c[y].all * c[x].num;
}
inline bool
ave_num_equal(int x,int y)
{
    return (c[x].all * c[y].num) == (c[y].all * c[x].num);
}
inline bool
ave_gold_cmp(int x,int y)
{
    return c[x].gold * c[y].num > c[y].gold * c[x].num;
}
inline bool
ave_gold_equal(int x,int y)
{
    return c[x].gold * c[y].num == c[y].gold * c[x].num;
}
inline bool
all_cmp (int x,int y)
{
    return c[x].all > c[y].all;
}
inline bool
all_equal (int x,int y)
{
    return c[x].all == c[y].all;
}
void sort_rank(int n,bool(*cmp)(int,int),bool(*equal)(int,int),int choose)
{
    int table[N],i,rank[N];
    for(i = 0; i < n; i++){
        table[i] = i;
        rank[i] = i;
    }
    sort(table,table+n,cmp);
    rank[0] = 1;
    for(i = 1 ; i < n; i ++)
    {
        if((*equal)(table[i],table[i-1]))
            rank[i] = rank[i-1];
    }
    cout << choose<<endl;
    for(i = 0; i < n; i++)
        cout << rank[i]<<" ";
    cout << endl;
    for(i = 0; i < n; i++)
    {
        if(c[table[i]].rank >= rank[i])//排名不能完全按照这个来 排名不是i+1而是要考虑之前的和当前是不是一致的 如果是一致的 则需要对其进行修改
        {
            c[table[i]].rank = rank[i];
            c[table[i]].choose = choose;
        }
    }
}
int main ()
{
    int n,m,which,i;
    cin >> n >> m;

    for(i = 0; i < n; i++)
    {
        cin >> c[i].gold >> c[i].all >> c[i].num;
        c[i].rank = N+1;
        c[i].choose = 0;
    }
    sort_rank(n,ave_num_cmp,ave_num_equal,4);
    sort_rank(n,ave_gold_cmp,ave_gold_equal,3);
    sort_rank(n,all_cmp,all_equal,2);
    sort_rank(n,gold_cmp,gold_equal,1);
    int flag = 1;
    while(m--)
    {
        if(flag)
            flag = 0;
        else
            printf(" ");
        cin >> which;
        printf("%d:%d",c[which].rank,c[which].choose);
    }
    return 0;
}
