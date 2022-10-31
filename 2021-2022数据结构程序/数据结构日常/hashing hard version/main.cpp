#include <iostream>
#include <queue>
using namespace std;
const int N = 1002;
int a[N];
int indegree[N];
int g[N][N];
//用这个是因为优先队列的排序问题 我想要的是输入i但是排序按a[i]来所以就需要自己再写一个自定义的比较方式来完成这个任务 需要使用到操作符重载
struct cmp
{
    bool operator()(int x,int y)
    {
        return a[x] > a[y];
    }
};

void top_sort(int n)
{
    //由于需要小的先输出 大的后输出 而这还需要队列 所以采取优先队列 也就是堆去操作拓扑排序
    int i,x,flag = 1;//控制输出格式正确
    priority_queue<int, vector<int>, cmp > q;
    for(i = 0; i < n; ++i)
    {
        if(indegree[i] == 0 && a[i] >=0)//入度为0并且有这个元素
            q.push(i);
    }
    while(!q.empty())
    {
        //这一小块处理格式输出
        if(flag) flag = 0;
        else printf(" ");
        //出队 访问
        x  = q.top();
        q.pop();
        printf("%d",a[x]);
        //对于其所有的邻接点进行访问
        for(i = 0; i < n; i++)
        {
            if(g[x][i] !=-1)//如果两个之间有边存在
            {
                if(--indegree[i] == 0)//入度减小并判断是否为0
                    q.push(i);
            }
        }
    }
}
int main ()
{
    int n;
    int i,x,j;
    cin >> n;
    for(i = 0; i < n; ++i)
        cin >> a[i];
    for(i =0; i< n; ++i)
    {
        indegree[i] = 0;
        for(j =0; j<n; j++)
            g[i][j]=-1;
    }
    for(i = 0; i < n; ++i)
    {
        if((a[i]%n) == i || a[i] < 0)
            continue;
        else //计算有多少条边指向它
        {
            x = a[i]%n;
            while(x != i)
            {
                //不得不说 这块有点绕
                //要达到的目标是 这个结点是经过线性探测之后才放到当前位置的 这个当前位置也就是i x是它本来应该放的地方
                /*而当x不等于i的时候 也就是从这里开始往后探测 每次探测如果还是不等于 那么所有探测过不等于的元素都应该在它前面输出
                而它本身的入度就要增加1
                它本身就是i 是第i个 因为之后是用这个映射去进行操作的 之后为邻接矩阵添加上 这个边 从当前点到i的边 需要放的元素是i方便去调用邻接表*/
                indegree[i]++;
                g[x][i] = i;
                x = (x+1)%n;
            }
        }
    }
    top_sort(n);
    return 0;
}
