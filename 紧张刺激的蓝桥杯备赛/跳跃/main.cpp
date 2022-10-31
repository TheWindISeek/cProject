#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    // 请在此输入您的代码
    int n,m;
    scanf("%d %d",&n,&m);
    int g[n][m];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            scanf("%d",&g[i][j]);
    int f[n][m];
    memset(f,0,sizeof(f));
    f[0][0] = g[0][0];
    for(int j = 1; j < m;j++)
    {
        int maxn = -10001;
    for(int k = j-1; k>=0&&k>=j-3; k--)
                maxn = max(f[0][k],maxn);
                f[0][j] = maxn+g[0][j];
    }
    for(int i = 1; i < n; i++)
    {
        int maxn = -10001;
        for(int j = 0; j < m; j++)
    {
        for(int k = j-1; k>=0&&k>=j-3; k--)
                maxn = max(f[i][k],maxn);
            for(int k = i-1; k>=0&&k>=i-3; k--)
                maxn = max(f[k][j],maxn);
              //  cout <<i<<' '<<j<<' '<<maxn<<endl;
            f[i][j] = g[i][j] + maxn;
        }
    }
    printf("%d",f[n-1][m-1]);
    return 0;
}
