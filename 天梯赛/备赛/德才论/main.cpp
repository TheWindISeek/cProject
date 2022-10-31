#include <iostream>
#include <algorithm>
using namespace std;
#define N 100003

int l,n,h;
struct node
{
    string s;
    int a,b;
};struct node a[N];
int level(int a,int b)
{
    if(a >= h&&b>=h)
        return 4;
    if(b<h&&a>=h)
        return 3;
    if(a<h&&b<h&&a>=b)
        return 2;
    return 1;
}
bool cmp(const struct node& x,const struct node & y)
{
    int xlevel = level(x.a,x.b),ylevel = level(y.a,y.b);
    if(xlevel != ylevel)
        return xlevel > ylevel;
    else
    {
        if(x.a+x.b != y.a+y.b)
            return x.a+x.b > y.a+y.b;
        if(x.a != y.a)
            return x.a > y.a;
        return x.s < y.s;
    }
}
int main()
{
    scanf("%d%d%d",&n,&l,&h);
    int aa,b,c= 0;
    string s;
    for(int i = 0; i < n; i++)
    {
        cin >> s >> aa >> b;
        if(aa >= l&&b >= l)
        {
            a[c].s = s;
            a[c].a = aa;
            a[c++].b = b;
        }
    }
    sort(a,a+c,cmp);
    printf("%d",c);
    for(int i = 0; i < c; i++)
    {
        printf("\n");
        cout << a[i].s <<' '<<a[i].a<<' '<<a[i].b;
    }
    return 0;
}
