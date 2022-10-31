/*typedef int Position;
typedef struct QNode *PtrToQNode;
struct QNode {
    ElementType *Data;      /�洢Ԫ�ص�����/
    Position Front, Rear;   /���е�ͷ��βָ��/
    int MaxSize;            /�����������/
};typedef PtrToQNode Deque;*/
/*
��Ŀ����
��ȡ����ȥʵ�ֶ��� ��Ҫע��ľ��ǿ����λ��û�а취ʹ�� ���ʱ���Ҫ���������ģ����ȥʵ��������
���������Һ���Ŀ���뷨��һ�� ����βָ��ָ�� ��һ�� �ҵ�ϰ���� ͷָ��ָ��ǰһ��
*/
//���βָ����Ҫָ������Ǹ�Ԫ�ص���һ��λ��
//��Ȼ�Ļ� ����ͷָ��ָ��ǰһ�� �����ĿҪ���Ч����βָ��ָ����һ��
//Push(X,D)����Ԫ��X���뵽˫�˶���D��ͷ��
bool Push( ElementType X, Deque D ){
    if((D->Rear + 1)%(D->MaxSize) == D->Front)
        return false;
    D -> Front = (D->Front-1+D->MaxSize)%(D->MaxSize);
    D->Data[D -> Front] = X;
    return true;
}
//Pop(D)��ɾ��˫�˶���D��ͷԪ�أ������أ�
ElementType Pop( Deque D ){
    if(D -> Rear == D -> Front)
        return ERROR;
    ElementType X = D ->Data[D->Front];
    D -> Front = (D->Front + 1)%(D->MaxSize);
    return X;
}
//Inject(X,D)����Ԫ��X���뵽˫�˶���D��β����
bool Inject( ElementType X, Deque D ){
    if((D->Rear + 1)%(D->MaxSize) == D->Front)
        return false;
    D -> Data[D->Rear] = X;
    D -> Rear = (D->Rear + 1)%(D->MaxSize);
    return true;
}
//Eject(D)��ɾ��˫�˶���D��β��Ԫ�أ������ء�
//�ƺ�������������
ElementType Eject( Deque D ){
    if(D -> Rear == D -> Front)
        return ERROR;

    D -> Rear = (D->Rear-1+D->MaxSize)%(D->MaxSize);ElementType X = D ->Data[D->Rear];
    return X;
}
