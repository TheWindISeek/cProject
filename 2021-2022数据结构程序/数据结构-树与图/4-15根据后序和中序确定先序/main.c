#include <stdio.h>
#include <stdlib.h>
typedef struct Tree{
    int data;
    struct Tree * left;
    struct Tree * right;
}*tree;
/*和之前的还原一样的思路*/
tree recovery(int post[],int in[],int i,int j,int k,int m)
{
    tree t = (tree) malloc(sizeof(struct Tree));
    t ->data = post[j];
   /**/
    int s;
    s = k;
    while(in[s] != post[j])
        s++;
    if(s == k)
        t->left = NULL;
    else
        t->left = recovery(post,in,i,i-k+s-1,k,s-1);
    if(s == m)
        t->right = NULL;
    else
        t->right = recovery(post,in,i-k+s,j-1,s+1,m);
    return t;
}
tree restore(int post[],int in[],int n){
    if(n <= 0)
        return NULL;
    else
        return recovery(post,in,0,n-1,0,n-1);
}
void preOrder(tree t){
    if(t){
        printf(" %d",t->data);
        preOrder(t->left);
    preOrder(t->right);
    }
}
int main (){
   int n,i;
    scanf("%d\n",&n);
    int post[n+1],in[n+1];
    for(i = 0; i < n;i++)
        scanf("%d",&post[i]);
    getchar();
    for(i = 0; i< n;++i)
        scanf("%d",&in[i]);
    /* for(i = 0; i < n;i++)
        printf("%d",post[i]);
    for(i = 0; i< n;++i)
        printf("%d",in[i]);*/
    tree t = restore(post,in,n);
    printf("Preorder:");
    preOrder(t);
    return 0;
}
