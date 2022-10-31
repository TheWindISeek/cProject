#include "../../READFILE/ReadFile.h"
#include <cstring>
#include <set>
#include <cmath>
#include <algorithm>
#define ANSPRE "../answer/set"
#define TESTPRE "../test/set"
#define OUT ".out"
#define IN ".in"
#define N 1
template <typename T>
void ReadFile(string pre,string suffix,vector<T> v[],int n)
{
    FILE* fp = NULL;
    string s = "0";
    T x;
    for(int i = 0; i < n; i++)
    {
        s[0] = i+'0';
        string destination = pre+suffix;
        cout<<destination<<endl;
        fp = fopen(destination.c_str(),"r");
        while(!feof(fp))//忽略空格
        {
            fscanf(fp,"%ld",&x);
            v[i].push_back(x);
        }
        fclose(fp);
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
        printf("%d\n",(*i));
}
long a[1001];
long comp(int n)
{
    long long ans = 1;
    if(a[n]>0)
        return a[n];
    for(int i = 1; i <= n/2;i++)
        ans +=comp(i);
    a[n] = ans;
    return ans;
}
int main()
{
    vector<long> out[N];
    vector<long> in[N];
    vector<long> result[N];

    ReadFile(TESTPRE,IN,in,N);
    ReadFile(ANSPRE,OUT,out,N);

    for(int i = 0; i < N; i++)
    {
        for(int x:in[i])
        {
            memset(a,0,sizeof(a));
            a[1] = 1;
            result[i].push_back(comp(x));
        }
    }
    PrintResult(result,out);
    return 0;
}
