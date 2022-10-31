#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <vector>

using namespace std;

int priority(char  one) //返回优先级的函数
{
    if(one == '(' )
        return 0;
    else if (one == '+'||one == '-')
        return 1;
    else if(one == '*'|| one == '/')
        return 2;
    return 0;
}
int main()
{
    string input;
    vector<char> output;
    stack<char> w;

    cin >> input;
    int length = input.length();
 //   cout << length<<endl;
    for(int i = 0; i < length; ++i)
    {
      //  cout<<i<<"  "<<input[i]<<endl;
        //运算量放入输出数组
        if(input[i]>='0'&&input[i]<= '9')//对多位数的处理不支持
        {
            while(input[i]=='.'||(input[i]>='0'&&input[i]<= '9')){//对于小数 负数 多位数的处理
               output.push_back(input[i]);
               i++;
            }
            i--;
            output.push_back(' ');
            //continue;
        }
        //运算符
        else
        {
            if((input[i]=='+'||input[i]=='-') && ((i == 0)||(input[i-1] == '(')) && (input[i+1]>='0'&&input[i+1]<= '9') ){
               if(input[i]=='-')
                output.push_back(input[i]);
                continue;
            }
            if(input[i] == '+' ||input[i] == '-'||input[i] == '*'||input[i] == '/' )
            {
START:
                if(w.empty())//如果栈为空  入栈
                {
                    w.push(input[i]);
                    // continue;
                }
                else  //栈不为空
                {

                    //当前运算符优先级大 入栈
                    if(priority(input[i])>priority(w.top()))
                    {
                        w.push(input[i]);
                        // continue;
                    }
                    else//优先级低于 ，弹出栈顶的元素添加到输出中
                    {
                        //cout<<w.top()<<endl;
                        output.push_back(w.top());
                        output.push_back(' ');
                        w.pop();
                        goto START;
                    }
                }
            }
            else
            {
                if(input[i] == '(')
                {
                    w.push(input[i]);
                    // continue;
                }
                else
                {
                    if (input[i] == ')')
                    {
BEGIN:
                        if(w.top() == '(')//如果是左括号
                        {
                            w.pop();
                            // continue;
                        }
                        else//栈顶不是( 弹出
                        {
                            if(!w.empty())//栈不空
                            {
                                output.push_back(w.top());
                                output.push_back(' ');
                                w.pop();
                                goto BEGIN;
                            }
                        }
                    }
                }
            }
        }
    }
    while(!w.empty())
    {
        output.push_back(w.top());
        output.push_back(' ');

        w.pop();
    }
    int i = 0;
    for(; i< (int)output.size()-1; ++i)
    {
        printf("%c",output[i]);
    }
if(output[i]!= ' ')
    printf("%c",output[i]);
    return 0;
}
