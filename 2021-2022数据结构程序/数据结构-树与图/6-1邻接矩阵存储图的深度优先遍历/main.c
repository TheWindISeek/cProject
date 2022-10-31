/*
typedef struct GNode *PtrToGNode;
struct GNode{
    int Nv;  /������ /
    int Ne;  /����   /
    WeightType G[MaxVertexNum][MaxVertexNum]; /�ڽӾ��� /
};
typedef PtrToGNode MGraph; /���ڽӾ���洢��ͼ���� /
*/
/*
����DFSӦ�ӵ�V����������ݹ��������ȱ���ͼGraph��
����ʱ�ò��ж���ĺ���Visit����ÿ�����㡣
�������ڽӵ�ʱ��Ҫ����ŵ�����˳����Ŀ��֤V��ͼ�еĺϷ����㡣
*/
/*
����������ⲻ�� ��ʱΨһ����һ�µľ����ж��������ﲻ�ǵ���1 ����ֱ�����õĲ�Ϊ0
*/
void DFS( MGraph Graph, Vertex V, void (*Visit)(Vertex) ){
    //�ݹ����ֹ������ʲô ��������˵ ������Ҷ�ӽ��Ϊ�� �Ϳ����ж����ʵ��յ���
    //���ȶ���������з���

    Visited[V] = true;
    (*Visit)(V);
    Vertex i;
    for(i = 0; i < Graph->Nv ;++i)
        if(Graph->G[V][i] == 1&&!Visited[i])
            DFS(Graph,i,Visit);
}
