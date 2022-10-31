#include <stdio.h>
#include <stdlib.h>
#define N 1003
typedef struct node * tree;//定义指向结点的指针
struct node
{
    tree left,right;
    int data;
};
int index;//用于输出的数组的游标
tree creat(tree root,int data)
{
    if(root)
    {
        if(root->data > data)//题目数据要求为严格小于
            root->left = creat(root->left,data);
        else
            root->right = creat(root->right,data);
    }
    else
    {
        root = (tree)malloc(sizeof(struct node));
        root->data = data;
        root->left = root->right= NULL;
    }
    return root;
}
//后序遍历 将东西放到输出数组中去
void postOrder(tree root,int output[])
{
    if(root)
    {
        postOrder(root->left,output);
        postOrder(root->right,output);
        output[index++] = root->data;
    }
}
//先序遍历将数据放入输出数组
void preOrder(tree root,int output[])
{
    if(root)
    {
        output[index++] = root->data;
        preOrder(root->left,output);
        preOrder(root->right,output);
    }
}
//交换树的左右孩子
void swap(tree root)
{
    if(root)
    {
        tree temp = root->left;
        root->left = root->right;
        root->right = temp;
        swap(root->left);
        swap(root->right);
    }
}
int main ()
{
    int n;//结点总数n
    int i,data,j;//两个循环变量与读取数据的变量
    int f,flag,mirror_flag;//判断是何种情况的标志变量
    tree root = NULL;//建树的根
    int output[N],input[N];//输入输出数组
//赋值
    f = flag = mirror_flag = 1;
    index = 0;
    //读取数据
    scanf("%d",&n);
    for(i = 0; i < n; i++)
    {
        scanf("%d",&data);
        input[i] = data;//放入输入数组便于后续比较
        root = creat(root,data);
    }
    //先判断是不是正常的二叉树
    index = 0;
    preOrder(root,output);
    for(i = 0; i < n; i++)
        if(output[i] != input[i])
            flag = 0;
            //再判断是不是镜像二叉搜索树
    index = 0;
    swap(root);
    preOrder(root,output);
    for(i = 0; i < n; i++)
        if(output[i] != input[i])
            mirror_flag = 0;
    index = 0;
    if(mirror_flag)//如果是镜像的已经交换过了 所以直接后序即可
    {
        printf("YES\n");
        postOrder(root,output);
        for(i = 0; i < index; i++)
        {
            if(f)
                f = 0;
            else
                printf(" ");
            printf("%d",output[i]);
        }
    }
    else if(flag)//正常的 需要先交换一次
    {
        printf("YES\n");
        swap(root);
        postOrder(root,output);
        for(i = 0; i < index; i++)
        {
            if(f)
                f = 0;
            else
                printf(" ");
            printf("%d",output[i]);
        }
    }
    else
        printf("NO\n");
    return 0;
}
