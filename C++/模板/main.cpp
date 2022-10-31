#include<bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int maxn = 110;
int prime[maxn];
bool is_prime[maxn];
int sleve(int n)
{
    int p = 0;//用于记录素数的个数
    memset(is_prime,1,sizeof(is_prime));
    is_prime[0] = is_prime[1] = 0;
    for(int i = 2; i <= n; i++) {
        if(is_prime[i]) {
            prime[p++] = i;
            for(int j = i+1; j<= n; ++j) {
                is_prime[j] = 0;
            }
        }
    }
    return p;
}
typedef long long ll;
ll powmod(ll x, ll n,ll m)
{
    ll res = 1;
    while(n) {
        if(n&1)
            res = (res*x)%m;
        x = (x*x)%m;
        n >>= 1;
    }
    return res;
}

int main()
{
    /*int a[2];
    memset(a,0x3f,sizeof(a));
    cout << a[0]<<endl;
    cout<<INF<<endl;*/
    return 0;
}
