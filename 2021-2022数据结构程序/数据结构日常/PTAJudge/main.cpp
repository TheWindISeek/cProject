#include <iostream>
#include <algorithm>
#include <cstring>
#define N 10002
#define K 6
#define M 100003
#define Null -2
using namespace std;
//整体程序应该是采取基数排序
typedef struct student
{
    int id;//
    int total_score;
    int rank;
    int perfect_solve;
    int *problem;
}*User;
User creatUser(int id,int problem_num)
{
    User u = (User)malloc(sizeof(struct student));
    int i;
    u->problem = (int*)malloc(sizeof(int)*(problem_num+1));
    for(i = 1; i <= problem_num; ++i)
        u->problem[i] = Null;
    u->id = id;
    u->total_score = 0;
    u->perfect_solve = 0;
    u->rank = 1;
    return u;
}
void calculate_totalScore(User users[],int n,int perfect[],int k)
{
    int i,j,sum,c;
    for(i = 1; i <= n; ++i)
    {
        sum = 0;
        c = 0;
        for(j = 1; j <= k; j++)
        {
            if(users[i]->problem[j] == perfect[j])
                c++;
            if(users[i]->problem[j] > 0)
                sum += users[i]->problem[j];
        }
        users[i]->total_score = sum;
        users[i]->perfect_solve = c;
    }
}
/*
void sort(User users[],int n,int k){
    return;
}*/
bool cmp(User &x,User &y)
{
    if(x->total_score > y->total_score)
        return true;
    else if(x->total_score < y->total_score)
        return false;
    else
    {
        //总分相同比较做对题的个数
        if(x->perfect_solve > y->perfect_solve)
            return true;
        else if(x->perfect_solve < y->perfect_solve)
            return false;
        else
            return x->id < y->id;
    }
}
void printUser(User users[],int n,int k)
{
    int i,j,flag = 1;

    for(i = 1; i <= n; ++i)
    {
        if(users[i]->total_score)
        {
            if(flag)
                flag = 0;
            else
                printf("\n");
            printf("%d %05d %d",users[i]->rank,users[i]->id,users[i]->total_score);
            //以下仅供测试使用
            printf(" %d",users[i]->perfect_solve);
            for(j = 1; j <= k; ++j)
            {
                if(users[i]->problem[j] == Null)
                    printf(" -");
                else
                    printf(" %d",users[i]->problem[j]);
            }
        }
    }
}
int main ()
{
    User users[N];
    int perfect[K],id,problem_id,score;
    int n,m,k;
    int i;
    cin >> n >> k >> m;
    //用户数组的初始化
    for(i = 1; i <= n; ++i)
    {
        users[i] = creatUser(i,k);
    }
    //浪费一点空间 不让它错位
    for(i = 1; i <= k; ++i)
    {
        cin >> perfect[i];
    }
    //读取学生的数据
    for(i = 0; i < m; ++i)
    {
        cin >> id >> problem_id >> score;
        if(users[id]->problem[problem_id] < score)
        {
            if(score < 0)
                users[id]->problem[problem_id] = 0;
            else
                users[id]->problem[problem_id] = score;
        }

    }
    calculate_totalScore(users,n,perfect,k);
    sort(users+1,users+n+1,cmp);
    for(i = 1; i <= n; ++i)
        users[i]->rank = i;
    for(i = 2; i <= n; ++i)
        if(users[i]->total_score == users[i-1]->total_score)
            users[i]->rank = users[i-1]->rank;
    printUser(users,n,k);
    return 0;
}
