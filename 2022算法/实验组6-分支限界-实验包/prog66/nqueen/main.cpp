#include <bits/stdc++.h>
using namespace std;
#define ANSPRE "../answer/queen"
#define TESTPRE "../test/queen"
#define OUT ".out"
#define IN ".in"
#define N 8
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
const int MAXN = 14;
int re[MAXN];
typedef struct node {
    int i;
    int a[MAXN];
}node;
bool Place(int i, int c, int* x)
//i是当前行数，c是列数,判断能否放在c列
{
    if (i == 1)return true;
    for (int j = 1; j < i; j++)
        if ((c == x[j]) || (fabs(c - x[j]) == fabs(i - j)))
            return false;
    return true;
}
bool NQueenQueue(int n)
{
    cout << n <<endl;
    queue<node> q;
    node e;
    e.i = 0;
    memset(e.a,0,sizeof(e.a));
    q.push(e);
    while (!q.empty()) {
        e = q.front();
        q.pop();
        if (e.i == n) {
            memcpy(re,e.a,sizeof(e.a));
            return true;
        }
        for (int j = 1; j <= n; j++) {
            if (Place(e.i + 1, j, e.a)) {
                node t;//扩展结点
                t.i = e.i + 1;
                memcpy(t.a,e.a,sizeof(e.a));
                t.a[t.i] = j;
                q.push(t);
            }
        }
    }
    return false;
}
int main()
{
    vector<int> out[N];
    vector<int> in[N];
    vector<int> result[N];

    ReadFile(TESTPRE,IN,in,N);
    ReadFile(ANSPRE,OUT,out,N);

    stringstream ss;
    for(int i = 0; i < N; i++) {
        int n = in[i][0];
        NQueenQueue(n);
        for(int j = 1; j <= n; j++)
            result[i].push_back(re[j]);
    }
    PrintResult<int>(result,out);
    return 0;
}
