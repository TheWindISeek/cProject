#include<bits/stdc++.h>

using namespace std;
bool cmp(int x,int y)
{
    return x > y;
}
int main()
{
    int n,m;
    int flag = 1;
    scanf("%d%d",&n,&m);
    int a[n];
    for(int i = 0; i < n;i++)
        a[i] = i+1;
    for(int i = 0; i < m;i++)
    {
        int p,q;
        scanf("%d%d",&p,&q);
        if(p)
            sort(a+q-1,a+n);
        else
            sort(a,a+q,cmp);
    }
    for(int i = 0; i < n;i++)
    {
        if(flag)
            flag = 0;
        else
            printf(" ");printf("%d",a[i]);
    }
    return 0;
}
