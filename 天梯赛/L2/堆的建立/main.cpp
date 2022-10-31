#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int heap[10001];
    int heap1[10001];
    int pre[10001];
    for(int i=1; i<=n; i++)
    {
        cin>>pre[i];
        heap[i] = pre[i];
        heap1[i] = pre[i];
    }
    for(int i=1; i<=n; i++)
    {
        int k=i;
        while(k>1&&heap[k]>heap[k/2])
        {
            swap(heap[k],heap[k/2]);
            k=k/2;
        }
    }
    for(int i=1; i <= n; i++)
    {
        int k=i;
        while(k>1 && heap1[k] < heap1[k/2])
        {
            swap(heap1[k],heap1[k/2]);
            k=k/2;
        }
    }
    for (int i = n / 2; i >= 1; i--)
    {
        int par = i,lch;
        int tmp = pre[par];
        for (lch = 2 * par; lch <= n; lch = 2 * par)
        {
            int min = lch;
            if(lch+1 <= n &&pre[lch]>pre[lch+1])
                min++;
            if( pre[min] > tmp)
                break;
            pre[par] = pre[min];
            par = min;
        }
        pre[par] = tmp;
    }
    for(int i=1; i<=n; i++)
    {
        cout<<heap[i];
        if(i != n)
            cout << " ";
    }
    cout << endl;
    for(int i=1; i<=n; i++)
    {
        cout<<heap1[i];
        if(i != n)
            cout << " ";
    }
    cout << endl;
    for(int i=1; i<=n; i++)
    {
        cout<<pre[i];
        if(i != n)
            cout << " ";
    }
    return 0;
}
