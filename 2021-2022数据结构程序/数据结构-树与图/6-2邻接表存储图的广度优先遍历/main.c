/*
д������ȱ�����Ҫע���һ����� �ȷ��ʽ���������
��Ȼ�Ļ� �ͻ�����ظ���ӵ����
��������Ĳ�α�����΢�е㲻ͬ
�����޻�·��
��ͼ��һ��
�������������ָ��ͬһ�� ����֮�����ʵ��ѭ�����мǵÿ�����С
*/
void BFS ( LGraph Graph, Vertex S, void (*Visit)(Vertex) ){
    //��Ҫ���ö��а� ����һ�����֮�� ����������Щ�ڽӵ��Ӧ�Ľ��ѹ����� Ȼ�󲻶ϴӶ����е�����Щ��� ������ͬ��ʽ���з���
    //�����ʼ����Ҫһ������ ������ģ�������
    Vertex queue[MaxVertexNum];
    int front,rear;
    PtrToAdjVNode temp = NULL;
    Vertex top;

    front = rear = 0;
    //���ʼ�Ľ�����
    queue[(rear+MaxVertexNum)%MaxVertexNum] = S;
    rear++;

    (*Visit)(S);
    Visited[S] = true;
    //�����в�Ϊ��ʱ
    while(front != rear){
        //���������һ�����û�б����ʹ��Ļ��Ͱ�����ӵ�����
        top = queue[((front++) +MaxVertexNum)%MaxVertexNum];
        temp = Graph->G[top].FirstEdge;//ͷָ��
        while(temp){
          if(!Visited[temp->AdjV]){//���û�з��ʹ� �����
              queue[((rear++)+MaxVertexNum)%MaxVertexNum] = temp->AdjV;
              (*Visit)(temp->AdjV);
              Visited[temp->AdjV] = true;
          }
          temp = temp -> Next;
        }
    }
}
