#include <iostream>
#include <algorithm>
#define N 10002
using namespace std;
typedef struct
{
    int num;
    int money;//�Է�Ϊ��λ
    int c;
} person;
bool cmp(person &a,person &b){
if(a.money == b.money){
    if(a.c == b.c)
        return a.num < b.num;
    else
        return a.c > b.c;
}
else
    return a.money > b.money;
}
int main ()
{
    int n,k,num,howmuch,sum;
    person all[N];
    scanf("%d",&n);
    for(int i = 0; i < N; i++)
    {
        all[i].num = i;
        all[i].money = 0;
        all[i].c = 0;
    }
    for(int i = 1; i <= n; i++)
    {
        scanf("%d",&k);
        sum = 0;
        while(k--)
        {
            scanf("%d%d",&num,&howmuch);
            all[num].c++;
            all[num].money += howmuch;
            sum+=howmuch;
        }
        all[i].money -= sum;
    }
    sort(all+1,all+n+1,cmp);
    for(int i = 1; i <= n; i++)
    {
        if(i-1)
            printf("\n");
        printf("%d %.2f",all[i].num,all[i].money/100.0);
    }
    /*
    �ṹ����Ҫ����
    ���
    ���
    �����������
    �����˽���ʼ��Ϊ0
    Ȼ���¼�����������
    ����ڼ�����ɺ�
    ����sort���������������еĽ��
    */
    return 0;
}
