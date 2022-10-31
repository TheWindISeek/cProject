#include "../../READFILE/ReadFile.h"
#include <cstring>
#include <set>
#include <cmath>
#define ANSPRE "../answer/count"
#define TESTPRE "../test/count"
#define OUT ".out"
#define IN ".in"
#define N 10
void ReadFile(string pre,string suffix,vector<int> v[],int n)
{
    FILE* fp = NULL;
    string s = "0";
    int x;
    for(int i = 0; i < 10; i++)
    {
        s[0] = i+'0';
        string destination = pre+s+suffix;
        cout<<destination<<endl;
        fp = fopen(destination.c_str(),"r");
        while(1)//���Կո�
        {
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
    for(int k = 0; k < N; k++)
    {
        cout <<k+1 <<endl;
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
    }
    printf("passed : %d\ntotal : %d\nWrong test case as followed:\n",c,N);
    for(auto i = s.begin(); i != s.end(); i++)
        printf("%d\n",(*i));
}

void  solveBF(int n,int *a)
{
    int x;
    for (int i = 1; i <= n; i++)//�������Ҫ�ж� ���Կ����ظ����� ��ջ���߶��ж���
    {
        x = i;
        while (x)//101
        {
            a[x % 10]++;
            x /= 10;
        }
    }
    return;
}
int Pow(int x,int exp)
{
    if(exp == 0)
        return 1;
    if(exp == 1)
        return x;
    int xx = Pow(x,exp/2);
    if(exp%2)
        return xx*xx*x;
    return xx*xx;
}
//������n ����λ�� c ������ݵĽ�� a����
void cal(int n, int c, int* a)
{
    //��ֹ����ӦΪ λ��Ϊ 0 ���ѡ��nΪ0 �����100�������ݾͻ����
    if (c == 0)
        return;
    //��������������
    int level = Pow(10, c - 1);
    int x = n / level;
    int left = n - (x * level);
    //���е��������ϵ�һ����
    for (int i = 0; i < 10; i++)
        a[i] += x*(c - 1) * level/10;
    //�ظ��˵�����
    for (int i = 0; i < x; i++)
        a[i] += level;
    a[x] += left + 1;

    //�ݹ����
    cal(left, c - 1, a);
}
void solveEffective(int n, int* a)
{
    //��ֹ������ѭ���Լ���������
    if (n <= 0)
        return;
    int x = n, c = 0;//��������log10+1ȥֱ�Ӽ���
    while (x)
    {
        x /= 10;
        c++;
    }
    cal(n, c, a);
    //��ȥ�����0 ���õȱ����еĺ͵Ĺ�ʽ���л���
    a[0] -= (Pow(10, c) - 1) / 9;
}

int main()
{
    vector<int> out[N];
    vector<int> in[N];
    vector<int> result[N];

    int a[N];

    ReadFile(ANSPRE,OUT,out,N);
    ReadFile(TESTPRE,IN,in,N);

    for(int i = 0; i < N; i++)
    {
        for(int x:in[i])
        {
            memset(a,0,sizeof(a));
            //�㷨��ʼ
          // solveBF(x,a);
            solveEffective(x,a);
            //�㷨����
            for(int k = 0; k < 10; k++)
                result[i].push_back(a[k]);
        }
    }
    PrintResult(result,out);
    return 0;
}
