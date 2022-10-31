#include <stdio.h>
#include <stdlib.h>
#include <math.h>
    //���ڵ�ǰ�� �Ƿ����һ���ɵ���ĵ� ���� ���Ե��ﰶ��
    /*
    ����� ���б��� �����ж�
    ����Ѿ��������� ���޷�����
    */
    //���ڵ�ǰ�� ����ҵõ���һ������ ����������������
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
//����Ҫ���иĽ� ��Ҫ��̵�
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
            //Ӧ�ôﵽʲô����Ч���� ���������· Ӧ�÷��ص���ʲô ���ص��Ǵӵ�ǰ����� ���յ�ĳ��� ����Ҫ��һ�� ����һ ����������2
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
    //Ӧ�ò�ȡ�����ֵ��¼���֮��ľ���ķ�ʽ����
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
