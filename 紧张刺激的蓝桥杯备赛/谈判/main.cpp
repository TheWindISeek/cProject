#include <bits/stdc++.h>
using namespace std;
int main()
{
    // 请在此输入您的代码

    //哈夫曼树
    int n;
    scanf("%d",&n);
    int data;
    priority_queue<int,vector<int>,greater<int> > q;
    for(int i = 0; i < n; i++)
    {
        scanf("%d",&data);
        q.push(data);
    }
    int cost = 0;
    while(!q.empty())
    {
        int x = q.top();
        q.pop();
        if(q.empty())
            break;
        int y = q.top();
        q.pop();
        //cout <<x<<' '<<y<<endl;
        cost +=(x+y);
        q.push(x+y);
    }
    printf("%d",cost);
    return 0;
}
