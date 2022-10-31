//并查集的应用
#include <stdio.h>
#include <stdlib.h>
/*
人的关系
认为朋友的朋友也是朋友
等价关系 采取并查集 我就是稍微不难理解这样读取数据会不会出现重复元素的情况
*/
/*
我现在明白了 它是采取类似动态更新的方式当当前这个结点和下一个结点的根不一样的时候就让它指向下一个的结点
*/
/*
现在遇到的问题就是 怎么去确定树根 怎么去判断是不是在同一集合*/
int tree[10010];
int visit[10010];
//根据给定的key值
int find(int key){
    if(key != tree[key])
    return tree[key] = find(tree[key]);
    return key;
}
void Union(int x,int y){
    int root1 = find(x);
    int root2 = find(y);
    if(root1 != root2)
        tree[root1] = root2;
}
int main (){
    //读取数据建立并查集 并与查
    //依据所得数据判断有多少个圈子 遍历整个 看有多少个小于0
    //根据查询 输出对应 find
    int i,n,k,data,first,sum = 0,ans=0,N;
    //初始化
    for(i = 0; i < 10010;++i){
        tree[i] = i;
        visit[i] = 0;
    }
    scanf("%d",&n);
    N=n;
    while(n--){
        scanf("%d %d",&k,&first);
        if(!visit[first])
        {
            visit[first] = 1;
            sum++;
        }
        for(i=1; i < k;++i){
            scanf("%d",&data);
            if(!visit[data])
            {
                visit[data] = 1;
                sum++;
            }
            Union(first,data);
        }
    }
    for(i = 1; i < 10010;++i){
        if(visit[i] && i == find(i))
            ans++;
    }
    printf("%d %d\n",sum,ans);
    scanf("%d",&k);
    while(k--){
        scanf("%d %d",&first,&data);
        if(find(first) == find(data))
            printf("Y\n");
        else
            printf("N\n");
    }
    for(int i =1; i <= sum;++i)
    {
        printf("%d:%d\t\n",i,tree[i]);
    }
    return 0;
}
