#include <stdio.h>
#include <stdlib.h>
Polynomial Add( Polynomial a, Polynomial b ){
    //����ʽ�ļӷ� �ж� ָ���Ƿ���ͬ ��ͬ����� Ȼ����� �����ʽ ɶ��û�н�����
    //��㰴ָ���ݽ��ķ�ʽ�洢
    /*
    typedef struct Node *PtrToNode;
    struct Node {
    int Coefficient;
    int Exponent;
    PtrToNode Next;
    };
    typedef PtrToNode Polynomial;*/
    //�Ҳ�֪���ǲ����ϸ�ݼ� ���ǵĻ��ر��鷳
    //�ô�����ѭ����
    //�������������ʽ
   Polynomial add = (Polynomial)malloc (sizeof (struct Node));
    PtrToNode p , q , last = NULL;

    p = a -> Next;
    q = b -> Next;
     last = add;

    while(q && p){
        if(p -> Exponent > q -> Exponent){
          Polynomial temp = (Polynomial)malloc(sizeof(struct Node));
            temp -> Exponent = p -> Exponent;
            temp -> Coefficient = p -> Coefficient;
            temp -> Next = NULL;

            last -> Next = temp;
            last = last ->Next;
            p = p -> Next;
        }else if (p -> Exponent == q -> Exponent){
             Polynomial temp = (Polynomial)malloc(sizeof(struct Node));
            temp->Exponent = p -> Exponent;
            temp->Coefficient = p->Coefficient + q->Coefficient;
            temp->Next = NULL;
            if(temp -> Coefficient !=0){
                last -> Next = temp;
            last = last ->Next;
            }

            p = p -> Next;
            q = q -> Next;
        }else{
             Polynomial temp = (Polynomial)malloc(sizeof(struct Node));
            temp->Exponent = q -> Exponent;
            temp->Coefficient = q ->Coefficient;
            temp->Next = NULL;

           last -> Next = temp;
            last = last ->Next;
            q = q -> Next;
        }
    }
    if(q == NULL){
     while(p){
           Polynomial temp = (Polynomial)malloc(sizeof(struct Node));
            temp->Exponent = p -> Exponent;
            temp->Coefficient = p->Coefficient;
            temp->Next = NULL;

            last -> Next = temp;
            last = last ->Next;
          p = p -> Next;
     }
    }
    if(p == NULL){
     while(q){
          Polynomial temp = (Polynomial)malloc(sizeof(struct Node));
            temp->Exponent = q -> Exponent;
            temp->Coefficient = q ->Coefficient;
            temp->Next = NULL;

           last -> Next = temp;
            last = last ->Next;
            q = q -> Next;
     }
    }
    return add;
}
int main()
{
    printf("Hello world!\n");
    return 0;
}
