#include <stdio.h>
#include <stdlib.h>
#define leftchild(i) ( 2*(i)+1 )
void Swap(int *a,int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
typedef int ElementType ;
void PercDown( ElementType A[], int i, int N )
{
    int child;
    ElementType Tmp;

    Tmp = A[i];
    for ( Tmp = A[i]; leftchild(i) < N; i = child )
    {
        child = leftchild(i);
        if (child+1 != N && A[child+1] < A[child])
            child ++;
        if (A[child] < Tmp)
            A[i] = A[child];
        else
            break;
    }
    A[i] = Tmp;
}
void Heapsort( ElementType A[ ], int N )
{
    int i;
    for ( i = N / 2; i>= 0; i -- ) /* BuildHeap */
        PercDown( A, i, N );
    for(i = 0; i < N;i++)
            printf("%d ",A[i]);
    printf("\n");
    for ( i = N-1; i >0; i -- )
    {
        Swap( &A[ 0 ], &A[ i ] );
        PercDown( A, 0, i);
    }
}
int main()
{
    int i,a[5];
    for(i = 0; i < 5; i++)
        scanf("%d",&a[i]);
    Heapsort(a,5);
    for(i = 0; i < 5; i++)
        printf("%d ",a[i]);
    printf("Hello world!\n");
    return 0;
}
