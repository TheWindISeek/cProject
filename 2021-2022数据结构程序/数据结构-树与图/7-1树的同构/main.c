#include <stdio.h>
#include <stdlib.h>
#define null -1
/*
这题整体思路是按照mooc上一步一步来的
关键点还是在于那个函数
当时的困扰了很久的就是那个函数有参数写错了
这个递归在于如下判断
如果两棵树为空
则同构
如果有一颗为空另一颗不为空
则不同构
如果两个都不为空 但是结点值对应不同
则不同构
如果两个不为空 且结点值相同 且 都存在左子树
则去判断左子树是否同构 右子树是否同构
否则
交换判断 第一个的左和第二个的右 第一个的右和第二个的左
*/
typedef struct {
    char c;
    int left;
    int right;
}tree;
tree t1[10];
tree t2[10];
int buildTree(tree t[]){
    int n,i,root = null;
    char left,right;
    scanf("%d\n",&n);
    int check[n];//此数组用于寻找根节点 根节点是那个没有任何结点指向它的结点 所以如果它没有被访问过 那么它就是根节点
    if(n){
        for(i = 0; i < n;++i)
            check[i] = 0;
        for(i = 0; i < n;++i){
            scanf("%c %c %c\n",&t[i].c,&left,&right);
            if(left != '-'){
                t[i].left = left-'0';
                check[t[i].left] = 1;
            }else
                t[i].left = null;
            if(right != '-'){
                t[i].right = right-'0';
                check[t[i].right] = 1;
            }else
                t[i].right = null;
        }
        for(i = 0; i < n;++i)
            if(!check[i])
                break;
        root = i;
    }
    return root;
}
int isomorphic(int r1,int r2){
    if((r1 == null) && (r2 == null))
        return 1;
    if(r1==null&&r2!=null || r1!=null&&r2==null)
        return 0;
    if(t1[r1].c != t2[r2].c)
        return 0;
    //左树都不空 且元素相等 不需要旋转
    if( (t1[r1].left != null && t2[r2].left != null)
       && (t1[t1[r1].left].c == t2[t2[r2].left].c) )
        return isomorphic(t1[r1].right,t2[r2].right)&&
                isomorphic(t1[r1].left,t2[r2].left);
    else
         return (isomorphic(t1[r1].left,t2[r2].right)&&
                isomorphic(t1[r1].right,t2[r2].left));
}
int judge(int R1,int R2){
	if(R1 == null && R2 == null)   // 都为空
		return 1;
	if(R1 == null && R2 != null || R1 != null && R2 == null)    // 一个为空，一个不为空
		return 0;
	if(t1[R1].c != t2[R2].c)   // 值不同
		return 0;
	if( (t1[R1].left != null && t2[R2].left != null )
       &&(t1[t1[R1].left].c == t2[t2[R2].left].c))  // 左儿子不为空且值相等
		return judge(t1[R1].left,t2[R2].left) && judge(t1[R1].right,t2[R2].right);
	else   // 左儿子不为空且值不等  或者 某一个左儿子为空
		return judge(t1[R1].right,t2[R2].left) && judge(t1[R1].left,t2[R2].right);
}
int main (){
    int r1,r2;
    r1 = buildTree(t1);
    r2 = buildTree(t2);
    if(isomorphic(r1,r2))
        printf("Yes");
    else
        printf("No");
    return 0;
}
