#include <bits/stdc++.h>
using namespace std;
#define inf 0x3f3f3f3f
#define MAX 1003
#define ANSPRE "../answer/merge"
#define TESTPRE "../test/merge"
#define OUT ".out"
#define IN ".in"
#define N 10
int dpmin[MAX][MAX];
int dpmax[MAX][MAX];
int a[MAX];
int s[MAX];
int minCost,maxCost;
void ReadFile(string pre,string suffix,vector<int> v[],int n)
{
    FILE* fp = NULL;
    string s = "0";
    long x;
    for(int i = 0; i < n; i++) { //需要解决一下如果多了10个怎么办
        string destination;
        stringstream ss;
        ss<<pre<<i<<suffix;
        ss >> destination;
        cout<<destination<<endl;
        fp = fopen(destination.c_str(),"r");
        if(fp != NULL) {
            while(!feof(fp)) { //忽略空格
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
    for(int k = 0; k < N; ++k) { //每组数据
        cout << k <<endl;
        istrue = true;
        for(auto i = result[k].begin(),j = out[k].begin(); i != result[k].end()&&j != out[k].end(); i++,j++) {
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
void MergeCost(int a[],int n,int &minCost,int &maxCost)
{
    memset(dpmin,0,sizeof(dpmin));
    memset(dpmax,0,sizeof(dpmax));
    memset(s,0,sizeof(s));
    for(int i = 1; i <= n*2; i++){
        s[i] = s[i-1] + a[i];
    }
    cout << endl;
    for(int len = 2; len <= n; len++) {
        for(int l = 1; l+len -1 <= n*2; ++l) {
            int r = l+len-1;
            dpmin[l][r] = inf;
            dpmax[l][r] = 0;
            for(int k = l; k < r; k++) {
                dpmin[l][r] = min(dpmin[l][r],dpmin[l][k]+dpmin[k+1][r]+s[r]-s[l-1]);
                dpmax[l][r] = max(dpmax[l][r],dpmax[l][k]+dpmax[k+1][r]+s[r]-s[l-1]);
            }
        }
    }
    for(int i = 1; i <= n;i++)
    {
       // cout << dpmin[i][i+n-1]<<' '<<dpmax[i][i+n-1]<<endl;
        minCost = min(dpmin[i][i+n-1],minCost);
        maxCost = max(dpmax[i][i+n-1],maxCost);
    }
}
int main()
{
    vector<int> out[N];
    vector<int> in[N];
    vector<int> result[N];

    ReadFile(TESTPRE,IN,in,N);
    ReadFile(ANSPRE,OUT,out,N);

    for(int i = 0; i < N; i++) {
        int n = in[i][0];
        for(int k = 1; k <= n; k++) {
            a[k] = a[k+n] = in[i][k];
        }
        minCost = 0x3f3f3f3f;
        maxCost = 0;
        MergeCost(a,n,minCost,maxCost);
        result[i].push_back(minCost);
        result[i].push_back(maxCost);
    }
    PrintResult<int>(result,out);
    return 0;
}
