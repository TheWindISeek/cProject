//�����ڽӾ���洢ͼ ����Floyd�㷨���ÿ�����㵽������������ľ��� ��ͨ�Ե��жϲ������������·��ֵ�Ƿ��������
#include <iostream>
#define inf 65535
using namespace std;
int n,m;//ͼ�ж������ͱ���

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
    //���һ�и�����Ҫ������ܶ������Ե�������ĸ���K����100���Լ�K�������
    return 0;
}
