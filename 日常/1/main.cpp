#include <bits/stdc++.h>

using namespace std;

typedef  long long ll;

int n,m;

ll maxs(vector<vector<int> > &a, ll x, ll y, ll b, ll e) {

    if(x + 1 == b && y + 1 == e){
           // cout << a[y][x] <<"sdadas"<<endl;
        return a[y][x];
    }
    ll sum = 0;
    for(ll i = x+1; i < b; ++i) {
            cout << x << ' ' <<y <<' ' << i << ' ' << e <<endl;
        sum = max(maxs(a,x,y,i,e)*maxs(a,i,y,b,e), sum);
    }
    for(int j = y+1; j < e; ++j) {
        sum = max(maxs(a,x,y,b,j)*maxs(a,x,j,b,e), sum);
    }
    return sum;
}


int main()
{
    int x;
    printf("%p", &x);//4*4*2byte = 32byte
    int y;
    printf("%p", &y);
    ios::sync_with_stdio(false);
    cin.tie(0);
    scanf("%d %d", &n, &m);
    vector<vector<int> > a(n,vector<int>(m));
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            scanf("%ld", &a[i][j]);
        }
    }
    cout <<maxs(a,0,0,m,n);
    return 0;
}
