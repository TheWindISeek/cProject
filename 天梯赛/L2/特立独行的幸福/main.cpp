//��ô�ж�һ�������Ǳ���ת�������� Ҳ������һ����ȫƽ�����ĺ͵��ص�
//�ڶ������ж���Ҫ���ٴε���
//�������ж���ѭ���� Ҳ���ǲ����Ҹ��������� ���������ĸо�
//����ֳ����� ��һ�봦���ǲ��ǵ����� �ǵĻ���Ҫ��עһ�� ��Щ���ܵ���Ҫȥ����
//���һ������ѭ���г�����һ��������������������е��� ��ô�����������һ�׶ε�Ŀ�� ����б���С�� ���Ǹ�С�Ĳ�������׶ε�Ŀ��
//��� ��Ȼ���Ҹ��� ���ǲ����������е��Ǹ� ������
#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
int isPrime(int x)
{
    if(x <= 3)
        return 1;
    for(int i = 2; i <= sqrt(x); i++)
        if(x%i == 0)
            return 0;
    return 1;
}
//�����������û��ͨ��
int main ()
{
    int x, y, n, tmp;
    int flag= 1,f[10001]= {0},one[10001]; //�Ƿ���SAD �ж��Ƿ��л� �ж��Ƿ����������е� �Ǿ���1 ������0
    int cnt[10001]= {0},c; //��һ����ÿ�������Ĵ��� �ڶ�����ÿ�ε��������õ�
    scanf("%d%d",&x,&y);
    memset(one,1,sizeof(one));
    for(int i = x; i <= y; i++)
    {
        memset(f,0,sizeof(f));
        c = 0;
        n = i;
        while(1)//Ϊ�����ж���������
        {
            f[n] = 1;
            tmp = 0;
            while(n)//���������
            {
                tmp += (n%10)*(n%10);
                //printf("%d %d\n",n,tmp);
                n /= 10;
            }
            n = tmp;
            c++;//ÿ�ε��������Ӽ�
            if(f[tmp])//����Ѿ����ֹ��� ��ѭ����Ҫ�˳�
            {
                one[i] = 0;
                break;
            }
            if(tmp == 1)//��������
            {
                flag = 0;//�������SAD
                break;
            }
            if(tmp >= x && tmp <= y)
                    one[tmp] = 0;
        }
        cnt[i] = c;
    }
    if(flag)
        printf("SAD");
    else
    {
        for(int i = x; i <= y; i++)
        {
            //cout << i<<" "<<one[i] <<" "<< cnt[i]<<endl;
            if(one[i])
            {
                if(isPrime(i))
                    cnt[i]*=2;
                printf("%d %d\n",i,cnt[i]);
            }
        }
    }
    return 0;
}
