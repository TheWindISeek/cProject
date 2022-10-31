#include <bits/stdc++.h>
using namespace std;
#define inf 0x3f3f3f3f
#define MAX 1003
#define ANSPRE "../answer/kmul"
#define TESTPRE "../test/kmul"
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
int kmult(int num[], int n, int k) {
    int f[n+1][k+1];
    //前i个数字分割j段的最大k乘积 别人的做法是记录的加乘号的位置 我还是按照这个来吧
    int m[n+1][n+1];
    //先打表 避免重复计算
    memset(m, 0, sizeof(m));
    for (int i = 1; i <= n; i++)
        m[i][i] = num[i];
    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++)
            m[i][j] = m[i][j - 1] * 10 + m[j][j];
    memset(f, 0, sizeof(f));
    for (int i = 1; i <= n; i++) {//枚举数字长度
        for (int c = 1; c <= k; c++) {//枚举分割次数
            if (c == 1) {
                f[i][c] = m[1][i];
                continue;
            }
            for (int j = 1; j < i; j++) {//找乘法的位置
                f[i][c] = max(f[i][c], f[j][c - 1] * m[j + 1][i]);
            }
        }
    }
    return f[n][k];
}
int main()
{
    vector<int> out[N];
    vector<int> in[N];
    vector<int> result[N];

    ReadFile(TESTPRE,IN,in,N);
    ReadFile(ANSPRE,OUT,out,N);

    for(int i = 0; i < N; i++) {
        int n = in[i][0],k = in[i][1];
        int num[11];
        stringstream ss;
        ss << in[i][2];
        string s;
        ss >>s;
        for(int j = 1; j <= n; j++)
            num[j] = (s[j-1]-'0');
            cout <<i<<' '<<n<<' '<<k<<endl;
for(int i = 1; i <= n;i++)
    cout << num[i]<<' ';
cout << endl;
        result[i].push_back(kmult(num,n,k));
    }
    PrintResult<int>(result,out);
    return 0;
}
