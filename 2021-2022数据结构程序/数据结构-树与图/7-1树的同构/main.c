#include <stdio.h>
#include <stdlib.h>
#define null -1
/*
��������˼·�ǰ���mooc��һ��һ������
�ؼ��㻹�������Ǹ�����
��ʱ�������˺ܾõľ����Ǹ������в���д����
����ݹ����������ж�
���������Ϊ��
��ͬ��
�����һ��Ϊ����һ�Ų�Ϊ��
��ͬ��
�����������Ϊ�� ���ǽ��ֵ��Ӧ��ͬ
��ͬ��
���������Ϊ�� �ҽ��ֵ��ͬ �� ������������
��ȥ�ж��������Ƿ�ͬ�� �������Ƿ�ͬ��
����
�����ж� ��һ������͵ڶ������� ��һ�����Һ͵ڶ�������
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
    int check[n];//����������Ѱ�Ҹ��ڵ� ���ڵ����Ǹ�û���κν��ָ�����Ľ�� ���������û�б����ʹ� ��ô�����Ǹ��ڵ�
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
    //���������� ��Ԫ����� ����Ҫ��ת
    if( (t1[r1].left != null && t2[r2].left != null)
       && (t1[t1[r1].left].c == t2[t2[r2].left].c) )
        return isomorphic(t1[r1].right,t2[r2].right)&&
                isomorphic(t1[r1].left,t2[r2].left);
    else
         return (isomorphic(t1[r1].left,t2[r2].right)&&
                isomorphic(t1[r1].right,t2[r2].left));
}
int judge(int R1,int R2){
	if(R1 == null && R2 == null)   // ��Ϊ��
		return 1;
	if(R1 == null && R2 != null || R1 != null && R2 == null)    // һ��Ϊ�գ�һ����Ϊ��
		return 0;
	if(t1[R1].c != t2[R2].c)   // ֵ��ͬ
		return 0;
	if( (t1[R1].left != null && t2[R2].left != null )
       &&(t1[t1[R1].left].c == t2[t2[R2].left].c))  // ����Ӳ�Ϊ����ֵ���
		return judge(t1[R1].left,t2[R2].left) && judge(t1[R1].right,t2[R2].right);
	else   // ����Ӳ�Ϊ����ֵ����  ���� ĳһ�������Ϊ��
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
