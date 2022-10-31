#include "../../READFILE/ReadFile.h"
#include <cstring>
#include <set>
#include <cmath>
#include <algorithm>
#define ANSPRE "../answer/mode"
#define TESTPRE "../test/mode"
#define OUT ".out"
#define IN ".in"
#define N 10
//100010
//1234_567
//N ： 总共有几组数据需要读取 10组以下
void ReadFile(string pre,string suffix,vector<int> v[],int n)
{
    FILE* fp = NULL;
    string s = "0";
    int x;
    for(int i = 0; i < n; i++)
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

int maxElement,maxNumber;
void Split(vector<int>&a,int mid,int left,int right,int &midLeft,int &midRight)
{
    int p = left;
    while(a[p]!=a[mid])
        p++;
    midLeft = p;
    p = right;
    while(a[p]!= a[mid])
        p--;
    midRight = p;
}
void Mode(vector<int> &a,int left,int right)//数组的范围
{
    int midLeft,midRight;//两个下标 分别标识左右限
    // int mid = Median(left,right);//用于获得中位数的值
    // int mid = (right-left)/2+left;
    int mid = (right+left)/2;
    Split(a,mid,left,right,midLeft,midRight);
    if(midRight - midLeft + 1 > maxNumber)//中位数
    {
        cout << midLeft << " "<<midRight<<endl;
        maxNumber = midRight - midLeft + 1;
        maxElement = a[mid];
    }
    if(midLeft - left > maxNumber)
        Mode(a,left,midLeft-1);
    if(right - midRight > maxNumber)
        Mode(a,midRight + 1,right);
}
void Counts(vector<int> &a,int n)
{
    Mode(a,0,n-1);
}

int main()
{
    vector<int> out[N];
    vector<int> in[N];
    vector<int> result[N];
    vector<int> a;

    ReadFile(TESTPRE,IN,in,N);
    ReadFile(ANSPRE,OUT,out,N);


    for(int i = 0; i < N; i++)
    {
        a.clear();
        int n = in[i][0];
        cout <<i<<" "<< n <<endl;
        maxElement = maxNumber = 0;
        for(int x = 1; x < (int)in[i].size(); x++)
            a.push_back(in[i][x]);
        sort(a.begin(),a.end());
        Counts(a,n);
        result[i].push_back(maxElement);
        result[i].push_back(maxNumber);
        cout << endl;
    }
    PrintResult(result,out);
    return 0;
}
