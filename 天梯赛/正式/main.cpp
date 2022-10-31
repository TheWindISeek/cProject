#include <bits/stdc++.h>
using namespace std;
const int N = 100001;
set<int> g[N];
int v[N];
int main ()
{
int n,m;
scanf("%d%d",&n,&m);
int root;
for(int i = 1;i <= n;i++)
{
    int data;
    scanf("%d",&data);
    if(data == -1)
        root = i;
    else{
        v[i] = data;
    g[data].insert(i);
    }
}
set<int> st;
int data;
scanf("%d",&data);
st.insert(data);
int cost = 0;
while(data!=root){
    data = v[data];cost++;
}


for(int i = 1; i < m;i++){
int data;
scanf("%d",&data);
}cout << cost+1<<endl;
return 0;
}
