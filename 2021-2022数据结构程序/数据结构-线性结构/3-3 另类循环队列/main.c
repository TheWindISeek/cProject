/*typedef int Position;
typedef struct QNode *PtrToQNode;
struct QNode {
    ElementType *Data;  /存储元素的数组/
    Position Front;     /队列的头指针/
    int Count;          /队列中元素个数/
    int MaxSize;        /队列最大容量/
}; typedef PtrToQNode Queue; */
/*如果用一个循环数组表示队列，并且只设队列头指针Front，不设尾指针Rear，
而是另设Count记录队列中元素个数。请编写算法实现队列的入队和出队操作。*/
/*
题目分析
没什么意思的题目 唯一就是如何利用%去实现循环的效果
*/
bool AddQ( Queue Q, ElementType X ){
    if(Q ->Count == Q -> MaxSize)//队列已满 输出并且返回false
    {
        printf("Queue Full\n");
        return false;
    }
    //从尾部插入元素
    Q -> Data[(Q->Front+Q->Count)%(Q->MaxSize)] = X;
   // Q -> Front = (Q -> Front +1)%(Q -> MaxSize);
    ++Q -> Count;
    return true;
}
ElementType DeleteQ( Queue Q ){
    if(Q -> Count == 0)
    {
        printf("Queue Empty\n");
        return ERROR;
    }
    //从头部删除元素
    ElementType X = Q ->Data[Q->Front];
    Q -> Front = (Q -> Front +1)%(Q -> MaxSize);
    --Q->Count;
    return X;
}
