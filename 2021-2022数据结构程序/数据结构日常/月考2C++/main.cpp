#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
#define N 50000
typedef struct stu
{
    char num[17];//���
    int score;//�ܷ�
    int rank;//��������
    int total_rank;//��������
    int which;//����
} Student;
Student a[N];
bool total_rank_cmp(Student x,Student y)
{
    if(x.score == y.score)
    {
        return strcmp(x.num,y.num) < 0;//���տ��ŵĵ���˳��
    }
    return x.score > y.score;//������ͬ�Ͱ���������
}
int main ()
{
    int n,k,sum = 0;
    int i,j;
    scanf("%d",&n);
    for(i = 0; i < n; i++)
    {
        scanf("%d",&k);
        for(j = 0; j < k; j++)
        {
            scanf("%s",a[j+sum].num);
            scanf("%d",&a[j+sum].score);
            a[j+sum].which = i+1;
        }
        sort(a+sum,a+sum+k,total_rank_cmp);
        for(j = 0; j < k; j ++)
            a[j+sum].rank = j+1;
        for(j = 1; j < k; j++)
            if(a[j+sum].score == a[j-1+sum].score)
                a[j+sum].rank = a[j-1+sum].rank;
        sum+=k;
    }
    sort(a,a+sum,total_rank_cmp);
    for(j = 0; j < sum; j++)
        a[j].total_rank = j+1;
    for(j = 1; j < sum; j++)
        if(a[j].score == a[j-1].score)
            a[j].total_rank = a[j-1].total_rank;
    //���
    printf("%d",sum);
    for(i = 0; i < sum; i++)
    {
        printf("\n%s %d %d %d",a[i].num,a[i].total_rank,a[i].which,a[i].rank);
    }
    return 0;
}
