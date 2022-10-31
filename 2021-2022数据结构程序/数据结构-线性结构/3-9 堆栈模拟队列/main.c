 #include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef int ElementType;
typedef struct stack{
    ElementType*data;
    int maxsize;
    int top;
}*Stack;
//����ջ��������� ����ջ��ָ��
Stack InitStack(int maxsize){
    Stack s = (Stack)malloc(sizeof(struct stack));
    s->maxsize = maxsize;
    s->data = (ElementType*)malloc(sizeof(ElementType)*maxsize);
    s->top = -1;
    return s;
}
//�ж϶�ջS�Ƿ�����������1��0��
int IsFull(Stack S){
    if(S->top == S->maxsize -1)
        return 1;
    else
        return 0;
}
//�ж϶�ջS�Ƿ�Ϊ�գ�����1��0��
int IsEmpty (Stack S ){
    if(S->top == -1)
        return 1;
    else
        return 0;
}
//��Ԫ��itemѹ���ջS��
void Push(Stack S, ElementType item ){
    ++S->top;
    S->data[S->top] = item;
}
//ɾ��������S��ջ��Ԫ�ء�
ElementType Pop(Stack S ){
    return S->data[S->top--];
}
/*
�������е�ÿ��D�����������Ӧ���ӵ����֣����ߴ�����ϢERROR:Empty��
�����Ӳ����޷�ִ�У�Ҳ��Ҫ���ERROR:Full��ÿ�����ռ1�С�
�������ȸ�������������N1��N2����ʾ��ջS1��S2�����������
������һϵ�еĶ��в�����A item��ʾ��item���У��������itemΪ�������֣�
D��ʾ���Ӳ�����T��ʾ���������
*/
/*
3 2
A 1 A 2 A 3 A 4 A 5 D A 6 D A 7 D A 8 D D D D T
*/
int main (){
    int M,N;
    scanf("%d %d",&M,&N);
    int max = (M > N) ? M : N, min = (M < N) ? M : N;
    Stack s1 = InitStack(min),s2 = InitStack(max);
    char op;
    int data;
    do{
     scanf("%c",&op);
        switch(op){
            case 'A':
                scanf("%d",&data);
                //s1���� ѹջ s2 ��Ϊ�� �����
                if(!IsFull(s1))
                     Push(s1,data);
                else//s1ջ��
                {
                    if(!IsEmpty(s2))
                       printf("ERROR:Full\n");
                    else{
                        while(!IsFull(s2) && !IsEmpty(s1))
                            Push(s2,Pop(s1));
                        Push(s1,data);
                    }
                }
                break;
            case 'D':
                if(!IsEmpty(s2))
                    printf("%d\n",Pop(s2));
                else{
                    if(!IsEmpty(s1))
                    {
                         while(!IsFull(s2) && !IsEmpty(s1))
                            Push(s2,Pop(s1));
                        printf("%d\n",Pop(s2));
                    }else
                        printf("ERROR:Empty\n");
                }
                break;
            case 'T':
            case ' ':
                break;
        }
    }while(op != 'T');
    return 0;
}
