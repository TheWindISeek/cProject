#include <bits/stdc++.h>
using namespace std;
#define ANSPRE "../answer/sched"
#define TESTPRE "../test/sched"
#define OUT ".out"
#define IN ".in"
#define N 11
void ReadFile(string pre,string suffix,vector<int> v[],int n)
{
    FILE* fp = NULL;
    string s = "0";
    int x;
    for(int i = 0; i < n; i++)//需要解决一下如果多了10个怎么办
    {
        string destination;
        stringstream ss;
        ss<<pre<<i<<suffix;
        ss >> destination;
        cout<<destination<<endl;
        fp = fopen(destination.c_str(),"r");
        if(fp != NULL)
        {
            while(!feof(fp))//忽略空格
            {
                fscanf(fp,"%d",&x);
                v[i].push_back(x);
            }
            fclose(fp);
        }
    }
}
template <typename T>
void PrintResult(vector<T>result[],vector<T>out[])
{
    bool istrue;
    set<int> s;
    int c = 0;
    for(int k = 0; k < N; ++k)//每组数据
    {
        cout << k <<endl;
        istrue = true;
        for(auto i = result[k].begin(),j = out[k].begin(); i != result[k].end()&&j != out[k].end(); i++,j++)
        {
            cout <<(*i)<<" "<<(*j)<<endl;
            if((*i) != (*j))
                istrue = false;
        }
        if(istrue)
            c++;
        else
            s.insert(k);
        cout << endl;
    }
    printf("passed : %d\ntotal : %d\nWrong test case as followed:\n",c,N);
    for(auto i = s.begin(); i != s.end(); i++)
        cout << (*i)<<endl;
}
int f[501][1001];
int Sched(vector<int> &a,vector<int> &b,int n)
{
    int x = a[1];
    memset(f,0x3f3f3f3f,sizeof(f));//先将f初始化为无穷大
    //f[i][j] 代表着 前i个任务 a耗时j 的情况下 b耗时最少的时间
    for(int i = 0; i < x;i++)
        f[1][i] = b[1];
     f[1][a[1]] = a[1] < b[1] ? 0 : b[1];//如果 第一个任务 a的耗时比b少 那么就放在a上面跑 不然就放在b上面跑
    for(int k = 2; k <= n; k++)//从第二个任务开始 一直到跑完第n个任务
    {
        x+=a[k];//每次往后多走一点
        for(int i = 0; i <= x; i++)
            if(i < a[k])//运行时间小于 a运行这个需要的时间 所以只能是让b去运行 a还在运行
                f[k][i] = f[k-1][i]+b[k];
            else//可以选择a 就在这两个中选择最快的那一个
                f[k][i] = min(f[k-1][i]+b[k],f[k-1][i-a[k]]);
    }
    int mint = 0x3f3f3f3f;//先初始化无穷大
    //i代表的是 a的时间 f[n][i]代表的是b完成n个任务b所需的最小时间 而最后的完成时间 是取决于 二者中最大的那个 最后的那个求的是最小的一种
    for(int i = 1; i <= x; i++)//总共有x种 x 就是a所有的可能性
        mint = min(mint,max(i,f[n][i]));
    return mint;
}
int main()
{
    vector<int> out[N];
    vector<int> in[N];
    vector<int> result[N];
    for(int i = 0; i < N; i++)
        in[i].reserve(256);
    ReadFile(TESTPRE,IN,in,N);
    ReadFile(ANSPRE,OUT,out,N);

    for(int i = 0; i < N; i++)
    {
        vector<int> a, b;
        a.push_back(0);
        b.push_back(0);
        int n = in[i][0];
        for(int k = 1; k <= n; k++)
            a.push_back(in[i][k]);
        for(int k = n+1; k <= 2*n; k++)
            b.push_back(in[i][k]);
        result[i].push_back(Sched(a,b,n));
    }
    PrintResult<int>(result,out);
    return 0;
}
