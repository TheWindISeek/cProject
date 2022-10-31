#include <iostream>
#include <stack>
#include <queue>
#include <map>
#include <cmath>
using namespace std;
using ll = long long int;
map<char,ll> m;
#define ERROR -1
ll toDe(string a,int radix){
    queue<ll> q;
    ll final_num = 0;
    for(char c:a)
            q.push(m[c]);
    while(!q.empty()){
            final_num = (q.front()+final_num)*radix;
            q.pop();
        }
        final_num/=radix;
    return final_num;
}
int judge(string a,ll final_num)
{
    ll m;
    ll left = 2,right = toDe(a,10),mid;
while(left <= right){
    mid = (right-left)/2+left;
    m = toDe(a,mid);
    if(m == final_num)
        return mid;
    else if(m > final_num|| m < 0)
        right = mid -1;
    else
        left = mid+1;
}
return ERROR;
}
int main ()
{
    string a,b;
    ll tag,radix,which;
    ll final_num = 0;
    m['0'] = 0;
    m['1'] = 1;
    m['2'] = 2;
    m['3'] = 3;
    m['4'] = 4;
    m['5'] = 5;
    m['6'] = 6;
    m['7'] = 7;
    m['8'] = 8;
    m['9'] = 9;
    m['a'] = 10;
    m['b'] = 11;
    m['c'] = 12;
    m['d'] = 13;
    m['e'] = 14;
    m['f'] = 15;
    m['g'] = 16;
    m['h'] = 17;
    m['i'] = 18;
    m['j'] = 19;
    m['k'] = 20;
    m['l'] = 21;
    m['m'] = 22;
    m['n'] = 23;
    m['o'] = 24;
    m['p'] = 25;
    m['q'] = 26;
    m['r'] = 27;
    m['s'] = 28;
    m['t'] = 29;
    m['u'] = 30;
    m['v'] = 31;
    m['w'] = 32;
    m['x'] = 33;
    m['y'] = 34;
    m['z'] = 35;
    cin >> a >> b >> tag >> radix;
    if(tag == 2)
        swap(a,b);
final_num = toDe(a,10);
which = judge(b,final_num);
    if(which == ERROR)
        printf("Impossible");
    else
        printf("%d",which);
    return 0;
}
