#include <stdio.h>
#include <stdlib.h>
Polynomial Add( Polynomial a, Polynomial b ){
    //多项式的加法 判断 指数是否相同 相同就添加 然后针对 零多项式 啥都没有进行了
    //结点按指数递降的方式存储
    /*
    typedef struct Node *PtrToNode;
    struct Node {
    int Coefficient;
    int Exponent;
    PtrToNode Next;
    };
    typedef PtrToNode Polynomial;*/
    //我不知道是不是严格递减 不是的话特别麻烦
    //该代码死循环了
    //存在两个零多项式
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
