/*
typedef struct Node *PtrToNode;
struct Node {
    ElementType Element;
    PtrToNode Next, Last;
};
typedef struct DequeRecord *Deque;
struct DequeRecord {
    PtrToNode Front, Rear;
};
*/
/*
Push and Inject are supposed to return 1
if the operations can be done successfully, or 0 if fail.
If the deque is empty, Pop and Eject must return ERROR which is defined by the judge program.
*/
/*
��Ŀ����
���ڲ�ȡ����˫������ ��Ȼ������˫��ѭ������
�ͻ���ֵ�ֻ��һ��Ԫ�ص�ʱ�� ����Ԫ����Ҫȥ�ƶ�front����rear��� ���������
������ûʲô��
*/
Deque CreateDeque(){
    Deque d = (Deque)malloc(sizeof(struct DequeRecord));
    d -> Front = d -> Rear = (PtrToNode)malloc(sizeof(struct Node));//��ָ�����ͷ���dummy head
    d -> Front ->Next = NULL;
    d -> Front -> Last = NULL;
    return d;
}
//��ͷ����ӽ�� ��ͷ��ɾ�����
//Push(X,D): Insert item X on the front end of deque D.
int Push( ElementType X, Deque D ){
    PtrToNode p = (PtrToNode)malloc(sizeof(struct Node));
    if(!p)//û�з���ռ���
        return 0;
    //��Ҫȥ����ͷ�ڵ���Ƿ��н������
    p -> Element = X;
    //����Ϊ�� ���뵽ͷ������
    if(D -> Rear == D -> Front){
    p-> Next = NULL;
    p -> Last = D -> Front;
    D -> Front -> Next = p;
    D ->Rear = p;
        return 1;
    }
    p -> Next = D -> Front -> Next;
    D -> Front ->Next -> Last = p;
    p -> Last = D -> Front;
    D -> Front -> Next = p;
    return 1;
}
//Pop(D): Remove the front item from deque D and return it.
ElementType Pop( Deque D ){
    if(D -> Front == D -> Rear)
        return ERROR;
    ElementType X = D -> Front -> Next ->Element;
    PtrToNode temp = D -> Front -> Next;
    //ɾ�����
    //������������ �ҵ�βָ������������ ��Ҫ��βָ��ָ��ͷ���
    if(D -> Front -> Next == D -> Rear){
        D -> Rear = D ->Front;
        D -> Front -> Next = NULL;
        free(temp);
        return X;
    }
    //�������
    D -> Front -> Next = temp -> Next;
    temp -> Next -> Last = D -> Front;
    free(temp);
    return X;
}
//��β����ӽ�� ��β��ɾ�����
//Inject(X,D): Insert item X on the rear end of deque D.
int Inject( ElementType X, Deque D ){
    PtrToNode p = (PtrToNode)malloc(sizeof(struct Node));
    if(!p)//û�з���ռ���
        return 0;
    //��Ҫȥ����ͷ�ڵ���Ƿ��н������
    p -> Element = X;
    //����Ϊ�� ���뵽ͷ������
    if(D -> Rear == D -> Front){
    p-> Next = NULL;
    p -> Last = D -> Front;
    D -> Front -> Next = p;
    D ->Rear = p;
        return 1;
    }
    D -> Rear -> Next = p;
    p -> Last = D -> Rear;
    p -> Next = NULL;
    D -> Rear = p;
    return 1;
}
//Eject(D): Remove the rear item from deque D and return it.
ElementType Eject( Deque D ){
    if(D -> Front == D -> Rear)
        return ERROR;
    ElementType X = D -> Rear -> Element;
    PtrToNode temp = D -> Rear;
    //ɾ�����
    //������������ �ҵ�βָ������������ ��Ҫ��βָ��ָ��ͷ���
    if(D -> Front -> Next == D -> Rear){
        D -> Rear = D ->Front;
        D -> Front -> Next = NULL;
        free(temp);
        return X;
    }
    //�������
    D -> Rear = temp -> Last;
    D -> Rear -> Next = NULL;
    free(temp);
    return X;
}
