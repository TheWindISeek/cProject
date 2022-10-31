 #include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef int ElementType;
typedef struct stack{
    ElementType*data;
    int maxsize;
    int top;
}*Stack;
//给出栈的最大容量 返回栈的指针
Stack InitStack(int maxsize){
    Stack s = (Stack)malloc(sizeof(struct stack));
    s->maxsize = maxsize;
    s->data = (ElementType*)malloc(sizeof(ElementType)*maxsize);
    s->top = -1;
    return s;
}
//判断堆栈S是否已满，返回1或0；
int IsFull(Stack S){
    if(S->top == S->maxsize -1)
        return 1;
    else
        return 0;
}
//判断堆栈S是否为空，返回1或0；
int IsEmpty (Stack S ){
    if(S->top == -1)
        return 1;
    else
        return 0;
}
//将元素item压入堆栈S；
void Push(Stack S, ElementType item ){
    ++S->top;
    S->data[S->top] = item;
}
//删除并返回S的栈顶元素。
ElementType Pop(Stack S ){
    return S->data[S->top--];
}
/*
对输入中的每个D操作，输出相应出队的数字，或者错误信息ERROR:Empty。
如果入队操作无法执行，也需要输出ERROR:Full。每个输出占1行。
输入首先给出两个正整数N1和N2，表示堆栈S1和S2的最大容量。
随后给出一系列的队列操作：A item表示将item入列（这里假设item为整型数字）
D表示出队操作；T表示输入结束。
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
                //s1不满 压栈 s2 不为空 输出满
                if(!IsFull(s1))
                     Push(s1,data);
                else//s1栈满
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
