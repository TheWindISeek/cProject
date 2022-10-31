#include<stdio.h>
#include<malloc.h>
#define LEN sizeof(struct Student)
struct Student                //结构体声明
{
    long num;
    int score;
    struct Student* next;
};
int n;

struct Student* creat()           //创建单向链表
{
    struct Student *head=NULL, *p_before, *p_later;
    p_before = p_later = (struct Student*) malloc(LEN);
    scanf("%ld%d", &p_before->num, &p_before->score);
    while (p_before->num!=0)
    {
        n++;
        if (n == 1)
            head = p_before;
        else
            p_later->next = p_before;
        p_later = p_before;
        p_before = (struct Student*) calloc(1,LEN);
        scanf("%ld%d", &p_before->num, &p_before->score);
    }
    p_later->next = NULL;
    free(p_before);
    return head;
}

struct Student* sort(struct Student* list)               //冒泡排序，交换排序。我已实现，但感觉差点味道
{
    struct Student *p, *q;
    int temp1,i;
    long temp2;
    for (p = list, i =1; i < n; i++,p=p->next)
        for (q = p->next; q!= NULL; q=q->next)
            if (p->score < q->score)
            {
                temp1 = p->score;
                p->score = q->score;
                q->score = temp1;
                temp2 = p->num;
                p->num = q->num;
                q->num = temp2;
            }
    return list;
}

struct Student* sort1(struct Student* h)                //插入排序
{
    struct Student *f, *t, *p=NULL, *q;
    f = h->next;
    h->next = NULL;
    while (f!=NULL)
    {
    //找到要插入的点，进行链表的遍历
    for (t = f, q = h; (q != NULL && (q->score > t->score)); p = q, q = q->next);
//在进行插入操作前，先使f后移，相当于让f++;
    f = f->next;
    //如果当前新链的头节点关键值比f（即t）所指节点关键值小，需要将f（即t）所指节点插在该头节点前，先让新链头节点指针指向f（即t）所指节点，作为新链的新的头节点
    if (q == h) h = t;
    //否则，将f（即t）所指节点连在p所指节点后
    else  p->next = t;
    //不管if还是else，都需要将f（即t）所指节点连在q所指节点前，如果q=NULL，就是让f（即t）所指节点的next域指向NULL,这显然也是正确的
    t->next = q;
    }
    return h;  //返回新链（排好序的链）的头节点指针
}

struct Student* sort2(struct Student* h)                                                 //选择排序
{
    struct Student *f=NULL,*t=NULL, *max, *maxbf=NULL, *p;

    while (h!=NULL)
    {
        for (p = h, max = h; p->next != NULL; p = p->next)
        {
            if (p->next->score > max->score)
            {
                maxbf = p;
                max = p->next;
            }
        }
        if (f==NULL)
        {
            f = max;
            t = max;
        }
        else
        {
            t->next = max;
            t = max;
        }
        if (max==h)
        {
            h = h->next;
        }
        else
        {
            maxbf->next = max->next;
        }
    }
    t->next = NULL;
    return f;
}

struct Student* sort3(struct Student* h) //先从链表第一个结点开始遍历链表找出关键值（这里是成绩score）最大的（因为是从大到小排序）结点和链表中第一个结点交换（利用指针实现）
{
                                                                   //然后从链表中第二个结点开始遍历链表，找出关键值最大的结点和链表中第二个结点交换……如此操作
    struct Student *p, *q, *pt=NULL, *pbf=NULL, *qbf=NULL;
    for (p = h ; p->next!=NULL; pbf = p, p = p->next)
    {
        //遍历和操作结束
        for (q = p; q->next != NULL; q=q->next)
        {

            if (p->score  <   q->next->score)
            {
                qbf = q;
                q = q->next;
                if (p==h && p->next==q)
                {
                    h = q;
                    p->next = q->next;
                    q->next = p;
                    p = q;
                }
                else
                {
                    if (p == h&&p->next != q)
                    {
                        h = q;
                        pt = q->next;
                        q->next = p->next, qbf->next = p;
                        p->next = pt;
                        p = q;
                        q = qbf;
                    }
                    else
                    {
                        if (p != h && p->next == q)
                        {
                            pt = q->next;
                            pbf->next = q;
                            q->next = p;
                            p->next = pt;
                            p = q;
                        }
                        else
                        {
                            if (p != h && p->next != q)
                            {
                                pt = q->next;
                                pbf->next = q;
                                q->next = p->next;
                                qbf->next = p;
                                p->next = pt;
                                p = q;
                                q = qbf;
                            }
                        }
                    }
                }
            }
        }
    }
    return h;
}


