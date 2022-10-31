#include <stdio.h>
#include <stdlib.h>
typedef struct link
{
    int data;
    struct link *next;
}LINK;
struct link *read (LINK * head);
void write (LINK * head);
void freedom (LINK * head);
LINK *DeleteNode (LINK * head,int nodedata);
LINK * IN (LINK * head,int nodeData);
int main ()
{
    LINK *head=NULL;
    int i=0;
    char c;
    printf("你是否想要添加节点 (y/n)");
    scanf(" %c",&c);
    while (c=='y'||c=='Y')
    {
        head  =  read(head);
        write(head);
        printf("你是否想要添加节点(y/n)");
        scanf(" %c",&c);
        i++;
        fflush(stdin);
    }
    char a;
    printf("你想去删除数据吗？\n");
    scanf(" %c",&a);
    while(a=='y'||a=='Y')
    {
        fflush(stdin);
        int datanode;
        printf("请输入数据\n");
        scanf(" %d",&datanode);
        head = DeleteNode(head,datanode);
        i--;
     write(head);
     printf("是否需要再次删除？(请输入y/n)\n");
     scanf(" %c",&a);
     }
     fflush(stdin);
printf("是否需要插入数据？");
char b;
scanf("%c",&b);
while(b=='y'||b=='Y')
{
    i++;
    fflush(stdin);
    printf("请输入数据？");
    int num;
    scanf(" %d",&num);
    head = IN(head,num);
    write(head);
    printf("是否需要再次输入？");
    scanf(" %c",&b);
}
    printf("%d new nodes have been apended !\n",i);
    freedom(head);
 return 0;
}
LINK *read (LINK* head)
{

    LINK *p=NULL,*pr = head;
    int data;
    p = (LINK *)malloc(sizeof(LINK));//p指向新建节点
    if(p==NULL)
    {
        printf("no enough memory to allocate !\n");
        exit(0);
    }
    if(head==NULL)
    {
        head = p;
    }
    else
    {
        while(pr->next!=NULL)
        {
            pr = pr ->next;
        }
        pr->next=p;
    }
    printf("input data");
    scanf("%d",&data);
    p->data = data;
    p->next = NULL;
    return head;
}
void write(LINK*head)
{
    LINK *p = head;
    int j = 1;
    while (p!=NULL)
    {
        printf("%5d%10d\n",j,p->data);
        p = p->next;
        j++;
    }
}
LINK *DeleteNode (LINK *head ,int nodedata)
{
    LINK *p=head,*pr=head;
    if(head==NULL)
    {
        printf("Linked Table is empty!\n");
        return (head);
    }
    while(nodedata != p ->data && p->next!=NULL)
    {
        pr = p;
        p = p-> next;
    }
    if(nodedata==p->data)
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
    else{
        printf("This node has not been found!");

    }
    return head;
}
void freedom (LINK * head)
{
    LINK *p=head,*pr=NULL;
    while(p!=NULL)
    {
        pr = p;
        p = p ->next;
        free(pr);
    }
}
LINK * IN (LINK * head,int nodeData)
{
    LINK *pr = head,*p=head,*temp = NULL;
    p = (LINK *)malloc(sizeof(LINK));
    if(p==NULL)
    {
        printf("没有足够地方存放！");
        exit(0);
    }
    p ->next = NULL;
    p->data = nodeData;
    if(head==NULL)
    {
        head = p;
    }
    else
    {
        while (pr->data < nodeData && pr->next != NULL)
        {
            temp = pr;
            pr = pr ->next;
        }
        if(pr->data >= nodeData)
        {
            if(pr == head)
            {
                p->next = head;
                head = p;
            }
            else
            {
                pr = temp;
                p->next = pr ->next;
                pr -> next = p;
            }
        }
        else
        {
            pr->next = p;
        }
    }
    return head;
}





















