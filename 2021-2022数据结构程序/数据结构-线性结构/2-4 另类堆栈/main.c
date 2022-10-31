#include <stdio.h>
#include <stdlib.h>
typedef int Position;
typedef struct SNode *PtrToSNode;
struct SNode {
    ElementType *Data;  /* 存储元素的数组 */
    Position Top;       /* 栈顶指针       */
    int MaxSize;        /* 堆栈最大容量   */
};
typedef PtrToSNode Stack;
/*注意：如果堆栈已满，Push函数必须输出“Stack Full”并且返回false
*/
//弹出元素
bool Push( Stack S, ElementType X ){
    //特殊情况处理
if(S ->MaxSize == S->Top){
    printf("Stack Full\n");
    return false;
}
   * (S->Data+S->Top) = X;
S->Top++;
return true;
}
/*如果队列是空的，则Pop函数必须输出“Stack Empty”，并且返回ERROR。*/
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
