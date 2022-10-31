#include <stdio.h>
#include <stdlib.h>
#include <math.h>
    //对于当前点 是否存在一个可到达的点 或者 可以到达岸边
    /*
    如果是 进行遍历 继续判断
    如果已经不存在了 则无法逃脱
    */
    //对于当前点 如果找得到下一条鳄鱼 则跳到那条鳄鱼上
typedef struct {
    int x;
    int y;
}node;
node g[101*102];
int n,dis;
int visit[101*102];
int path[101*102];
int top;
int min_path[101*102];
int min_top;
int safe(int v){
    if(g[v].y+dis >= 50 || g[v].x-dis <= -50||g[v].x+dis >= 50 || g[v].y-dis <= -50)
        return 1;
    return 0;
}
int jump(int v,int w){
    double distant = sqrt(((double)g[v].x-g[w].x)*((double)g[v].x-g[w].x)+((double)g[v].y-g[w].y)*((double)g[v].y-g[w].y));
    if(v == 0){
        distant -= 7.5;
    }
    if(distant > dis)
        return 0;
    return 1;
}
//我需要进行改进 我要最短的
int isAlive(int v){
    int answer = 0,i,min = 90000;
    visit[v] = 1;
    top++;
    path[top] = v;
    if(safe(v))
        return 1;
    for(i = 1; i <= n;++i){
        if(!visit[i] && jump(v,i)){
            answer = isAlive(i);
            //应该达到什么样的效果呢 就是如果有路 应该返回的是什么 返回的是从当前点出发 到终点的长度 所以要走一步 返回一 走两步返回2
            if(answer){
                if(answer < min){
                    min = answer;
                }else{
                top -= answer;
                }
            }
            else
                top--;
        }
    }
    return answer+1;
}
int main (){
    int x,y;
    int i,j;
    for(i = 0; i < 101*102;++i){
        g[i].x = 0;
        g[i].y = 0;
    }
    for(i = 0; i < 101*102;++i)
        visit[i] = 0;
    top = -1;
    min_top = -1;
    scanf("%d %d",&n,&dis);
    //应该采取这个数值记录结点之间的距离的方式更好
    for(i = 1; i <= n;++i){
        scanf("%d %d",&x,&y);
        g[i].x = x;
        g[i].y = y;
    }
    int flag = isAlive(0);
    if(flag){
        printf("%d\n",top+1);
        for(i = 1; i <= top;++i){
            printf("%d %d\n",g[path[i]].x,g[path[i]].y);
        }
    }
    else
        printf("0\n");
    return 0;
}
