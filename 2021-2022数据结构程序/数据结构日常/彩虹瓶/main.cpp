#include <iostream>
#include <stack>
using namespace std;


int main()
{
//这题又再次提醒了我一次 思考问题的顺序对问题的求解也是有很大的影响的
int n,m,k;
    scanf("%d %d %d",&n,&m,&k);
    while(k--){
        //对于每一次具体情况
        stack<int> s;
        int flag = 0;
        int goal = 1;
        int data;
        for(int i = 0; i < n ;++i){
            scanf("%d", &data);
            if(data == goal){
                //如果这个数据刚好就是我要的
                ++goal;
                //栈非空的情况
                while(!s.empty()){//栈非空的情况下一直去做
                    if(s.top() == goal){
                        s.pop();//出栈
                        goal++;
                    }
                    else//如果栈中元素不对
                       break;
                }
            }else{
             s.push(data);
             if(s.size() > m){
                 flag = 1;
             }
            }
        }
        if(flag || goal < n){
            printf("NO\n");
        }else{
            printf("YES\n");
        }
    }


  /*  int N,M,K;
    scanf("%d",&N);
    int result[N];
    scanf("%d",&M);
    scanf("%d",&K);
    int data[K][N];
    //判断数组
    int adjust[N];
    //可以考虑直接边读边写 这样节约一点代码
    for(int i = 0; i< K ; ++i)
        for(int j = 0; j < N ; ++j)
            scanf("%d",&data[i][j]);
    //结果栈的初始化
    for(int i = 1; i <=N ; ++i)
        result[i-1]=i;
    stack<int> temp[K];//放临时数据的栈
//总共次数
    int index = 0;
    for (int k = 0; k < K ; ++k)
    {
        index = 0;
        //每一次具体
        for(int i = 0; i < N; ++i)
        {
            //利用的临时栈为 temp[k] 数据库为 data[k] 结果库为result
            if(temp[k].empty())
            {
                MOVE:
                if(index == N)
                {
                    adjust[k] = 0;
                    break;
                }
                else
                {
                    if(data[k][index] != result[i])
                    {
                        if((int)temp[k].size() == M){
                            adjust[k] = 0;
                            break;
                        }
                        temp[k].push(data[k][index]);
                        ++index;
                        goto MOVE;
                    }
                    else
                    {
                        ++index;

                    }
                }
            }
            else
            {
                if(temp[k].top() == result[i])
                {
                    temp[k].pop();
                    continue;
                }
                else
                {
                    goto MOVE;

                }
            }
        }
    }
    //打印结果
    for(int i = 0; i < K; ++i)
    {
        if(adjust[i])
            printf("YES");
        else
            printf("NO");
        if(i<N-1)
            printf("\n");
    }*/
    return 0;
}
