#include <stdio.h>
#include <stdlib.h>
struct stud_node {
    int              num;      /*ѧ��*/
    char             name[20]; /*����*/
    int              score;    /*�ɼ�*/
    struct stud_node *next;    /*ָ���¸�����ָ��*/
};
//�ô�����ѭ���� ��ĳ�����ݵ������
//�пձ���������
//����һ������
struct stud_node *
createlist(){
struct stud_node * head = (struct stud_node*)malloc(sizeof (struct stud_node));
struct stud_node* last;
head -> next = NULL;
last = head;

    int num;
    scanf("%d",&num);
    //������δ����������ѭ��
    while(num){
    struct stud_node * new_stu = (struct stud_node*)malloc(sizeof (struct stud_node));
    scanf("%s",new_stu->name);
    scanf("%d",&(new_stu->score));
    new_stu -> next = NULL;
    new_stu -> num = num;
    scanf("%d",&num);
    last ->next = new_stu;
    last = last -> next;
    }
return head ;
}
//ɾ��ָ�����������
struct stud_node *
deletelist( struct stud_node *head, int min_score ){
    struct stud_node * p = head;
    struct stud_node* n;
    //�������һ����ͷ���� ��ô�ͺܼ���
    //дһ��˼· �����϶����м��� �м����ɾ����Ҫǰ���ָ��
    while(p->next){
    if(p->next ->score < min_score){
    n = p -> next;
    p -> next = p -> next ->next;
    free(n);
    }else
    p = p -> next;
   }
return head -> next;
}
int main()
{
    printf("Hello world!\n");
    return 0;
}
