#include <stdio.h>
#include <stdlib.h>
typedef int Position;
typedef struct SNode *PtrToSNode;
struct SNode {
    ElementType *Data;  /* �洢Ԫ�ص����� */
    Position Top;       /* ջ��ָ��       */
    int MaxSize;        /* ��ջ�������   */
};
typedef PtrToSNode Stack;
/*ע�⣺�����ջ������Push�������������Stack Full�����ҷ���false
*/
//����Ԫ��
bool Push( Stack S, ElementType X ){
    //�����������
if(S ->MaxSize == S->Top){
    printf("Stack Full\n");
    return false;
}
   * (S->Data+S->Top) = X;
S->Top++;
return true;
}
/*��������ǿյģ���Pop�������������Stack Empty�������ҷ���ERROR��*/
ElementType Pop( Stack S ){
if(S == NULL || S -> Top ==0){
    printf("Stack Empty\n");
    return ERROR;
}
S->Top--;
return *(S->Data+S->Top);
}
int main()
{
    printf("Hello world!\n");
    return 0;
}
