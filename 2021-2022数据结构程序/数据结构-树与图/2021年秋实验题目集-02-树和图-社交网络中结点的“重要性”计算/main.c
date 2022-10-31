
#include <stdio.h>
#include <stdlib.h>
#define N 10000
#define M 100000
#define INF 0x3f3f3f3f
/*
计算方程为n-1/该结点到其余结点的距离之和
*/
/*
整体程序思路
选择数据结构
我选择邻接矩阵
初始化邻接矩阵为无穷远
读取数据
将距离依据读取的数据进行修改
我选择最粗暴的方式
最后看长度
计算即可
*/
int g[N][N];

float Cc(int node ,int n){
    float sum = 0;
    for(int i =1; i <= n;++i)
        if(i != node)
        sum += g[node][i];
    return sum;
}
int main (){

    //读取数据
    int n,m,i,head,tail;
    scanf("%d %d",&n,&m);
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            g[i][j]=INF;//双向图
        }
    }
    for(i = 1; i <= m;++i){
        scanf("%d %d",&head,&tail);
        g[head][tail] = 1;
        g[tail][head] = 1;
    }

    for(int i=1; i<=n; i++){//找出两点间的最短路径
        for(int j=1; j<=n; j++){
            for(int k=1; k<=n; k++){
                if(i==j || i==k || j==k)continue;
                if(g[k][j] > g[k][i]+g[i][j])
                    g[k][j] = g[k][i]+g[i][j];
            }
        }
    }

    int num,node,flag = 1;
    scanf("%d",&num);
    while(num--){
        scanf("%d",&node);
        if(flag){
            flag = 0;
        }else
            printf("\n");
        //printf("%d ",Cc(node,n));
        printf("Cc(%d)=%.2f",node,(float)(n-1)/Cc(node,n));
    }
    return 0;
}
