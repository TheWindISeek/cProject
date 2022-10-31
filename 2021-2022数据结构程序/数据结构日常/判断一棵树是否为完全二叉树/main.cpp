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
    tree temp = NULL;//����һ���ѵ�û��͸�ĵ�ʱ�Ѿ��뵽�ӱ���˵��ǲ���� ���������ڿ������ɻ����е�
    while(!q.empty())
    {
        temp = q.front();
        q.pop();
        if(!temp->left&&temp->right)//������Һ���û���� ��ô�϶��ǲ��е�
            f = 0;
        if(temp->left&&flag)//�Ȳο������ ���ǰ����Ѿ��ǽ�����־�� ��ô�ٶ��һ�����Ǵ����
            f = 0;
        if(!temp->left||!temp->right)//�˴�����˼�����ֻ��һ������Ϊ�ջ�������Ҷ�ӽ�� ��ô����Ĳ�Ӧ�ó��ֺ���
            flag = 1;
            //������ô���������Ҫ��� ��Ȼ��α����Ľ�������
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
