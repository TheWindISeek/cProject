#include <bits/stdc++.h>

using namespace std;

int main()
{
    int v[6]= {0,6,3,5,4,6};
    int s[6]= {0,2,2,6,5,4};
    int m[101][101];
    int n = 5;
    int c = 10;
    memset(m,0,sizeof(m));
    for(int i = 0; i <= n; i++)
        m[i][0] = 0;
    for(int i = 0; i <= c; i++)
        m[0][i] = 0;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= c; j++) {
            m[i][j] = m[i-1][j];
           // cout << i<<' '<<s[i]<<' '<<j<<' '<<m[i][j]<<endl;
            if(s[i]<=j) {
                    //cout <<"<="<<m[i][j]<<" "<<m[i-1][j-s[i]]<<" "<<v[j]<<endl;
                m[i][j] = max(m[i][j],m[i-1][j-s[i]]+v[i]);

            }
            //cout << i<<' '<<s[i]<<' '<<j<<' '<<m[i][j]<<endl;
        }
    for(int i =1; i <= n; i++) {
        for(int j = 1; j <= c; j++)
            printf("%d ",m[i][j]);
        cout <<endl;
    }
    return 0;
}
