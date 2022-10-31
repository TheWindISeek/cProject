#include <stdio.h>
#include <stdlib.h>
typedef struct Tree{
    char data;
    struct Tree * left;
    struct Tree * right;
}*tree;
/*根据先序和中序还原二叉树*/
tree recovery(char pre[],char in[],int i,int j,int k,int m)
{
    tree t = (tree) malloc(sizeof(struct Tree));
    t ->data = pre[i];
    int s;
    s = k;
    while(in[s] != pre[i])
        s++;
    if(s == k)
        t->left = NULL;
    else
        t->left = recovery(pre,in,i+1,i+s-k,k,s-1);
    if(s == m)
        t -> right = NULL;
    else
        t -> right = recovery(pre,in,i+s-k+1,j,s+1,m);
    return t;
}
tree restore(char pre[],char in[],int n){
    if(n <= 0)
        return NULL;
    else
        return recovery(pre,in,0,n-1,0,n-1);
}
int getHeight(tree t){
    int max = 0;
    if(t)
    {
        int l = getHeight(t ->left),r = getHeight(t->right);
        max = (l > r?l:r) + 1;
    }
    return max;
}
int main (){
    int n,i;
    scanf("%d\n",&n);
    char pre[n+1],in[n+1];
    for(i = 0; i < n;++i)
        scanf("%c",&pre[i]);
    getchar();
    for(i = 0; i < n;++i)
        scanf("%c",&in[i]);
   /* for(i = 0; i < n;++i)
        printf("%c",pre[i]);
    printf("\n");
    for(i = 0;i < n;++i)
        printf("%c",in[i]);*/
    tree t = restore(pre,in,n);
    printf("%d",getHeight(t));
    return 0;
}
