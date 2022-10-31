#include <stdio.h>
#include <stdlib.h>
#define N 1003
typedef struct node * tree;
/*
这题最开始就想复制了
把简单的问题想得太复杂不好
所以苍天啊，请给我一双明辨是非的眼睛吧
整体其实可采取的思路多种
整体程序需要做的事情不过以下几种
建树
判断树是二叉树还是镜像二叉树
根据输入序列判断这序列无法建树
当时就把时间耗在建树那里了
以及怎么使用二叉树这个条件
走了不少弯路
不过这时是发现关系了的
所以倒还好

之后选择去看人代码 主体看的就是两块
第一块 建树 第二块 怎么判断NO

当时也看了不少份代码但是总觉得不合适
于是就针对一种思路明确的，模块之间联系不大的代码进行了较大的改善得到了我现在代码的雏形
然后就把输出板块写好
最后就是去判断是镜像还是不是镜像这个玩意
这个被一种特殊情况坑了 由于我只判断与根节点的大小 没有管其他元素之间的 才导致了这些错误
pta虽然说给出了你的提示 但是没有给测试数据 而且那个提示我总感觉读起来不通顺 特别怪
先给出我自己用于自己代码测试的机组数据
7
8 6 5 7 10 8 11
YES
5 7 6 8 11 10 8

7
8 10 11 8 6 7 5
YES
11 8 10 7 5 6 8

7
8 6 5 7 10 11 8
NO

7
8 6 8 5 10 9 11
NO
*/
struct node
{
    tree left,right;
    int data;
};
int index;
tree creat(tree root,int data)
{
    if(root)
    {
        if(root->data > data)
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

void postOrder(tree root,int output[])
{
    if(root)
    {
        postOrder(root->left,output);
        postOrder(root->right,output);
        output[index++] = root->data;
    }
}
void preOrder(tree root,int output[])
{
    if(root)
    {
        output[index++] = root->data;
        preOrder(root->left,output);
        preOrder(root->right,output);
    }
}
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
    int n;
    int i,data,j;
    int f,flag,mirror_flag;
    tree root = NULL;
    int output[N],input[N];

    f = flag = mirror_flag = 1;
    index = 0;
    scanf("%d",&n);
    for(i = 0; i < n; i++)
    {
        scanf("%d",&data);
        input[i] = data;
        root = creat(root,data);
    }
    index = 0;
    preOrder(root,output);
    for(i = 0; i < n; i++)
    {
        //printf("%d ",output[i]);
        if(output[i] != input[i])
            flag = 0;
    }
    printf("\n");
    index = 0;
    swap(root);
    preOrder(root,output);
    for(i = 0; i < n; i++)
    {
        //printf("%d ",output[i]);
        if(output[i] != input[i])
            mirror_flag = 0;
    }
    printf("\n");
    index = 0;
    if(mirror_flag)
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
    else if(flag)
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
