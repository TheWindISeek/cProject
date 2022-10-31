#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e6+1;
bool isP[MAX];//�ȼ�����������������
int num[MAX]; //�洢������i����������

void aiSeive()
{
   memset(isP,1,sizeof(isP));
   isP[1] = 0;
   for(int i = 2;i <= MAX;i++)
   {
       if(isP[i])
       {
           for(int j = 2*i;j <= MAX;j += i)
           {
               isP[j] = 0;
           }
       }
   }
}

int prime[10000005];
int primesize = 0;
bool isprime[10000005];
void getlist(int n)
{
    memset(isprime,1,sizeof(isprime));
    isprime[1] = false;
    for(int i = 2;i <= n;i++)
    {
        if(isprime[i])//������������Ͱ���������
        {
            prime[++primesize] = i;
        }//�������ȥ�����е���������
        for(int j = 1;j <= primesize && i * prime[j] <= n;j++)
        {
            isprime[i * prime[j]] = false;
            if(i%prime[j] == 0)//���������Ǻ����������������֮����Ա���ǹ�prime[j]��ǣ�û�б�Ҫһֱ�����
                break;
        }
    }
}
int main()
{
    int t;
    cin >> t;
    aiSeive();
    num[0] = 0;
    for(int i = 1;i <= MAX;i++)
    {
        num[i] = num[i-1]+isP[i];
    }
    while(t--)
    {
        int l,r;
        cin >> l >> r;
        cout << num[r] - num[l-1] << endl;
    }
    return 0;
}

