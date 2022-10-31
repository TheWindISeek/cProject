#include "../../READFILE/ReadFile.h"
#include <cstring>
#include <set>
#include <cmath>
#define ANSPRE "../answer/count"
#define TESTPRE "../test/count"
#define OUT ".out"
#define IN ".in"
#define N 10
void ReadFile(string pre,string suffix,vector<int> v[],int n)
{
    FILE* fp = NULL;
    string s = "0";
    int x;
    for(int i = 0; i < 10; i++)
    {
        s[0] = i+'0';
        string destination = pre+s+suffix;
        cout<<destination<<endl;
        fp = fopen(destination.c_str(),"r");
        while(1)//忽略空格
        {
            fscanf(fp,"%d",&x);
            v[i].push_back(x);
            if(feof(fp))
                break;
        }
        fclose(fp);
    }
}
void PrintResult(vector<int>result[],vector<int>out[])
{

    bool istrue;
    set<int> s;
    int c = 0;
    for(int k = 0; k < N; k++)
    {
        cout <<k+1 <<endl;
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
    }
    printf("passed : %d\ntotal : %d\nWrong test case as followed:\n",c,N);
    for(auto i = s.begin(); i != s.end(); i++)
        printf("%d\n",(*i));
}

void  solveBF(int n,int *a)
{
    int x;
    for (int i = 1; i <= n; i++)//程序的主要判断 可以考虑重复计算 用栈或者队列都行
    {
        x = i;
        while (x)//101
        {
            a[x % 10]++;
            x /= 10;
        }
    }
    return;
}
int Pow(int x,int exp)
{
    if(exp == 0)
        return 1;
    if(exp == 1)
        return x;
    int xx = Pow(x,exp/2);
    if(exp%2)
        return xx*xx*x;
    return xx*xx;
}
//输入数n 它的位数 c 存放数据的结果 a数组
void cal(int n, int c, int* a)
{
    //终止条件应为 位数为 0 如果选择n为0 则对于100此类数据就会出错
    if (c == 0)
        return;
    //利用整除分离数
    int level = Pow(10, c - 1);
    int x = n / level;
    int left = n - (x * level);
    //所有的数都加上的一部分
    for (int i = 0; i < 10; i++)
        a[i] += x*(c - 1) * level/10;
    //重复了的数据
    for (int i = 0; i < x; i++)
        a[i] += level;
    a[x] += left + 1;

    //递归计算
    cal(left, c - 1, a);
}
void solveEffective(int n, int* a)
{
    //防止出现死循环以及其他问题
    if (n <= 0)
        return;
    int x = n, c = 0;//还可利用log10+1去直接计算
    while (x)
    {
        x /= 10;
        c++;
    }
    cal(n, c, a);
    //减去多余的0 利用等比数列的和的公式进行化简
    a[0] -= (Pow(10, c) - 1) / 9;
}

int main()
{
    vector<int> out[N];
    vector<int> in[N];
    vector<int> result[N];

    int a[N];

    ReadFile(ANSPRE,OUT,out,N);
    ReadFile(TESTPRE,IN,in,N);

    for(int i = 0; i < N; i++)
    {
        for(int x:in[i])
        {
            memset(a,0,sizeof(a));
            //算法开始
          // solveBF(x,a);
            solveEffective(x,a);
            //算法结束
            for(int k = 0; k < 10; k++)
                result[i].push_back(a[k]);
        }
    }
    PrintResult(result,out);
    return 0;
}
