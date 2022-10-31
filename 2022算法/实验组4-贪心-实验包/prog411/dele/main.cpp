#include <bits/stdc++.h>
using namespace std;
#define ANSPRE "../answer/dele"
#define TESTPRE "../test/dele"
#define OUT ".out"
#define IN ".in"
#define N 11
void ReadFile(string pre,string suffix,vector<string> v[],int n)
{
    string s = "0";
    string sss;
    for(int i = 0; i < n; i++) {
        string destination;
        stringstream ss;
        ss<<pre<<i<<suffix;
        ss >> destination;
        cout<<destination<<endl;
        ifstream fp(destination.c_str());
        fp >> sss;
        v[i].push_back(sss);
        fp >> sss;
        v[i].push_back(sss);
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
    printf("passed : %d\ntotal : %d\nWrong test case as followed:\n",c,N);
    for(auto i = s.begin(); i != s.end(); i++)
        printf("%d\n",(*i));
}
string & deleteK(string & a,int k){

    while(k--){
        //找到从头开始连续增长子序列的末尾
        auto i = a.begin();
        while(i != a.end()-1){
            if(*i <= *(i+1))//是最长连续增长子序列的最后一个
                i++;
            else
                break;
        }
        a.erase(i);
    }
    while(1){//是我没考虑周全 确实有可能出现这样把0都全部往前放的情况 这样的话需要把前导0全部删除
        auto i = a.begin();
        if(*i != '0')
            break;
        a.erase(i);
    }
    return a;
}
int main()
{
    vector<string> out[N];
    vector<string> in[N];
    vector<string> result[N];

    ReadFile(TESTPRE,IN,in,N);
    ReadFile(ANSPRE,OUT,out,N);


    for(int i = 0; i < N; i++) {
        string a(in[i][0]);
        int k;
        stringstream ss;
        ss << in[i][1];
        ss >> k;
        cout << a <<' '<<k<<endl;
        result[i].push_back(deleteK(a,k));
    }
    PrintResult<string>(result,out);
    return 0;
}
