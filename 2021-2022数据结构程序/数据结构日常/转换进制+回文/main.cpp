#include <iostream>
#include <queue>
#include <stack>
#include <cstring>
using namespace std;
using ll =  long long;
int main(){
    stack<ll> s;
    queue<ll> sn;
    ll n,b;
    ll i = 0,k;
    ll ns[100000];
    cin >> n >> b;
    int flag = 0;
    while(n!=0){
        s.push(n%b);
        n = n/b;
    }
    while(!s.empty())
    {
        ns[i++] = (char)('0'+s.top());
        sn.push(s.top());
        s.pop();
    }
    for(k = 0; k < i/2;k++)
        if(ns[k] != ns[i-k-1])
    {
        flag = 1;
        break;
    }
    if(flag){
        printf("No\n");
    }
    else{
        printf("Yes\n");
    }
    flag = 0;
while(!sn.empty())
{
    if(flag)
        printf(" ");
    else
        flag = 1;
    printf("%d",sn.front());
    sn.pop();
}
   return 0;
}
