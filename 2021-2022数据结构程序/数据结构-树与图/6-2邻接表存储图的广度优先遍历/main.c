/*
写广度优先遍历需要注意的一点就是 先访问结点了再入队
不然的话 就会出现重复入队的情况
这个和树的层次遍历稍微有点不同
树是无回路的
但图不一定
可以有两个结点指向同一个 除此之外就是实现循环队列记得开够大小
*/
void BFS ( LGraph Graph, Vertex S, void (*Visit)(Vertex) ){
    //需要利用队列吧 访问一个结点之后 按照升序将那些邻接点对应的结点压入队列 然后不断从队列中弹出这些结点 按照相同方式进行访问
    //所以最开始我需要一个队列 用数组模拟就行了
    Vertex queue[MaxVertexNum];
    int front,rear;
    PtrToAdjVNode temp = NULL;
    Vertex top;

    front = rear = 0;
    //让最开始的结点入队
    queue[(rear+MaxVertexNum)%MaxVertexNum] = S;
    rear++;

    (*Visit)(S);
    Visited[S] = true;
    //当队列不为空时
    while(front != rear){
        //如果它的下一个结点没有被访问过的话就把它添加到里面
        top = queue[((front++) +MaxVertexNum)%MaxVertexNum];
        temp = Graph->G[top].FirstEdge;//头指针
        while(temp){
          if(!Visited[temp->AdjV]){//如果没有访问过 就入队
              queue[((rear++)+MaxVertexNum)%MaxVertexNum] = temp->AdjV;
              (*Visit)(temp->AdjV);
              Visited[temp->AdjV] = true;
          }
          temp = temp -> Next;
        }
    }
}
