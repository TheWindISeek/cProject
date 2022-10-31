#include <stdio.h>
#include <stdlib.h>
struct stud_node {
    int              num;      /*学号*/
    char             name[20]; /*姓名*/
    int              score;    /*成绩*/
    struct stud_node *next;    /*指向下个结点的指针*/
};
//该代码死循环了 在某种数据的情况下
//有空表的情况出现
//创建一个链表
struct stud_node *
createlist(){
struct stud_node * head = (struct stud_node*)malloc(sizeof (struct stud_node));
struct stud_node* last;
head -> next = NULL;
last = head;

    int num;
    scanf("%d",&num);
    //下面这段代码出现了死循环
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
//删除指定区间的链表
struct stud_node *
deletelist( struct stud_node *head, int min_score ){
    struct stud_node * p = head;
    struct stud_node* n;
    //如果我有一个有头结点的 那么就很简单了
    //写一下思路 基本上都是中间结点 中间结点的删除需要前面的指针
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
