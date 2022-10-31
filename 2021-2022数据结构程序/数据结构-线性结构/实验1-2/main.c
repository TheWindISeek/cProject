#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
    int data;
    struct ListNode *next;
};

struct ListNode *createlist(); /*����ʵ�֣�ϸ�ڲ���*/
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

/* ��Ĵ��뽫��Ƕ������ */
struct ListNode *createlist()
{
    struct ListNode * list = NULL;//����Ҫ�ﵽ��Ч��������Ϊ�����������룬����Ϊ������ֹ����
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
    if(head->next == NULL || head == NULL){//ֻ��ͷ���
        return head;
    }
    //ͷ�����
    p = head;
    pre = p -> next;
    later = p -> next -> next;
    p->next -> next = p;
    p -> next = NULL;
    _pre = pre;
    if(later == NULL){//�������
        return pre;
    }
    if (later -> next == NULL){//�������
        later -> next = pre;
        return later;
    }
    //�м����
    while (later -> next -> next != NULL){
        p = later;
        pre = p -> next;
        later = p -> next -> next;
        p->next -> next = p;
        p -> next =  _pre;
        _pre = pre;
    }
    //β�����
        p = later;
        pre = p -> next;
        later = p -> next -> next;
        p->next -> next = p;
        p -> next = _pre;
        _pre = pre;
    return pre;
}
