#include <bits/stdc++.h>
using namespace std;
#define inf 0x3f3f3f3f
#define MAX 1003
#define ANSPRE "../answer/sum"
#define TESTPRE "../test/sum"
#define OUT ".out"
#define IN ".in"
#define N 10
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
const int MAXN = 1000010,INF = 0x3fffffff;
int g[MAXN],a[MAXN];
int splitArray(int* nums, int numsSize, int m)
{
    long long f[numsSize + 1][m + 1];
    memset(f, 0x3f, sizeof(f));
    long long sub[numsSize + 1];
    memset(sub, 0, sizeof(sub));
    for (int i = 0; i < numsSize; i++) {
        sub[i + 1] = sub[i] + nums[i];
    }
    f[0][0] = 0;
    for (int i = 1; i <= numsSize; i++) {
        for (int j = 1; j <= min(i, m); j++) {
            for (int k = 0; k < i; k++) {
                f[i][j] = min(f[i][j], max(f[k][j - 1], sub[i] - sub[k]));
            }
        }
    }
    return (int)f[numsSize][m];
}
int main()
{
    vector<int> out[N];
    vector<int> in[N];
    vector<int> result[N];

    ReadFile(TESTPRE,IN,in,N);
    ReadFile(ANSPRE,OUT,out,N);

    for(int i = 0; i < N; i++) {
        int n = in[i][0],m = in[i][1];
        for(int k = 0; k < n; k++) {
            a[k] = in[i][k+2];
        }
        result[i].push_back(splitArray(a,n,m));

    }
    PrintResult<int>(result,out);
    return 0;
}
