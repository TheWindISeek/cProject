/*
typedef struct GNode *PtrToGNode;
struct GNode{
    int Nv;  /顶点数 /
    int Ne;  /边数   /
    WeightType G[MaxVertexNum][MaxVertexNum]; /邻接矩阵 /
};
typedef PtrToGNode MGraph; /以邻接矩阵存储的图类型 /
*/
/*
函数DFS应从第V个顶点出发递归地深度优先遍历图Graph，
遍历时用裁判定义的函数Visit访问每个顶点。
当访问邻接点时，要求按序号递增的顺序。题目保证V是图中的合法顶点。
*/
/*
这个程序问题不大 当时唯一卡了一下的就是判断条件那里不是等于1 而是直接有用的不为0
*/
void DFS( MGraph Graph, Vertex V, void (*Visit)(Vertex) ){
    //递归的终止条件是什么 对于树来说 是两个叶子结点为空 就可以判定访问的终点了
    //首先对这个结点进行访问

    Visited[V] = true;
    (*Visit)(V);
    Vertex i;
    for(i = 0; i < Graph->Nv ;++i)
        if(Graph->G[V][i] == 1&&!Visited[i])
            DFS(Graph,i,Visit);
}
