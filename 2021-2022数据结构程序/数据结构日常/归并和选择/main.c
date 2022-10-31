#include <stdio.h>
#include <stdlib.h>
/*
�鲢���� �� ����������Ҫ�Լ�д Ȼ��ÿ�ε�����һ���ȥ�ж�һ���ǲ���ƥ���
*/
//��������ǲ����ܹ�ƥ��
int match (int a[],int b[],int n)
{
    int i;
    for(i = 0; i < n; ++i)
        if(a[i] != b[i])
            return 0;
    return 1;
}
int run = 0;
int insert_run = 0;
int heap_run = 0;
//��ȡ�鲢���� ��һ������Ϊ ��Ҫ��������� �ڶ���Ϊ��Ҫ�жϵ� ������������Ĵ�С
void merge_array(int a[],int p[],int begin,int mid,int end)
{
    int left, temp,n;
    int i;

    left = mid -1;//��ߵ��յ�
    temp  = begin;//��ʱ��������
    n = end - begin + 1;//Ԫ�ظ���

    while( begin <= left && mid <= end)
    {
        if(a[begin] <= a[mid])
            p[temp++] = a[begin++];
        else
            p[temp++] = a[mid++];
    }
    //��ʣ�µ�Ԫ�ظ��ƹ���
    while( begin <= left)
        p[temp++] = a[begin++];
    while(mid  <= end)
        p[temp++] = a[mid++];
    for(i = 0; i < n; ++i,end--)
        a[end] = p[end];
}

void msort(int a[],int p[],int t[],int begin,int end,int n)
{
    if(begin < end)
    {
        int mid = (end - begin)/2+begin;
        msort(a,p,t,begin,mid,n);
        if(run)
            return;
        if(match(a,t,n))
            run = 1;
        msort(a,p,t,mid+1,end,n);
        merge_array(a,p,begin,mid+1,end);
    }
}
//�������0�� n-length*2�ź���
void merge_pass(int a[],int p[],int n,int length)
{
    int i,j;

    for(i = 0; i <= n-length*2; i += 2*length)
        merge_array(a,p,i,i+length,i+2*length-1);
    if(i + length < n)
        merge_array(a,p,i,i+length,n-1);
    else
        for(j = i; j < n; j ++)
            p[j] = a[j];

}
void merge(int a[],int t[],int n)
{
    int *p = (int*)malloc(sizeof(int)*n);
    /*
    *�����ȡ������ʽʵ����
    */
    int length = 1;
    while(length < n)
    {
        merge_pass(a,p,n,length);
        length *= 2;
        if(insert_run)
            return;
        if(match(a,t,n))
            insert_run = 1;
        merge_pass(p,a,n,length);
        length *= 2;
        if(insert_run)
            return;
        if(match(a,t,n))
            insert_run = 1;
    }
    // msort(a,p,t,0,n-1,n);
    free(p);
}
void swap(int *x,int *y)
{
    int t = *x;
    *x = *y;
    *y = t;
}
void percdown(int a[],int begin,int n)
{
    int parent,child;
    int x = a[begin];
    for(parent = begin; parent*2+1 < n ; parent = child)
    {
        child = parent*2+1;
        if(child < n && a[child+1] > a[child])
            child++;
        if(x >= a[child])
            break;
        else
            a[parent] = a[child];
    }
    a[parent] = x;
}
void heap(int a[],int t[],int n)
{
    int i;
    for(i = n/2 - 1; i >=0; --i)
    {
        percdown(a,i,n);
        if(heap_run)
            return;
        if(match(a,t,n))
            heap_run = 1;
        for(int k = 0; k < n;++k)
            printf("%d ",a[k]);
        printf("\n");
    }

    for(i = n-1; i > 0; --i)
    {
        swap(&a[0],&a[i]);
        percdown(a,0,i);
        for(int k = 0; k < n;++k)
                printf("%d ",a[k]);
        printf("\n");
    }
}
typedef int ElementType ;
void Swap( ElementType *a, ElementType *b )
{
     ElementType t = *a; *a = *b; *b = t;
}

void PercDown( ElementType A[], int p, int N )
{ /* �ı����4.24��PercDown( MaxHeap H, int p )    */
  /* ��N��Ԫ�ص���������A[p]Ϊ�����Ӷѵ���Ϊ���� */
    int Parent, Child;
    ElementType X;

    X = A[p]; /* ȡ��������ŵ�ֵ */
    for( Parent=p; (Parent*2+1)<N; Parent=Child ) {
        Child = Parent * 2 + 1;
        if( (Child!=N-1) && (A[Child]<A[Child+1]) )
            Child++;  /* Childָ�������ӽ��Ľϴ��� */
        if( X >= A[Child] ) break; /* �ҵ��˺���λ�� */
        else  /* ����X */
            A[Parent] = A[Child];
    }
    A[Parent] = X;
}

void HeapSort( ElementType A[], int N )
{ /* ������ */
     int i;

     for ( i=N/2-1; i>=0; i-- )/* �������� */
         PercDown( A, i, N );

     for ( i=N-1; i>0; i-- ) {
         /* ɾ�����Ѷ� */
         Swap( &A[0], &A[i] ); /* ������7.1 */
         PercDown( A, 0, i );
     }
}

int insert(int a[],int t[],int n)
{
    int i,j;
    int temp;
    for(i = 1; i < n; ++i)
    {
        temp = a[i];
        for(j = i; j > 0 && a[j-1] > temp; j--)
            a[j] = a[j-1];
        a[j] = temp;
        if(insert_run)
            return 1;
        if(match(a,t,n))
            insert_run = 1;
    }
    return 0;
}
int main ()
{
    int n,i;
    scanf("%d",&n);
    int a[n],b[n],t[n];//��һ�����ڹ鲢���� �ڶ������ڲ������� ��������ƥ��
    //��ȡ����
    for(i = 0; i < n; ++i)
    {
        scanf("%d",&a[i]);
        b[i] = a[i];
    }
    for(i = 0; i < n ; ++i)
        scanf("%d",&t[i]);
    int flag = insert(a,t,n);
    int c = 1;
    if(flag)
    {
        printf("Insertion Sort\n");
        for(int i = 0; i < n; ++i)
            if(c)
            {
                c = 0;
                printf("%d",a[0]);
            }
            else
                printf(" %d",a[i]);
    }
    else
    {
        //heap(b,t,n);
        HeapSort(b,n);
        printf("Heap Sort\n");
        for(int i = 0; i < n; ++i)
            if(c)
            {
                c = 0;
                printf("%d",b[0]);
            }
            else
                printf(" %d",b[i]);
    }
    return 0;
}
