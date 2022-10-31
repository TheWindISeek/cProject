#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;
#define max  1002
typedef struct{
    int u;
    int v;
    int weight;
}edge;
//最小生成树 要检查连通性
bool cmp (edge&x,edge&y){
    return x.weight < y.weight;
}
int tree[max];
int cost;
int find(int key){
    if(key != tree[key])
        return tree[key] = find(tree[key]);
    return key;
}
void Union(edge ed){
    int root1 = find(ed.u);
    int root2 = find(ed.v);
    if(root1 != root2)
    {
        tree[root2] = root1;
        cost += ed.weight;
    }
}
int main (){
    int n,m;
    int u,v, weight;
    edge e[3*max];
    cin >> n >> m;
    cost = 0;
    for(int i = 1; i <= n; i++){
        tree[i] = i;
    }
    for(int i = 1; i <= m;++i){
        cin >> u >> v >> weight;
        e[i].u = u;
        e[i].v = v;
        e[i].weight = weight;
    }
    sort(e+1,e+m+1,cmp);
    for(int i = 1; i <=m;++i){
        Union(e[i]);
    }
    int c = 0;
    for(int i = 1; i <= n;++i){
        if(tree[i] == i)
            c++;
    }
    if(c > 1)
        printf("-1");
    else
        printf("%d",cost);
    return 0;
}
