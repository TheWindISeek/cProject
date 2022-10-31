#include <iostream>
#define N 100001
#define null -1
using namespace std;
typedef struct
{
    int next;
    int data;
} Node;
Node address[N];
void print(int head)
{
    int p = head;
    while(p != null)
    {
        if(address[p].next != null)
            printf("%05d %d %05d\n",p,address[p].data,address[p].next);
        else
            printf("%05d %d -1",p,address[p].data);
        p = address[p].next;
        //system("pause");
    }
}
int reverse(int head)//逆转链表 头指针版本
{
    int p = head,q = null;
    head = null;
    while(p != null)
    {
        if(head == null)
        {
            head = p;
            q = p;
            p = address[p].next;
            address[q].next = null;
        }
        else
        {
            q = p;
            p = address[p].next;
            address[q].next = head;
            head = q;
        }
    }
    return head;
}
int Length(int head)
{
    int c = 0;
    while(head != null)
    {
        c++;
        head = address[head].next;
    }
    return c;
}
int main()
{
    int first_address,n,a,data,next = -1;
    scanf("%d %d",&first_address,&n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d %d %d",&a,&data,&next);
        address[a].data = data;
        address[a].next = next;
    }
    int p = null,q = null,rear = null;
    int length = Length(first_address);
    if(length == 1)
    {
        print(first_address);
        return 0;
    }
    int first_length;
    int c;

    first_length = length/2;
    p = first_address;
    q = first_address;
    c = 0;

    while(c != first_length)
    {
        c++;
        p = q;
        q = address[q].next;
    }
    address[p].next = null;

    p = first_address;
    q = reverse(q);
    first_address = null;
    while(p != null || q != null)
    {
        if(q != null)
        {
            if(first_address == null)
            {
                first_address = q;
                rear = q;
                q = address[q].next;
            }
            else
            {
                address[rear].next = q;
                rear = q;
                q = address[q].next;
            }
        }
        if(p != null)
        {
                address[rear].next = p;
                rear = p;
                p = address[p].next;
        }

    }
    print(first_address);
    return 0;
}
