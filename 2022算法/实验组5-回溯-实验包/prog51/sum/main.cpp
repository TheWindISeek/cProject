#include <bits/stdc++.h>
using namespace std;
#define ANSPRE "../answer/subsum"
#define TESTPRE "../test/subsum"
#define OUT ".out"
#define IN ".in"
#define N 7
void ReadFile(string pre,string suffix,vector<int> v[],int n)
{
    string s = "0";
    int sss;
    for(int i = 0; i < n; i++) {
        string destination;
        stringstream ss;
        ss<<pre<<i<<suffix;
        ss >> destination;
        cout<<destination<<endl;
        ifstream fp(destination.c_str());
        while(!fp.eof()) {
            fp >> sss;
            v[i].push_back(sss);
        }
        fp.close();
    }
}
void ReadAnsFile(string pre,string suffix,vector<int> v[],int n)
{
    string s = "0";
    string re;
    for(int i = 0; i < n; i++) {
        string destination;
        stringstream ss;
        ss<<pre<<i<<suffix;
        ss >> destination;
        cout<<destination<<endl;
        ifstream fp(destination.c_str());
        getline(fp,re);
        if(re[0] == 'N') {
            v[i].push_back(-1);
            continue;
        }
        int x;
        stringstream sss(re);
        while(sss >> x)
            v[i].push_back(x);
        fp.close();
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
    printf("passed : %d%%\nWrong test case as followed:\n",c*100/N);
    for(auto i = s.begin(); i != s.end(); i++)
        printf("%d\n",(*i));
}
vector<int> res;
vector<int> tmp;

int flag;
void subsum(vector<int>& v, int n, int c, int i)
{
    if (flag)
        return;
    if (i >= n) {//没找到
        flag = 0;
        return;
    }
    //cout << c << endl;
    tmp.push_back(v[i]);
    c -= v[i];
    if (c == 0) {
        flag = 1;
        for (int num : tmp)
            res.push_back(num);
        return;
    }//找到了//如果c还没有减小到0 就说明还可以继续取
    else if (c > 0) {
        subsum(v, n, c, i + 1);
    }
    c += v[i];
    tmp.pop_back();
    subsum(v, n, c, i + 1);
}

int main()
{
    vector<int> out[N];
    vector<int> in[N];
    vector<int> result[N];

    ReadFile(TESTPRE,IN,in,N);
    ReadAnsFile(ANSPRE,OUT,out,N);

    for(int i = 0; i < N; i++) {
        int n = in[i][0],c = in[i][1];
        vector<int> v(n);
        res.clear();
        tmp.clear();
        flag = 0;
        for(int k = 0; k < n ; k++)
            v[k] = in[i][k+2];
        subsum(v,n,c,0);
        cout << i <<endl;
        if(flag) {
            for(int a : res)
                result[i].push_back(a);
        } else {
            result[i].push_back(-1);
        }
    }
    PrintResult<int>(result,out);
    return 0;
}
