#include<stdio.h>
#include<malloc.h>
#define LEN sizeof(struct Student)
struct Student                //�ṹ������
{
    long num;
    int score;
    struct Student* next;
};
int n;

struct Student* creat()           //������������
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

struct Student* sort(struct Student* list)               //ð�����򣬽�����������ʵ�֣����о����ζ��
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

struct Student* sort1(struct Student* h)                //��������
{
    struct Student *f, *t, *p=NULL, *q;
    f = h->next;
    h->next = NULL;
    while (f!=NULL)
    {
    //�ҵ�Ҫ����ĵ㣬��������ı���
    for (t = f, q = h; (q != NULL && (q->score > t->score)); p = q, q = q->next);
//�ڽ��в������ǰ����ʹf���ƣ��൱����f++;
    f = f->next;
    //�����ǰ������ͷ�ڵ�ؼ�ֵ��f����t����ָ�ڵ�ؼ�ֵС����Ҫ��f����t����ָ�ڵ���ڸ�ͷ�ڵ�ǰ����������ͷ�ڵ�ָ��ָ��f����t����ָ�ڵ㣬��Ϊ�������µ�ͷ�ڵ�
    if (q == h) h = t;
    //���򣬽�f����t����ָ�ڵ�����p��ָ�ڵ��
    else  p->next = t;
    //����if����else������Ҫ��f����t����ָ�ڵ�����q��ָ�ڵ�ǰ�����q=NULL��������f����t����ָ�ڵ��next��ָ��NULL,����ȻҲ����ȷ��
    t->next = q;
    }
    return h;  //�����������ź����������ͷ�ڵ�ָ��
}

struct Student* sort2(struct Student* h)                                                 //ѡ������
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

struct Student* sort3(struct Student* h) //�ȴ������һ����㿪ʼ���������ҳ��ؼ�ֵ�������ǳɼ�score�����ģ���Ϊ�ǴӴ�С���򣩽��������е�һ����㽻��������ָ��ʵ�֣�
{
                                                                   //Ȼ��������еڶ�����㿪ʼ���������ҳ��ؼ�ֵ���Ľ��������еڶ�����㽻��������˲���
    struct Student *p, *q, *pt=NULL, *pbf=NULL, *qbf=NULL;
    for (p = h ; p->next!=NULL; pbf = p, p = p->next)
    {
        //�����Ͳ�������
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


//����
struct Student* Link_Quick_Sort(struct Student ** head, struct Student ** end)          //  ע�����ﺯ������ֵ����д��void��ͬʱ��return���ȥ����
{
    struct Student * big_head=NULL, *big_end=NULL, *small_head=NULL, *small_end=NULL;   //ͬʱ����main������(1)(2)�����Ϊ��Link_Quick_Sort(&pt, NULL);for (p=pt, i = 1; i <= n; i++, p = p->next)
    struct Student * big_tail=NULL, *small_tail = NULL;
    int key = (*head)->score;                                                        //Ҳ�ǿ��Եġ�ԭ���ǵݹ����Ƚ����������ȳ�������һ�ε���ʱ������&pt����main������
    struct Student * traversal = (*head)->next;                                     //��(1)�䣩���ʵ���������������pt��ֵ���޸ģ���ָ���ź���������ͷ��㡣
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

int main()                                                   //��main����������
{
    printf("����������ѧ����ѧ������\n");
    printf("ѧ�ź��������Կո����\n");
    printf("����0 0����\n");
    struct Student* pt,*p;
    struct Student* creat();
    struct Student* sort();               //������õ���ð������Ҫ��������������������һ�º������þͿ�����
    pt=creat();
    int i;
    for ( p=pt,i = 1; i <=n; i++,p=p->next)
        printf("num=%ld score=%d\n", p->num, p->score);
    printf("�����\n");
    p=Link_Quick_Sort(&pt, NULL);//(1)
    struct Student *head=p;
    for ( i = 1; i <= n; i++, p = p->next)//(2)
        printf("��%d���� num=%ld score=%d\n",i, p->num, p->score);
        freedom(head);
        return 0;
}