//快排
struct Student* Link_Quick_Sort(struct Student ** head, struct Student ** end)          //  注意这里函数返回值可以写成void，同时将return语句去掉，
{
    struct Student * big_head=NULL, *big_end=NULL, *small_head=NULL, *small_end=NULL;   //同时，将main函数中(1)(2)两句改为：Link_Quick_Sort(&pt, NULL);for (p=pt, i = 1; i <= n; i++, p = p->next)
    struct Student * big_tail=NULL, *small_tail = NULL;
    int key = (*head)->score;                                                        //也是可以的。原因是递归是先进后出，后进先出，二第一次调用时传的是&pt（见main函数中
    struct Student * traversal = (*head)->next;                                     //第(1)句），故当整个函数结束后，pt的值已修改，且指向排好序的链表的头结点。
    (*head)->next = NULL;
    struct Student *p = NULL;
    while (traversal != NULL)
    {
        if (traversal->score > key)
        {
            if (big_head == NULL)
            {
                big_head = traversal;
                big_tail = traversal;
            }
            else
            {
                big_tail->next = traversal;
                big_tail = traversal;
            }
            traversal = traversal->next;
            big_tail->next = NULL;
        }
        else
        {
            if (small_head == NULL)
            {
                small_head = traversal;
                small_tail = traversal;
            }
            else
            {
                small_tail->next = traversal;
                small_tail = traversal;
            }
            traversal = traversal->next;
            small_tail->next = NULL;
        }
    }
    big_end = big_tail;
    small_end = small_tail;
    if (big_head != NULL && big_head->next != NULL)
    {
        Link_Quick_Sort(&big_head, &big_end);
    }
    if (small_head != NULL && small_head->next != NULL)
    {
        Link_Quick_Sort(&small_head, &small_end);
    }
    if (big_end != NULL&&small_head != NULL)
    {
        big_end->next = (*head);
        (*head)->next = small_head;
        (*head) = big_head;
        if (end == NULL)
        {
            end = &p;
        }
        (*end) = small_end;
    }
    else if (big_end!=NULL)
    {
        big_end->next = (*head);
        if (end == NULL)
        {
            end = &p;
        }
        (*end) = (*head);
        (*head) = big_head;
    }
    else if (small_head!=NULL)
    {
        (*head)->next = small_head;
        if (end == NULL)
        {
            end = &p;
        }
        (*end) = small_end;
    }
    return (*head);
}
void freedom (struct Student *head)
{

    struct Student *p=head,*pr=NULL;
    while(p!=NULL)
    {
        pr=p;
        p=p->next;
        free(pr);
    }
}

int main()                                                   //用main函数来测试
{
    printf("请依次输入学生的学和姓名\n");
    printf("学号和姓名间以空格隔开\n");
    printf("输入0 0结束\n");
    struct Student* pt,*p;
    struct Student* creat();
    struct Student* sort();               //这里调用的是冒泡排序，要想调用其它排序，在这里改一下函数调用就可以了
    pt=creat();
    int i;
    for ( p=pt,i = 1; i <=n; i++,p=p->next)
        printf("num=%ld score=%d\n", p->num, p->score);
    printf("排序后：\n");
    p=Link_Quick_Sort(&pt, NULL);//(1)
    struct Student *head=p;
    for ( i = 1; i <= n; i++, p = p->next)//(2)
        printf("第%d名： num=%ld score=%d\n",i, p->num, p->score);
        freedom(head);
        return 0;
}

