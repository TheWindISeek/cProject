#include <bits/stdc++.h>
using namespace std;
#define ANSPRE "../answer/thuff"
#define TESTPRE "../test/thuff"
#define OUT ".out"
#define IN ".in"
#define N 10
void ReadFile(string pre,string suffix,vector<int> v[],int n)
{
    FILE* fp = NULL;
    string s = "0";
    int x;
    for(int i = 0; i < n; i++) {
        s[0] = i+'0';
        string destination = pre+s+suffix;
        cout<<destination<<endl;
        fp = fopen(destination.c_str(),"r");
        while(1) { //忽略空格
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
int main()
{
    vector<int> out[N];
    vector<int> in[N];
    vector<int> result[N];

    ReadFile(TESTPRE,IN,in,N);
    ReadFile(ANSPRE,OUT,out,N);


    for(int i = 0; i < N; i++) {

    }
    PrintResult(result,out);
    return 0;
}
