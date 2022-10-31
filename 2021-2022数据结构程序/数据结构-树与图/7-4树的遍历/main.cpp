#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <queue>
/*
根据树的后续和中序确定树
根据树确定树的层次遍历
不难
*/
using namespace std;
typedef struct Tree{
    int data;
    struct Tree * left;
    struct Tree * right;
}*tree;

tree recovery(int post[],int in[],int i,int j,int k,int m)
{
    tree t = (tree) malloc(sizeof(struct Tree));
    t ->data = post[j];
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
void levelOrder(tree root){
    queue<tree> q;
    q.push(root);
   tree temp = NULL;
    int flag = 1;
    while(!q.empty()){
        temp = q.front();
        q.pop();
        if(flag){
            printf("%d",temp->data);
            flag = 0;
        }
        else
            printf(" %d",temp->data);

        if(temp -> left != NULL)
            q.push(temp->left);
        if(temp->right != NULL)
            q.push(temp->right);
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
    tree t = restore(post,in,n);
    levelOrder(t);
    return 0;
}
