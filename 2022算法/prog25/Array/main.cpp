#include "../../READFILE/ReadFile.h"
#include <cstring>
#include <set>
#include <cmath>
#include <algorithm>
#include <string>
#include <sstream>
#include <fstream>
#define ANSPRE "../answer/perm"
#define TESTPRE "../test/perm"
#define OUT ".out"
#define IN ".in"
#define N 10
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
void ReadFile(string pre,string suffix,vector<string> v[],int n)
{
    string s;
    ifstream ifs;
    for(int i = 0; i < n; i++)
    {
        string destination;
        stringstream ssout;
        ssout<<pre<<i<<suffix;
        ssout >> destination;
        cout<<destination<<endl;
        ifs.open(destination);
        while(!ifs.eof())
        {
            ifs >> s;
            v[i].push_back(s);
        }
        ifs.close();
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

int ans;
bool IsFound(int j,int k,string s)
{
    if(j > k)
        for(int i = k; i < j; i++)
            if(s[i] == s[j])
                return true;
    return false;
}
void perm(string &s,int begin,int end,vector<string>&result)
{
    if(begin == end)
    {
        ++ans;
        result.push_back(s);
        return;
    }
    for(int i = begin; i <= end; i++)
    {
        if(!IsFound(i,begin,s))
        {
            swap(s[i],s[begin]);
            perm(s,begin+1,end,result);
            swap(s[i],s[begin]);
        }
    }
}
void Perm(int n,string &s,vector<string> &result)
{
    perm(s,0,n-1,result);
}
int main()
{
    vector<string> out[N];
    vector<string> in[N];
    vector<string> result[N];

    ReadFile(TESTPRE,IN,in,N);
    ReadFile(ANSPRE,OUT,out,N);

    stringstream ss;
    for(int i = 0; i < N; i++)
    {
        ss << in[i][0];
        int n;
        ss >> n;
        ss.clear();
        cout << n <<endl;
        Perm(n,in[i][1],result[i]);
    }
    PrintResult<string>(result,out);
    return 0;
}
