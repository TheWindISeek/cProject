#include <iostream>
#include <stack>
using namespace std;
//这题又再次提醒了我一次 思考问题的顺序对问题的求解也是有很大的影响的

int main()
{
    int n,m,k;
    scanf("%d %d %d",&n,&m,&k);
    while(k--)
    {
        //对于每一次具体情况
        stack<int> s;
        int flag = 0;
        int goal = 1;
        int data;
        for(int i = 0; i < n ; ++i)
        {
            scanf("%d", &data);//题意的要求就是在每次搬完后 就去看看架子上的是不是我要的瓶子 如果在不是的情况下去输出 就错了
            if(data == goal)
            {
                //如果这个数据刚好就是我要的
                ++goal;
                //栈非空的情况
                while(!s.empty()) //栈非空的情况下一直去做
                {
                    if(s.top() == goal)
                    {
                        s.pop();//出栈
                        goal++;
                    }
                    else//如果栈中元素不对
                        break;
                }
            }
            else
            {
                s.push(data);
                if(s.size() > m)
                {
                    flag = 1;
                }
            }
        }
        if(flag || goal < n)
        {
            printf("NO\n");
        }
        else
        {
            printf("YES\n");
        }
    }
    return 0;
}
