/*typedef struct Node *PtrToNode;
struct Node {
    ElementType Data; /存储结点数据/
    PtrToNode   Next; /指向下一个结点的指针/
};
typedef PtrToNode List; /定义单链表类型/*/
/*
给定一个带头结点的单链表和一个整数K，要求你将链表中的每K个结点做一次逆转。
例如给定单链表 1→2→3→4→5→6 和 K=3，你需要将链表改造成 3→2→1→6→5→4；
如果 K=4，则应该得到 4→3→2→1→5→6。
*/
/*
题目分析
我想到的是利用整除操作 去确定需要逆转多少次
然后遇到了链表数据丢失的问题 在于我连上下一个链表我最开始采取的是最新的那一个结点
但是仔细分析了之后 这是尾插法 我记录的应该是第一个插入的结点 这个结点才是最后一个结点
我记录这个结点是为了像以前的传统的逆转链表一样 可以去统一操作 方便简单
然后就是每一次做完之后更新头结点的数据 这个不是丢失访问链表的那个头结点 而是假设有一个新的链表的头结点
其他就没什么意思了
*/
//L是给定的带头结点的单链表，K是每段的长度。函数K_Reverse应将L中的结点按要求分段逆转。
void K_Reverse( List L, int K ){
    int length = 0;//记录链表长度
     List head = L -> Next;//保存头结点的信息
    while(head){
        ++length;
        head = head -> Next;
    }
    //printf("%d",length);
    //单链表的逆转采取的读取按链表形式的读取 按尾插法进行解决
    int n = length / K;//需要逆转几次
    //p指针用于遍历给定的链表 temp指针用于尾插法的实现 H 指针用于实现多次插入
   // rear指针用于保存每段链表最后的那个结点的数据 方便作为下一次遍历的头结点
    List p = L -> Next,temp = NULL,H = L,rear = NULL;
    H -> Next = NULL;
    //第一个循环控制需要做的次数
    while(n--){
        //这个循环主要为了每次需要的逆转的个数
        for(int c = 0; c < K;++c){
            if(c == 0)//由于采取的是尾插法 所以rear需要保存的是第一个结点的数据
                rear = p;
            //正常尾插操作
            temp = p;
            p = p -> Next;
            temp -> Next = H -> Next;
            H -> Next = temp;
        }
        //为下一次遍历准备头结点
        H = rear;
        H -> Next = NULL;
    }
    H -> Next = p;//将不需要链接的结点放在后面 如果正好连接完毕 则p为空 操作统一
    return L;
}
