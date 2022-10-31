/*typedef int Position;
typedef struct QNode *PtrToQNode;
struct QNode {
    ElementType *Data;  /�洢Ԫ�ص�����/
    Position Front;     /���е�ͷָ��/
    int Count;          /������Ԫ�ظ���/
    int MaxSize;        /�����������/
}; typedef PtrToQNode Queue; */
/*�����һ��ѭ�������ʾ���У�����ֻ�����ͷָ��Front������βָ��Rear��
��������Count��¼������Ԫ�ظ��������д�㷨ʵ�ֶ��е���Ӻͳ��Ӳ�����*/
/*
��Ŀ����
ûʲô��˼����Ŀ Ψһ�����������%ȥʵ��ѭ����Ч��
*/
bool AddQ( Queue Q, ElementType X ){
    if(Q ->Count == Q -> MaxSize)//�������� ������ҷ���false
    {
        printf("Queue Full\n");
        return false;
    }
    //��β������Ԫ��
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
    //��ͷ��ɾ��Ԫ��
    ElementType X = Q ->Data[Q->Front];
    Q -> Front = (Q -> Front +1)%(Q -> MaxSize);
    --Q->Count;
    return X;
}
