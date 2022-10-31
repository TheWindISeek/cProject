//并查集的应用
#include <stdio.h>
#include <stdlib.h>
/*现在遇到的问题就是 怎么去确定树根 怎么去判断是不是在同一集合*/
#define N 30005
#define M 1005
/*
很简单的一个并查集的应用
*/
int tree[N];
int visit[N];
//根据给定的key值
int find(int key){
    if(tree[key] > 0)
    return tree[key] = find(tree[key]);
    return key;
}
void Union(int x,int y){
    int root1 = find(x);
    int root2 = find(y);
    //printf("%d %d ",root1,root2);
    if(root1 == -1 && root2 == -1)
    {
        tree[root1] += tree[root2];
        tree[root2] = root1;
        return;
    }
    if(root1 < root2){
        tree[root1] += tree[root2];
        tree[root2] = root1;
    }else if (root1 > root2){
        tree[root2] += tree[root1];
        tree[root1] = root2;
    }
}
int main (){
    /*输入的第一行包含两个正整数N（≤30000）和M（≤1000）*/
    int i,n,m,k,data,first;
    //初始化
    for(i = 0; i < N;++i){
        tree[i] = -1;
        visit[i] = 0;
    }
    scanf("%d %d",&n,&m);
    while(m--){
        scanf("%d %d",&k,&first);
        if(!visit[first])
            visit[first] = 1;
        for(i=1; i < k;++i){
            scanf("%d",&data);
            if(!visit[data])
                visit[data] = 1;
            Union(first,data);
        }
    }
    int sum = 0;
    for(i = 1; i <=n; ++i){
        //printf("%d ",tree[i]);
        if(sum > tree[i])
            sum = tree[i];
    }
    printf("%d",-sum);
        return 0;
}
