#include <bits/stdc++.h>
using namespace std;
#define inf 0x3f3f3f3f
#define MAX 1003
#define ANSPRE "../answer/mult"
#define TESTPRE "../test/mult"
#define OUT ".out"
#define IN ".in"
#define N 10
void ReadFile(string pre,string suffix,vector<char> v[],int n)
{
    FILE* fp = NULL;
    string s = "0";
    char x;
    for(int i = 0; i < n; i++) { //��Ҫ���һ���������10����ô��
        string destination;
        stringstream ss;
        ss<<pre<<i<<suffix;
        ss >> destination;
        cout<<destination<<endl;
        fp = fopen(destination.c_str(),"r");
        if(fp != NULL) {
            while(!feof(fp)) { //���Կո�
                fscanf(fp,"%c",&x);
                v[i].push_back(x);
            }
            fclose(fp);
        }
    }
}
void ReadFile(string pre,string suffix,vector<int> v[],int n)
{
    FILE* fp = NULL;
    string s = "0";
    int x;
    for(int i = 0; i < n; i++) { //��Ҫ���һ���������10����ô��
        string destination;
        stringstream ss;
        ss<<pre<<i<<suffix;
        ss >> destination;
        cout<<destination<<endl;
        fp = fopen(destination.c_str(),"r");
        if(fp != NULL) {
            while(!feof(fp)) { //���Կո�
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
    for(int k = 0; k < N; ++k) { //ÿ������
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
int multCount(string v, int n)//���� �ַ������� ���ַ��� ���ظ��������¿��Ƶ���a������ĸ���
{
    int f[n+1][n+1][3];
    memset(f, 0, sizeof(f));
    for (int i = 1; i <= n; i++)
        f[i][i][v[i-1]-'a'] = 1;
    //�о������������û�õ�֮ǰ������ �Ҹо���ö�ٵķ��򲻶� Ӧ������ö�ٳ��� ��ö�ٴ���
    for (int j = 1; j <= n; j++) {//ö�ٳ���
        for (int i = 1; i <= n-j; i++) {//ö�����
            for (int k = i; k < i+j; k++) {//ö�������Χ�ڵ��������
                f[i][i+j][0] += f[i][k][2] * f[k + 1][i+j][0] + f[i][k][1] * f[k + 1][i+j][2] + f[i][k][0] * f[k + 1][i+j][2];
                f[i][i+j][1] += f[i][k][0] * f[k + 1][i+j][0] + f[i][k][0] * f[k + 1][i+j][1] + f[i][k][1] * f[k + 1][i+j][1];
                f[i][i+j][2] += f[i][k][1] * f[k + 1][i+j][0] + f[i][k][2] * f[k + 1][i+j][1] + f[i][k][2] * f[k + 1][i+j][2];
            }
        }
    }
    return f[1][n][0];
}
int main()
{
    vector<int> out[N];
    vector<char> in[N];
    vector<int> result[N];

    ReadFile(TESTPRE,IN,in,N);
    ReadFile(ANSPRE,OUT,out,N);

    for(int i = 0; i < N; i++) {
        string s;
        for(int k = 0; k < in[i].size()-1 ; k++)
            s.push_back(in[i][k]);
        cout << s << ' '<<s.size()<<endl;
        result[i].push_back(multCount(s,s.size()));
    }
    PrintResult<int>(result,out);
    return 0;
}
