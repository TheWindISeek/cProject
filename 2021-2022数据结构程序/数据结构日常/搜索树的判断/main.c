#include <stdio.h>
#include <stdlib.h>
#define N 1003
typedef struct node * tree;
/*
�����ʼ���븴����
�Ѽ򵥵��������̫���Ӳ���
���Բ��찡�������һ˫�����Ƿǵ��۾���
������ʵ�ɲ�ȡ��˼·����
���������Ҫ�������鲻�����¼���
����
�ж����Ƕ��������Ǿ��������
�������������ж��������޷�����
��ʱ�Ͱ�ʱ����ڽ���������
�Լ���ôʹ�ö������������
���˲�����·
������ʱ�Ƿ��ֹ�ϵ�˵�
���Ե�����

֮��ѡ��ȥ���˴��� ���忴�ľ�������
��һ�� ���� �ڶ��� ��ô�ж�NO

��ʱҲ���˲��ٷݴ��뵫���ܾ��ò�����
���Ǿ����һ��˼·��ȷ�ģ�ģ��֮����ϵ����Ĵ�������˽ϴ�ĸ��Ƶõ��������ڴ���ĳ���
Ȼ��Ͱ�������д��
������ȥ�ж��Ǿ����ǲ��Ǿ����������
�����һ������������� ������ֻ�ж�����ڵ�Ĵ�С û�й�����Ԫ��֮��� �ŵ�������Щ����
pta��Ȼ˵�����������ʾ ����û�и��������� �����Ǹ���ʾ���ܸо���������ͨ˳ �ر��
�ȸ������Լ������Լ�������ԵĻ�������
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
