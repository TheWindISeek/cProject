#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <conio.h>
typedef struct link
{
    int data;
    struct link *next;
} LINK;
LINK* add_link(LINK *head)//创建一个新节点连接在链表后面
{
    LINK *p=NULL,*pr=head;
    int data;
    p=(LINK *)calloc(1,sizeof(LINK));
    if(p==NULL)//申请不到空间
    {
        printf("没有空间了");
        exit(0);
    }
    if(head==NULL)//链表为空的情况
    {
        head=p;
    }
    else//在头节点后添加新节点
    {
        while(pr->next!=NULL)//找到那个点
        {
            pr=pr->next;
        }
        pr->next=p;
    }
    printf("请输入数据");//为其数据进行赋值
    scanf("%d",&data);
    p->data=data;
    p->next=NULL;
    return head;//将头指针返回
}
void  free_all(LINK *head)//清空链表的动态申请的空间
{
    LINK *p=head,*pr=NULL;
    while(p!=NULL)//有数据的节点
    {
        pr=p;//先保存节点位置
        p=p->next;//更改节点
        free(pr);//释放当前节点对应的的空间
    }
}
void print_all(LINK*head)//打印所有链表的数据
{
    LINK *p = head;
    int j = 1;//表明是第几个数据
    while (p!=NULL)//不是空节点就打印
    {
        printf("\t%5d\t%10d\n",j,p->data);
        p = p->next;//修改指向
        j++;
    }
}
LINK *delete_link(LINK *head,int data)//删除链表中的指定元素
{
    /*删除结点会遇到5种情况
    1、链表是空表，没有结点可以删除
    2、链表中没有找到这个数据
    3、要删除的点是头结点
    4、要删除的点是尾结点
    5、要删除的点在中间
    情况1或2直接返回头指针
    情况3需要删除头结点，并将头结点的指针修改为head->next
    情况4需要删除尾结点，应当将指向指向尾结点的指针的指针的->next修改为NULL
    情况5需要删除中间结点，应该将指向指向删除结点的指针的->next修改为指向删除节点指向的下一个，然后释放掉内存*/
    LINK *p=head,*pr=NULL;//pr是为了能够找到P的前一个结点，不然无法进行指针改指向的操作，实质上p=pr->next;我们要改的就是p的指向，\
    从要删除的那个结点到那个结点指针域指向的内存，以下被注释的代码是我自己是实现的过程，最后的代码更简洁
    /*if(head==NULL)
    {
        printf("链表是空表");//第一种
        return head;
    }
    while(p->data!=data && p->next!=NULL)//当没有找到那个结点的时候p不断向下移动
    {
        pr=p;
        p=p->next;
    }
    if(p->next==NULL)
    {
        printf("没有找到");//第二种
        return head;
    }
    else
    {
        if(p==head)//第三种
        {
            head=p->next;
            free(p);
            return head;
        }
        else if(p->next==NULL)//第四种
        {
            pr->next=NULL;
            free(p);
            return head;
        }
        else//第五种在中间的情况
        {
            pr->next=p->next;
            free(p);
            return head;
        }
    }*/
    if(head==NULL)
    {
        printf("链表为空\n");
        return (head);
    }
    while(data != p ->data && p->next!=NULL)
    {
        pr = p;
        p = p-> next;
    }
    if(data==p->data)
    {
        if(p==head)
        {
            head = p->next;
        }
        else
        {
            pr->next=p->next;
        }
        free (p);
    }
    else
    {
        printf("没有找到");

    }
    return head;
}
LINK * insert_link(LINK *head)//将数据插入链表
{
    LINK *p=NULL,*pr=head,*pl=head;
    /*要找到插入点，默认升序排列，前一个比这个大，后面的那个比这个小，也就是说p->data>data&&p->next->data<data,
    那么就进行插入，插入一个结点，需要修改两个结点的指向，让p指向这个结点，让这个结点的指针域指向p指向那个结点*/
    /*情况分析
    1、头结点
    2、尾结点
    3、插入中间
    4、空链表*/
    printf("请输入你要添加的数据");
    int data;
    scanf("%d",&data);
    p=(LINK*)calloc(1,sizeof(LINK));
    if(p==NULL)
    {
        printf("申请不到空间");
        exit(0);
    }
    p->data=data;
    p->next=NULL;
    if(head==NULL)//空链表直接放里边
    {
        head=p;
        return head;
    }
    while(pr->data<data && pr->next!=NULL)
    {
        pl=pr;
        pr=pr->next;
    }
    if(pr->data>data)
    {
        if(pr==head)
        {
            head=p;
            p->next=pr;
        }
        else
        {
            pl->next=p;
            p->next=pr;
        }
    }
    else
    {
        pr->next=p;
    }
    return head;

}
LINK *sort_link(LINK *head)//对链表进行排序，默认升序
{
    LINK *p=head,*pn=head->next,*k=head,*temp=NULL;//设置两个变量的目的就是好做前后配套，最后一个变量是为了实现链表的遍历设置的
    //int temp;//这块是数据域
    /*升序排列，如果我想修改指针的指向而不是修改数据，
            那就得换种想法。不然没法进行遍历操作。或者说 我以后链表的数据域可能是按某一块排序，而不是纯粹按数字排序，如果每次都进行一次排列的话
            太耗时间，修改指针指向最好。如何交换指针，也就是让后一个的指针指向前一个，前一个的指针指向后一个指针最开始指向的东西，指向前一个的指针的指向修改为后一个
            具体代码实现为 if(p->data>pn->data)

            {
                temp=p->data;
                p->data=pn->data;
                pn->data=temp;
            } */
    /*  while(k->next!=NULL)//实现n-1次循环
      {
          p=head;
          pn=head->next;
          while(pn!=NULL)
          {
               if(p->data>pn->data)
              {
               temp=pn->next;
               pn->next=p;
               p=pn;
               pn=temp;
               p=p->next;
              }
              p=pn;
              pn=pn->next;

          }
          k=k->next;//相当于i++
      }*/
        return head;
    }
    int main()
    {
        LINK *head=NULL;
        int i=0;
        int flag,num;
        do
        {
            printf("请输入你是否想要输入？(0/1)");
            scanf("%d",&flag);
            head  =  add_link(head);
            print_all(head);
        }
        while(flag);
        printf("请输入你想删除的数据？");
        scanf("%d",&num);
        head  = delete_link(head,num);
        print_all(head);
        head=insert_link(head);
        print_all(head);
        printf("以下为排好序的链表\n");
        head= sort_link(head);
        print_all(head);
        free_all(head);
        return 0;
    }
