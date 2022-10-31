#include <bits/stdc++.h>
using namespace std;
typedef struct node * ptr;
struct node
{
    int data;
    ptr pre,next;
};
void insertLeft(ptr &p,int data)
{
    ptr tmp = (ptr)malloc(sizeof(struct node));
    tmp->data = data;
    tmp->pre = tmp->next = NULL;

    p->pre->next = tmp;
    tmp->pre = p->pre;

    tmp->next = p;
    p->pre = tmp;

    p = tmp;
}
void insertRight(ptr &p,int data)
{
    ptr tmp = (ptr)malloc(sizeof(struct node));
    tmp->data = data;
    tmp->pre = tmp->next = NULL;

    p->next->pre = tmp;
    tmp->next = p->next;
    tmp->pre = p;
    p->next = tmp;
    p = tmp;
}
void print(ptr head)
{
    ptr p = head->next;
    int flag = 0;
    while(p != NULL)
    {
        if(flag)
            printf(" ");
        else
            flag = 1;
        printf("%d",p->data);
        p = p->next;
    }
}
int main()
{
    int n;
    ptr head = (ptr)malloc(sizeof(struct node));
    ptr tmp = (ptr)malloc(sizeof(struct node));
    tmp->data = 0;
    tmp->pre = head;
    tmp->next = NULL;
    head->next=tmp;
    head->pre = NULL;
    ptr p = NULL;
    p = head->next;
    char c;
    scanf("%d",&n);
    getchar();
    for(int i = 1; i <= n; i++)
    {
        scanf("%c",&c);
        switch(c)
        {
        case 'L':
            insertLeft(p,i);
            //cout << p->data <<endl;
            //cout << p->next->data<<endl;
            //print(p);
            //cout << endl;
            break;
        case 'R':
            insertRight(p,i);
            //cout << p->data <<endl;
            //cout << p->pre->data<<endl;
           // print(p);
            //cout << endl;
            break;
        }
    }
    print(head);
    return 0;
}
