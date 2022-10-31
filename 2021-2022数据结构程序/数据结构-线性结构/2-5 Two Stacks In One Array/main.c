#include <stdio.h>
#include <stdlib.h>
typedef struct StackRecord *Stack;
struct StackRecord  {
    int Capacity;       /* maximum size of the stack array */
    int Top1;           /* top pointer for Stack 1 */
    int Top2;           /* top pointer for Stack 2 */
    ElementType *Array; /* space for the two stacks */
}
//����ջ��һ������ʵ�� �������뷨��һ��ͷָ�� һ��βָ�� Ȼ��˫��
Stack CreateStack( int MaxElements ){
    Stack s = (Stack)malloc(sizeof(struct StackRecord)*MaxElements);
    s->Array = (ElementType*)malloc(sizeof(ElementType)*MaxElements);
    s->Capacity = MaxElements;
    s ->Top1 = -1;
    s-> Top2 = MaxElements;
    return s;
}
//Stacknum˵��Ҫʹ���ĸ�ջ ֻ��Ϊ1��2
//�ж��Ƿ�Ϊ��
int IsEmpty( Stack S, int Stacknum ){
    if (Stacknum == 1)
        return (S->Top1 == -1);
    else
        return (S->Top2 == S->Capacity);
}
//�ж��Ƿ���
int IsFull( Stack S ){
    return (S->Top1 +1==S->Top2);
}
/*Push is supposed to return 1 if the operation can be done successfully, or 0 if fails.
*/
int Push( ElementType X, Stack S, int Stacknum ){
    //ջ����
    if(IsFull(S))
        return 0;
    //�������
    switch(Stacknum){
        case 1:
            S->Top1++;
            S->Array[S->Top1] = X;
            break;
        case 2:
            --S ->Top2;
            S ->Array[S->Top2] = X;
            break;
    }
    return 1;
}
/*If the stack is empty, Top_Pop must return ERROR which is defined by the judge program.*/
ElementType Top_Pop( Stack S, int Stacknum ){
    if(S == NULL||IsEmpty(S,Stacknum)){
        return ERROR;
    }
    switch(Stacknum){
        case 1:
            --S ->Top1;
            return S -> Array[S->Top1+1];
            break;
        case 2:
            ++S ->Top2;
            return S ->Array[S->Top2-1];
            break;
    }
}

int main()
{
    printf("Hello world!\n");
    return 0;
}
