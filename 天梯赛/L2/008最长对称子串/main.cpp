#include <stdio.h>
#include <iostream>
#include <map>
/*
����Ĳ��������ڵ�һ���ύ֮��Ͳ������
Ȼ���Լ�Ҳ���Ǹ��뷨������
������ΪһЩ����
����û��ALL PASS
��������һ�����ϵ�
������ʵ˼·һ��
���Ǿ��ǲ�֪��Ϊʲô�ϲ���
�Ͱ����ĸ�����
���ֻ��ǲ���
��ʱ�ͺܾ��� ��������һ��
�����ĺܷ� û�����Լ��ĳ����е��ƶ��������
�����ύ�˱��˵Ĵ���� ����ȶ�֮�²ŷ����������
�����ļ��� ����д�� ȥ���
ͬʱ��������һ��֤�����ֽⷨ��ȷ�Ե����� �����֮ǰ��ѭ������ʽһ���ĸо�-��ҲҪ֤��
��֤����
*/
using namespace std;
int Symmetric(string &s,int n,int f,int b,int length)
{
    int l = length;
    while(f >= 0 && b < n)
    {
        if(s[f] == s[b])
            l+=2;
        else
            break;
        f--;
        b++;
    }
    return l;
}
int main ()
{
    string s;
    getline(cin,s);
    int max = 1,l;
    int n = s.length();
    for(int i = 0; i < n; i++)
    {
        l = Symmetric(s,n,i-1,i+1,1);
        if(l  > max)
            max = l;
        l = Symmetric(s,n,i,i+1,0);
        if(l  > max)
            max = l;
    }
    cout << max;
    return 0;
}
