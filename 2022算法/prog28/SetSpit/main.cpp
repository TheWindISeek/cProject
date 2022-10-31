#include "../../READFILE/ReadFile.h"
#include <cstring>
#include <set>
#include <cmath>
#include <algorithm>
#include <string>
#include <sstream>
#include <fstream>
#define ANSPRE "../answer/stir"
#define TESTPRE "../test/stir"
#define OUT ".out"
#define IN ".in"
#define N 11
void ReadFile(string pre,string suffix,vector<long> v[],n)
{
    FILE* fp = NULL;
    string s = "0";
    long x;
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
                fscanf(fp,"%ld",&x);
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

void SplitNumber(long m,long n)
{
    long min;
    s[0][0] = 1;
    for(int i = 1; i <= m;i++)
    {
        s[i][0] = 0;
    }
    for(int i = 0;i < m;i++)
    {
        s[i][i+1] = 0;
    }
    for(int i = 1; i <= m;i++)
    {
        if(i < n)
            min = i;
        else
            min = n;
    }
    for(int j = 1; j<= min;j++)
        s[i][j] = j*s[i-1][j]+s[i-1][j-1];
}
long computeB(long m){
SplitNumber(m,m);
for(int i = 0; i < m;i++)
    b[i] = 0;
for(int i = 1; i <= m;i++)
    for(int j = 0; j <= i;j++)
        b[i-1] += s[i][j];
return b[m-1];
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

    }
    PrintResult<long>(result,out);
    return 0;
}
