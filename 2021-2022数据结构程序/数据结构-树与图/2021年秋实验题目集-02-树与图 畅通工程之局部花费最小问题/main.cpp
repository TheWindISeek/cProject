#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
/*
该题目为最小生成树的题目
唯一的技巧是如果连通了
则将相对应的权值置为0 而不是它给出的数值
然后利用prim算法或者树合并的那种算法即可
这个代码是prim算法
另外一个编程容易
整体框架分为初始化矩阵 注意采取边存储的方式
边有关联的两个点 已经对应的权值
然后读取数据
最后按边权值的从小到大进行排序
最后再从小到大进行归并
输出结果即可
*/
using namespace std;
#define INF 0xffffff
#define N 105
//prim算法版本
int adjmatrix[N][N];
int lowcost[N];
int sumcost = 0;
void prim(int v,int n)
{
    int mincost;
    int k,i,j;
    for( i = 1; i <= n; ++i)
    {
        lowcost[i] = adjmatrix[v][i];
    }
    lowcost[v] = -1;
    for(i = 0; i < n-1; ++i)
    {
        mincost = INF;
        for(j = 1; j <=n; ++j)
        {
            //没有被访问过并且可以更新的时候
            if(lowcost[j] != -1 && lowcost[j] < mincost)
            {
                mincost = lowcost[j];
                k = j;
            }
        }
        //在访问完成后更新结点
        sumcost += mincost;
        lowcost[k] = -1;
//
        for(j = 1; j <=n; ++j)
        {
            if(adjmatrix[k][j] < lowcost[j] && j !=k)
            {
                lowcost[j] = adjmatrix[k][j];
            }
        }
    }
}
int main()
{
    int i,j,n,first,second,weight,build;
    scanf("%d",&n);
    for(i = 0; i < N; i++)
        for(j = 0; j < N; j++)
            adjmatrix[i][j] = INF;
    for(i = 1; i <=n*(n-1)/2; ++i)
    {
        scanf("%d %d %d %d",&first,&second,&weight,&build);
        if(build)
            adjmatrix[first][second] = adjmatrix[second][first] = 0;

        else
            adjmatrix[first][second] = adjmatrix[second][first] = weight;
    }
    prim(1,n);
    cout << sumcost << endl;
    return 0;
}
