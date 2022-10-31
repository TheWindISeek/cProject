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
    //感觉很平常的一题
    /*首先建立结构体数组
    然后把数据读进来
    读取的时候就可以去计算花费了多少钱
    之后再排个序
    先按分数
    然后分数相同按字母序
    最后记得修改名次
    然后去遍历一遍就完了*/
    return 0;
}
