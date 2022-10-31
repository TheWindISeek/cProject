#include <iostream>
#include <stack>
using namespace std;
//在写代码之前稍微分析一下问题
//找出yes 对应的情况与no对应的情况 这个比写代码更重要
//按我现在的思路就是从给定的顺序开始遍历
//遇到一个数据 把它前面数据输入到栈里面
//然后再到他这个数据之后去看看前面的数据能否满足条件 如果满足就可以继续这样做直到不满足或者栈空
//但是总感觉这样会遇到问题
//这种情况下对应的yes 就是能够顺利遍历完我的结果数组 不然就可以判定为失败
//换句话说 就是只有在我遍历完这个数组的情况下才能是yes 其他情况直接没
int main()
{
    int m,n,k;
    scanf("%d %d %d",&m,&n,&k);
    while(k--)
    {
        stack<int> s;
        int num = 1;
        int goal[n];
        for(int i =0; i < n ; ++i)
            scanf("%d",&goal[i]);
        int index  = 0;
        while(num <= n)
        {
            //如果这个可以直接出来 就直接出来
            if(num == goal[index])
            {
                num++;
                index++;
                while(!s.empty())
                {
                    if(s.top() == goal[index])
                    {
                        s.pop();
                        index++;
                    }
                    else
                        break;
                }
            }
            else
            {
              //  printf("9");
                //压栈
                if((int)s.size() < m-1)
                {
                   // printf("%d",(int)s.size());
                   s.push(num);
                   num++;
                }else{
                    break;}
            }
        }
        if(index < n-1)
        {
            printf("NO\n");
        }
        else{
            printf("YES\n");
        }
    }
    return 0;
}
