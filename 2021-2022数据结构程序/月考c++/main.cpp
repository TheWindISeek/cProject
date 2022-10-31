#include <bits/stdc++.h>
using namespace std;
typedef struct node * ptr;
struct node
{
    ptr next,pre;
    int data;
};
void insertLeft(ptr &p,int data)
{
    ptr tmp = (ptr)malloc(sizeof(struct node));
    tmp->data = data;
    tmp->pre = tmp->next = NULL;
    if(p->pre)
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
    if(p->next)
        p->next->pre = tmp;
    tmp->next = p->next;
    tmp->pre = p;
    p->next = tmp;
    p = tmp;
}
ptr deleteLeft(ptr &p)
{
if(p->pre)
{

}
}
int main ()
{
    ptr head = (ptr)malloc(sizeof(struct node)),tail;
    ptr max = (ptr)malloc(sizeof(struct node));
    tail = head;
    ptr tmp = NULL,p = NULL;
    int n;
    int data,size = 0;
    scanf("%d",&n);
    while(n--)
    {
        cin >> op;
        switch(op)
        {
        case 'I':
            scanf("%d",&data);
            break;
        case 'Q':
            if(p!=0)
                printf("%d\n",max[p-1]);
            else
                printf("-10000"\n);
            break;
        case 'L':
            if(p!=0)
                p--;
            break;
        case 'R':
            if(p < size)
                p++;
            break;
        case 'D':

            break;
        }
    }
    return 0;
}

