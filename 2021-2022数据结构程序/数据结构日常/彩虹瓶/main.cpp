#include <iostream>
#include <stack>
using namespace std;


int main()
{
//�������ٴ���������һ�� ˼�������˳�����������Ҳ���кܴ��Ӱ���
int n,m,k;
    scanf("%d %d %d",&n,&m,&k);
    while(k--){
        //����ÿһ�ξ������
        stack<int> s;
        int flag = 0;
        int goal = 1;
        int data;
        for(int i = 0; i < n ;++i){
            scanf("%d", &data);
            if(data == goal){
                //���������ݸպþ�����Ҫ��
                ++goal;
                //ջ�ǿյ����
                while(!s.empty()){//ջ�ǿյ������һֱȥ��
                    if(s.top() == goal){
                        s.pop();//��ջ
                        goal++;
                    }
                    else//���ջ��Ԫ�ز���
                       break;
                }
            }else{
             s.push(data);
             if(s.size() > m){
                 flag = 1;
             }
            }
        }
        if(flag || goal < n){
            printf("NO\n");
        }else{
            printf("YES\n");
        }
    }


  /*  int N,M,K;
    scanf("%d",&N);
    int result[N];
    scanf("%d",&M);
    scanf("%d",&K);
    int data[K][N];
    //�ж�����
    int adjust[N];
    //���Կ���ֱ�ӱ߶���д ������Լһ�����
    for(int i = 0; i< K ; ++i)
        for(int j = 0; j < N ; ++j)
            scanf("%d",&data[i][j]);
    //���ջ�ĳ�ʼ��
    for(int i = 1; i <=N ; ++i)
        result[i-1]=i;
    stack<int> temp[K];//����ʱ���ݵ�ջ
//�ܹ�����
    int index = 0;
    for (int k = 0; k < K ; ++k)
    {
        index = 0;
        //ÿһ�ξ���
        for(int i = 0; i < N; ++i)
        {
            //���õ���ʱջΪ temp[k] ���ݿ�Ϊ data[k] �����Ϊresult
            if(temp[k].empty())
            {
                MOVE:
                if(index == N)
                {
                    adjust[k] = 0;
                    break;
                }
                else
                {
                    if(data[k][index] != result[i])
                    {
                        if((int)temp[k].size() == M){
                            adjust[k] = 0;
                            break;
                        }
                        temp[k].push(data[k][index]);
                        ++index;
                        goto MOVE;
                    }
                    else
                    {
                        ++index;

                    }
                }
            }
            else
            {
                if(temp[k].top() == result[i])
                {
                    temp[k].pop();
                    continue;
                }
                else
                {
                    goto MOVE;

                }
            }
        }
    }
    //��ӡ���
    for(int i = 0; i < K; ++i)
    {
        if(adjust[i])
            printf("YES");
        else
            printf("NO");
        if(i<N-1)
            printf("\n");
    }*/
    return 0;
}
