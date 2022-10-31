#include <iostream>
#include <vector>
#include <set>
#include <cmath>
using namespace std;
using ll = long long int;
int main()
{
    // 请在此输入您的代码
    ll n = 2021041820210418;
    ll result = 0;
    ll nn = sqrt(n);
    vector<ll> v;
    for(ll i = 1; i <= nn; ++i)
    {
        if(n%i == 0)
        {
            v.push_back(i);
            if(n/i != i)
                v.push_back(n/i);
        }
    }
    for(ll x : v)
        for(ll y:v)
            for(ll z:v)
                if(x*y*z == n)
                    result++;
    printf("%lld",result);
    return 0;
}
