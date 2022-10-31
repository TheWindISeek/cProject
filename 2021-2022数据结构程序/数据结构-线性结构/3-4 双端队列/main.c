/*typedef int Position;
typedef struct QNode *PtrToQNode;
struct QNode {
    ElementType *Data;      /存储元素的数组/
    Position Front, Rear;   /队列的头、尾指针/
    int MaxSize;            /队列最大容量/
};typedef PtrToQNode Deque;*/
/*
题目分析
采取数组去实现队列 需要注意的就是空余的位置没有办法使用 这个时候就要巧妙地利用模操作去实现这个结果
其他就是我和题目的想法不一样 他是尾指针指向 下一个 我的习惯是 头指针指向前一个
*/
//这个尾指针需要指向最后那个元素的下一个位置
//不然的话 就是头指针指向前一个 这个题目要求的效果是尾指针指向下一个
//Push(X,D)：将元素X插入到双端队列D的头；
bool Push( ElementType X, Deque D ){
    if((D->Rear + 1)%(D->MaxSize) == D->Front)
        return false;
    D -> Front = (D->Front-1+D->MaxSize)%(D->MaxSize);
    D->Data[D -> Front] = X;
    return true;
}
//Pop(D)：删除双端队列D的头元素，并返回；
ElementType Pop( Deque D ){
    if(D -> Rear == D -> Front)
        return ERROR;
    ElementType X = D ->Data[D->Front];
    D -> Front = (D->Front + 1)%(D->MaxSize);
    return X;
}
//Inject(X,D)：将元素X插入到双端队列D的尾部；
bool Inject( ElementType X, Deque D ){
    if((D->Rear + 1)%(D->MaxSize) == D->Front)
        return false;
    D -> Data[D->Rear] = X;
    D -> Rear = (D->Rear + 1)%(D->MaxSize);
    return true;
}
//Eject(D)：删除双端队列D的尾部元素，并返回。
//似乎是这里有问题
ElementType Eject( Deque D ){
    if(D -> Rear == D -> Front)
        return ERROR;

    D -> Rear = (D->Rear-1+D->MaxSize)%(D->MaxSize);ElementType X = D ->Data[D->Rear];
    return X;
}
