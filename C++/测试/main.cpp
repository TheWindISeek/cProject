#include <iostream>
#include <string>
#include <cstring>
#include <stack>
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
int main()
{
    //�����Ƿ��ŷֶε���� ���ж�ȡ
    //[ 0 { 1 /* 2 ( 3
    string a;
    stack<int> s;
    //���ڵ��뷨������hash��ȥ��¼ֵ �ȵ� ���� �����뷨���� ��Ϊ������ջ���� �Ҿ�����΢����һ�¸��ӶȱȽϺ�
    //��Ҫ���������� �ж����ĸ�ȱ�� �Ѿ�����ȱ�ٵ����ĸ�����
    //�����Ķ��ܼ� �����Ҳ�ȡ�����ұ�ƥ����� �����ͻ����һЩ���� ���� ����������û���ҵ� ��ô�������Ǹ� ��һ���������
    //�����������ҵ��˺�����ƥ��� ��ô���ƥ�����һ����������Ҫ�� ��֮ǰ���뷨������hash�� �����ڸо����� ֱ��ȥ�ҵ����ͺ���
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
                if(!s.empty() && s.top() == 0)
                    s.pop();
                else//ջΪ�� Ҳ�����ұ߶��� ��¼���һ��
                {
                    printf("NO\n");
                    if(s.empty())
                        print(0,1);
                    else
                        print(s.top(),0);
                    return 0;
                }
            else if(a[i] == '{')
                s.push(1);
            else if (a[i] == '}')
                if(!s.empty() && s.top() == 1)
                    s.pop();
                else//ջΪ�� Ҳ�����ұ߶��� ��¼���һ��
                {
                    printf("NO\n");
                    if(s.empty())
                        print(1,1);
                    else
                        print(s.top(),0);
                    return 0;
                }
            else if(i+1<(int)a.size() && a[i]=='/' &&a[i+1]=='*')
                s.push(2);
            else if(i+1<(int)a.size() && a[i]=='*' &&a[i+1]=='/')
                if(!s.empty() && s.top() == 2)
                    s.pop();
                else//ջΪ�� Ҳ�����ұ߶��� ��¼���һ��
                {
                    printf("NO\n");
                    if(s.empty())
                        print(2,1);
                    else
                        print(s.top(),0);
                    return 0;
                }
            else if(a[i] == '(')
                s.push(3);
            else if(a[i] == ')')
                if(!s.empty() && s.top() == 3)
                    s.pop();
                else//ջΪ�� Ҳ�����ұ߶��� ��¼���һ��
                {
                    printf("NO\n");
                    if(s.empty())
                        print(3,1);
                    else
                        print(s.top(),0);
                    return 0;
                }
        }
    }
    cout << "YES";
    return 0;
}
