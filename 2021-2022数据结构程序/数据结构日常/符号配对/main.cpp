#include <iostream>
#include <stack>
#include <queue>
#include <string>
#include <cstring>
using namespace std;
//printf("YES"); 2
//printf("NO\n?-]"); 4
//printf("NO\n[-?"); 5
//printf("NO\n?-*/"); 1
//printf("NO\n/*-?"); 不存在
//printf("NO\n?-)"); 不存在
//printf("NO\n(-?"); 0
//printf("NO\n?-}"); 不存在
//printf("NO\n{-?"); 3
//第一个是输出的指代 第二个是说明是左边还是右边
void print(int n,int flag)
{
    switch(n)
    {
    case 0:
        if(flag)
            printf("[-?");
        else
            printf("?-]");
        break;
    case 1:
        if(flag)
            printf("{-?");
        else
            printf("?-}");
        break;
    case 2:
        if(flag)
            printf("/*-?");
        else
            printf("?-*/");
        break;
    case 3:
        if(flag)
            printf("(-?");
        else
            printf("?-)");
        break;
    }
}
int main()
{
    //不考虑符号分段的情况 按行读取
    //[ 0 { 1 /* 2 ( 3
    string a;
    queue<int> q;
    stack<int> s;
    while(1)
    {
        getline(cin,a);
        if(a == ".")
            break;
        for(int i = 0; i < (int)a.size(); ++i)
        {
            if(a[i] == '{')
            {
                s.push(1);
            }
            else if (a[i] == '}')
            {
                if(!s.empty()&&s.top()==1)
                    s.pop();
                else
                    q.push(1);
            }
            else if(a[i] == '[')
            {
                s.push(0);
            }
            else if (a[i] == ']')
            {
                if(!s.empty()&&s.top() == 0)
                    s.pop();
                else
                    q.push(0);
            }
            else if(a[i] == '(')
            {
                s.push(3);
            }
            else if(a[i] == ')')
            {
                if(!s.empty()&&s.top() == 3)
                    s.pop();
                q.push(3);
            }
            else if(i+1<(int)a.size() && a[i]=='/' &&a[i+1]=='*')
            {
                s.push(2);
            }
            else if(i+1<(int)a.size() && a[i]=='*' &&a[i+1]=='/')
            {
                if(!s.empty()&&s.top() == 2)
                    s.pop();
                else
                    q.push(2);
            }
        }
    }
    if(s.empty()&&q.empty())
    {
        printf("YES\n");
    }
    else
    {
        printf("NO\n");
        if(!s.empty()&&q.empty())
        {
            print(s.top(),0);
        }
        else if (s.empty()&&!q.empty())
        {
            print(q.front(),1);
        }
        else if (!s.empty()&&q.empty())
        {
            if((int)s.size() >= (int)q.size())
            {
                print(s.top(),0);
            }
            else
                print(q.front(),1);
        }
    }
    //读取完所有的符号了
    //现在要做的就是队列出 用栈匹配 然后如果匹配不到 就准备去遍历完栈 如果在栈中找到了 则说明是右边不匹配 如果没找到 则说明是左边不匹配
    //除此之外 如果有一个输出完了 但是另一个没有输出完 则取出最近的那个输出
    /*  int flag = 1;
      int error = 0;
      int mark;
      int _mark;
      while(!s.empty()&&!q.empty())
      {
          if(s.top() == q.front())
          {
              s.pop();
              q.pop();
          }
          else
          {
              error = 1;
              mark = s.top();
              _mark = q.front();
              s.pop();
              while(!s.empty())
              {
                  if(s.top() == q.front())
                  {
                      flag = 0;
                      break;
                  }
                  s.pop();
              }
          }
      }
      if(!error)
      {
          printf("YES");
      }
      else
      {


      }*/
    return 0;
}
