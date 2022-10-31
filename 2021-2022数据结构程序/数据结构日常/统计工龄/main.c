//利用邻接矩阵存储图 采用Floyd算法求出每个顶点到其他各个顶点的距离 连通性的判断采用任意两点间路径值是否是无穷大
#include <iostream>
#define inf 65535
using namespace std;
int n,m;//图中顶点数和边数

void floyd(int arr[][],int n)
{
    for(int i=0;i<n;i++)
        for(int k=0;k<n;k++)
            for(int j=0;j<n;j++)
            {
                if(i==k||k==j||i==j)
                    continue;
                if(arr[k][i]+arr[i][j]<arr[k][j])
                    arr[k][j]=arr[k][i]+arr[i][j];
            }
}
void check (int u){
    int sum=0;
   for(int i=0;i<n;i++){
       u--;
       sum+=arr[u][i];
   }
    printf("Cc(%d)=%.2f",u++,1.0*(n-1)/sum);
}
int main(){
    cin>>n>>m;
    int i,j;
    int arr[n][n];
    /*arr = (int **)malloc(sizeof(int*)*n);
    for(i = 0; i < n;i++)
    arr[i] = (int *)malloc(sizeof(int)*n);*/
    for(i =0; i < n;i++){
        for( j = 0; j < n;j++)
             arr[i][j] = inf;
    }
   int u,v;
    for(i = 0; i < m;i++)
    {
        cin >> u >> v;
        u--,v--;
        arr[u][v] = 1;
        arr[v][u]=1;
    }
    /*for(i =0; i < n;i++){
        for( j = 0; j < n;j++)
            cout << arr[i][j]<<" ";
        cout << endl;
    }*/
    floyd(arr,n);
    int num;
    cin >> num;
    while(num--){
        cin >> u;
        check(u);
    }
    //最后一行给出需要计算紧密度中心性的这组结点的个数K（≤100）以及K个结点编号
    return 0;
}
