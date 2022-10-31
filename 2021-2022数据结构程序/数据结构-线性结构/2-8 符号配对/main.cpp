#include <iostream>

using namespace std;

int main()#include <iostream>
//不考虑符号分段的情况 按行读取
//[ 0 { 1 /* 2 ( 3
#include <stack>
#include <queue>
#include <string>
#include <cstring>
using namespace std;

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
void right(stack<int> &s,int key){
                 printf("NO\n");
                    if(s.empty())
                    print(key,0);
				else
                    print(s.top(),1);
            }
int main()
{
    string a;
    stack<int> s;
    while(1)
    {
        getline(cin,a);
        if(a == ".")
            break;
        for(int i = 0; i < (int)a.size(); ++i)
        {
         if(a[i] == '[')
                s.push(0);
            else if (a[i] == ']')
                if(!s.empty()&&s.top() == 0)
                    s.pop();
                else{
right(s,0);
				return 0;
                }
            else if(a[i] == '{')
                s.push(1);
            else if (a[i] == '}')
                if(!s.empty()&&s.top()==1)
                    s.pop();
                else{
right(s,1);
				return 0;
                }
            else if(i+1<(int)a.size() && a[i]=='/' &&a[i+1]=='*'){
                s.push(2);
                i++;
            }

            else if(i+1<(int)a.size() && a[i]=='*' &&a[i+1]=='/')
                if(!s.empty()&&s.top() == 2){
                    s.pop();
                    i++;
                }
                else{
               right(s,2);
				return 0;
                }
            else if(a[i] == '(')
                s.push(3);
            else if(a[i] == ')')
                if(!s.empty()&&s.top() == 3)
                    s.pop();
                else{
                    right(s,3);
                    return 0;
                }
        }
    }
    int mark;
    if(s.empty())
        printf("YES\n");
    else
    {//此处仍应该做错误判断处理 为右边符号为空的情况
       while(!s.empty()){
			mark = s.top();
			s.pop();
		}
		cout <<"NO"<< endl;
        print(mark,1);
    }
    return 0;
}
{
    cout << "Hello world!" << endl;
    return 0;
}
