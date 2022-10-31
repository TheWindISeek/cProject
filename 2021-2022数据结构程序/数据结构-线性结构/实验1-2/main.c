#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
    int data;
    struct ListNode *next;
};

struct ListNode *createlist(); /*裁判实现，细节不表*/
struct ListNode *reverse( struct ListNode *head );
struct ListNode* add_note(struct ListNode* head,int data);
void printlist( struct ListNode *head )
{
    struct ListNode *p = head;
    while (p)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int main()
{
    struct ListNode  *head;

    head = createlist();
     head = reverse(head);
    printlist(head);

    return 0;
}

/* 你的代码将被嵌在这里 */
struct ListNode *createlist()
{
    struct ListNode * list = NULL;//我想要达到的效果是输入为正，继续输入，输入为负，中止输入
    int i;
    for(;;)
    {
        scanf("%d",&i);
        if(i >0)
            list = add_note(list,i);
        else
            break;
    }
    return list;
}
struct ListNode* add_note(struct ListNode* head,int data)
{
    struct ListNode * p,*phead = head;
    p = (struct ListNode *)malloc(16);

    p->data = data;
    p->next = NULL;
    if(head == NULL){
        head = p;
        return head;
    }
    while(phead->next != NULL)
    {
        phead = phead ->next;
    }
    phead ->next = p;
    return head;
}
struct ListNode *reverse( struct ListNode *head ){
    struct ListNode *p,*pre,*_pre,*later;
    if(head->next == NULL || head == NULL){//只有头结点
        return head;
    }
    //头部情况
    p = head;
    pre = p -> next;
    later = p -> next -> next;
    p->next -> next = p;
    p -> next = NULL;
    _pre = pre;
    if(later == NULL){//两个结点
        return pre;
    }
    if (later -> next == NULL){//三个结点
        later -> next = pre;
        return later;
    }
    //中间情况
    while (later -> next -> next != NULL){
        p = later;
        pre = p -> next;
        later = p -> next -> next;
        p->next -> next = p;
        p -> next =  _pre;
        _pre = pre;
    }
    //尾部情况
        p = later;
        pre = p -> next;
        later = p -> next -> next;
        p->next -> next = p;
        p -> next = _pre;
        _pre = pre;
    return pre;
}
