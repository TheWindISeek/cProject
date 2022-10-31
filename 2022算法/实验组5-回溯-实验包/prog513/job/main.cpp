#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define ANSPRE "../answer/job"
#define TESTPRE "../test/job"
#define OUT ".out"
#define IN ".in"
#define N 10
#define MAXN 12
void ReadFile(string pre,string suffix,vector<int> v[],int n)
{
    FILE* fp = NULL;
    string s = "0";
    int x;
    for(int i = 0; i < n; i++) { //需要解决一下如果多了10个怎么办
        string destination;
        stringstream ss;
        ss<<pre<<i<<suffix;
        ss >> destination;
        cout<<destination<<endl;
        fp = fopen(destination.c_str(),"r");
        if(fp != NULL) {
            while(!feof(fp)) { //忽略空格
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
int a[MAXN][MAXN];
int best;
int visit[MAXN];
void aj(int a[][MAXN], int n, int i, int j, int value) {
    if (value >= best)
        return;
    if (i == n) {
        best = value;
        return;
    }
    visit[j] = 1;
    for (int k = 1; k <= n; k++) {
        if (!visit[k])
            aj(a, n, i + 1, k, value+a[i+1][k]);
    }
    visit[j] = 0;
}
void AssignJob(int a[][MAXN], int n) {
    best = INF;
    memset(visit, 0, sizeof(visit));
    aj(a, n, 0, 0, 0);
}
int main()
{
    vector<int> out[N];
    vector<int> in[N];
    vector<int> result[N];

    ReadFile(TESTPRE,IN,in,N);
    ReadFile(ANSPRE,OUT,out,N);

    for(int i = 0; i < N; i++) {
        int n = in[i][0],index = 1;
        for(int k = 1; k <= n; k++) {
            for(int j = 1; j <= n; j++) {
                a[k][j] = in[i][index++];
            }
        }
        AssignJob(a,n);
        result[i].push_back(best);
    }
    PrintResult<int>(result,out);
    return 0;
}
