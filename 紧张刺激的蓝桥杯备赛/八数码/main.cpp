#include <bits/stdc++.h>
using namespace std;
const int LEN = 362880;//9!
struct node {
    int state[9];//状态
    int dis;//距离
};
int dir[4][2]= {
    {-1,0},{0,-1},{1,0},{0,1}//各个方向
};

int visited[LEN] = {0};//访问数组
int start[9];//起点状态
int goal[9];//结束状态
long int factory[] = {1,1,2,6,24,120,720,5040,40320,362880};//0! - 9!

bool Cantor(int str[],int n)
{
    long result = 0;//由于计算的是阶乘 防止越界
    for(int i = 0; i < n; ++i) {
        int counted = 0;//当前这个数字处于哪个位置
        for(int j = i+1; j <n; j++) {
            if(str[i] > str[j])
                ++counted;
        }
        result += counted * factory[n-i-1];//计算位置
    }
    if(!visited[result]) {//没有访问过 访问
        visited[result] = 1;
        return 1;
    } else//已经访问过了
        return 0;
}
int bfs()
{
    node head;
    memcpy(head.state,start,sizeof(head.state));//内存拷贝 保存初始情况
    head.dis = 0;//结点距离为0
    queue<node> q;//队列
    Cantor(head.state,9);//标记已访问
    q.push(head);

    while(!q.empty()) {
        head = q.front();
        q.pop();
        int z;
        for(z = 0; z < 9; ++z)//找到0的位置 转移0的位置
            if(head.state[z] == 0)
                break;
        int x = z % 3;//将一维坐标转换成二维的
        int y = z / 3;//
        for(int i = 0; i < 4; i++) {
            int newx = x + dir[i][0];
            int newy = y + dir[i][1];
            int nz = newx + newy * 3;//将二维坐标转换成一维坐标
            if(newx >= 0&& newx < 3 && newy >= 0 && newy <3) {//新坐标合理 此处的判断有意思 确实这样才能避免出现重复访问的问题
                node newnode;
                memcpy(&newnode,&head,sizeof(struct node));//拷贝之前的信息
                swap(newnode.state[z],newnode.state[nz]);//移动0的位置
                newnode.dis++;
                if(memcmp(newnode.state,goal,sizeof(goal)) == 0)//匹配成功
                    return newnode.dis;
                if(Cantor(newnode.state,9))//判重
                    q.push(newnode);
            }
        }
    }
    return -1;
}
int main ()
{
    for(int i = 0; i < 9; i++) cin >> start[i];
    for(int i = 0; i < 9; i++) cin >> goal[i];
    int num = bfs();
    if(num != -1)
        cout << num << endl;
    else
        cout << "Impossible" << endl;
    return 0;
}
