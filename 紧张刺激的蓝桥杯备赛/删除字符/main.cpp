#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    // ���ڴ��������Ĵ���
    string s;
    getline(cin,s);
    int t;
    cin >> t;
    //��ôɾ���������ֵ�����С ���������ǰ�ıȺ����
    /*
    ��С�ľ�������ǰ���� ���������� ÿ�ΰѺ�����С���Ǹ�������
    */
    int l = s.length();
    bool is[l];
    int c = 0;
    memset(is,false,sizeof(is));
    for(int i = 0; i < l&&c<t; i++)
    {
        int next = i+1;
        for(; next<l; next++)
        {
            while(is[next])
                next++;
            if(s[next] < s[i])
            {
                c++;
                is[i] = true;
                break;
            }
        }
    }
    for(int i = 0; i < l; i++)
    {
        if(!is[i])
            printf("%c",s[i]);
    }

    return 0;
}
