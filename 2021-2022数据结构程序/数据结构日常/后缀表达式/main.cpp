#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <vector>

using namespace std;

int priority(char  one) //�������ȼ��ĺ���
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
        //�����������������
        if(input[i]>='0'&&input[i]<= '9')//�Զ�λ���Ĵ���֧��
        {
            while(input[i]=='.'||(input[i]>='0'&&input[i]<= '9')){//����С�� ���� ��λ���Ĵ���
               output.push_back(input[i]);
               i++;
            }
            i--;
            output.push_back(' ');
            //continue;
        }
        //�����
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
                if(w.empty())//���ջΪ��  ��ջ
                {
                    w.push(input[i]);
                    // continue;
                }
                else  //ջ��Ϊ��
                {

                    //��ǰ��������ȼ��� ��ջ
                    if(priority(input[i])>priority(w.top()))
                    {
                        w.push(input[i]);
                        // continue;
                    }
                    else//���ȼ����� ������ջ����Ԫ����ӵ������
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
                        if(w.top() == '(')//�����������
                        {
                            w.pop();
                            // continue;
                        }
                        else//ջ������( ����
                        {
                            if(!w.empty())//ջ����
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
