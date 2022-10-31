#include <iostream>
#include <queue>
using namespace std;
typedef struct node* tree;
struct node{
int data;
tree left,right;
};
int isCBT(tree root)
{
    if(root == NULL)
        return 1;
    else
        return isCompleteBinaryTree(root);
}
int isCompleteBinaryTree(tree root)
{
    queue<tree> q;
    int flag = 0,f = 1;
    q.push(root);
    tree temp = NULL;//算是一个难得没想透的当时已经想到加标记了但是不会加 这个编程现在看来技巧还是有的
    while(!q.empty())
    {
        temp = q.front();
        q.pop();
        if(!temp->left&&temp->right)//如果有右孩子没左孩子 那么肯定是不行的
            f = 0;
        if(temp->left&&flag)//先参考下面的 如果前面的已经是结束标志了 那么再多出一个就是错误的
            f = 0;
        if(!temp->left||!temp->right)//此处的意思是如果只有一个左右为空或者是是叶子结点 那么后面的不应该出现孩子
            flag = 1;
            //不管怎么样这个都需要添加 不然层次遍历的结果会出错
        if(temp->left)
            q.push(temp->left);
        if(temp->right)
            q.push(temp->right);
    }
    return f;
}
int main()
{

    return 0;
}
