#include <stdio.h>
#include <stdlib.h>
typedef struct Node *PtrToNode;
struct Node {
    ElementType Data; /* 存储结点数据 */
    PtrToNode   Next; /* 指向下一个结点的指针 */
};
typedef PtrToNode List; /* 定义单链表类型 */
struct ListNode *reverse( struct ListNode *head ){
    struct ListNode *p = NULL,*pre = NULL,*later = NULL;
    if(head == NULL)
        return NULL;
    if(head->next == NULL){//只有头结点或者没有结点
        return head;
    }
    //头部情况
    p = head -> next;
    head -> next = NULL;
    later = p->next;
    p->next = head;
    pre= p;
    //中间情况
    while (later != NULL){
        p = later;
        later = p->next;
        p->next = pre;
        pre= p;
    }
    later = pre;
    return p;
}
int main()
{
    printf("Hello world!\n");
    return 0;
}
