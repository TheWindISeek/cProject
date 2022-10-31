#include <iostream>

using namespace std;
void swap(int &m,int &n)
{

    int temp ;
    temp = m;
    m = n;
    n = temp;
}
void move(int *a,int n,int m)
{
    for(int i = m-1; i>=0; i--)
    {
        swap(a[i],a[n-m+i]);

    }
}
template<typename T>
bool _min(const T& a,const T & b)
{
    return a < b;
}
int main()
{
    int n;
    int m;
    scanf("%d %d",&n,&m);
    int a[n];
    for(int i=0; i <n; i++)
    {
        cin>>a[i];
    }
    int nn = n;
    while(n!=1)
    {
        move(a,n,m);
        n = n-m;
        if(n<m)
            m = m-n;
    }
    for(int i = 0; i<nn; i++)
    {
        cout<<a[i]<<" ";
    }
}
