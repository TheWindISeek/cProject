#include <iostream>
#include <queue>
typedef struct node* tree;
struct node
{
    int data;
    tree left,right;
};
using namespace std;
const int N = 31;
tree re(int post[],int pb,int pe,int in[],int ib,int ie)
{
    tree root = (tree)malloc(sizeof(struct node));
    root->left = root->right = NULL;
    root->data = post[pe];
    int m = ib;
    while(in[m] != post[pe])
        m++;
    if(m == ib)
        root->left = NULL;
    else
        root->left = re(post,pb,pb+m-1-ib,in,ib,m-1);
    if(m == ie)
        root->right = NULL;
    else
        root->right = re(post,pb+m-ib,pe-1,in,m+1,ie);
    return root;
}
tree recover(int post[],int in[],int n)
{
    if(n <= 0)
        return NULL;
    else
        return re(post,0,n-1,in,0,n-1);
}
void levelOrder(tree root)
{
    queue<tree> q;
    tree temp = NULL;
    int flag = 1;
    q.push(root);
    while(!q.empty())
    {
        if(flag)
            flag = 0;
        else
            printf(" ");
        temp = q.front();
        q.pop();
        printf("%d",temp->data);
        if(temp->left)
            q.push(temp->left);
        if(temp->right)
            q.push(temp->right);
    }
}
int main()
{
    //后序和中序 输出层次
    int n;
    int post[N];
    int in[N];
    scanf("%d",&n);
    for(int i = 0; i < n; i++)
        scanf("%d",&post[i]);
    for(int i = 0; i < n; i++)
        scanf("%d",&in[i]);
    tree root = recover(post,in,n);
    levelOrder(root);
    return 0;
}
