#include <stdio.h>
#include <stdlib.h>
struct ListNode {
    int data;
    struct ListNode *next;
};
struct ListNode *reverse_2( struct ListNode *head ){
    struct ListNode *p = head,*pre = NULL,*later = NULL;
   while(p)
   {
       later = p->next;
       p->next = pre;
       pre= p;
       p = later;
   }
    return pre;

}
struct ListNode *reverse_1( struct ListNode *head ){
    struct ListNode *p = NULL,*pre = NULL,*later = NULL;
   while(p)
   {
       later = p->next;
       p->next = pre;
       pre= p;
       p = later;
   }
    return pre;
    }
    struct ListNode *reverse( struct ListNode *head ){
    struct ListNode *p = NULL,*pre = NULL,*later = NULL;
    if(head->next == NULL || head == NULL){//ֻ��ͷ������û�н��
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
