#include <bits/stdc++.h>
using namespace std;
#define ANSPRE "../answer/maxm"
#define TESTPRE "../test/maxm"
#define OUT ".out"
#define IN ".in"
#define N 10
/*
说明
由于给的测试数据太过于离谱 虽然我确实应该考虑到有这么大的数据
但是鉴于这么大的数据只能用字符串进行模拟
不再用字符串进行模拟了
*/
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
int maxm(int n)
{
    /*if(n <= 4)
        return n;
    if(n&1)
        return (n-1)/2*maxm((n+1)/2);
    return n/2*maxm(n/2);*/
    int a[10001],i = 2,j = 0,length,sum = 1,x = n;
    while(x >= i){//这一个循环用于寻找所有可能的因子 同时利用这种方法避免重复 而最多找到中间
        x -= i;
        a[j++] = i++;
    }
    length = j--;
    while(x--){//这一个循环用于将找到最大的那种
        a[j]++;//先给大的分配 这样才能让最后的值更大
        j = (j-1+length)%length;//防止剩余个数多于因子个数
    }
    for(int i = 0; i < length;i++)
        sum *= a[i];
    return sum;
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
        cout << n <<endl;
        result[i].push_back(maxm(n));
    }
    PrintResult(result,out);
    return 0;
}
