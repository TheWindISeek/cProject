#include <iostream>
#include <stack>
using namespace std;
//��д����֮ǰ��΢����һ������
//�ҳ�yes ��Ӧ�������no��Ӧ����� �����д�������Ҫ
//�������ڵ�˼·���ǴӸ�����˳��ʼ����
//����һ������ ����ǰ���������뵽ջ����
//Ȼ���ٵ����������֮��ȥ����ǰ��������ܷ��������� �������Ϳ��Լ���������ֱ�����������ջ��
//�����ܸо���������������
//��������¶�Ӧ��yes �����ܹ�˳���������ҵĽ������ ��Ȼ�Ϳ����ж�Ϊʧ��
//���仰˵ ����ֻ�����ұ�����������������²�����yes �������ֱ��û
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
            //����������ֱ�ӳ��� ��ֱ�ӳ���
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
                //ѹջ
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
