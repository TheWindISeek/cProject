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
//��Ҫע����Ǵ�ӡ���Ǹ�����ͷ����������ݵ�
//��Ȼʹ��β�巨 ��Ҫע����������Ĵ���
struct ListNode *
mergelists(struct ListNode *list1, struct ListNode *list2){
    struct ListNode *p = list1;
    struct ListNode *q = list2;
    struct ListNode *result = (struct ListNode *)malloc (sizeof(struct ListNode));
    struct ListNode *last = result;
    while(p && q){//�Ȱ�֮ǰ��������� �ٵ������ж��Ƿ����������ȥ
    if ( p -> data > q -> data){
    struct ListNode *temp = (struct ListNode *)malloc (sizeof(struct ListNode));
    temp -> data = q->data;
    last -> next = temp;
    last = temp;
    q = q -> next;
    }else{//С�ڵ���
     struct ListNode *temp = (struct ListNode *)malloc (sizeof(struct ListNode));
    temp -> data = p->data;
    last -> next = temp;
    last = temp;
    p = p -> next;
    }
    }
    //��ʣ�µ����������е���������
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
