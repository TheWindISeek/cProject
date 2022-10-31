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
题目分析
由于采取的是双重链表 虽然我想用双重循环链表
就会出现当只有一个元素的时候 插入元素需要去移动front结点和rear结点 就这个问题
其他都没什么了
*/
Deque CreateDeque(){
    Deque d = (Deque)malloc(sizeof(struct DequeRecord));
    d -> Front = d -> Rear = (PtrToNode)malloc(sizeof(struct Node));//都指向多余头结点dummy head
    d -> Front ->Next = NULL;
    d -> Front -> Last = NULL;
    return d;
}
//从头部添加结点 从头部删除结点
//Push(X,D): Insert item X on the front end of deque D.
int Push( ElementType X, Deque D ){
    PtrToNode p = (PtrToNode)malloc(sizeof(struct Node));
    if(!p)//没有分配空间吗
        return 0;
    //需要去考虑头节点后是否有结点的情况
    p -> Element = X;
    //队列为空 插入到头结点后面
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
    //删除结点
    //会出现特殊情况 我的尾指针在这个结点上 需要将尾指针指向头结点
    if(D -> Front -> Next == D -> Rear){
        D -> Rear = D ->Front;
        D -> Front -> Next = NULL;
        free(temp);
        return X;
    }
    //正常情况
    D -> Front -> Next = temp -> Next;
    temp -> Next -> Last = D -> Front;
    free(temp);
    return X;
}
//从尾部添加结点 从尾部删除结点
//Inject(X,D): Insert item X on the rear end of deque D.
int Inject( ElementType X, Deque D ){
    PtrToNode p = (PtrToNode)malloc(sizeof(struct Node));
    if(!p)//没有分配空间吗
        return 0;
    //需要去考虑头节点后是否有结点的情况
    p -> Element = X;
    //队列为空 插入到头结点后面
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
    //删除结点
    //会出现特殊情况 我的尾指针在这个结点上 需要将尾指针指向头结点
    if(D -> Front -> Next == D -> Rear){
        D -> Rear = D ->Front;
        D -> Front -> Next = NULL;
        free(temp);
        return X;
    }
    //正常情况
    D -> Rear = temp -> Last;
    D -> Rear -> Next = NULL;
    free(temp);
    return X;
}
