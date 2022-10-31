#include <cstdio>
#include <algorithm>
#define N 1005
using namespace std;
typedef struct
{
    double total;
    double price;
    double ave;
} mooncake;
mooncake m[N];
bool cmp(mooncake &x,mooncake &y)
{
    return x.ave > y.ave;
}
int main ()
{
    int n,mm,i;
    double sum = 0,sold = 0;
    scanf("%d%d",&n,&mm);
    for( i = 0; i < n; i++)
        scanf("%lf",&m[i].total);
    for(i = 0; i < n; i++)
        scanf("%lf",&m[i].price);
    for(i = 0; i < n; i++)
        m[i].ave = m[i].price/m[i].total;
    sort(m,m+n,cmp);
    //按价格这样排列 然后看单价如何 然后根据单价决定
     /*for(i = 0; i < n; i++)
         printf("%lf %lf %lf\n",m[i].ave,m[i].total,m[i].price);*/
    for(i = 0; i < n; i++)
    {
        sold+=m[i].total;
        //printf("%lf %lf\n",sold,m[i].total);
        if(sold >= mm)
            break;

    }
    for(int k = 0; k < i; k++)
        sum+=m[k].price;
    sum+=(mm+m[i].total-sold)*m[i].ave;
    printf("%.2lf",sum);
    return 0;
}
