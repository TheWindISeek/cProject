#include <stdio.h>
#include <stdlib.h>
/*
�����Ĵ洢ӳ���Ǵ���-��ֵ�ڴ������ձ� Ҳ��Ϊ������
�����������������¼���
*/
//�������ȵ�������
/*��һ��ȥ��ų��� */
typedef struct
{
    char name[MAXNAME]; /*����*/
    int length; /*����*/
    char *stradr; /*��ʼ��ַ*/
} LNode;


//ĩβָ���������
/*
��ͷ��β�������з���
*/
typedef struct
{
    char name[MAXNAME]; /*����*/
    char *stradr,*enadr; /*��ʼ��ַ��ĩβ��ַ*/
} ENode;


//������λ��������
/*��һ�����Ĵ洢�ռ䲻����һ��ָ��Ĵ洢�ռ�ʱ
����ֱ�ӽ��ô��������������ָ����
�����Ƚ�Լ�˴洢�ռ䣬����߲����ٶ�
����Ҫ���һ������λtag��ָ��ָ�����ŵ���ָ�뻹�Ǵ�
*/
typedef struct
{
    char name[MAXNAME];
    int tag; /*����λ*/
    union /*��ʼ��ַ��ֵ*/
    {
        char *stradr;
        char value[4];
    } uval;
} TNode;

/*������ĸ ���� �����ַ����з���*/
int isCh(char c)//���ַ��Ƿ�Ϊ��ĸ
{

    if(c >= 'a' && c <='z'||c >= 'A' && c <='Z')
        return 1;
    else
        return 0;
}
int isNum(char c)//���ַ��Ƿ�Ϊ����
{

    if(c >= '0' && c <='9')
        return 1;
    else
        return 0;
}
void process(char r[],int n)
{
    int low = 0,high = n-1;
    while(low < high)
    {
        char k;
        while(low < high && isCh(r[low]))
            low++;
        while(low < high && !isNum(r[high]))
            high--;
        if(low < high)
        {
            k = r[low];
            r[low] = r[high];
            r[high] = k;
        }
    }
    ++low;
    high = n-1;
    while(low < high)
    {
        char k;
        while(low < high && isNum(r[low]))
            low++;
        while(low < high && !isNum(r[high]))
            high--;
        if(low < high)
        {
            k = r[low];
            r[low] = r[high];
            r[high] = k;
        }
    }
}
typedef struct{
int data[MAXSIZE];
int last;
}list;
void move(list* l,int m,int n)//m <= n
{
    int i,x;
    for(i = 1; i <= m ;++i){
        x = l ->data[0];
        for(k = 1;k <= l ->last;++k)
            l->data[k-1] = l->data[k];
        l ->data[l->last] = x;
    }
}
int main()
{
    printf("Hello world!\n");
    return 0;
}
