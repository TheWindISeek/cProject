#include <bits/stdc++.h>
using namespace std;
#define ANSPRE "../answer/sched"
#define TESTPRE "../test/sched"
#define OUT ".out"
#define IN ".in"
#define N 11
void ReadFile(string pre,string suffix,vector<int> v[],int n)
{
    FILE* fp = NULL;
    string s = "0";
    int x;
    for(int i = 0; i < n; i++)//��Ҫ���һ���������10����ô��
    {
        string destination;
        stringstream ss;
        ss<<pre<<i<<suffix;
        ss >> destination;
        cout<<destination<<endl;
        fp = fopen(destination.c_str(),"r");
        if(fp != NULL)
        {
            while(!feof(fp))//���Կո�
            {
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
    for(int k = 0; k < N; ++k)//ÿ������
    {
        cout << k <<endl;
        istrue = true;
        for(auto i = result[k].begin(),j = out[k].begin(); i != result[k].end()&&j != out[k].end(); i++,j++)
        {
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
int f[501][1001];
int Sched(vector<int> &a,vector<int> &b,int n)
{
    int x = a[1];
    memset(f,0x3f3f3f3f,sizeof(f));//�Ƚ�f��ʼ��Ϊ�����
    //f[i][j] ������ ǰi������ a��ʱj ������� b��ʱ���ٵ�ʱ��
    for(int i = 0; i < x;i++)
        f[1][i] = b[1];
     f[1][a[1]] = a[1] < b[1] ? 0 : b[1];//��� ��һ������ a�ĺ�ʱ��b�� ��ô�ͷ���a������ ��Ȼ�ͷ���b������
    for(int k = 2; k <= n; k++)//�ӵڶ�������ʼ һֱ�������n������
    {
        x+=a[k];//ÿ���������һ��
        for(int i = 0; i <= x; i++)
            if(i < a[k])//����ʱ��С�� a���������Ҫ��ʱ�� ����ֻ������bȥ���� a��������
                f[k][i] = f[k-1][i]+b[k];
            else//����ѡ��a ������������ѡ��������һ��
                f[k][i] = min(f[k-1][i]+b[k],f[k-1][i-a[k]]);
    }
    int mint = 0x3f3f3f3f;//�ȳ�ʼ�������
    //i������� a��ʱ�� f[n][i]�������b���n������b�������Сʱ�� ���������ʱ�� ��ȡ���� �����������Ǹ� �����Ǹ��������С��һ��
    for(int i = 1; i <= x; i++)//�ܹ���x�� x ����a���еĿ�����
        mint = min(mint,max(i,f[n][i]));
    return mint;
}
int main()
{
    vector<int> out[N];
    vector<int> in[N];
    vector<int> result[N];
    for(int i = 0; i < N; i++)
        in[i].reserve(256);
    ReadFile(TESTPRE,IN,in,N);
    ReadFile(ANSPRE,OUT,out,N);

    for(int i = 0; i < N; i++)
    {
        vector<int> a, b;
        a.push_back(0);
        b.push_back(0);
        int n = in[i][0];
        for(int k = 1; k <= n; k++)
            a.push_back(in[i][k]);
        for(int k = n+1; k <= 2*n; k++)
            b.push_back(in[i][k]);
        result[i].push_back(Sched(a,b,n));
    }
    PrintResult<int>(result,out);
    return 0;
}
