#include <iostream>
#include <cstdlib>
using namespace std;

typedef int Position;
typedef struct LNode *List;
struct LNode {
    ElementType Data[MAXSIZE];
    Position Last; /* �������Ա������һ��Ԫ�ص�λ�� */
};

//����������һ���յ����Ա�
List MakeEmpty();

//�������Ա���X��λ�á����Ҳ����򷵻�ERROR��
Position Find( List L, ElementType X );

//��X������λ��P������true�����ռ����������ӡ��FULL��������false���������Pָ��Ƿ�λ�ã����ӡ��ILLEGAL POSITION��������false��
bool Insert( List L, ElementType X, Position P );

//��λ��P��Ԫ��ɾ��������true��������Pָ��Ƿ�λ�ã����ӡ��POSITION P EMPTY��������P�ǲ���ֵ��������false��
bool Delete( List L, Position P );


#define MAXSIZE 5
#define ERROR -1
typedef enum {false, true} bool;
typedef int ElementType;
typedef int Position;
typedef struct LNode *List;
struct LNode {
    ElementType Data[MAXSIZE];
    Position Last; /* �������Ա������һ��Ԫ�ص�λ�� */
};

List MakeEmpty();
Position Find( List L, ElementType X );
bool Insert( List L, ElementType X, Position P );
bool Delete( List L, Position P );

int main()
{
    List L;
    ElementType X;
    Position P;
    int N;

    L = MakeEmpty();
    scanf("%d", &N);
    while ( N-- ) {
        scanf("%d", &X);
        if ( Insert(L, X, 0)==false )
            printf(" Insertion Error: %d is not in.\n", X);
    }
    scanf("%d", &N);
    while ( N-- ) {
        scanf("%d", &X);
        P = Find(L, X);
        if ( P == ERROR )
            printf("Finding Error: %d is not in.\n", X);
        else
            printf("%d is at position %d.\n", X, P);
    }
    scanf("%d", &N);
    while ( N-- ) {
        scanf("%d", &P);
        if ( Delete(L, P)==false )
            printf(" Deletion Error.\n");
        if ( Insert(L, 0, P)==false )
            printf(" Insertion Error: 0 is not in.\n");
    }
    return 0;
}

/* ��Ĵ��뽫��Ƕ������ */
