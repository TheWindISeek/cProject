#include <stdio.h>
#include <stdlib.h>
struct ListNode {
    int data;
    struct ListNode *next;
};
/*struct ListNode {
    int data;
    struct ListNode *next;
};*/
//需要注意的是打印的那个链表头结点是有数据的
//仍然使用尾插法 需要注意特殊情况的处理
struct ListNode *
mergelists(struct ListNode *list1, struct ListNode *list2){
    struct ListNode *p = list1;
    struct ListNode *q = list2;
    struct ListNode *result = (struct ListNode *)malloc (sizeof(struct ListNode));
    struct ListNode *last = result;
    while(p && q){//先把之前的输入完成 再到后面判断是否将两列输入进去
    if ( p -> data > q -> data){
    struct ListNode *temp = (struct ListNode *)malloc (sizeof(struct ListNode));
    temp -> data = q->data;
    last -> next = temp;
    last = temp;
    q = q -> next;
    }else{//小于等于
     struct ListNode *temp = (struct ListNode *)malloc (sizeof(struct ListNode));
    temp -> data = p->data;
    last -> next = temp;
    last = temp;
    p = p -> next;
    }
    }
    //将剩下的两个表其中的数据输入
    if(p== NULL){
    while(q){
     struct ListNode *temp = (struct ListNode *)malloc (sizeof(struct ListNode));
  temp -> data = q->data;
    last -> next = temp;
    last = temp;
    q = q -> next;
    }
    }
    if(q == NULL){
    while(p){
    struct ListNode *temp = (struct ListNode *)malloc (sizeof(struct ListNode));
    temp -> data = p->data;
    last -> next = temp;
    last = temp;
    p = p -> next;
    }
    }
    return result -> next;
}
int main()
{
    printf("Hello world!\n");
    return 0;
}
