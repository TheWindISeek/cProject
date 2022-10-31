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
LINK* add_link(LINK *head)//����һ���½ڵ��������������
{
    LINK *p=NULL,*pr=head;
    int data;
    p=(LINK *)calloc(1,sizeof(LINK));
    if(p==NULL)//���벻���ռ�
    {
        printf("û�пռ���");
        exit(0);
    }
    if(head==NULL)//����Ϊ�յ����
    {
        head=p;
    }
    else//��ͷ�ڵ������½ڵ�
    {
        while(pr->next!=NULL)//�ҵ��Ǹ���
        {
            pr=pr->next;
        }
        pr->next=p;
    }
    printf("����������");//Ϊ�����ݽ��и�ֵ
    scanf("%d",&data);
    p->data=data;
    p->next=NULL;
    return head;//��ͷָ�뷵��
}
void  free_all(LINK *head)//�������Ķ�̬����Ŀռ�
{
    LINK *p=head,*pr=NULL;
    while(p!=NULL)//�����ݵĽڵ�
    {
        pr=p;//�ȱ���ڵ�λ��
        p=p->next;//���Ľڵ�
        free(pr);//�ͷŵ�ǰ�ڵ��Ӧ�ĵĿռ�
    }
}
void print_all(LINK*head)//��ӡ�������������
{
    LINK *p = head;
    int j = 1;//�����ǵڼ�������
    while (p!=NULL)//���ǿսڵ�ʹ�ӡ
    {
        printf("\t%5d\t%10d\n",j,p->data);
        p = p->next;//�޸�ָ��
        j++;
    }
}
LINK *delete_link(LINK *head,int data)//ɾ�������е�ָ��Ԫ��
{
    /*ɾ����������5�����
    1�������ǿձ�û�н�����ɾ��
    2��������û���ҵ��������
    3��Ҫɾ���ĵ���ͷ���
    4��Ҫɾ���ĵ���β���
    5��Ҫɾ���ĵ����м�
    ���1��2ֱ�ӷ���ͷָ��
    ���3��Ҫɾ��ͷ��㣬����ͷ����ָ���޸�Ϊhead->next
    ���4��Ҫɾ��β��㣬Ӧ����ָ��ָ��β����ָ���ָ���->next�޸�ΪNULL
    ���5��Ҫɾ���м��㣬Ӧ�ý�ָ��ָ��ɾ������ָ���->next�޸�Ϊָ��ɾ���ڵ�ָ�����һ����Ȼ���ͷŵ��ڴ�*/
    LINK *p=head,*pr=NULL;//pr��Ϊ���ܹ��ҵ�P��ǰһ����㣬��Ȼ�޷�����ָ���ָ��Ĳ�����ʵ����p=pr->next;����Ҫ�ĵľ���p��ָ��\
    ��Ҫɾ�����Ǹ���㵽�Ǹ����ָ����ָ����ڴ棬���±�ע�͵Ĵ��������Լ���ʵ�ֵĹ��̣����Ĵ�������
    /*if(head==NULL)
    {
        printf("�����ǿձ�");//��һ��
        return head;
    }
    while(p->data!=data && p->next!=NULL)//��û���ҵ��Ǹ�����ʱ��p���������ƶ�
    {
        pr=p;
        p=p->next;
    }
    if(p->next==NULL)
    {
        printf("û���ҵ�");//�ڶ���
        return head;
    }
    else
    {
        if(p==head)//������
        {
            head=p->next;
            free(p);
            return head;
        }
        else if(p->next==NULL)//������
        {
            pr->next=NULL;
            free(p);
            return head;
        }
        else//���������м�����
        {
            pr->next=p->next;
            free(p);
            return head;
        }
    }*/
    if(head==NULL)
    {
        printf("����Ϊ��\n");
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
        printf("û���ҵ�");

    }
    return head;
}
LINK * insert_link(LINK *head)//�����ݲ�������
{
    LINK *p=NULL,*pr=head,*pl=head;
    /*Ҫ�ҵ�����㣬Ĭ���������У�ǰһ��������󣬺�����Ǹ������С��Ҳ����˵p->data>data&&p->next->data<data,
    ��ô�ͽ��в��룬����һ����㣬��Ҫ�޸���������ָ����pָ�������㣬���������ָ����ָ��pָ���Ǹ����*/
    /*�������
    1��ͷ���
    2��β���
    3�������м�
    4��������*/
    printf("��������Ҫ��ӵ�����");
    int data;
    scanf("%d",&data);
    p=(LINK*)calloc(1,sizeof(LINK));
    if(p==NULL)
    {
        printf("���벻���ռ�");
        exit(0);
    }
    p->data=data;
    p->next=NULL;
    if(head==NULL)//������ֱ�ӷ����
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
LINK *sort_link(LINK *head)//�������������Ĭ������
{
    LINK *p=head,*pn=head->next,*k=head,*temp=NULL;//��������������Ŀ�ľ��Ǻ���ǰ�����ף����һ��������Ϊ��ʵ������ı������õ�
    //int temp;//�����������
    /*�������У���������޸�ָ���ָ��������޸����ݣ�
            �Ǿ͵û����뷨����Ȼû�����б�������������˵ ���Ժ����������������ǰ�ĳһ�����򣬶����Ǵ��ⰴ�����������ÿ�ζ�����һ�����еĻ�
            ̫��ʱ�䣬�޸�ָ��ָ����á���ν���ָ�룬Ҳ�����ú�һ����ָ��ָ��ǰһ����ǰһ����ָ��ָ���һ��ָ���ʼָ��Ķ�����ָ��ǰһ����ָ���ָ���޸�Ϊ��һ��
            �������ʵ��Ϊ if(p->data>pn->data)

            {
                temp=p->data;
                p->data=pn->data;
                pn->data=temp;
            } */
    /*  while(k->next!=NULL)//ʵ��n-1��ѭ��
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
          k=k->next;//�൱��i++
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
            printf("���������Ƿ���Ҫ���룿(0/1)");
            scanf("%d",&flag);
            head  =  add_link(head);
            print_all(head);
        }
        while(flag);
        printf("����������ɾ�������ݣ�");
        scanf("%d",&num);
        head  = delete_link(head,num);
        print_all(head);
        head=insert_link(head);
        print_all(head);
        printf("����Ϊ�ź��������\n");
        head= sort_link(head);
        print_all(head);
        free_all(head);
        return 0;
    }
