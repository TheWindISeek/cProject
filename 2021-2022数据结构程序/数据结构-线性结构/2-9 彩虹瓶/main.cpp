#include <iostream>
#include <stack>
using namespace std;
//�������ٴ���������һ�� ˼�������˳�����������Ҳ���кܴ��Ӱ���

int main()
{
    int n,m,k;
    scanf("%d %d %d",&n,&m,&k);
    while(k--)
    {
        //����ÿһ�ξ������
        stack<int> s;
        int flag = 0;
        int goal = 1;
        int data;
        for(int i = 0; i < n ; ++i)
        {
            scanf("%d", &data);//�����Ҫ�������ÿ�ΰ���� ��ȥ���������ϵ��ǲ�����Ҫ��ƿ�� ����ڲ��ǵ������ȥ��� �ʹ���
            if(data == goal)
            {
                //���������ݸպþ�����Ҫ��
                ++goal;
                //ջ�ǿյ����
                while(!s.empty()) //ջ�ǿյ������һֱȥ��
                {
                    if(s.top() == goal)
                    {
                        s.pop();//��ջ
                        goal++;
                    }
                    else//���ջ��Ԫ�ز���
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
