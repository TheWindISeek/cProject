//�����ڽӾ���洢ͼ ����Floyd�㷨���ÿ�����㵽������������ľ��� ��ͨ�Ե��жϲ������������·��ֵ�Ƿ��������
#include <iostream>
#define inf 65535
#define N 10000
using namespace std;
int n,m;
int arr[N][N];





int main()
{
    cin>>n>>m;
    int i,j;

    /*arr = (int **)malloc(sizeof(int*)*n);
    for(i = 0; i < n;i++)
    arr[i] = (int *)malloc(sizeof(int)*n);*/
    for(i =0; i < n; i++)
    {
        for( j = 0; j < n; j++)
            arr[i][j] = inf;
    }
    int u,v;
    for(i = 0; i < m; i++)
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
    for(int i=0; i<n; i++)
        for(int k=0; k<n; k++)
            for(int j=0; j<n; j++)
            {
                if(i==k||k==j||i==j)
                    continue;
                if(arr[k][i]+arr[i][j]<arr[k][j])
                    arr[k][j]=arr[k][i]+arr[i][j];
            }
    int num;
    cin >> num;
    int flag=0;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
        {
            if(arr[i][j]==inf)
                flag=1;

        }
    while(num--)
    {
        cin >> u;
        u--;
        int sum=0;

        for(int i=0; i<n; i++)
        {

            if(arr[u][i]!= inf)
                sum+=arr[u][i];

        }
        if(!sum)
        {
            printf("Cc(%d)=%.2f\n",u+1,0.00);
        }else
        printf("Cc(%d)=%.2f\n",u+1,1.0*(n-1)/sum);
        //���һ�и�����Ҫ������ܶ������Ե�������ĸ���K����100���Լ�K�������

    }
    return 0;
}
