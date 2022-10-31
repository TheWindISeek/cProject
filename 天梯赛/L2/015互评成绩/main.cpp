#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
    int n,k,m,max,min,sum,flag = 1,data;
    scanf("%d%d%d",&n,&k,&m);
    float a[10001]= {0};
    for(int i = 0; i < n; i++)
    {
        sum = 0;
        max = 0;
        min = 101;
        for(int j = 0; j < k; j++)
        {
            scanf("%d",&data);
            if(max < data)
                max = data;
            if(min > data)
                min = data;
            sum+=data;
        }
        a[i] = (float)(sum-max-min)/(k-2.0);
    }
    sort(a,a+n);
    for(int i = n-m;i < n;i++)
    {
        if(flag)
            flag = 0;
        else
            printf(" ");
        printf("%.3f",a[i]);
    }
    return 0;
}
