#include <stdio.h>
#include <stdlib.h>
typedef struct Node *PtrToNode;
struct Node {
    ElementType Data; /* �洢������� */
    PtrToNode   Next; /* ָ����һ������ָ�� */
};
typedef PtrToNode List; /* ���嵥�������� */
struct ListNode *reverse( struct ListNode *head ){
    struct ListNode *p = NULL,*pre = NULL,*later = NULL;
    if(head == NULL)
        return NULL;
    if(head->next == NULL){//ֻ��ͷ������û�н��
        return head;
    }
    //ͷ�����
    p = head -> next;
    head -> next = NULL;
    later = p->next;
    p->next = head;
    pre= p;
    //�м����
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
