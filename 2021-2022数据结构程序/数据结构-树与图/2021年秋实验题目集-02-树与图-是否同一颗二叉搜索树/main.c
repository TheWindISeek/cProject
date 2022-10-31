#include <stdio.h>
#include <stdlib.h>
/*
*����˵��
�Ҳ�ȡ������򵥵�˼·
ֱ�ӽ���һ����
Ȼ���֮��ÿ�ζ�ȡ�Ķ�����һ����
����һ���ݹ麯��ȥ��������ȵ��ж�
��ʵ����mooc�ϵ� ���⻹�и���ⷨ
����ֻ���������뵽��
*/
typedef struct Tree* tree;
struct Tree{
    int data;
    tree left;
    tree right;
};
tree creatTree(tree root,int data){
    if(root){
        if(root->data > data)
           root->left = creatTree(root->left,data);
        else
           root -> right = creatTree(root->right,data);
    }else{
        //printf("data: %d ",data);
    root = (tree)malloc(sizeof(struct Tree));
    root ->left = root -> right = NULL;
    root ->data = data;
    }
    return root;
}
tree buildTree(int n){
    int i,t[n];
    tree root = NULL;
    for(i = 0; i < n;++i){
        scanf("%d",&t[i]);
       root = creatTree(root,t[i]);
    }
    return root;
}
void print(tree root){
    if(root){
        printf("%d ",root->data);
        print(root->left);
        print(root->right);
    }
}
int isSame(tree a,tree b){
    if(a == NULL && b == NULL)
        return 1;
    if(a == NULL || b == NULL)
        return 0;
    if(a->data != b ->data)
        return 0;
    else
        return isSame(a->left,b->left)&&isSame(a->right,b->right);
}
int main (){
    int n,l,flag;
    while(1){
        flag = 0;
    scanf("%d",&n);
    if(n == 0)
        break;
    scanf("%d\n",&l);
       // printf("%d %d\n",n,l);
tree fisrt = buildTree(n);
  //    print(fisrt);
     //   printf("\n");
    while(l--){
        tree temp = buildTree(n);
        if(isSame(fisrt,temp))
            printf("Yes\n");
        else
            printf("No\n");
       // print(temp);
    }
    }
    return 0;
}
