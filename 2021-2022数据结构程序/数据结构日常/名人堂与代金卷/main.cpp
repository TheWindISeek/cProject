#include <iostream>
#include <algorithm>
#define N 10001
using namespace std;
typedef struct
{
    string email;
    int rank;
    int score;
} student;
bool cmp(student & a,student &b)
{
    if(a.score == b.score)
        return a.email < b.email;
    else
        return a.score > b.score;
}
int main ()
{
    int n,g,k;
    student s[N];
    string a;
    int sum = 0,score;
    scanf("%d %d %d",&n,&g,&k);
    for(int i = 0; i < n; i++)
    {

        cin >> a;
        scanf("%d",&score);
        if(score >= g && score <= 100)
            sum+=50;
        else if(score < g && score >= 60)
            sum+=20;
        s[i].email = a;
        s[i].score = score;
    }
    sort(s,s+n,cmp);
    for(int i = 0; i < n;++i)
    {
        if(i >= 1 &&s[i].score == s[i-1].score)
            s[i].rank = s[i-1].rank;
        else
            s[i].rank = i+1;
    }
    printf("%d",sum);
    for(int i = 0; i < n &&s[i].rank <= k;i++)
    {
        printf("\n%d %s %d",s[i].rank,s[i].email.c_str(),s[i].score);
    }
    //�о���ƽ����һ��
    /*���Ƚ����ṹ������
    Ȼ������ݶ�����
    ��ȡ��ʱ��Ϳ���ȥ���㻨���˶���Ǯ
    ֮�����Ÿ���
    �Ȱ�����
    Ȼ�������ͬ����ĸ��
    ���ǵ��޸�����
    Ȼ��ȥ����һ�������*/
    return 0;
}
