#include <bits/stdc++.h>
using namespace std;
int gcd(int x,int y)
{
    if(y == 0)
        return x;
    return gcd(y,x%y);
}
//最短路径的动态规划 真是神了 心中一惊
int main()
{
    int f[2022];
    memset(f,0,sizeof f);
    for(int i = 1;i <= 2021;i++) {
        for(int j = i+1;j <= i+21;j++) {
            if(j > 2021)
                break;
            if(f[j] == 0)
                f[j] = f[i]+j*i/gcd(j,i);
            else
                f[j] = min(f[j],f[i]+j*i/gcd(j,i));
        }
    }
    cout << f[2021] << endl;
    return 0;
}
