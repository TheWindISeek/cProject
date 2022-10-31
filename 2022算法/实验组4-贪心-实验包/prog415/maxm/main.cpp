#include <bits/stdc++.h>
using namespace std;
#define ANSPRE "../answer/maxm"
#define TESTPRE "../test/maxm"
#define OUT ".out"
#define IN ".in"
#define N 10
/*
˵��
���ڸ��Ĳ�������̫�������� ��Ȼ��ȷʵӦ�ÿ��ǵ�����ô�������
���Ǽ�����ô�������ֻ�����ַ�������ģ��
�������ַ�������ģ����
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
        while(1) { //���Կո�
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
    while(x >= i){//��һ��ѭ������Ѱ�����п��ܵ����� ͬʱ�������ַ��������ظ� ������ҵ��м�
        x -= i;
        a[j++] = i++;
    }
    length = j--;
    while(x--){//��һ��ѭ�����ڽ��ҵ���������
        a[j]++;//�ȸ���ķ��� ��������������ֵ����
        j = (j-1+length)%length;//��ֹʣ������������Ӹ���
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
