#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
/*
����ĿΪ��С����������Ŀ
Ψһ�ļ����������ͨ��
�����Ӧ��Ȩֵ��Ϊ0 ����������������ֵ
Ȼ������prim�㷨�������ϲ��������㷨����
���������prim�㷨
����һ���������
�����ܷ�Ϊ��ʼ������ ע���ȡ�ߴ洢�ķ�ʽ
���й����������� �Ѿ���Ӧ��Ȩֵ
Ȼ���ȡ����
��󰴱�Ȩֵ�Ĵ�С�����������
����ٴ�С������й鲢
����������
*/
using namespace std;
#define INF 0xffffff
#define N 105
//prim�㷨�汾
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
            //û�б����ʹ����ҿ��Ը��µ�ʱ��
            if(lowcost[j] != -1 && lowcost[j] < mincost)
            {
                mincost = lowcost[j];
                k = j;
            }
        }
        //�ڷ�����ɺ���½��
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
